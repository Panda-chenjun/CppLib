#include"IOS.cpp"
#include"cxxtype.cpp"
template<ull P>
class modint{
	private:
	ll v;
	public:
	modint(ll x){v=x%P;}
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
	modint operator/(modint __rhs){return (v/__rhs.v)%P;}
};
template<ull P>
std::OS& operator << (std::OS x,modint<P> A){
	return x<<A.val();
}