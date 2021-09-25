//Logic
//Simple lets have three number
// 0 if node isn't yet visited
//1  if node is traversed but its descendant aren't yet
//2 if node is completly visited
//if we are visiting any node and we find that any node is visited but not completly that is 1 then there is cycle 
bool dfs(int u,vector<int>&vis,vector<vector<int>>&adj){
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(vis[v]==0){
            if(dfs(v,vis,adj)){
                return true;
            }
        }
        else{
            if(vis[v]==1){
                return true;
            }
        }
    }
    vis[u]=2;
    return false;
}
int Solution::solve(int n, vector<vector<int> > &B) {

    vector<vector<int>>adj(n+1);
    for(int i=0;i<B.size();i++){
        int a=B[i][0];
        int b=B[i][1];
        adj[a].push_back(b);
    }
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
             if(dfs(i,vis,adj)){
                 return 1;
             }
        }
            
    }
      return 0;

}
