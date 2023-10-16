//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int label, unordered_set<int>& visited, int& count) {
        int n = grid.size();
        if (i < 0 || j < 0 || i >= n || j >= n ){
            return;
        }   
        if(grid[i][j] != 1 ){
            return;
        }
        if(visited.count(i * n + j) == 1){
            return;
        }

        visited.insert(i * n + j);
        count++;
        grid[i][j] = label;
        dfs(grid, i + 1, j, label, visited, count);
        dfs(grid, i - 1, j, label, visited, count);
        dfs(grid, i, j + 1, label, visited, count);
        dfs(grid, i, j - 1, label, visited, count);
    }
    
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int largestIsland = 0;
        
        int label = 2;
      
        unordered_map<int, int> areasOfIsland; 
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    unordered_set<int> visited;
                    int count = 0;
                    dfs(grid, i, j, label, visited, count);
                    areasOfIsland[label] = count;
                    label++;
                    largestIsland = max(largestIsland, count);
                }
            }
        }
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighbor;
                    if (i > 0) neighbor.insert(grid[i - 1][j]);
                    if (i < n - 1) neighbor.insert(grid[i + 1][j]);
                    if (j > 0) neighbor.insert(grid[i][j - 1]);
                    if (j < n - 1) neighbor.insert(grid[i][j + 1]);
    
                    int newCount = 1;
                    for (int island : neighbor) {
                        newCount += areasOfIsland[island];
                    }
                    largestIsland = max(largestIsland, newCount);
                }
            }
        }
    
        return largestIsland;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends