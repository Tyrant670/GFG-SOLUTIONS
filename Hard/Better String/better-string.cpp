//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const int MAX_CHAR = 256;
    int countSub(string str)
    {
        vector<int> last(MAX_CHAR, -1);

        int n = str.length();
        int dp[n + 1];
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            dp[i] = 2 * dp[i - 1];
            if (last[str[i - 1]] != -1)
                dp[i] = dp[i] - dp[last[str[i - 1]]];
            last[str[i - 1]] = (i - 1);
        }
     
        return dp[n];
    }

    string betterString(string str1, string str2) {
        int n=countSub(str1);
        int m=countSub(str2);
        if(n>=m) return str1;
        return str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends