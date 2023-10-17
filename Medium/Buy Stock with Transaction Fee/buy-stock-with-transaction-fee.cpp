//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long f(int ind,int buy,vector<long long>&arr,vector<vector<long long>> &dp,int fee){
        if(ind==arr.size()) return 0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        long long profit=0;
        
        if(buy){
            long long x=-arr[ind]-fee+f(ind+1,0,arr,dp,fee);
            long long y=0+f(ind+1,1,arr,dp,fee);
            profit=max(x,y);
        }
        else{
            long long x=arr[ind]+f(ind+1,1,arr,dp,fee);
            long long y=0+f(ind+1,0,arr,dp,fee);
            profit=max(x,y);
        }
        return dp[ind][buy]=profit;
    }
    
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return f(0,1,prices,dp,fee);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends