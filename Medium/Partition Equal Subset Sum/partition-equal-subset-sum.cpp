//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int t=0;
        for(int i=0;i<N;i++){
            t+=arr[i];
        }
        if(t&1) return 0;
        
        t=t/2;
        
        vector<vector<bool>> dp(N+1,vector<bool>(t+1));
        
        for(int i=0;i<N+1;i++){
            for(int j=0;j<t+1;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        
        for(int i=1;i<N+1;i++){
            for(int j=1;j<t+1;j++){
                if(arr[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            }
        }
        
        return dp[N][t];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends