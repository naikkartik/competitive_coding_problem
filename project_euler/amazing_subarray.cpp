#include <bits/stdc++.h>
using namespace std;
int solution(string str){
    map<char,bool>vowel;
    vowel['A']=true;
    vowel['E']=true;
    vowel['I']=true;
    vowel['O']=true;
    vowel['U']=true;
    vowel['a']=true;
    vowel['e']=true;
    vowel['i']=true;
    vowel['o']=true;
    vowel['u']=true;
    int count = 0;
    for(int i=0;i<str.length();i++){
        if(vowel.find(str[i])!=vowel.end()){
            cout<<"at index "<<i<<" "<<str[i]<<endl;
            count+=(str.length()-i);
        }
    }
    return count;
}
int main(){
 string str;
 cin>>str;
 int ans = solution(str);
 cout<<ans<<endl;   
}