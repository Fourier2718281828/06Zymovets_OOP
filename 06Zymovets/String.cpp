#include "String.h"

String::String()
	: _len(0), _allocator(new char[1]{'\0'})
{
#ifndef NDEBUG
	cout <<
#endif // !NDEBUG

	return;
}

String::String(const char*)
{
	return;
}

String::String(const string& s)
{
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
	return;
}

ostream& operator<<(ostream& o, const String& s)
{
	for (size_t i = 0; i < s.length(); ++i)
	{
		
	}

	return o;
}