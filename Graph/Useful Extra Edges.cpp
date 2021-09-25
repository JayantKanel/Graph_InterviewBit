int Solution::solve(int n, vector<vector<int> > &B, int src, int dest, vector<vector<int> > &E) {
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back({B[i][2],B[i][1]});
        adj[B[i][1]].push_back({B[i][2],B[i][0]});

    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dis1(n+1,INT_MAX);
    dis1[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        pair<int,int>curr=pq.top();
        pq.pop();
        // int min_dis=curr.first;
        int u=curr.second;
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].second;
            int w=adj[u][i].first;
            if(dis1[v]>dis1[u]+w){
                dis1[v]=dis1[u]+w;
                pq.push({dis1[v],v});
            }
        }
    }
    vector<int>dis2(n+1,INT_MAX);
    dis2[dest]=0;
    pq.push({0,dest});
    while(!pq.empty()){
        pair<int,int>curr=pq.top();
        pq.pop();
        // int min_dis=curr.first;
        int u=curr.second;
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].second;
            int w=adj[u][i].first;
            if(dis2[v]>dis2[u]+w ){
                dis2[v]=dis2[u]+w;
                pq.push({dis2[v],v});
            }
        }
    }
    int ans=dis1[dest];
    for(int i=0;i<E.size();i++){
        int u=E[i][0];
        int v=E[1][1];
        int wt=E[i][2];
        if(dis1[u]!=INT_MAX and dis2[v]!=INT_MAX)
            ans=min(dis1[u]+wt+dis2[v],ans);    
        if(dis1[v]!=INT_MAX and dis2[u]!=INT_MAX)
            ans=min(dis1[v]+wt+dis2[u],ans); 
    }
    if(ans==INT_MAX)
      return -1;
      return ans;
}
