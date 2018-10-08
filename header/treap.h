#include<cstdlib>
#define inf 1<<30
class treap{
	public:
		treap* l;
		treap* r;
		treap* f;
		int key,priority,tot;
		treap* findmax(treap*);
		treap* findmin(treap*);
		treap* find(treap*,int);
		void rightrotate(treap*); 
		void leftrotate(treap*);
		void ins(treap*,int,int,treap*);
		void del(treap*);
		treap* split(int,treap*);
		void join(treap*,treap*);
}*root;

