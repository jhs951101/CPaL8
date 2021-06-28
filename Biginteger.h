#pragma once
#include<iostream>

using namespace std;

class BigInteger
{
private:
	int length;// the length of integer
	int digit[10000]; // each number of the integer

public:
	BigInteger(int n = 0);

	BigInteger operator+(BigInteger & b); // a + b;
	BigInteger operator-(BigInteger & b); // a - b;
	BigInteger operator*(BigInteger & b); // a * b;
	BigInteger& operator++(); // ++a;

	friend BigInteger pow(BigInteger a, int b); // a^b
	friend istream& operator>>(istream& is, BigInteger& a); // cin >> a;
	friend ostream& operator<<(ostream& os, BigInteger& a); // cout << a;
};