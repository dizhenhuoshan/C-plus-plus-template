#include <iostream>
using namespace std;
const int maxm = XXX; // max num of the edge
const int maxn = XXX; // max num of the node

int u[maxm], v[maxm], w[maxm]; // from u to v there is an edge weighted m
int first[maxn], next[maxn];
//first[i] is the first edge of node[i]. if there is no edge, first[i] = -1;
//next[i] is the previous edge of edge i (like a link, this is used to creat a link).

void addedge()
{
    for (int i = 1; i <= n; i++)
        first[i] = -1;
    for (int i = 1; i <=m; i++)
    {
        scanf("%d%d%d\n", &u[i], &v[i], &w[i]);
        next[i] = first[u[i]];
        first[u[i]] = i;
    }
}

void tranverse_node()
{
    for (int i = 1; i <= n; i++)
    {
        int k = first[i];
        while (k != -1)
        {
            /*......*/
            k = next[k];
        }
    }
}

void tranverse_edge()
{
    int k = first[1];
    while (k != -1)
    {
        /*......*/
        k = next[k];
    }
}
