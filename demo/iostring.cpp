#include"../any.h"
#include<bits/stdc++.h>
#define f(Tp,str) if(os==str){Tp x;Cin>>x;Cout<<x<<"\n";}
using namespace std;
int main(){
	Cout<<"Welcome to CppLib testing!\n";
	Cout<<"Tips:I=int,F=float,D=double,L=long long,C=char,S=string\n";
	Cout<<"press Ctrl+C to exit\n";
	while(1){
		string os;
		Cin>>os;
		f(int,"I");
		f(float,"F");
		f(double,"D");
		f(long long,"L");
		f(char,"C");
		f(string,"S");
	}
}