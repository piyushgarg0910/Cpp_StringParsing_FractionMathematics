/*******************************************************************************************
********************************************************************************************
********************************************************************************************

Code By: Piyush Garg
Date: 05/01/2017

This is a code file to test the functionalities of the Fraction_Head.h file with a console
input and ouput. This file takes the choice to evaluate the equation of compare two 
equations from the user. Depending on the choice, it asks equation as a 1 sided input or a 
2 sided input seperated by '?'. If the choice is to evaluate the equation, it converts the
string to fractions and sings and calculates final value. If the entered choice is to
find the relation between two sides, it converts the entered string into two equations with
fractions and signs, evaluates final answer for each sides, and then compares them.

********************************************************************************************
********************************************************************************************
*******************************************************************************************/

# include <sstream>
# include <iostream>
# include <vector>
# include <algorithm>
# include "Fraction_Head.h"
using namespace std;

int main()
{
	int choice;
	char cho;

	// Loop to keep asking for new equation as long as the user requests
	do {
		string s, eq1, eq2;
		vector <Fraction> l_eq, r_eq;
		vector <char> l_z, r_z;
		
		// Loop to continue asking user to enter the right choice if he/she enters the wrong choice 
		do
		{
			cout << "Enter 1 to compare two equations and 2 to evaluate one eqation: ";
			cin >> choice;
			if ((choice == 1) || (choice == 2))
			{
				break;
			}
		} while (1);

		// Ask for the input equation depending on the choice
		if (choice == 1)
		{
			cout << "\n\n" << "Enter 2 equations seperated by '?' " << endl ;
		}
		else
		{
			cout << "\n\n" <<"Enter the equation to be evaluated: " << endl;
		}

		// Get input in for of string
		getline(cin >> ws, s);
		cout << endl;
		int i1 = 0;
		int i2 = 0;
		eq1 = s;
		eq2 = s;

		// Depending on the choice convert the string to one or two equations and evaluate
		if (choice == 1)
		{
			while (eq1[i1] != '?')
			{
				i1++;
			}
			eq1.erase(eq1.begin() + i1, eq1.end());
			i1++;
			get_fractions(eq1, &l_eq, &l_z); // Equation 1
			evaluate(&l_eq, &l_z); // Resolved Value of Equation 1
			while (s[i1] != '\0')
			{
				eq2[i2] = s[i1];
				i1++;
				i2++;
			}
			eq2.erase(eq2.begin() + i2, eq2.end());
			get_fractions(eq2, &r_eq, &r_z); // Equation 2
			evaluate(&r_eq, &r_z); // Resolved Value of Equation 2
			cout << "Left Side Equation: ";
			l_eq[0].display_fraction(); // Display Resolved Value of Equation 1
			cout << endl << "Right Side Equation: ";
			r_eq[0].display_fraction(); // Display Resolved Value of Equation 2
			cout << endl;
			int comp;
			comp = l_eq[0] == r_eq[0]; // Find if both values are equal
			if (comp) // If they are equal print both values to be equal
			{
				cout << "LHS = RHS (Both sides are Equal)";
			}
			else // If not equal, Find which side is greater
			{
				l_eq[0].display_fraction();
				cout << " != ";
				r_eq[0].display_fraction();
				cout << endl;
				if (l_eq[0] > r_eq[0]) // If LHS is greater
				{
					l_eq[0].display_fraction();
					cout << " > ";
					r_eq[0].display_fraction();
					cout << endl;
				}
				else // If RHS is greater
				{

					l_eq[0].display_fraction();
					cout << " < ";
					r_eq[0].display_fraction();
					cout << endl;
				}
			}
			cout << endl;
		}
		else // If the choice is to evaluate only
		{
			get_fractions(eq2, &l_eq, &l_z); // Convert String to Equation
			evaluate(&l_eq, &l_z); // Resolved value of the Equation
			cout << "The evaluated Value is: ";
			l_eq[0].display_fraction(); // Display the final value
			cout << endl << endl;
		}
		// Ask for a choice to perform another operation
		cout << "Do you wish to perform another operation ('Y' or 'y')? : ";
		cin >> cho;
		cout << endl;
		cin.get();
	} while ((cho == 'y') || (cho == 'Y'));

	cin.get();
	return 0;
}