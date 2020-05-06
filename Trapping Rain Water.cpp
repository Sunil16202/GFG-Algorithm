//https://practice.geeksforgeeks.org/problems/trapping-rain-water/0
#include <bits/stdc++.h>
using namespace std;

int TrappingRainWater(int arr[], int n){
    int maxL[n];
    int maxR[n];
    int width[n];
    
    maxL[0] = arr[0];
    maxR[n-1] = arr[n-1];
    
    for(int i=1; i<n; i++){
        maxL[i] = max(arr[i],maxL[i-1]);
    }
    for(int i=n-2; i>=0; i--){
        maxR[i] = max(arr[i],maxR[i+1]);
    }
    for(int i=0; i<n; i++){
        width[i] = min(maxR[i],maxL[i]) - arr[i];
    }
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + width[i];
    }
    return sum;
    
}
int main() {
    //code
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin >>n;
        int arr[n];
        for(int j=0; j<n; j++){
            cin >> arr[j];
        }
        cout<<TrappingRainWater(arr,n)<<endl;
    }
    return 0;
}