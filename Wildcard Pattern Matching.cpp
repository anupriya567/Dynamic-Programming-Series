// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int wildCard(string pattern,string str);
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           cout<<wildCard(pat,text)<<endl;
   }
}
// } Driver Code Ends


/*You are required to complete this method*/
int wildCard(string pt,string str)
{
    int dpr=pt.size()+1;
    int dpc=str.size()+1;
    int dp[dpr][dpc];
    
    int i,j;
    for(i=dpr-1;i>=0;i--)
    {
        for(j=dpc-1;j>=0;j--)
        {
            if(i==dpr-1 && j== dpc-1)  // last block
            dp[i][j]=1;
            
            else if(i== dpr-1)  // last row
            dp[i][j]=0;
            else if(j== dpc-1)  // last column
            {
                if(pt[i]=='*')
                dp[i][j]=dp[i+1][j];
                else
                dp[i][j]=0;
            }
            
            else
            {
                if(pt[i]=='?')
                 dp[i][j]=dp[i+1][j+1];
                 
                 else if(pt[i]=='*')
                  dp[i][j]=dp[i+1][j]|dp[i][j+1];
                  
                  else if(pt[i]==str[j])
                   dp[i][j]=dp[i+1][j+1];
                   
                   else
                   {
                      dp[i][j]=0; 
                   }
            }
        }
    }
    return dp[0][0];
}