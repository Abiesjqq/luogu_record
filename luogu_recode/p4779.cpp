//单源最短路程(标准版)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+9;
const ll inf = 0x3f3f3f3f3f3f3f3f; //long long的最大值

struct Node {
    ll x,w; //x终点,w权值
    bool operator< (const Node &y) const {
        return w>y.w;
    }
};
vector<Node> g[N];

ll n,m,s;
ll d[N];

void dijkstra(ll st) {
    //初始化
    memset(d,inf,sizeof(ll)*(n+1));
    d[st]=0;

    bitset<N> vis; //标记点是否被拓展过

    //建立优先队列
    priority_queue<Node> pq;
    pq.push((Node){st,d[st]});

    while (pq.size()) {
        ll x=pq.top().x; //x是距离源点最近的点
        pq.pop();

        if (vis[x]) continue; //不重复拓展
        vis[x]=true;

        //遍历x的终点进行松弛
        for (auto &[y,w] : g[x]) {
            if (!vis[y] && d[y]>d[x]+w) {
                d[y]=d[x]+w;
                pq.push((Node){y,d[y]});
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    //构建图
    for (ll i=1;i<=m;i++) {
        ll u,v,w; cin >> u >> v >> w;
        if (u!=v) g[u].push_back({v,w});
    }

    dijkstra(s);

    for (ll i=1;i<=n;i++) {
        if (d[i]<inf) cout << d[i] << ' ';
        else cout << (1LL<<31)-1 << ' ';
    }
    cout << '\n';

    return 0;
}