///////////////////////////////////////////////////////////
//  BMETSystem.cpp
//  Implementation of the Class BMETSystem
//  Created on:      03-Dec-2025 11:43:06 PM
//  Original author: Asus
///////////////////////////////////////////////////////////

#include "BMETSystem.h"

BMETSystem::~BMETSystem() {}
BMETSystem::BMETSystem() {}

void BMETSystem::addEquipment(MedicalEquipment equipment) {
    equipments.push_back(equipment);
    cout << "Equipment added.\n";
}

int BMETSystem::findEquipmentById(int id) {
    for (int i = 0; i < (int)equipments.size(); i++) {
        if (equipments[i].getId() == id) return i;
    }
    return -1;
}

void BMETSystem::editEquipment(int id, MedicalEquipment newData) {
    int idx = findEquipmentById(id);
    if (idx == -1) {
        cout << "Equipment not found.\n";
        return;
    }
    equipments[idx] = newData;
    cout << "Equipment updated.\n";
}

void BMETSystem::deleteEquipment(int id) {
    int idx = findEquipmentById(id);
    if (idx == -1) {
        cout << "Equipment not found.\n";
        return;
    }
    equipments.erase(equipments.begin() + idx);
    cout << "Equipment deleted.\n";
}

void BMETSystem::listEquipments() {
    if (equipments.empty()) {
        cout << "No equipment data.\n";
        return;
    }
    for (auto &e : equipments) e.displayInfo();
}

void BMETSystem::createSchedule(int idEquipment, string dueDate) {
    int idx = findEquipmentById(idEquipment);
    if (idx == -1) {
        cout << "Equipment not found.\n";
        return;
    }

    int newScheduleId = (int)schedules.size() + 1;
    CalibrationSchedule sch(newScheduleId, idEquipment, dueDate, "OPEN");
    schedules.push_back(sch);

    equipments[idx].setStatus("SCHEDULED");
    cout << "Schedule created.\n";
}

void BMETSystem::addCalibrationRecord(CalibrationRecord record) {
    int idEq = record.getIdEquipment();
    int idx = findEquipmentById(idEq);
    if (idx == -1) {
        cout << "Equipment not found. Record not added.\n";
        return;
    }

    records.push_back(record);

    equipments[idx].setStatus("OK");

    for (auto &sch : schedules) {
        if (sch.getIdEquipment() == idEq) {
            sch.markDone();
            break;
        }
    }

    cout << "Calibration record added. Equipment status set to OK by default.\n";
}

void BMETSystem::showHistory(int idEquipment) {
    bool any = false;
    for (auto &r : records) {
        if (r.getIdEquipment() == idEquipment) {
            r.displayInfo();
            any = true;
        }
    }
    if (!any) cout << "No calibration history.\n";
}

static vector<string> splitPipe(const string &line) {
    vector<string> out;
    stringstream ss(line);
    string item;
    while (getline(ss, item, '|')) out.push_back(item);
    return out;
}

void BMETSystem::loadFromFile(string filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Failed to open file.\n";
        return;
    }

    equipments.clear();
    schedules.clear();
    records.clear();

    enum Section { NONE, EQUIP, SCHED, REC };
    Section sec = NONE;

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        if (line == "[EQUIPMENTS]") { sec = EQUIP; getline(fin, line); continue; }
        if (line == "[SCHEDULES]")  { sec = SCHED; getline(fin, line); continue; }
        if (line == "[RECORDS]")    { sec = REC; getline(fin, line); continue; }

        auto parts = splitPipe(line);

        if (sec == EQUIP && parts.size() >= 5) {
            int id = stoi(parts[0]);
            string name = parts[1];
            string model = parts[2];
            string location = parts[3];
            string status = parts[4];
            equipments.push_back(MedicalEquipment(id, name, model, location, status));
        }
        else if (sec == SCHED && parts.size() >= 4) {
            int idSchedule = stoi(parts[0]);
            int idEq = stoi(parts[1]);
            string dueDate = parts[2];
            string status = parts[3];
            schedules.push_back(CalibrationSchedule(idSchedule, idEq, dueDate, status));
        }
        else if (sec == REC && parts.size() >= 5) {
            int idRecord = stoi(parts[0]);
            int idEq = stoi(parts[1]);
            string date = parts[2];
            string result = parts[3];
            string notes = parts[4];
            records.push_back(CalibrationRecord(idRecord, idEq, date, result, notes));
        }
    }
    cout << "Data loaded from " << filename << ".\n";
}

void BMETSystem::saveToFile(string filename) {
    ofstream fout(filename);
    if (!fout) {
        cout << "Failed to write file.\n";
        return;
    }

    fout << "[EQUIPMENTS]\n";
    fout << "id|name|model|location|status\n";
    for (auto &e : equipments) {
        fout << e.getId() << "|" 
             << e.getName() << "|" 
             << e.getModel() << "|" 
             << e.getLocation() << "|" 
             << e.getStatus() << "\n";
    }

    fout << "\n[SCHEDULES]\n";
    fout << "idSchedule|idEquipment|dueDate|status\n";
    for (auto &s : schedules) {
        fout << s.getIdSchedule() << "|" 
             << s.getIdEquipment() << "|" 
             << s.getDueDate() << "|" 
             << s.getStatus() << "\n";
    }

    fout << "\n[RECORDS]\n";
    fout << "idRecord|idEquipment|date|result|notes\n";
    for (auto &r : records) {
        fout << r.getIdRecord() << "|" 
             << r.getIdEquipment() << "|" 
             << r.getDate() << "|" 
             << r.getResult() << "|" 
             << r.getNotes() << "\n";
    }

    cout << "Data saved to " << filename << ". \n";
    fout.close();
}
