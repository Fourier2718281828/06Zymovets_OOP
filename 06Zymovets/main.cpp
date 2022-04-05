#include <iostream>
#include "String.h"
using std::cout;
using std::endl;

//***************************************************
//Визначити і реалізувати власний клас рядків String:
//конструктор за С-рядком, STL-рядком, копіювальні 
//і пересувні конструктор і присвоєння, суміщене 
//присвоєння, оператори [], +, ==,!=. Забезпечити 
//можливість виконання змішаних операцій над 
//власними рядками, С-рядками і STL-рядками.
//Developed by Ruslan Zymovets (IPZ, group 1)
//on March 15
//Version 1.0
//***************************************************

int main(void)
{	
	cout << "#1-----------------------------------------------------------" << endl;
	{
		cout << "Testing Constructors and Destructor:" << endl << endl;
		cout << "1). String():" << endl;
		String s1;
		cout << "created String :" << s1 << endl << endl;

		cout << "2). String(const char):" << endl;
		String s2 ('a');
		cout << "created String :" << s2 << endl << endl;

		cout << "3). String(const char*):" << endl;
		String s3("abcd");
		cout << "created String :" << s3 << endl << endl;

		cout << "4). String(const string&):" << endl;
		String s4(string("abcd"));
		cout << "created String :" << s4 << endl << endl;

		cout << "5). String(String&&):" << endl;
		String s5(std::move(s4));
		cout << "created String :" << s5 << endl << endl;

		cout << "6). String(char*&&):" << endl;
		cout << "(!Needed for operator+ implementation!)" << endl;
		String s6(new char[5]{'a', 'b', 'c', 'd', '\0'});
		cout << "created String :" << s6 << endl << endl;

		cout << "Destructors:" << endl;
	}
	cout << "#2-----------------------------------------------------------" << endl;
	{
		cout << "Testing Assignments:" << endl;
		String s1("ab"), s2("cd"), s3("ef"), s4("gh");
		cout << endl << "s1 :" << s1 << ", s2 :" << s2 << ", s3 :" << s3 << ", s4 :" << s4 << endl;
		cout << endl << "s1 = s2 :" << endl;
		s1 = s2;
		cout << endl << "s2 = String(\"move\") :" << endl;
		s2 = String("move");
		cout << endl << "s3 = new char[3]{ 'i', 'j', '\\0' } :" << endl;
		s3 = new char[3]{ 'i', 'j', '\0' };
		cout << "(!Needed for operator+ implementation!)" << endl;
		cout << endl << "s4 += s3 (one object created):" << endl;
		s4 += s3;
		cout << endl << "s3 += \"plus\":" << endl;
		s3 += "plus";
		cout << endl << "s1 :" << s1 << ", s2 :" << s2 << ", s3 :" << s3 << ", s4 :" << s4 << endl << endl;

	}
	cout << "#3-----------------------------------------------------------" << endl;
	{
		cout << "Testing String Methods:" << endl;
		String s1("example");
		cout << "s1 :" << s1 << endl;
		cout << endl;
		cout << "1). operator string() \t:" << static_cast<string>(s1) << endl;
		cout << "2). s1.c_str() \t\t:" << s1.c_str() << endl;
		cout << "4). s1.length()\t\t:" << s1.length() << endl;
		cout << "5). s1.isEmpty()\t:" << std::boolalpha << s1.isEmpty() << endl;
		cout << "6). s1.clear(); s1 :" << endl;
		s1.clear();
		cout << "7). s1.isEmpty()\t:" << s1.isEmpty() << endl;

	}
	cout << "#4-----------------------------------------------------------" << endl;
	{
		cout << "Testing utilities:" << endl;
		String s1("ab"), s2(s1), s3("cd");
		cout << "s1 :" << s1 << ", s2 :" << s2 << ", s3 :" << s3 << endl;
		cout << "s1 == s2 = " << (s1 == s2) << endl;
		cout << "s1 == s3 = " << (s1 == s3) << endl;
		cout << "s1 != s2 = " << (s1 != s2) << endl;
		cout << "s1 != s3 = " << (s1 != s3) << endl;
		cout << "s1 == \"abcd\" = " << (s1 == "abcd") << endl;
		cout << "\"ab\" == s1 = " << ("ab" == s1) << endl << endl;

		cout << "Concatenation:" << endl;
		cout << endl << "ONLY ONE OBJECT CREATED! :" << endl;
		cout << "s1 + s3 = " << (s1 + s3) << endl;
		cout << endl << "Mixed types:" << endl;
		cout << "s1 + \"plus\" = " << (s1 + "plus") << endl;
		cout << "\"plus\" + s1 = " << ("plus" + s1) << endl;

	}

	return 0;
}