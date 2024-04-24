#pragma once


#include<iostream>
#include"../OOP Final Project/User.h"
#include"Book_Appointement.h"
using namespace std;


class Admin :public User //inheritance of user class
{

protected:

	bool login_status;
	bool register_status;
	/*Doctor* doctor;
	Patient* patient;
	Book_Appointement* booking;*/

public:
	//prametrized default constructor
	Admin(int id = 0, string username = " ", string password = " ") :User(id, username, password)
	{
		login_status = 0;

		if (username == " ")
			register_status = 1;
		else
			register_status = 0;

		strcpy_s(this->username, username.c_str());
		strcpy_s(this->password, password.c_str());
	}

	//Admin(Doctor* doctor, Patient* patient, Book_Appointement* booking):doctor(doctor), patient(patient)
	//	, booking(booking)
	//{


	//Function to verify admin
	virtual void getObject(string username, string password)
	{
		string fileName = "Admin.bin";
		Admin temp;
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
	//Polymorphically accessing admin menu
	virtual int Main_Menu()
	{
		int Choice;
		cout << "-----------------------------------Welcome Admin-----------------------------------" << endl;
		cout << "What would you like to do?" << endl;
		cout << "\t1.Manage a Doctor" << endl;
		cout << "\t2.View Patient Data " << endl;
		cout << "\t3.Return to Main Menu " << endl;

		cout << "--------------------------------------------------------------------------------" << endl;

		cout << "Please Enter you Choice(1, 2 or 3): ";
		cin >> Choice;

		switch (Choice)
		{
		case 1:
			return 1;
			break;
		case 2:
			return 2;
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
	//Function to return admin to main menu
	virtual void Menu()
	{
		int Choice;
		cout << "-----------------------------------Admin-Menu-----------------------------------" << endl;
		cout << "\t1.Login" << endl;
		cout << "\t2.Return to Main Menu " << endl;

		cout << "--------------------------------------------------------------------------------" << endl;

		cout << "Please Enter you Choice(1 or 2): ";
		cin >> Choice;

		switch (Choice)
		{
			case 1:
				login();
				//Main_Menu();
				break;
			case 2:
				return_Status = 1;
				break;
			default:
				cout << "Wrong Input! (Enter to Continue) " << endl;
				system("pause");
				system("cls");
				Menu();

		}
	}


	//Function to polymorphically access admin login function
	virtual void login()
	{
		string username;
		string password;
		string fileName = "Admin.bin";

		cout << "Enter the username: ";
		cin >> username;

		cout << "Enter the Password: ";
		cin >> password;

		bool flag = false;

		flag = verify(fileName, username, password);

		if (flag)
		{
			cout << endl<<"Welcome Back to OlaDoc: " << endl;
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
	//Function to verify admin login details
	virtual bool verify(string fileName, string username, string password)
	{
		Admin temp;
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if ((temp.username == username) && (temp.password == password))
			{
				myFile.close();
				return true;

			}
		}

		myFile.close();
		return false;

	}


};
