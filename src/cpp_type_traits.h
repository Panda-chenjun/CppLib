// <typeinfo> -*- C++ -*-

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

#include<string>
#include<vector>
#include<set>
#include<map>

template<typename>
	bool constexpr __is_interger_v = false;
template<>
	bool constexpr __is_interger_v<short> = true;
template<>
	bool constexpr __is_interger_v<unsigned short> = true;
template<>
	bool constexpr __is_interger_v<int> = true;
template<>
	bool constexpr __is_interger_v<unsigned int> = true;
template<>
	bool constexpr __is_interger_v<long long> = true;
template<>
	bool constexpr __is_interger_v<unsigned long long> = true;
template<>
	bool constexpr __is_interger_v<__int128> = true;
template<>
	bool constexpr __is_interger_v<unsigned __int128> = true;

template<typename>
	bool constexpr __is_floating_v = false;
template<>
	bool constexpr __is_floating_v<float> = true;
template<>
	bool constexpr __is_floating_v<double> = true;
template<>
	bool constexpr __is_floating_v<long double> = true;

template<typename>
	bool constexpr __is_char_v = false;
template<>
	bool constexpr __is_char_v<char> = true;

template<typename>
	bool constexpr __is_bool_v = false;
template<>
	bool constexpr __is_bool_v<bool> = true;


template<typename>
	bool constexpr __is_string_v = false;
template<>
	bool constexpr __is_string_v<std::string> = true;
template<typename>
	bool constexpr __is_vector_v = false;
template<typename T>
	bool constexpr __is_vector_v<std::vector<T>> = true;
template<typename>
	bool constexpr __is_set_v = false;
template<typename T>
	bool constexpr __is_set_v<std::set<T>> = true;
template<typename>
	bool constexpr __is_map_v = false;
template<typename K, typename V>
	bool constexpr __is_map_v<std::map<K,V>> = true;