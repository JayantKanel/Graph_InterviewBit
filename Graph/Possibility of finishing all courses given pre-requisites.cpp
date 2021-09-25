bool flag=false;
void dfs(int src,vector<int>&vis,vector<vector<int>>&adj){
    vis[src]=1;
    for(int i=0;i<adj[src].size();i++){
        int child=adj[src][i];
        if(vis[child]==-1){
            // vis[child]=1;
            dfs(child,vis,adj);
        }
        else if(vis[child]==1){
            flag=true;
            return;
        }
    }
    vis[src]=2;
}
int Solution::solve(int n, vector<int> &B, vector<int> &C) {
    vector<vector<int>>adj(n+1);
    for(int i=0;i<B.size();i++){
        adj[B[i]].push_back(C[i]);
    }
    vector<int>vis(n+1,-1);
    flag=false;
    for(int i=1;i<=n;i++){
      if(vis[i]==-1)
          dfs(i,vis,adj);
    if(flag==true)
      return 0;
    }
      return 1;
}
