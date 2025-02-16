#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+9;

ll n,V;
ll v[N];
ll dp[N];

int main() {
    cin >> V >> n;
    for (int i=1;i<=n;i++) cin >> v[i];

    for (int i=1;i<=n;i++) {
        for (int j=V;j>=v[i];j--) {
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }
    }
    cout << V-dp[V] << '\n';
    return 0;
}