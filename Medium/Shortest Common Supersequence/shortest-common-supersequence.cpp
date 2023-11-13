//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int lcs(string &X, string &Y, int &m, int &n, int i, int j, vector<vector<int>>& dp){
        if(i == m || j == n){
            return 0;
        }
        else if(dp[i][j] != -1){
            return dp[i][j];
        }
        else{
            if(X[i] == Y[j]){
                return dp[i][j] = 1 + lcs(X, Y, m, n, i+1, j+1, dp);
            }
            else{
                return dp[i][j] = max(lcs(X, Y, m, n, i+1, j, dp), lcs(X, Y, m, n, i, j+1, dp));
            }
        }
    }
    
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans = lcs(X, Y, m, n, 0, 0, dp);
        return m + n - ans;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends