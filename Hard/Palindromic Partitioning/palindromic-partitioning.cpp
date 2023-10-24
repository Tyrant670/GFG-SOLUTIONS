//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool checkPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i,int n,string& s,vector<int> & dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int cost=1e9;
        for(int j=i;j<n;j++){
            if(checkPalindrome(i,j,s)){
                int currCost=1+f(j+1,n,s,dp);
                cost=min(cost,currCost);
            }
        }
        return dp[i]=cost;
    }

    int palindromicPartition(string str)
    {
        int n=str.size();
        vector<int> dp(n+1,-1);
        return f(0,n,str,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends