//Logic:
//Simple we do what question wants us to do
//we will go to leaf node of the graph from every node keep the count of the node which are good node if the number of good node are in the limit we will increase the count by one
//lets creatre adjacency list for every point with given graph
//now the node is leaf if its connected to only one point
//simple use dfs by keeping the count of good node and answer will be yours.
int ans=0;
void dfs(int u,int count,vector<bool>&vis,vector<vector<int>>&adj,vector<int> &A,int C){
    bool flag=false;
    vis[u]=true;
    if(A[u-1]==1){
        count++;
    }
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(vis[v]==false){
            vis[v]=true;
            dfs(v,count,vis,adj,A,C);
            flag=true;
        }
    }
    if(flag==false && count<=C){
        ans++;
    }
}
int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n=A.size();
    vector<vector<int>>adj(n+1);
    for(int i=0;i<B.size();i++){
        int a=B[i][0];
        int b=B[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool>vis(n+1,false);
    ans=0;
    dfs(1,0,vis,adj,A,C);
    return ans;
}
