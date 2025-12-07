///////////////////////////////////////////////////////////
//  CalibrationRecord.cpp
//  Implementation of the Class CalibrationRecord
//  Created on:      03-Dec-2025 11:43:05 PM
//  Original author: Asus
///////////////////////////////////////////////////////////

#include "CalibrationRecord.h"

CalibrationRecord::~CalibrationRecord() {}

CalibrationRecord::CalibrationRecord() {}

//CalibrationRecord::CalibrationRecord(int idRecord, int idEquipment, string date, string result, string notes) {}
CalibrationRecord::CalibrationRecord(int idRec, int idEq, string dt, string res, string nts) {
    this->idRecord = idRec;
    this->idEquipment = idEq;
    this->date = dt;
    this->result = res;
    this->notes = nts;
}

void CalibrationRecord::displayInfo() {
    cout << "RecordID: " << idRecord
         << " | EquipmentID: " << idEquipment
         << " | Date: " << date
         << " | Result: " << result
         << " | Notes: " << notes
         << endl;
}

int CalibrationRecord::getIdEquipment() {
    return idEquipment;
}
int CalibrationRecord::getIdRecord() { 
    return idRecord; 
}
string CalibrationRecord::getDate() { 
    return date; 
}
string CalibrationRecord::getResult() { 
    return result; 
}
string CalibrationRecord::getNotes() { 
    return notes; 
}
