class Solution {
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
public:
    int numIslands(vector<vector<char>>& grid) {
        bool visit[101][101];
        queue<pair<int,int>> q;
        int answer=0;
        int y=grid.size();
        int x=grid[0].size();
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(!visit[i][j]&&grid[i][j]=='1')
                {
                    q.push({i,j});
                    visit[i][j]=true;
                    while(!q.empty())
                    {
                        pair<int,int>cur =q.front();
                        q.pop();
                        for(int dir=0;dir<4;dir++)
                        {
                            int nextY=cur.first+dy[dir];
                            int nextX=cur.second+dx[dir];
                            if(nextY<0||nextX<0||nextY>=y||nextX>=x)continue;
                            if(grid[nextY][nextX] == '0') continue;
                            if(visit[nextY][nextX]) continue;
                            q.push({nextY,nextX});
                            visit[nextY][nextX]=true;
                        }
                    }
                        answer++;

                }
            }
        }

        return answer;
    }
};
