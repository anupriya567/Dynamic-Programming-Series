// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int max(int a,int b)
{
    return a>b?a:b;
}
int knapSack(int W, int w[], int p[], int n) 
{ 
    
    vector< vector<int> >dp(n+1,vector<int> (W+1,0) ); // initialize with 0
   // dp[0][0]=0;
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=W;j++)
        {
          if(j<w[i-1] ) 
          dp[i][j]=dp[i-1][j];
          
          else
                 //not take item,take item
          dp[i][j]=max(dp[i-1][j],p[i-1]+dp[i-1][j-w[i-1]]);
          
          
        }
    }
    return dp[n][W];
   // Your code here
}





// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends