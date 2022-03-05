#pragma once
#include<string>
#include<ostream>
using std::string;
using std::ostream;

class String
{
private:
	size_t _len;
	char* _allocator;
public:
	String();
	String(const char*);
	String(const string&);
	String(const String&);
	String(String&&);
	~String();
	operator string() const;
	operator const char* () const;
	String& operator=(const String&)&;
	String& operator=(String&&)&;
	String& operator=(const char*)&;
	String& operator=(const char)&;
	inline const char* c_str() const { return _allocator; }
	inline size_t length() const { return _len; }
	inline bool isEmpty() const { return _len == 0; }
	inline void clear() { *this = String(); }

	inline char& operator[](const size_t i) 
	{
		if (i < 0 || i >= length()) throw IndexOutOfBounds(i);
		return _allocator[i];
	}
	inline const char& operator[](const size_t) const;
	String& operator+=(const String&);
	String& operator+=(const char*);

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