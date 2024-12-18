#define _FASTIN_H
#define BEGIN namespace std{
#define END }
#include<stdio.h>
#include<string>
#include<bitset>

BEGIN

class IS{
	private:
	int (*fn)(const char*,...) = scanf;
	public:
	auto& operator>>(int& x){fn("%d",&x);return*this;}
	auto& operator>>(char& x){fn("%c",&x);return*this;}
	auto& operator>>(float& x){fn("%f",&x);return*this;}
	auto& operator>>(double& x){fn("%lf",&x);return*this;}
	auto& operator>>(long long& x){fn("%lld",&x);return*this;}
	auto& operator>>(char* x){fn("%s",x);return*this;}
	IS& operator>>(short& x){fn("%d",&x);return*this;}
	IS& operator>>(short&& x){fn("%d",&x);return*this;}
	IS& operator>>(__int128& x){
		x=0;
		char ch='\0';
		while(1){
			scanf("%c",&ch);
			if(ch=='\t'||ch==' '||ch=='\n')
				break;
			x=x*10+ch-'0';
		}
	}
	IS& operator>>(string& x){
		x.clear();
		char ch='\0';
		while(1){
			scanf("%c",&ch);
			if(ch=='\t'||ch==' '||ch=='\n')
				break;
			x+=ch;
		}
	}
}Cin;

END