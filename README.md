**Managing a network starts with knowing what's connected, how it's configured, and what needs attention.**

Built a **Network Device & IP Manager using C++**, a console-based application designed to organize network device information, manage IP address assignments, track device status, and maintain operational records.

The objective was to translate fundamental programming concepts into a practical network administration workflow, connecting device management, data persistence, maintenance tracking, and reporting within a single system.

**Core Features & Implementation:**

🔹 **Device Inventory Management:** Implemented CRUD operations to register, search, modify, display, and remove network devices using unique device identifiers.

🔹 **IP Address Validation:** Developed IPv4 format validation and duplicate-IP detection to reduce addressing conflicts during device registration and updates.

🔹 **Device Status Management:** Added manual Active/Inactive status tracking to maintain an organized view of registered network assets.

🔹 **Network Statistics:** Implemented device categorization and statistical summaries covering total devices, active/inactive counts, and network equipment types.

🔹 **Maintenance History:** Designed a record-keeping module to associate maintenance dates and descriptions with individual network devices.

🔹 **Persistent Data Storage:** Integrated C++ file handling to save and retrieve device information and maintenance records across application sessions.

🔹 **Automated Report Generation:** Built a reporting module that exports device inventories, status summaries, and maintenance records into a structured text file.

🔹 **Interactive Command-Line Interface:** Used ANSI escape sequences and Windows console functionality to create a color-coded, menu-driven user experience.

**Technical Stack:**

C++ | Data Structures | Arrays | File Handling | IPv4 Validation | Input Validation | Windows API | Network Inventory Management

**Engineering Takeaways:**

The challenge wasn't simply storing device information. It was maintaining consistency across interconnected operations.

A newly registered device receives a unique identifier. Its IP address is checked against existing records. Its status contributes to network statistics, while maintenance activities become part of its history. These details are preserved through file-based storage and incorporated into generated reports.

This project strengthened my understanding of **data integrity, modular programming, record management, validation logic, and network administration fundamentals**.

It also established a foundation for exploring more advanced networking concepts, database-backed applications, and automated network monitoring.

The screenshots below demonstrate device registration, inventory visualization, device searching, and record updates.

**One question for network engineers and developers: What would be the most valuable next addition — live device discovery, connectivity monitoring, or database integration?**

#Cpp #ComputerNetworks #NetworkManagement #SoftwareEngineering #DataStructures #IPAddressManagement #NetworkAdministration #ComputerSystemsEngineering
