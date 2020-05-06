// https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

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

long MaximumRectangularAreaInHistogram(long arr[], long n){
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
    return max;   
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    long n = A.size();
    long m = A[0].size();
    
    long l = m;
    long arr[l];
    for(int j=0; j<m; j++){
        arr[j] = (long)A[0][j];
    }
    long mx = MaximumRectangularAreaInHistogram(arr,l);
    
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j] == 0){
                arr[j] = 0;   
            }
            else{
                long temp = (long)A[i][j];
                arr[j] = arr[j] + temp;
            }
        }
        mx = max(mx,MaximumRectangularAreaInHistogram(arr,l));
    }
    mx = (int)mx;
    return mx;
}
    