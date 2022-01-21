class Solution {
public:
    void dfs(vector<int> adj[],vector<int> &vis,int node,stack<int> &st){
        vis[node]=1;
        
        for(auto x: adj[node]){
            if(!vis[x]){
                dfs(adj,vis,x,st);
            }
        }
        
        st.push(node);
    }
     bool iscycle(vector<int> adj[],vector<int> &vis,int id){
        if(vis[id]==1)
            return true;
        if(vis[id]==0){
            vis[id]=1;
            for(auto edge : adj[id]){
                if(iscycle(adj,vis,edge))
                    return true;
            }
        }
        vis[id] = 2;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
         vector<int> adj[n];
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);
        vector<int> vis(n,0);
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(iscycle(adj,vis,i))
                return ans;
        }
        
      
        stack<int> st;
        fill(begin(vis) , end(vis) , 0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i,st);
            }
        }
        
        
        while(!st.empty()){
            
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};