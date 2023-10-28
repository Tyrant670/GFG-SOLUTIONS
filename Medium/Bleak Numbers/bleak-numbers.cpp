//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countSetbits(int n){
        int cnt=0;
        while(n!=0){
            n&=(n-1);
            cnt++;
        }
        return cnt;
    }
    
	int is_bleak(int n)
	{
	    for(int i=n-32;i<=n-1;i++){
	        if(i>0){
	            int x=countSetbits(i);
    	        if(i+x==n){
    	            return 0;
    	        }
	        }
	    }
	    
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends