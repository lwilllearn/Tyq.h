#include"tyq.h"
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	matrix a(n,m),b(n,m);
	cout<<a<<endl;
	cin>>a>>b;
	a+=b;
	cout<<a<<endl;
}
