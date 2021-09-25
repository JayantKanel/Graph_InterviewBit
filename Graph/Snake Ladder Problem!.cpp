//Logic
//As usual keep things single start from point 1 and go to every other siz mooves from there and see if we can reach to 100 from there or not
//we will use bfs ofcourse:)
//hve an array of size 100 and for every point put the value accoriding to ladder or snakeLadder
//we got the answer
int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    vector<int>move(101,-1);
    for(int i=0;i<A.size();i++){
        int a=A[i][0];
        int b=A[i][1];
        move[a]=b;
    }
    for(int i=0;i<B.size();i++){
        int a=B[i][0];
        int b=B[i][1];
        move[a]=b;
    }
    for(int i=1;i<=100;i++){
        if(move[i]==-1){
            move[i]=i;
        }
    }
   queue<int>q;
   vector<bool>vis(101,false);
   q.push(1);
   int ans=0;
   while(!q.empty()){
       int n=q.size();
       ans++;
       while(n--){
           int curr=q.front();
           q.pop();
           vis[curr]=true;
           if(curr==100)
             return ans-1;
           for(int i=1;i<=6;i++){
               int temp=curr+i;
               if(vis[temp]==false && temp<=100){
                   vis[move[temp]]=true;
                   vis[temp]=true;
               q.push(move[temp]);
               }
           }
       }
   }
   return -1;

}
