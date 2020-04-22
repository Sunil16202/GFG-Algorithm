//https://www.geeksforgeeks.org/longest-repeated-subsequence/

#include <bits/stdc++.h> 
using namespace std; 

string longestRepeatedSubSeq(string str){
    string x = str;
    string y= str;
    
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
            if(x[i-1] == y[j-1] && i!=j){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = m;
    int j = n;
    string output = "";
    while(i>0 && j>0){
        if(x[i-1] == y[j-1] && i!=j){
            output.push_back(x[i-1]);
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
    reverse(output.begin(), output.end());
    return output;
}

int main() 
{ 
	string str = "AABEBCDD"; 
	cout << longestRepeatedSubSeq(str)<<endl; 
	return 0; 
} 
