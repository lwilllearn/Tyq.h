/*****************************************
 *Copyright TYQ,All rights served        *
 *****************************************/

/*****************************************
 *2018/9/29,first update                 *
 *upd:                                   *
 *Add:Segmettree,BinaryIndexTree(treay)  *
 *Write:math(some)                       *
 *****************************************/
/*****************************************
 *2018/9/29,second update                *
 *upd:                                   *
 *Write:math(some),algo(some);           *
 *Add : treap                            *
 *****************************************/

#include<iostream>
#include<algorithm>
#include<cstring>
#include"splay.h"
#include"Segments.h"
#include"treap.h"
#define ll		long long
#define in      inline
#define inll    inline long long
#define inint   inline int
#define rell    register long long
#define reint   register int
const std::string stderrorvalMATRIX = "ERROR : matrix operator" ;
namespace std {
	/*includes:<iostream><algorithm><cstring><iostream><cstdlib><cstdio>
			   "splay""Segments""treap"*/
	inll gcd(const ll& a,const ll& b);
	inint gcd(const int& a,const int& b);
	template<class T>in auto gcd(const T& a,const T& b)->decltype(a);
	inint ex_gcd(const int& a,const int& b,int& x,int& y);
	inll exgcd(const ll& a,const ll& b,ll& x,ll& y);
	template<class T>in auto exgcd(const T& a,const T& b,T& x,T& y)->decltype(a);
	inll quickpow(ll a,ll b,ll n);
	inint quickpow(int a,int b,int n);
	class matrix {
		private:
			ll** mmat;
			int rol;
			int col;
		public:
			matrix(int r,int c) : rol(c),col(r) {
				mmat = new ll* [rol];
				for(reint i=0; i<rol; ++i) {
					mmat[i]=new ll[c];
					for(reint j=0; j<col; ++j)
						mmat[i][j] = 0;
				}
			}
			~matrix() {
				for(reint i=0; i<rol; ++i)delete[] mmat[i];
				delete[] mmat;
			}
			in ll*& operator[](int);
			in ll** self();
			void operator+=(matrix&);
			void operator=(matrix);
			matrix operator+(matrix&);
			matrix operator *=(matrix&);
			friend ostream& operator <<(ostream&,matrix&);
			friend istream& operator >>(istream&,matrix&);
			matrix operator -();
			void operator -=(matrix&);
			matrix operator -(matrix&);
			matrix operator *(matrix&);
			matrix operator ^=(int);
	};
	//algo
	void kmpinit(char* str,int* fail);
	int kmpmatch(char* a,char* b,int* fail);
	int kmp(char* main,char* find,int* fail);
	int primeinit(int N,bool* notprime,int* prime);
};

