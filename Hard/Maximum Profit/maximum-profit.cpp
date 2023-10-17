//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int i,int buy,int limit,int arr[],int n,vector<vector<vector<int>>> & dp) {
        if(i==n) return 0;
        if(limit==0) return 0;
    
        if(dp[i][buy][limit]!=-1) return dp[i][buy][limit];
    
        // int profit=0;
        if(buy){
            dp[i][buy][limit]=max(-arr[i]+f(i+1,0,limit,arr,n,dp),0+f(i+1,1,limit,arr,n,dp));
        }
        else{
            dp[i][buy][limit]=max(arr[i]+f(i+1,1,limit-1,arr,n,dp),0+f(i+1,0,limit,arr,n,dp));
        }
        return dp[i][buy][limit];
    }
  
    int maxProfit(int K, int N, int A[]) {
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(2,vector<int>(K+1,-1)));
        return f(0,1,K,A,N,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends