#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int lcs_recurse(string s1,string s2,int m,int n){
    if(m==0 or n==0){
        return 0;
    }
    if(s1[m]==s2[n]){
        return 1+lcs_recurse(s1,s2,m-1,n-1);
    }
    return max(lcs_recurse(s1,s2,m-1,n),lcs_recurse(s1,s2,m,n-1));
}
int main(){
    string s1 ="AGGTAB";
    string s2 ="GXTXAYB";
    int max_len = lcs_recurse(s1,s2,s1.length(),s2.length());
    cout<<max_len<<endl;
}