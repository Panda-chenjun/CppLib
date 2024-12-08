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
	auto& operator<<(const char& x){fn("%c",x);return*this;}
	auto& operator<<(const float& x){fn("%f",x);return*this;}
	auto& operator<<(const double& x){fn("%lf",x);return*this;}
	auto& operator<<(const long long& x){fn("%lld",x);return*this;}
	auto& operator<<(const char* x){fn("%s",x);return*this;}
	OS& operator<<(const short& x){fn("%d",x);return*this;}
	OS& operator<<(std::string str){
		return *this<<str.data();
	}
	template<const unsigned long long N> 
	OS& operator<<(std::bitset<N> t){
		for(int i=0;i<N;i++)
			fn("%d",t[i]);
	}
}Cout;
END