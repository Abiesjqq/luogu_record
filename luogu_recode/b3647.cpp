//Folyd模板
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 102;
const int inf = 1e5;

int d[N][N],n,m;

void floyd() {
    for (int k=1;k<=n;k++) //中转点
        for (int i=1;i<=n;i++) //起点
            for (int j=1;j<=n;j++) //终点
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
                

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;

    //初始化邻接矩阵
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            d[i][j]=(i==j)?0:inf;
    //读入边
    for (int i=1;i<=m;i++) {
        int u,v,w; cin >> u >> v >> w;
        d[u][v]=min(d[u][v],w); //重边
        d[v][u]=min(d[v][u],w);
    }

    //计算最短路径
    floyd();

    //输出
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) 
            cout << d[i][j] << " \n"[j==n];

    return 0;
}