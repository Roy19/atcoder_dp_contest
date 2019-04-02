#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18 + 1;

// dynamic programming approach
ll knapsack(vector<pair<ll, int>> &wv, ll  w, ll sum_val){
    // dp[i] represents the minimum weight which can be formed by value i
    vector<ll> dp(sum_val + 1, INF);
    dp[0] = 0;

    for(int items = 0;items < wv.size();items++){
        for(int value_already = sum_val - wv[items].second;value_already >= 0;value_already--){
            dp[value_already + wv[items].second] = min(dp[value_already + wv[items].second], dp[value_already] + wv[items].first);
        }
    }

    ll ans = 0;
    
    for(int i = 0;i < dp.size();i++){
        if(dp[i] <= w)
            ans  = max(ans, (ll) i);
    }

    return ans;
}

int main(){
    ll n, w;
    ll sum_val = 0;
    cin >> n >> w;
    vector<pair<ll, int>> wv(n);

    for(int i = 0;i < n;i++){
        cin >> wv[i].first >> wv[i].second;
        sum_val += wv[i].second;
    }

    cout << knapsack(wv, w, sum_val) << endl;

    return 0;
}