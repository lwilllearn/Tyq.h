/*
MIT License

Copyright (c) 2018 Ã∑“‚«‡

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

email:11186192@qq.com / TYQ11186192@163.com

*/

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

