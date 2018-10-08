#include<cstdlib>
#define inf 1<<30
class treap{
	public:
		treap* l;
		treap* r;
		treap* f;
		int key,priority,tot;
}*root;
treap* findmax(treap* x){
	if(! x->r)return x;
	return findmax(x->r);
}
treap* findmin(treap* x){
	if(! x->l)return x;
	return findmin(x->l);
}
treap* find(treap* x,int k){
	if(x==NULL)return 0;
	if(x->key == k)return x;
	if(k<x->key)return find(x->l,k);
}
void rightrotate(treap* x){
	treap* y = x->f ;
	x->f = y->f ;
	if(y->f->l == y)x->f->l = x;
	else x->f->r=x;
	if(x->l)x->l->f = y;
	y->r = x->l ;
	y->f = x;
	x->l = y;
}
void leftrotate(treap* x){
	treap* y = x->f ;
	x->f = y->f ;
	if(y->f->l == y)x->f->l = x;
	else x->f->r=x;
	if(x->r)x->r->f = y;
	y->l = x->r ;
	y->f = x;
	x->r = y;
}
void ins(treap* x,int k,int dir,treap* fa){
	if(!x){
		x = new treap;
		x->key=k;
		x->priority = rand()%inf;
		x->l = x->r = NULL;
		x->tot = 1;
		x->f = fa;
		if(dir)fa->r=x;else fa->l=x;
	}
	else{
		if(k<x->key){
			ins(x->l,k,0,x);
			if(x->l->priority<x->priority)leftrotate(x->l);
			else {
				ins(x->r,k,1,x);
				if(x->r->priority<x->priority)rightrotate(x->r) ;
			}
		}
	}
}
void del(treap* x){
	while(x->l || x->r){
		if(x->l&&(x->r&&x->l->priority<x->r->priority||!x->r))
			leftrotate(x->l);
		else
			rightrotate(x->r); 
	}
	if(x->f->l==x)x->f->l=0;
	else x->f->r=0;
	delete x;
}
treap* split(int k,treap* x){
	if(x->key==k)return x;
	if(x->key<k){
		if(x->r->key==k){
			treap* tmp=new treap;
			tmp->r = x->r ;
			tmp->f = x ;
			x->r->f = tmp;
			tmp->l = 0;
			x->r = tmp;
			tmp->priority = -inf;
			return tmp;
		}
		else{
			treap* tmp = split(k,x->r);
			rightrotate(x->r);
			return tmp;
		}
	}
	else{
		if(x->l->key==k){
			treap* tmp=new treap;
			tmp->l = x->l;
			tmp->f = x;
			x->l->f = tmp;
			tmp->r = 0;
			x->l = tmp;
			tmp->priority = -inf;
			return tmp;
		}
		else {
			treap* tmp = split(k,x->l);
			leftrotate(x->l);
			return tmp;
		}
	}
}
void join(treap* x,treap* y){
	treap* t = new treap;
	t->l = x;
	t->r = y;
	x->f = y->f = t;
	del(t);
}
