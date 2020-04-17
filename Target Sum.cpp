//https://leetcode.com/problems/target-sum/
using namespace std;
#include <bits/stdc++.h> 
#include <vector>

int findTargetSumWays(vector<int>& nums, int S){
    int arr_sum = 0;
        for(int i=0; i<nums.size(); i++){
            arr_sum = arr_sum + nums[i];
        }
        if(arr_sum < S){
            return 0;
        }
       
        int sum = S + arr_sum;
        if(sum%2!=0){
            return 0;
        }
        sum = sum/2;
        
        //have to find the number of subset equal to sum
        int n= nums.size();
        
        int dp[n+1][sum+1];
        for(int i=1; i<=sum; i++){
            dp[0][i] = 0;
        }
        
        //intilization
        int temp = 0;
        for(int i=0; i<=n; i++){
            if(i==0){
                dp[i][0] = 1;
            }
            else{
                if(nums[i-1] == 0){
                    temp ++;
                    dp[i][0] = pow(2,temp);
                }
                else{
                    dp[i][0] = pow(2,temp);
                }
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];       
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    int S;
    cin >> S;
    cout<<findTargetSumWays(v,S)<<endl;

}