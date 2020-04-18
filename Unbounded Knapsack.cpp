//https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/

#include<bits/stdc++.h> 
using namespace std; 

 int unboundedKnapsack(int val[], int weight[], int n, int sum){
     int dp[n+1][sum+1];
     for(int i=0; i<=sum; i++){
         dp[0][i] = 0;
     }
     for(int i=1; i<=n; i++){
         dp[i][0] = 0;
     }
     for(int i=1; i<=n; i++){
         for(int j=1; j<=sum; j++){
             if(weight[i-1] <= j){
                 dp[i][j] = max(dp[i-1][j], (val[i-1] + dp[i][j-weight[i-1]]));
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
    int sum = 100; 
    int val[] = {10, 30, 20}; 
    int weight[] = {5, 10, 15}; 
    int n = sizeof(val)/sizeof(val[0]); 

    cout << unboundedKnapsack(val, weight, n, sum)<<endl; 

    return 0; 
} 
