//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int f(int ind , int buy , int cmp , int n ,vector<int>&price ,  vector<vector<vector<int>>> &dp ){
    if(ind==n)
        return 0;
    if(cmp==0)
        return 0;
    if(dp[ind][buy][cmp] != -1)
        return dp[ind][buy][cmp];
    if(buy){
        return dp[ind][buy][cmp] =   max(-price[ind] + f(ind+1 , 0 , cmp , n , price , dp) , 0 + f(ind+1 , 1, cmp,n , price ,dp));
    }
    else{
        return dp[ind][buy][cmp] = max(price[ind] + f(ind+1 , 1 , cmp-1,n , price ,dp) , 0 + f(ind+1 , 0 , cmp,n , price,dp));
    }
}

int maxProfit(vector<int>&prices){
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
    return f(0,1,2,n,prices,dp);
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends