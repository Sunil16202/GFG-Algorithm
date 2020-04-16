// https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
#include <bits/stdc++.h> 
using namespace std; 

int countSubsetSum(int arr[], int n, int sum){
    int dp[n+1][sum+1];
    for(int i=1; i<=sum; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
    
}

int main() 
{ 
	int arr[] = { 3, 3, 3, 3 }; 
	int n = 4; 
	int sum = 6; 

	cout << countSubsetSum(arr,n,sum)<<endl; 

	return 0; 
} 
