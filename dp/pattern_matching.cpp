#include <bits/stdc++.h>
using namespace std; 
//i is for str 
//j is for pattern
bool Matched(int m,int n,string str,string pattern){
    if(m==0 and n==0){
        return true;
    }
    if(m!=0 and n==0){
        return false;
    }
    if(m==0 and n!=0){
        return false;
    }
    if(pattern[n]=='*'){
        char prev = pattern[n-1];
        if(prev=='.'){
            prev =str[n];
        }
        if(str[m]!=prev){
            Matched(m-1,n-1,str,pattern);
        }
        bool ans =false;
        int i =m;
        while(str[i]==prev){
            ans =ans or Matched(i-1,n-1,str,pattern);
            i--;
        }
        return ans;
    }
    if(pattern[n]=='.'){
        return Matched(m-1,n-1,str,pattern);
    }
    if(pattern[n]==str[m]){
        return Matched(m-1,n-1,str,pattern);
    }
    return false;
}
int main(){
    string pattern,str;
    cin>>str>>pattern;
    bool ans = Matched(str.length()-1,pattern.length()-1,str,pattern);
    if(ans){
        cout<<"Matched"<<endl;

    }
    else{
        cout<<"Not matched"<<endl;
    }
}