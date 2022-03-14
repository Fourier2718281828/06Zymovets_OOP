#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using std::string;
using std::ostream;
using std::cout;
using std::endl;

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
	String& operator=  (const char*)	 &;
	String& operator=  (const char)		 &;		
	String& operator=  (String&&)		 &;
	String& operator=  (char*&&)		 &;
	String& operator+= (const String& s) &;
	String& operator+= (const char* s)	 &;
	String& operator+= (const string& s) &;

	inline operator		string ()		const { return string(_allocator); }
	inline const char*	c_str  ()		const { return _allocator		 ; }
	inline size_t		length ()		const { return _len				 ; }
	inline bool			isEmpty()		const { return _len == 0		 ; }
	inline void			clear  ()			  { *this = String()		 ; }

	inline char& operator[](const size_t i)
	{
		if (i < 0 || i >= length()) throw IndexOutOfBounds(i);
		return _allocator[i];
	}

	inline char operator[](const size_t i) const
	{
		if (i < 0 || i >= length()) throw IndexOutOfBounds(i);
		return _allocator[i];
	}

	class IndexOutOfBounds
	{
	private:
		const size_t _index;
	public:
		IndexOutOfBounds(const size_t index) : _index(index) { return; }
		~IndexOutOfBounds()								     { return; }
	};
};

bool operator==		(const String&, const String&);
bool operator!=		(const String&, const String&);
String operator+	(const String&, const String&);
ostream& operator<< (	  ostream&, const String&);