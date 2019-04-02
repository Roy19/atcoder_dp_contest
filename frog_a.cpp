#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &h, int n){
    vector<int> dp(n, INT32_MAX);
    dp[0] = 0;

    for(int i = 1;i < n;i++){
        if(i >= 1){
            dp[i] = min(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
        }
        if(i >= 2){
            dp[i] = min(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
        }
    }

    return dp[n-1];
}

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(auto &x: h){
        cin >> x;
    }

    cout << solve(h, n) << endl;

    return 0;
}