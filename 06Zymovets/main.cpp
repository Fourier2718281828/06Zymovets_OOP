#include <iostream>
#include "String.h"
using std::cout;
using std::endl;

int main(void)
{
	String s1("ab"), s2("cd");
	cout << "s1 + s2 = " << (s1 + "") << endl;

	return 0;
}