///////////////////////////////////////////////////////////
//  MedicalEquipment.cpp
//  Implementation of the Class MedicalEquipment
//  Created on:      03-Dec-2025 11:43:07 PM
//  Original author: Asus
///////////////////////////////////////////////////////////

#include "MedicalEquipment.h"

MedicalEquipment::~MedicalEquipment() {}

MedicalEquipment::MedicalEquipment() {}

//MedicalEquipment::MedicalEquipment(int id, string name, string model, string location, string status) {}
MedicalEquipment::MedicalEquipment(int id, string nm, string mdl, string loc, string stat) {
    this->id = id;   
    this->name = nm;          
    this->model = mdl;        
    this->location = loc;     
    this->status = stat;    
}

void MedicalEquipment::displayInfo() {
    cout << "ID: " << id
         << " | Name: " << name
         << " | Model: " << model
         << " | Location: " << location
         << " | Status: " << status
         << endl;
}

int MedicalEquipment::getId() {
    return id;
}
string MedicalEquipment::getName() { 
    return name; 
}
string MedicalEquipment::getModel() { 
    return model; 
}
string MedicalEquipment::getLocation() { 
    return location; 
}
string MedicalEquipment::getStatus() { 
    return status; 
}
void MedicalEquipment::setStatus(string newStatus) {
    status = newStatus;
}
