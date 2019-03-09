#include <bits/stdc++.h>
using namespace std;

string lcs(string &a, string &b){
    string ans = "";
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
    vector<vector<char>> direction(a.length() + 1, vector<char>(b.length() + 1, '\\'));

    for(int i = 1;i <= a.length();i++){
        for(int j = 1;j <= b.length();j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                direction[i][j] = '\\';
            }else if(dp[i-1][j] >= dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                direction[i][j] = '|';
            }else{
                dp[i][j] = dp[i][j-1];
                direction[i][j] = '-';
            }
        }
    }

    for(int i = a.length(), j = b.length();i >= 1 and j >= 1;){
        if(direction[i][j] == '\\'){
            ans += b[j-1];
            --j;
            --i;
        }else if(direction[i][j] == '-'){
            --j;
        }else{
            --i;
        }
    }

    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);

    cout << lcs(a, b) << endl;

    return 0;
}