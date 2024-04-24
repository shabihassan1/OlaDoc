#pragma once
#include<iostream>
#include"../OOP Final Project/User.h"
#include"Book_Appointement.h"
using namespace std;


class Doctor :public User//inheritance from user
{

protected:
	
	char Email[100];
	char City[100];
	char Hospital[100];
	double hourlyRate;
	char specilization[100];
	int Availability;
	double totalRating;
	int exp;


	bool login_status;
	bool register_status;

public:
	//Default prametrized constructor
	Doctor(int id=0, string username=" ", string password=" ", string CNIC=" ", string City=" "
		, string Hospital=" ", string specilization=" ", int exp = 0, double totalRating = 5, int Availability = 12, double hourlyRate=0) :User(id, username, password, CNIC), exp(exp),
		  totalRating(totalRating),  Availability(Availability), hourlyRate(hourlyRate)
	{
		login_status = 0;

		if (username!= " ")
			register_status = 1;
		else
			register_status = 0;

		strcpy_s(this->City, City.c_str());
		strcpy_s(this->Hospital, Hospital.c_str());

	}

	Doctor(const Doctor& copy)
	{
		id = copy.id;
		exp = copy.exp;
		Availability = copy.Availability;
		totalRating = copy.totalRating;
		hourlyRate = copy.hourlyRate;
		login_status = copy.login_status;
		register_status = copy.register_status;

		strcpy_s(username, copy.username);
		strcpy_s(CNIC, copy.CNIC);
		strcpy_s(password, copy.password);
		strcpy_s(Hospital, copy.Hospital);
		strcpy_s(City, copy.City);
		strcpy_s(Email, copy.Email);
		strcpy_s(specilization, copy.specilization);
		
	}

	//Setter
	void setExp(int exp)
	{
		this->exp = exp;
	}
	//Getter
	int getExp()
	{
		return exp;

	}
	//Function to edit doctors profile
	void virtual edit_profile()
	{

		system("Pause");
		system("cls");

		int Choice;
		cout << "---------------------------------Edit-Doctor-Profile-------------------------------------" << endl;
		cout << "\t1.CNIC" << endl;
		cout << "\t2.Availability" << endl;
		cout << "\t3.Hourly Rate " << endl;
		cout << "\t4.Go Back to Main-Menu " << endl;

		cout << "---------------------------------------------------------------------------------" << endl;

		cout << "Please Enter you Choice(1, 2 or 3): ";
		cin >> Choice;

		string CNIC;
		switch (Choice)
		{
		case 1:

			cout << "Enter the CNIC(13-Digit): ";
			cin >> CNIC;

			while (CNIC.size() > 13)
			{

				cout << endl << "INVALID ENTRY! Please Enter a 13-Digit-CNIC number: ";
				cin >> CNIC;
			}

			setCNIC(CNIC);
			Menu();
			break;


		case 2:
			//registration();
			break;
		case 3:
			return_Status = 1;
			break;
		default:
			cout << "Wrong Input! (Enter to Continue) " << endl;
			system("pause");
			system("cls");
			Menu();


		}
	}
	//Setter
	void setHourlyRate(int hourlyRate)
	{
		this->hourlyRate = hourlyRate;
	}
	//Getter
	double getHourlyRate()
	{
		return hourlyRate;

	}
	//Setter
	void setTotalRating(double totalRating)
	{
		this->totalRating = (this->totalRating + totalRating) / 2;
	}
	//Getter
	double getTotalRating()
	{
		return totalRating;
	}

	//Setter
	void setCity(string City)
	{
		strcpy_s(this->City, City.c_str());
	}
	//Getter
	string getCity()
	{
		return City;
	}

	//Setter
	void setEmail(string Email)
	{
		strcpy_s(this->Email, Email.c_str());
	}
	//Getter
	string getEmail()
	{
		return Email;
	}

	//Setter
	void setHospital(string Hospital)
	{
		strcpy_s(this->Hospital, Hospital.c_str());
	}
	//Getter
	string getHospital()
	{
		return Hospital;
	}

	//Function to write doctors detail to binary file
	void Write(Doctor obj, string fileName)
	{
		ofstream myFile(fileName, ios::binary | ios::app);
		myFile.write((char*)&obj, sizeof(obj));
		myFile.close();
	}

	virtual void getObject(string username, string password)
	{
		string fileName = "Doctor.bin";
		Doctor temp;
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) 
		{
			if ((temp.username == username) && (temp.password == password))
			{
				//temp.getData();
				myFile.close();
				*this = temp;
			}
		}
	}

	virtual void getAllObjects() {

		string fileName = "Doctor.bin";
		Doctor temp;
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			temp.display();
			cout << "..." << endl << endl;
		}
		myFile.close();
	}

	virtual double cal_Charges(int hours)
	{
		return hourlyRate * hours;
	}
	virtual void Menu()
	{
		int Choice;
		cout << "---------------------------------Doctor-Menu-------------------------------------" << endl;
		cout << "\t1.Login" << endl;
		cout << "\t2.Registration" << endl;
		cout << "\t3.Return to Main Menu " << endl;
		cout << "---------------------------------------------------------------------------------" << endl;

		cout << "Please Enter you Choice(1, 2 or 3): ";
		cin >> Choice;

		switch (Choice)
		{
		case 1:
			login();
			break;
		case 2:
			registration();
			break;
		case 3:
			return_Status = 1;
			break;
		default:
			cout << "Wrong Input! (Enter to Continue) " << endl;
			system("pause");
			system("cls");
			Menu();


		}
	}

	virtual void login()
	{
		string username;
		string password;
		string fileName = "Doctor.bin";

		cout << endl << endl;

		cout << "Enter the username: ";
		cin >> username;

		cout << "Enter the Password: ";
		cin >> password;

		bool flag = false;

		flag = verify(fileName, username, password);

		if (flag)
		{
			cout << endl<< "Welcome Back to OlaDoc: " << endl;
			getObject(username, password);
			display();
			
			system("Pause");
			system("cls");
			Main_Menu();
			login_status = 1;
		}

		else
		{
			cout << endl<<"Wrong Credenials!" << endl;
			login_status = 0;

			string check;

			cout << "Do you Want to Continue(Y):";
			cin >> check;

			if (check == "Y" or check == "y")
				login();
			else
			{
				cin.clear();
				cin.ignore(10000, '\n');
				system("cls");
				Menu();
			}

		}
	}
	

	void Validate(string str, char ch)
	{
		while (str.find(ch) == -1)
		{
			cout << endl << " Please Enter a Vailid Addribute! " << endl;
			cin >> str;
		}

	}

	virtual int Main_Menu()
	{
		cout << "------------------------------------Welcome Back Doctor---------------------------------------" << endl;
		cout << "1.Edit Profile" << endl;
		cout << "2.View Appointements"<<endl;
		cout << "3.Patient Data" << endl;

		int Choice;
		cout << "Please Enter you Choice(1, 2 or 3): ";
		cin >> Choice;

		switch (Choice)
		{
		case 1:
			edit_profile();
			break;
		case 2:
			//view_appointements();
			break;
		case 3:
		{
			cout << "ID is: 774"<<"Name is : Mansoor" << endl << "CNIC is : 35202" << endl;
			break;
			
		}
		case 4:
			return_Status = 1;
			break;
		default:
			cout << "Wrong Input! (Enter to Continue) " << endl;
			system("pause");
			system("cls");
			Menu();


		}

		return 0;
	}
	virtual void registration()
	{
		int id;
		double totalRating;
		double hourlyRate;
		int Availability;
		string username;
		string password;
		string password1;
		string CNIC;
		string Email;
		string Specilization;
		string Hospital;
		string City;
		int exp;

		string fileName = "Doctor.bin";

		cout << endl << endl << "-----------------------------Starting Registration--------------------------" << endl << endl;


		cout << "Enter an ID(Integer Value): ";
		cin >> id; //Prevent Id from Causing trouble 

		while ( id<0 || id>1000000 ) 
		{
			cout << endl << "Please Enter an Integer Value! ";
			cin >> id;

		}

		cin.clear();
		cin.ignore(10000, '\n');

		cout << "Enter the username: ";
		cin >> username;

		cout << "Enter the Password: ";
		cin >> password;

		cout << "Enter the Password Again: ";
		cin>>password1;

		while (password != password1)
		{
			cout << "Passwords Should Match, Please Try Again: ";
			cin>>password1;
		}

		int ch;
		cout << endl<<endl<<"Do you Want to Register by:"<<endl<< "1.CNIC "<<endl<< "2.Email" << endl<<endl;
		cout << "Please Choose : ";
		cin >> ch;

		if (ch == 1)
		{
			cout << "Enter the CNIC(13-Digit): ";
			cin >> CNIC;

			while (CNIC.size() > 13)
			{

				cout <<endl<<"INVALID ENTRY! Please Enter a 13-Digit-CNIC number: ";
				cin >> CNIC;
			}

		}
		else
		{
			cout << "Enter your Email: " << endl;
			cin >> Email;


			while (Email.find('@') == -1)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << endl << "Please Enter a Vailid Email Address " << endl;
				cin >> Email;
			}
			
		}

		cout << "Enter your Hourly Rate: ";
		cin >> hourlyRate;

		cout << "Enter your Availability: ";
		cin >> Availability;
		
		cout << "Enter Your Specilization:  ";
		cin >> Specilization;

		cout << "Enter the Hospital you work at: ";
		cin >> Hospital;

		cout<< "Enter your City of Residence: ";
		cin >> City;

		cout << endl<< "Enter your Experience In Years: ";
		cin >> exp;
		
		cout << "Enter your Total Rating: ";
		cin >> totalRating;


		cout << endl<< "--------------------------------Registration Complete--------------------------------------" << endl;

		register_status = 1;

		if (ch == 1)
		{
			Doctor temp(id, username, password, CNIC, City, Hospital,Specilization, exp, totalRating, Availability, hourlyRate);
			Write(temp, fileName);

		}
		else
		{
			Doctor temp(id, username, password, " ", City, Hospital, Specilization, exp, totalRating, Availability, hourlyRate);
			setEmail(Email);
			Write(temp, fileName);
		}

		cin.clear();
		cin.ignore(10000, '\n');  //float

		system("Pause");
		system("cls");

		Menu();


	}

	virtual void display()
	{
		cout << "---------"<<endl << id<<endl<<username << endl<< password << endl<<CNIC<<endl
			<< Hospital<<endl<< City<<endl<<exp<<endl<<totalRating<<endl<<"-------------"<<endl;
	}

	//Category wise searching, location wise searching, doctor / clinic wise searching

	virtual int searchDoc()
	{
		int choice;

		cout << "--------------------------Search Doctor Menu---------------------------" << endl;
		cout << "1.Search by City" << endl;
		cout << "2.Search by Category" << endl;
		cout << "3. Search by Hospital " << endl;
		cout << "-----------------------------------------------------------------------" << endl;


		cout << "Please Choose";
		cin >> choice;

		if (choice == 1)
		{
			string fileName = "Doctor.bin";
			Doctor temp;
			ifstream myFile(fileName, ios::binary);
			while (myFile.read((char*)&temp, sizeof(temp)))
			{
				if (temp.City == City)
				{
					myFile.close();
					return temp.id;

				}
			}

			myFile.close();
		}
		else if (choice == 2)
		{
			string fileName = "Doctor.bin";
			Doctor temp;
			ifstream myFile(fileName, ios::binary);
			while (myFile.read((char*)&temp, sizeof(temp)))
			{
				if (temp.City == City)
				{
					myFile.close();
					return temp.id;

				}
			}

			myFile.close();
			//	return false;
		}
		else if(choice==3)
		{

			string fileName = "Doctor.bin";
			Doctor temp;
			ifstream myFile(fileName, ios::binary);
			while (myFile.read((char*)&temp, sizeof(temp)))
			{
				if (temp.City == City)
				{
					myFile.close();
					return temp.id;

				}
			}

			myFile.close();
			//	return false;
				
		}
	}


	virtual bool verify(string fileName, string username, string password)
	{
		Doctor temp;
		ifstream myFile(fileName, ios::binary );
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if ((temp.username == username) && (temp.password == password))
			{
				myFile.close();
				return true;

			}
		}

		myFile.close();
		return false;
	}



};


