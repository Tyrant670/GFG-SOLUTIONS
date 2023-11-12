//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        int n=str1.size();
        string s=str1;
        string ss=str1;
        for(int j=0;j<2;j++){
            char aa=s[0];
            for(int i=0;i<n-1;i++){
                s[i]=s[i+1];
            }
            s[n-1]=aa;
        }
        
        for(int j=0;j<2;j++){
            char aa=ss[n-1];
            for(int i=n-1;i>0;i--){
                ss[i]=ss[i-1];
            }
            ss[0]=aa;
        }
        
        if(str2==s || str2==ss){
            return 1;
        }
        
        
        return 0;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends