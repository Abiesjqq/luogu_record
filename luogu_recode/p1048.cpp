//采药,01背包
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 102;

int T,M;
ll dp[1010];
ll t[N],v[N];

int main() {
    cin >> T >> M;
    for (int i=1;i<=M;i++) cin >> t[i] >> v[i];

    for (int i=1;i<=M;i++) {
        for (int j=T;j>=t[i];j--) {
            dp[j]=max(dp[j],dp[j-t[i]]+v[i]);
        }
    }

    cout << dp[T] << '\n';
    return 0;
}