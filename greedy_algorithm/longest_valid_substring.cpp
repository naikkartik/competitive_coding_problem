#include <bits/stdc++.h>
using namespace std; 
int find_longest_valid_substring(string str){
    stack<int>stk;
    stk.push(-1);
    int maxi =0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            stk.push(i);
        }
        else{
            stk.pop();
            if(!stk.empty()){
                maxi = max(maxi,(i-stk.top()));
            }
            else{
                stk.push(i);
            }
            
        }
    }
    return maxi;if(s.length()<=0){
        return 0;
    }
    stack<int>stk;
    stk.push(-1);
    int ans =0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            stk.push(i);
        }
        else{
            stk.pop();
            if(!stk.empty()){
                ans =max(ans,i-stk.top());
            }
            else{
                stk.push(i);
            }
        }
    }
    return ans;
}
int longestValidParentheses(string s){
    
}
int main(){
    string str;
    cin>>str;
    int ans =find_longest_valid_substring(str);
    cout<<ans<<endl;
}