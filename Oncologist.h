#pragma once

#include<iostream>
#include"Doctor.h"
using namespace std;

class Oncologist: public Doctor
{
protected:


public:


	virtual double cal_Charges(int hours)
	{
		return hourlyRate * hours;
	}
};