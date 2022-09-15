#include <iostream>
#include "Date.h"
using namespace std;
int main() {
	Date date1(29, 2, 2020);
	Date date2(29, 2, 2016);
	date1.PrintDate();
	date1 - 87;
	date1--;
	date1.PrintDate();
	cout<<date1.GetYear();
	bool C=date1 != date2;
	cout <<endl<< C;
}