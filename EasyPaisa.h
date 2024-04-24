#pragma once

#include<iostream>
#include"E_Transaction.h"
using namespace std;

class EasyPaisa:public E_Transaction
{
public:

	EasyPaisa(int T_id = 0, double charges = 0, double returns = 0, double deductions = 0, double doc_balance = 0
		, double patient_balance = 0, int phone = 0, int PIN = 0) :E_Transaction(T_id, charges,
			returns, deductions, doc_balance,patient_balance, phone,PIN)
	{

	}



	virtual void Bill()
	{
		cout << endl<< "----------EasyPaisa Transaction-Receipt-------------------" << endl;
		cout << "Transaction ID: " << T_id << endl;
		cout << "Ammout Spent: " << charges + deductions << endl;
		cout << "Returns: " << returns << endl;
		cout << "Balance: " << patient_balance << endl;
		cout << "----------------------Thank You :) --------------------------"<<endl;
	
	}

	virtual void recharge(string fileName, int phone, int PIN)
	{
		double Ammount=0;
		bool flag = false;
		flag = verify(fileName, phone, PIN);

		if (flag)
		{
			cout <<endl<< "Enter the Ammount you Want to Recharge:";
			cin >> Ammount;

			patient_balance += Ammount;
		}
		else
		{
			cout << endl<<"Wrong Credentials!"<<endl;
		}
	}



	virtual bool verify(string fileName, int phone, int PIN)
	{
		EasyPaisa temp;
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if ((temp.getPhone() == phone) && (temp.getPIN() == PIN))
			{
				myFile.close();
				return true;

			}
		}

		myFile.close();
		return false;
	}
	
};