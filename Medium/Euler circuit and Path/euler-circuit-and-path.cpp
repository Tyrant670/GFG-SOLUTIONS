//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int x;
    void dfs(int node,vector<int> adj[],vector<int>& vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
            else{
                bool ok=1;
                for(auto it:vis){
                    if(it==0){
                        ok=0;
                        break;
                    }
                }
                if(ok and it==0){
                    x=2;
                }
                else if(ok and it!=0){
                    x=1;
                }
                else{
                    x=0;
                }
                return;
            }
        }
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	    vector<int> vis(V,0);
	    dfs(0,adj,vis);
	   // return x;
	   
	    int odd=0, even=0;
	    for(int i=0;i<V;i++){
	        if(adj[i].size()%2==0) even++;
	        else odd++;
	    }
	    if(even==V) return 2;
	    else if(odd==2) return 1;
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends