#include <iostream>
using namespace std;
int makeEqualLength(string &str1, string &str2) 
{ 
    int len1 = str1.size(); 
    int len2 = str2.size(); 
    if (len1 < len2) 
    { 
        for (int i = 0 ; i < len2 - len1 ; i++) 
            str1 = '0' + str1; 
        return len2; 
    } 
    else if (len1 > len2) 
    { 
        for (int i = 0 ; i < len1 - len2 ; i++) 
            str2 = '0' + str2; 
    } 
    return len1; // If len1 >= len2 
} 
string addBitStrings(string a,string b){
    string result;
    int length = makeEqualLength(a,b);
    int carry =0;
    for(int i = length-1;i>=0;i--){
        int firstBit = a.at(i)-'0';
        int secondBit=b.at(i)-'0';
        int sum = (firstBit^secondBit^carry)+'0';
        result = (char) sum +result;
        carry = (firstBit &secondBit)|(firstBit|carry)|(secondBit&carry);
    }
    if(carry) {
        result = '1'+result;
    }
    return result;

}
int main(){
    string a,b;
    cin>>a>>b;
    string result = addBitStrings(a,b);
    cout<<result<<endl;
}