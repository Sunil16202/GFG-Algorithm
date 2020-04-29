//https://www.interviewbit.com/problems/palindrome-partitioning-ii/

#include<bits/stdc++.h> 
using namespace std; 

bool isPalindrome(string str, int i, int j){
    if(i == j){
        return true;
    }
    if(i > j){
        return true;
    }
    
    while(i < j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int Palindromicpatitioning(string str, int i, int j, int ** dp){
    if(i>=j){
        return 0;
    }
    if(isPalindrome(str,i,j)){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int min = INT_MAX;
    for(int k=i; k<=(j-1); k++){
        int left;
        int right;
        if(dp[i][k] != -1){
            left = dp[i][k];
        }
        else{
            left = Palindromicpatitioning(str,i,k,dp);
        }
        
        if(dp[k+1][j] != -1){
            right = dp[k+1][j];
        }
        else{
            right = Palindromicpatitioning(str,k+1,j,dp);
        }
        
        int temp = 1 + left + right;
        if(temp < min){
            min = temp;
        }
    }
    dp[i][j] = min;
    return dp[i][j];
}



int minCut(string A) {
    int n = A.size();
        int ** dp = new int*[n+1];
        for(int i=0; i<=n; i++){
            dp[i] = new int[n+1];
        }
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                dp[i][j] = -1;
            }
        }
    return Palindromicpatitioning(A,0,n-1,dp);
}
int main(){
    string str;
    cin >> str;
    cout<<minCut(str)<<endl;

}
