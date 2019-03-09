#include <bits/stdc++.h>
using namespace std;

// recursive approach
long long knapsack(vector<pair<int, long long>> &wv, int w, int i){
    if(w < 0)
        return LONG_LONG_MIN;
    if(w == 0 or i < 0){
        return 0;
    }

    return max(knapsack(wv, w - wv[i].first, i-1) + wv[i].second,
                knapsack(wv, w, i-1));
}

// dynamic programming approach
long long knapsack1(vector<pair<int, long long>> &wv, int w){
    vector<vector<long long>> dp(wv.size() + 1, vector<long long>(w + 1, 0));

    for(int i = 0;i <= wv.size();i++){
        for(int wt = 0;wt <= w;wt++){
            if(i == 0 || wt == 0)
                dp[i][wt] = 0;
            else if(wv[i-1].first <= wt){
                dp[i][wt] = max(wv[i-1].second + dp[i-1][wt - wv[i-1].first], dp[i-1][wt]);
            }else{
                dp[i][wt] = dp[i-1][wt];
            }
        }
    }

    return dp[wv.size()][w];
}


// dynamic programming approach, memory optimized
long long knapsack2(vector<pair<int, long long>> &wv, int w){
    vector<long long> dp(w + 1, 0);

    for(int i = 0;i < wv.size();i++){
        // wt is the weight of items already considered in knapsack
        for(int wt = w-wv[i].first;wt >= 0;wt--){
            // now to that already filled knapsack we want to add item with weight w[i] or else not
            dp[wt + wv[i].first] = max(dp[wt + wv[i].first], wv[i].second + dp[wt]);
        }
    }

    long long ans = 0;
    for(int i = 0;i <= w;i++){
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main(){
    int n, w;
    cin >> n >> w;
    vector<pair<int, long long>> wv(n);

    for(int i = 0;i < n;i++){
        cin >> wv[i].first >> wv[i].second;
    }

    cout << knapsack2(wv, w) << endl;

    return 0;
}