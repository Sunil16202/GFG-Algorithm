//https://leetcode.com/problems/scramble-string/

#include <bits/stdc++.h>
using namespace std; 
    
unordered_map<string, bool> mp;
bool isScramble(string a, string b) {
    if(a.compare(b) == 0){
        return true;
    }
    if(a.length() <= 1){
        return false;
    }
    string key = a;
    key.push_back(' ');
    key.append(b);
        
    if(mp.find(key) != mp.end()){
        return mp[key];
    }
        
    int n = a.length();
    bool flag = false;
    for(int i=1; i<n; i++){
        bool cond1 = (isScramble(a.substr(0,i), b.substr(n-i,i)) == true) &&
                     (isScramble(a.substr(i,n-i), b.substr(0,n-i)));
        bool cond2 = (isScramble(a.substr(0,i), b.substr(0,i)) == true) &&
                     (isScramble(a.substr(i,n-i), b.substr(i,n-i)));
        if(cond1 || cond2){
            flag = true;
            break;
        }
    }
    mp[key] = flag;
    return flag;                      
    }
int main(){
    string a = "great";
    string b = "rgeat";
    if(isScramble(a,b)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
