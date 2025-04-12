// <stdio.h> -*- C++ -*-

// Copyright (C) 2001-2023 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ extended-Library.  This library
// is free software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

#pragma GCC system_header

#ifndef EX_STDIO
#define EX_STDIO

#include <stdio.h>
#include <algorithm> // for std::reverse<>

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

/**
 * std-in `get` function.
 * Using example :`int res = get<int>();`
 * @note You will not use this template function
 * (but specialized) if you use a support_type.
 */

template <typename _Unsupport_type>
const _Unsupport_type get() = delete;

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

#include <libex/int128.h>

template <typename _Integer_type>
const char* __itoa(_Integer_type v)
{
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


template <typename _Head>
void __put_head_value(FILE* file,_Head head)
{

}

// To Do : _STDIO_DEFINE_PUTHEAD_FLOATING

template <typename _Head>
void __put_helper(FILE* file, _Head head) 
{
	__put_head_value(file, head);
}

template <typename _Head, typename ..._Tail>
void __put_helper(FILE* file, _Head head, _Tail... tails) 
{
	__put_head_value(file, head);
	__put_helper(file, tails...);
}


#endif // EX_STDIO