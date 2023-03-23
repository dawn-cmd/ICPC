#include<bits/stdc++.h>
#define LL long long
#define N 100010
#define M 200010
#define INf (2 << 31 - 1)
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
LL dis[N];
LL vis[N];
priority_queue<pair<LL, LL> > q;

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

void dijkstra()
{
    for (int i = 0; i < n; ++i)
        dis[i] = -1;
    memset(vis, 0, sizeof(vis));
    while (!q.empty())
        q.pop();
    dis[n - 1] = s;
    q.emplace(s, n - 1);
    while (!q.empty())
    {
        LL cur = q.top().second;
        q.pop();
        // cout << cur << ' ' << dis[cur] << endl;
        if (vis[cur])
            continue;
        vis[cur] = 1;
        for (LL i = heads[cur]; i; i = lines[i].next)
        {
            LL cost = lines[i].t0;
            while (cost + lines[i].d <= dis[cur])
                cost += lines[i].p;
            if (cost == lines[i].t0)
                continue;
            cost -= lines[i].p;
            dis[lines[i].v] = max(cost, dis[lines[i].v]);
            q.emplace(-dis[lines[i].v], lines[i].v);
        }
    }
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
        addEdge(tmpv, tmpu, tmpt0, tmpp, tmpd);
    }
    dijkstra();
    if (dis[0] > s || dis[0] == -1)
        cout << "impossible" << endl;
    else
        cout << dis[0] << endl;
}
