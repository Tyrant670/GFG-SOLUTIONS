//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    bool isprime(int x)
    {
        if(x <= 1) return false;
        if(x == 2 || x == 3) return true;
        if(x % 2 == 0 || x % 3 == 0) return false;
        if((x - 1) % 6 != 0 && (x + 1) % 6 != 0) return false;
        for(int i = 5; i * i <= x; i += 6)
        {
            if(x % i == 0 || x % (i + 2) == 0) return false;
        }
        return true;
    }
    int minNumber(int arr[],int N)
    {
        int s=0;
        for(int i=0;i<N;i++) s+=arr[i];
        int x=0;
        for(int i=s;;i++){
            if(isprime(i)) break;
            x++;
        }
        return x;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends