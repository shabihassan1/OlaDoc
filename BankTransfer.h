#pragma once

#include<iostream>
#include"Payment.h"
using namespace std;

class BankTransfer: public Payment
{
protected:

	int accNum;
	int PIN;
public:

	BankTransfer(int T_id = 0, double charges = 0, double returns = 0, double deductions = 0, double doc_balance = 0
		, double patient_balance = 0, int accNum = 0, int PIN = 0) : Payment(T_id, charges, returns
		, deductions, doc_balance, patient_balance),accNum(accNum), PIN(PIN)
	{

	}

	void accNum(int accNum)
	{
		this->accNum = accNum;
	}

	void setPIN(int PIN)
	{
		this->PIN = PIN;
	}

	int get_accountNumber()
	{
		return accNum;
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