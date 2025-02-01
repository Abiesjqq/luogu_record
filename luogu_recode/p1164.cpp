#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3+9;

int n,m;
int a[N];
int dp[N]; //由dp[109][N]压缩而来,其中dp[i][j]表示到第i个为止花j的钱的方法数

int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];

    dp[0]=1; //初始化
    for (int i=1;i<=n;i++) {
        for (int j=m;j>=a[i];j--) {
            dp[j]+=dp[j-a[i]]; //方法数相加
        }
    }

    cout << dp[m] << '\n';
    return 0;
}