#include <bits/stdc++.h>
using namespace std;


int main(){
    string str;
    cin>>str;
    stack<char>s;
    int k;
    cin>>k;
    for(int i=0;i<str.length();i++){
        while(!s.empty() and s.top()>str[i] and k>0){
            s.pop();
            k--;
        }
        s.push(str[i]);
    }
    while(k>0 and !s.empty()){
        k--;
        s.pop();
    }
    string result;
    while(!s.empty()){
        result = s.top()+result;
        s.pop();
    }
    while(result[0]=='0'){
        result= result.substr(1);
    }
    cout<<result<<endl;
}