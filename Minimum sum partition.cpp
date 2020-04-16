//https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

using namespace std;
#include <bits/stdc++.h> 
#include <vector>

int subSetSum(int arr[], int n, int sum){
    
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
    
    //creating the subsetsum array
    vector<int> v;
    for(int i=0; i<=sum; i++){
        if(dp[n][i] == true && (i<=(sum/2))){
            v.push_back(i);
        }
    }
  
    int ans = sum - 2*v[v.size()-1];
    return ans;
}

int main() {
    //code
    int t;
    cin >>t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        int arr[n];
        for(int j=0; j<n; j++){
            cin >> arr[j];
        }
        int sum = 0;
        for(int j=0; j<n; j++){
            sum = sum + arr[j];
        }
        cout<<subSetSum(arr,n,sum)<<endl;;
    }
    return 0;
}