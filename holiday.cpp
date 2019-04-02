#include <bits/stdc++.h>
using namespace std;

// recursive solution
int solve(vector<int> &a, vector<int> &b, vector<int> &c, int n, char dont_use){
    if(n <= 0)
        return 0;

    int maxPoints = 0;

    for(char activity = 'a';activity <= 'c';activity++){
        if(activity != dont_use){
            if(activity == 'a')
                maxPoints = max(maxPoints, solve(a, b, c, n-1, activity) + a[n-1]);
            else if(activity == 'b')
                maxPoints = max(maxPoints, solve(a, b, c, n-1, activity) + b[n-1]);
            else
                maxPoints = max(maxPoints, solve(a, b, c, n-1, activity) + c[n-1]);
        }
    }

    return maxPoints;
}

// dynamic programming solution
int solve(vector<int> &a, vector<int> &b, vector<int> &c, int n){
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));

    for(int i = 1;i <= n;i++){
        for(int activity = 0;activity < 3;activity++){
            
            for(int j = 0;j < 3;j++){
                if(j == activity)
                    continue;
                if(activity == 0)
                    dp[i][activity] = max(dp[i][activity], dp[i-1][j] + a[i-1]);
                else if(activity == 1)
                    dp[i][activity] = max(dp[i][activity], dp[i-1][j] + b[i-1]);
                else
                    dp[i][activity] = max(dp[i][activity], dp[i-1][j] + c[i-1]);
            }
        }
    }

    return *max_element(dp[n].begin(), dp[n].end());
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    int maxPoints = solve(a, b, c, n);

    cout << maxPoints << endl;
}