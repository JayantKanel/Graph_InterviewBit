bool flag=false;
void dfs(int src,int par,vector<int>&vis,vector<vector<int>>&adj){
    vis[src]=1;
    for(int i=0;i<adj[src].size();i++){
        int child=adj[src][i];
        if(vis[child]==-1){
            // vis[child]=1;
            dfs(child,src,vis,adj);
        }
        else if(vis[child]==1 && child!=par){
            flag=true;
            return;
        }
    }
    vis[src]=2;
}
int Solution::solve(int n, vector<vector<int> > &B) {
    vector<vector<int>>adj(n+1);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    vector<int>vis(n+1,-1);
    flag=false;
    for(int i=1;i<=n;i++){
      if(vis[i]==-1)
          dfs(i,-1,vis,adj);
    }
    if(flag==true)
      return 1;
      return 0;
}
