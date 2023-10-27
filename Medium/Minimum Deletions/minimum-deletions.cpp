//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int lcs(int i, int j , string& s, string &r, vector<vector<int>>&dp){
        if(i==s.size() || j==s.size()){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int take=0, notTake=0;
        if(s[i] == r[j]){
            take = 1 + lcs(i+1,j+1,s,r,dp);
        }
        notTake = max(lcs(i+1,j,s,r,dp), lcs(i,j+1,s,r,dp));
        
        return dp[i][j] =  max(take,notTake);
    }
  
    int minimumNumberOfDeletions(string S) { 
        string t=S;
        reverse(t.begin(),t.end());
        int n=S.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return n-lcs(0,0,S,t,dp);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends