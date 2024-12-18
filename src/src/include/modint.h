#include"IOS.h"
#include"cxxtype.h"
#include"cxxmaths.h"
template<ull P>
class modint{
	private:
	ll v;
	public:
	modint(ll x){v=x%P;}
	modint(int x){v=x%P;}
	modint(){v=0;}
	fll val(){
		return this->v;
	}
	bool operator<(modint __rhs){return v<__rhs.v;}
	bool operator>(modint __rhs){return v>__rhs.v;}
	bool operator<=(modint __rhs){return v<=__rhs.v;}
	bool operator>=(modint __rhs){return v>=__rhs.v;}
	modint operator+(modint __rhs){return (v+__rhs.v)%P;}
	modint operator-(modint __rhs){return (v-__rhs.v+P)%P;}
	modint operator*(modint __rhs){return (v*__rhs.v)%P;}
	modint operator/(modint __rhs){return (v*inv(__rhs.v,P))%P;}
	/// @warning **POWER**, not **XOR**.
	modint operator^(ll __rhs){return pw(v,__rhs,P)%P;}
};
template<ull P>
std::OS& operator << (std::OS x,modint<P> A){
	return x<<A.val();
}