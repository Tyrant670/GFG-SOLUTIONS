//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    const int mod=1e9+7;
    long long int count(int n , vector<long long int>&dp){
      if(n<0) return 0;
      if(n==0) return 1;
      if(dp[n] != -1)return dp[n];
      return dp[n]=(count(n-3,dp)+count(n-2,dp)+count(n-1,dp))%mod;  
    }
    
    long long countWays(int n)
    {
        vector<long long int> dp(n+1,-1);
        return count(n,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends