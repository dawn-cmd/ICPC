#include<bits/stdc++.h>
#define LL long long
#define N 20010
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

LL n;
LL m;
LL heads[N];
LL heights[N];

int main() 
{
    while (true)
    {
        n = read();
        m = read();
        if (n == 0 && m == 0)
            break;
        memset(heads, 0 , sizeof(heads));
        memset(heights, 0, sizeof(heights));
        // cout << n << ' ' << m << endl;
        for (int i = 0; i < n; ++i)
            heads[i] = read();
        for (int i = 0; i < m; ++i)
            heights[i] = read();
        sort(heads, heads + n);
        sort(heights, heights + m);
        if (n > m || heads[n - 1] > heights[m - 1])
        {
            cout << "Loowater is doomed!" << endl;
            continue;
        }
        LL id = 0;
        LL ans = 0;
        bool canBeKilled = true;
        for (int i = 0; i < n; ++i)
        {
            while (id < m && heads[i] > heights[id])
                id++;
            if ((id == m) || (n - i - 1 > m - id - 1))
            {
                canBeKilled = false;
                break;
            }
            ans += heights[id];
            id += 1;
        }
        if (!canBeKilled)
            cout << "Loowater is doomed!" << endl;
        else
            cout << ans << endl;
    }
}
