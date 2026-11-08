#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// ==========================================================
// DHT11 CONFIGURATION
// ==========================================================

#define DHTPIN A0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// ==========================================================
// HARDWARE CONFIGURATION
// ==========================================================

#define TRIG_PIN 13
#define ECHO_PIN 12

#define RED_LED_PIN 11
#define GREEN_LED_PIN 10
#define BUZZER_PIN 8

#define TDS_PIN A3
#define TURBIDITY_PIN A2
#define PH_PIN A1

LiquidCrystal_I2C lcd(0x27, 16, 4);

// ==========================================================
// WATER LEVEL CALIBRATION
// ==========================================================

const float EMPTY_DISTANCE = 15.40;
const float FULL_DISTANCE = 3.58;

const int MAX_VOLUME = 2000;

// ==========================================================
// WATER QUALITY LIMITS
// ==========================================================

const float PH_MIN = 6.5;
const float PH_MAX = 8.5;

const int TDS_MAX = 500;

const float TURBIDITY_MAX_PERCENT = 10.0;

// ==========================================================
// pH CALIBRATION
// ==========================================================

float PH7_VOLTAGE = 2.50;

const float PH_SENSITIVITY = 0.18;

// ==========================================================
// TURBIDITY CALIBRATION
// ==========================================================

int TURBIDITY_CLEAR_ADC = 0;

const int TURBIDITY_DIRTY_ADC = 300;

// ==========================================================
// LOGGING
// ==========================================================

const unsigned long LOG_INTERVAL = 3000;

unsigned long lastLogTime = 0;

// ==========================================================
// LEVEL VARIABLES
// ==========================================================

float distanceBuffer[5] = {0};

int distanceIndex = 0;

bool distanceInitialized = false;

float distance = EMPTY_DISTANCE;

// ==========================================================
// LOADING BAR CHARACTER
// ==========================================================

byte bar[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

// ==========================================================
// SETUP
// ==========================================================

void setup()
{
  Serial.begin(9600);

  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(TDS_PIN, INPUT);
  pinMode(TURBIDITY_PIN, INPUT);
  pinMode(PH_PIN, INPUT);

  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, LOW);

  noTone(BUZZER_PIN);

  // ========================================================
  // LCD INITIALIZATION - 16x4
  // ========================================================

  lcd.init();
  lcd.backlight();

  // ========================================================
  // WELCOME SCREEN
  // ========================================================

  lcd.setCursor(2, 0);
  lcd.print("Welcome");
 delay(500);
 lcd.print(".");
 delay(500);
 lcd.print(".");
 delay(500);
 lcd.print(".");
 delay(500);
 lcd.print(".");
 delay(500);
 lcd.print(".");
 delay(500);
 lcd.print(".");
  delay(2500);
  lcd.clear();
lcd.print("Team Aquenza");
lcd.setCursor(1,1);
lcd.print("Presents....");
delay(2500);
lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Water Quality");

  lcd.setCursor(1, 1);
  lcd.print("Monitoring Sys");

  delay(2500);
  lcd.clear();

  // ========================================================
  // ACTIVATION SCREEN
  // ========================================================

  lcd.setCursor(3, 0);
  lcd.print("Activating");

  lcd.setCursor(0, 1);
  lcd.print("Please Wait");
delay(500);
 lcd.print(".");
 delay(500);
 delay(500);
 lcd.print(".");
 delay(500);
 delay(500);
 lcd.print(".");
 delay(500);
  lcd.print(".");
 delay(500);
  lcd.print(".");
 delay(500);
 delay(1000);
 lcd.clear();

  // ========================================================
  // INITIALIZATION SCREEN
  // ========================================================

  lcd.createChar(0, bar);

  lcd.setCursor(2, 0);
  lcd.print("Initializing");

  for (int i = 0; i <= 16; i++)
  {
    lcd.setCursor(0, 1);

    for (int j = 0; j < 16; j++)
    {
      if (j < i)
      {
        lcd.write(byte(0));
      }
      else
      {
        lcd.print(" ");
      }
    }

    delay(200);
  }

  delay(1000);
  lcd.clear();

  // ========================================================
  // pH CALIBRATION
  // ========================================================

  long totalPH = 0;

  for (int i = 0; i < 100; i++)
  {
    totalPH += analogRead(PH_PIN);
    delay(10);
  }

  float averagePH = totalPH / 100.0;

  PH7_VOLTAGE = averagePH * 5.0 / 1023.0;

  // ========================================================
  // TURBIDITY CALIBRATION
  // ========================================================

  long turbidityTotal = 0;

  for (int i = 0; i < 100; i++)
  {
    turbidityTotal += analogRead(TURBIDITY_PIN);
    delay(10);
  }

  TURBIDITY_CLEAR_ADC = turbidityTotal / 100;

  // ========================================================
  // SERIAL INFORMATION
  // ========================================================

  Serial.println();
  Serial.println("========================================");
  Serial.println("       WATER QUALITY SYSTEM");
  Serial.println("========================================");

  Serial.print("EMPTY distance : ");
  Serial.print(EMPTY_DISTANCE);
  Serial.println(" cm");

  Serial.print("FULL distance  : ");
  Serial.print(FULL_DISTANCE);
  Serial.println(" cm");

  Serial.print("pH reference   : ");
  Serial.print(PH7_VOLTAGE, 3);
  Serial.println(" V");

  Serial.print("TUR clear ADC  : ");
  Serial.println(TURBIDITY_CLEAR_ADC);

  Serial.println("----------------------------------------");

  // ========================================================
  // CALIBRATION COMPLETED SCREEN
  // ========================================================

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Calibration Done");

  lcd.setCursor(0, 1);
  lcd.print("pH Ref=");
  lcd.print(PH7_VOLTAGE, 2);

  lcd.setCursor(0, 2);
  lcd.print("TUR Ref=");
  lcd.print(TURBIDITY_CLEAR_ADC);

  lcd.setCursor(2, 3);
  lcd.print("Starting...");

  delay(2000);

  lcd.clear();
}

