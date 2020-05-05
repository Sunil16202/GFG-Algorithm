//https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0

#include <bits/stdc++.h>
using namespace std;


vector<long> nearestsmallerright(long arr[], long n){
    long psudo_left = n;
    
    vector<long> v;
    stack<pair<long, long>> s;
    
    for(long i=n-1; i>=0; i--){
        if(s.size() == 0){
            v.push_back(psudo_left);
        }
        else if(s.size() > 0 && s.top().first < arr[i]){
            v.push_back(s.top().second);
        }

        else if(s.size() > 0 && s.top().first >= arr[i]){
            while(s.size() > 0 && s.top().first >= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(psudo_left);
            }
            else{
                v.push_back(s.top().second);
            }

        }
        s.push({arr[i],i});

    }
    reverse(v.begin(), v.end());
    return v;
}


vector<long> nearestsmallerleft(long arr[], long n){
    long psudo_left = -1;
    
    vector<long> v;
    stack<pair<long, long>> s;
    
    for(long i=0; n>i; i++){
        if(s.size() == 0){
            v.push_back(psudo_left);
        }
        else if(s.size() > 0 && s.top().first < arr[i]){
            v.push_back(s.top().second);
        }

        else if(s.size() > 0 && s.top().first >= arr[i]){
            while(s.size() > 0 && s.top().first >= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(psudo_left);
            }
            else{
                v.push_back(s.top().second);
            }

        }
        s.push({arr[i],i});

    }
    return v;
}


void MaximumRectangularAreaInHistogram(long arr[], long n){
    vector<long> left = nearestsmallerleft(arr, n);
    vector<long> right = nearestsmallerright(arr, n);
    vector<long> width;
    vector<long> area;
    for(long i=0; i<n; i++){
        width.push_back(right[i] - left[i] - 1);
    }
    
    for(long i=0; i<n; i++){
        area.push_back(width[i]*arr[i]);
    }
    long max = 0;
    for(long i=0; i<n; i++){
        if(area[i] > max){
            max = area[i];
        }
    }
    cout<<max<<endl;

    
}
int main() {
    //code
    long t;
    cin >> t;
    for(long i=0; i<t; i++){
        long n;
        cin >> n;
        long arr[n];
        for(long j=0; j<n; j++){
            cin >> arr[j];
        }
        MaximumRectangularAreaInHistogram(arr,n);
    }
    return 0;
}