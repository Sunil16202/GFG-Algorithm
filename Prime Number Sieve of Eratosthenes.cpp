//https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes/0

#include <bits/stdc++.h>
using namespace std;

void findprime(int n){
    int prime[n+1];
    for(int i=0; i<=n; i++){
        prime[i]=1;
    }
    prime[0] = 0;
    prime[1] = 0;
    
    for(int i=2; i<=sqrt(n); i++){
        if(prime[i]==1){
            for(int j=2; i*j<=n; j++){
                prime[i*j] = 0;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(prime[i]==1){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main() {
    //code
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        findprime(n);
    }
    return 0;
}