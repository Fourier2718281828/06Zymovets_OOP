#include <iostream>
#include "String.h"
using std::cout;
using std::endl;

int main(void)
{
	String s1("ab"), s2("231");
	static_cast<int>(2);
	cout << (s1 += s2) << endl;
	return 0;
}