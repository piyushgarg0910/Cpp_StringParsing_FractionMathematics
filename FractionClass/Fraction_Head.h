/*******************************************************************************************
********************************************************************************************
********************************************************************************************

Code By: Piyush Garg
Date: 05/01/2017

This is a header file for Class Fraction. It contains the declaration of class Fraction and
its members. The class has 2 member variables (numerator and denominator) of type long long.
It also contains memeber functions to display, reduce fraction to lowest form (factorize the
numerator and the denominator), constructors, destructor, and operations by overloading the 
+, *, /, ==, and > operators. Subtraction is done by changing the sign of the numerator and
adding the two fractions.

This files also contains the functions for converting the string input to fractions (to take
input from the user) and push the signs and fractions into 2 vectors which can be used for
evaluating an eqation with multiple fractions and sign. It contain another function for
evaluating the value of a vector of type fraction, and also a funtion to reduce the size of 
a vector after every operation from the point where the operation was performed.

********************************************************************************************
********************************************************************************************
*******************************************************************************************/

#pragma once
# include <sstream>
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

/*
Declaration and definition of class Fraction and its members.
*/
class Fraction
{
public:
	long long numerator, denominator;
	
	// Paramatrized Constructor
	Fraction(long long n, long long d)
	{
		numerator = n;
		denominator = d;
	}

	// Default Constructor (Initializes the values of numerator and denominator to 1)
	Fraction() 
	{
		numerator = 1;
		denominator = 1;
	};

	// Destructor
	~Fraction() {};

	/* 
	This is an overloaded + operator which adds two values of type Fraction and returns a Fraction
	The final value of the fraction is factorized before returning, so that the reduced form is used
	for display as well as for the next operation
	*/
	Fraction operator+(const Fraction &nxt)
	{
		long long num = numerator*nxt.denominator + denominator*nxt.numerator;
		long long den = denominator*nxt.denominator;
		return factorize(num, den);
	}

	/*
	This is an function to convert a subtraction into addition of a positive and a negative number.
	The Numerator of the equation is multiplied with -1, which in the next operation, will be added
	to as a negative fraction to give the value of subtraction between 2 fractions
	*/
	void sub()
	{
		numerator *= -1;
	}

	/*
	This is an overloaded * operator which multiplies two values of type Fraction and returns a Fraction
	The final value of the fraction is factorized before returning, so that the reduced form is used
	for display as well as for the next operation
	*/
	Fraction operator*(const Fraction &nxt)
	{
		long long num = numerator*nxt.numerator;
		long long den = denominator*nxt.denominator;
		return factorize(num, den);
	}

	/*
	This is an overloaded / operator which divided one values of type Fraction with another and returns
	a Fraction. The final value of the fraction is factorized before returning, so that the reduced form 
	is used for display as well as for the next operation
	*/
	Fraction operator/(const Fraction &nxt)
	{
		long long num = numerator*nxt.denominator;
		long long den = denominator*nxt.numerator;
		return factorize(num, den);
	}

	/*
	This is an overloaded == operator which compares two values of type fractions and returns 1 if they are
	equal or 0 if they are not equal
	*/
	int operator==(const Fraction &nxt)
	{
		if ((numerator == nxt.numerator) && (denominator == nxt.denominator))
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}

	/*
	This is an overloaded > operator which compares two values of type fractions and returns 1 if the value on
	the side is greater than that on the right side or 0 otherwise.
	*/
	int operator>(const Fraction &nxt)
	{
		if ((numerator*nxt.denominator > nxt.numerator*denominator))
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}

	/*
	This funtion is used to reduce the fractions to the lowest form. The funtion is divided into 2
	sections which perform the same operation but with a different efficiency. In the first section,
	the factors for till the half of the smallest value between numerator and denominator are checked
	for a maximum limit of 10000. In the second section, it is assumed that the likelyhood of the 
	occurance of the prime numbers is very less and we check for factors only till the squareroot of the
	smallest value amongst the numerator and denominator to speed up the calculation for higher numbers
	*/
	Fraction factorize(long long num, long long den)
	{
		long long max_nd = std::max(num, den);
		long long sqrt_max = sqrt(max_nd);
		long long fac = 2;
		if (max_nd <= 10000)
		{
			while (fac <= max_nd/2)
			{
				if ((num % fac == 0) && (den % fac == 0))
				{
					num = num / fac;
					den = den / fac;
				}
				else
				{
					fac++;
				}

			}
		}
		else
		{
			while (fac <= sqrt_max)
			{
				if ((num % fac == 0) && (den % fac == 0))
				{
					num = num / fac;
					den = den / fac;
				}
				else
				{
					fac++;
				}

			}
		}
		return(Fraction(num, den));
	}

	/*
	This is a function to display the fractions on the console in the form "num/den"
	*/
	void display_fraction()
	{
		cout << numerator << "/" << denominator;
	}
};
//end of class



/*
This function takes the current iteration, number of operators, number of fractions, vector of type 
Fractions, and vector of type character (for signs) as input and reduces the size of vectors depending
on the current iteration. This function supplements the evaluate function which calculates the value
for an equation with multiple fractions and operations
*/
void reduce_vector(int inc, int &signs, int &no_of_fracs, vector <Fraction> *eq, vector <char> *z)
{
	signs--;
	no_of_fracs--;
	(*eq).erase((*eq).begin() + inc + 1, (*eq).begin() + inc + 2);
	(*z).erase((*z).begin() + inc, (*z).begin() + inc + 1);
}


/*
This function is used to convert the string input on the console to sepearate fractions and
operators, and pushes them into fraction and char vectors. These vectors can be used in the 
evaluate function to calculate final value of the equation entered as a string
*/
void get_fractions(string s, vector <Fraction> *eq, vector <char> *z)
{
	long long i[2];
	char ch[2];
	stringstream ss(s);
	while (ss)
	{
		ss >> i[0] >> ch[0] >> i[1] >> ch[1];
		(*eq).push_back(Fraction(i[0], i[1]));
		(*z).push_back(ch[1]);
	}
	(*z).pop_back();
}


/*
This function takes the vector of type Fraction and signs as input and calculates the final
value. The function is arranged for priority based operation for /,*,-, and + respectively.
*/
void evaluate(vector <Fraction> *eq, vector <char> *z)
{
	int no_of_fracs = (*eq).size();
	int signs = (*z).size();

	for (int inc = 0; inc < signs; inc++)
	{
		if ((*z)[inc] == '/')
		{
			(*eq)[inc] = (*eq)[inc] / (*eq)[inc + 1];
			reduce_vector(inc, signs, no_of_fracs, &(*eq), &(*z));
			if (inc < signs)
			{
				if ((*z)[inc] == '/')
				{
					inc--;
				}
			}
		}
	}

	for (int inc = 0; inc < signs; inc++)
	{
		if ((*z)[inc] == '*')
		{
			(*eq)[inc] = (*eq)[inc] * (*eq)[inc + 1];
			reduce_vector(inc, signs, no_of_fracs, &(*eq), &(*z));
			if (inc < signs)
			{
				if ((*z)[inc] == '*')
				{
					inc--;
				}
			}
		}
	}

	for (int inc = 0; inc < signs; inc++)
	{
		if ((*z)[inc] == '-')
		{
			(*eq)[inc + 1].sub();
			(*z)[inc] = '+';
		}
	}

	for (int inc = 0; inc < signs; inc++)
	{
		if ((*z)[inc] == '+')
		{
			(*eq)[inc] = (*eq)[inc] + (*eq)[inc + 1];
			reduce_vector(inc, signs, no_of_fracs, &(*eq), &(*z));
			if (inc < signs)
			{
				if ((*z)[inc] == '+')
				{
					inc--;
				}
			}
		}
	}
}