//SJTU OJ 4117
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 100005;

long long sum[maxn<<2];
long long add[maxn<<2];
long long A[maxn];
int N;

void pushup(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void buildtree(int l ,int r, int rt)
{
    if (l == r)
    {
        sum[rt] = A[l];
        return;
    }
    int m = (l + r)>>1;
    buildtree(l, m, rt<<1);
    buildtree(m + 1, r, rt<<1|1);
    pushup(rt);
}

void pushdown(int rt, int ln, int rn)
{
    if (add[rt])
    {
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += add[rt] * ln;
        sum[rt<<1|1] += add[rt] * rn;
        add[rt] = 0;
    }
}

//A[L] += C
void singleupdate(int L, int C, int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] += C;
        return;
    }
    int m = (l + r)>>1;
    if (L <= m) singleupdate(L, C, l, m, rt<<1);
    else singleupdate(L, C, m + 1, r, rt<<1|1);
    pushup(rt);
}

//A[L, R] += C
void segupdate(int L, int R, int C, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        sum[rt] += C * (r - l + 1);
        add[rt] += C;
        return;
    }
    int m = (l + r) >> 1;
    pushdown(rt, m - l + 1, r - m);
    if (L <= m) segupdate(L, R, C, l, m, rt<<1);
    if (R > m)  segupdate(L, R, C, m + 1, r, rt<<1|1);
    pushup(rt);
}

long long Query(int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
    {
        return sum[rt];
    }
    int m = (l + r)>>1;
    pushdown(rt, m - l + 1, r - m);
    long long ans = 0;
    if (L <= m) ans += Query(L, R, l, m, rt<<1);
    if (R > m)  ans += Query(L, R, m + 1, r, rt<<1|1);
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    int a, b, c;
    long long ans = 0;
    char opt;
    cin >> N >> M;
    for (register int i = 1; i <= N; i++)
        cin >> A[i];
    buildtree(1, N, 1);
    for (register int i = 0; i < M; i++)
    {
        cin >> opt;
        if (opt == 'Q')
        {
            cin >> a >> b;
            ans = Query(a, b, 1, N, 1);
            cout << ans << '\n';
        }
        else if (opt == 'C')
            {
                cin >> a >> b >> c;
                segupdate(a, b, c, 1, N, 1);
            }
    }
    return 0;
}
