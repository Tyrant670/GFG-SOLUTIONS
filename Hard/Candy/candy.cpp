//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int n, vector<int> &ratings) {
        // code here
        vector<int> pre(n);
        
        pre[0] = 1;
        for(int i = 1 ; i < n ; i++) {
            if(ratings[i] > ratings[i - 1]) {
                pre[i] = pre[i - 1] + 1;
            }
            else {
                pre[i] = 1;
            }
        }
        
        vector<int> suff(n);
        suff[n - 1] = 1;
        
        for(int i = n - 2 ; i >= 0 ; i--) {
            if(ratings[i] > ratings[i + 1]) {
                suff[i] = suff[i + 1] + 1;
            }
            else {
                suff[i] = 1;
            }
        }
        
        int min_candies = 0;
        for(int i = 0 ; i < n ; i++) {
            min_candies += max(pre[i] , suff[i]);
        }
        return min_candies;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends