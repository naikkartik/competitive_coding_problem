#include <bits/stdc++.h>
using namespace std;

#define R 5
#define C 4

bool isValid(int x,int y1,int y2){
    return (x>=0 && x<R and y1>=0 and y1<C and y2>=0 and y2<C);
}

int getMaxUtil(int arr[R][C],int mem[R][C][C],int x,int y1,int y2){
    if(!isValid(x,y1,y2)){
        return INT_MIN;
    }
    if(x==R-1 and y1==0 and y2 == C-1){
        if(y1==y2) return arr[x][y1];

        return arr[x][y1]+arr[x][y2];
    }
    int temp =INT_MIN;
    if(y1==y2){
        temp = arr[x][y1];
    }
    else{
        temp =arr[x][y1]+arr[x][y2];
    }
    if(mem[x][y1][y2]!=-1){
        return mem[x][y1][y2];
    }
    int ans =INT_MIN;
    ans =max(ans,temp+getMaxUtil(arr,mem,x+1,y1,y2+1));
    ans =max(ans,temp+getMaxUtil(arr,mem,x+1,y1,y2-1));
    ans =max(ans,temp+getMaxUtil(arr,mem,x+1,y1,y2));
    ans =max(ans,temp+getMaxUtil(arr,mem,x+1,y1+1,y2+1));
    ans =max(ans,temp+getMaxUtil(arr,mem,x+1,y1+1,y2-1));
    ans =max(ans,temp+getMaxUtil(arr,mem,x+1,y1+1,y2));
    ans =max(ans,temp+getMaxUtil(arr,mem,x+1,y1-1,y2+1));
    ans =max(ans,temp+getMaxUtil(arr,mem,x+1,y1-1,y2-1));
    ans =max(ans,temp+getMaxUtil(arr,mem,x+1,y1-1,y2));
    return ans;

}
int geMaxCollection(int arr[R][C]){
    int mem[R][C][C];
    memset(mem,-1,sizeof(mem));
    return getMaxUtil(arr,mem,0,0,C-1);
}
int main()
{
int arr[R][C] = {{3, 6, 8, 2},
                {5, 2, 4, 3},
                {1, 1, 20, 10},
                {1, 1, 20, 10},
                {1, 1, 20, 10},
                };
cout << "Maximum collection is " << geMaxCollection(arr);
return 0;
}