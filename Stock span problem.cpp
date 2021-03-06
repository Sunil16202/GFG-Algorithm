//https://practice.geeksforgeeks.org/problems/stock-span-problem/0


#include <bits/stdc++.h>
using namespace std;


void stockspan(int arr[], int n){
    vector<int> v;
    stack<pair<int, int>> s;
    
    for(int i=0; i<n; i++){
        if(s.size() == 0){
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top().first > arr[i]){
            v.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first <= arr[i]){
            while(s.size() > 0 && s.top().first <= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    for(int i=0; i<n; i++){
        cout<<i-v[i]<<" ";
    }
    cout<<endl;
    
}

int main() {
	//code
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int j=0; j<n; j++){
	        cin >> arr[j];
	    }
	    stockspan(arr,n);
	}
	return 0;
}