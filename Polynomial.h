#pragma once
#include<iostream>

using namespace std;

class Polynomial
{
private:
  int degree;
  int coef[10];

public:
  Polynomial(); // initialize all coefs as zeros

  Polynomial operator+(Polynomial& b);
  Polynomial operator-(Polynomial& b);
  Polynomial operator*(Polynomial& b);
  bool operator==(Polynomial& b);

  friend istream& operator>>(istream& is, Polynomial& a);
  friend ostream& operator<<(ostream& os, Polynomial& a);
};