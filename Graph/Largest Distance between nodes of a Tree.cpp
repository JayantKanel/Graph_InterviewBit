//logic :
//Simple go from any point to another point and from that end point go to another end point we will find the largest distance
int len1=0,root1=0,ans=0;
void dfs(int src,int len,vector<bool>&vis,vector<vector<int>>&adj){
    vis[src]=true;
    if(len>ans && adj[src].size()==1){
        ans=len;
    }
    len++;
    for(int i=0;i<adj[src].size();i++){
        int child=adj[src][i];
        if(!vis[child]){
            vis[child]=true;
            dfs(child,len,vis,adj);
        }
    }
    if(adj[src].size()==1){
        if(len>len1){
            len1=len;
            root1=src;
        }
    }
}

int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<vector<int>>adj(n+1);
    if(n==1)
    return 0;
    if(n==2)
     return 1;
    int root=0;
    for(int i=0;i<n;i++){
        if(A[i]==-1){
            root=i;
        }
        else{
            adj[i].push_back(A[i]);
            adj[A[i]].push_back(i);
        }
    }
    vector<bool>vis(n+1,false);
   len1=0,root1=0,ans=0;
    dfs(root,0,vis,adj);
     vector<bool>vis1(n+1,false);
    dfs(root1,0,vis1,adj);
   return ans;
}
