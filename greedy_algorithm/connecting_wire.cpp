#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int white[n];
    int black[n];
    for(int i=0;i<n;i++){
        cin>>white[i];
    }
    for(int i=0;i<n;i++){
        cin>>black[i];
    }
    sort(white,white+n);
    sort(black,black+n);
    int count =0;
    for(int i=0;i<n;i++){
        count+=abs(white[i]-black[i]);
    }
    cout<<count<<endl;
}
