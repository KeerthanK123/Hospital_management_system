#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Patient class
class Patient {
public:
    string id, name, age, disease;

    void inputPatient() {
        cout << "Enter Patient ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Disease: ";
        cin.ignore();
        getline(cin, disease);
    }

    void displayPatient() {
        cout << left << setw(10) << id << setw(20) << name << setw(10) << age << setw(20) << disease << endl;
    }

    void savePatient() {
        ofstream file("patients.txt", ios::app);
        file << id << "," << name << "," << age << "," << disease << "\n";
        file.close();
    }

    static void viewPatients() {
        ifstream file("patients.txt");
        if (!file) {
            cout << "No patient records found!" << endl;
            return;
        }
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Age" << setw(20) << "Disease" << endl;
        cout << "-----------------------------------------------------------\n";

        string id, name, age, disease;
        while (getline(file, id, ',') && getline(file, name, ',') && getline(file, age, ',') && getline(file, disease)) {
            cout << left << setw(10) << id << setw(20) << name << setw(10) << age << setw(20) << disease << endl;
        }
        file.close();
    }
};

// Doctor class
class Doctor {
public:
    string id, name, specialty;

    void inputDoctor() {
        cout << "Enter Doctor ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Specialty: ";
        getline(cin, specialty);
    }

    void saveDoctor() {
        ofstream file("doctors.txt", ios::app);
        file << id << "," << name << "," << specialty << "\n";
        file.close();
    }

    static void viewDoctors() {
        ifstream file("doctors.txt");
        if (!file) {
            cout << "No doctor records found!" << endl;
            return;
        }
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(20) << "Specialty" << endl;
        cout << "-----------------------------------------------------------\n";

        string id, name, specialty;
        while (getline(file, id, ',') && getline(file, name, ',') && getline(file, specialty)) {
            cout << left << setw(10) << id << setw(20) << name << setw(20) << specialty << endl;
        }
        file.close();
    }
};

// Appointment class
class Appointment {
public:
    string patientID, doctorID, date;

    void bookAppointment() {
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cout << "Enter Doctor ID: ";
        cin >> doctorID;
        cout << "Enter Appointment Date (DD/MM/YYYY): ";
        cin >> date;
    }

    void saveAppointment() {
        ofstream file("appointments.txt", ios::app);
        file << patientID << "," << doctorID << "," << date << "\n";
        file.close();
    }

    static void viewAppointments() {
        ifstream file("appointments.txt");
        if (!file) {
            cout << "No appointments found!" << endl;
            return;
        }
        cout << left << setw(15) << "Patient ID" << setw(15) << "Doctor ID" << setw(15) << "Date" << endl;
        cout << "-----------------------------------------------------------\n";

        string patientID, doctorID, date;
        while (getline(file, patientID, ',') && getline(file, doctorID, ',') && getline(file, date)) {
            cout << left << setw(15) << patientID << setw(15) << doctorID << setw(15) << date << endl;
        }
        file.close();
    }
};

// Billing class
class Billing {
public:
    string patientID;
    float amount;

    void generateBill() {
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cout << "Enter Amount: ";
        cin >> amount;
    }

    void saveBill() {
        ofstream file("bills.txt", ios::app);
        file << patientID << "," << amount << "\n";
        file.close();
    }

    static void viewBills() {
        ifstream file("bills.txt");
        if (!file) {
            cout << "No billing records found!" << endl;
            return;
        }

        cout << left << setw(15) << "Patient ID" << setw(15) << "Amount" << endl;
        cout << "-----------------------------------------------------------\n";

        string line;
        while (getline(file, line)) {
            // Split the line by comma to get patientID and amount
            size_t commaPos = line.find(',');
            if (commaPos != string::npos) {
                string patientID = line.substr(0, commaPos);
                float amount = stof(line.substr(commaPos + 1)); // Convert the string to float
                cout << left << setw(15) << patientID << setw(15) << amount << endl;
            }
        }
        file.close();
    }
};


// Main menu function
void menu() {
    int choice;
    do {
        cout << "\n===== Hospital Management System =====\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Add Doctor\n";
        cout << "4. View Doctors\n";
        cout << "5. Book Appointment\n";
        cout << "6. View Appointments\n";
        cout << "7. Generate Bill\n";
        cout << "8. View Bills\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Patient p;
                p.inputPatient();
                p.savePatient();
                break;
            }
            case 2:
                Patient::viewPatients();
                break;
            case 3: {
                Doctor d;
                d.inputDoctor();
                d.saveDoctor();
                break;
            }
            case 4:
                Doctor::viewDoctors();
                break;
            case 5: {
                Appointment a;
                a.bookAppointment();
                a.saveAppointment();
                break;
            }
            case 6:
                Appointment::viewAppointments();
                break;
            case 7: {
                Billing b;
                b.generateBill();
                b.saveBill();
                break;
            }
            case 8:
                Billing::viewBills();
                break;
            case 9:
                cout << "Exiting the system...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 9);
}

// Main function
int main() {
    menu();
    return 0;
}
