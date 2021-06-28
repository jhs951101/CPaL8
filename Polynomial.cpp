#include "Polynomial.h"

Polynomial::Polynomial(){

	for(int i=0; i<=9; i++)
		this->coef[i] = 0;  // 모든 coef를 0으로 초기화
}

Polynomial Polynomial::operator+(Polynomial& b){

	Polynomial C;  // 두 다항식의 덧셈을 수행

	if(this->degree > b.degree) C.degree = this->degree;
	else C.degree = b.degree;  // C의 degree를 설정
	
	for(int i=0; i<=C.degree; i++)
		C.coef[i] = this->coef[i] + b.coef[i];  // 덧셈을 수행

	return C;

}

Polynomial Polynomial::operator-(Polynomial& b){

	Polynomial C;  // 두 다항식의 뻴셈을 수행 

	if(this->degree > b.degree) C.degree = this->degree;
	else C.degree = b.degree;  // C의 degree를 설정
	
	for(int i=0; i<=C.degree; i++)
		C.coef[i] = this->coef[i] - b.coef[i];  // 뻴셈을 수행

	return C;

}

Polynomial Polynomial::operator*(Polynomial& b){

	Polynomial C;  // 두 다항식의 곱셈을 수행

	C.degree = this->degree + b.degree;  // C의 degree를 설정
	
	for(int x=0; x<=this->degree; x++)
		for(int y=0; y<=b.degree; y++)
			C.coef[x+y] += this->coef[x] * b.coef[y];  // 곱셈을 수행

	return C;

}

bool Polynomial::operator==(Polynomial& b){

	int max;  // max: degree의 최댓값
	if(this->degree > b.degree) max = this->degree;
	else max = b.degree;
	
	for(int i=0; i<=max; i++)
		if(this->coef[i] != b.coef[i]) return false;  // 같지 않은 요소가 하나라도 있으면 false

	return true;

}

istream& operator>>(istream& is, Polynomial& a){

	is >> a.degree;  // degree 입력받기

	for(int i=a.degree; i>=0; i--)
		is >> a.coef[i];  // coef 입력받기

	return is;

}

ostream& operator<<(ostream& os, Polynomial& a){

	bool allzero = true;  // allzero: 모든 상수의 값이 0이면 true

	for(int i=a.degree; i>=0; i--)  // 모든 상수의 값이 0인지 검사
		if(a.coef[i] != 0) allzero = false;

	if(allzero == true){  // 모든 상수의 값이 0일 경우 0만 출력하고 종료
		cout << "0" << endl;
		return os;
	}

	if(a.coef[a.degree] > 0) os << a.coef[a.degree] << "x^" << a.degree;		// 양수, 음수 구분하여 최고차항 출력
	else if(a.coef[a.degree] < 0) os << " - " << - a.coef[a.degree] << "x^" << a.degree;

	for(int i=a.degree-1; i>=1; i--){				// 양수, 음수 구분하여 방정식 출력(중간)
		if(a.coef[i] > 0) os << " + " << a.coef[i] << "x^" << i;
		else if(a.coef[i] < 0) os << " - " << - a.coef[i] << "x^" << i;
	}
	
	if(a.coef[0] > 0) os << " + " << a.coef[0] << endl;		 //  양수, 음수 구분하여 상수항 출력
	else if(a.coef[0] < 0) os << " - " << - a.coef[0] << endl;
	
	return os;

}