// ==========================================================
// MAIN LOOP
// ==========================================================

void loop()
{
  delay(2000);

  // ========================================================
  // DHT11
  // ========================================================

  float tmp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(tmp) || isnan(hum))
  {
    Serial.println("DHT11 Sensor Error!");

    lcd.setCursor(0, 0);
    lcd.print("DHT11 ERROR     ");

    lcd.setCursor(0, 1);
    lcd.print("Check Sensor    ");

    return;
  }

  Serial.print("Temp :");
  Serial.println(tmp);

  // ========================================================
  // ULTRASONIC DISTANCE
  // ========================================================

  float rawDistance = getDistance();

  if (rawDistance >= 0)
  {
    distance = filterDistance(rawDistance);
  }

  // ========================================================
  // LEVEL CALCULATION
  // ========================================================

  float levelPercent =
    ((EMPTY_DISTANCE - distance) /
    (EMPTY_DISTANCE - FULL_DISTANCE)) * 100.0;

  levelPercent = constrain(levelPercent, 0.0, 100.0);

  // ========================================================
  // VOLUME CALCULATION
  // ========================================================

  int currentVolume =
    round((levelPercent / 100.0) * MAX_VOLUME);

  currentVolume = constrain(currentVolume, 0, MAX_VOLUME);

  // ========================================================
  // TDS
  // ========================================================

  int tdsValue = analogRead(TDS_PIN);

  int TDS = map(tdsValue, 0, 1023, 0, 1000);

  TDS = constrain(TDS, 0, 1000);

  // ========================================================
  // TURBIDITY
  // ========================================================

  int turbidityValue = analogRead(TURBIDITY_PIN);

  float TUR_PERCENT = 0;

  if (TURBIDITY_CLEAR_ADC > TURBIDITY_DIRTY_ADC)
  {
    TUR_PERCENT =
      ((float)(TURBIDITY_CLEAR_ADC - turbidityValue) /
      (TURBIDITY_CLEAR_ADC - TURBIDITY_DIRTY_ADC)) * 100.0;
  }
  else
  {
    TUR_PERCENT =
      ((float)(turbidityValue - TURBIDITY_CLEAR_ADC) /
      (TURBIDITY_DIRTY_ADC - TURBIDITY_CLEAR_ADC)) * 100.0;
  }

  TUR_PERCENT = constrain(TUR_PERCENT, 0.0, 100.0);

  // ========================================================
  // pH
  // ========================================================

  long totalPHReading = 0;

  for (int i = 0; i < 20; i++)
  {
    totalPHReading += analogRead(PH_PIN);
    delay(5);
  }

  float averagePHReading = totalPHReading / 20.0;

  float phVoltage = averagePHReading * 5.0 / 1023.0;

  float pH =
    7.0 + ((PH7_VOLTAGE - phVoltage) / PH_SENSITIVITY);

  pH = constrain(pH, 0.0, 14.0);

  // ========================================================
  // WATER QUALITY CHECK
  // ========================================================

  bool phSuitable = (pH >= PH_MIN && pH <= PH_MAX);

  bool tdsSuitable = (TDS <= TDS_MAX);

  bool turbiditySuitable =
    (TUR_PERCENT <= TURBIDITY_MAX_PERCENT);

  bool waterSuitable =
    phSuitable && tdsSuitable && turbiditySuitable;

  // ========================================================
  // LED + BUZZER
  // ========================================================

  if (waterSuitable)
  {
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);

    noTone(BUZZER_PIN);
  }
  else
  {
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);

    tone(BUZZER_PIN, 2000);
  }

  // ========================================================
  // 16x4 LCD SENSOR DISPLAY
  // ========================================================

  // ROW 1: TDS + TURBIDITY

  lcd.setCursor(0, 0);

  lcd.print("TDS:");
  lcd.print(TDS);

  lcd.print(" TUR:");
  lcd.print((int)TUR_PERCENT);
  lcd.print("%  ");

  // ROW 2: pH + TEMPERATURE

  lcd.setCursor(0, 1);

  lcd.print("pH:");
  lcd.print(pH, 2);

  lcd.print(" T:");
  lcd.print(tmp);
  lcd.print("C");

  // ROW 3: LEVEL + VOLUME

  int displayLevel = (int)levelPercent - 30;

  displayLevel = constrain(displayLevel, 0, 100);

  lcd.setCursor(0, 2);

  lcd.print("L:");
  lcd.print(displayLevel);
  lcd.print("% V:");
  lcd.print(currentVolume);
  lcd.print("ml  ");

  // ROW 4: HUMIDITY + WATER STATUS

  lcd.setCursor(0, 3);

  if (waterSuitable)
  {
    lcd.print("H:");
    lcd.print((int)hum);
    lcd.print("% GOOD      ");
  }
  else
  {
    lcd.print("H:");
    lcd.print((int)hum);
    lcd.print("% BAD       ");
  }

  // ========================================================
  // SERIAL MONITOR
  // ========================================================

  unsigned long currentTime = millis();

  if (currentTime - lastLogTime >= LOG_INTERVAL)
  {
    Serial.println();
    Serial.println("----------------------------------------");

    Serial.print("Temperature = ");
    Serial.print(tmp);
    Serial.println(" C");

    Serial.print("Humidity    = ");
    Serial.print(hum);
    Serial.println(" %");

    Serial.print("Distance = ");
    Serial.print(distance, 2);
    Serial.println(" cm");

    Serial.print("LEVEL    = ");
    Serial.print(levelPercent, 1);
    Serial.println("%");

    Serial.print("DISPLAY LEVEL = ");
    Serial.print(displayLevel);
    Serial.println("%");

    Serial.print("VOLUME   = ");
    Serial.print(currentVolume);
    Serial.println(" ml");

    Serial.print("TDS      = ");
    Serial.print(TDS);
    Serial.println(" ppm");

    Serial.print("TUR      = ");
    Serial.print(TUR_PERCENT, 1);
    Serial.println("%");

    Serial.print("TUR ADC  = ");
    Serial.println(turbidityValue);

    Serial.print("pH       = ");
    Serial.println(pH, 2);

    Serial.print("pH Volt  = ");
    Serial.print(phVoltage, 3);
    Serial.println(" V");

    Serial.print("WATER    = ");

    if (waterSuitable)
    {
      Serial.println("SUITABLE");
    }
    else
    {
      Serial.println("UNSUITABLE");
    }

    Serial.println("----------------------------------------");

    lastLogTime = currentTime;
  }

  delay(300);
}

