#include <bits/stdc++.h>
using namespace std;
int longest_palidrome_ss(string s,int start,int end){
    if(end<start){
        return 0;
    }
    if(start==end){
        return 1;
    }
    if(s[start]==s[end] and start+1==end){
        return 2;
    }
    if(s[start]==s[end]){
        return 2+longest_palidrome_ss(s,start+1,end-1);
    }
    int ans1 = longest_palidrome_ss(s,start+1,end);
    int ans2 =longest_palidrome_ss(s,start,end-1);
    return max(ans1,ans2);
}
int main(){
    string s="GEEKSFORGEEKS";
    int start =0;
    int end =s.length()-1;
    cout<<longest_palidrome_ss(s,start,end)<<endl;
    cout<<dp_solution_up_down(s)<<endl;
}
