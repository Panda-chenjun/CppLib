#define OS_H
#define BEGIN namespace std{
#define END }
#include<stdio.h>
#include<string>
#include<bitset>
#define f(type,c) auto& operator<<(const type& x){fn(c,x);return*this;}

BEGIN

class OS{
	private:
	int (*fn)(const char*,...) = printf;
	public:
	auto& operator<<(const int& x){fn("%d",x);return*this;}
	auto& operator<<(const int&& x){fn("%d",x);return*this;}
	auto& operator<<(const char& x){fn("%c",x);return*this;}
	auto& operator<<(const char&& x){fn("%c",x);return*this;}
	auto& operator<<(const float& x){fn("%f",x);return*this;}
	auto& operator<<(const float&& x){fn("%f",x);return*this;}
	auto& operator<<(const double& x){fn("%lf",x);return*this;}
	auto& operator<<(const double&& x){fn("%lf",x);return*this;}
	auto& operator<<(const long long& x){fn("%lld",x);return*this;}
	auto& operator<<(const long long&& x){fn("%lld",x);return*this;}
	auto& operator<<(const char* x){fn("%s",x);return*this;}
	OS& operator<<(const short& x){fn("%d",x);return*this;}
	OS& operator<<(const short&& x){fn("%d",x);return*this;}
	OS& operator<<(const std::string& str){
		return *this<<str.data();
	}
	OS& operator<<(const std::string&& str){
		return *this<<str.data();
	}
	template<const unsigned long long N> 
	OS& operator<<(const std::bitset<N>& t){
		for(int i=N-1;i>=0;i--)
			fn("%d",t[i]);
		return *this;
	}
	OS& operator<<(const __int128& x){
		if(x>=10)
			*this<<(x/10);
		return *this<<int(x%10);
	}
}Cout;

END