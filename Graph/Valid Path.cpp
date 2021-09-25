//Logic
//As usual keep things simple
//A point is valid by valid I meant that point is in the rectangle and not in the circle
//Now by basic math we know  that how to check if point is in the circle see the code for that or else read the circle chapter in mathematics from 11 th class:)
//Now use bfs from (0,0) and go to any of the valid 8 direction and see if that point is in  the circle or not if not go to another valid 8 direction 
//keep going till we do not reach to the desire point
bool valid(int h, int k, map<int,map<int,bool>> &visited, int A, int B, int D, vector<int> &E, vector<int> &F){
    if(h<0 || h>A) return false;
    else if(k<0 || k>B) return false;
    else if(visited[h][k]) return false;
 
    for(int i=0;i<E.size();i++){
        // int t1=
        if(( (h-E[i])*(h-E[i]) + (k-F[i])*(k-F[i])) <= D*D ) return false;
    }
 
    visited[h][k]=true;
    return true;
}
 
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
int i=0,j=0;
map<int,map<int,bool>> visited;
queue<pair<int,int>>q;
q.push(make_pair(i,j));
visited[i][j]=true;
 
while(!q.empty()){
    auto cordinate = q.front();
    q.pop();
    
    int x = cordinate.first;
    int y = cordinate.second;
    
    if(x==A && y==B) return "YES";
    int h,k;
    
    h=x,k=y+1;
    if(valid(h,k,visited,A,B,D,E,F)) q.push(make_pair(h,k));
    
    h=x+1,k=y+1;
    if(valid(h,k,visited,A,B,D,E,F)) q.push(make_pair(h,k));
    
    h=x+1,k=y;
    if(valid(h,k,visited,A,B,D,E,F)) q.push(make_pair(h,k));
    
    h=x,k=y-1;
    if(valid(h,k,visited,A,B,D,E,F)) q.push(make_pair(h,k));
    
    h=x+1,k=y-1;
    if(valid(h,k,visited,A,B,D,E,F)) q.push(make_pair(h,k));
    
    h=x,k=y-1;
    if(valid(h,k,visited,A,B,D,E,F)) q.push(make_pair(h,k));
    
    h=x-1,k=y-1;
    if(valid(h,k,visited,A,B,D,E,F)) q.push(make_pair(h,k));
    
    h=x-1,k=y;
    if(valid(h,k,visited,A,B,D,E,F)) q.push(make_pair(h,k));
}
 
return "NO";
}
