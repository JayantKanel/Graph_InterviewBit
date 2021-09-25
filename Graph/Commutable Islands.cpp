//Logic
//Use either kruskal algo or prims algo
int parent(int n,vector<int>&main){
    while(main[n]!=-1)
      n=main[n];
    return n;
}
int Solution::solve(int n, vector<vector<int> > &B) {
   vector<int>main(n+1,-1);
   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
   for(int i=0;i<B.size();i++){
       int a=B[i][0];
       int b=B[i][1];
       int w=B[i][2];
       pq.push({w,{a,b}});
   }
   int ans=0;
   while(!pq.empty()){
       pair<int,pair<int,int>>curr=pq.top();
       pq.pop();
       int min_dis=curr.first;
       int n1=curr.second.first;
       int n2=curr.second.second;
       int p1=parent(n1,main);
       int p2=parent(n2,main);
       if(p1==p2)
         continue;
        main[p1]=p2;
        ans+=min_dis;
   }
   return ans;
}
