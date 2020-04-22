//https://leetcode.com/problems/shortest-common-supersequence/

using namespace std;
#include <bits/stdc++.h>

string shortestCommonSupersequence(string str1, string str2) {
        string x = str1;
        string y = str2;
        
        int m = x.size();
        int n = y.size();
        int dp[m+1][n+1];
        
        for(int i=0; i<=n; i++){
            dp[0][i]  = 0;
        }
        for(int i=1; i<=m; i++){
            dp[i][0] = 0;
        }
    
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i = m;
        int j = n;
        string scs = "";
        while(i>0 && j>0){
            if(x[i-1] == y[j-1]){
                scs.push_back(x[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    scs.push_back(x[i-1]);
                    i--;
                }
                else{
                    scs.push_back(y[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
            scs.push_back(x[i-1]);
            i--;
        }
        while(j>0){
            scs.push_back(y[j-1]);
            j--;
        }
        reverse(scs.begin(), scs.end());
        return scs;
    }

int main(){
    string x;
    string y;
    cin >> x;
    cin >> y;
    cout<<shortestCommonSupersequence(x,y)<<endl;

}