# Network Device & IP Manager

A menu-driven **C++ console application** for maintaining a network-device inventory, assigning and validating IPv4 addresses, tracking device status and maintenance history, and generating text-based reports.

The project demonstrates practical use of **arrays, functions, input validation, file I/O, and Windows console formatting** in a network administration scenario. It manages **manually entered device records**; it does not discover devices on a network or monitor their live connectivity.

## Features

- **Device inventory (CRUD):** Add, display, search by unique device ID, update, and delete registered devices.
- **IPv4 input checks:** Check four numeric address components (0–255) and reject IP strings already assigned to another registered device.
- **Device status:** Manually mark registered devices as **Active** or **Inactive**.
- **Network statistics:** View total, active, and inactive device counts; counts of recognized computers, routers, and switches; and the number of maintenance records.
- **Maintenance history:** Add a maintenance date and description for a device ID, and retrieve its recorded maintenance activities.
- **Text report:** Export the current inventory, status totals, and maintenance records to `network_report.txt`.
- **Local persistence:** Save and reload inventory and maintenance information using `devices.txt` and `maintenance.txt`.
- **Color-coded CLI:** Use ANSI escape codes and Windows console virtual-terminal processing for readable menus and results.

## Technologies and Concepts

| Area | Implementation |
| --- | --- |
| Language | C++ |
| Storage | Standard C++ file streams (`<fstream>`) and delimited text files |
| Data structures | Parallel fixed-size arrays |
| Input handling | `getline`, `stringstream`, and validation functions |
| Console styling | ANSI escape codes enabled through `<windows.h>` |
| Reporting | Generated `.txt` report |

## Requirements

- **Windows** (the current source uses `<windows.h>`)
- A C++ compiler such as **MinGW-w64 g++**
- Windows Terminal, Command Prompt, or a compatible ANSI-capable console

## Build and Run

1. Download or clone this project and open a terminal in the folder containing `main.cpp`.
2. Compile the application:

   ```powershell
   g++ -std=c++11 main.cpp -o NetworkDeviceManager.exe
   ```

3. Run it:

   ```powershell
   .\NetworkDeviceManager.exe
   ```

The program loads existing records at startup, when the corresponding files are present. Use **Save All Data** to persist changes, or select **Exit**, which also calls the save routine.

> Run the program from the same working directory each time so that the relative data-file paths resolve consistently.

## Main Menu

| Option | Action |
| --- | --- |
| 1 | Add New Device |
| 2 | Display All Devices |
| 3 | Search Device |
| 4 | Update Device |
| 5 | Delete Device |
| 6 | Network Statistics |
| 7 | Update Device Status |
| 8 | Add Maintenance Record |
| 9 | View Maintenance History |
| 10 | Generate Network Report |
| 11 | Save All Data |
| 12 | Exit |

## Example Workflow

**Register a device** by entering a device name, IP address, and type. The application generates a unique ID and initially marks the record **Active**.

```text
ADD NEW DEVICE
Enter Device Name: Realme
Enter IP Address: 192.168.10.1
Enter Device Type: Mobile

Device Added Successfully!
Device ID: 7
```

Next, use **Search Device** with ID `7` to retrieve the record. You can update its information, change its status, or associate it with a maintenance record. Select **Network Statistics** for inventory totals or **Generate Network Report** to export a text summary.

## Project Files

```text
Network-Device-IP-Manager/
├── main.cpp              # Main application source code
├── devices.txt           # Saved device records (created when saving)
├── maintenance.txt       # Saved maintenance records (created when saving)
├── network_report.txt    # Generated report (created on demand)
└── README.md             # Project documentation
```

The `.txt` files are local runtime data / generated output; they are not required to compile the program. For public repositories, consider excluding private device inventories and maintenance information from version control.

## Current Scope and Limitations

- Device status is **set manually**, not determined using ping, SNMP, or network scanning.
- Address validation performs basic dotted-decimal numeric checks; it is **not a complete networking configuration validator**.
- Storage uses **fixed-size arrays**, supporting up to **100 devices** and **200 maintenance records** in the current implementation.
- Statistics recognize computer, router, and switch labels using limited capitalization variants; other device types remain in the total inventory but are not counted in those specific categories.
- Records are stored in plain-text files, not a database, and the current interface targets Windows.

## Possible Future Improvements

- Automated network discovery and live connectivity checks
- Database integration (SQLite or MySQL)
- More robust IPv4 validation and subnet-aware address management
- Flexible device-type categorization and enhanced reporting
- A graphical or web-based management interface

## Project Purpose

This project was built as a hands-on exercise in **C++ programming, data management, and computer networking fundamentals**, showing how several small modules can work together as a usable network inventory utility.
