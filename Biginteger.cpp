#include "BigInteger.h"
#include <string>

BigInteger::BigInteger(int n){

	for(int i=0; i<10000; i++)
		this->digit[i] = 0;  // 모든 digit를 0으로 지정

	int i = 1;
	while(n > 0){

		int pn = n%10;
		this->digit[i] = pn;  // 모든 digit를 0으로 지정

		n = n/10;
		i++;
	}

	this->length = i-1;  // length 지정

}

BigInteger BigInteger::operator+(BigInteger & b){

	int* num1 = new int[this->length +1];   // num1: this->digit[i] 의 숫자들을 저장하는 배열
	int* num2 = new int[b.length +1];		// num2: b.digit[i] 의 숫자들을 저장하는 배열

	for(int i=1; i<=this->length; i++)
		num1[i] = this->digit[i];   // num1: this->digit[i] 의 숫자들을 저장

	for(int i=1; i<=b.length; i++)
		num2[i] = b.digit[i];		// num2: b.digit[i] 의 숫자들을 저장
									// * 두 개의 빅 인터가 손상되는 것을 막기 위해 우선 숫자를 저장해놓고 연산이 끝나면 다시 넘겨줌
	

	BigInteger A;  // A: 두 빅인티저의 덧셈
	int length;  // length: 빅인티저 덧셈의 임시 길이

	if(this->length > b.length)  // 임시 길이를 설정해줌
		length = this->length +1;
	else
		length = b.length +1;

	for(int i=1; i<=length; i++){

		int num = this->digit[i] + b.digit[i];  // 서로 한 자리를 더함

		if(num > 9){  // 자리올림이 필요한 경우
			num = num%10;  // 십의 자리를 제외해줌
			A.digit[i+1] = 1;  // 십의 자리를 다음 자리에 누적
		}
		A.digit[i] += num;  // 더한 값을 넣어줌
	}

	int x = length; // 임시 길이를 저장

	while(true){			// ex) 0521 → 521
		if(A.digit[x] != 0){  	  // x--를 통해 빅인티저의 길이를 설정
			A.length = x;
			break;
		}
		x--;
	}


	for(int i=1; i<=this->length; i++)
		this->digit[i] = num1[i]; // 저장했던 숫자를 다시 넘겨줌(1)

	for(int i=1; i<=b.length; i++)
		b.digit[i] = num2[i];	  // 저장했던 숫자를 다시 넘겨줌(1)

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


	BigInteger B;  // B: 두 빅인티저의 뻴셈
	int length;

	if(this->length > b.length)  // 임시 길이를 설정해줌
		length = this->length +1;
	else
		length = b.length +1;

	for(int i=1; i<=length; i++){

		if(this->digit[i] < b.digit[i]){  // 자리올림을 전에 해줘야하는경우
			this->digit[i] += 10;  // 자리올림이 필요한 곳에 10을 더해줌
			this->digit[i+1] += -1;  // 다음 자리의 값을 1만큼 빼줌
		}
		B.digit[i] = this->digit[i] - b.digit[i];  // 서로 한 자리를 뺌
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


	BigInteger C;  // C: 두 빅인티저의 곱셈

	int length = this->length + b.length;  // 임시 길이를 설정해줌

	for(int x=1; x<=b.length; x++)
		for(int y=1; y<=this->length; y++){

			int num = this->digit[y] * b.digit[x];  // 서로 한 자리를 곱함

			if(num > 9){  // 자리올림이 발생했을 경우
				C.digit[y+x-1+1] += num/10;  // 십의 자리를 다음 자리에 누적
				num = num%10; // 일의 자리만 남김
			}
			C.digit[y+x-1] += num;  // 곱한 값을 넣어줌
		}
	
	for(int i=1; i<=length; i++){  // 결과 값을 정리해줌

		if(C.digit[i] > 9){  // 배열 한 칸에 십의 자리가 존재할 경우
			C.digit[i+1] += C.digit[i] / 10;  // 십의 자리를 다음 자리로 넘겨줌
			C.digit[i] = C.digit[i] % 10;  // 일의 자리로 값을 덮어줌
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

	if(this->digit[1] != 9){  // 일의 자리가 9 미만일 경우

		this->digit[1] = this->digit[1] + 1;  // 일의 자리에 +1만 하고 끝냄
	}
	else{  // 일의 자리가 10일 경우

		this->digit[2] += 1;  // 십의 자리에 +1을 함
		this->digit[1] = 0;   // 일의 자리를 0으로 바꿈

		for(int i=2; i<=this->length; i++){  // 십의 자리 이상부터 9를 초과하는지 확인함

			if(this->digit[i] == 10){  // 해당 자리가 9를 초과할 경우
				this->digit[i+1] += 1;  // 다음 자리에 +1을 함
				this->digit[i] = 0;     // 해당 자리를 0으로 바꿈
			}
			else break;
		}

		if(this->digit[this->length +1] == 1)  // 숫자에 +1을 함으로써 자릿수가 늘었는지 확인
			this->length++;					   // 늘었을 경우 길이를 재정의해줌
	}

	return *this;

}

BigInteger pow(BigInteger a, int b){

	BigInteger C;  // C: pow(c, 100)

	C.length = a.length;  // 우선 길이를 입력받은 c의 길이로 설정

	for(int i=1; i<=a.length; i++)
		C.digit[i] = a.digit[i];  // 그리고 입력받은 c의 값을 모두 넘겨줌

	for(int i=2; i<=b; i++){  // pow(c, 100) 연산 수행
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

	string s;  // s: 빅 인티저를 입력받기 위한 임시 변수
	is >> s;

	a.length = s.length();  // 길이를 저장해줌

	string c;  // c: 빅 인티저에서 숫자 한 자리를 저장

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
		else if(c == "9") a.digit[x] = 9;  // c를 통해 digit[]에 값 저장
	}

	return is;

}

ostream& operator<<(ostream& os, BigInteger& a){

	int x = a.length;  // x: 숫자의 길이를 저장

	for(int i=x; i>=1; i--)
		os << a.digit[i];  // 숫자 출력

	os << endl;

	return os;

}