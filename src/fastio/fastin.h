#include"getfunc.h"
class FastIS{
	public:
	auto&operator>>(__int16&x){return x=getint(),*this;}
	auto&operator>>(__int32&x){return x=getint(),*this;}
	auto&operator>>(__int64&x){return x=getint(),*this;}
	auto&operator>>(__int128&x){return x=getint128(),*this;}
	auto&operator>>(char &x){return x=getchar(),*this;}
	auto&operator>>(std::string &x){return x=getstr(),*this;}
};
FastIS fastin;
