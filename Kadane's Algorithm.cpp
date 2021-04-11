// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array

//using Kadane's algo. we would be able to calculate the max subarray sum in O(n).
int maxSubarraySum(int arr[], int n){
    
    int currs=arr[0];
    int overalls=arr[0];
    int i;
    for(i=1;i<n;i++)
    {
        if(arr[i]+currs>= arr[i])
        currs+=arr[i];
        
        if(arr[i]+currs < arr[i])
        currs=arr[i];
        
        if(currs>overalls)
        overalls=currs;
    }
    
    return overalls;
}

// { Driver Code Starts.

int main()
{
    int test,n;
    
    cin>>test; //input testcases
    while(test--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends