#include<bits/stdc++.h>
#define LL long long
#define N 100
#define M 10010
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

struct Edge
{
    LL to;
    LL next;
} edges[M];
LL n;
LL m;
LL score[N][N];
LL heads[N];
LL tot = 1;
LL vis[N];
queue<LL> q;

void addEdge(LL s, LL t)
{
    edges[++tot].to = t;
    edges[tot].next = heads[s];
    heads[s] = tot;
}

LL bfs(LL s)
{
    while (!q.empty())
        q.pop();
    memset(vis, 0, sizeof(vis));
    q.push(s);
    LL cnt = 1;
    vis[s] = 1;
    while (!q.empty())
    {
        LL cur = q.front();
        q.pop();
        // cout << cur << endl;
        // for (int i = 0; i < n; ++i)
        //     cout << vis[i] << ' ';
        // cout << endl;
        for (int i = heads[cur]; i; i = edges[i].next)
        {
            if (vis[edges[i].to])
                continue;
            cnt += 1;
            q.push(edges[i].to);
            vis[edges[i].to] = 1;
        }
    }
    return cnt;
}

int main() 
{
    n = read();
    m = read();
    LL vote;
    string seq;
    memset(heads, 0, sizeof(heads));
    memset(score, 0, sizeof(score));
    for (int i = 0; i < m; ++i)
    {
        cin >> vote >> seq;
        for (int j = 0; j < n - 1; ++j)
            for (int k = j + 1; k < n; ++k)
            {
                LL tmpa = seq[j] - 'A';
                LL tmpb = seq[k] - 'A';
                score[tmpa][tmpb] += vote;
            }
    }
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            // cout << i << ' ' << j << ' ' << score[i][j] << ' ' << score[j][i] << endl; 
            if (score[i][j] > score[j][i])
                addEdge(i, j);
            else
                addEdge(j, i);
        }

    // for (int i = 0; i < n; ++i)
    // {
    //     cout << i << " -> ";
    //     for (int j = heads[i]; j; j = edges[j].next)
    //         cout << edges[j].to << ' ';
    //     cout << endl;
    // }
            
    for (int i = 0; i < n; ++i)
        if (bfs(i) == n)
            cout << (char)('A' + i) << ": can win" << endl;
        else
            cout << (char)('A' + i) << ": can't win" << endl;
}
