#include "BigInteger.h"
#include <string>

BigInteger::BigInteger(int n){

	for(int i=0; i<10000; i++)
		this->digit[i] = 0;  // ��� digit�� 0���� ����

	int i = 1;
	while(n > 0){

		int pn = n%10;
		this->digit[i] = pn;  // ��� digit�� 0���� ����

		n = n/10;
		i++;
	}

	this->length = i-1;  // length ����

}

BigInteger BigInteger::operator+(BigInteger & b){

	int* num1 = new int[this->length +1];   // num1: this->digit[i] �� ���ڵ��� �����ϴ� �迭
	int* num2 = new int[b.length +1];		// num2: b.digit[i] �� ���ڵ��� �����ϴ� �迭

	for(int i=1; i<=this->length; i++)
		num1[i] = this->digit[i];   // num1: this->digit[i] �� ���ڵ��� ����

	for(int i=1; i<=b.length; i++)
		num2[i] = b.digit[i];		// num2: b.digit[i] �� ���ڵ��� ����
									// * �� ���� �� ���Ͱ� �ջ�Ǵ� ���� ���� ���� �켱 ���ڸ� �����س��� ������ ������ �ٽ� �Ѱ���
	

	BigInteger A;  // A: �� ����Ƽ���� ����
	int length;  // length: ����Ƽ�� ������ �ӽ� ����

	if(this->length > b.length)  // �ӽ� ���̸� ��������
		length = this->length +1;
	else
		length = b.length +1;

	for(int i=1; i<=length; i++){

		int num = this->digit[i] + b.digit[i];  // ���� �� �ڸ��� ����

		if(num > 9){  // �ڸ��ø��� �ʿ��� ���
			num = num%10;  // ���� �ڸ��� ��������
			A.digit[i+1] = 1;  // ���� �ڸ��� ���� �ڸ��� ����
		}
		A.digit[i] += num;  // ���� ���� �־���
	}

	int x = length; // �ӽ� ���̸� ����

	while(true){			// ex) 0521 �� 521
		if(A.digit[x] != 0){  	  // x--�� ���� ����Ƽ���� ���̸� ����
			A.length = x;
			break;
		}
		x--;
	}


	for(int i=1; i<=this->length; i++)
		this->digit[i] = num1[i]; // �����ߴ� ���ڸ� �ٽ� �Ѱ���(1)

	for(int i=1; i<=b.length; i++)
		b.digit[i] = num2[i];	  // �����ߴ� ���ڸ� �ٽ� �Ѱ���(1)

	delete[] num1;
	delete[] num2;

	return A;

}

BigInteger BigInteger::operator-(BigInteger & b){

	int* num1 = new int[this->length +1];
	int* num2 = new int[b.length +1];

	for(int i=1; i<=this->length; i++)
		num1[i] = this->digit[i];

	for(int i=1; i<=b.length; i++)
		num2[i] = b.digit[i];


	BigInteger B;  // B: �� ����Ƽ���� �y��
	int length;

	if(this->length > b.length)  // �ӽ� ���̸� ��������
		length = this->length +1;
	else
		length = b.length +1;

	for(int i=1; i<=length; i++){

		if(this->digit[i] < b.digit[i]){  // �ڸ��ø��� ���� ������ϴ°��
			this->digit[i] += 10;  // �ڸ��ø��� �ʿ��� ���� 10�� ������
			this->digit[i+1] += -1;  // ���� �ڸ��� ���� 1��ŭ ����
		}
		B.digit[i] = this->digit[i] - b.digit[i];  // ���� �� �ڸ��� ��
	}

	int x = length;

	while(true){
		if(B.digit[x] != 0){
			B.length = x;
			break;
		}
		x--;
	}


	for(int i=1; i<=this->length; i++)
		this->digit[i] = num1[i];

	for(int i=1; i<=b.length; i++)
		b.digit[i] = num2[i];

	delete[] num1;
	delete[] num2;

	return B;

}

BigInteger BigInteger::operator*(BigInteger & b){

	int* num1 = new int[this->length +1];
	int* num2 = new int[b.length +1];

	for(int i=1; i<=this->length; i++)
		num1[i] = this->digit[i];

	for(int i=1; i<=b.length; i++)
		num2[i] = b.digit[i];


	BigInteger C;  // C: �� ����Ƽ���� ����

	int length = this->length + b.length;  // �ӽ� ���̸� ��������

	for(int x=1; x<=b.length; x++)
		for(int y=1; y<=this->length; y++){

			int num = this->digit[y] * b.digit[x];  // ���� �� �ڸ��� ����

			if(num > 9){  // �ڸ��ø��� �߻����� ���
				C.digit[y+x-1+1] += num/10;  // ���� �ڸ��� ���� �ڸ��� ����
				num = num%10; // ���� �ڸ��� ����
			}
			C.digit[y+x-1] += num;  // ���� ���� �־���
		}
	
	for(int i=1; i<=length; i++){  // ��� ���� ��������

		if(C.digit[i] > 9){  // �迭 �� ĭ�� ���� �ڸ��� ������ ���
			C.digit[i+1] += C.digit[i] / 10;  // ���� �ڸ��� ���� �ڸ��� �Ѱ���
			C.digit[i] = C.digit[i] % 10;  // ���� �ڸ��� ���� ������
		}
	}

	int x = length;

	while(true){
		if(C.digit[x] != 0){
			C.length = x;
			break;
		}
		x--;
	}


	for(int i=1; i<=this->length; i++)
		this->digit[i] = num1[i];

	for(int i=1; i<=b.length; i++)
		b.digit[i] = num2[i];

	delete[] num1;
	delete[] num2;

	return C;

}

BigInteger& BigInteger::operator++(){

	if(this->digit[1] != 9){  // ���� �ڸ��� 9 �̸��� ���

		this->digit[1] = this->digit[1] + 1;  // ���� �ڸ��� +1�� �ϰ� ����
	}
	else{  // ���� �ڸ��� 10�� ���

		this->digit[2] += 1;  // ���� �ڸ��� +1�� ��
		this->digit[1] = 0;   // ���� �ڸ��� 0���� �ٲ�

		for(int i=2; i<=this->length; i++){  // ���� �ڸ� �̻���� 9�� �ʰ��ϴ��� Ȯ����

			if(this->digit[i] == 10){  // �ش� �ڸ��� 9�� �ʰ��� ���
				this->digit[i+1] += 1;  // ���� �ڸ��� +1�� ��
				this->digit[i] = 0;     // �ش� �ڸ��� 0���� �ٲ�
			}
			else break;
		}

		if(this->digit[this->length +1] == 1)  // ���ڿ� +1�� �����ν� �ڸ����� �þ����� Ȯ��
			this->length++;					   // �þ��� ��� ���̸� ����������
	}

	return *this;

}

BigInteger pow(BigInteger a, int b){

	BigInteger C;  // C: pow(c, 100)

	C.length = a.length;  // �켱 ���̸� �Է¹��� c�� ���̷� ����

	for(int i=1; i<=a.length; i++)
		C.digit[i] = a.digit[i];  // �׸��� �Է¹��� c�� ���� ��� �Ѱ���

	for(int i=2; i<=b; i++){  // pow(c, 100) ���� ����
		C = C * a;
	}

	int x = 9999;

	while(true){
		if(C.digit[x] != 0){
			C.length = x;
			break;
		}
		x--;
	}

	return C;

}

istream& operator>>(istream& is, BigInteger& a){

	string s;  // s: �� ��Ƽ���� �Է¹ޱ� ���� �ӽ� ����
	is >> s;

	a.length = s.length();  // ���̸� ��������

	string c;  // c: �� ��Ƽ������ ���� �� �ڸ��� ����

	for(int i=a.length; i>=1; i--){
		c = s.substr(i-1,1);
		int x = a.length - i + 1;

		if(c == "0") a.digit[x] = 0;
		else if(c == "1") a.digit[x] = 1;
		else if(c == "2") a.digit[x] = 2;
		else if(c == "3") a.digit[x] = 3;
		else if(c == "4") a.digit[x] = 4;
		else if(c == "5") a.digit[x] = 5;
		else if(c == "6") a.digit[x] = 6;
		else if(c == "7") a.digit[x] = 7;
		else if(c == "8") a.digit[x] = 8;
		else if(c == "9") a.digit[x] = 9;  // c�� ���� digit[]�� �� ����
	}

	return is;

}

ostream& operator<<(ostream& os, BigInteger& a){

	int x = a.length;  // x: ������ ���̸� ����

	for(int i=x; i>=1; i--)
		os << a.digit[i];  // ���� ���

	os << endl;

	return os;

}