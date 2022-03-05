#include "String.h"

size_t String::freeId = 0;

String::String()
	: _len(0), _id(++freeId), _allocator(new char[1]{'\0'})
{
#ifndef NDEBUG
	cout << "--String id" << _id << " created (empty-constructor)." << endl;
#endif // !NDEBUG

	return;
}

String::String(const char ch)
	: _len(1), _id(++freeId), _allocator(new char[2]{ch, '\0'})
{
#ifndef NDEBUG
	cout << "--String id" << _id << " created (char-constructor)." << endl;
#endif // !NDEBUG

	return;
}


String::String(const char* c)
	: _len(strlen(c)), _id(++freeId), _allocator(new char[_len + 1])
{
#ifndef NDEBUG
	cout << "--String id" << _id << " created (char*-constructor)." << endl;
#endif // !NDEBUG
	strcpy(_allocator, c);
	return;
}

String::String(const string& s)
	: _len(s.length()), _id(++freeId), _allocator(new char[_len + 1])
{
#ifndef NDEBUG
	cout << "--String id" << _id << " created (string-constructor)." << endl;
#endif // !NDEBUG
	strcpy(_allocator, s.c_str());
	return;
}

String::String(const String& s)
	: _len(s.length()), _id(++freeId), _allocator(new char[_len + 1])
{
#ifndef NDEBUG
	cout << "--String id" << _id << " copied." << endl;
#endif // !NDEBUG
	strcpy(_allocator, s.c_str());
	return;
}

String::String(String&& s) : _len(s._len), _allocator(s._allocator)
{
	s._len = 0;
	s._allocator = nullptr;

	return;
}

String::~String()
{
#ifndef NDEBUG
	cout << "--String id" << _id << " deleted." << endl;
#endif // !NDEBUG

	return;
}

ostream& operator<<(ostream& o, const String& s)
{
	for (size_t i = 0; i < s.length(); ++i)
	{
		o << s[i];
	}

	return o;
}