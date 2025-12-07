///////////////////////////////////////////////////////////
//  BMETSystem.h
//  Implementation of the Class BMETSystem
//  Created on:      03-Dec-2025 11:43:06 PM
//  Original author: Asus
///////////////////////////////////////////////////////////

#if !defined(EA_DD190322_18B9_49b8_9C7A_988754E65FAF__INCLUDED_)
#define EA_DD190322_18B9_49b8_9C7A_988754E65FAF__INCLUDED_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "MedicalEquipment.h"
#include "CalibrationRecord.h"
#include "CalibrationSchedule.h"
using namespace std;

class BMETSystem
{

public:
	virtual ~BMETSystem();
	MedicalEquipment *m_MedicalEquipment;
	CalibrationRecord *m_CalibrationRecord;
	CalibrationSchedule *m_CalibrationSchedule;

	BMETSystem();
	void addCalibrationRecord(CalibrationRecord record);
	void addEquipment(MedicalEquipment equipment);
	void createSchedule(int idEquipment, string dueDate);
	void deleteEquipment(int id);
	void editEquipment(int id, MedicalEquipment newData);
	int findEquipmentById(int id);
	void listEquipments();
	void loadFromFile(string filename);
	void saveToFile(string filename);
	void showHistory(int idEquipment);

private:
	vector<MedicalEquipment> equipments;
	vector<CalibrationRecord> records;
	vector<CalibrationSchedule> schedules;

};
#endif // !defined(EA_DD190322_18B9_49b8_9C7A_988754E65FAF__INCLUDED_)
