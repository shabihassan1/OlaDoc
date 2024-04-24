#pragma once
#include<iostream>
using namespace std;

class DateTime
{
private:

	int s;
	int m;
	int h;
	int dd;
	int mm;
	int yy;

public:
	//Default prametrized constructor
	DateTime(int s=0, int m=0, int h=0, int dd=1):s(s),m(m),h(h),dd(dd), mm(8), yy(2022)
	{
		if (s >= 60)
		{
			m+= s/60;
			s = s % 60;
		}

		if (m >= 60)
		{
			h+m / 60;
			m = m % 60;
		}
	}

	void setSeconds(int s)
	{
		this->s = s;

	}


	void setMinutes(int m)
	{
		this->m = m;
	}


	void setHours(int h)
	{
		this->h = h;
	}

	void setDays(int dd)
	{
		this->dd = dd;
	}
	int getSeconds()
	{
		return s;
	}

	int getMinutes()
	{
		return m;
	}

	int getHours()
	{
		return h;
	}

	int getDays()
	{
		return dd;
	}

	int getMonth()
	{
		return mm;
	}

	int getYears()
	{
		return yy;
	}

	double totalSeconds()
	{
		return s + m * 60 + h * 3600;
	}

	double totalMinutes()
	{
		return s/60.0 + m + h * 60;
	}

	int operator()()
	{
		return s / 60.0 + m + h * 60;

	}

	void operator+=(int m)
	{
		this->m += m;

		if (m >= 60)
		{
			h+= m / 60;
			m= m % 60;
		}
	}


	const DateTime& operator=(const DateTime& obj)
	{
		s = obj.s;
		m = obj.m;
		h = obj.h;
		dd = obj.dd;
		mm = obj.mm;
		yy = obj.yy;

		return *this;
	}

	DateTime operator-(const DateTime& x) const
	{
		DateTime temp(s - x.s, m - x.m, h - x.h, dd - x.dd);
		return temp;

	}
	friend ostream& operator<<(ostream& output, const DateTime& obj) 	// outputs the Rational
	{

		output << obj.s << ":" << obj.m << ":" << obj.h;
		return output;
	}

	friend istream& operator>>(istream& input, DateTime& obj) 	// inputs the Rational
	{
		input >> obj.s;
		input >> obj.m;
		input >> obj.h;
		input >> obj.dd;

		return input;

	}

};