#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4+9;

ll t,m;
ll a[N],b[N];
ll dp[2][10000002];

int main() {
    cin >> t >> m;
    for (ll i=1;i<=m;i++) cin >> a[i] >> b[i];

    for (ll i=1;i<=m;i++) {
        int y=i&1;
        for (ll j=1;j<=t;j++) {
            if (j>=a[i]) dp[y][j]=max(dp[y^1][j],dp[y][j-a[i]]+b[i]);
            else dp[y][j]=dp[y^1][j];
        }
    }

    cout << dp[m&1][t] << '\n';
    return 0;
}