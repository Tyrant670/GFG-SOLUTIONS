//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    #define ll long long
    const int mod=1e9+7;
    
    ll power(ll a, ll n)
    {
      ll res = 1;
      while(n)
      {
        if(n % 2) res = (res * 1LL * a) % mod;
        n/= 2;
        a = (a * 1LL * a) % mod;
      }
      return res;
    }
    
    long long f(int i, int j, int N,int M,vector<vector<long long>> &dp){
        if(i==0 and j==0) return 1;
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        long long up=0,left=0;
        if(i>0) up=f(i-1,j,N,M,dp);
        if(j>0) left=f(i,j-1,N,M,dp);
        
        return dp[i][j]=(up%mod+left%mod)%mod;
    }
    
    long long  numberOfPaths(int M, int N)
    {
        // vector<vector<long long>> dp(N,vector<long long>(M,-1));
        // return f(N-1,M-1,N,M,dp);
        
        N = N+M-2;
        int r = M-1;
        long long res = 1;

        for(int i=1;i<=r;i++)
        {
            res = (res * 1LL * (N - r +i)) % mod;
            res = (res * 1LL * power(i , mod-2)) % mod; 
        }

        return res;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends