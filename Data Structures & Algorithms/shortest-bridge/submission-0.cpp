class Solution {
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
public:
    int shortestBridge(vector<vector<int>>& grid) 
    {
        int y=grid.size();
        int x=grid[0].size();
        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;
        bool visit1[100][100]={};
        bool found = false;
        int answer=0;

        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                if (grid[i][j] == 1)
                {
                    q1.push({i, j});
                    q2.push({i, j});
                    visit1[i][j] = true;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        while(!q1.empty())
        {
            pair<int,int> cur=q1.front();
            q1.pop();
            for(int i=0;i<4;i++)
            {
                int nextY=cur.first+dy[i];
                int nextX=cur.second+dx[i];
                if(nextX<0||nextY<0||nextX>=x||nextY>=y) continue;
                if(grid[nextY][nextX]==0) continue;
                if(visit1[nextY][nextX])continue;
                q2.push({nextY,nextX});
                q1.push({nextY,nextX});
                visit1[nextY][nextX]=true;
            }
        }
    while (!q2.empty())
    {
        int qSize = q2.size();

        for (int cnt = 0; cnt < qSize; cnt++)
        {
            pair<int,int> cur = q2.front();
            q2.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nextY = cur.first + dy[dir];
                int nextX = cur.second + dx[dir];

                if (nextX < 0 || nextY < 0 ||
                    nextX >= x || nextY >= y)
                    continue;

                if (visit1[nextY][nextX])
                    continue;

                // 다른 섬 도착
                if (grid[nextY][nextX] == 1)
                {
                    return answer;
                }

                // 바다 확장
                visit1[nextY][nextX] = true;
                q2.push({nextY, nextX});
            }
        }

        answer++;
    }
        
        return answer;
    }
};