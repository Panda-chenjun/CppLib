/**
 * @file stdio_impl.cc
 * DO NOT include this file directly.
 * This file is for static lib `libstdio`.
 */

#include <libex/stdio.h>

/**
 * A helper to ignore spaces.
 */
const char __get_first_char()
{
	char res = getchar();
	while (res == ' ' || res == '\t' || res == '\n')
		res = getchar();
	return res;
}

#define _STDIO_DEFINE_GET_INTEGER(type) \
template <> \
const type get<type>() \
{ \
	char ch = __get_first_char(); \
	bool neg = false; \
	if (ch == '-' || ch == '+') \
		neg = (ch == '-'), ch = getchar(); \
	type res = 0; \
	while ('0' <= ch && ch <= '9') \
		res = res * 10 + ch - '0', \
		ch = getchar(); \
	return neg ? -res : res; \
}

_STDIO_DEFINE_GET_INTEGER (__int16)
_STDIO_DEFINE_GET_INTEGER (__int32)
_STDIO_DEFINE_GET_INTEGER (__int64)
_STDIO_DEFINE_GET_INTEGER (__int128)
_STDIO_DEFINE_GET_INTEGER (unsigned __int16)
_STDIO_DEFINE_GET_INTEGER (unsigned __int32)
_STDIO_DEFINE_GET_INTEGER (unsigned __int64)
_STDIO_DEFINE_GET_INTEGER (unsigned __int128)

#define _STDIO_DEFINE_GET_FLOATING(type) \
template <> \
const type get<type>() \
{ \
	char ch = __get_first_char(); \
	bool neg = false; \
	if(ch == '-' || ch == '+') \
		neg = (ch == '-'), ch = getchar(); \
	type res = 0; \
	while ('0' <= ch && ch <= '9') \
		res = res * 10 + ch - '0', \
		ch = getchar(); \
	if(ch == '.'){ \
		type power = 0.1; \
		ch = getchar(); \
		while ('0' <= ch && ch <= '9') \
			res = res + power * (ch - '0'), \
			ch = getchar(), power = power * 0.1; \
	} \
	return neg ? -res : res; \
}

_STDIO_DEFINE_GET_FLOATING (float)
_STDIO_DEFINE_GET_FLOATING (double)
_STDIO_DEFINE_GET_FLOATING (long double)
_STDIO_DEFINE_GET_FLOATING (__float128)

template <>
const char get<char>()
{
	return __get_first_char();
}

template <>
const bool get<bool>()
{
	return __get_first_char()-'0';
}

#include <libex/int128.h> // for int128 support
#include <type_traits> // for int128 support

template <typename _Integer_type>
const char* __itoa(_Integer_type v)
{
	static_assert(std::__is_integer<_Integer_type>::__value,
		"v must be a interger");
	char* buffer = new char[50]{};
	char* ptr = buffer;
	bool neg = v < 0;
	if(v < 0)
		v = -v, *ptr = '-', ++ ptr;
	while(v)
	{
		*ptr = '0' + (v % 10);
		v = v / 10;
		++ ptr;
	}
	std::reverse(buffer + neg, ptr);
	return buffer;
}

