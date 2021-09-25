//Logic 
//Just use bfs from every point which has 1 in it and count number of 1's from there
bool valid(int i,int j,int n,int m,vector<vector<int> > &A){
    if(i<0 || j<0 || i>=n || j>=m || A[i][j]==0)
    return false;
 return true;
}
int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    int dirX[]={0,0,1,-1,1,1,-1,-1};
    int dirY[]={1,-1,0,0,1,-1,-1,1};
    vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==false && A[i][j]==1){
                queue<pair<int,int>>q;
                q.push({i,j});
                int curr=0;
                while(!q.empty()){
                    int currX=q.front().first;
                    int currY=q.front().second;
                    q.pop();
                    curr++;
                    for(int k=0;k<8;k++){
                        int moveX=currX+dirX[k];
                        int moveY=currY+dirY[k];
                        if(valid(moveX,moveY,n,m,A) && vis[moveX][moveY]==false){
                            vis[moveX][moveY]=true;
                            q.push({moveX,moveY});
                        }
                    }
                }
                ans=max(ans,curr-1);
            }
        }
    }
    return ans;
}
