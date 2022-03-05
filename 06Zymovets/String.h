#pragma once
#include<string>
using std::string;

class String
{
private:
	size_t _len;
	char* _allocator;
public:
	String();
	explicit String(const char*);
	String(const char); 
	explicit String(const string&);
	String(const String& s, const int multiplayer = 1);
	~String();
	operator string() const;
	operator char* () const;
	const char* c_str() const { return _allocator; }
	size_t length() const { return _len; }
	bool empty() const { return _len == 0; }
	void clear() { *this = String(); }
	char& operator[](const size_t);
	const char& operator[](const size_t) const;
	bool operator==(const String&) const;
	bool operator!=(const String&) const;
	String& operator=(const String&);
	String& operator=(const char*);
	String& operator=(const char);
	String operator+(const String&) const;
	String& operator+=(const String&);
	String& operator+=(const char*);
};