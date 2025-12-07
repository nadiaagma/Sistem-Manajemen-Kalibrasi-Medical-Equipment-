///////////////////////////////////////////////////////////
//  CalibrationRecord.h
//  Implementation of the Class CalibrationRecord
//  Created on:      03-Dec-2025 11:43:05 PM
//  Original author: Asus
///////////////////////////////////////////////////////////

#if !defined(EA_5006F4E2_0B24_4d3b_8547_6A29370D2004__INCLUDED_)
#define EA_5006F4E2_0B24_4d3b_8547_6A29370D2004__INCLUDED_

#include <string>
#include <iostream>
#include "MedicalEquipment.h"
using namespace std;

class CalibrationRecord
{

public:
	virtual ~CalibrationRecord();
	MedicalEquipment *m_MedicalEquipment;

	CalibrationRecord();
	CalibrationRecord(int idRecord, int idEquipment, string date, string result, string notes);
	void displayInfo();
	int getIdEquipment();
	int getIdRecord();
    string getDate();
    string getResult();
    string getNotes();

private:
	string date;
	int idEquipment;
	int idRecord;
	string notes;
	string result;

};
#endif // !defined(EA_5006F4E2_0B24_4d3b_8547_6A29370D2004__INCLUDED_)
