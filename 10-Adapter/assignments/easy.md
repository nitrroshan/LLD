# Assignment: Temperature Sensor Adapter (Easy)

## Objective

Apply the Adapter pattern to integrate two incompatible temperature sensor APIs into a unified interface.

## Requirements

Your weather monitoring app expects all sensors to implement:

```java
interface TemperatureSensor {
    double readCelsius();
    String getSensorId();
}
```

But you have two third-party sensor libraries with different interfaces:

**`FahrenheitSensor`** (US manufacturer):
```java
class FahrenheitSensor {
    float getTemperatureF();     // returns Fahrenheit as float
    int getDeviceCode();         // returns numeric device code
}
```

**`KelvinSensor`** (Scientific instrument):
```java
class KelvinSensor {
    double measure();            // returns Kelvin as double
    String serialNumber();       // returns serial like "KS-4092"
}
```

### What to implement

1. **`TemperatureSensor`** — target interface (Celsius, String ID)
2. **`FahrenheitSensor`** — adaptee (returns Fahrenheit, int code)
3. **`KelvinSensor`** — adaptee (returns Kelvin, String serial)
4. **`FahrenheitAdapter`** — adapts FahrenheitSensor → TemperatureSensor
   - Converts F → C: `celsius = (fahrenheit - 32) * 5.0 / 9.0`
   - Converts int code → String: `"F-" + code`
5. **`KelvinAdapter`** — adapts KelvinSensor → TemperatureSensor
   - Converts K → C: `celsius = kelvin - 273.15`
   - Passes serial number through as-is
6. **`Main`** — create both adapted sensors, read from both through the unified interface

### Expected Output

```
=== Temperature Sensor Adapter ===

Reading from all sensors:
  Sensor F-1001: 22.22°C
  Sensor KS-4092: 23.85°C

Average temperature: 23.04°C
```

## Constraints

- One file per class
- Client code must only use `TemperatureSensor` — never touch the adaptees directly
- Conversion formulas must be accurate (round to 2 decimal places for display)

## Submission

Put your solution in `10-Adapter/assignments/easy/src/{java,cpp,rust,go}/`.
