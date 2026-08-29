class Solution {
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int y=grid.size();
        int x=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            pair<int,int> cur=q.front();
            q.pop();
            for(int dir=0;dir<4;dir++)
            {
                int nextY=cur.first+dy[dir];
                int nextX=cur.second+dx[dir];
                if(nextX<0||nextY<0||nextX>=x||nextY>=y) continue;
                if(grid[nextY][nextX]!=2147483647) continue;
                grid[nextY][nextX] = grid[cur.first][cur.second] + 1;
                q.push({nextY,nextX});

            }
        }
    }
};
