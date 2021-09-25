//logic:
//lets keep things simple and find 'O' which are invalid/not surrounded by 'X' and swap those with 'X'
//Any 'O' which will on the border that is on the left most column or rightmost cloumn or uppermost row or lowermost row will not be sorrounded by 'X'
//any 'O'  which is connected to with above 'O' will also be invalid and those are not will be valid
//Now just use dfs
//Initially push all the points which has 'O' and are at the border of given Matrices
//after push all those points which are connedted to those point already in the queue and has 'O' as value
//keep these in the mind that connected means point which is adjacent in the direction of horizontal and verticall
//diagonal aren't connected
//Now you can go through code my freind or you can try on your own just think about it you will find the solution:)
bool valid(int i,int j,int n,int m){
    if(i<0 || j<0 ||i>=n || j>=m){
        return false;
    }
    return true;
}
void Solution::solve(vector<vector<char> > &A) {
    int n=A.size();
    int m=A[0].size();
    vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
    queue<pair<int,int>>q;
    if(A[0][0]=='O'){
        q.push({0,0});
        vis[0][0]=true;
    }
    if(A[n-1][m-1]=='O'){
        if(vis[n-1][m-1]==false){
        q.push({n-1,m-1});
        vis[n-1][m-1]=true;
        }
    }
    if(A[0][m-1]=='O'){
        if(vis[0][m-1]==false){
        q.push({0,m-1});
        vis[0][m-1]=true;
        }
    }
    if(A[n-1][0]=='O'){
        if(vis[n-1][0]==false){
            vis[n-1][0]=true;
        q.push({n-1,0});
        }
    }
    for(int i=1;i<m-1;i++){
        if(A[0][i]=='O' && vis[0][i]==false){
            q.push({0,i});
            vis[0][i]=true;
        }
        if(A[n-1][i]=='O' && vis[n-1][i]==false){
            vis[n-1][i]=true;
            q.push({n-1,i});
        }
    }
    for(int i=1;i<n-1;i++){
        if(A[i][0]=='O' && vis[i][0]==false){
            q.push({i,0});
            vis[i][0]=true;
        }
        if(A[i][m-1]=='O' && vis[i][m-1]==false){
            vis[i][m-1]=true;
            q.push({i,m-1});
        }
    }
    int dirX[]={0,0,1,-1};
    int dirY[]={1,-1,0,0};
    while(!q.empty()){
        pair<int,int>curr=q.front();
        q.pop();
        int currX=curr.first;
        int currY=curr.second;
        vis[currX][currY]=true;
        for(int i=0;i<4;i++){
            int moveX=currX+dirX[i];
            int moveY=currY+dirY[i];
            if(valid(moveX,moveY,n,m)){
                if(vis[moveX][moveY]==false){
                if(A[moveX][moveY]=='O'){
                    vis[moveX][moveY]=true;
                    q.push({moveX,moveY});
                }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==false){
                A[i][j]='X';
            }
        }
    }
    // return A;
}
