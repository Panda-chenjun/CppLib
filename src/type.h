template<typename>
	bool constexpr __is_interger_v = false;
template<typename>
	bool constexpr __is_int128_v = false;
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
	bool constexpr __is_int128_v<__int128> = true;
template<>
	bool constexpr __is_int128_v<unsigned __int128> = true;