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



