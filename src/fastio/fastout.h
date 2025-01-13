#include"putfunc.h"
class FastOs{
	public:
	auto&operator<<(const __int16 x){return putint(x),*this;}
	auto&operator<<(const __int32 x){return putint(x),*this;}
	auto&operator<<(const __int64 x){return putint(x),*this;}
	auto&operator<<(const __int128 x){return putint128(x),*this;}
	auto&operator<<(const char x){return putchar(x),*this;}
	auto&operator<<(const std::string x){return putstr(x),*this;}
	auto&operator<<(const char* x){return putstr(x),*this;}
	auto&operator<<(FastOs& (*x)(FastOs&)){return x(*this);}
};
FastOs fastout;
FastOs& endl(FastOs& Os){
	return Os<<"\n";
}
