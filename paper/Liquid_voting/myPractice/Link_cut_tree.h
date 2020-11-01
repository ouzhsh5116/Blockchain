/*
https://www.bilibili.com/s/video/BV1G4411z7mN
https://oi-wiki.org/ds/lct/
https://www.luogu.com.cn/problem/solution/P3690
https://www.zybuluo.com/xzyxzy/note/1027479
*/ 

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 10010;
struct LCTree
{
    int ch[maxn][2], fa[maxn], tag[maxn];
    // vector<int> fa, tag;
    // vector<vector<int> > ch;
    // LCTree(int sz){
    //     fa.reserve(sz);
    //     fa.assign(sz, -1);
    //     tag.reserve(sz);
    //     tag.assign(sz, 0);
    //     ch.reserve(sz);
    //     ch.assign(sz, vector<int>{0,0});
    // }

    void clear(int x) { ch[x][0] = ch[x][1] = fa[x] = tag[x] = 0; }
    int getch(int x) { return ch[fa[x]][1] == x; }
    int isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
    void pushdown(int x)
    {
        if (tag[x])
        {
            if (ch[x][0])
                swap(ch[ch[x][0]][0], ch[ch[x][0]][1]), tag[ch[x][0]] ^= 1;
            if (ch[x][1])
                swap(ch[ch[x][1]][0], ch[ch[x][1]][1]), tag[ch[x][1]] ^= 1;
            tag[x] = 0;
        }
    }
    void update(int x)
    {
        if (!isroot(x))
            update(fa[x]);
        pushdown(x);
    }
    void rotate(int x)
    {
        int y = fa[x], z = fa[y], chx = getch(x), chy = getch(y);
        fa[x] = z;
        if (!isroot(y))
            ch[z][chy] = x;
        ch[y][chx] = ch[x][chx ^ 1];
        fa[ch[x][chx ^ 1]] = y;
        ch[x][chx ^ 1] = y;
        fa[y] = x;
    }

    // 将x旋转至整个splay树的定点
    void splay(int x)
    {
        update(x);
        int f;
        // while 保证x一定可以旋转到根节点位置
        while (!isroot(x))
        {
            f = fa[x];
            if (!isroot(f))
                rotate(getch(x) == getch(f) ? f : x);
            rotate(x);
        }
    }
    // 访问节点x，并且将根节点到x节点之间所有的路径变为实边
    void access(int x)
    {
        for (int son = 0; x; son = x, x = fa[x])
        {
            splay(x);
            // 这句代码将虚边变为实边，同时将最后一个点的右儿子变为0，即变为虚边
            ch[x][1] = son;
        }
    }
    // 将原来的树中x节点作为根节点
    void makeroot(int x)
    {
        access(x);
        splay(x);
        // 交换x的左孩子节点和右孩子节点
        swap(ch[x][0], ch[x][1]);
        // 进行懒人标记，不再递归的进行翻转
        tag[x] ^= 1;
    }

    // 寻找x节点在原树的根节点
    int findRoot(int x)
    {
        access(x);
        splay(x);
        while (ch[x][0])
        {
            pushdown(x);
            x = ch[x][0];
        }
        splay(x);
        return x;
    }

    // 将x和y之间建立连接
    void link(int x, int y)
    {
        makeroot(x);
        // 如果是同一个点，或者x和y已经连通，则跳过
        if (x == y || findRoot(x) == findRoot(y))
            return;
        fa[x] = y;
    }

    // 断开x 和 y 之间的连接
    void cut(int x, int y)
    {
        makeroot(x);
        // 如果y和x不在一棵树上，或者x和y之间不邻接(y的父亲不是x 或者y有左儿子)，不进行cut
        if (findRoot(y) != x || fa[y] != x || ch[y][0])
            return;
        fa[y] = ch[x][1] = 0;
        update(x);
    }

    // 把x到y的路径拆出来
    void split(int x, int y)
    {
        if (x == y || findRoot(x) != findRoot(y))
            return;
        makeroot(x);
        access(y);
        splay(y);
    }
};
int n, q, x, y;
char op[maxn];
int main()
{
    scanf("%d%d", &n, &q);
    while (q--)
    {
        scanf("%s%d%d", op, &x, &y);
        LCTree st;
        if (op[0] == 'Q')
        {
            if (st.findRoot(x) == st.findRoot(y))
                printf("Yes\n");
            else
                printf("No\n");
        }
        if (op[0] == 'C')
        {
            st.link(x, y);
        }
        if (op[0] == 'D')
        {
            st.cut(x, y);
        }
    }
    return 0;
}