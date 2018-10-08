template<const int& num>
class treay{
	public:
		long long C[num+5];
		int lowbit(int);
		long long query(int);
		void modify(int,long long);
		treay();
};
#define BinaryIndexTree treay
#define BIT treay
//sorry for using "#define" because I can't find other way 

const int Maxn = 1e5+5;
struct SegTree
{
    SegTree *ch[2];
    long long _v, label;
    int Num, _l, _r, mid;
    SegTree() { _v = label = 0; Num = 1; }
    void update();
    void maintain();
}Node[Maxn], *null, *Root;
int tot = 0, _k, _L, _R;
long long v;



