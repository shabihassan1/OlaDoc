#pragma once
#include<iostream>
#include"Payment.h"
#include"DateTime.h"
using namespace std;

//Function to calculate random transaction ID
int Random()
{
	srand(time(0));     //randomizing results... (using time as an input)

	int x;
	const int totalNumbersGenerated = 30;
	const int minRange = 1, maxRange = 200;

	//	cout << "\nPrinting " << totalNumbersGenerated << " random integer numbers (from " << minRange << " to " << maxRange << "):\n";

		//for (int i = 1; i <= totalNumbersGenerated; i++) {
			//generating random number in specified range (inclusive)
			//cout << 1 + ((rand() % maxRange) + minRange - 1) << " ";
	x = ((rand() % maxRange) + minRange - 1);
	//	}

	return x;
}

class Book_Appointement
{
protected:

	bool appointement_Status;
	Payment* payment;
	DateTime* time;
	int *booked;

public:
	//Default prametrized constructor

	Book_Appointement(int T_id=0, double charges = 0, double returns = 0, double deductions = 0, double doc_balance = 0
		, double patient_balance = 0) :time(new DateTime[2]),payment(new Payment(T_id, charges, returns, deductions,
			doc_balance,patient_balance))
	{
		T_id = Random();
	}

	void Slots(int n, int interval)
	{
		time = new DateTime[n];
		booked = new int[n];
	
		for (int i = 0; i < n; i++)
		{
			booked[i] = 0;
		}


		for (int i = 0; i < n; i++)
		{
			time[i].setHours(9);
		}

		int m = 0;

		for(int i=0; i<n; i++)
		{
			time[i]+= m;
			m += interval;
		}

		cout << "Here is a List of Slots Avaialable for this Doctor:" << endl;

		for (int i = 0; i < n; i++)
		{
			cout << i+1 << ". " << time[i] << endl;
		}

		int index;
		cout << endl<<"Which Slot do you Want to Select? ";
		cin >> index;

		booked[index] = 1;
	}

	void Cancel()
	{

	}

};