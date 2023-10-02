//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string arr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ans = "";
        while(n){
            long long int rem = (n-1)%26;
            ans+=arr[rem];
            n=(n-1)/26;
        } 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends