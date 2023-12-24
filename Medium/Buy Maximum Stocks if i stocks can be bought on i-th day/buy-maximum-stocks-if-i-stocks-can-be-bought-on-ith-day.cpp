//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({price[i],i+1});
        }
        int ans=0;
        sort(v.begin(),v.end());
        for(auto it:v){
            int val=it.first;
            int cnt=it.second;
            if(k-cnt*val>0){
                k-=cnt*val;  
                ans+=cnt;
            }else{
                int m=k/val;
                k-=m*val;
                ans+=m;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends