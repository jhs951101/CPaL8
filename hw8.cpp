//#include "ComplexNumber.h"
//#include "Integer.h"
#include "Polynomial.h"
#include "BigInteger.h"
#include<iostream>

//void testComplexNumber()
//{
//	ComplexNumber a(3, 4);
//	ComplexNumber b(2, 3);
//
//	cout << "a: " << a << endl;
//	cout << "b: " << b << endl;
//	cout << "a + b = " << (a + b) << endl;
//	cout << "a - b = " << (a - b) << endl;
//	cout << "a + 5 = " << (a + 5) << endl;
//	cout << "4 + a = " << (4 + a) << endl;
//	cout << "a - 5 = " << (a - 5) << endl;
//	cout << "4 - a = " << (4 - a) << endl;
//	cout << "++a: " << (++a) << endl;
//	cout << "--b: " << (--b) << endl;
//
//
//	if (a == b) cout << "a and b are equal" << endl;
//	else cout << "a and b are not equal" << endl;
//}

/*
void testInteger()
{
	Integer a, b;

	cout << "Input the first integer: ";
	cin >> a;

	cout << "Input the second integer: ";
	cin >> b;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "a + b = " << (a + b) << endl;
	cout << "a - b = " << (a - b) << endl;
	cout << "a * b = " << (a * b) << endl;
	cout << "a / b = " << (a / b) << endl;
	cout << "a + 3 = " << (a + 3) << endl;
	cout << "a - 3 = " << (a - 3) << endl;
	cout << "a * 3 = " << (a * 3) << endl;
	cout << "a / 3 = " << (a / 3) << endl;
	cout << "++a: " << ++a << endl;
	cout << "++b: " << --b << endl;

	if (a == b) cout << "a and b are equal" << endl;
	else cout << "a and b are not equal" << endl;
}
*/

void testPolynomial()
{
	Polynomial a, b;

	cin >> a;
	cin >> b;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "a + b = " << (a + b) << endl;
	cout << "a - b = " << (a - b) << endl;
	cout << "a * b = " << (a * b) << endl;

	if (a == b) cout << "a and b are equal" << endl;
	else cout << "a and b are not equal" << endl;
}

void testBigInteger()
{
	BigInteger a, b, c;

	cin >> a;
	cin >> b;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "a + b = " << (a + b) << endl;
	cout << "a - b = " << (a - b) << endl;
	cout << "a * b = " << (a * b) << endl;
	cout << "++a = " << (++a) << endl;
	
	cin >> c;
	cout << "c: " << c << endl;
	cout << "pow(c, 100) = " << pow(c, 100) << endl;

	BigInteger d = 99915;
	BigInteger e = 99889;
	BigInteger f = 999999;

	cout << "d: " << d << endl;
	cout << "e: " << e << endl;
	cout << "f: " << f << endl;
	cout << "d + e= " << (d + e) << endl;
	cout << "d - e = " << (d - e) << endl;
	cout << "d * e = " << (d * e) << endl;
	cout << "++f = " << (++f) << endl;
}


int main()
{
	//testComplexNumber();
	//testInteger();
	//testPolynomial();
	testBigInteger();
}