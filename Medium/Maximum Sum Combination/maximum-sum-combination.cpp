//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &a, vector<int> &b) {
        // vector<int> ans;
        // if(N==1) return {A[0]+B[0]};
        // sort(A.rbegin(),A.rend());
        // sort(B.rbegin(),B.rend());
        // vector<int> x,y;
        // for(int i=0;i<N;i++){
        //     x.push_back(A[0]+B[i]);
        // }
        // for(int i=1;i<N;i++){
        //     y.push_back(B[0]+A[i]);
        // }
        // sort(x.rbegin(),x.rend());
        // sort(y.rbegin(),y.rend());
        
        // int i=0,j=0;
        
        // while(ans.size()!=K){
        //     if(x[i]>y[j]){
        //         ans.push_back(x[i++]);
        //     }
        //     else ans.push_back(y[j++]);
        // }
        
        // return ans;
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        priority_queue<int> p;
        vector<int> res;
        
        for(int i = N-1;i>=N-K;i--){
            for(int j = N-1;j>=N-K;j--){
                if(p.size()<K) p.push(-(a[i]+b[j]));
                else{
                    if((a[i]+b[j])>-p.top()){
                        p.pop();
                        p.push(-(a[i]+b[j]));
                    }
                    else break;
                }
            }
        }
        while(!p.empty()){
            res.push_back(-p.top());
            p.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends