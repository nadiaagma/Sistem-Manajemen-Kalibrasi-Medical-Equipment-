///////////////////////////////////////////////////////////
//  MedicalEquipment.h
//  Implementation of the Class MedicalEquipment
//  Created on:      03-Dec-2025 11:43:07 PM
//  Original author: Asus
///////////////////////////////////////////////////////////

#if !defined(EA_29FDEA76_52DE_45aa_9541_4CB15F43BD20__INCLUDED_)
#define EA_29FDEA76_52DE_45aa_9541_4CB15F43BD20__INCLUDED_

#include <string>
#include <iostream>
using namespace std;

class MedicalEquipment
{

public:
	virtual ~MedicalEquipment();

	MedicalEquipment();
	MedicalEquipment(int id, string name, string model, string location, string status);
	void displayInfo();
	int getId();
	string getName();
    string getModel();
    string getLocation();
    string getStatus();
	void setStatus(string newStatus);

private:
	/**
	 * Primary key equipment
	 */
	int id;
	/**
	 * The equipment's location (ICU/ER/etc)
	 */
	string location;
	/**
	 * The version or type of the equipment
	 */
	string model;
	/**
	 * the equipment's name
	 */
	string name;
	/**
	 * The needed for calibration (OK/SCHEDULED/DUE/FAIL)
	 */
	string status;

};
#endif // !defined(EA_29FDEA76_52DE_45aa_9541_4CB15F43BD20__INCLUDED_)
