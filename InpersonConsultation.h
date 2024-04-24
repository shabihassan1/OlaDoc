#pragma once
#include<iostream>
#include"Book_Appointement.h"
using namespace std;


class Inperson:public Book_Appointement
{
protected:
	double Charges;
public:
	Inperson(double Charges = 0, int T_id = 0, double charges = 0, double returns = 0, double deductions = 0, double doc_balance = 0
		, double patient_balance = 0) :Charges(Charges), Book_Appointement(T_id, charges, returns, deductions,
			doc_balance, patient_balance)
	{

	}
};