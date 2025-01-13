#include<string>
inline bool is_split(char ch){
	if(ch==' '||ch=='\n'||ch=='\t')
		return 1;
	return 0;
}
inline char __flush_input(){
	static char ch='\0';
	while(1){
		ch=getchar();
		if(!is_split(ch))
			return ch;
	}
}
const long long getint(){
	long long res=0;
	long long sign=1;
	static char ch='\0';
	while(!isdigit(ch)){
		ch=getchar();
		if(ch=='-')
			sign=-1;
	}
	while(1){
		if(!isdigit(ch))
			break;
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*sign;
}
const std::string getstr(){
	std::string res;
	res.clear();
	static char ch=__flush_input();
	while(1){
		ch=getchar();
		if(is_split(ch))
			break;
		res.push_back(ch);
	}
	return res;
}
const std::string getln(){
	std::string res;
	char ch=__flush_input();
	while(1){
		ch=getchar();
		if(ch=='\n')
			break;
		res.push_back(ch);
	}
	return res;
}
using __int128_t=__int128;
const __int128_t getint128(){
	__int128_t res=0;
	int sign=1;
	static char ch='\0';
	while(!isdigit(ch)){
		ch=getchar();
		if(ch=='-')
			sign=-1;
	}
	while(1){
		if(!isdigit(ch))
			break;
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*sign;
}