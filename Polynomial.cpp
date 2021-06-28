#include "Polynomial.h"

Polynomial::Polynomial(){

	for(int i=0; i<=9; i++)
		this->coef[i] = 0;  // ��� coef�� 0���� �ʱ�ȭ
}

Polynomial Polynomial::operator+(Polynomial& b){

	Polynomial C;  // �� ���׽��� ������ ����

	if(this->degree > b.degree) C.degree = this->degree;
	else C.degree = b.degree;  // C�� degree�� ����
	
	for(int i=0; i<=C.degree; i++)
		C.coef[i] = this->coef[i] + b.coef[i];  // ������ ����

	return C;

}

Polynomial Polynomial::operator-(Polynomial& b){

	Polynomial C;  // �� ���׽��� �y���� ���� 

	if(this->degree > b.degree) C.degree = this->degree;
	else C.degree = b.degree;  // C�� degree�� ����
	
	for(int i=0; i<=C.degree; i++)
		C.coef[i] = this->coef[i] - b.coef[i];  // �y���� ����

	return C;

}

Polynomial Polynomial::operator*(Polynomial& b){

	Polynomial C;  // �� ���׽��� ������ ����

	C.degree = this->degree + b.degree;  // C�� degree�� ����
	
	for(int x=0; x<=this->degree; x++)
		for(int y=0; y<=b.degree; y++)
			C.coef[x+y] += this->coef[x] * b.coef[y];  // ������ ����

	return C;

}

bool Polynomial::operator==(Polynomial& b){

	int max;  // max: degree�� �ִ�
	if(this->degree > b.degree) max = this->degree;
	else max = b.degree;
	
	for(int i=0; i<=max; i++)
		if(this->coef[i] != b.coef[i]) return false;  // ���� ���� ��Ұ� �ϳ��� ������ false

	return true;

}

istream& operator>>(istream& is, Polynomial& a){

	is >> a.degree;  // degree �Է¹ޱ�

	for(int i=a.degree; i>=0; i--)
		is >> a.coef[i];  // coef �Է¹ޱ�

	return is;

}

ostream& operator<<(ostream& os, Polynomial& a){

	bool allzero = true;  // allzero: ��� ����� ���� 0�̸� true

	for(int i=a.degree; i>=0; i--)  // ��� ����� ���� 0���� �˻�
		if(a.coef[i] != 0) allzero = false;

	if(allzero == true){  // ��� ����� ���� 0�� ��� 0�� ����ϰ� ����
		cout << "0" << endl;
		return os;
	}

	if(a.coef[a.degree] > 0) os << a.coef[a.degree] << "x^" << a.degree;		// ���, ���� �����Ͽ� �ְ����� ���
	else if(a.coef[a.degree] < 0) os << " - " << - a.coef[a.degree] << "x^" << a.degree;

	for(int i=a.degree-1; i>=1; i--){				// ���, ���� �����Ͽ� ������ ���(�߰�)
		if(a.coef[i] > 0) os << " + " << a.coef[i] << "x^" << i;
		else if(a.coef[i] < 0) os << " - " << - a.coef[i] << "x^" << i;
	}
	
	if(a.coef[0] > 0) os << " + " << a.coef[0] << endl;		 //  ���, ���� �����Ͽ� ����� ���
	else if(a.coef[0] < 0) os << " - " << - a.coef[0] << endl;
	
	return os;

}