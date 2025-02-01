#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N =3e5+9;

int n,m;
int v[30],p[30];
ll dp[N]; //dp[i][j]表示到第i件物品花j元时,乘积之和的最大值

int main() {
    cin >> n >> m;
    for (int i=1;i<=m;i++) cin >> v[i] >> p[i];

    for (int i=1;i<=m;i++) {
        for (int j=n;j>=v[i];j--) {
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]*p[i]);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}