#include<stdexcept>
/**
 * @file cpplib/SegTree
 * @brief O(n log^2 n)
 */
// ------SegTree-------
namespace std
{
	template<class T>class SUM
	{
		public:
		T operator()(const T x,const T y){return x+y;}
		T UNSET=0;
	};
	template<class T>class MIN
	{
		public:
		T operator()(const T x,const T y){return min(x,y);}
		T UNSET=1e9;
	};
	template<class T>class MAX
	{
		public:
		T operator()(const T x,const T y){return max(x,y);}
		T UNSET=-1e9;
	};
	template<class T,class op>
	class SegTree{
		private:
		T d[2005000]={};
		T UNSET=op().UNSET;
		op opt;
		/// @brief range [L,R) of root (node 1).
		int L=-1,R=-1;
		/// @brief build from [begin,last) of array `a`.
		/// @param begin Begin. 
		/// @param last Last.
		/// @param a the array.
		void __build_a(int s,int t,int p,T* a)
		{
			if(s==t){
				d[p]=*(a+s);
				return;
			}
			int m=(s+t)>>1;
			__build_value(s,m,p*2,a),__build_value(m+1,t,p*2+1,a);
			d[p]=opt(d[p*2],d[(p*2)+1]);
		}
		void __build_value(int s,int t,int p,T v)
		{
			if(s==t){
				d[p]=v;
				return;
			}
			int m=(s+t)>>1;
			__build_value(s,m,p*2,v),__build_value(m+1,t,p*2+1,v);
			d[p]=opt(d[p*2],d[(p*2)+1]);
		}
		/// @brief Query from [Begin,End) .
		/// @param l,r [Begin,End) 
		/// @param s,t [Begin,End) of node `p`.
		/// @param p the node which is on progress.
		T __query(int l,int r,int s,int t,int p=1)
		{
			if(L==-1)
				throw std::logic_error("Query without init");
			if(l<=s&&t<=r)
				return d[p];
			int m=(s+t)>>1;
			T sum=0;
			if(l<=m)
				sum=opt(__query(l,r,s,m,p*2),sum);
			if(r>m)
				sum=opt(__query(l,r,m+1,t,p*2+1),sum);
			return sum;
		}
		/// @brief Update the value of id-th elements.
		/// @param l,r Range [L,R) of node p.
		/// @param id the id which will be changed. 
		/// @param v change id-th with value `v`.
		/// @param p the node which is on progress.
		void __update(int l,int r,int id,T v,int p=1)
		{
			if(L==-1)
				throw std::logic_error("Update without init");
			if(l==r){
				d[p]=v;
				return;
			}
			int mid=(l+r)>>1;
			if(id<=mid)
				__update(l,mid,id,v,p*2);
			else
				__update(mid+1,r,id,v,p*2+1);
			d[p]=opt(d[p*2],d[(p*2)+1]);
		}
		public:
		SegTree()=default;
		SegTree(T val):UNSET(val){};
		T query(int l,int r){return __query(l,r,L,R,1);}
		void update(int id,T v){__update(L,R,id,v,1);}
		void build(int l,int r,T v){L=l,R=r,__build_value(L,R,1,v);}
		void build(int l,int r,T* a){L=l,R=r,__build_a(L,R,1,a);}
	};
} 
// --------------------