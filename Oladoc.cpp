#pragma once
#include<iostream>
#include"Oladoc.h"
#include"Doctor.h"
using namespace std;

void Read(string fileName)
{
	Doctor obj;
	ifstream myFile(fileName, ios::binary | ios::in);
	myFile.read((char*)&obj, sizeof(obj));
	obj.display();
	myFile.close();

}

void Reset(string fileName)
{
	ofstream myFile(fileName, ios::binary | ios::out);
	myFile.close();
}

int main()
{
  //  Reset("Doctor.bin");
	Oladoc system;
	system.Menu();
	return 0;
}