///////////////////////////////////////////////////////////
//  CalibrationSchedule.cpp
//  Implementation of the Class CalibrationSchedule
//  Created on:      03-Dec-2025 11:43:03 PM
//  Original author: Asus
///////////////////////////////////////////////////////////

#include "CalibrationSchedule.h"

CalibrationSchedule::~CalibrationSchedule() {}

CalibrationSchedule::CalibrationSchedule() {}

//CalibrationSchedule::CalibrationSchedule(int idSchedule, int idEquipment, string dueDate, string status) {}
CalibrationSchedule::CalibrationSchedule(int idSch, int idEq, string dt, string stat) { 
    this->idSchedule = idSch;
    this->idEquipment = idEq;
    this->dueDate = dt;
    this->status = stat;
}
void CalibrationSchedule::displayInfo() {
    cout << "ScheduleID: " << idSchedule
         << " | EquipmentID: " << idEquipment
         << " | DueDate: " << dueDate
         << " | Status: " << status
         << endl;
}

int CalibrationSchedule::getIdEquipment() {
    return idEquipment;
}
int CalibrationSchedule::getIdSchedule() { 
    return idSchedule; 
}
string CalibrationSchedule::getDueDate() { 
    return dueDate; 
}
string CalibrationSchedule::getStatus() { 
    return status; 
}
void CalibrationSchedule::markDone() {
    status = "DONE";
}

