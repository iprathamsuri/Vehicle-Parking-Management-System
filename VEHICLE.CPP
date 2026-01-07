#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

class Vehicle
{
    int vehicleType;   // 2 = Bike, 4 = Car
    char regno[20];
    char mobile[20];
    int entryH, entryM;
    int exitH, exitM;

public:
    void input();
    void displayRow() const;
    void save() const;

    int parkedHours() const;
    int calculateFee() const;
    void generateBill() const;

    const char* getRegNo() const;   // ✅ Getter added

    static void showAll();
    static void updateExit(const char* reg);
    static void deleteRecord(const char* reg);
};

/* ================= INPUT ================= */

void Vehicle::input()
{
    cout << "\nEnter Vehicle Type (2 = Bike, 4 = Car): ";
    cin >> vehicleType;
    cin.ignore();

    cout << "Registration Number: ";
    cin.getline(regno, 20);

    cout << "Mobile Number: ";
    cin.getline(mobile, 20);

    cout << "Entry Time (HH MM): ";
    cin >> entryH >> entryM;

    cout << "Exit Time (HH MM): ";
    cin >> exitH >> exitM;
}

/* ================= GETTER ================= */

const char* Vehicle::getRegNo() const
{
    return regno;
}

/* ================= CALCULATIONS ================= */

int Vehicle::parkedHours() const
{
    int entryMin = entryH * 60 + entryM;
    int exitMin = exitH * 60 + exitM;
    return (int)ceil((exitMin - entryMin) / 60.0);
}

int Vehicle::calculateFee() const
{
    int rate = (vehicleType == 2) ? 10 : 20;
    return parkedHours() * rate;
}

/* ================= DISPLAY ================= */

void Vehicle::displayRow() const
{
    cout << left
         << setw(8) << (vehicleType == 2 ? "Bike" : "Car")
         << setw(15) << regno
         << setw(15) << mobile
         << setw(10) << parkedHours()
         << "₹" << calculateFee() << endl;
}

/* ================= FILE SAVE ================= */

void Vehicle::save() const
{
    ofstream fout("vehicle.dat", ios::binary | ios::app);
    fout.write((char*)this, sizeof(Vehicle));
    fout.close();
}

/* ================= SHOW ALL ================= */

void Vehicle::showAll()
{
    ifstream fin("vehicle.dat", ios::binary);
    if (!fin)
    {
        cout << "\nNo records found.\n";
        return;
    }

    Vehicle v;
    cout << "\n------------------------------------------------------------\n";
    cout << left << setw(8) << "Type"
         << setw(15) << "Reg No"
         << setw(15) << "Mobile"
         << setw(10) << "Hours"
         << "Fee\n";
    cout << "------------------------------------------------------------\n";

    while (fin.read((char*)&v, sizeof(Vehicle)))
        v.displayRow();

    fin.close();
}

/* ================= UPDATE EXIT ================= */

void Vehicle::updateExit(const char* reg)
{
    fstream file("vehicle.dat", ios::binary | ios::in | ios::out);
    Vehicle v;
    bool found = false;

    while (file.read((char*)&v, sizeof(Vehicle)))
    {
        if (strcmp(v.getRegNo(), reg) == 0)
        {
            cout << "Enter new Exit Time (HH MM): ";
            cin >> v.exitH >> v.exitM;

            long pos = file.tellg();
            file.seekp(pos - sizeof(Vehicle));
            file.write((char*)&v, sizeof(Vehicle));

            cout << "Exit time updated successfully.\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Vehicle not found.\n";

    file.close();
}

/* ================= DELETE RECORD ================= */

void Vehicle::deleteRecord(const char* reg)
{
    ifstream fin("vehicle.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary);

    Vehicle v;
    bool deleted = false;

    while (fin.read((char*)&v, sizeof(Vehicle)))
    {
        if (strcmp(v.getRegNo(), reg) != 0)
            fout.write((char*)&v, sizeof(Vehicle));
        else
            deleted = true;
    }

    fin.close();
    fout.close();

    remove("vehicle.dat");
    rename("temp.dat", "vehicle.dat");

    if (deleted)
        cout << "Record deleted successfully.\n";
    else
        cout << "Vehicle not found.\n";
}

/* ================= BILL ================= */

void Vehicle::generateBill() const
{
    cout << "\n========== PARKING BILL ==========\n";
    cout << "Vehicle Type : " << (vehicleType == 2 ? "Bike" : "Car") << endl;
    cout << "Reg No       : " << regno << endl;
    cout << "Mobile       : " << mobile << endl;
    cout << "Duration     : " << parkedHours() << " Hours\n";
    cout << "Total Fee    : ₹" << calculateFee() << endl;
    cout << "=================================\n";
}

/* ================= MAIN ================= */

int main()
{
    Vehicle v;
    char choice;
    char reg[20];

    do
    {
        cout << "\n===== VEHICLE PARKING SYSTEM =====\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Display All Vehicles\n";
        cout << "3. Update Exit Time\n";
        cout << "4. Delete Vehicle\n";
        cout << "5. Generate Bill\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            v.input();
            v.save();
            cout << "Vehicle added successfully.\n";
            break;

        case '2':
            Vehicle::showAll();
            break;

        case '3':
            cout << "Enter Reg No: ";
            cin >> reg;
            Vehicle::updateExit(reg);
            break;

        case '4':
            cout << "Enter Reg No to delete: ";
            cin >> reg;
            Vehicle::deleteRecord(reg);
            break;

        case '5':
            cout << "Enter Reg No: ";
            cin >> reg;
            {
                ifstream fin("vehicle.dat", ios::binary);
                while (fin.read((char*)&v, sizeof(Vehicle)))
                {
                    if (strcmp(v.getRegNo(), reg) == 0)
                    {
                        v.generateBill();
                        break;
                    }
                }
                fin.close();
            }
            break;

        case '6':
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option!\n";
        }
    } while (choice != '6');

    return 0;
}
