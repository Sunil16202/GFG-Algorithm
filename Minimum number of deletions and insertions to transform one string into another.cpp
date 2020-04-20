#include <bits/stdc++.h> 
using namespace std; 

void printMinDelAndInsert(string x, string y){
    int m = x.size();
    int n = y.size();
    int dp[m+1][n+1];
    for(int i=0; i<=n; i++){
        dp[0][i] = 0;
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
    int lcs = dp[m][n];
    int deletion = m - lcs;
    int insertion = n - lcs;
    cout<<deletion + insertion<<endl;
}
	
int main() 
{ 
    string str1 = "heap"; 
    string str2 = "pea"; 
    printMinDelAndInsert(str1, str2); 
    return 0; 
} 
