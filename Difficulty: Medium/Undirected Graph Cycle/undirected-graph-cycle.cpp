//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    bool detectc(int src,unordered_map<int,vector<int>>&mp,vector<int>&vis){
        vis[src]=1;
        
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto i:mp[node]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push({i,node});
                }
                else if(parent!=i){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        //first make the adj list
        unordered_map<int,vector<int>>mp;
        for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
          vector<int> vis(V, 0);
        for(int i=0;i<V;i++){
            
            if(!vis[i]){
                if(detectc(i,mp,vis)) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends