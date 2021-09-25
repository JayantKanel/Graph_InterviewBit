bool valid(int x,int y,int m,int n){
    if(x<=0 || y<=0 || x>m || y>n)
     return false;
    return true;
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    queue<pair<int,int>>q;
    if(C==E && D==F)
     return 0;
    q.push({C,D});
    int dirX[8]={1,1,2,2,-2,-2,-1,-1};
    int dirY[8]={2,-2,1,-1,1,-1,2,-2};
    int cnt=0;
    int n=max(A,B);
    vector<vector<bool>>vis(n+1,vector<bool>(n+1,false));
    while(!q.empty()){
        cnt++;
        int n=q.size();
        while(n--){
            int currX=q.front().first;
            int currY=q.front().second;
            q.pop();
            vis[currX][currY]=true;
            for(int i=0;i<8;i++){
                int moveX=currX+dirX[i];
                int moveY=currY+dirY[i];
                if(valid(moveX,moveY,A,B)){
                    if(!vis[moveX][moveY]){
                        vis[moveX][moveY]=true;
                        if(moveX==E && moveY==F)
                          return cnt;
                        q.push({moveX,moveY});
                    }
                }
            }
        }
    }
    return -1;
}
