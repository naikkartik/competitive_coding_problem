#include <bits/stdc++.h>
using namespace std;
long long int solution(long long int n){
    long long count = 0;
    long long int ans =0;
    while(n>0){
        count++;
        n = n>>1;
        cout<<n<<endl;
    }
    return ans;
}
int main(){
    long long int n;
    cin>>n;
    long long int ans = solution(n);
    //cout<<ans<<endl;
}

