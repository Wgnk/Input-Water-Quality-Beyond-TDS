# 💧 Smart Water Purification and Quality Monitoring System

A low-cost, Arduino-based water quality monitoring and screening prototype developed to address the limitations of conventional water quality assessment methods that primarily focus on Total Dissolved Solids (TDS). The project monitors multiple water quality parameters, including TDS, pH, turbidity, temperature, and water level, to provide a broader understanding of input water quality.

Designed for the Water Purifier track of **Atomberg AtomQuest 2026**, the system aims to support water quality assessment, particularly in rural and mining-affected areas where water contamination can be a significant concern.

The prototype integrates multiple sensors with an **Arduino Uno** for data acquisition and processing. An **HC-05 Bluetooth module** enables wireless serial communication between the Arduino Uno and the monitoring interface. Sensor readings are displayed locally through an I2C LCD and remotely through a **custom-developed AQUENZA web dashboard**.

The custom dashboard provides live sensor monitoring, graphical data visualization, water quality status analysis, historical readings, and event notifications. Visual and audible alerts indicate whether the measured parameters fall within the configured screening limits.

# 🚀 Project Overview

Conventional water quality monitoring systems often emphasize TDS as a primary indicator of water quality. However, TDS alone cannot provide a complete picture of water suitability. Water may have acceptable TDS levels while exhibiting abnormal pH or turbidity.

To address this limitation, the proposed system monitors multiple parameters simultaneously:

1. **TDS Monitoring:** Measures the approximate concentration of dissolved solids in water.
2. **pH Monitoring:** Evaluates whether the water is acidic, neutral, or alkaline.
3. **Turbidity Monitoring:** Estimates the cloudiness of water caused by suspended particles.
4. **Temperature Monitoring:** Measures the temperature of the water sample.
5. **Water Level Monitoring:** Measures the water level and estimates the available volume inside the container using an ultrasonic sensor.

The Arduino Uno acts as the primary controller, collecting sensor readings, processing measurements, checking configured water quality limits, and controlling the LCD, LEDs, and buzzer.

An HC-05 Bluetooth module is interfaced with the Arduino Uno through UART serial communication. It transmits the processed sensor readings wirelessly to the monitoring interface, eliminating the requirement for Wi-Fi connectivity in the sensor communication system.

The received readings are presented through the custom AQUENZA web dashboard, providing a centralized interface for monitoring sensor parameters, viewing historical trends, and observing water quality alerts.

The system is designed as an affordable and expandable monitoring platform that can support better awareness of input water quality before and during purification.

# ✨ Key Features

1. **Multi-Parameter Water Quality Monitoring:** Monitors TDS, pH, turbidity, and temperature instead of relying exclusively on TDS.

2. **TDS Measurement:** Provides an approximate TDS reading using the sensor's analog output.

3. **pH Monitoring:** Measures the pH of the water sample and checks whether it falls within the configured range.

4. **Turbidity Monitoring:** Estimates water cloudiness using a turbidity sensor and displays the result as a percentage.

5. **Temperature Monitoring:** Measures temperature using a DHT11 sensor.

6. **Water Level Detection:** Uses an ultrasonic sensor to measure the distance between the sensor and the water surface.

7. **Water Volume Estimation:** Calculates the approximate water volume based on the measured water level and calibrated container dimensions.

8. **Real-Time LCD Display:** Displays sensor readings and water quality status on a 16×4 I2C LCD.

9. **Bluetooth-Based Wireless Communication:** Uses the HC-05 Bluetooth module to transfer processed sensor readings from the Arduino Uno to the monitoring interface.

10. **Custom AQUENZA Web Dashboard:** Provides a dedicated web-based monitoring interface instead of relying on third-party IoT platforms.

11. **Live Sensor Monitoring:** Displays TDS, pH, turbidity, temperature, and water level readings through individual dashboard components.

12. **360° Water Quality Status Indicator:** Provides a circular water quality score visualization to represent the overall screening result.

13. **Horizontal Water Level Indicator:** Displays the available water level through a horizontal progress bar instead of a conventional gauge.

14. **Historical Data Visualization:** Provides graphical representations of sensor readings to observe changes over time.

15. **Event and Alert Monitoring:** Displays system events, water quality alerts, and monitoring status.

16. **Visual Alert System:** Uses red and green LEDs to indicate whether the measured water parameters satisfy the configured screening conditions.

17. **Audible Alert System:** Activates a buzzer when one or more measured parameters fall outside the configured limits.

18. **Standalone Processing:** Performs sensor acquisition, calculations, screening, and alert generation locally using the Arduino Uno without requiring an internet connection for the core monitoring operation.

# 🛠️ Hardware Components

The prototype uses the following electronic components:

1. **Arduino Uno:** Acts as the primary microcontroller. It collects sensor readings, performs calculations, evaluates configured limits, and controls the display and alert system.

2. **TDS Sensor:** Measures the electrical response associated with dissolved substances in water and provides an approximate TDS reading.

3. **pH Sensor Module:** Measures the pH of the water sample to identify acidic or alkaline conditions.

4. **Turbidity Sensor:** Detects changes in the optical properties of water and estimates its turbidity.

5. **DHT11 Sensor:** Measures temperature and humidity. Temperature is included in the primary monitoring dashboard; humidity is an additional environmental reading.

6. **HC-SR04 Ultrasonic Sensor:** Measures the distance between the sensor and the water surface for water-level estimation.

7. **HC-05 Bluetooth Module:** Establishes wireless serial communication between the Arduino Uno and the monitoring interface, transmitting processed sensor values.

8. **16×4 I2C LCD Display:** Displays TDS, turbidity, pH, temperature, water level, volume, humidity, and the configured water quality status.

9. **Red LED:** Indicates that one or more monitored parameters are outside the configured screening limits.

10. **Green LED:** Indicates that the monitored parameters satisfy the configured screening limits.

11. **Buzzer:** Provides an audible alert when the measured water quality parameters do not satisfy the programmed conditions.

12. **Resistors:** Used for electrical interfacing, including voltage-level reduction where required.

13. **Breadboard and Jumper Wires:** Used for circuit prototyping and component connections.

14. **Power Supply and USB Cable:** Provide power and support programming and testing of the microcontroller.

# 💻 Software and Technologies

1. **Arduino IDE:** Used for writing, compiling, and uploading firmware to Arduino Uno.

2. **Embedded C/C++:** Used to develop sensor-reading routines, calibration logic, water-level calculations, alert conditions, and serial communication.

3. **Arduino Libraries:** Used for interfacing with the LCD and DHT11 sensor.

4. **I2C Communication:** Used for communication between Arduino Uno and the LCD module.

5. **UART Serial Communication:** Transfers processed sensor readings from Arduino Uno to the HC-05 Bluetooth module.

6. **HC-05 Bluetooth Communication:** Provides wireless serial data transmission between the hardware prototype and the monitoring interface.

7. **HTML5:** Used to structure the AQUENZA web dashboard.

8. **CSS3:** Used to design the dashboard layout, responsive interface, visual indicators, and monitoring components.

9. **JavaScript:** Handles incoming sensor data, live dashboard updates, data processing, graphical visualization, and user interactions.

10. **Bluetooth Communication Interface:** Handles the reception and interpretation of serial sensor data, subject to browser or application Bluetooth compatibility.

11. **Chart Visualization:** Displays historical sensor readings through graphical representations.

12. **Sensor Calibration and Data Processing:** Establishes reference readings, filters ultrasonic measurements, and calculates the corresponding water quality parameters.

# ⚙️ Working Principle

The system operates through sensor data acquisition, calibration, processing, water quality screening, local indication, Bluetooth communication, and web-based monitoring.

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

Multiple ultrasonic readings and a filtering mechanism are used to reduce measurement fluctuations.

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

### 9. Arduino Uno–HC-05 Bluetooth Communication

The Arduino Uno acts as the primary controller, while the HC-05 module provides wireless serial connectivity.

The HC-05 communicates with the Arduino Uno through UART serial communication.

The Arduino transmits processed sensor readings in a structured, comma-separated format.

**Data transmission format:**

`TDS,Turbidity,pH,Temperature,WaterLevel`

Example:

`11,0.0,6.95,28.80,20.0`

The transmitted data is received by the connected Bluetooth-compatible monitoring interface, where JavaScript processes the incoming values and updates the corresponding dashboard components.

This architecture eliminates the requirement for Wi-Fi connectivity between the hardware and the monitoring interface.

### 10. Custom AQUENZA Web Dashboard

Instead of using the Blynk IoT platform, the project incorporates a custom-developed web dashboard named **AQUENZA – Water Quality Monitoring**.

The dashboard is designed to provide an interactive monitoring experience with a dedicated interface for displaying live sensor readings and historical information.

**Dashboard components include:**

- Live TDS monitoring gauge (ppm).
- Live pH monitoring gauge.
- Turbidity percentage gauge.
- Temperature gauge (°C).
- Horizontal water-level progress bar (%).
- Water quality status represented through a full 360° circular indicator.
- Historical graphs for TDS, pH, turbidity, and temperature.
- Time-range selection for historical graphs, including 1-hour, 6-hour, and 1-day views.
- Latest event notifications.
- System connection and monitoring status.
- Water quality alerts and parameter status information.

The dashboard receives sensor data through the Bluetooth communication interface and updates the displayed readings as new measurements arrive.

The water-level visualization uses a horizontal bar to make the available water level easier to understand, while the circular water quality indicator provides an overall visual representation of the configured screening result.

Historical graphs help users observe parameter variations over time, while event notifications provide information about changes in monitoring and screening conditions.

The custom dashboard is designed to be responsive so that its interface can adapt to desktop and mobile screen sizes.

# 🧩 System Architecture

The system follows a centralized processing and Bluetooth-based wireless monitoring architecture.

### Sensor and Processing Unit

**INPUT SENSORS**

- TDS Sensor
- pH Sensor
- Turbidity Sensor
- DHT11 Temperature Sensor
- HC-SR04 Ultrasonic Sensor

↓

**ARDUINO UNO – PRIMARY CONTROLLER**

- Sensor Data Acquisition
- Calibration and Processing
- Water Level and Volume Calculation
- Water Quality Screening
- LED and Buzzer Control
- Serial Data Formatting

↓

**LOCAL MONITORING**

- 16×4 I2C LCD
- Red LED
- Green LED
- Buzzer

### Bluetooth Communication Unit

**ARDUINO UNO**

↓

UART Serial Communication

↓

**HC-05 BLUETOOTH MODULE**

↓

Wireless Bluetooth Serial Communication

↓

**CONNECTED MONITORING DEVICE**

↓

**AQUENZA – CUSTOM WEB DASHBOARD**

- Live Sensor Readings
- Water Quality Status
- Horizontal Water Level Indicator
- Historical Graphs
- Event Notifications
- Monitoring Status

# 🔌 Important Pin Configuration

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
| HC-05 TXD | Arduino RX (D0) |
| HC-05 RXD | Arduino TX (D1) |

### HC-05 Bluetooth Connections

| HC-05 Pin | Arduino Uno Connection |
|---|---|
| VCC | 5V (breakout-board dependent) |
| GND | GND |
| TXD | RX – D0 |
| RXD | TX – D1 through a voltage divider |

**Important:** The Arduino Uno operates at 5V logic, whereas the HC-05 RX input requires an appropriate lower logic voltage. Use a voltage divider between Arduino TX and HC-05 RX.

The HC-05 TX output can be connected to Arduino RX.

The hardware UART pins D0 and D1 are shared with USB serial communication. Disconnect the HC-05 TX/RX connections when uploading firmware if they interfere with programming. Alternatively, a SoftwareSerial connection can be used on separate digital pins.

# 🌐 AQUENZA Custom Web Dashboard

The custom AQUENZA dashboard replaces the previously considered Blynk IoT dashboard.

It provides a dedicated interface for monitoring the water quality parameters transmitted by the Arduino Uno through the HC-05 Bluetooth module.

### Live Monitoring

Five primary parameters are displayed:

| Parameter | Unit |
|---|---|
| TDS | ppm |
| pH | pH value |
| Turbidity | % |
| Temperature | °C |
| Water Level | % |

### Dashboard Visualizations

1. **Sensor Gauges:** Individual gauges display the latest TDS, pH, turbidity, and temperature readings.

2. **Water Level Bar:** A horizontal progress bar displays the current water level percentage.

3. **360° Water Quality Indicator:** A full circular indicator represents the overall water quality screening score and status.

4. **Historical Graphs:** Graphical trends display changes in TDS, pH, turbidity, and temperature.

5. **Time Filters:** Historical data can be viewed using different time ranges, such as 1 hour, 6 hours, and 1 day.

6. **Events Panel:** Displays recent monitoring events, alerts, and water quality status changes.

7. **Live Connection Indicator:** Displays the connection and monitoring state of the dashboard.

The dashboard is intended to receive real-time sensor values over Bluetooth rather than relying on cloud-based Blynk virtual pins.

# 🔬 Applications

The concepts demonstrated by this project can be extended to several practical applications:

1. **Rural Water Quality Monitoring:** Provides an affordable platform for monitoring multiple water quality indicators in rural areas.

2. **Mining-Affected Areas:** Supports preliminary monitoring of water samples in regions where mining activities may affect water quality.

3. **Input Water Assessment:** Helps identify abnormal pH, turbidity, or TDS readings before water enters a purification process.

4. **Water Purification Systems:** Can be integrated with suitable purification units to provide monitoring information about incoming water.

5. **Educational Laboratories:** Demonstrates the practical integration of sensors, microcontrollers, Bluetooth communication, and web technologies.

6. **Wireless Water Monitoring:** Enables users to observe sensor readings through a connected monitoring device without requiring Wi-Fi communication from the hardware.

7. **Water Storage Monitoring:** Provides water-level and approximate volume information for storage containers.

# ⚡ Challenges Faced During Development

During the development of the prototype, several hardware and software integration challenges were encountered.

1. **Multi-Sensor Integration:** Interfacing TDS, pH, turbidity, temperature, and ultrasonic sensors with a single Arduino Uno required careful pin allocation and coordination of sensor readings.

2. **Sensor Calibration:** Establishing reference values for pH and turbidity was important for obtaining meaningful measurements.

3. **Ultrasonic Measurement Stability:** Fluctuations in ultrasonic readings affected water-level calculations. Multiple readings and filtering techniques were incorporated to improve stability.

4. **Water Volume Estimation:** Calibrating the ultrasonic sensor with the cylindrical 2-litre container required appropriate empty and full distance references.

5. **Local Alert Integration:** Coordinating the LEDs and buzzer with the programmed screening conditions required combining multiple sensor readings into a single decision.

6. **Bluetooth Communication:** Establishing reliable serial communication between Arduino Uno and HC-05 required correct baud-rate configuration, appropriate pin connections, and voltage-level interfacing.

7. **Custom Web Dashboard Integration:** Receiving and interpreting Bluetooth serial data in the web monitoring interface required coordination between hardware communication and JavaScript-based data processing.

8. **Live Data Visualization:** Updating sensor indicators, historical graphs, and event notifications consistently required careful handling of incoming sensor values.

9. **Hardware and Software Coordination:** Maintaining consistent sensor updates across the LCD, alert system, Bluetooth communication, and web dashboard required careful firmware integration.

# 🔮 Future Scope

The current prototype provides a foundation for further development. Several improvements can extend its monitoring and purification capabilities:

1. **Additional Water Quality Parameters:** Integrate sensors for free chlorine, dissolved oxygen, conductivity, ORP, and other relevant water quality indicators.

2. **Advanced Turbidity Measurement:** Improve turbidity calibration and measurement accuracy using a properly calibrated optical sensing arrangement.

3. **Automated Purification Control:** Integrate suitable pumps, valves, and filtration stages to support controlled purification based on measured input-water conditions.

4. **Before-and-After Water Analysis:** Introduce additional sensing points to compare water quality before and after purification.

5. **Advanced Dashboard Analytics:** Add more detailed historical data analysis, parameter comparisons, and downloadable monitoring reports.

6. **Improved Decision-Making:** Develop a more comprehensive water quality assessment mechanism using validated sensor calibration and suitable water quality standards.

7. **Advanced Notifications:** Extend the monitoring interface with more detailed alerts when monitored parameters exceed configured limits.

8. **Improved Sensor Accuracy:** Use more reliable sensors and standard calibration procedures to improve measurement consistency.

9. **Power Optimization:** Explore low-power operation and alternative power sources for deployment in remote locations.

10. **Extended Wireless Monitoring:** Explore additional communication technologies for longer-range monitoring and multi-device connectivity.

# 📌 Important Notes and Limitations

- This project is an educational and prototype-level water quality monitoring and screening system.
- TDS values in the current firmware are calculated using a simple analog mapping. They should not be treated as laboratory-calibrated TDS measurements.
- pH and turbidity readings depend on sensor calibration and measurement conditions.
- The DHT11 is used for temperature and humidity measurement; humidity is not a water quality parameter.
- The ultrasonic sensor measures water level and estimates volume. It does not measure water purity.
- The configured screening limits are prototype conditions and do not establish that water is safe to drink.
- The system does not replace laboratory testing or certified drinking-water assessment.
- Physical purification performance should only be claimed after suitable purification hardware has been implemented and validated.
- Bluetooth communication requires a compatible receiving device and communication interface. Direct browser support for HC-05 Bluetooth Classic serial communication is not universal. A compatible Android application or Bluetooth-to-web communication bridge may be required for the custom web dashboard.

**The primary objective of this project is to demonstrate how multiple water quality parameters can be monitored together to provide a broader assessment of input water quality beyond TDS, using an Arduino-based embedded system, Bluetooth wireless communication, and a dedicated web monitoring interface.**
<img width="1672" height="941" alt="AQUENZA Water Quality Dashboard (1)" src="https://github.com/user-attachments/assets/92563af3-5a04-4b7d-b393-104e18c3c97d" />
<img width="693" height="426" alt="Screenshot 2026-11-08 173621" src="https://github.com/user-attachments/assets/bd883c19-5308-4473-92c3-e5ca25aab91a" />
