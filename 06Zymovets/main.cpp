#include <iostream>
#include "String.h"
using std::cout;
using std::endl;

int main(void)
{
	/*String S1("ab"), S2("cd");
	string s("ef");
	const char* c = "ch";
	cout << "-----------------------------------------------" << endl;
	cout << (S1 += S2) << endl;
	cout << "-----------------------------------------------" << endl;
	cout << (S1 += s) << endl;
	cout << "-----------------------------------------------" << endl;
	cout << (S1 += c) << endl;
	cout << "-----------------------------------------------" << endl;
	cout << (s += S1) << endl;
	
	S1 + S2;*/

	char* c = new char[3]{'a', 'b', '\0'};
	String s(std::move(c));
	return 0;
}