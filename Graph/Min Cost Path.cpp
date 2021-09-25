bool valid(int i,int j,int n,int m){
    if(i<0 || j<0 || i>=n ||j>=m)
      return false;
    return true;
}
int Solution::solve(int n, int m, vector<string> &C) {
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
pq.push({0,{0,0}});
vector<vector<int>>dis(n+1,vector<int>(m+1,INT_MAX));
dis[0][0]=0;
while(!pq.empty()){
    pair<int,pair<int,int>>curr=pq.top();
    pq.pop();
    int curr_dis=curr.first;
    int currX=curr.second.first;
    int currY=curr.second.second;
    int moveX=currX;
    int moveY=currY+1;
    if(valid(moveX,moveY,n,m)){
        int cost;
        if(C[currX][currY]=='R'){
            cost=0;
        }
        else{
            cost=1;
        }
        if(dis[moveX][moveY]>dis[currX][currY]+cost){
            dis[moveX][moveY]=dis[currX][currY]+cost;
            pq.push({dis[moveX][moveY],{moveX,moveY}});
        }
    }
     moveX=currX;
     moveY=currY-1;
    if(valid(moveX,moveY,n,m)){
        int cost;
        if(C[currX][currY]=='L'){
            cost=0;
        }
        else{
            cost=1;
        }
        if(dis[moveX][moveY]>dis[currX][currY]+cost){
            dis[moveX][moveY]=dis[currX][currY]+cost;
            pq.push({dis[moveX][moveY],{moveX,moveY}});
        }
    }
     moveX=currX+1;
     moveY=currY;
    if(valid(moveX,moveY,n,m)){
        int cost;
        if(C[currX][currY]=='D'){
            cost=0;
        }
        else{
            cost=1;
        }
        if(dis[moveX][moveY]>dis[currX][currY]+cost){
            dis[moveX][moveY]=dis[currX][currY]+cost;
            pq.push({dis[moveX][moveY],{moveX,moveY}});
        }
    }
     moveX=currX-1;
     moveY=currY;
    if(valid(moveX,moveY,n,m)){
        int cost;
        if(C[currX][currY]=='U'){
            cost=0;
        }
        else{
            cost=1;
        }
        if(dis[moveX][moveY]>dis[currX][currY]+cost){
            dis[moveX][moveY]=dis[currX][currY]+cost;
            pq.push({dis[moveX][moveY],{moveX,moveY}});
        }
    }
}
return dis[n-1][m-1];
}
