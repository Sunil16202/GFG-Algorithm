//https://www.geeksforgeeks.org/printing-longest-common-subsequence/

using namespace std; 
#include <bits/stdc++.h>


void printLcs(string x, string y, int m, int n){
    int dp[m+1][n+1];
    for(int i=0; i<=n; i++){
        dp[0][i] = 0;
    }
    for(int i=1; i<=m; i++){
        dp[i][0] = 0;
    }
    //lcs matrix
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
    
    //to print the lcs
    int i = m;
    int j = n;
    string lcs = "";
    while( i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            lcs.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout<<lcs<<endl;
    
    
}

int main() 
{ 
    char X[] = "acbcf"; 
    char Y[] = "abcdaf"; 
    int m = strlen(X); 
    int n = strlen(Y); 
    printLcs(X, Y, m, n); 
    return 0; 
} 
