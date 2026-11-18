
#include <iostream>
#include <string>
using namespace std;

// Colours - Hospital wale style me
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

const int MAX = 100;

string deviceName[MAX];
string ipAddress[MAX];
string deviceType[MAX];

int count = 0;

// STEP 1: ADD DEVICE
void addDevice()
{
    if (count >= MAX)
    {
        cout << RED << "\nStorage is full!\n" << RESET;
        return;
    }
    cout << YELLOW << "\nEnter Device Name: " << RESET;
    cin >> deviceName[count];
    cout << YELLOW << "Enter IP Address: " << RESET;
    cin >> ipAddress[count];
    cout << YELLOW << "Enter Device Type (Router/Switch/PC): " << RESET;
    cin >> deviceType[count];
    count++;
    cout << GREEN << "\nDevice Added Successfully!" << RESET << endl;
}

// STEP 2: DISPLAY ALL
void displayAllDevices()
{
    if (count == 0)
    {
        cout << RED << "\nNo Devices Found!" << RESET << endl;
        return;
    }
    cout << CYAN << "\n----- All Network Devices -----" << RESET << endl;
    for (int i = 0; i < count; i++)
    {
        cout << GREEN << i + 1 << ". Name: " << deviceName[i]
             << " | IP: " << ipAddress[i]
             << " | Type: " << deviceType[i] << RESET << endl;
    }
}

// STEP 3: SEARCH DEVICE
void searchDevice()
{
    if (count == 0)
    {
        cout << RED << "\nNo Devices Found!" << RESET << endl;
        return;
    }
    string searchName;
    cout << YELLOW << "\nEnter Device Name to Search: " << RESET;
    cin >> searchName;
    for (int i = 0; i < count; i++)
    {
        if (deviceName[i] == searchName)
        {
            cout << GREEN << "\nDevice Found!" << RESET << endl;
            cout << "Name: " << deviceName[i] << endl;
            cout << "IP: " << ipAddress[i] << endl;
            cout << "Type: " << deviceType[i] << endl;
            return;
        }
    }
    cout << RED << "\nDevice Not Found!" << RESET << endl;
}

// STEP 4: UPDATE DEVICE
void updateDevice()
{
    if (count == 0)
    {
        cout << RED << "\nNo Devices Found!" << RESET << endl;
        return;
    }
    string searchName;
    cout << YELLOW << "\nEnter Device Name to Update: " << RESET;
    cin >> searchName;
    for (int i = 0; i < count; i++)
    {
        if (deviceName[i] == searchName)
        {
            cout << YELLOW << "Enter New IP Address: " << RESET;
            cin >> ipAddress[i];
            cout << YELLOW << "Enter New Device Type: " << RESET;
            cin >> deviceType[i];
            cout << GREEN << "\nDevice Updated Successfully!" << RESET << endl;
            return;
        }
    }
    cout << RED << "\nDevice Not Found!" << RESET << endl;
}

// STEP 5: DELETE DEVICE
void deleteDevice()
{
    if (count == 0)
    {
        cout << RED << "\nNo Devices Found!" << RESET << endl;
        return;
    }
    string searchName;
    cout << YELLOW << "\nEnter Device Name to Delete: " << RESET;
    cin >> searchName;

    for (int i = 0; i < count; i++)
    {
        if (deviceName[i] == searchName)
        {
            for (int j = i; j < count - 1; j++)
            {
                deviceName[j] = deviceName[j + 1];
                ipAddress[j] = ipAddress[j + 1];
                deviceType[j] = deviceType[j + 1];
            }
            count--;
            cout << GREEN << "\nDevice Deleted Successfully!" << RESET << endl;
            return;
        }
    }
    cout << RED << "\nDevice Not Found!" << RESET << endl;
}

int main()
{
#ifdef _WIN32
    system("color");
#endif

    int choice;
    while (true)
    {
        cout << RED << "\n======================================" << RESET << endl;
        cout << RED << "      Welcome to NETWORK DEVICE & IP MANAGER" << RESET << endl;
        cout << RED << "======================================" << RESET << endl;
        cout << GREEN << "\nWe Have Management Of All Network Devices:" << RESET << endl;
        cout << endl;
        cout << BLUE << "1. Add Device" << RESET << endl;
        cout << GREEN << "2. Display All Devices" << RESET << endl;
        cout << CYAN << "3. Search Device" << RESET << endl;
        cout << YELLOW << "4. Update Device" << RESET << endl;
        cout << RED << "5. Delete Device" << RESET << endl;
        cout << YELLOW << "6. Exit" << RESET << endl;
        cout << "\nPlease select an option: ";
        cin >> choice;

        if (choice == 1)
            addDevice();
        else if (choice == 2)
            displayAllDevices();
        else if (choice == 3)
            searchDevice();
        else if (choice == 4)
            updateDevice();
        else if (choice == 5)
            deleteDevice();
        else if (choice == 6)
        {
            cout << CYAN << "\nExiting... Thank You!" << RESET << endl;
            break;
        }
        else
        {
            cout << RED << "\nInvalid Choice! Try Again." << RESET << endl;
        }
    }
    return 0;
}