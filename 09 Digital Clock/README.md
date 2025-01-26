# Digital Clock in C

## Overview

This project is a simple digital clock implemented in C. It displays the current date and time, updating every second. The user can choose between a 24-hour or 12-hour time format.

## Features

- **Real-Time Updates:** Continuously displays the current time and date, updating every second.
- **Custom Time Format:** Offers a choice between 24-hour and 12-hour (AM/PM) formats.
- **Cross-Platform Compatibility:** Works on Windows, Linux, and macOS terminals.

## How It Works

1. The program uses the `time.h` library to fetch and format the current system time and date.
2. It prompts the user to select their preferred time format at the start.
3. The time and date are displayed on the console, updating every second.
4. The screen is cleared and updated seamlessly to show the latest information.

## How to Run

1. **Compile the Program:**
   Use a C compiler like GCC to compile the code:
   ```bash
   gcc -o digital_clock digital_clock.c
   ```
