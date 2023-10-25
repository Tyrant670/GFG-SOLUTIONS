//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    static int dp[2000][2000];

    // Top down approach 
    int f(int wt[],int val[],int w,int n){
        for(int i=0;i<n+1;i++){
            for(int j=0;j<w+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
    
        for(int i=1;i<n+1;i++){
            for(int j=1;j<w+1;j++){
                if(wt[i-1]<=j){
                    dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                }
                else {
                    dp[i][j]=dp[i-1][j];
                }
    
            }
        }
    
        return dp[n][w];
        
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W+1,0);
        
        for (int i=0;i<N;i++) {
            for (int j=1;j<=W;j++) {
                if (j >= wt[i])
                    dp[j] = max(dp[j],dp[j-wt[i]]+val[i]);
            }
        }
        
        return dp[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends