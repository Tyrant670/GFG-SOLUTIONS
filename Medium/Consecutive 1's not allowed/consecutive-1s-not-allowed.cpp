//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    const int mod=1e9+7;
	#define ll long long
	ll countStrings(int n) {
	    ll z=1;
        ll o=1;
        ll sum=z+o;
      
        if(n==1) return sum;
             
        int i=2;
        while(i<=n){
            o=z;
            z=sum;
            
            sum=(o+z)%mod;
            i++;
        }
         
        return sum%mod;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends