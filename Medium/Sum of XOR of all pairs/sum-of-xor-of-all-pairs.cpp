//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	long long int sum = 0;
        for(int j=0;j<32;j++){
            int zero_count = 0;
            int one_count = 0;
            for(int i=0;i<n;i++)
            {
             if(arr[i]%2 == 1) one_count++;
             else zero_count++;
             arr[i] = arr[i]/2;
            }
            sum += pow(2,j)*zero_count*one_count;
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends