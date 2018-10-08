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
const std::string stderrorval = "ERROR : matrix operator" ;
//math.h
namespace std{
	/*includes:<iostream><algorithm><cstring><iostream><cstdlib><cstdio>
			   "splay""Segments""treap"*/
	in ll gcd(const ll& a,const ll& b){
		if(b==0)return a;
		else return gcd(b,a%b);
	}
	in int gcd(const int& a,const int& b){
		if(b==0)return a;
		else return gcd(b,a%b);
	}
	template<class T>
	in auto gcd(const T& a,const T& b)->decltype(a){
		if(b==0)return a;
		else return gcd(b,a%b);
	}//To use this , you have to define operator"=="(to 0) , "%" ;
	inint ex_gcd(const int& a,const int& b,int& x,int& y){
		if(b==0){
			x=1,y=0;
			return a;
		}
		int r = ex_gcd(b,a%b,x,y);
		int t = x;
		x = y;
		y = t-a/b*y;
		return r;
	}
	inll exgcd(const ll& a,const ll& b,ll& x,ll& y){
		if(b==0){
			x=1,y=0;
			return a;
		}
		ll r = exgcd(b,a%b,x,y);
		int t = x;
		x = y;
		y = t-a/b*y;
		return r;
	}
	template<class T>in auto exgcd(const T& a,const T& b,T& x,T& y)->decltype(a){
		if(b==0){
			x=1,y=0;
			return a;
		}
		ll r = exgcd(b,a%b,x,y);
		int t = x;
		x = y;
		y = t-a/b*y;
		return r;
	}//To use this , you must define operator"=="(toint),%,=,-,*;
	inll quickpow(ll a,ll b,ll n){
  		int t,y;
  		t=1; y=a;
  		while (b){
    		if (b&1) t=t*y%n;
    		y=y*y%n; b=b>>1;
  		}
  		return t;
	}
	inint quickpow(int a,int b,int n){
		int t,y;
		t = 1;y = a;
		while(b){
			if(b&1)t=t*y%n;
			y = y*y % n;
			b>>=1;
		}
		return t;
	}
	class matrix{
		private:
			ll** mmat;
			int rol;
			int col;
		public:
			matrix(int r,int c) : rol(c),col(r){
				mmat = new ll* [rol];
				for(reint i=0;i<rol;++i){
					mmat[i]=new ll[c];
					for(reint j=0;j<col;++j)
						mmat[i][j] = 0;
				}
			}
			~matrix(){
				for(reint i=0;i<rol;++i)delete[] mmat[i];
				delete[] mmat;
			}
			in ll* operator[](int a){
				return this->mmat[a];
			}
			in ll** self(){
				return this->mmat ;
			}
			void operator+=(matrix& add){
				if(add.rol!=rol || add.col!=col)throw((stderrorval+char(34)+"+="+char(34)));
				for(reint i=0;i<rol;++i)
					for(reint j=0;j<col;++j)
						mmat[i][j]+=add.self()[i][j];
				return ;
			}
			void operator=(matrix eval){
				if(eval.col!=col || eval.rol!=rol)throw((stderrorval+char(34)+"+="+char(34)));
				else {
					rol = eval.rol;
					col = eval.col;
					for(reint i=0;i<rol;++i)
						for(reint j=0;j<col;++j)
							this->mmat[i][j] = eval.self()[i][j] ;
				}
			}
			matrix operator+(matrix& add){
				matrix a = *this ;
				a+=add;
				return a;
			}
			friend ostream& operator <<(ostream& os,matrix& eval){
				for(reint i=0;i<eval.rol;++i){
					for(reint j=0;j<eval.col;++j)
						os<<eval.self()[i][j]<<" ";
					os<<endl;
				}
				return os;		
			}
			friend istream& operator >>(istream& is,matrix& eval){
				for(reint i=0;i<eval.rol;++i)
					for(reint j=0;j<eval.col;++j)
						is>>eval.self()[i][j];
				return is;
			}
			matrix operator -(){
				for(reint i=0;i<rol;++i)
					for(reint j=0;j<col;++j)
						this->mmat[i][j] = -this->mmat[i][j];
				return *this;
			}
			void operator -=(matrix& add){
				if(add.rol!=rol || add.col!=col)throw((stderrorval+char(34)+"+="+char(34)));
				for(reint i=0;i<rol;++i)
					for(reint j=0;j<col;++j)
						mmat[i][j]-=add.self()[i][j];
				return ;
			}
			matrix operator -(matrix& add){
				matrix a = *this ;
				a-=add;
				return a;
			}
			matrix operator *(matrix& eval){
				if(this->col != eval.rol)throw((stderrorval+char(34)+"*="+char(34)));
				matrix a(rol,eval.col);
				for(reint i=0;i<rol;++i)
					for(reint j=0;j<col;++j)
						for(reint k=0;k<eval.col;++k)
							a.self()[i][j] += this->mmat[i][j]*eval.self()[i][j] ;
				return a;
			}
			matrix operator *=(matrix& add){
				matrix ans = this->operator *(add);
				*this = ans;
				return *this;
			}
			matrix operator ^=(int b){
				if(rol!=col)throw((stderrorval+(char)(34)+"^="));
				matrix matans(rol,col),matres=*this;
				for(int i=0;i<rol;++i)
					for(int j=0;j<col;++j)
						if(i==j)matans.self()[i][j] = 1 ;
						else matans.self()[i][j] = 0;
				while(b){
					if(b&1)matans.operator=(matans*matres);
					matres.operator=(matres*matres);
					b>>=1;
				}
				return matans;
			}
	};
	//algo
	void kmpinit(char* str,int* fail){ // str satrts with one;
		//get fail prt
		fail[1]=0;
		int lenstr = strlen(str+1);
		for(int i=2,j=0;i<lenstr;++i){
			while(j && str[i]!=str[j+1])j = fail[j];
			if(str[i] == str[j+1])++j;
			fail[i] = j;
		}
	}
	int kmpmatch(char* a,char* b,int* fail){//find b from a
		int lb = strlen(b+1);
		int la = strlen(a+1);
		for(int i=1,j=0;i<lb;++i){
			while(j>0 && a[i]!=b[j+1])j=fail[j];
			if(a[i]==b[j+1])++j;
			if(j==la)return i;
		}
	}
	int kmp(char* main,char* find,int* fail){//find b from a
		kmpinit(find,fail);
		return kmpmatch(main,find,fail);
	}
	int primeinit(int N,bool* notprime,int* prime){
		notprime[0]=true;notprime[1]=true;int j = 0;
		for(register int i=2;i<=N;++i){
			if(notprime[i]==false){
				prime[j++] = i ;
				for(int k=i+i;k<=N;k=k+i){
					notprime[k]=true;
				}
			}
		}
		return j;
	}
	
};

