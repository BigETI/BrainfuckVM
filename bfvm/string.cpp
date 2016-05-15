#include "string.h"

CSTRING::CSTRING()
{

}

CSTRING::CSTRING(const char *cs)
{
	assign(cs);
	//str = cs;
}

CSTRING::CSTRING(const wchar_t *wcs)
{
	for (wchar_t *wc = (wchar_t *)wcs; (*wc) != L'\0'; wc++) push_back((char)(*wc));
}

CSTRING::CSTRING(const CSTRING &_c_str)
{
	assign(_c_str);
}

CSTRING::CSTRING(const STRING &_str)
{
	for (wchar_t *wc = (wchar_t *)(_str.c_str()); (*wc) != L'\0'; wc++) push_back((char)(*wc));
	//for (wchar_t *wc = (wchar_t *)(((STRING)_str).c_str()); (*wc) != L'\0'; wc++) push_back((char)(*wc));
}

CSTRING::CSTRING(const char c)
{
	push_back(c);
}

CSTRING::CSTRING(const wchar_t wc)
{
	push_back((char)wc);
}

CSTRING::CSTRING(const int value)
{
	assign(std::to_string(value));
}

CSTRING::CSTRING(const double value)
{
	assign(std::to_string(value));
}

CSTRING &CSTRING::operator=(const char *cs)
{
	assign(cs);
	return *this;
}

CSTRING &CSTRING::operator=(const CSTRING &_c_str)
{
	assign(_c_str);
	return *this;
}

CSTRING &CSTRING::operator=(const char c)
{
	clear();
	push_back(c);
	return *this;
}

CSTRING &CSTRING::operator=(const wchar_t wc)
{
	clear();
	push_back((char)wc);
	return *this;
}

CSTRING &CSTRING::operator=(const int value)
{
	assign(std::to_string(value));
	return *this;
}

CSTRING &CSTRING::operator=(const double value)
{
	assign(std::to_string(value));
	return *this;
}

CSTRING & CSTRING::operator+=(const char *cs)
{
	append(cs);
	return *this;
}

CSTRING & CSTRING::operator+=(const CSTRING &_c_str)
{
	append(_c_str);
	return *this;
}

CSTRING & CSTRING::operator+=(const char c)
{
	push_back(c);
	return *this;
}

CSTRING & CSTRING::operator+=(const wchar_t wc)
{
	push_back((char)wc);
	return *this;
}

CSTRING &CSTRING::operator+=(const int value)
{
	append(std::to_string(value));
	return *this;
}

CSTRING &CSTRING::operator+=(const double value)
{
	append(std::to_string(value));
	return *this;
}

CSTRING CSTRING::operator+(const char *cs)
{
	CSTRING ret(*this);
	return (ret += cs);
}

STRING CSTRING::operator+(const wchar_t *wcs)
{
	STRING ret(*this);
	return (ret += wcs);
}

CSTRING CSTRING::operator+(const CSTRING &_c_str)
{
	CSTRING ret(*this);
	return (ret += _c_str);
}

STRING CSTRING::operator+(const STRING &_str)
{
	STRING ret(*this);
	return (ret += ((STRING)_str));
}

CSTRING CSTRING::operator+(const char c)
{
	CSTRING ret(*this);
	return (ret += c);
}

STRING CSTRING::operator+(const wchar_t wc)
{
	STRING ret(*this);
	return (ret += wc);
}

CSTRING CSTRING::operator+(const int value)
{
	CSTRING ret(*this);
	return (ret += value);
}

CSTRING CSTRING::operator+(const double value)
{
	CSTRING ret(*this);
	return (ret += value);
}

CSTRING CSTRING::substr(unsigned int pos, unsigned int len)
{
	CSTRING ret;
	size_t str_len = length();
	char *buf = NULL, *c;
	if ((len + pos) >= str_len)
	{
		if (pos >= str_len) len = 0;
		else len = (str_len - pos);
	}
	if (len)
	{
		buf = new char[len + 1];
		c = (char *)(c_str());
		for (unsigned i = 0; i != pos; i++) c++;
		memcpy(buf, c, len*sizeof(char));
		buf[len] = '\0';
		ret = buf;
		delete[] buf;
	}
	return ret;
}

STRING::STRING()
{

}

STRING::STRING(const wchar_t *wcs)
{
	assign(wcs);
}

STRING::STRING(const char *cs)
{
	for (char *c = (char *)cs; (*c) != L'\0'; c++) push_back(((wchar_t)(*c)) & 0xFF);
}

STRING::STRING(const STRING &_str)
{
	assign(_str);
}

STRING::STRING(const CSTRING &c_str)
{
	for (char *c = (char *)(c_str.c_str()); (*c) != '\0'; c++) push_back((wchar_t)(*c));
	//for (char *c = (char *)(((CSTRING)c_str).c_str()); (*c) != L'\0'; c++) push_back((wchar_t)(*c));
}

STRING::STRING(const char c)
{
	push_back((wchar_t)c);
}

STRING::STRING(const wchar_t wc)
{
	push_back(wc);
}

STRING::STRING(const int value)
{
	assign(std::to_wstring(value));
}

STRING::STRING(const double value)
{
	assign(std::to_wstring(value));
}

STRING &STRING::operator=(const char *cs)
{
	assign(L"");
	for (char *c = (char *)cs; (*c) != '\0'; c++) push_back((wchar_t)(*c));
	return *this;
}

STRING &STRING::operator=(const wchar_t *wcs)
{
	assign(wcs);
	return *this;
}

STRING &STRING::operator=(const STRING &_str)
{
	assign(_str);
	return *this;
}

STRING &STRING::operator=(const CSTRING &c_str)
{
	assign(L"");
	for (char *c = (char *)(c_str.c_str()); (*c) != '\0'; c++) push_back((wchar_t)(*c));
	return *this;
}

STRING &STRING::operator=(const wchar_t wc)
{
	clear();
	push_back(wc);
	return *this;
}

STRING &STRING::operator=(const char c)
{
	clear();
	push_back((wchar_t)c);
	return *this;
}

STRING &STRING::operator=(const int value)
{
	assign(std::to_wstring(value));
	return *this;
}

STRING &STRING::operator=(const double value)
{
	assign(std::to_wstring(value));
	return *this;
}

STRING &STRING::operator+=(const wchar_t *wcs)
{
	append(wcs);
	return *this;
}

STRING &STRING::operator+=(const char *cs)
{
	for (char *c = (char *)cs; (*c) != '\0'; c++) push_back((wchar_t)(*c));
	return *this;
}

STRING &STRING::operator+=(const STRING &_str)
{
	append(_str);
	return *this;
}

STRING &STRING::operator+=(const CSTRING &c_str)
{
	for (char *c = (char *)(c_str.c_str()); (*c) != '\0'; c++) push_back((wchar_t)(*c));
	return *this;
}

STRING &STRING::operator+=(const wchar_t wc)
{
	push_back(wc);
	return *this;
}

STRING &STRING::operator+=(const char c)
{
	push_back((wchar_t)c);
	return *this;
}

STRING &STRING::operator+=(const int value)
{
	append(std::to_wstring(value));
	return *this;
}

STRING &STRING::operator+=(const double value)
{
	append(std::to_wstring(value));
	return *this;
}

STRING STRING::operator+(const wchar_t *wcs)
{
	STRING ret(*this);
	return (ret += wcs);
}

STRING STRING::operator+(const char *cs)
{
	STRING ret(*this);
	return (ret += cs);
}

STRING STRING::operator+(const STRING &_str)
{
	STRING ret(*this);
	return (ret += _str);
}

STRING STRING::operator+(const CSTRING &c_str)
{
	STRING ret(*this);
	return (ret += c_str);
}

STRING STRING::operator+(const wchar_t wc)
{
	STRING ret(*this);
	return (ret += wc);
}

STRING STRING::operator+(const char c)
{
	STRING ret(*this);
	return (ret += c);
}

STRING STRING::operator+(const int value)
{
	STRING ret(*this);
	return (ret += value);
}

STRING STRING::operator+(const double value)
{
	STRING ret(*this);
	return (ret += value);
}

STRING STRING::substr(unsigned int pos, unsigned int len)
{
	STRING ret;
	size_t str_len = length();
	wchar_t *buf = NULL, *c;
	if ((len + pos) >= str_len)
	{
		if (pos >= str_len) len = 0;
		else len = (str_len - pos);
	}
	if (len)
	{
		buf = new wchar_t[len + 1];
		c = (wchar_t *)(c_str());
		for (unsigned i = 0; i != pos; i++) c++;
		memcpy(buf, c, len*sizeof(wchar_t));
		buf[len] = '\0';
		ret = buf;
		delete[] buf;
	}
	return ret;
}