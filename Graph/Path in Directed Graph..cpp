//Just start traversing from Node 1 if we find the given node then there is path or else no path exist we can use 
// we can either user bfs or dfs I have used bfs in it.
int Solution::solve(int A, vector<vector<int> > &B) {
    int n=B.size();
    vector<vector<int>>adj(A+1);
    for(int i=0;i<n;i++){
        int a=B[i][0];
        int b=B[i][1];
        adj[a].push_back(b);
    }
    queue<int>q;
    q.push(1);
    vector<bool>vis(A+1,false);
    while(!q.empty()){
        int u=q.front();
        if(u==A)
          return 1;
        q.pop();
        // vis[u]=true;
        for(int i=0;i<adj[u].size();i++){
            if(vis[adj[u][i]]==false){
                // vis[adj[u][i]]=true;
            q.push(adj[u][i]);
            }
        }
    }
    return 0;
}
