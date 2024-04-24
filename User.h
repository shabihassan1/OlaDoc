#pragma once
#include<iostream>
#include"Book_Appointement.h"

using namespace std;


class User
{

protected:

	int id;
	char username[100];
	char password[100];
	char CNIC[100];

	Book_Appointement* booking;

	int return_Status;
	//int id;
	/*string username;
	string password;
	string CNIC;
	bool login_status;
	bool register_status;*/



public:

	User(int id = 0, string username = " ", string password = " ", string CNIC = " ") :id(id), return_Status(0)
	{
		
		strcpy_s(this->username, username.c_str());
		strcpy_s(this->password, password.c_str());
		strcpy_s(this->CNIC, CNIC.c_str());
	}

	void setID(int id)
	{
		this->id = id;
	}

	int getID()
	{
		return id;

	}

	void setName(string username)
	{
		strcpy_s(this->username, username.c_str());
	}

	string getName()
	{
		return username;
	}

	void setPassword(string password)
	{
		strcpy_s(this->password, password.c_str());
	}

	void setBook_Appointement(Book_Appointement* booking)
	{
		booking = new Book_Appointement(*booking);
	}

	string getPassword()
	{
		return password;
	}

	void setCNIC(string CNIC)
	{
		while (CNIC.size() > 13)
		{
			cout << endl << "Please Enter a 13-Digit Valid-CNIC number: ";
			cin >> CNIC;
		}
		strcpy_s(this->CNIC, CNIC.c_str());
	}

	string getCNIC()
	{
		return CNIC;
	}

	int get_returnStatus()
	{
		return return_Status;
	}

	virtual void edit_profile()
	{

	}

	void myAppointements()
	{

	}

	virtual int searchDoc()
	{
		return 0;
	}

	void ResetPassword()
	{
		
	}

	void doctor_Availability()
	{

	}

	virtual void Menu()
	{

	}

	virtual bool verify()
	{
		return 0;
	}


	virtual	void login()
	{

	}

	virtual void display()
	{

	}

	virtual void getObject(string username, string password)
	{

	}
	virtual void getAllObjects()
	{

	}

	virtual int Main_Menu()
	{
		return 0;
	}

	virtual void set_Booking(int Availability)
	{

	}


};
