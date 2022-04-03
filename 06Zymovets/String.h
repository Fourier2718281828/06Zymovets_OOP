#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using std::string;
using std::ostream;
using std::cout;
using std::endl;
using std::cerr;

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

class String
{
private:
	size_t _len;
	size_t _id;
	char*  _allocator;
	static size_t freeId;
public:
	String ()			  ;
	String (const char)   ;
	String (const char*)  ;
	String (const string&);
	String (const String&);
	String (String&&)     ;
	String (char*&&)      ;
	~String()             ;

	String& operator=  (const String&)	 &;	
	String& operator=  (String&&)		 &;
	String& operator=  (char*&&)		 &;
	String& operator+= (const String& s) &;

	inline operator		string ()		const { return string(_allocator); }
	inline const char*	c_str  ()		const { return _allocator		 ; }
	inline size_t		length ()		const { return _len				 ; }
	inline bool			isEmpty()		const { return _len == 0		 ; }
	inline void			clear  ()			  { *this = String()		 ; }
	inline char& operator[](const size_t);
	inline char	 operator[](const size_t) const;

	class IndexOutOfBounds;
};

class String::IndexOutOfBounds
{
private:
	const size_t _index;
public:
	IndexOutOfBounds(const size_t index) : _index(index) { return; }
	~IndexOutOfBounds()								     { return; }
	inline void diagnosis()
	{
		cerr << "Index out of acceptable bounds:" << _index << endl;
	}
};

inline char& String::operator[](const size_t i)
{
	if (i < 0 || i >= length()) throw IndexOutOfBounds(i);
	return _allocator[i];
}

inline char String::operator[](const size_t i) const
{
	if (i < 0 || i >= length()) throw IndexOutOfBounds(i);
	return _allocator[i];
}

bool operator==		(const String&, const String&);
bool operator!=		(const String&, const String&);
String operator+	(const String&, const String&);
ostream& operator<< (ostream&, const String&);