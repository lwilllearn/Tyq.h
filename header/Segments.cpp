#include"Segments.h"
//start treay
template<const int& num>
int treay<num>::lowbit(int x){
	return (x)& (-x);
}	
template<const int& num>
long long treay<num>::query(int x){
	long long re=0;
	for(int i=x;i;i-=i&-i)
		re+=C[i];
	return re;
}
template<const int& num>
void treay<num>::modify(int x,long long val){
	if(x>num)return;
	for(int i=x;i<=num;i+=i&-i)
		C[i]+=val;
}
template<const int& num>
treay<num>::treay(){
	memset(C,0,sizeof C);
}
//finish treay
//start Segment tree
void SegTree::update(){
    if(!label) return;
    _v += Num*label;
    if(Num != 1) ch[0]->label += label, ch[1]->label += label;
    label = 0;
}
void SegTree::maintain(){
    ch[0]->update(); ch[1]->update();
    _v = ch[0]->_v + ch[1]->_v;
}
void protect(){
	null = new SegTree();
    null->ch[0] = null->ch[1] = null; null->Num = 0;
}
void insert(SegTree *&o, int l, int r){
    int mid = (l+r)/2;
    if(o == null){
        o = &Node[tot++];
        o->ch[0] = o->ch[1] = null;
        o->_l = l; o->_r = r; o->mid = (l+r)/2;
    }
    if(l == r) { o->_v = v; return; }
    if(_k <= mid) insert(o->ch[0], l, mid);
    else insert(o->ch[1], mid+1, r);
    o->maintain(); o->Num = o->ch[1]->Num + o->ch[0]->Num;
}
SegTree* Build(int n, long long *a){
    protect(); Root = null;
    for(int i = 1; i <= n; i++) _k = i, v = a[i], insert(Root, 1, n);
    return Root;
}
long long query(SegTree *o){
    long long ans = 0;
    o->update();
    if(_L <= o->_l && o->_r <= _R) return o->_v;
    if(_L <= o->mid) ans += query(o->ch[0]);
    if(_R > o->mid) ans += query(o->ch[1]);
    return ans;
}
long long Query(int L, int R) {
	_L = L; 
	_R = R; 
	return query(Root); 
}
void change(SegTree *o){
    o->update();
    if(_L <= o->_l && o->_r <= _R) { o->label += v; o->update(); return; }
    if(_L <= o->mid) change(o->ch[0]);   if(_R > o->mid) change(o->ch[1]);
    o->maintain(); 
}
void Change(int L, int R, int V) { 
	_L = L; 
	_R = R; 
	v = V; 
	change(Root); 
}
int main(){
	return 0;
}