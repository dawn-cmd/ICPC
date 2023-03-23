#include<bits/stdc++.h>
#define LL long long
#define minn(a, b) ((a) < (b) ? (a) : (b))
#define maxn(a, b) ((a) > (b) ? (a) : (b))
#define N 100010
#define M 200010
#define INF 0x3f3f3f3f
using namespace std;

LL read()
{
    LL x = 0;
    LL w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return (LL)(x * w);
}

inline void write(LL x)
{
    static LL sta[35];
    LL top = 0;
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    do
    {
        sta[top++] = x % 10;
        x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + 48);
}

struct busLine
{
    LL u;
    LL v;
    LL t0;
    LL p;
    LL d;
    LL next;
} lines[M];

LL n;
LL m;
LL s;
LL heads[N];
LL numLine = 1;
priority_queue<pair<LL, LL>> q;

void addEdge(LL u, LL v, LL t0, LL p, LL d)
{
    lines[++numLine].u = u;
    lines[numLine].v = v;
    lines[numLine].t0 = t0;
    lines[numLine].p = p;
    lines[numLine].d = d;
    lines[numLine].next = heads[u];
    heads[u] = numLine;
}

LL dfs(LL cur, LL tim)
{
    if (tim > s)
        return INF;
    if (cur == n - 1)
        return tim;
    LL ans = INF;
    for (int i = heads[cur]; i; i = lines[i].next)
    {
        LL cost = lines[i].d;
        if (tim <= lines[i].t0)
            cost += lines[i].t0 - tim;
        else
        {
            LL tmp = tim - lines[i].t0;
            LL p = lines[i].p;
            cost += (tmp / p + ((tmp % p) != 0)) * p - tmp;
        }
        ans = min(dfs(lines[i].v, cost + tim), ans);
    }
    return ans;
}

int main() 
{
    n = read();
    m = read();
    s = read();
    LL tmpu;
    LL tmpv;
    LL tmpt0;
    LL tmpp;
    LL tmpd;
    memset(heads, 0, sizeof(heads));
    for (int i = 0; i < m; ++i)
    {
        tmpu = read();
        tmpv = read();
        tmpt0 = read();
        tmpp = read();
        tmpd = read();
        addEdge(tmpu, tmpv, tmpt0, tmpp, tmpd);
    }
    LL ans = dfs(0, 0);
    if (ans > s)
        cout << "impossible" << endl;
    else
        cout << s - ans << endl;
}
