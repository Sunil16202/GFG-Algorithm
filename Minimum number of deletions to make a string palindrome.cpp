//https://www.geeksforgeeks.org/minimum-number-deletions-make-string-palindrome/

#include <bits/stdc++.h> 
using namespace std; 

int minimumNumberOfDeletions(string x, string y, int m, int n){
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
    int minimumNumberOfDeletions_in_string = m - lcs;
    return minimumNumberOfDeletions_in_string;
    
}

int main() 
{ 
	string str = "geeksforgeeks";
	string y = str;
	reverse(y.begin(), y.end());
	cout << "Minimum number of deletions = "
		<< minimumNumberOfDeletions(str,y,str.size(),y.size()); 
	return 0; 
} 
