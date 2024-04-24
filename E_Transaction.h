#pragma once

#include<iostream>
#include"Payment.h"
using namespace std;

class E_Transaction:public Payment
{
	int phone;
	int PIN;
public:

	E_Transaction(int T_id = 0, double charges = 0, double returns = 0, double deductions = 0, double doc_balance = 0
		, double patient_balance = 0, int phone=0, int PIN=0 ):	Payment(T_id, charges, returns 
			,deductions, doc_balance, patient_balance),phone(phone), PIN(PIN)
	{

	}

	void setPhone(int Phone = 0)
	{
		this->phone = phone;
	}

	void setPIN(int PIN = 0)
	{
		this->PIN = PIN;
	}

	int getPhone()
	{
		return phone;
	}
	int getPIN()
	{
		return PIN;
	}

	virtual void recharge()
	{

	}

	virtual void Bill()
	{

	}
	

	

};