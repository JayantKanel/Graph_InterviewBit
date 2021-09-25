//Logic :
//If water from "Blue Lake" can go to any particular node and for that particular node water from "Red Lake" can also come then water can flow from both the lake for that cell.
bool isValid(int x,int y,int n,int m)
{
    if(x<0 || y<0 || x>=n || y>=m)
        return false;
    return true;
}
int Solution::solve(vector<vector<int> > &A) {
 
    int n=A.size(),m=A[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    vector<vector<int>>dp2(n+1,vector<int>(m+1,0));
 
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
 
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++)
    {
        q.push({i,0});
        dp[i][0]=1;
    }
    for(int i=1;i<m;i++)
    {
        q.push({0,i});
        dp[0][i]=1;
    }
    int ans=0;
 
    while(!q.empty())
    {
        pair<int,int> curr=q.front();
        q.pop();
        int currX=curr.first;
        int currY=curr.second;
        dp[currX][currY]=1;
 
        for(int i=0;i<4;i++)
        {
            int moveX=currX+dx[i];
            int moveY=currY+dy[i];
            if(isValid(moveX,moveY,n,m))
            {
                if(A[moveX][moveY]>=A[currX][currY])
                {
                    if(dp[moveX][moveY]!=1)
                    {
                        q.push({moveX,moveY});
                        dp[moveX][moveY]=1;
                    }
                }
            }
        }
    }
 
    for(int i=0;i<n;i++)
    {
        q.push({i,m-1});
        dp2[i][m-1]=1;
    }
    for(int i=0;i<m-1;i++)
    {
        q.push({n-1,i});
        dp2[n-1][i]=1;
    }
 
    while(!q.empty())
    {
        pair<int,int> curr=q.front();
        q.pop();
        int currX=curr.first;
        int currY=curr.second;
        
        if(dp[currX][currY]+dp2[currX][currY]==2)
            ans++;
 
        for(int i=0;i<4;i++)
        {
            int moveX=currX+dx[i];
            int moveY=currY+dy[i];
            if(isValid(moveX,moveY,n,m))
            {
                if(A[moveX][moveY]>=A[currX][currY])
                {
                    if(dp2[moveX][moveY]!=1)
                    {
                        q.push({moveX,moveY});
                        dp2[moveX][moveY]=1;
                    }
                }
            }
        }
    }
 
    return ans;
}
