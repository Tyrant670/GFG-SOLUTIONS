//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        int sum = 0 ;
        for(int i = 0; i<str.size(); i++){
            if(str[i]=='C' && str[i+1]=='M'){
                sum += 900;
                ++i;
            }
            else if(str[i]=='M'){
                sum += 1000;
            }
            else if(str[i]=='C' && str[i+1]=='D'){
                sum += 400;
                ++i;
            }
            else if(str[i] == 'D'){
                sum += 500;
            }
            else if(str[i]=='X' && str[i+1]=='C'){
                sum += 90;
                ++i;
            }
            else if(str[i] == 'C'){
                sum += 100;
            }
            else if(str[i]=='X' && str[i+1]=='L'){
                sum += 40;
                ++i;
            }
            else if(str[i] == 'L'){
                sum += 50;
            }
            else if(str[i]=='I' && str[i+1]=='X'){
                sum += 9;
                ++i;
            }
            else if(str[i] == 'X'){
                sum += 10;
            }
            else if(str[i]=='I' && str[i+1]=='V'){
                sum += 4;
                ++i;
            }
            else if(str[i] == 'V'){
                sum += 5;
            }
            else{
                sum += 1;
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends