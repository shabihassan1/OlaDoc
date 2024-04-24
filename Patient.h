#pragma once

#include<iostream>
#include"../OOP Final Project/User.h"
#include"Doctor.h"
#include"Book_Appointement.h"
using namespace std;


class Patient : public User//inherits from user class
{

protected:
	
	Doctor* d;
	int doc_ID;
	bool login_status;
	bool register_status;

public: 
	//Default prametrized constructor
	Patient(int id = 0, string username = " ", string password = " ", string CNIC = " ", int doc_ID=0) :User(id, username, password, CNIC), doc_ID(doc_ID)
	{
		login_status = 0;

		if (username != " ")
			register_status = 1;
		else
			register_status = 0;

	}

	Patient(const Patient& copy)
	{
		id = copy.id;
		login_status = copy.login_status;
		register_status = copy.register_status;

		strcpy_s(username, copy.username);
		strcpy_s(CNIC, copy.CNIC);
		strcpy_s(password, copy.password);
	}

	//Function to write patients details
	void Write(Patient obj, string fileName)
	{
		ofstream myFile(fileName, ios::binary | ios::app);
		myFile.write((char*)&obj, sizeof(obj));
		myFile.close();
	}
	//Function to displat patient main menu
	virtual void Menu()
	{
		int Choice;
		cout << "---------------------------------Patient-Menu-------------------------------------" << endl;
		cout << "\t1.Login" << endl;
		cout << "\t2.Registration" << endl;
		cout << "\t3.Return to Main Menu " << endl;

		cout << "----------------------------------------------------------------------" << endl;

		cout << "Please Enter you Choice(1, 2 or 3): ";
		cin >> Choice;

		switch (Choice)
		{
			case 1:
				login();
				break;
			case 2:
				registration();
				break;
			case 3:
				return_Status = 1;
				break;
			default:
				cout << "Wrong Input! (Enter to Continue) " << endl;
				system("pause");
				system("cls");
				Menu();


		}

	}


	//Function to register patient account
	virtual void registration()
	{
		int id;
		string username;
		string password;
		string password1;
		string CNIC;
		
		string fileName = "Patient.bin";

		cout << endl << endl << "-----------------------------Starting Registration--------------------------" << endl << endl;

		cout << "Enter an ID(Integer Value): ";
		cin >> id; //Prevent Id from Causing trouble 

		while (id < 0 || id>1000000)
		{
			cout << endl << "Please Enter an Integer Value! ";
			cin >> id;

		}

		cin.clear();
		cin.ignore(10000, '\n');

		cout << "Enter the username: ";
		cin >> username;

		cout << "Enter the Password: ";
		cin >> password;

		cout << "Enter the Password Again: ";
		cin >> password1;

		while (password != password1)
		{
			cout << "Passwords Should Match, Please Try Again: ";
			cin >> password1;
		}

		cout << "Enter the CNIC(13-Digit): ";
		cin >> CNIC;

		while (CNIC.size() > 13)
		{
			cout << endl << "INVALID ENTRY! Please Enter a 13-Digit-CNIC number: ";
			cin >> CNIC;
		}

		cout << "--------------------------------Registration Complete--------------------------------------" << endl;
		register_status = 1;

		Patient temp(id, username, password, CNIC);

		Write(temp, fileName);

		cin.clear();
		cin.ignore(10000, '\n');
		system("Pause");
		system("cls");

		Menu();


	}


	virtual void display()
	{
		cout << "---------" << endl << "ID: "<<id << endl << "USERNAME: "<<username << endl << "CNIC: "<< CNIC << endl << "-------------" << endl;
	}

	virtual void getObject(string username, string password)
	{
		string fileName = "Patient.bin";
		Patient temp;
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if ((temp.username == username) && (temp.password == password))
			{
				//temp.getData();
				myFile.close();
				*this = temp;
			}
		}
	}

	virtual void getAllObjects() {

		string fileName = "Patient.bin";
		Patient temp;
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			temp.display();
		}
		myFile.close();
	}

	virtual void login()
	{
		string username;
		string password;
		string fileName="Patient.bin";

		cout << "Enter the username: ";
		cin >> username;

		cout<< "Enter the Password: ";
		cin >> password;

		bool flag = false;

		flag=verify(fileName, username, password);

		if (flag)
		{
			cout << endl<<"Welcome Back to OlaDoc: "<<endl;
			getObject(username, password);
			display();
			/*d = new Doctor;
			d->getAllObjects();*/

			system("Pause");
			system("cls");
			Menu();
			login_status = 1;
		}

		else
		{
			cout << endl<< "Wrong Credenials!" << endl;
			login_status = 0;

			string check;

			cout << "Do you Want to Continue(Y):";
			cin >> check;

			if (check == "Y" or check == "y")
				login();
			else
			{
				system("cls");
				Menu();
			}

		}

	}

	virtual void set_Booking(int Availaility)
	{
		//Patient and doctor can be linked through id's in one Array
		booking->Slots(Availaility, 45);
	}

	virtual bool verify(string fileName, string username, string password)
	{
		Patient temp;
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if ((temp.username == username) && (temp.password == password))
			{
				//temp.getData();
				return true;
				myFile.close();

			}
		}

		myFile.close();
		return false;
	}

};