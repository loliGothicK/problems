#include <iostream>
#include <cmath>
using namespace std;
const double pi=3.1415926535;
int main(){
	double a,b,d;
	cin >> a >> b >> d;
	cout.precision(12);
	cout << a*b*sin(d/180.0*pi)/2 << endl;
}