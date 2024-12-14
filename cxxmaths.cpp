#include"cxxtype.cpp"
template<class Func>
ll __pow(ll base,ll k,Func f){
	ll ans=1;
	while(k){
		if(k&1)
			ans=f(ans,base);
		k>>=1;
		base=f(base,base);
	}
	return ans;
}
ll pw(ll base,ll k,ll P=-1){
	if(P==-1)
		return __pow(base,k,[](ll x,ll y){return x*y;});
	return __pow(base,k,[P](ll x,ll y){return x*y%P;});
}
/// @warning `P` must be prime, or return value may be undefined.
ll inv(ll val,ll P){
	return pw(val,P-2,P);
}