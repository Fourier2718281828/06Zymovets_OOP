#include <iostream>
#include "String.h"
using std::cout;
using std::endl;

int main(void)
{
	String s1, s2("tete"), s3(string("dsads"));
	String s4(s2);
	String s5('3');
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s5 = " << s5 << endl;
	char c = '2';
	return 0;
}