//https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

using namespace std;
#include <bits/stdc++.h>

void minCoins(int coins[], int n, int sum){
    //to avoid the stack over flow
    int infinity = INT_MAX-1;
    int dp[n+1][sum+1];
    for(int i=0; i<=sum; i++){
        dp[0][i] = infinity;
    }
    for(int i=1; i<=n; i++){
        dp[i][0] = 0;
    }
    
    vector<int> output;
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
    
    //To Print the Coins
    int i = n;
    int j = sum;
    while(i>0 && j>0){
        
        //If the dp value is equal to above cell then it means it wasnt chosen 
       // so skip it and move to next coin.
        if(dp[i][j] == dp[i-1][j]){
            i--;
        }
        else{
            cout<<coins[i-1]<<" ";
            //Subtract from the coin to get new balance amount.
            j = j - coins[i-1];
        }
    }
    cout<<endl;
    
}

int main() 
{ 
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int n = sizeof(coins)/sizeof(coins[0]); 
        int sum;
        cin >> sum;
        minCoins(coins, n, sum); 
    }

    return 0; 
} 