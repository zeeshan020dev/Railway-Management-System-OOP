# Railway Management System in C++

This is a console-based Railway Management System developed in C++ using Object-Oriented Programming (OOP) principles. The system allows passengers to book train tickets and administrators to manage trains, staff, stations, and routes. It simulates a real-world railway reservation environment.

## Features

- **Passenger Module**:
  - Book tickets by selecting departure and arrival stations
  - Choose train timings from a schedule
  - Input personal details (Name, Age, Address, ID, Account No.)
  - View ticket details including departure/arrival time, total cost
  - Ticket cancellation feature

- **Administrator Module**:
  - Secure login (with password hint feature)
  - View list of:
    - Trains and their schedules
    - Stations and locations
    - Staff members
    - All registered passengers

- **Visual Enhancements**:
  - Color-coded output using ANSI escape codes
  - Delayed text printing for smoother CLI user experience

## How to Compile and Run

To compile and run the project, you'll need a C++ compiler like `g++`.

1. **Save the code** into a file named:
   ```
   Railway Management System (OOP Project).cpp
   ```

2. **Open a terminal/command prompt**.

3. **Navigate to the directory** containing the file.

4. **Compile the code** using:
   ```sh
   g++ "Railway Management System (OOP Project).cpp" -o RailwaySystem
   ```

   > ⚠️ This program uses `<conio.h>` and `<windows.h>`, which are Windows-specific headers. It may not compile on Linux/macOS without modifications.

5. **Run the executable**:
   ```sh
   ./RailwaySystem
   ```
   Or on Windows:
   ```sh
   RailwaySystem
   ```

## How to Use

- **Passenger Mode**:
  1. Choose your departure and arrival stations.
  2. Select a preferred train schedule.
  3. Provide your personal information.
  4. Select the number of tickets and proceed to payment.
  5. Confirm the booking to generate the ticket.

- **Administrator Mode**:
  1. Log in using:
     - **ID**: `1122`
     - **Password**: `Admin123` (Hint: 123456)
  2. Choose from various admin options to:
     - View train schedules
     - See staff member details
     - List all stations
     - View registered passengers

## Class Structure

- `Person`: Base class for both passengers and staff.
- `Passenger`: Inherits from `Person`, includes ticket booking functionality.
- `Staff`: Inherits from `Person`, includes staff ID and salary.
- `Train`: Represents train details, schedules, capacity, and loading/unloading operations.
- `Ticket`: Contains ticket details including departure/arrival info, ticket class, and pricing.
- `Station`: Manages station ID, name, and location.
- `Route`: Links stations to a route.
- `RailwayManager`: Administrator controller to manage trains, stations, passengers, staff, and routes.

## File Structure

- `Railway Management System (OOP Project).cpp`: Main C++ source file containing the entire implementation.

---

## 👤 Author

**[Muhammad Zeeshan Islam](https://github.com/zeeshan020dev)**  
Co-Founder – Unicodrex | Technical Associate – Skill Sprint

[![GitHub](https://img.shields.io/badge/GitHub-zeeshan020dev-black?logo=github)](https://github.com/zeeshan020dev)

