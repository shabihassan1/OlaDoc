#pragma once


#include<iostream>
#include"BankTransfer.h"
using namespace std;


class UnionPay : public BankTransfer
{
public:

	UnionPay(int T_id = 0, double charges = 0, double returns = 0, double deductions = 0, double doc_balance = 0
		, double patient_balance = 0, int accNum = 0, int PIN = 0) : BankTransfer(T_id, charges, returns
			, deductions, doc_balance, patient_balance, accNum, PIN)
	{

	}
	virtual void Bill()
	{
		cout << endl << "----------UnionPay Transaction-Receipt-------------------" << endl;
		cout << "Transaction ID: " << T_id << endl;
		cout << "Ammout Spent: " << charges + deductions << endl;
		cout << "Returns: " << returns << endl;
		cout << "Balance: " << patient_balance << endl;
		cout << "----------------------Thank You :) --------------------------" << endl;
	}
	
	virtual void recharge(string fileName, int accNum, int PIN)
	{
		double Ammount = 0;
		bool flag = false;
		flag = verify(fileName, accNum, PIN);

		if (flag)
		{
			cout << endl << "Enter the Ammount you Want to Recharge:";
			cin >> Ammount;

			patient_balance += Ammount;
		}
		else
		{
			cout << endl << "Wrong Credentials!" << endl;
		}
	}



	virtual bool verify(string fileName, int accNum, int PIN)
	{
		UnionPay temp;
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if ((temp.get_accountNumber() == accNum) && (temp.getPIN() == PIN))
			{
				myFile.close();
				return true;

			}
		}

		myFile.close();
		return false;
	}

	
};