// ==========================================================
// ULTRASONIC DISTANCE
// ==========================================================

float getDistance()
{
  const int SAMPLE_COUNT = 5;

  float readings[SAMPLE_COUNT];

  int validCount = 0;

  for (int i = 0; i < SAMPLE_COUNT; i++)
  {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(3);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    unsigned long duration =
      pulseIn(ECHO_PIN, HIGH, 30000);

    if (duration > 0)
    {
      float measuredDistance =
        duration * 0.0343 / 2.0;

      if (measuredDistance >= 2.0 &&
          measuredDistance <= 50.0)
      {
        readings[validCount] = measuredDistance;
        validCount++;
      }
    }

    delay(30);
  }

  if (validCount == 0)
  {
    return -1;
  }

  // SORT READINGS

  for (int i = 0; i < validCount - 1; i++)
  {
    for (int j = i + 1; j < validCount; j++)
    {
      if (readings[j] < readings[i])
      {
        float temp = readings[i];
        readings[i] = readings[j];
        readings[j] = temp;
      }
    }
  }

  // MEDIAN VALUE

  if (validCount % 2 == 1)
  {
    return readings[validCount / 2];
  }
  else
  {
    return (readings[(validCount / 2) - 1] +
            readings[validCount / 2]) / 2.0;
  }
}

// ==========================================================
// DISTANCE FILTER
// ==========================================================

float filterDistance(float newDistance)
{
  if (!distanceInitialized)
  {
    for (int i = 0; i < 5; i++)
    {
      distanceBuffer[i] = newDistance;
    }

    distanceInitialized = true;
  }

  distanceBuffer[distanceIndex] = newDistance;

  distanceIndex++;

  if (distanceIndex >= 5)
  {
    distanceIndex = 0;
  }

  float sum = 0;

  for (int i = 0; i < 5; i++)
  {
    sum += distanceBuffer[i];
  }

  return sum / 5.0;
}
