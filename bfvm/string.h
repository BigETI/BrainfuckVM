#pragma once

#include <string>

class CSTRING;
class STRING;
class CSTRING : public std::string
{
public:
	CSTRING();
	CSTRING(const char *cs);
	CSTRING(const wchar_t *wcs);
	CSTRING(const CSTRING &c_str);
	CSTRING(const STRING &_str);
	CSTRING(const char c);
	CSTRING(const wchar_t wc);
	CSTRING(const int value);
	CSTRING(const double value);
	CSTRING &operator=(const char *cs);
	CSTRING &operator=(const CSTRING &c_str);
	CSTRING &operator=(const char c);
	CSTRING &operator=(const wchar_t wc);
	CSTRING &operator=(const int value);
	CSTRING &operator=(double value);
	CSTRING &operator+=(const char *cs);
	CSTRING &operator+=(const CSTRING &c_str);
	CSTRING &operator+=(const char c);
	CSTRING &operator+=(const wchar_t wc);
	CSTRING &operator+=(const int value);
	CSTRING &operator+=(const double value);
	CSTRING operator+(const char *cs);
	STRING operator+(const wchar_t *wcs);
	CSTRING operator+(const CSTRING &c_str);
	STRING operator+(const STRING &_str);
	CSTRING operator+(const char c);
	STRING operator+(const wchar_t wc);
	CSTRING operator+(const int value);
	CSTRING operator+(const double value);
	CSTRING substr(unsigned int pos, unsigned int len);
};
class STRING : public std::wstring
{
public:
	STRING();
	STRING(const wchar_t *wcs);
	STRING(const char *cs);
	STRING(const STRING &_str);
	STRING(const CSTRING &c_str);
	STRING(const char c);
	STRING(const wchar_t wc);
	STRING(const int value);
	STRING(const double value);
	STRING & operator=(const wchar_t *wcs);
	STRING & operator=(const char *cs);
	STRING & operator=(const CSTRING &c_str);
	STRING & operator=(const STRING &_str);
	STRING & operator=(const wchar_t wc);
	STRING & operator=(const char c);
	STRING & operator=(const int value);
	STRING & operator=(const double value);
	STRING & operator+=(const wchar_t *wcs);
	STRING & operator+=(const char *cs);
	STRING & operator+=(const STRING &_str);
	STRING & operator+=(const CSTRING &c_str);
	STRING & operator+=(const wchar_t wc);
	STRING & operator+=(const char c);
	STRING & operator+=(const int value);
	STRING & operator+=(const double value);
	STRING operator+(const wchar_t *wcs);
	STRING operator+(const char *cs);
	STRING operator+(const STRING &_str);
	STRING operator+(const CSTRING &c_str);
	STRING operator+(const wchar_t wc);
	STRING operator+(const char c);
	STRING operator+(const int value);
	STRING operator+(const double value);
	STRING substr(unsigned int pos, unsigned int len);
};