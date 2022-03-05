#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<string>
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
	char* _allocator;
	static size_t freeId;
public:
	String();
	String(const char);
	String(const char*);
	String(const string&);
	String(const String&);
	String(String&&);
	~String();

	inline operator string() const { return string(_allocator); }
	inline const char* c_str() const { return _allocator; }
	inline size_t length() const { return _len; }
	inline bool isEmpty() const { return _len == 0; }
	inline void clear() { *this = String(); }

	inline String& operator=(const String& s)&
	{
		if (this == &s)
		{
			return *this;
		}

		delete _allocator;
		_len = s._len;
		_allocator = new char[s._len + 1];
		strcpy(_allocator, s._allocator);

		return *this;
	}

	inline String& operator=(const char* s)&
	{
		delete _allocator;
		_len = strlen(s);
		_allocator = new char[_len + 1];
		strcpy(_allocator, s);

		return *this;
	}

	inline String& operator=(const char)&
	{

	}

	inline String& operator=(String&&)&
	{

	}

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

	inline String& operator+=(const String&);
	inline String& operator+=(const char*);

	class IndexOutOfBounds
	{
	private:
		size_t _index;
	public:
		IndexOutOfBounds(const size_t index) : _index(index) { return; }
		~IndexOutOfBounds() { return; }
	};
};

bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);
String operator+(const String&, const String&);
ostream& operator<<(ostream&, const String&);