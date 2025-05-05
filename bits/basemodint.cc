// <libex/bits/basemodint.cc> -*- C++ -*-

// Copyright (C) 2001-2023 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
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

/**
 * @file basemodint.cc
 * Don't use thie file directly.
*/


template <unsigned long long P>  
struct _Modint_base {
	typedef unsigned long long	value_t;
	value_t value;
	_Modint_base()
	:value(0) { }
	_Modint_base(value_t nvalue)
	:value(nvalue) { }
#define _Modint_base_operator_defines(op,returns) \
	_Modint_base operator op (_Modint_base __rhs) \
		{return returns;}
};