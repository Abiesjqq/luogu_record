#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4+9;

int m,n;
int p[N],t[N];
ll dp[2][N];

int main() {
    cin >> m >> n;
    for (int i=1;i<=n;i++) cin >> p[i] >> t[i];

    for (int i=1;i<=n;i++) {
        int y=i&1;
        for (int j=1;j<=m;j++) {
            if (j>=t[i]) dp[y][j]=max(dp[y^1][j],dp[y][j-t[i]]+p[i]);
            else dp[y][j]=dp[y^1][j];
        }
    }

    cout << dp[n&1][m] << '\n';
    return 0;
}