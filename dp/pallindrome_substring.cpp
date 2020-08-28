#include <bits/stdc++.h>
using namespace std; 
bool check_pallindrome(int i,int j,string str){
    while(i<=j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return false;
}
int find_str(int i,int j,string str){
    if(i>j){
        return 0;
    }
    if(i==j){
        return 1;
    }
    if(j==i+1){
        return str[i]==str[j];
    }
    if(check_pallindrome(i,j,str)){
        return find_str(i+1,j,str)+find_str(i,j-1,str)+1-find_str(i+1,j-1,str);
    }
    return find_str(i+1,j,str)+find_str(i,j-1,str)-find_str(i+1,j-1,str);
}


int main(){
    string str;
    cin>>str;
    int ans = find_str(0,str.length()-1,str);
    cout<<ans<<endl;
}