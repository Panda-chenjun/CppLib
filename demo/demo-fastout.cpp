#include<string>
#include"../src/fastio.h"
int main(){
	fastout<<"-----------fastout-demo-----------"<<endl;
	fastout<<"short:"<<short(255)<<endl;
	fastout<<"int:"<<int(2345342)<<endl;
	fastout<<"long long:"<<1391039578LL<<endl;
	fastout<<"int128:"<<__int128(100000000)*__int128(100000000)<<endl;
	fastout<<"string:"<<std::string("Hello world!")<<endl;
	fastout<<"----------------------------------";
}