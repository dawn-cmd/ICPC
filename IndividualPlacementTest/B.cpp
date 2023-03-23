#include<bits/stdc++.h>
#define LL long long
#define N 100010
#define minn(a, b) ((a) < (b) ? (a) : (b))
#define maxn(a, b) ((a) > (b) ? (a) : (b))
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
LL p;
LL profit[N];
LL prefix[N];

int main() 
{
    n = read();
    p = read();
    LL s = 0;
    for (int i = 0; i < n; ++i)
    {
        profit[i] = read() - p;
        prefix[i] = profit[i] + s;
        s += profit[i];
    }
    LL minPrefix = 0;
    LL ans = 0;
    for (int i = 0; i < n; ++i)
    {
        minPrefix = minn(minPrefix, prefix[i]);
        ans = maxn(ans, prefix[i] - minPrefix);
    }
    write(ans);
}
