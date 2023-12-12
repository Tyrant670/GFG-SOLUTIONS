//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int solve(vector<vector<int>> &m,int i,int j,vector<vector<int>>&dp){
        int row=m.size();
        int col=m[0].size();
        if(i<0 || i>=row || j<0 || j>=col)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int r=m[i][j]+solve(m,i,j+1,dp);
        int ru=m[i][j]+solve(m,i-1,j+1,dp);
        int rd=m[i][j]+solve(m,i+1,j+1,dp);
        return dp[i][j]= max(r,max(ru,rd));
    }
    int f(int i,int j,int n,int m,vector<vector<int>> arr,vector<vector<int>>& dp){
        if(i>=n || j>=m || i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up=arr[i][j]+f(i-1,j+1,n,m,arr,dp);
        int right=arr[i][j]+f(i,j+1,n,m,arr,dp);
        int down=arr[i][j]+f(i+1,j+1,n,m,arr,dp);
        
        return dp[i][j]=max({up,right,down});
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // int ans=INT_MIN;
        // for(int i=0;i<n;i++){
        //     ans=max(ans,f(i,0,n,m,M,dp));
        // }
        // return ans;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int res=INT_MIN;
        for(int i=0;i<M.size();i++){
            res=max(res,solve(M,i,0,dp));
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends