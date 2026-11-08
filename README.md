# 💧 Smart Water Purification and Quality Monitoring System

A low-cost, Arduino-based water quality monitoring and screening prototype developed to address the limitations of conventional water quality assessment methods that primarily focus on Total Dissolved Solids (TDS). The project focuses on monitoring multiple water quality parameters, including TDS, pH, turbidity, and temperature, to provide a broader understanding of input water quality.

Designed for the Water Purifier track of **Atomberg AtomQuest 2026**, the system aims to support water quality assessment, particularly in rural and mining-affected areas where water contamination can be a significant concern.

The prototype integrates multiple sensors with an Arduino Uno for data acquisition and processing, while an ESP32 handles wireless communication and cloud-based monitoring. Sensor readings are displayed locally through an I2C LCD and remotely through a Blynk IoT dashboard. Visual and audible alerts indicate whether the measured parameters fall within the configured screening limits.

# 🚀 Project Overview :-

Conventional water quality monitoring systems often emphasize TDS as a primary indicator of water quality. However, TDS alone cannot provide a complete picture of water suitability. Water may have acceptable TDS levels while exhibiting abnormal pH or turbidity.

To address this limitation, the proposed system monitors multiple parameters simultaneously:

1. **TDS Monitoring:** Measures the approximate concentration of dissolved solids in water.
2. **pH Monitoring:** Evaluates whether the water is acidic, neutral, or alkaline.
3. **Turbidity Monitoring:** Estimates the cloudiness of water caused by suspended particles.
4. **Temperature Monitoring:** Measures the temperature of the surrounding water sample.
5. **Water Level Monitoring:** Measures the water level and estimates the available volume inside the container using an ultrasonic sensor.

The Arduino Uno acts as the primary controller, collecting sensor readings, processing the measurements, checking configured water quality limits, and controlling the LCD, LEDs, and buzzer.

An ESP32 is connected to the Arduino Uno through UART serial communication. It receives the processed sensor values and transfers them through Wi-Fi to a Blynk IoT dashboard, where users can monitor the parameters using individual gauge widgets.

The system is designed as an affordable and expandable monitoring platform that can support better awareness of input water quality before and during purification.

# ✨ Key Features :- 

1. **Multi-Parameter Water Quality Monitoring:** Monitors TDS, pH, turbidity, and temperature instead of relying exclusively on TDS.

2. **TDS Measurement:** Provides an approximate TDS reading using the sensor's analog output.

3. **pH Monitoring:** Measures the pH of the water sample and checks whether it falls within the configured range.

4. **Turbidity Monitoring:** Estimates water cloudiness using a turbidity sensor and displays the result as a percentage.

5. **Temperature Monitoring:** Measures temperature using a DHT11 sensor.

6. **Water Level Detection:** Uses an ultrasonic sensor to measure the distance between the sensor and the water surface.

7. **Water Volume Estimation:** Calculates the approximate water volume based on the measured water level and calibrated container dimensions.

8. **Real-Time LCD Display:** Displays sensor readings and water quality status on a 16×4 I2C LCD.

9. **Wi-Fi-Based Monitoring:** Uses an ESP32 to transfer sensor readings to the Blynk IoT platform.

10. **Blynk Gauge Dashboard:** Displays TDS, pH, turbidity, temperature, and water level through five individual gauge widgets.

11. **Visual Alert System:** Uses red and green LEDs to indicate whether the measured water parameters satisfy the configured screening conditions.

12. **Audible Alert System:** Activates a buzzer when one or more measured parameters fall outside the configured limits.

13. **Separate Processing and Connectivity:** Uses Arduino Uno for sensor acquisition and processing, while the ESP32 handles wireless data communication and remote monitoring.

# 🛠️ Hardware Components :-

The prototype uses the following electronic components:

1. **Arduino Uno:** Acts as the primary microcontroller. It collects sensor readings, performs calculations, evaluates configured limits, and controls the display and alert system.

2. **TDS Sensor:** Measures the electrical response associated with dissolved substances in water and provides an approximate TDS reading.

3. **pH Sensor Module:** Measures the pH level of the water sample to identify acidic or alkaline conditions.

4. **Turbidity Sensor:** Detects changes in the optical properties of water and estimates its turbidity.

5. **DHT11 Sensor:** Measures temperature and humidity. Temperature is included in the water monitoring dashboard; humidity is an additional environmental reading.

6. **HC-SR04 Ultrasonic Sensor:** Measures the distance between the sensor and the water surface for water-level estimation.

7. **ESP32 Development Board:** Receives processed sensor values from the Arduino Uno through UART communication and sends the data to the Blynk IoT platform using Wi-Fi.

8. **16×4 I2C LCD Display:** Displays TDS, turbidity, pH, temperature, water level, volume, humidity, and the configured water quality status.

9. **Red LED:** Indicates that one or more monitored parameters are outside the configured screening limits.

10. **Green LED:** Indicates that the monitored parameters satisfy the configured screening limits.

11. **Buzzer:** Provides an audible alert when the measured water quality parameters do not satisfy the programmed conditions.

12. **Resistors:** Used for electrical interfacing, including voltage-level reduction during Arduino-to-ESP32 serial communication.

13. **Breadboard and Jumper Wires:** Used for circuit prototyping and component connections.

14. **Power Supply and USB Cables:** Provide power and support programming and testing of the microcontroller boards.

# 💻 Software and Technologies :-

1. **Arduino IDE:** Used for writing, compiling, and uploading firmware to Arduino Uno and ESP32.

2. **Embedded C/C++:** Used to develop sensor-reading routines, calibration logic, water-level calculations, alert conditions, and serial communication.

3. **Arduino Libraries:** Used for interfacing with the LCD, DHT11 sensor, and serial communication modules.

4. **I2C Communication:** Used for communication between Arduino Uno and the LCD module.

5. **UART Serial Communication:** Transfers processed sensor readings from Arduino Uno to ESP32.

6. **Wi-Fi Connectivity:** Enables ESP32 to communicate with the Blynk IoT platform.

7. **Blynk IoT Platform:** Provides a remote dashboard for monitoring the five primary parameters through individual gauge widgets.

8. **Sensor Calibration and Data Processing:** Used to establish reference readings, filter ultrasonic measurements, and calculate the corresponding water quality parameters.

# ⚙️ Working Principle :-

The system operates through sensor data acquisition, calibration, processing, water quality screening, local indication, and wireless monitoring.

### 1. Multi-Sensor Data Acquisition

The sensors continuously provide analog or digital readings to the Arduino Uno.

- TDS sensor provides an analog reading corresponding to dissolved substances.
- pH sensor provides an analog voltage used for pH estimation.
- Turbidity sensor provides an analog reading corresponding to water cloudiness.
- DHT11 provides temperature and humidity readings.
- Ultrasonic sensor measures the distance between itself and the water surface.

The Arduino Uno collects these readings and processes them using the programmed logic.

### 2. TDS Measurement

The TDS sensor provides an analog output to the Arduino Uno.

The analog reading is converted into an approximate TDS value using the programmed mapping:

**TDS = map(Analog Reading, 0–1023, 0–1000)**

The resulting value is expressed in parts per million (ppm).

This provides a basic measurement channel for monitoring dissolved solids in the water sample.

### 3. pH Measurement

The pH sensor module provides an analog voltage corresponding to the water sample's pH.

The Arduino reads the analog signal and converts it into voltage. A reference voltage is established during the startup calibration routine.

The calculated pH value is then compared with the configured acceptable screening range of 6.5–8.5.

### 4. Turbidity Measurement

The turbidity sensor detects changes in the optical properties of water.

The Arduino reads its analog output and compares it against the calibrated clear-water reference and configured dirty-water reference.

The resulting reading is converted into a turbidity percentage between 0% and 100%.

This provides an indication of changes in water clarity and suspended-particle conditions.

### 5. Temperature Monitoring

The DHT11 sensor measures temperature and humidity.

The Arduino processes these readings, and temperature is included in the primary monitoring dashboard.

Temperature provides additional information about the water sample and its surrounding measurement conditions.

### 6. Ultrasonic Water Level and Volume Measurement

The HC-SR04 ultrasonic sensor is positioned above the water container.

It measures the time taken for an ultrasonic pulse to travel to the water surface and return.

The distance is calculated using:

**Distance = (Time × Speed of Sound) / 2**

The measured distance is compared with the calibrated empty and full distances:

- Empty container reference: 15.40 cm
- Full container reference: 3.58 cm

The Arduino calculates the water level percentage using:

**Water Level (%) = [(Empty Distance − Measured Distance) / (Empty Distance − Full Distance)] × 100**

The calculated percentage is constrained between 0% and 100%.

For the configured 2-litre cylindrical container, the approximate water volume is calculated as:

**Water Volume (ml) = (Water Level (%) / 100) × 2000**

Multiple ultrasonic readings and a moving-average filter are used to reduce measurement fluctuations.

### 7. Water Quality Screening and Alert System

After processing the sensor readings, the Arduino compares the measured values with the programmed screening limits.

The current prototype uses the following conditions:

| Parameter | Configured screening condition |
|---|---|
| pH | 6.5–8.5 |
| TDS | ≤ 500 ppm |
| Turbidity | ≤ 10% |

If all three conditions are satisfied, the system indicates a suitable screening result using the green LED.

If any of the conditions are violated, the red LED and buzzer are activated to indicate an alert.

The system therefore provides a simple multi-parameter screening mechanism rather than relying on TDS alone.

### 8. LCD-Based Monitoring

The 16×4 I2C LCD displays the processed sensor readings locally.

The display includes:

- TDS value
- Turbidity percentage
- pH value
- Temperature
- Water level
- Estimated water volume
- Humidity
- Water quality screening status

This allows users to observe the system's measurements without requiring an internet connection.

### 9. Arduino Uno–ESP32 Communication

The Arduino Uno acts as the master controller, while the ESP32 acts as the receiving and connectivity unit.

The two boards communicate through UART serial communication.

The Arduino sends the following comma-separated data:

**TDS, Turbidity, pH, Temperature, Water Level**

The ESP32 receives the data through its UART2 interface and separates the individual sensor values for further processing.

This arrangement separates the sensor acquisition and processing responsibilities from the wireless communication functionality.

### 10. Blynk IoT Dashboard

The ESP32 connects to a Wi-Fi network and transfers the received sensor readings to the Blynk IoT platform.

The dashboard contains five individual gauge widgets:

| Parameter | Blynk Virtual Pin |
|---|---|
| TDS | V0 |
| pH | V1 |
| Turbidity | V2 |
| Temperature | V3 |
| Water Level | V4 |

The dashboard provides a remote view of the measured water quality parameters, allowing users to monitor the system through a smartphone.

# 🧩 System Architecture :-

The system follows a master-controller and wireless-connectivity architecture.

### Sensor and Processing Unit

**INPUT SENSORS**

- TDS Sensor
- pH Sensor
- Turbidity Sensor
- DHT11 Temperature Sensor
- HC-SR04 Ultrasonic Sensor

↓

**ARDUINO UNO – MASTER CONTROLLER**

- Sensor Data Acquisition
- Calibration and Processing
- Water Level and Volume Calculation
- Water Quality Screening
- LED and Buzzer Control

↓

**LOCAL MONITORING**

- 16×4 I2C LCD
- Red LED
- Green LED
- Buzzer

### Wireless Communication Unit

**ARDUINO UNO**

↓

UART Serial Communication

↓

**ESP32 – SLAVE / CONNECTIVITY UNIT**

↓

Wi-Fi Communication

↓

**BLYNK IoT CLOUD**

↓

**SMARTPHONE DASHBOARD**

- TDS Gauge
- pH Gauge
- Turbidity Gauge
- Temperature Gauge
- Water Level Gauge

# 🔌 Important Pin Configuration :-

The following pin assignments correspond to the current Arduino Uno prototype firmware.

| Component | Arduino Uno Pin |
|---|---|
| DHT11 Data | A0 |
| pH Sensor Analog Output | A1 |
| Turbidity Sensor Analog Output | A2 |
| TDS Sensor Analog Output | A3 |
| HC-SR04 Trigger | D13 |
| HC-SR04 Echo | D12 |
| Red LED | D11 |
| Green LED | D10 |
| Buzzer | D8 |
| LCD | I2C (SDA/SCL) |
| ESP32 Serial TX | D3 (SoftwareSerial) |

### ESP32 UART2 Configuration

| ESP32 Pin | Function |
|---|---|
| GPIO16 | RX2 – Receives data from Arduino Uno |
| GPIO17 | TX2 – Not required for the current one-way communication |

A voltage divider is used between the Arduino Uno's 5V TX signal and the ESP32's 3.3V RX input. Both boards share a common ground.

# 📱 Blynk Dashboard :-

The Blynk dashboard provides a remote monitoring interface for the five primary water quality parameters.

Each parameter is displayed through a dedicated gauge widget.

**Dashboard parameters:**

1. TDS – ppm
2. pH – pH value
3. Turbidity – %
4. Temperature – °C
5. Water Level – %

The dashboard receives the values processed by the Arduino Uno through the ESP32, allowing users to view the sensor readings remotely over Wi-Fi.

# 🔬 Applications :-

The concepts demonstrated by this project can be extended to several practical applications:

1. **Rural Water Quality Monitoring:** Provides an affordable platform for monitoring multiple water quality indicators in rural areas.

2. **Mining-Affected Areas:** Supports preliminary monitoring of water samples in regions where mining activities may affect water quality.

3. **Input Water Assessment:** Helps identify abnormal pH, turbidity, or TDS readings before water enters a purification process.

4. **Water Purification Systems:** Can be integrated with suitable purification units to provide monitoring information about incoming water.

5. **Educational Laboratories:** Demonstrates the practical integration of sensors, microcontrollers, IoT communication, and embedded systems.

6. **Remote Water Monitoring:** Enables users to observe sensor readings through an internet-connected dashboard.

7. **Water Storage Monitoring:** Provides water-level and approximate volume information for storage containers.

# ⚡ Challenges Faced During Development :-

During the development of the prototype, several hardware and software integration challenges were encountered.

1. **Multi-Sensor Integration:** Interfacing TDS, pH, turbidity, temperature, and ultrasonic sensors with a single Arduino Uno required careful pin allocation and coordination of sensor readings.

2. **Sensor Calibration:** Establishing reference values for pH and turbidity was important for obtaining meaningful measurements.

3. **Ultrasonic Measurement Stability:** Fluctuations in ultrasonic readings affected water-level calculations. Multiple readings, median selection, and moving-average filtering were incorporated to improve stability.

4. **Water Volume Estimation:** Calibrating the ultrasonic sensor with the cylindrical 2-litre container required appropriate empty and full distance references.

5. **Local Alert Integration:** Coordinating the LEDs and buzzer with the programmed screening conditions required combining multiple sensor readings into a single decision.

6. **Arduino Uno–ESP32 Communication:** Establishing reliable one-way UART communication between the two boards required correct baud-rate configuration, pin connections, common grounding, and voltage-level reduction.

7. **IoT Dashboard Integration:** Transferring the received sensor values to the Blynk platform required configuring Wi-Fi connectivity, virtual pins, and individual gauge widgets.

8. **Hardware and Software Coordination:** Maintaining consistent sensor updates across the LCD, alert system, serial communication, and remote dashboard required careful firmware integration.

# 🔮 Future Scope :-

The current prototype provides a foundation for further development. Several improvements can extend its monitoring and purification capabilities:

1. **Additional Water Quality Parameters:** Integrate sensors for free chlorine, dissolved oxygen, conductivity, ORP, and other relevant water quality indicators.

2. **Advanced Turbidity Measurement:** Improve turbidity calibration and measurement accuracy using a properly calibrated optical sensing arrangement.

3. **Automated Purification Control:** Integrate suitable pumps, valves, and filtration stages to support controlled purification based on measured input-water conditions.

4. **Before-and-After Water Analysis:** Introduce additional sensing points to compare water quality before and after purification.

5. **Advanced IoT Dashboard:** Add historical data logging, parameter trends, notifications, and sensor-health information.

6. **Improved Decision-Making:** Develop a more comprehensive water quality assessment mechanism using validated sensor calibration and suitable water quality standards.

7. **Remote Monitoring and Alerts:** Extend the dashboard with notifications when monitored parameters exceed configured limits.

8. **Improved Sensor Accuracy:** Use more reliable sensors and standard calibration procedures to improve measurement consistency.

9. **Power Optimization:** Explore low-power operation and alternative power sources for deployment in remote locations.

# 📌 Important Notes and Limitations :-

- This project is an educational and prototype-level water quality monitoring and screening system.
- TDS values in the current firmware are calculated using a simple analog mapping. They should not be treated as laboratory-calibrated TDS measurements.
- pH and turbidity readings depend on sensor calibration and measurement conditions.
- The DHT11 is used for temperature and humidity measurement; humidity is not a water quality parameter.
- The ultrasonic sensor measures water level and estimates volume. It does not measure water purity.
- The configured screening limits are prototype conditions and do not establish that water is safe to drink.
- The system does not replace laboratory testing or certified drinking-water assessment.
- Physical purification performance should only be claimed after suitable purification hardware has been implemented and validated.

**The primary objective of this project is to demonstrate how multiple water quality parameters can be monitored together to provide a broader assessment of input water quality beyond TDS.**
<img width="693" height="426" alt="Screenshot 2026-11-08 173621" src="https://github.com/user-attachments/assets/bd883c19-5308-4473-92c3-e5ca25aab91a" />
