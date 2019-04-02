#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &h, int n, int k){
    vector<int> dp(n, INT32_MAX);
    dp[0] = 0;

    for(int i = 1;i < n;i++){
        for(int j = 1;j <= k;j++){
            if(i >= j){
                dp[i] = min(dp[i], dp[i-j] + abs(h[i]- h[i-j]));
            }
        }
    }

    return dp[n-1];
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(auto &x: h){
        cin >> x;
    }

    cout << solve(h, n, k) << endl;

    return 0;
}