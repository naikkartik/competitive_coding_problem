#include <bits/stdc++.h>
using namespace std;
void solution(int k,string str){
    if(k==0){
        cout<<str<<endl;
        return;
    }
    solution(k-1,str+'0');
    solution(k-1,str+'1');
}
int main(){
    int k;
    cin>>k;
    solution(k,"");
}