//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis){
        int n=grid.size();
        int m=grid[0].size();
        if(row>=0 && row<n && col>=0 && col<m && vis[row][col]==0 && 
        grid[row][col]==1){
            vis[row][col]=1;
            dfs(row+1,col,grid,vis);
            dfs(row-1,col,grid,vis);
            dfs(row,col-1,grid,vis);
            dfs(row,col+1,grid,vis);
        }
        else return;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(!vis[i][j] && grid[i][j]==1){
                        dfs(i,j,grid,vis);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && i!=0 && i!=n-1 && j!=0 && j!=m-1 && !vis[i][j]){
                    // dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends