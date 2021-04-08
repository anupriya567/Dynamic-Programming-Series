// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

// this ques. is same as LIS but a slight diff. is that in LIS when an ele. is less than curr ele.
// but its index is greater than curr value index so we will not include that ele. in the LIS upto
// that ele.But in this ques we will include that too so we will sort the arr.
// eg:
// {5  24 , 39 60 , 15 28 , 27 40 , 50 90 , 41 45}  acc.to LIS=> ans=3
// { 5  24 , 15 28 , 27 40 ,41 45 ,39 60 , 50 90}   after sort=> ans=4


bool compareinterval(struct val a,struct val b)
{
    return a.first < b.first;
}

int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,compareinterval);
    int dp[n];
    dp[0]=1;
    int i,j;
    int ans=0;
    for(i=0;i<n;i++)
    {
        int mx=0;
      for(j=0;j<i;j++)
      {
          if(p[j].second<p[i].first)
          {
              if(dp[j]>mx)
              mx=dp[j];
          }
      }
      dp[i]=mx+1;
      if(dp[i]>ans)
      ans=dp[i];
    }
    
return ans;
}