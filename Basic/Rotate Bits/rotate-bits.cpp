//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            bitset<16> bits(n);
            d%=16;
            bitset<16> temp = (bits<<d)|(bits>>(16-d));
            int x = temp.to_ulong();
            temp = (bits>>d) | (bits<<(16-d)); 
            int y = temp.to_ulong();
            return {(int)x,(int)y};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends