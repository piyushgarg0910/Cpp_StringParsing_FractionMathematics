/*******************************************************************************************
********************************************************************************************
********************************************************************************************

Code By: Piyush Garg
Date: 05/02/2017

This is a unit test file for the Fraction class. The Google Test framework for C++ using 
Visual Studio is used for creating this file. This file tests the operation of all the 
functions in the Fraction_Head.h file, including those which are not the member of class
Fraction. The tested functionality include test for Constructors (Default and Paramatrized),
Operators +,-,*,/,==, and >, subtraction function, factorize function, evaluate function, and 
get_fractions funciton (to convert string to fractions and signs)

There are a total of 42 test cases that are divided into 6 sections. The functionality tested
in each of the section are as follows:
I) The first section tests constructor and validity of the members
II) The second section test operations between 2 fractions using any 1 of the operators. It
	also test for the equality and comparison between 2 equations involving 2 fractions and 
	1 operator each.
III) This section tests operations between 3 fractions using any two of the operators. It
	 also test for the equality and comparison between 2 equations involving 3 fractions and 
	 2 operators each.
IV) In the fourth section, the operation between 4 fractions and any 3 operators is tested. It
	also test equality and comparison between 2 equations with 4 fractions and 2 operators
	each
V) In the fifth section, the operation with 5 fractions and 4 operators is tested
VI) In this section a string is converted to fractions and signs. This section also tests the
	evaluation and comparison the fractions and signs obtained from the string

********************************************************************************************
********************************************************************************************
*******************************************************************************************/

# include <sstream>
#include "stdafx.h"
#include "gtest\gtest.h"
#include "Fraction_Head.h"



/*
The class ConstructorTest has 2 tests to test the constructor and validity of the members 
of the Class Fraction 
*/
class ConstructorTest : public ::testing::Test
{
public:
	virtual void SetUp()
	{
		fra_para_con.numerator = 3;
		fra_para_con.denominator = 2;
	}
	virtual void TearDown()
	{

	}
	Fraction fra_para_con, fra_def_con;
};
//Test for Default Constructor
TEST_F(ConstructorTest, Default_Constructor)
{
	EXPECT_EQ(1, fra_def_con.numerator);
	EXPECT_EQ(1, fra_def_con.denominator);
}
//Test for setting the class members
TEST_F(ConstructorTest, Parametrized_Constructor)
{
	EXPECT_EQ(3, fra_para_con.numerator);
	EXPECT_EQ(2, fra_para_con.denominator);
}


/*
Class Operations is used for evaluating the result of equations with 2 fractions
and an operator
*/
class Operations : public ::testing::Test
{
public:
	virtual void SetUp()
	{
		frac0.numerator = 25; frac0.denominator = 18;
		frac1.numerator = 14; frac1.denominator = 9;
		frac2.numerator = 25; frac2.denominator = 18;
		frac3.numerator = 3; frac3.denominator = 2;
		frac4.numerator = 13860; frac4.denominator = 30030;

		add = '+'; sub = '-'; mul = '*'; div = '/';
	}
	virtual void TearDown()
	{

	}
	 
	char add, sub, mul, div;
	Fraction frac0, frac1, frac2, frac3, frac4, result;
};

// Check for addition operation using overloaded + operator
TEST_F(Operations, Addition)
{
	result = frac0 + frac1;
	EXPECT_EQ(18, result.denominator);
	EXPECT_EQ(53, result.numerator);
}

// Check for subtraction using sub() to convert the numerator into a negative
// number and then adding it using overloaded + operator
TEST_F(Operations, Subtraction)
{
	frac1.sub();
	result = frac0 + frac1;
	EXPECT_EQ(6, result.denominator);
	EXPECT_EQ(-1, result.numerator);
}

// Check for Multiplication operation using overloaded * operator
TEST_F(Operations, Multiplication)
{
	result = frac0 * frac1;
	EXPECT_EQ(81, result.denominator);
	EXPECT_EQ(175, result.numerator);
}

// Check for Division operation using overloaded / operator
TEST_F(Operations, Division)
{
	result = frac0 / frac1;
	EXPECT_EQ(28, result.denominator);
	EXPECT_EQ(25, result.numerator);
}

// Check for Equality operation using overloaded == operator
TEST_F(Operations, Equality)
{
	int m = frac0 == frac2;
	EXPECT_EQ(1, m);
}

// Check for Non Equality operation using overloaded == operator
TEST_F(Operations, Non_Equality)
{
	int m = frac3 == frac2;
	EXPECT_EQ(0, m);
}

// Check for Greater Than operation using overloaded > operator
TEST_F(Operations, Greater_Than)
{
	int m = frac1 > frac2;
	EXPECT_EQ(1, m);
}

// Check for Less Than operation using overloaded > operator
TEST_F(Operations, Less_Than)
{
	int m = frac3 > frac1;
	EXPECT_EQ(0, m);
}

// Check for Factorize function which reduces the fraction to lowest form
TEST_F(Operations, Factorize)
{
	result = result.factorize(frac4.numerator,frac4.denominator);
	EXPECT_EQ(6, result.numerator);
	EXPECT_EQ(13, result.denominator);
}


/*
The class Double_Operations is used to check the working of the evaluate function
to get the output for equations with 3 fractions having any 2 operations
*/
class Double_Operations : public ::testing::Test
{
public:
	virtual void SetUp()
	{
		frac0.numerator = 14; frac0.denominator = 9;
		frac1.numerator = 25; frac1.denominator = 18;
		frac2.numerator = 3; frac2.denominator = 2;
		vec_frac_1.push_back(frac0);
		vec_frac_1.push_back(frac1);
		vec_frac_1.push_back(frac2);
		vec_frac_2.push_back(frac0);
		vec_frac_2.push_back(frac2);
		vec_frac_2.push_back(frac1);

		add = '+'; sub = '-'; mul = '*'; div = '/';
	}
	virtual void TearDown()
	{

	}

	char add, sub, mul, div;
	Fraction frac0, frac1, frac2, result;
	vector <Fraction> vec_frac_1, vec_frac_2;
	vector <char> sign_1, sign_2;
};

// Addition operation followed by another addition
TEST_F(Double_Operations, Add_Add)
{
	sign_1.push_back(add);
	sign_1.push_back(add);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(40, vec_frac_1[0].numerator);
	EXPECT_EQ(9, vec_frac_1[0].denominator);
}

// Addition and Subtraction
TEST_F(Double_Operations, Add_Sub)
{
	sign_1.push_back(add);
	sign_1.push_back(sub);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(13, vec_frac_1[0].numerator);
	EXPECT_EQ(9, vec_frac_1[0].denominator);
}

// Addition and Multiplication
TEST_F(Double_Operations, Add_Mul)
{
	sign_1.push_back(add);
	sign_1.push_back(mul);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(131, vec_frac_1[0].numerator);
	EXPECT_EQ(36, vec_frac_1[0].denominator);
}

// Addition and Divsion
TEST_F(Double_Operations, Add_Div)
{
	sign_1.push_back(add);
	sign_1.push_back(div);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(67, vec_frac_1[0].numerator);
	EXPECT_EQ(27, vec_frac_1[0].denominator);
}

// Subtraction and Subtraction
TEST_F(Double_Operations, Sub_Sub)
{
	sign_1.push_back(sub);
	sign_1.push_back(sub);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(-4, vec_frac_1[0].numerator);
	EXPECT_EQ(3, vec_frac_1[0].denominator);
}

// Subtraction and Division
TEST_F(Double_Operations, Sub_Div)
{
	sign_1.push_back(sub);
	sign_1.push_back(div);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(17, vec_frac_1[0].numerator);
	EXPECT_EQ(27, vec_frac_1[0].denominator);
}

// Multiplication and Subtraction
TEST_F(Double_Operations, Mul_Sub)
{
	sign_1.push_back(mul);
	sign_1.push_back(sub);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(107, vec_frac_1[0].numerator);
	EXPECT_EQ(162, vec_frac_1[0].denominator);
}

// Multiplication and Division
TEST_F(Double_Operations, Mul_Div)
{
	sign_1.push_back(mul);
	sign_1.push_back(div);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(350, vec_frac_1[0].numerator);
	EXPECT_EQ(243, vec_frac_1[0].denominator);
}

// Division and Multiplication
TEST_F(Double_Operations, Div_Mul)
{
	sign_1.push_back(div);
	sign_1.push_back(mul);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(42, vec_frac_1[0].numerator);
	EXPECT_EQ(25, vec_frac_1[0].denominator);
}

// Division and Addition
TEST_F(Double_Operations, Div_Add)
{
	sign_1.push_back(div);
	sign_1.push_back(add);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(131, vec_frac_1[0].numerator);
	EXPECT_EQ(50, vec_frac_1[0].denominator);
}

// Division and Subtraction
TEST_F(Double_Operations, Div_Sub)
{
	sign_1.push_back(div);
	sign_1.push_back(sub);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(-19, vec_frac_1[0].numerator);
	EXPECT_EQ(50, vec_frac_1[0].denominator);
}

// Equality check for 2 operations
TEST_F(Double_Operations, Equality)
{
	sign_1.push_back(div);
	sign_1.push_back(mul);
	sign_2.push_back(mul);
	sign_2.push_back(div);
	evaluate(&vec_frac_1, &sign_1);
	evaluate(&vec_frac_2, &sign_2);
	int m = vec_frac_1[0] == vec_frac_2[0];
	EXPECT_EQ(1, m);
}

// Non Equality and Greater Than check for 2 equations
TEST_F(Double_Operations, Greater_Than)
{
	sign_1.push_back(div);
	sign_1.push_back(mul);
	sign_2.push_back(div);
	sign_2.push_back(mul);
	evaluate(&vec_frac_1, &sign_1);
	evaluate(&vec_frac_2, &sign_2);
	int m = vec_frac_1[0] == vec_frac_2[0];
	int n = vec_frac_1[0] > vec_frac_2[0];
	EXPECT_EQ(0, m);
	EXPECT_EQ(1, n);
}

// Non Equality and Less than check for 2 equations
TEST_F(Double_Operations, Less_Than)
{
	sign_1.push_back(sub);
	sign_1.push_back(sub);
	sign_2.push_back(mul);
	sign_2.push_back(mul);
	evaluate(&vec_frac_1, &sign_1);
	evaluate(&vec_frac_2, &sign_2);
	int m = vec_frac_1[0] == vec_frac_2[0];
	int n = vec_frac_1[0] > vec_frac_2[0];
	EXPECT_EQ(0, m);
	EXPECT_EQ(0, n);
}


/*
The class Trile_Operations is used to check the working of the evaluate function
to get the output for equations with 4 fractions having any 3 operations
*/
class Triple_Operations : public ::testing::Test
{
public:
	virtual void SetUp()
	{
		frac0.numerator = 13; frac0.denominator = 4;
		frac1.numerator = 8; frac1.denominator = 5;
		frac2.numerator = 6; frac2.denominator = 11;
		frac3.numerator = 9; frac3.denominator = 13;

		vec_frac_1.push_back(frac0);
		vec_frac_1.push_back(frac1);
		vec_frac_1.push_back(frac2);
		vec_frac_1.push_back(frac3);

		vec_frac_2.push_back(frac0);
		vec_frac_2.push_back(frac1);
		vec_frac_2.push_back(frac2);
		vec_frac_2.push_back(frac3);

		add = '+'; sub = '-'; mul = '*'; div = '/';
	}
	virtual void TearDown()
	{

	}

	char add, sub, mul, div;
	Fraction frac0, frac1, frac2, frac3;
	vector <Fraction> vec_frac_1, vec_frac_2;
	vector <char> sign_1, sign_2;
};

// Addition, Addition and subtraction
TEST_F(Triple_Operations, Add_Add_Sub)
{
	sign_1.push_back(add);
	sign_1.push_back(add);
	sign_1.push_back(sub);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(13451, vec_frac_1[0].numerator);
	EXPECT_EQ(2860, vec_frac_1[0].denominator);
}

// Addition, Subtraction and subtraction
TEST_F(Triple_Operations, Add_Sub_Sub)
{
	sign_1.push_back(add);
	sign_1.push_back(sub);
	sign_1.push_back(sub);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(10331, vec_frac_1[0].numerator);
	EXPECT_EQ(2860, vec_frac_1[0].denominator);
}

// Multiplication, Multiplication and Division
TEST_F(Triple_Operations, Mul_Mul_Div)
{
	sign_1.push_back(mul);
	sign_1.push_back(mul);
	sign_1.push_back(div);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(676, vec_frac_1[0].numerator);
	EXPECT_EQ(165, vec_frac_1[0].denominator);
}

// Multiplication, Division and subtraction
TEST_F(Triple_Operations, Mul_Div_Sub)
{
	sign_1.push_back(mul);
	sign_1.push_back(div);
	sign_1.push_back(sub);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(1724, vec_frac_1[0].numerator);
	EXPECT_EQ(195, vec_frac_1[0].denominator);
}

// Addition, Multiplication and Division
TEST_F(Triple_Operations, Add_Mul_Div)
{
	sign_1.push_back(add);
	sign_1.push_back(mul);
	sign_1.push_back(div);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(2977, vec_frac_1[0].numerator);
	EXPECT_EQ(660, vec_frac_1[0].denominator);
}

// Equality test for 2 equations
TEST_F(Triple_Operations, Equality)
{
	sign_1.push_back(add);
	sign_1.push_back(add);
	sign_1.push_back(sub);
	sign_2.push_back(add);
	sign_2.push_back(add);
	sign_2.push_back(sub);
	evaluate(&vec_frac_1, &sign_1);
	evaluate(&vec_frac_2, &sign_2);
	int m = vec_frac_1[0] == vec_frac_2[0];
	EXPECT_EQ(1, m);
}

// Non Equality and Greater Than test for 2 equations
TEST_F(Triple_Operations, Greater_Than)
{
	sign_1.push_back(add);
	sign_1.push_back(add);
	sign_1.push_back(sub);
	sign_2.push_back(add);
	sign_2.push_back(sub);
	sign_2.push_back(sub);
	evaluate(&vec_frac_1, &sign_1);
	evaluate(&vec_frac_2, &sign_2);
	int m = vec_frac_1[0] == vec_frac_2[0];
	int n = vec_frac_1[0] > vec_frac_2[0];
	EXPECT_EQ(0, m);
	EXPECT_EQ(1, n);
}


// Non Equality and Less Than test for 2 equations
TEST_F(Triple_Operations, Less_Than)
{
	sign_1.push_back(add);
	sign_1.push_back(add);
	sign_1.push_back(sub);
	sign_2.push_back(mul);
	sign_2.push_back(div);
	sign_2.push_back(sub);
	evaluate(&vec_frac_1, &sign_1);
	evaluate(&vec_frac_2, &sign_2);
	int m = vec_frac_1[0] == vec_frac_2[0];
	int n = vec_frac_1[0] > vec_frac_2[0];
	EXPECT_EQ(0, m);
	EXPECT_EQ(0, n);
}

/*
The class Quad_Operations is used to check the working of the evaluate function
to get the output for equations with 5 fractions having any 4 operations
*/
class Quad_Operations : public ::testing::Test
{
public:
	virtual void SetUp()
	{
		frac0.numerator = 13; frac0.denominator = 4;
		frac1.numerator = 8; frac1.denominator = 5;
		frac2.numerator = 3; frac2.denominator = 2;
		frac3.numerator = 3; frac3.denominator = 8;
		frac4.numerator = 9; frac4.denominator = 13;

		vec_frac_1.push_back(frac0);
		vec_frac_1.push_back(frac2);
		vec_frac_1.push_back(frac1);
		vec_frac_1.push_back(frac3);
		vec_frac_1.push_back(frac4);


		add = '+'; sub = '-'; mul = '*'; div = '/';
	}
	virtual void TearDown()
	{

	}

	char add, sub, mul, div;
	Fraction frac0, frac1, frac2, frac3, frac4;
	vector <Fraction> vec_frac_1, vec_frac_2;
	vector <char> sign_1, sign_2;
};

// Addition, Subtraction, Multiplication, and Division
TEST_F(Quad_Operations, Add_Sub_Mul_Div)
{
	sign_1.push_back(add);
	sign_1.push_back(sub);
	sign_1.push_back(mul);
	sign_1.push_back(div);
	evaluate(&vec_frac_1, &sign_1);
	EXPECT_EQ(233, vec_frac_1[0].numerator);
	EXPECT_EQ(60, vec_frac_1[0].denominator);
}

// Equality test for 2 equations with quad operations
TEST_F(Quad_Operations, Equality)
{
	sign_1.push_back(add);
	sign_1.push_back(sub);
	sign_1.push_back(mul);
	sign_1.push_back(div);
	sign_2.push_back(add);
	sign_2.push_back(sub);
	sign_2.push_back(div);
	sign_2.push_back(mul);
	vec_frac_2.push_back(frac0);
	vec_frac_2.push_back(frac2);
	vec_frac_2.push_back(frac1);
	vec_frac_2.push_back(frac4);
	vec_frac_2.push_back(frac3);
	evaluate(&vec_frac_1, &sign_1);
	evaluate(&vec_frac_2, &sign_2);
	int m = vec_frac_1[0] == vec_frac_2[0];
	EXPECT_EQ(1, m);
}

// Non Equality and Greater Than test for 2 equations
TEST_F(Quad_Operations, Greater_Than)
{
	sign_1.push_back(add);
	sign_1.push_back(sub);
	sign_1.push_back(mul);
	sign_1.push_back(div);
	sign_2.push_back(add);
	sign_2.push_back(sub);
	sign_2.push_back(div);
	sign_2.push_back(mul);
	vec_frac_2.push_back(frac0);
	vec_frac_2.push_back(frac2);
	vec_frac_2.push_back(frac1);
	vec_frac_2.push_back(frac3);
	vec_frac_2.push_back(frac4);
	evaluate(&vec_frac_1, &sign_1);
	evaluate(&vec_frac_2, &sign_2);
	int n = vec_frac_1[0] == vec_frac_2[0];
	int o = vec_frac_1[0] > vec_frac_2[0];
	EXPECT_EQ(0, n);
	EXPECT_EQ(1, o);
}

// Non Equality and Less Than test for 2 equations
TEST_F(Quad_Operations, Less_Than)
{
	sign_1.push_back(add);
	sign_1.push_back(sub);
	sign_1.push_back(mul);
	sign_1.push_back(div);
	sign_2.push_back(add);
	sign_2.push_back(add);
	sign_2.push_back(mul);
	sign_2.push_back(div);
	vec_frac_2.push_back(frac0);
	vec_frac_2.push_back(frac2);
	vec_frac_2.push_back(frac4);
	vec_frac_2.push_back(frac3);
	vec_frac_2.push_back(frac1);
	evaluate(&vec_frac_1, &sign_1);
	evaluate(&vec_frac_2, &sign_2);
	int n = vec_frac_1[0] == vec_frac_2[0];
	int o = vec_frac_1[0] > vec_frac_2[0];
	EXPECT_EQ(0, n);
	EXPECT_EQ(0, o);
}

/*
This class is for tests designed to take inputs in for of string and convert
them into fractions and signs. These fractions are then evaluated to test the 
working of all the functions together. To input 2 different equations to check
the equality, the equations are entered seperated by '?'
*/
class Read_Fractions_From_String : public ::testing::Test
{
public:
	virtual void SetUp()
	{
	}
	virtual void TearDown()
	{

	}

	char ch[2];
	int f[2];
	vector <Fraction> vec_frac, vec_frac_1;
	vector <char> sign, sign_1;
};

// Check to read a string and convert it into fractions and Signs
TEST_F(Read_Fractions_From_String, Read_One_Side)
{
	string s = "1/2 + 3/4 + 5/6";
	get_fractions(s, &vec_frac, &sign);
	EXPECT_EQ(1, vec_frac[0].numerator);
	EXPECT_EQ(2, vec_frac[0].denominator);
	EXPECT_EQ(3, vec_frac[1].numerator);
	EXPECT_EQ(4, vec_frac[1].denominator);
	EXPECT_EQ(5, vec_frac[2].numerator);
	EXPECT_EQ(6, vec_frac[2].denominator);
	EXPECT_EQ('+', sign[0]);
	EXPECT_EQ('+', sign[1]);
};

// Check to read strings with 2 sides seperated by '?'
TEST_F(Read_Fractions_From_String, Read_Two_Sides)
{
	string s = "1/2 - 3/4 + 5/6 ? 5/6 - 3/4 + 1/2";
	string s1 = s, s2 = s;
	int i1 = 0;
	int i2 = 0;
	while (s1[i1] != '?')
	{
		i1++;
	}
	s1.erase(s1.begin() + i1, s1.end());
	i1++;
	while (s[i1] != '\0')
	{
		s2[i2] = s[i1];
		i1++;
		i2++;
	}
	s2.erase(s2.begin() + i2, s2.end());
	get_fractions(s1, &vec_frac, &sign);
	get_fractions(s2, &vec_frac_1, &sign_1);
	EXPECT_EQ(1, vec_frac[0].numerator);
	EXPECT_EQ(2, vec_frac[0].denominator);
	EXPECT_EQ(3, vec_frac[1].numerator);
	EXPECT_EQ(4, vec_frac[1].denominator);
	EXPECT_EQ(5, vec_frac[2].numerator);
	EXPECT_EQ(6, vec_frac[2].denominator);
	EXPECT_EQ('-', sign[0]);
	EXPECT_EQ('+', sign[1]);
	EXPECT_EQ(5, vec_frac_1[0].numerator);
	EXPECT_EQ(6, vec_frac_1[0].denominator);
	EXPECT_EQ(3, vec_frac_1[1].numerator);
	EXPECT_EQ(4, vec_frac_1[1].denominator);
	EXPECT_EQ(1, vec_frac_1[2].numerator);
	EXPECT_EQ(2, vec_frac_1[2].denominator);
	EXPECT_EQ('-', sign_1[0]);
	EXPECT_EQ('+', sign_1[1]);
};

// Check to read a string and convert it into fractions and Signs
// and evaluate the output
TEST_F(Read_Fractions_From_String, Evaluate_From_String)
{
	string s = "1/2 + 3/4 + 5/6";
	get_fractions(s, &vec_frac, &sign);
	evaluate(&vec_frac, &sign);
	EXPECT_EQ(25, vec_frac[0].numerator);
	EXPECT_EQ(12, vec_frac[0].denominator);
};

// Check to read strings with 2 sides seperated by '?' and check for
// Equality
TEST_F(Read_Fractions_From_String, Equality_From_String)
{
	string s = "1/2 - 3/4 + 5/6 ? 5/6 - 3/4 + 1/2";
	string s1 = s, s2 = s;
	int i1 = 0;
	int i2 = 0;
	while (s1[i1] != '?')
	{
		i1++;
	}
	s1.erase(s1.begin() + i1, s1.end());
	i1++;
	while (s[i1] != '\0')
	{
		s2[i2] = s[i1];
		i1++;
		i2++;
	}
	s2.erase(s2.begin() + i2, s2.end());
	get_fractions(s1, &vec_frac, &sign);
	get_fractions(s2, &vec_frac_1, &sign_1);
	evaluate(&vec_frac, &sign);
	evaluate(&vec_frac_1, &sign_1);
	int m = vec_frac[0] == vec_frac_1[0];
	EXPECT_EQ(1, m);
};

// Check to read strings with 2 sides seperated by '?' and check for
// Non Equality and Greater Than
TEST_F(Read_Fractions_From_String, Non_Equality_From_String)
{
	string s = "1/2 - 3/4 + 5/6 ? 5/6 - 3/4 - 1/2";
	string s1 = s, s2 = s;
	int i1 = 0;
	int i2 = 0;
	while (s1[i1] != '?')
	{
		i1++;
	}
	s1.erase(s1.begin() + i1, s1.end());
	i1++;
	while (s[i1] != '\0')
	{
		s2[i2] = s[i1];
		i1++;
		i2++;
	}
	s2.erase(s2.begin() + i2, s2.end());
	get_fractions(s1, &vec_frac, &sign);
	get_fractions(s2, &vec_frac_1, &sign_1);
	evaluate(&vec_frac, &sign);
	evaluate(&vec_frac_1, &sign_1);
	int m = vec_frac[0] == vec_frac_1[0];
	int n = vec_frac[0] > vec_frac_1[0];
	EXPECT_EQ(0, m);
	EXPECT_EQ(1, n);
};