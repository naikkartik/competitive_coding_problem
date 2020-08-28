#include <bits/stdc++.h>
using namespace std;
int find_min(int a,int b,int c){
    return min(a,min(b,c));
}
int edit_distance_recurse(string s1,string s2,int m,int n){
    //base case 
    if(m==0) return n;
    if(n==0) return m;
    //if both character of s1 and s2 are equal do not increment the count
    if(s1[m]==s2[n]){
        return edit_distance_recurse(s1,s2,m-1,n-1);
    }
    int a =edit_distance_recurse(s1,s2,m-1,n);
    int b=edit_distance_recurse(s1,s2,m,n-1);
    int c=edit_distance_recurse(s1,s2,m-1,n-1);
    return 1+find_min(a,b,c);
}
int main(){
    string s1 ="sunday";
    string s2 ="saturday";
    int max_len = edit_distance_recurse(s1,s2,s1.length()-1,s2.length()-1);
    cout<<max_len<<endl;
}
