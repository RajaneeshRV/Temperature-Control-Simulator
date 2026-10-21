# Embedded Temperature Control Simulator in C

A C program that simulates a temperature-controlled cooling fan.
It processes predefined temperature readings, controls the fan using
hysteresis, detects out-of-range readings, displays overheating
warnings, and saves results to a CSV file.

I built this project to practice C programming and learn control
logic that I plan to adapt to a hardware version.

## Features

- Simulated temperature readings stored in an array.
- Fan turns ON at 80°F or above.
- Fan turns OFF at 75°F or below.
- Between 75°F and 80°F, the fan keeps its previous state.
- Overheating warnings at 95°F or above.
- Sensor range validation from -40°F to 125°F.
- CSV logging of reading numbers, temperatures, and fan states.

## How to Compile and Run

You need GCC installed. Open a terminal in the folder containing
Tempcontrol.c.

Compile:

```bash
gcc -Wall -Wextra Tempcontrol.c -o Tempcontrol.exe
```

Run on Windows using PowerShell:

```powershell
.\Tempcontrol.exe
```

Run using Git Bash or MSYS2:

```bash
./Tempcontrol.exe
```

The program automatically processes the temperatures in the readings
array. To try different temperatures, edit the array, save, and compile
again.

## CSV Output

The program creates temperature_log.csv in the terminal's current
folder. Each run overwrites the previous file.

Example:

```csv
reading,temperature,fan
1,74.0,0
2,78.0,1
3,60.0,1
```

- reading: Reading number, starting at 1.
- temperature: Temperature in degrees Fahrenheit.
- fan: 0 means OFF; 1 means ON.

At 78°F, the fan stays ON in this example because the previous
reading turned it on and the temperature has not dropped to 75°F.

## Testing

I manually tested the following behavior:

- The fan starts OFF.
- At 80°F, the fan turns ON.
- At 75°F, the fan turns OFF.
- Between 75°F and 80°F, the previous fan state is preserved.
- At 80°F or above, an overheating warning appears.
- Readings of -40°F and 125°F are accepted.
- Readings below -40°F or above 125°F cause an error and
  end the program.
- Fan states in the CSV match the terminal output.

## Limitations

- Temperature readings come from a predefined array.
- The program does not connect to a physical sensor or fan.
- Fan operation does not affect the simulated temperatures.
- Readings are processed without real-time delays.
- Temperature thresholds are practice settings for this simulator.

## Future Improvements

I plan to extend this project into a hardware version:

- Connect a temperature sensor to a microcontroller.
- Adapt the fan-control function to operate a physical fan
  through a suitable driver circuit.
- Test the controller with measured temperatures.