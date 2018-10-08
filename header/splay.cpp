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

#include"splay.h"
splaynode::splaynode(){L = R = F = NULL;}
splaynode::splaynode(int k){
	key = k;
	L = R = F = NULL;
}
void splaynode::leftrotate(){
	splaynode *y = F;
	F = y->F;
	if(F!=NULL){
		if(F->L == y)F->L=this;
		else F->R=this;
	}
	if(R!=NULL)R->F=y;
	y->L=R;
	y->F=this;
	this->R=y;
}
void splaynode::rightrotate(){
	splaynode *y = F;
	F = y->F;
	if(F!=NULL){
		if(F->L == y)F->L=this;
		else F->R=this;
	}
	if(L!=NULL)R->F=L;
	y->R=L;
	y->F=this;
	this->L=y;
}
void splaynode::splay(splaynode* x,splaynode* s){
	splaynode *sf = s->F;
	while(x->F != sf){
		splaynode *y=x->F;
		splaynode *z=y->F;
		if(z==sf){
			if(y->L == x)x->leftrotate();
			else x->rightrotate();
		}
		else {
			if(y->L == x && z->L ==y){
				y->leftrotate();
				x->leftrotate();
			}
			else if(y->L == x && z->R == y){
				x->leftrotate();
				x->rightrotate();
			}
			else if(y->R == x && z->R == y){
				y->rightrotate();
				x->rightrotate();
			}
			else {
				x->rightrotate();
				x->leftrotate();
			}
		}
	}
}
splaynode* splaynode::find(int k){
	if(k==key)return this;
	if(k<key){
		if(L==NULL)return NULL;
		return L->find(k);
	}
	else {
		if(R==NULL)return NULL;
		return R->find(k);
	}
}
splaynode* splaynode::insert(int k){
	if(k<=key){
		if(L==NULL){
			L = new splaynode(k);
			L->F = this;
			return L;
		}
		else return L->insert(k);
	}
	else {
		if(R==NULL){
			R = new splaynode(k);
			R->F = this;
			return R;
		}
		else return R->insert(k);
	}
}
splaynode* splaynode::deletenode(splaynode* x,splaynode* s){
	splay(x,s);
	splaynode* a=x->L;
	splaynode* b=x->R;
	delete x;
	if(a!=NULL)a->F=NULL;
	if(b!=NULL)b->F=NULL;
	if(a==NULL)return b;
	if(b==NULL)return a;
	return join(a,b);
}
splaynode* splaynode::max(){
	if(R==NULL)return this;
	else return R->max();
}
splaynode* splaynode::min(){
	if(L==NULL)return this;
	else return L->min();
}
splaynode* splaynode::prev(int k){
	if(key<=k){
		if(R==NULL)return this;
		splaynode* tmp = R->prev(k);
		if(tmp==NULL)return this;
		return tmp;
	}
	else {
		if(L==NULL)return NULL;
		return L->prev(k);
	}
}
splaynode* splaynode::succ(int k){
	if(k<=key){
		if(L==NULL)return this;
		splaynode* tmp = L->succ(k);
		if(tmp==NULL)return this;
		return tmp;
	}
	else {
		if(R==NULL)return NULL;
		else return R->succ(k);
	}
}
splaynode* splaynode::join(splaynode* x,splaynode* y){
	splaynode* p = x->max();
	splay(p,x);
	p->R = y;
	y->F = p;
	return p;
}
void splaynode::split(int k,splaynode* s,splaynode* x,splaynode* y){
	splaynode* p = s->find(k);
	splay(p,s);
	x = p->L;
	y = p->R;
}
int main(){
	return 0;
}
