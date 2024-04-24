#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"DateTime.h"
#include"Patient.h"
#include"Doctor.h"

class Feedback
{
private:

	string review;
	double rating;
	Doctor* doctor;
	Patient* patient;
	DateTime* time;

public:

	Feedback()
	{
		rating = 0;
		review = " ";
	}

	Feedback(double rating)
	{
		this->rating = rating;
	}

	Feedback(Doctor* doctor, Patient* patient, DateTime* Time):doctor(doctor),patient(patient)
		,time(time)
	{

	}


	void Write(Feedback obj, string fileName)
	{
		ofstream myFile(fileName, ios::binary | ios::app);
		myFile.write((char*)&obj, sizeof(obj));
		myFile.close();
	}

	void Menu()
	{
		cout << "---------------------------------Welcome to FeedBack Menu-----------------------------------" << endl;

		string fileName = "Feedback.bin";


		cout << "Please Give a Rating out of 5:";
		cin >> rating;

		doctor->setTotalRating(rating);

		cout << "Please Give your Honest Oponion about this Doctor:";
		getline(cin, review);

		Write(*this, fileName);

		cout << "-------------------------------------Thank you for your Response! ------------------------------";





	}

	virtual bool verify(string fileName, string username, string password)
	{
		Doctor temp;
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if ((temp.getName() == username) && (temp.getPassword() == password))
			{
				myFile.close();
				return true;

			}
		}

		myFile.close();
		return false;
	}



};