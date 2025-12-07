///////////////////////////////////////////////////////////
//  CalibrationSchedule.h
//  Implementation of the Class CalibrationSchedule
//  Created on:      03-Dec-2025 11:43:02 PM
//  Original author: Asus
///////////////////////////////////////////////////////////

#if !defined(EA_45E683C9_BEEE_404d_A73C_6D8AFAFA082B__INCLUDED_)
#define EA_45E683C9_BEEE_404d_A73C_6D8AFAFA082B__INCLUDED_

#include <string>
#include <iostream>
#include "MedicalEquipment.h"
using namespace std;

class CalibrationSchedule
{

public:
	virtual ~CalibrationSchedule();
	MedicalEquipment *m_MedicalEquipment;

	CalibrationSchedule();
	CalibrationSchedule(int idSchedule, int idEquipment, string dueDate, string status);
	void displayInfo();
	int getIdSchedule();
    int getIdEquipment();
    string getDueDate();
    string getStatus();
	void markDone();

private:
	string dueDate;
	int idEquipment;
	int idSchedule;
	/**
	 * The schedule's status (OPEN/DONE)
	 */
	string status;

};
#endif // !defined(EA_45E683C9_BEEE_404d_A73C_6D8AFAFA082B__INCLUDED_)
