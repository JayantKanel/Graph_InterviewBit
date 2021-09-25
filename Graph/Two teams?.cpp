//Logic:
//See this question like these graph is given and we have tp find whether graph is bipartite or not
//graph is bipartite when it can be divided into parts such after deleting any particular edge graph will nit be connected anymore
//now lets use these logic that if any node has color 1 then it's child should havr color then 1 if both has same color then it can't be bipartite
int Solution::solve(int n, vector<vector<int> > &B) {
    vector<vector<int>>adj(n+1);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    vector<int>vis(n+1,-1);
    for(int i=1;i<=n;i++){
        if(vis[i]==-1){
    vis[i]=0;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int i=0;i<adj[curr].size();i++){
            int child=adj[curr][i];
            if(vis[child]==-1){
                if(vis[curr]==0){
                    vis[child]=1;
                }
                else{
                    vis[child]=0;
                }
                q.push(child);
            }
            else if(vis[child]==vis[curr])
              return 0;
        }
    }
    }
    }
    return 1;
    
}
