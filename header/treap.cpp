/*
MIT License

Copyright (c) 2018 Ì·ÒâÇà

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

#include"treap.h" 
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
int main(){
	return 0;
}
