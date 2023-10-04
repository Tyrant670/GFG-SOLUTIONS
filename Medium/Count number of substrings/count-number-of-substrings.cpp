//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int solve(string s, int k)
    {
        int n = s.size();
        int freq[26] = {0};
        int dist_cnt = 0;
        long long int ans = 0; 
        
        int i=0;  
        int j=0; 
        while(j<n)
        {
            freq[s[j]-'a']++;
            if(freq[s[j]-'a'] == 1)
                dist_cnt++;
            

            while(dist_cnt > k)
            {
                freq[s[i]-'a']--;
                if(freq[s[i]-'a'] == 0)
                    dist_cnt--;
                i++;
            }
            j++;
            ans += (j-i+1);
        }
        return ans;
    }
    long long int substrCount (string s, int k) {
    // 	long long int ans=0;
    // 	map<char,int> mp;
    // 	int n=s.size();
    // 	int j=0;
    // 	for(int i=0;i<n;i++){
    // 	    mp[s[i]]++;
    // 	    if(mp.size()==k) ans++;
    // 	    while(mp.size()>=k and j<n){
    // 	        mp[s[j]]--;
    // 	        if(mp[s[j]]==0){
    // 	            mp.erase(s[j]);
    // 	        }
    // 	        j++;
    // 	    }
    // 	}
    // 	return ans;
        return solve(s,k)-solve(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends