//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int node,vector<int> adj[],vector<int>& vis,vector<int>& path,int mark[]){
        vis[node]=1;
        path[node]=1;
        mark[node]=0;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path,mark)==true) {
                    mark[it]=0;
                    return true;
                }
            }
            else{
                if(path[it]){
                    mark[it]=0;
                    return true;
                }
            }
        }
        mark[node]=1;
        path[node]=0;
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> path(V,0);
        int mark[V]={0};
        vector<int> safeNodes;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,path,mark);
            }
        }
        
        for(int i=0;i<V;i++){
            if(mark[i]==1) safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends