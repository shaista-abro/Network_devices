
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <windows.h>

using namespace std;

const int MAX = 100;
const int MAX_MAINTENANCE = 200;

// Device Arrays
int deviceID[MAX];
string deviceName[MAX];
string ipAddress[MAX];
string deviceType[MAX];
string deviceStatus[MAX];

int count = 0;
int nextID = 1;

// Maintenance Arrays
int maintenanceDeviceID[MAX_MAINTENANCE];
string maintenanceDate[MAX_MAINTENANCE];
string maintenanceDescription[MAX_MAINTENANCE];

int maintenanceCount = 0;

// Colors
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string GREEN = "\033[32m";
const string RED = "\033[31m";
const string CYAN = "\033[36m";
const string YELLOW = "\033[33m";

// Function Declarations
void enableANSIColors();
void showMenu();
void addDevice();
void displayDevices();
void searchDevice();
void updateDevice();
void deleteDevice();
void showStatistics();
void updateDeviceStatus();
void addMaintenance();
void viewMaintenance();
void generateReport();
void saveAllData();
void loadAllData();

int findDevice(int id);
bool isValidIP(string ip);
bool isDuplicateIP(string ip, int ignoreIndex = -1);

int getInteger(string message);
string getText(string message);
void printLine();

// Enable Windows ANSI Colors
void enableANSIColors()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;

    if (GetConsoleMode(hOut, &dwMode))
    {
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }
}

// Get Integer Safely
int getInteger(string message)
{
    int value;
    string input;

    while (true)
    {
        cout << message;
        getline(cin, input);

        stringstream ss(input);

        if (ss >> value)
        {
            ss >> ws;

            if (ss.eof())
                return value;
        }

        cout << RED
             << "Invalid input! Enter a valid number.\n"
             << RESET;
    }
}

// Get Text
string getText(string message)
{
    string value;

    cout << message;
    getline(cin, value);

    return value;
}

// Print Line
void printLine()
{
    cout << CYAN
         << "================================================\n"
         << RESET;
}

// Menu
void showMenu()
{
    printLine();

    cout << CYAN << BOLD;
    cout << "          NETWORK DEVICE & IP MANAGER\n";
    cout << "================================================\n";
    cout << "          PROFESSIONAL NETWORK SYSTEM\n";
    cout << RESET;

    cout << GREEN << "1. Add New Device\n" << RESET;
    cout << CYAN << "2. Display All Devices\n" << RESET;
    cout << YELLOW << "3. Search Device\n" << RESET;
    cout << GREEN << "4. Update Device\n" << RESET;
    cout << RED << "5. Delete Device\n" << RESET;
    cout << CYAN << "6. Network Statistics\n" << RESET;
    cout << YELLOW << "7. Update Device Status\n" << RESET;
    cout << GREEN << "8. Add Maintenance Record\n" << RESET;
    cout << CYAN << "9. View Maintenance History\n" << RESET;
    cout << YELLOW << "10. Generate Network Report\n" << RESET;
    cout << GREEN << "11. Save All Data\n" << RESET;
    cout << RED << "12. Exit\n" << RESET;

    printLine();
}

// Find Device By ID
int findDevice(int id)
{
    for (int i = 0; i < count; i++)
    {
        if (deviceID[i] == id)
        {
            return i;
        }
    }

    return -1;
}

// Validate IP Address
bool isValidIP(string ip)
{
    stringstream ss(ip);
    string part;
    int dots = 0;

    while (getline(ss, part, '.'))
    {
        if (part.empty() || part.length() > 3)
            return false;

        for (int i = 0; i < part.length(); i++)
        {
            if (!isdigit(static_cast<unsigned char>(part[i])))
                return false;
        }

        int number = stoi(part);

        if (number < 0 || number > 255)
            return false;

        dots++;
    }

    return dots == 4 &&
           ip.find('.') != string::npos;
}

// Check Duplicate IP
bool isDuplicateIP(string ip, int ignoreIndex)
{
    for (int i = 0; i < count; i++)
    {
        if (i != ignoreIndex && ipAddress[i] == ip)
        {
            return true;
        }
    }

    return false;
}

// Add Device
void addDevice()
{
    if (count >= MAX)
    {
        cout << RED << "\nDevice storage is full!\n"
             << RESET;
        return;
    }

    printLine();

    cout << GREEN << BOLD
         << "             ADD NEW DEVICE\n"
         << RESET;

    printLine();

    deviceID[count] = nextID++;

    deviceName[count] = getText("Enter Device Name: ");

    while (true)
    {
        string ip = getText("Enter IP Address: ");

        if (!isValidIP(ip))
        {
            cout << RED << "Invalid IP Address!\n" << RESET;
        }
        else if (isDuplicateIP(ip))
        {
            cout << RED << "This IP already exists!\n" << RESET;
        }
        else
        {
            ipAddress[count] = ip;
            break;
        }
    }

    deviceType[count] = getText("Enter Device Type: ");

    deviceStatus[count] = "Active";

    cout << GREEN
         << "\nDevice Added Successfully!\n"
         << "Device ID: " << deviceID[count]
         << RESET << endl;

    count++;
}

// Display All Devices
void displayDevices()
{
    printLine();

    cout << CYAN << BOLD
         << "              ALL NETWORK DEVICES\n"
         << RESET;

    printLine();

    if (count == 0)
    {
        cout << YELLOW << "No devices available!\n" << RESET;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        cout << CYAN << "\nDevice ID: "
             << deviceID[i] << RESET << endl;

        cout << "Name: " << deviceName[i] << endl;
        cout << "IP Address: " << ipAddress[i] << endl;
        cout << "Type: " << deviceType[i] << endl;

        if (deviceStatus[i] == "Active")
            cout << GREEN;
        else
            cout << RED;

        cout << "Status: " << deviceStatus[i]
             << RESET << endl;

        printLine();
    }
}

// Search Device
void searchDevice()
{
    printLine();

    cout << CYAN << BOLD
         << "               SEARCH DEVICE\n"
         << RESET;

    printLine();

    int id = getInteger("Enter Device ID: ");

    int index = findDevice(id);

    if (index == -1)
    {
        cout << RED << "Device not found!\n" << RESET;
        return;
    }

    cout << GREEN << "\nDevice Found!\n" << RESET;

    cout << "Device ID: " << deviceID[index] << endl;
    cout << "Name: " << deviceName[index] << endl;
    cout << "IP Address: " << ipAddress[index] << endl;
    cout << "Type: " << deviceType[index] << endl;
    cout << "Status: " << deviceStatus[index] << endl;
}

// Update Device
void updateDevice()
{
    printLine();

    cout << YELLOW << BOLD
         << "               UPDATE DEVICE\n"
         << RESET;

    printLine();

    int id = getInteger("Enter Device ID to Update: ");

    int index = findDevice(id);

    if (index == -1)
    {
        cout << RED << "Device not found!\n" << RESET;
        return;
    }

    cout << "\nEnter New Device Information\n";

    deviceName[index] = getText("New Device Name: ");

    while (true)
    {
        string ip = getText("New IP Address: ");

        if (!isValidIP(ip))
        {
            cout << RED << "Invalid IP Address!\n" << RESET;
        }
        else if (isDuplicateIP(ip, index))
        {
            cout << RED
                 << "IP already assigned to another device!\n"
                 << RESET;
        }
        else
        {
            ipAddress[index] = ip;
            break;
        }
    }

    deviceType[index] = getText("New Device Type: ");

    cout << GREEN
         << "\nDevice Updated Successfully!\n"
         << RESET;
}

// Delete Device
void deleteDevice()
{
    printLine();

    cout << RED << BOLD
         << "               DELETE DEVICE\n"
         << RESET;

    printLine();

    int id = getInteger("Enter Device ID to Delete: ");

    int index = findDevice(id);

    if (index == -1)
    {
        cout << RED << "Device not found!\n" << RESET;
        return;
    }

    for (int i = index; i < count - 1; i++)
    {
        deviceID[i] = deviceID[i + 1];
        deviceName[i] = deviceName[i + 1];
        ipAddress[i] = ipAddress[i + 1];
        deviceType[i] = deviceType[i + 1];
        deviceStatus[i] = deviceStatus[i + 1];
    }

    count--;

    cout << GREEN
         << "Device Deleted Successfully!\n"
         << RESET;
}

// Network Statistics
void showStatistics()
{
    printLine();

    cout << CYAN << BOLD
         << "             NETWORK STATISTICS\n"
         << RESET;

    printLine();

    int active = 0;
    int inactive = 0;
    int computers = 0;
    int routers = 0;
    int switches = 0;

    for (int i = 0; i < count; i++)
    {
        if (deviceStatus[i] == "Active")
            active++;
        else
            inactive++;

        if (deviceType[i] == "computer" ||
            deviceType[i] == "Computer")
            computers++;

        else if (deviceType[i] == "router" ||
                 deviceType[i] == "Router")
            routers++;

        else if (deviceType[i] == "switch" ||
                 deviceType[i] == "Switch")
            switches++;
    }

    cout << "\nTotal Devices: " << count << endl;

    cout << GREEN << "Active Devices: "
         << active << RESET << endl;

    cout << RED << "Inactive Devices: "
         << inactive << RESET << endl;

    cout << "\nDevice Types:\n";

    cout << "Computers: " << computers << endl;
    cout << "Routers: " << routers << endl;
    cout << "Switches: " << switches << endl;

    cout << "\nTotal Maintenance Records: "
         << maintenanceCount << endl;
}

// Update Device Status
void updateDeviceStatus()
{
    printLine();

    cout << YELLOW << BOLD
         << "             UPDATE DEVICE STATUS\n"
         << RESET;

    printLine();

    int id = getInteger("Enter Device ID: ");

    int index = findDevice(id);

    if (index == -1)
    {
        cout << RED << "Device not found!\n" << RESET;
        return;
    }

    cout << GREEN << "\n1. Active\n" << RESET;
    cout << RED << "2. Inactive\n" << RESET;

    int choice = getInteger("Select New Status: ");

    if (choice == 1)
    {
        deviceStatus[index] = "Active";
    }
    else if (choice == 2)
    {
        deviceStatus[index] = "Inactive";
    }
    else
    {
        cout << RED << "Invalid choice!\n" << RESET;
        return;
    }

    cout << GREEN
         << "Device Status Updated Successfully!\n"
         << RESET;
}

// Add Maintenance Record
void addMaintenance()
{
    if (maintenanceCount >= MAX_MAINTENANCE)
    {
        cout << RED
             << "Maintenance storage is full!\n"
             << RESET;
        return;
    }

    printLine();

    cout << GREEN << BOLD
         << "             ADD MAINTENANCE RECORD\n"
         << RESET;

    printLine();

    int id = getInteger("Enter Device ID: ");

    if (findDevice(id) == -1)
    {
        cout << RED << "Device not found!\n" << RESET;
        return;
    }

    maintenanceDeviceID[maintenanceCount] = id;

    maintenanceDate[maintenanceCount] =
        getText("Enter Maintenance Date: ");

    maintenanceDescription[maintenanceCount] =
        getText("Enter Maintenance Description: ");

    maintenanceCount++;

    cout << GREEN
         << "\nMaintenance Record Added Successfully!\n"
         << RESET;
}

// View Maintenance History
void viewMaintenance()
{
    printLine();

    cout << CYAN << BOLD
         << "             MAINTENANCE HISTORY\n"
         << RESET;

    printLine();

    int id = getInteger("Enter Device ID: ");

    if (findDevice(id) == -1)
    {
        cout << YELLOW
             << "Device is not currently registered. "
             << "Checking saved history...\n"
             << RESET;
    }

    bool found = false;

    for (int i = 0; i < maintenanceCount; i++)
    {
        if (maintenanceDeviceID[i] == id)
        {
            found = true;

            cout << "\n" << CYAN
                 << "Date: " << maintenanceDate[i]
                 << RESET << endl;

            cout << "Description: "
                 << maintenanceDescription[i] << endl;

            printLine();
        }
    }

    if (!found)
    {
        cout << YELLOW
             << "No maintenance history found!\n"
             << RESET;
    }
}

// Generate Network Report
void generateReport()
{
    ofstream report("network_report.txt");

    if (!report)
    {
        cout << RED
             << "Unable to create report!\n"
             << RESET;
        return;
    }

    report << "========================================\n";
    report << "       NETWORK DEVICE & IP REPORT\n";
    report << "========================================\n\n";

    report << "Total Devices: " << count << endl;

    int active = 0;
    int inactive = 0;

    for (int i = 0; i < count; i++)
    {
        if (deviceStatus[i] == "Active")
            active++;
        else
            inactive++;
    }

    report << "Active Devices: " << active << endl;
    report << "Inactive Devices: " << inactive << endl;

    report << "\nDEVICE DETAILS\n";

    for (int i = 0; i < count; i++)
    {
        report << "\nDevice ID: " << deviceID[i] << endl;
        report << "Name: " << deviceName[i] << endl;
        report << "IP: " << ipAddress[i] << endl;
        report << "Type: " << deviceType[i] << endl;
        report << "Status: " << deviceStatus[i] << endl;
    }

    report << "\nMAINTENANCE RECORDS\n";

    for (int i = 0; i < maintenanceCount; i++)
    {
        report << "\nDevice ID: "
               << maintenanceDeviceID[i] << endl;

        report << "Date: "
               << maintenanceDate[i] << endl;

        report << "Description: "
               << maintenanceDescription[i] << endl;
    }

    report.close();

    cout << GREEN
         << "\nNetwork Report Generated Successfully!\n"
         << "File: network_report.txt\n"
         << RESET;
}

// Save All Data
void saveAllData()
{
    ofstream file("devices.txt");

    if (!file)
    {
        cout << RED
             << "Unable to save device data!\n"
             << RESET;
        return;
    }

    file << count << endl;
    file << nextID << endl;

    for (int i = 0; i < count; i++)
    {
        file << deviceID[i] << "|"
             << deviceName[i] << "|"
             << ipAddress[i] << "|"
             << deviceType[i] << "|"
             << deviceStatus[i] << endl;
    }

    file.close();

    ofstream maintenanceFile("maintenance.txt");

    if (!maintenanceFile)
    {
        cout << RED
             << "Unable to save maintenance data!\n"
             << RESET;
        return;
    }

    maintenanceFile << maintenanceCount << endl;

    for (int i = 0; i < maintenanceCount; i++)
    {
        maintenanceFile << maintenanceDeviceID[i] << "|"
                        << maintenanceDate[i] << "|"
                        << maintenanceDescription[i] << endl;
    }

    maintenanceFile.close();

    cout << GREEN
         << "\nAll Data Saved Successfully!\n"
         << RESET;
}

// Load Saved Data
void loadAllData()
{
    ifstream file("devices.txt");

    if (file)
    {
        file >> count;
        file >> nextID;

        file.ignore();

        if (count < 0 || count > MAX)
        {
            count = 0;
            nextID = 1;
            file.close();
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                string line;

                if (!getline(file, line))
                {
                    count = i;
                    break;
                }

                stringstream ss(line);
                string temp;

                if (!getline(ss, temp, '|'))
                {
                    count = i;
                    break;
                }

                try
                {
                    deviceID[i] = stoi(temp);
                }
                catch (...)
                {
                    count = i;
                    break;
                }

                getline(ss, deviceName[i], '|');
                getline(ss, ipAddress[i], '|');
                getline(ss, deviceType[i], '|');
                getline(ss, deviceStatus[i]);
            }

            file.close();
        }
    }

    ifstream maintenanceFile("maintenance.txt");

    if (maintenanceFile)
    {
        maintenanceFile >> maintenanceCount;
        maintenanceFile.ignore();

        if (maintenanceCount < 0 ||
            maintenanceCount > MAX_MAINTENANCE)
        {
            maintenanceCount = 0;
        }
        else
        {
            for (int i = 0; i < maintenanceCount; i++)
            {
                string line;

                if (!getline(maintenanceFile, line))
                {
                    maintenanceCount = i;
                    break;
                }

                stringstream ss(line);
                string temp;

                if (!getline(ss, temp, '|'))
                {
                    maintenanceCount = i;
                    break;
                }

                try
                {
                    maintenanceDeviceID[i] = stoi(temp);
                }
                catch (...)
                {
                    maintenanceCount = i;
                    break;
                }

                getline(ss, maintenanceDate[i], '|');
                getline(ss, maintenanceDescription[i]);
            }
        }

        maintenanceFile.close();
    }
}

// Main Function
int main()
{
    enableANSIColors();

    loadAllData();

    int choice;

    do
    {
        showMenu();

        choice = getInteger("\nEnter Your Choice: ");

        switch (choice)
        {
            case 1:
                addDevice();
                break;

            case 2:
                displayDevices();
                break;

            case 3:
                searchDevice();
                break;

            case 4:
                updateDevice();
                break;

            case 5:
                deleteDevice();
                break;

            case 6:
                showStatistics();
                break;

            case 7:
                updateDeviceStatus();
                break;

            case 8:
                addMaintenance();
                break;

            case 9:
                viewMaintenance();
                break;

            case 10:
                generateReport();
                break;

            case 11:
                saveAllData();
                break;

            case 12:
                saveAllData();

                cout << GREEN << BOLD
                     << "\nThank You for Using "
                     << "Network Device & IP Manager!\n"
                     << RESET;
                break;

            default:
                cout << RED
                     << "\nInvalid Choice! Please Try Again.\n"
                     << RESET;
        }

    } while (choice != 12);

    return 0;
}
