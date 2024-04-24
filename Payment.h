#pragma once
#include<iostream>
#include<fstream>
#include <cstdlib>  //required for rand(), srand()
#include <ctime> 
using namespace std;


class Payment
{
protected:
	
	int T_id;
	double doc_balance;
	double patient_balance;
	double charges;
	double returns;
	double deductions;

public:

	Payment(int T_id=0,double charges = 0, double returns = 0, double deductions=0, double doc_balance=0
	     , double patient_balance=0): T_id(T_id),charges(charges), returns(returns),
			deductions(deductions), doc_balance(doc_balance), patient_balance(patient_balance)

	{

	}

	int Random()
	{
		srand(time(0));     //randomizing results... (using time as an input)

		int x;
		const int totalNumbersGenerated = 30;
		const int minRange = 1, maxRange = 20000;

	//	cout << "\nPrinting " << totalNumbersGenerated << " random integer numbers (from " << minRange << " to " << maxRange << "):\n";

		//for (int i = 1; i <= totalNumbersGenerated; i++) {
			//generating random number in specified range (inclusive)
			//cout << 1 + ((rand() % maxRange) + minRange - 1) << " ";
			x = ((rand() % maxRange) + minRange - 1);
	//	}

			return x;
	}
	void setCharges(double charges)
	{
		this->charges = charges;
	}

	double getCharges()
	{
		return charges;
	}

	void setReturns(double returns)
	{
		this->returns = returns;
	}

	double getReturns()
	{
		return returns;
	}


	void setDoc_Balance(double doc_balance)
	{
		this->doc_balance = doc_balance;
	}

	double getDoc_Balance()
	{
		return doc_balance;
	}


	void setPatient_Balance(double patient_balance)
	{
		this->patient_balance = patient_balance;
	}

	double getPatient_Balance()
	{
		return patient_balance;
	}

	void cal_Charges(int mode)
	{
		if (mode == 1) //Person to Person Consultation
			charges = charges;
		else if (mode == 2)
			charges = (70 * charges) / 100.0;
	}

	double Deduction(int day)
	{
		if (day == 1)
			return (charges * 30) / 100;

		if (day == 2)
			return (charges * 60) / 100;

		if (day >= 3)
			return (charges * 100) / 100;
	}

	 double cal_Returns(int day)           //Check Later
	{
		if (day == 1)
			returns = returns;
		else if (day == 2)
			returns = (60 * returns) / 100.0;
		else if (day == 3)
			returns = (30 * returns) / 100.0;
		else 
			returns = 0;

		return returns;
	}

	void transcation()
	{
		doc_balance += charges;
		doc_balance -= returns;
		doc_balance += deductions;

		patient_balance -= charges;
		patient_balance += returns;
		patient_balance -= deductions;
	}

	virtual void recharge()
	{

	}
	virtual void Bill()
	{

	}
};