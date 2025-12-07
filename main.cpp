#include <iostream>
#include <string>
#include "BMETSystem.h"
using namespace std;

static MedicalEquipment inputEquipment() {
    int id; string name, model, location, status;
    cout << "ID: "; cin >> id; cin.ignore();
    cout << "Name: "; getline(cin, name);
    cout << "Model: "; getline(cin, model);
    cout << "Location: "; getline(cin, location);
    cout << "Status (OK/SCHEDULED/DUE/FAIL): "; getline(cin, status);
    return MedicalEquipment(id, name, model, location, status);
}

static CalibrationRecord inputRecord() {
    int idRecord, idEquipment;
    string date, result, notes;
    cout << "Record ID: "; cin >> idRecord;
    cout << "Equipment ID: "; cin >> idEquipment; cin.ignore();
    cout << "Date (YYYY-MM-DD): "; getline(cin, date);
    cout << "Result (PASS/FAIL): "; getline(cin, result);
    cout << "Notes: "; getline(cin, notes);
    return CalibrationRecord(idRecord, idEquipment, date, result, notes);
}

int main() {
    BMETSystem system;
    int roleChoice;

    while (true) {
        cout << "\n === BMET Calibration Manager ===\n";
        cout << "1. Admin BMET\n";
        cout << "2. BMET Technician\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> roleChoice;

        if (roleChoice == 0) break;

        if (roleChoice == 1) {
            int c;
            do {
                cout << "\n --- Admin Menu ---\n";
                cout << "1. Add Medical Equipment (F-01)\n";
                cout << "2. Edit Medical Equipment (F-02)\n";
                cout << "3. Delete Medical Equipment (F-03)\n";
                cout << "4. List Medical Equipment (F-04)\n";
                cout << "5. Schedule for Calibration (F-05)\n";
                cout << "6. Load Input File (F-08)\n";
                cout << "7. Save Output File (F-09)\n";
                cout << "0. Back\n";
                cout << "Choice: ";
                cin >> c; cin.ignore();

                if (c == 1) {
                    auto eq = inputEquipment();
                    system.addEquipment(eq);
                }
                else if (c == 2) {
                    int id; cout << "Equipment ID to edit: "; cin >> id; cin.ignore();
                    auto eq = inputEquipment();
                    system.editEquipment(id, eq);
                }
                else if (c == 3) {
                    int id; cout << "Equipment ID to delete: "; cin >> id;
                    system.deleteEquipment(id);
                }
                else if (c == 4) {
                    system.listEquipments();
                }
                else if (c == 5) {
                    int idEq; string dueDate;
                    cout << "Equipment ID: "; cin >> idEq; cin.ignore();
                    cout << "Due date (YYYY-MM-DD): "; getline(cin, dueDate);
                    system.createSchedule(idEq, dueDate);
                }
                else if (c == 6) {
                    system.loadFromFile("input.txt");
                }
                else if (c == 7) {
                    system.saveToFile("output.txt");
                }
            } while (c != 0);
        }
        else if (roleChoice == 2) {
            int c;
            do {
                cout << "\n--- Technician Menu ---\n";
                cout << "1. List Medical Equipment (F-04)\n";
                cout << "2. Input Calibration Report (F-06)\n";
                cout << "3. History of Calibration (F-07)\n";
                cout << "0. Back\n";
                cout << "Choice: ";
                cin >> c; cin.ignore();

                if (c == 1) {
                    system.listEquipments();
                }
                else if (c == 2) {
                    system.listEquipments(); 
                    auto rec = inputRecord();
                    system.addCalibrationRecord(rec);
                }
                else if (c == 3) {
                    int idEq; cout << "Equipment ID: "; cin >> idEq;
                    system.showHistory(idEq);
                }
            } while (c != 0);
        }
    }

    cout << "Exiting...\n";
    return 0;
}
