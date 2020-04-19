using namespace std;

#include <bits/stdc++.h>
//https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

int minCoins(int coins[], int n, int sum){
    //to avoid the stack over flow
    
    int infinity = INT_MAX-1;
    
    int dp[n+1][sum+1];
    for(int i=0; i<=sum; i++){
        dp[0][i] = infinity;
    }
    for(int i=1; i<=n; i++){
        dp[i][0] = 0;
    }
    
    //Unbounded Knapsack
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(coins[i-1]<=j){
                dp[i][j] = min(dp[i][j- coins[i-1]]+1, dp[i-1][j]);
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
	int coins[] = {25, 10, 5};
	int m = sizeof(coins)/sizeof(coins[0]); 
	int V =30;
	cout<< minCoins(coins, m, V)<<endl;
	return 0; 
} 