//https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

#include <bits/stdc++.h> 
using namespace std; 

bool isSubsetSum(int arr[], int n, int sum){
    bool dp[n+1][sum+1];
    for(int i=1; i<=sum; i++){
        dp[0][i] = false;
    }
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
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
    int arr[] = {3, 34, 4, 12, 5, 2}; 
    int sum = 9; 
    int n = 6; 
    if (isSubsetSum(arr, n, sum)) {
        cout<<"Found a subset with given sum"<<endl; 
    }
    else{
        cout<<"No subset with given sum"<<endl;
    }
    return 0;
} 
