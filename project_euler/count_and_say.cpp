#include <bits/stdc++.h>
using namespace std;
string solution(int n){
    string s ="1";
    for(int i=1;i<n;i++){
        //count the occurance of each character
        int count = 1;
        int result;
        char cur = s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==cur){
                count++;
            }
            else{
                string temp = to_string(count);
                result=result+temp;
                cur = s[i];
                count =1;
            }
        }
        result+char(count+'0');
        result+cur;
        s=result;
        cout<<result<<endl;
    }
    return s;
}
int main(){
    int n;
    cin>>n;
    string ans= solution(n);
    cout<<ans<<endl;
}
