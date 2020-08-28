#include <bits/stdc++.h>
using namespace std;
int solution(string haystack,string niddle){
    int i=0;
    while(i<haystack.size()){
        if(haystack[i]==niddle[0]){
            int k =i;
            int j=0;
            while(haystack[k]==niddle[j]){
                k++;
                j++;
            }
            if(j>=niddle.size()){
                return i;
            }
        }
        i++;
    }
    return -1;
}
int main(){
    string haystack;
    string niddle;
    cin>>haystack;
    cin>>niddle;
    int ans = solution(haystack,niddle);
    cout<<ans<<endl;
}
