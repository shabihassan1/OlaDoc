#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include"User.h";
#include"Admin.h"
#include"Doctor.h"
#include"Patient.h"
#include"Payment.h"
#include"EasyPaisa.h"
using namespace std;

//
//void Write(Doctor obj, string fileName)
//{
//	ofstream myFile(fileName, ios::binary | ios::app);
//	myFile.write((char*)&obj, sizeof(obj));
//	myFile.close();
//}

//
//void Write(Patient obj, string fileName)
//{
//	ofstream myFile(fileName, ios::binary | ios::app);
//	myFile.write((char*)&obj, sizeof(obj));
//	myFile.close();
//}

void Write(Admin *obj, string fileName)
{
	ofstream myFile(fileName, ios::binary | ios::app);
	myFile.write((char*)&*obj, sizeof(*obj));
	myFile.close();
}

//void Reset(string fileName)
//{
//	ofstream myFile(fileName, ios::binary | ios::out);
//	myFile.close();
//}



class Oladoc
{
private:

	User *user;//composition of user class
	

public:
	//Default constructor
	Oladoc():user()
	{

	}

	User* getUser()
	{
		return user;
	}
	//Function to create payment method
	void fun()
	{
		Payment *p1;
		p1 = new EasyPaisa(232,40, 30, 20, 5000, 2400, 334,344);
		p1->recharge();
		
	}
	//Main menu of the oladoc system
	void Menu()
	{
		int Choice;

		cout << "-------------------------------Welcome to OLADOC------------------------------" << endl;
		cout << " Please Choose Any of the Following " << endl;
		cout << "\t 1.Admin" << endl;
		cout << "\t 2.Doctor" << endl;
		cout << "\t 3.Patient" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		

		cout << endl << endl << "Please Select: ";
		cin >> Choice;

		system("cls");

		cout << endl;

		switch (Choice)
		{
			//case to display admin menu to the user
			case 1:
				user = new Admin(1, "mansoor","mansoor");
				Write(new Admin(1, "mansoor", "mansoor"), "Admin.bin");
				user->Menu();
				if (user->Main_Menu() == 1)
				{
					user = new Doctor;
					user->Menu();
				}
				else
				{
					user = new Patient;
					user->getAllObjects();

					system("Pause");
					system("cls");
					user->Menu();
					
				}
				if (user->get_returnStatus() == 1)
					{
						system("cls");
						Menu();
					}
				break;
				//case to display doctor menu 
			case 2:
				user = new Doctor;
				user->Menu();
				if (user->get_returnStatus() == 1)
				{
					system("cls");
					Menu();
				}
				break;
				//case to display patient
			case 3:
				user = new Patient;
				user->Menu();
				if (user->get_returnStatus() == 1)
				{
					system("cls");
					Menu();
				}
				break;
		}

	}

};
