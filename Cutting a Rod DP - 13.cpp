//https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

using namespace std;
#include <bits/stdc++.h>

int rodCutting(int rod[],int price[],int n){
    int dp[n+1][n+1];
    
    for(int i=0; i<=n; i++){
        dp[0][i] = 0;
    }
    for(int i=1; i<=n; i++){
        dp[i][0] = 0;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(rod[i-1] <= j){
               dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i][j-rod[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][n];
}

int main() {
	int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(price)/sizeof(price[0]);
    int rod[size];
    for(int i=0; i<size; i++){
        rod[i] = i+1;
    }
    cout<<rodCutting(rod,price,size)<<endl;
    return 0; 
}