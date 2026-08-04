class Solution {
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int visit[101][101]={};
        int y=matrix.size();
        int x=matrix[0].size();
        int minDist=0;
        int indegree[101][101]={};
        queue<pair<int,int>> q;

        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                for(int dir=0;dir<4;dir++)
                {
                    int ny=i+dx[dir];
                    int nx=j+dy[dir];
                    if(ny<0||nx<0||nx>=x||ny>=y) continue;
                    if(matrix[ny][nx]<matrix[i][j])
                    {
                        indegree[i][j]++;
                    }
                }
            }
        }
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(indegree[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            int size=q.size();
            minDist++;
            while(size--)
            {
                pair<int ,int> cur=q.front();
                int curX=cur.second;
                int curY=cur.first;
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int nextX=curX+dx[i];
                    int nextY=curY+dy[i];
                    if(nextX<0||nextY<0||nextX>=x||nextY>=y)continue;
                    if(matrix[nextY][nextX]>matrix[curY][curX])
                    {
                        indegree[nextY][nextX]--;
                        if(indegree[nextY][nextX]==0)
                        {
                            q.push({nextY,nextX});
                        }
                    }

                }

            }

        }


        return minDist;

    }
};
