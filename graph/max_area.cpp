#include<bits/stdc++.h>
using namespace std;
bool vis[101][101];
int g[101][101];
int n,m;
bool safe(int i,int j)
{
    return i>=0 and j>=0 and i<n and j<m and g[i][j]==1 and !vis[i][j];
}

int c=0;
static int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
static int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void f(int i,int j)
{
 vis[i][j] = true;
    for(int ii=0;ii<8;ii++)
    {
        if(safe(i+x[ii],j+y[ii]))
        {
           
            c++;
            f(i+x[ii],j+y[ii]);            
        }
    }
    return;
}


int main()
 {
	//code
      int t;
      cin>>t;
      while(t--)
      {
        
        cin>>n>>m;
        memset(g,0,sizeof g);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            cin>>g[i][j];
        }
        
        int ans=INT_MIN;
        c=0;
        memset(vis,0,sizeof vis);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(g[i][j]){
                c=1;
                f(i,j);
                }
                ans = max(ans,c);
                
            }
        }
        
        cout<<ans<<endl;
      
      }
	return 0;
}
GeeksforGeeks
5th Floor, A-118,
Sector-136, Noida, Uttar Pradesh - 201305
feedback@geeksforgeeks.org
COMPANY
About Us
Careers
Privacy Policy
Contact Us
