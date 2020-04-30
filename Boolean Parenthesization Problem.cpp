//https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
//https://www.interviewbit.com/problems/evaluate-expression-to-true/


using namespace std; 
#include <bits/stdc++.h>

#define mod 1003

static unordered_map<string, int> mp;

int noOfexpT(string str, int i, int j, bool istrue){
    if(i > j){
        return 0;
    }
    if(i == j){
        if(istrue == true){
          return str[i] == 'T';
        }
        else{
            return str[i] == 'F';
        }
    }
    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(istrue));
    
    if(mp.find(temp) != mp.end()){
        return mp[temp];
    }
    
    int ans = 0;
    for(int k = i+1; k<=j-1; k=k+2){
        
        int lt;
        int lf;
        int rt;
        int rf;
        
        string left_t = to_string(i);
        left_t.push_back(' ');
        left_t.append(to_string(k-1));
        left_t.push_back(' ');
        left_t.append(to_string(true));
         
        if(mp.find(left_t) != mp.end()){
            lt = mp[left_t];
        }
        else{
            lt = noOfexpT(str, i, k-1, true);
        }
        
        string left_f = to_string(i);
        left_f.push_back(' ');
        left_f.append(to_string(k-1));
        left_f.push_back(' ');
        left_f.append(to_string(false));
        
        if(mp.find(left_f) != mp.end()){
            lf = mp[left_f];
        }
        else{
            lf = noOfexpT(str, i, k-1, false);
        }
        
        
        string right_t = to_string(k+1);
        right_t.push_back(' ');
        right_t.append(to_string(j));
        right_t.push_back(' ');
        right_t.append(to_string(true));
         
        if(mp.find(right_t) != mp.end()){
            rt = mp[right_t];
        }
        else{
            rt = noOfexpT(str, k+1, j, true);
        }
        
        string right_f = to_string(k+1);
        right_f.push_back(' ');
        right_f.append(to_string(j));
        right_f.push_back(' ');
        right_f.append(to_string(false));
         
        if(mp.find(right_f) != mp.end()){
            rf = mp[right_f];
        }
        else{
            rf = noOfexpT(str, k+1, j, false);
        }
        

        //find the number of ways for the operator
        if(str[k] == '&'){
            if(istrue == true){
                ans = (ans + (lt*rt))%mod;
            }
            else{
                ans = (ans + (lt*rf) + (lf*rt) + (lf*rf))%mod;
            }
        }
        else if(str[k] == '|'){
            if(istrue == true){
                ans = (ans + (lt*rt) + (lt*rf) + (lf*rt))%mod;
            }
            else{
                ans = (ans + (lf*rf))%mod;
            }
        }
        else if(str[k] == '^'){
            if(istrue == true){
                ans = (ans + (lf*rt) + (lt*rf))%mod;
            }
            else{
                ans = (ans + (lt*rt) + (lf*rf))%mod;
            }
        }
    }
    mp[temp] = ans;
    return ans;
}

int main(){
    string str = "T&T|F|F^F^T^T^T&T^F^T&F|F^F^F&F&F|F|F^F^T|T&T";
    int n = str.size();
    cout<<noOfexpT(str,0,n-1,true)<<endl;
    return 0;

}
