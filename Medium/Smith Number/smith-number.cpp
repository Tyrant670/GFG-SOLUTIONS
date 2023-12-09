//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int digitSum(int n){
        int rem, ans=0;
        while(n){
            rem = n % 10;
            ans += rem;
            n = n/10;
        }
        return ans;
    }
    
    bool isPrime(int n){
        if(n==1) return false;
        for(int i=2; i <= sqrt(n); i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
  
    vector<int> prime(int n, vector<int> &v){
        for (int i = 2; i <= n; i = i + 1){ 
            if(i%2==0 && i>2) continue;
            while (n % i == 0)  
            {  
                v.push_back(i);  
                n = n/i;  
            }  
        }
        if(n>2){
            v.push_back(n);
        }
        return v;
    }
    
    int smithNum(int n) {
        if(isPrime(n)) return 0;
        
        int sum = digitSum(n);
        int primeSum = 0;
        vector<int> digits;
        prime(n, digits);
        
        for(int i=0; i<digits.size(); i++){
            primeSum += digitSum(digits[i]);
        }
        
        return sum==primeSum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends