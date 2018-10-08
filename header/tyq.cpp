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

#include"tyq.h"
#define ll		long long
#define in      inline
#define inll    inline long long
#define inint   inline int
#define rell    register long long
#define reint   register int
inll std::gcd(const ll& a,const ll& b) {
	if(b==0)return a;
	else return gcd(b,a%b);
}
inint std::gcd(const int& a,const int& b) {
	if(b==0)return a;
	else return gcd(b,a%b);
}
template<class T>
in auto std::gcd(const T& a,const T& b)->decltype(a) {
	if(b==0)return a;
	else return gcd(b,a%b);
}
inint std::ex_gcd(const int& a,const int& b,int& x,int& y) {
	if(b==0) {
		x=1,y=0;
		return a;
	}
	int r = ex_gcd(b,a%b,x,y);
	int t = x;
	x = y;
	y = t-a/b*y;
	return r;
}
inll std::exgcd(const ll& a,const ll& b,ll& x,ll& y) {
	if(b==0) {
		x=1,y=0;
		return a;
	}
	ll r = exgcd(b,a%b,x,y);
	int t = x;
	x = y;
	y = t-a/b*y;
	return r;
}
template<class T>in auto std::exgcd(const T& a,const T& b,T& x,T& y)->decltype(a) {
	if(b==0) {
		x=1,y=0;
		return a;
	}
	ll r = exgcd(b,a%b,x,y);
	int t = x;
	x = y;
	y = t-a/b*y;
	return r;
}//To use this , you must define operator"=="(toint),%,=,-,*;
inll std::quickpow(ll a,ll b,ll n) {
	int t,y;
	t=1;
	y=a;
	while (b) {
		if (b&1) t=t*y%n;
		y=y*y%n;
		b=b>>1;
	}
	return t;
}
inint std::quickpow(int a,int b,int n) {
	int t,y;
	t = 1;
	y = a;
	while(b) {
		if(b&1)t=t*y%n;
		y = y*y % n;
		b>>=1;
	}
	return t;
}
std::matrix::in ll*& operator[](int a) {
	return this->mmat[a];
}
std::matrix::in ll** self() {
	return this->mmat ;
}
std::matrix::void operator+=(matrix& add) {
	if(add.rol!=rol || add.col!=col)throw((stderrorvalMATRIX+char(34)+"+="+char(34)));
	for(reint i=0; i<rol; ++i)
		for(reint j=0; j<col; ++j)
			mmat[i][j]+=add.self()[i][j];
	return ;
}
std::matrix::void operator=(matrix eval) {
	if(eval.col!=col || eval.rol!=rol)throw((stderrorvalMATRIX+char(34)+"+="+char(34)));
	else {
		rol = eval.rol;
		col = eval.col;
		for(reint i=0; i<rol; ++i)
			for(reint j=0; j<col; ++j)
				this->mmat[i][j] = eval.self()[i][j] ;
	}
}
std::matrix::matrix operator+(matrix& add) {
	matrix a = *this ;
	a+=add;
	return a;
}
std::matrix::friend ostream& operator <<(ostream& os,matrix& eval) {
	for(reint i=0; i<eval.rol; ++i) {
		for(reint j=0; j<eval.col; ++j)
			os<<eval.self()[i][j]<<" ";
		os<<endl;
	}
	return os;
}
std::matrix::friend istream& operator >>(istream& is,matrix& eval) {
	for(reint i=0; i<eval.rol; ++i)
		for(reint j=0; j<eval.col; ++j)
			is>>eval.self()[i][j];
	return is;
}
std::matrix::matrix operator -() {
	for(reint i=0; i<rol; ++i)
		for(reint j=0; j<col; ++j)
			this->mmat[i][j] = -this->mmat[i][j];
	return *this;
}
std::matrix::void operator -=(matrix& add) {
	if(add.rol!=rol || add.col!=col)throw((stderrorvalMATRIX+char(34)+"+="+char(34)));
	for(reint i=0; i<rol; ++i)
		for(reint j=0; j<col; ++j)
			mmat[i][j]-=add.self()[i][j];
	return ;
}
std::matrix::matrix operator -(matrix& add) {
	matrix a = *this ;
	a-=add;
	return a;
}
std::matrix::matrix operator *(matrix& eval) {
	if(this->col != eval.rol)throw((stderrorvalMATRIX+char(34)+"*="+char(34)));
	matrix a(rol,eval.col);
	for(reint i=0; i<rol; ++i)
		for(reint j=0; j<col; ++j)
			for(reint k=0; k<eval.col; ++k)
				a.self()[i][j] += this->mmat[i][j]*eval.self()[i][j] ;
	return a;
}
std::matrix::matrix operator *=(matrix& add) {
	matrix ans = this->operator *(add);
	*this = ans;
	return *this;
}
std::matrix::matrix operator ^=(int b) {
	if(rol!=col)throw((stderrorvalMATRIX+(char)(34)+"^="));
	matrix matans(rol,col),matres=*this;
	for(int i=0; i<rol; ++i)
		for(int j=0; j<col; ++j)
			if(i==j)matans.self()[i][j] = 1 ;
			else matans.self()[i][j] = 0;
	while(b) {
		if(b&1)matans.operator=(matans*matres);
		matres.operator=(matres*matres);
		b>>=1;
	}
	return matans;
}
void std::kmpinit(char* str,int* fail) { // str satrts with one;
	//get fail prt
	fail[1]=0;
	int lenstr = strlen(str+1);
	for(int i=2,j=0; i<lenstr; ++i) {
		while(j && str[i]!=str[j+1])j = fail[j];
		if(str[i] == str[j+1])++j;
		fail[i] = j;
	}
}
int std::kmpmatch(char* a,char* b,int* fail) { //find b from a
	int lb = strlen(b+1);
	int la = strlen(a+1);
	for(int i=1,j=0; i<lb; ++i) {
		while(j>0 && a[i]!=b[j+1])j=fail[j];
		if(a[i]==b[j+1])++j;
		if(j==la)return i;
	}
}
int std::kmp(char* main,char* find,int* fail) { //find b from a
	kmpinit(find,fail);
	return kmpmatch(main,find,fail);
}
int std::primeinit(int N,bool* notprime,int* prime) {
	notprime[0]=true;
	notprime[1]=true;
	int j = 0;
	for(register int i=2; i<=N; ++i) {
		if(notprime[i]==false) {
			prime[j++] = i ;
			for(int k=i+i; k<=N; k=k+i) {
				notprime[k]=true;
			}
		}
	}
	return j;
}
