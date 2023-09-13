//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &arr, int N, int M)
        {
            int ans,maxi=-1;
            for(int i=0;i<N;i++){
                int it = lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin();
                int ones;
                if(it==M) ones=0;
                else ones=M-it+1;
                if(ones>maxi){
                    maxi=ones;
                    ans=i;
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends