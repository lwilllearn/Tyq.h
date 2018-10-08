#include<iostream>
class splaynode{
	public:
		splaynode *L,*R,*F;
		int key;
		splaynode(int k);
		splaynode();
		void leftrotate();
		void rightrotate();
		static void splay(splaynode* x,splaynode* s);
		splaynode* find(int k);
		splaynode* insert(int k);
		splaynode *max();
		splaynode* min();
		splaynode* succ(int k);
		splaynode* prev(int k);
		static splaynode* join(splaynode* x,splaynode* y);
		static splaynode* deletenode(splaynode* x,splaynode* y);
		static void split(int k,splaynode* s,splaynode* x,splaynode* y);
};

