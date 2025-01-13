#include<string>
using __int128_t=__int128;
void putint128(__int128_t x){
	if(x<0){
		putchar('-'),putint128(-x);
		return;
	}
	if(x>9)
		putint128(x/10);
	putchar(x%10+'0');
}
inline void putint(const long long &x){
	if(x<0){
		putchar('-'),putint(-x);
		return;
	}
	if(x>9)
		putint(x/10);
	putchar(x%10+'0');
}
inline void putstr(const std::string &x){
	for(auto &ch : x)
		putchar(ch);
}
inline void putstr(const char* x){
	for(auto it=x;*it!='\0';it++)
		putchar(*it);
}