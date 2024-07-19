/*
House Loan Calculator
Programmer:
- Nabira Hazeerah binti Ahmad Zairee (2022679428)
- Arnie Sabila binti Ahmad Najib (2022853258)
*/

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

void displayPropertyType();
void displayPropertyA(string&);
void displayTypeACorner(string&, double&);
void displayTypeAIntermediate(string&, double&);
void displayPropertyB(string&);
void displayTypeBEnd(string&, double&);
void displayTypeBIntermediate(string&, double&);
void loadingBar();
void inputPersonalInfo(string&, string&, string&);
void inputLoanInfo(double&, double&, double&, double&);
void displaypersonalInfo (string&, string&, string&, string, string);
double calcLoanAmount(double&, double, double);
double calcTotalInterest (double&, double, double&, double);
double calcTotalPayment (double, double&, double&);
double calcMonthlyPayment (double, double&, double);
void displayCalculation (double&, double&, double&);

int main ()
{
	double purchasePrice, loanAmount, totalInterest, totalPayment, monthlyPayment, downPayment, interestRate, loanPeriod;
	char choice='N';
	string propertyChoice, lotChoice, name, phoneNumber, email;
	string propertyType[2]={"  TYPE A - RUSA TERRACE HOME", "  TYPE B - BAYU APARTMENT"};
	
	do
	{
		//1st page
		displayPropertyType();
		
		cout << endl << endl;
		do
		{
			cout << "\n\n Please enter your preferred property type!";
			cout << "\n Which property type would you like to view? (A / B): ";
			cin >> propertyChoice;
		}
		while (propertyChoice != "A" && propertyChoice != "a" && propertyChoice != "B" && propertyChoice != "b" );
		
		
		if (propertyChoice == "A" || propertyChoice == "a")
		{
			displayPropertyA(propertyChoice);
			
			do
			{
				cout << "\n\n Please enter your preferred lot type!";
				cout << "\n Which lot are you interested in? (C / I): ";
				cin >> lotChoice;
			}
			while (lotChoice != "C" && lotChoice != "c" && lotChoice != "I" && lotChoice != "i");
					
			if (lotChoice == "C" || lotChoice == "c")
			{
				displayTypeACorner(lotChoice, purchasePrice);
			}
		
			else if (lotChoice == "I" || lotChoice == "i")
			{
				displayTypeAIntermediate(lotChoice, purchasePrice);
			}		
		}
			
		else if (propertyChoice == "B" || propertyChoice == "b")
		{
			displayPropertyB(propertyChoice);
			
			do
			{
				cout << "\n\n Please enter your preferred lot type!";
				cout << "\n\n Which lot are you interested in? (E / I): ";
				cin >> lotChoice;
			}
			while (lotChoice != "E" && lotChoice != "e" && lotChoice != "I" && lotChoice != "i");
			
				
			if (lotChoice == "E" || lotChoice == "e")
			{
				displayTypeBEnd(lotChoice, purchasePrice);
			}
			
			else if (lotChoice == "I" || lotChoice == "i")
			{
				displayTypeBIntermediate(lotChoice, purchasePrice);
			}
		}

		cout << "\n\n Proceed to count loan? (Y/ N): ";
		cin >> choice;
		
		choice = toupper(choice);
		
		system ("cls");
	}	


	//2nd page
	while (choice!='Y');
	inputPersonalInfo(name, phoneNumber, email);
	
	//3rd page
	inputLoanInfo(purchasePrice, interestRate, loanPeriod, downPayment);
	
	loadingBar();
	
	//4th page
	displaypersonalInfo (name, phoneNumber, email, propertyChoice, lotChoice);
	
	loanAmount = calcLoanAmount(loanAmount, purchasePrice, downPayment);
	
	totalInterest = calcTotalInterest (totalInterest, interestRate, loanAmount, loanPeriod);
	
	totalPayment = calcTotalPayment (totalPayment, loanAmount, totalInterest);
	
	monthlyPayment = calcMonthlyPayment (monthlyPayment, totalPayment, loanPeriod);
	
	displayCalculation (loanAmount, totalInterest, monthlyPayment);
	
	cout << "\n\n\n Thank you!";
	
	return 0;
}


void displayPropertyType()
{
	string propertyType[2]={"  TYPE A - RUSA TERRACE HOME", "  TYPE B - BAYU APARTMENT"};
	
	system("cls");
	cout << "\n\t===================================";
	cout << "\n\t           NHAS PROPERTY";
	cout << "\n\t===================================";
	
	cout << "\n\n\n   Property Catalogue";
	cout << "\n------------------------";
	
	for (int x = 0; x < 2; x++)
	{
		cout << endl << endl << " " << propertyType[x];
	}
}

void displayPropertyA(string& propertyChoice)
{
	system("cls");
	propertyChoice = "Rusa Terrace Home";
	cout << "\n RUSA TERRACE HOME TYPE: ";
	cout << "\n\n  C - Corner Lot";
	cout << "\n  I - Intermediate Lot";
}

void displayTypeACorner(string& lotChoice, double& purchasePrice)
{
	lotChoice = "Corner lot";
	purchasePrice = 800000;
	system ("cls");
	cout << "\n RUSA TERRACE HOME [CORNER LOT]";
	cout << "\n\n Property purchase price : RM 800,000";
	cout << "\n Sq ft : 4,670 sqft ";
}

void displayTypeAIntermediate(string& lotChoice, double& purchasePrice)
{
	lotChoice = "Intermediate lot";
	purchasePrice = 650000;
	system ("cls");
	cout << "\n RUSA TERRACE HOME [INTERMEDIATE LOT]";
	cout << "\n\n Property purchase price : RM 650,000";
	cout << "\n Sq feet :  3,290 sqft";
}

void displayPropertyB(string& propertyChoice)
{
	system("cls");
	propertyChoice = "Bayu Apartment";
	cout << "\n BAYU APARTMENT TYPE: ";
	cout << "\n\n  E - End Lot";
	cout << "\n  I - Intermediate Lot";
}

void displayTypeBEnd(string& lotChoice, double& purchasePrice)
{
	lotChoice = "End lot";
	purchasePrice = 400000;
	system ("cls");
	cout << "\n BAYU APARTMENT [END LOT]";
	cout << "\n\n Property purchase price : RM 400,000";
	cout << "\n Sq feet : 1,300 sqft ";
}

void displayTypeBIntermediate(string& lotChoice, double& purchasePrice)
{
	lotChoice = "Intermediate lot";
	purchasePrice = 200000;
	system ("cls");
	cout << "\n BAYU APARTMENT [INTERMEDIATE LOT]";
	cout << "\n\n Property purchase price : RM 200,000";
	cout << "\n Sq feet :  900 sqft";
}

void loadingBar()
{
	for (int i=0; i < 20; i++)
	{
		system ("cls");
    	cout << "\n Loading...\n";
    	cout << " [";
    	cout << setw(20) << left << string(i, '=');
    	cout << "]";
    	Sleep (100);
	}
}

void inputPersonalInfo(string& name, string& phoneNumber, string& email)
{
	cout << "\n  Personal Information";
	cout << "\n------------------------";
	cout << "\n\n Enter name: ";
	cin >> name;
	cout << "\n Enter phone number: +60";
	cin >> phoneNumber;
	cout << "\n Enter email address: ";
	cin >> email;
}

void inputLoanInfo(double& purchasePrice, double& interestRate, double& loanPeriod, double& downPayment)
{
	system ("cls");
	cout << "\n  "\n Enter email address: ";
	cout << "\n--------------------------";
	cout << "\n\n Property purchase price: RM " << purchasePrice;
	cout << "\n\n Enter interest rate (%): ";
	cin >> interestRate;
	cout << "\n Enter loan period (years): ";
	cin >> loanPeriod;
	
	int i = 0;
	while ( i < 1 )
	{
		cout << "\n Enter down payment rate (%): ";
		cin >> downPayment;
	
		if (downPayment < 10)
		{
			cout << "\nDown payment rate needs to be at least 10%";
		}
		
		else if(downPayment>=10)
		{
			break;
		}
	}
}

double calcLoanAmount(double& loanAmount, double purchasePrice, double downPayment)
{
	loanAmount = purchasePrice - (purchasePrice * downPayment/100);
	
	return loanAmount;
}

double calcTotalInterest (double& totalInterest, double interestRate, double& loanAmount, double loanPeriod)
{
	totalInterest = (interestRate/100 * loanAmount) * loanPeriod;
	
	return totalInterest;
}

double calcTotalPayment (double totalPayment, double& loanAmount, double& totalInterest)
{
	totalPayment = loanAmount + totalInterest;
	
	return totalPayment;
}

double calcMonthlyPayment (double monthlyPayment, double& totalPayment, double loanPeriod)
{
	monthlyPayment = (totalPayment / loanPeriod) / 12;
	
	return monthlyPayment;
}

void displaypersonalInfo (string& name, string& phoneNumber, string& email, string propertyChoice, string lotChoice)
{
	system("cls");
	cout << "\n   Your House Loan Repayment";
	cout << "\n-------------------------------";
	cout << "\n Name: " << name;
	cout << "\n\n Phone Number: +60" << phoneNumber;
	cout << "\n\n Email Address: " << email;
	cout << "\n\n Property Name: " << propertyChoice;
	cout << "\n\n Property Type: " << lotChoice;
}

void displayCalculation (double& loanAmount, double& totalInterest, double& monthlyPayment)
{
	cout << "\n\n Loan Amount: RM " << loanAmount;
    cout << "\n\n Total Interest: RM " << totalInterest;
	cout << "\n\n Monthly Payment: RM " << monthlyPayment;
}
