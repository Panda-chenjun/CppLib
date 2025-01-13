#define LLONG_MAX 9223372036854775807LL
/// @brief Pow for interger.
long long pow(long long base,long long K,long long P=LLONG_MAX){
	long long ans=1;
	while(K){
		if(K&1)
			base=(base*base)%P;
		ans=(ans*base)%P;
		K>>=1;
	}
	return ans%P;
}
unsigned int __builtin_lowbit(unsigned int v){
	return v&-v;
}
unsigned long long __builtin_lowbit(unsigned long long v){
	return v&-v;
}
