//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    const int mod=1e9+7;
		    if(n==1) return 1;
		    int f=1,s=1;
		    for(int i=2;i<=n;i++){
		        int temp=(f%mod+s%mod)%mod;
		        f=s%mod;
		        s=temp%mod;
		    }
		    return s%mod;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends