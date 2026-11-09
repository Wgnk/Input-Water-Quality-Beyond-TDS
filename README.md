# 💧 AQUENZA – Smart Water Purification and Quality Monitoring System

**Input-Water Intelligence Beyond TDS**

AQUENZA is a low-cost, Arduino-based multi-parameter water quality monitoring and screening prototype developed for the **Water Purifier Track of Atomberg AtomQuest 2026**.

The project addresses the limitations of conventional water monitoring approaches that primarily focus on Total Dissolved Solids (TDS). Since TDS alone cannot provide a complete picture of water quality, AQUENZA combines multiple sensing parameters, including TDS, pH, turbidity, temperature, and water level, to provide a broader assessment of input water conditions.

The system integrates multiple sensors with an **Arduino Uno**, which performs sensor data acquisition, measurement processing, threshold evaluation, and local alert generation. An **HC-05 Bluetooth module** provides wireless serial communication between the hardware and the monitoring interface.

A major component of the project is **AQUENZA – Custom Web Dashboard**, a dedicated HTML, CSS, and JavaScript-based monitoring platform. It provides live sensor visualization, colour-coded water quality classification, historical data logging, statistical analytics, smart observations, configurable alerts, event monitoring, and downloadable reports.

The platform is designed to make water monitoring more understandable by presenting sensor measurements alongside their trends, screening conditions, and monitoring events.

---

# 🚀 Project Overview

Conventional water quality monitoring systems often emphasize TDS as a primary indicator. However, water samples with similar TDS values may have different pH levels and turbidity conditions.

AQUENZA addresses this limitation by monitoring multiple parameters simultaneously:

1. **TDS Monitoring:** Estimates the concentration of dissolved substances in water.
2. **pH Monitoring:** Identifies acidic, neutral, or alkaline conditions.
3. **Turbidity Monitoring:** Estimates water cloudiness caused by suspended particles.
4. **Temperature Monitoring:** Measures temperature using a DHT11 sensor.
5. **Water Level Monitoring:** Measures the water surface distance using an ultrasonic sensor.
6. **Water Volume Estimation:** Calculates approximate available water volume based on calibrated container dimensions.

The Arduino Uno processes the sensor readings and controls the LCD, LEDs, and buzzer. The HC-05 transfers the processed readings to the AQUENZA web dashboard.

The dashboard converts incoming measurements into meaningful visual information through gauges, status indicators, graphs, statistics, alerts, and historical records.

AQUENZA follows a simple concept:

**SENSE → PROCESS → ANALYSE → ALERT → MONITOR**

---

# ✨ Key Features

## 1. Multi-Parameter Water Quality Monitoring

- Simultaneous monitoring of TDS, pH, turbidity, temperature, and water level.
- Individual dashboard components for each measured parameter.
- Configured screening limits for identifying unusual readings.
- Local processing through Arduino Uno.

## 2. AQUENZA Custom Web Dashboard

- Dedicated web-based monitoring interface.
- Custom-designed dashboard using HTML5, CSS3, and JavaScript.
- Responsive desktop and mobile layouts.
- Dedicated navigation sections for Dashboard, History, Smart Analytics, Events, Automations, Web Dashboard, and Mobile Dashboard.
- Live connection indicator for Bluetooth serial communication.
- Incoming packet counter to display received sensor-data packets.

## 3. Live Sensor Gauges

Individual graphical gauges display the latest readings for:

| Parameter | Display Unit |
|---|---|
| TDS | ppm |
| pH | pH value |
| Turbidity | % |
| Temperature | °C |
| Water Level | % |

The gauges update as new sensor readings arrive from the Arduino.

## 4. Three-Level Colour-Coded Water Quality Status

AQUENZA provides a dedicated water quality status section with a circular monitoring-score visualization and three colour-coded classifications.

- **GREEN – SAFE:** The monitored parameters are within the configured screening limits.
- **ORANGE – CAUTION:** One or more parameters have crossed a caution threshold and require attention.
- **RED – DANGER:** One or more parameters have crossed a configured danger threshold.

The dashboard also displays:

- Current water quality classification.
- Live monitoring score out of 100.
- A descriptive status message.
- Identification of affected parameters.
- Details explaining why a particular status was assigned.
- Automatic status updates when new readings are received.

The status classification uses configured thresholds for pH, TDS, turbidity, and temperature.

**Important:** These are prototype screening classifications. They do not certify that water is safe to drink.

## 5. 360° Water Quality Monitoring Score

- Circular score visualization representing the current monitoring result.
- Score displayed on a 0–100 scale.
- Score updates according to the configured warning and danger conditions.
- Colour changes according to the current classification.
- Helps users understand the overall monitoring condition at a glance.

The score is a programmed monitoring indicator, not a scientifically validated drinking-water quality index.

## 6. Horizontal Water Level Monitoring

- Displays water level using a horizontal progress indicator.
- Provides a visual representation of available water in the container.
- Updates with incoming ultrasonic sensor readings.
- Makes water-level information easier to interpret without relying on another circular gauge.

## 7. Historical Sensor Data Logging

The dashboard maintains a record of incoming sensor readings.

Historical records include:

- Timestamp.
- pH.
- Turbidity percentage.
- TDS in ppm.
- Temperature in °C.
- Water level percentage.

Additional capabilities include:

- Automatic insertion of new readings into the history.
- Locally stored sensor records using browser local storage.
- Restoration of previously stored readings when the dashboard is reopened.
- A historical readings table.
- Export of sensor history as a CSV file.
- An option to clear stored sensor readings.

The dashboard retains up to 3,000 sensor samples in its local storage dataset.

## 8. Historical Graphs and Trend Visualization

AQUENZA provides graphical representations of sensor readings to help users observe changes over time.

Features include:

- Individual historical graphs for TDS, pH, turbidity, and temperature.
- Live graph updates when new sensor data arrives.
- Time-range selection for:
  - 1 hour
  - 6 hours
  - 24 hours
- Graph scaling and redrawing when the dashboard layout changes.
- Visual representation of sensor variations over the selected period.

These graphs help identify changes in measured water parameters rather than relying on a single reading.

## 9. AQUENZA Smart Analytics

The Smart Analytics section performs local statistical analysis using the sensor readings received from the Arduino.

It provides four major monitoring indicators:

| Analytics Indicator | Description |
|---|---|
| Data Points | Total number of stored sensor samples |
| Quality Score | Latest configured monitoring score out of 100 |
| Safe Sample Rate | Percentage of stored samples classified as SAFE |
| Last Reading | Time and date of the latest recorded sample |

### Parameter Statistics

The dashboard calculates statistical information for all five monitored parameters.

| Parameter | Average | Minimum | Maximum | Latest Trend |
|---|---|---|---|---|
| pH | Calculated | Calculated | Calculated | Rising / Falling / Stable |
| TDS | Calculated | Calculated | Calculated | Rising / Falling / Stable |
| Turbidity | Calculated | Calculated | Calculated | Rising / Falling / Stable |
| Temperature | Calculated | Calculated | Calculated | Rising / Falling / Stable |
| Water Level | Calculated | Calculated | Calculated | Rising / Falling / Stable |

The latest trend is determined by comparing recent readings, using up to the latest five samples.

### Smart Observations

The analytics engine generates observations based on the received sensor data.

Examples include:

- Current water quality classification and monitoring score.
- pH readings outside the configured target range.
- TDS readings above the configured caution threshold.
- Turbidity readings above the configured caution threshold.
- Temperature readings above the configured caution threshold.
- The largest parameter change compared with the previous sensor packet.
- Recent 10-sample average TDS when sufficient readings are available.
- Informational messages when no configured warning thresholds are crossed.

These observations help users understand which parameters require attention and how readings are changing.

## 10. Configurable Automations and Alerts

The Automations & Alerts section provides configurable browser-side monitoring rules.

Users can enable or disable individual alert conditions:

| Alert Rule | Configured Condition |
|---|---|
| pH Alert | pH below 6.5 or above 8.5 |
| TDS Alert | TDS above 500 ppm |
| Turbidity Alert | Turbidity above 10% |
| Water Level Alert | Water level below 20% |
| Temperature Alert | Temperature above 40 °C |

Additional capabilities:

- Individual checkbox-based alert configuration.
- Save alert preferences in browser local storage.
- Restore saved preferences when reopening the dashboard.
- Generate an event when an enabled condition becomes active.
- Avoid repeatedly generating the same alert for every incoming packet while that condition remains active.
- Reset alert selections through the available cancel/reset control.

These rules operate within the web dashboard. They do not automatically control a pump, valve, or purification mechanism.

## 11. Event Monitoring and Notifications

The Events section records important monitoring activities.

Examples include:

- HC-05 connection events.
- Water quality status changes.
- Parameter threshold alerts.
- Saved dashboard settings.
- Stored sensor history restoration.
- Dashboard initialization.
- Local storage warnings.
- Historical data clearing events.

The event interface includes:

- Event count.
- Latest event list.
- Event timestamps.
- Colour-coded event indicators.
- Informational, warning, and normal event categories.
- A separate Events section and a latest-events panel.

The dashboard maintains a limited event history and displays recent events for quick inspection.

## 12. CSV Data Export and Reporting

AQUENZA includes two separate data-export functions.

**Sensor History Export**

Exports recorded sensor readings with:

- Timestamp.
- pH.
- Turbidity.
- TDS.
- Temperature.
- Water level.

Generated filename:

`aquenza-water-history.csv`

**Smart Analytics Export**

Exports sensor readings along with calculated monitoring information:

- Timestamp.
- pH.
- Turbidity.
- TDS.
- Temperature.
- Water level.
- Monitoring score.
- Water quality classification.

Generated filename:

`aquenza-analytics-report.csv`

These files can be opened in spreadsheet applications for further examination and reporting.

## 13. Local Data Storage and Restoration

- Uses browser local storage to preserve sensor history.
- Restores previously stored readings when the dashboard is reopened.
- Restores the latest recorded measurements.
- Restores saved alert preferences.
- Continues live monitoring if the browser storage becomes full, while generating a warning that new readings could not be saved.
- Provides an option to clear stored sensor history.

Data is stored locally in the browser rather than automatically uploaded to a cloud server.

## 14. Bluetooth-Based Wireless Communication

- Uses the HC-05 Bluetooth module.
- UART serial communication between Arduino Uno and HC-05.
- Configured baud rate of 9600.
- Wireless serial data transfer to a compatible monitoring device.
- Live packet reception and parsing by the dashboard.
- Connect and disconnect controls.
- Bluetooth connection status indicator.

The dashboard supports structured JSON readings and comma-separated sensor readings.

For comma-separated input, the dashboard parser expects:

`pH,Turbidity,TDS,Temperature,WaterLevel`

Example:

`6.95,0.0,11,28.80,20.0`

The exact format transmitted by the Arduino firmware should match the dashboard parser.

## 15. Responsive Desktop and Mobile Interface

- Responsive dashboard layout.
- Dedicated Web Dashboard section.
- Dedicated Mobile Dashboard section.
- Adaptive layout for different screen sizes.
- Sensor information and monitoring sections designed for convenient viewing.

---

# 🛠️ Hardware Components

| Component | Purpose |
|---|---|
| Arduino Uno | Primary microcontroller for sensor acquisition and processing |
| TDS Sensor | Estimates dissolved-solids concentration |
| pH Sensor Module | Measures pH of the water sample |
| Turbidity Sensor | Estimates water cloudiness |
| DHT11 Sensor | Measures temperature and humidity |
| HC-SR04 Ultrasonic Sensor | Measures water surface distance |
| HC-05 Bluetooth Module | Provides wireless serial communication |
| 16×4 I2C LCD | Displays local sensor measurements |
| Red LED | Indicates an alert condition |
| Green LED | Indicates readings within configured screening limits |
| Buzzer | Provides audible alerts |
| Resistors | Used for electrical interfacing and voltage reduction |
| Breadboard and Jumper Wires | Used for circuit prototyping |
| USB Cable and Power Supply | Provide power and programming connectivity |

---

# 💻 Software and Technologies

1. **Arduino IDE:** Firmware development, compilation, and uploading.
2. **Embedded C/C++:** Sensor acquisition, calibration, calculations, and alert logic.
3. **HTML5:** Structure of the AQUENZA web dashboard.
4. **CSS3:** Dashboard styling, layouts, responsive design, and visual indicators.
5. **JavaScript:** Sensor-data processing, dashboard updates, analytics, event generation, and user interactions.
6. **LiquidCrystal_I2C Library:** LCD interfacing.
7. **DHT Library:** DHT11 sensor interfacing.
8. **I2C Communication:** Communication between Arduino Uno and LCD.
9. **UART Serial Communication:** Data transmission between Arduino Uno and HC-05.
10. **Web Serial API:** Browser-based serial-port communication where supported.
11. **Browser Local Storage:** Local persistence of sensor history and alert settings.
12. **JavaScript Canvas:** Rendering historical sensor graphs.
13. **CSV Export:** Downloading sensor history and analytics reports.

---

# ⚙️ Working Principle

The system operates through sensor acquisition, data processing, screening, local indication, Bluetooth transmission, and dashboard-based analytics.

## 1. Multi-Sensor Data Acquisition

The Arduino Uno collects readings from the connected sensors:

- TDS sensor provides an analog signal.
- pH sensor provides an analog voltage.
- Turbidity sensor provides an analog signal.
- DHT11 provides temperature and humidity readings.
- HC-SR04 measures the distance between the sensor and water surface.

The Arduino processes the measurements using the programmed firmware.

## 2. TDS Measurement

The TDS sensor produces an analog output associated with dissolved substances.

The current prototype firmware uses an analog conversion or mapping approach to estimate TDS in ppm.

The resulting value is used for preliminary screening. It is not a laboratory-calibrated measurement unless validated against a suitable reference.

## 3. pH Measurement

The pH module produces an analog voltage corresponding to the water sample's pH.

The Arduino converts the analog reading into voltage and applies the programmed calibration logic to estimate pH.

The configured target range is 6.5–8.5.

## 4. Turbidity Measurement

The turbidity sensor detects changes in the optical properties of water.

The Arduino processes the analog output using the programmed reference values and converts it into a percentage between 0% and 100%.

The percentage represents the prototype's calibrated turbidity indication, not a direct NTU measurement.

## 5. Temperature Monitoring

The DHT11 measures temperature and humidity.

Temperature is included in the dashboard's monitoring and analytics system.

The DHT11 is an ambient temperature and humidity sensor; it should not be treated as a waterproof water-temperature probe.

## 6. Water Level and Volume Estimation

The HC-SR04 ultrasonic sensor measures the distance between the sensor and the water surface.

Distance is calculated using:

**Distance = (Time × Speed of Sound) / 2**

The current calibration references are:

- Empty container distance: 15.40 cm
- Full container distance: 3.58 cm

Water level is calculated using:

**Water Level (%) = [(Empty Distance − Measured Distance) / (Empty Distance − Full Distance)] × 100**

The result is constrained between 0% and 100%.

For the configured 2-litre container:

**Water Volume (ml) = (Water Level (%) / 100) × 2000**

This is an approximate estimate based on the calibrated container geometry.

## 7. Water Quality Screening

The Arduino evaluates the configured screening conditions.

| Parameter | Prototype Screening Condition |
|---|---|
| pH | 6.5–8.5 |
| TDS | ≤ 500 ppm |
| Turbidity | ≤ 10% |

If all three conditions are satisfied, the hardware indicates the configured in-range condition using the green LED.

If one or more conditions are violated, the red LED and buzzer indicate an alert.

The dashboard independently evaluates received pH, TDS, turbidity, and temperature values using its three-level classification logic.

### Dashboard Classification Thresholds

| Parameter | SAFE | CAUTION | DANGER |
|---|---|---|---|
| pH | 6.5–8.5 | 6.0–6.5 or 8.5–9.0 | Below 6.0 or above 9.0 |
| TDS | ≤ 500 ppm | Above 500 to 600 ppm | Above 600 ppm |
| Turbidity | ≤ 10% | Above 10% to 20% | Above 20% |
| Temperature | ≤ 40 °C | Above 40 °C to 45 °C | Above 45 °C |

The dashboard's water-level and temperature alert rules are configurable separately. A water level below 20% generates an alert when its rule is enabled.

## 8. Monitoring Score Calculation

The dashboard calculates a configured monitoring score.

- Starts at 100.
- Deducts 10 points for each caution condition.
- Deducts 25 points for each danger condition.
- The final score cannot fall below zero.

The score is intended to summarize the dashboard's programmed screening conditions. It is not a certified water-quality index.

## 9. LCD-Based Monitoring

The 16×4 I2C LCD displays locally processed sensor information.

Depending on the firmware display layout, it can present:

- TDS.
- Turbidity.
- pH.
- Temperature.
- Humidity.
- Water level.
- Estimated volume.
- Water quality status.

The local display operates independently of the web dashboard.

## 10. Arduino Uno–HC-05 Communication

The Arduino Uno sends processed sensor readings through UART serial communication.

The HC-05 transfers these readings wirelessly to a compatible monitoring device.

The web dashboard receives serial data at 9600 baud and processes incoming readings to update the interface.

## 11. Dashboard Processing and Analytics

After receiving a valid sensor packet, the dashboard:

1. Parses the incoming data.
2. Updates the live sensor gauges.
3. Updates historical graphs.
4. Adds a timestamped sensor record.
5. Stores readings locally where browser storage is available.
6. Evaluates the current water quality classification.
7. Updates the circular monitoring score.
8. Generates smart observations.
9. Evaluates enabled alert rules.
10. Records relevant monitoring events.

This provides a combined live monitoring and historical analysis experience.

---

# 🧩 System Architecture

AQUENZA follows a centralized embedded-processing architecture with Bluetooth-based wireless monitoring.

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
- Screening Threshold Evaluation
- LED and Buzzer Control
- Serial Data Formatting

↓

**LOCAL MONITORING**

- 16×4 I2C LCD
- Red LED
- Green LED
- Buzzer

### Wireless Monitoring Unit

**ARDUINO UNO**

↓

UART Serial Communication

↓

**HC-05 BLUETOOTH MODULE**

↓

Wireless Bluetooth Serial Communication

↓

**COMPATIBLE MONITORING DEVICE**

↓

**AQUENZA – CUSTOM WEB DASHBOARD**

- Live Sensor Gauges
- Three-Level Water Status
- 360° Monitoring Score
- Horizontal Water Level Indicator
- Historical Graphs
- Sensor History
- Smart Analytics
- Parameter Statistics
- Smart Observations
- Events and Notifications
- Configurable Automations and Alerts
- CSV Data Export
- Local Data Storage

---

# 🔌 Important Pin Configuration

The following assignments correspond to the current Arduino Uno prototype firmware.

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
| LCD | I2C SDA/SCL |
| HC-05 TXD | D0 / RX |
| HC-05 RXD | D1 / TX through voltage divider |

### HC-05 Connections

| HC-05 Pin | Arduino Uno Connection |
|---|---|
| VCC | 5V, depending on breakout-board specifications |
| GND | GND |
| TXD | Arduino RX – D0 |
| RXD | Arduino TX – D1 through a voltage divider |

**Important:** The HC-05 RX input requires suitable logic-level interfacing. Use a voltage divider between Arduino TX and HC-05 RX.

The hardware UART pins D0 and D1 are shared with USB serial communication. Disconnect the HC-05 serial connections during firmware uploading if they interfere with programming.

---

# 🌐 AQUENZA Dashboard Modules

The web dashboard is organized into dedicated sections.

| Dashboard Section | Main Functionality |
|---|---|
| Dashboard | Live gauges, water status, monitoring score, and graphs |
| History | Timestamped sensor readings and CSV export |
| Smart Analytics | KPIs, parameter statistics, trends, and smart observations |
| Events | Historical monitoring events and alerts |
| Automations | Configurable browser-side alert rules |
| Web Dashboard | Information about the browser monitoring interface |
| Mobile Dashboard | Responsive mobile monitoring interface |

---

# 🔬 Applications

1. **Rural Water Monitoring:** Affordable preliminary monitoring of multiple water quality indicators.
2. **Mining-Affected Areas:** Supports observation of abnormal pH, dissolved-solids, and turbidity readings.
3. **Input-Water Assessment:** Helps identify unusual readings before water enters a purification process.
4. **Water Purification Systems:** Can be extended to monitor input and output water conditions.
5. **Educational Laboratories:** Demonstrates sensor integration, embedded processing, wireless communication, and web technologies.
6. **Wireless Water Monitoring:** Enables monitoring through a compatible Bluetooth-connected device.
7. **Water Storage Monitoring:** Provides water-level and approximate volume information.
8. **Historical Water Analysis:** Helps users observe parameter variations using stored readings and graphical trends.

---

# ⚡ Challenges Faced During Development

1. **Multi-Sensor Integration:** Coordinating multiple sensors with the Arduino Uno required careful pin allocation.
2. **Sensor Calibration:** Establishing suitable reference values for pH, TDS, and turbidity was important for meaningful measurements.
3. **Ultrasonic Measurement Stability:** Fluctuations affected water-level calculations, requiring multiple readings and filtering.
4. **Water Volume Estimation:** The ultrasonic sensor required calibration against the container's empty and full reference distances.
5. **LCD Compatibility:** Display configuration and I2C communication required testing to achieve stable operation.
6. **Alert Integration:** Combining multiple screening conditions with LED and buzzer control required coordinated firmware logic.
7. **Bluetooth Communication:** Correct baud rate, UART connections, and voltage-level interfacing were necessary.
8. **Browser Serial Integration:** Connecting HC-05 Bluetooth Classic serial communication to a browser required a compatible Web Serial environment.
9. **Live Dashboard Updates:** Incoming sensor packets had to be parsed and reflected consistently across gauges, graphs, and status indicators.
10. **Historical Data Management:** Local data persistence and restoration required handling browser storage limitations.
11. **Analytics Integration:** Statistical calculations, trend detection, and smart observations had to remain synchronized with incoming readings.
12. **Responsive Interface Design:** The dashboard needed to remain usable across desktop and mobile screen sizes.

---

# 🔮 Future Scope

1. **Additional Water Quality Parameters:** Integrate sensors for free chlorine, dissolved oxygen, conductivity, ORP, and other relevant indicators.
2. **Advanced Turbidity Measurement:** Improve calibration and measurement accuracy using a validated optical sensing arrangement.
3. **Automated Purification Control:** Integrate suitable pumps, valves, and filtration stages after implementing and validating the purification hardware.
4. **Before-and-After Water Analysis:** Introduce separate sensing points to compare water conditions before and after purification.
5. **Advanced Dashboard Analytics:** Extend historical analysis with parameter comparisons, longer-term reports, and more detailed statistical methods.
6. **Improved Decision-Making:** Develop a more comprehensive screening mechanism using validated calibration and appropriate water-quality guidance.
7. **Advanced Notifications:** Extend alert delivery through compatible notification services or applications.
8. **Improved Sensor Accuracy:** Use more reliable sensors and standard calibration procedures.
9. **Power Optimization:** Explore low-power operation and alternative power sources for remote deployment.
10. **Extended Wireless Monitoring:** Explore additional communication technologies for longer-range and multi-device monitoring.
11. **Cloud Data Integration:** Introduce optional remote storage and access to historical readings.
12. **Filter Health Monitoring:** Explore additional sensors and validated methods to observe purification-system performance over time.

---

# 📌 Important Notes and Limitations

- AQUENZA is an educational and prototype-level water quality monitoring and screening system.
- TDS values calculated using simple analog mapping are approximate and should not be treated as laboratory-calibrated measurements.
- pH and turbidity readings depend on sensor calibration and measurement conditions.
- The DHT11 measures ambient temperature and humidity; it is not a waterproof water-temperature probe.
- Humidity is an environmental measurement, not a water quality parameter.
- The ultrasonic sensor measures water level and estimates volume; it does not measure water purity.
- The dashboard's SAFE, CAUTION, and DANGER classifications are based on configured prototype thresholds.
- The monitoring score is a programmed indicator and is not a certified water-quality index.
- Browser-side alert rules do not control a pump or purifier.
- Browser local storage is local to the browser and device; it is not automatic cloud backup.
- Direct browser support for HC-05 Bluetooth Classic serial communication is not universal. The current dashboard uses the Web Serial API and requires a compatible browser and serial-port connection.
- Desktop Chrome or Edge over HTTPS or localhost is the intended Web Serial environment. A compatible Bluetooth-to-serial COM port is required.
- Android Chrome generally cannot directly access HC-05 Bluetooth Classic SPP through the Web Serial API. A compatible Android application or communication bridge may be needed.
- The system does not detect every pathogen, chemical contaminant, or other potential drinking-water hazard.
- The prototype does not replace laboratory testing or certified drinking-water assessment.
- Physical purification performance should only be claimed after suitable purification hardware has been implemented and validated.

---

# 🎯 Project Objective

The primary objective of AQUENZA is to demonstrate how multiple water quality parameters can be monitored together to provide a broader assessment of input water conditions beyond TDS alone.

By combining an Arduino-based embedded monitoring system, Bluetooth wireless communication, a responsive custom web dashboard, colour-coded screening, historical data logging, and smart analytics, AQUENZA aims to make water monitoring more informative, accessible, and understandable.

**AQUENZA – Sense More. Understand Better. Monitor Smarter.**

Dashboard images: -
<img width="1354" height="628" alt="Screenshot 2026-11-09 185511" src="https://github.com/user-attachments/assets/269c2a04-4bdd-4020-9cfc-bbe534f1b337" />
<img width="1672" height="941" alt="AQUENZA Water Quality Dashboard (1)" src="https://github.com/user-attachments/assets/92563af3-5a04-4b7d-b393-104e18c3c97d" />
Circuit Diagram :- 

<img width="693" height="426" alt="Screenshot 2026-11-08 173621" src="https://github.com/user-attachments/assets/bd883c19-5308-4473-92c3-e5ca25aab91a" />
