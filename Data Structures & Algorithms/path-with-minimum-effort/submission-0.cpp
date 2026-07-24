/*
한칸 한칸 이동할때 최대한 적은 비용을 가지는 경로로 가서 마지막에 그 
각 칸 마다 이동하는 비용을 출력
*/
class Solution {
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int efforts[101][101]={};
        int ySize=heights.size();
        int xSize=heights[0].size();
        for (int y = 0; y < ySize; y++)
        {
            for (int x = 0; x < xSize; x++)
            {
                efforts[y][x] = INT_MAX;
            }
        }

        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        pq.push({0,{0,0}});
        efforts[0][0]=0;
        while(!pq.empty())
        {
            pair<int,pair<int,int>> cur=pq.top();
            int curEffort=cur.first;
            pair<int,int> curPos=cur.second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int curY=curPos.first;
                int curX=curPos.second;

                int nextY = curY + dy[i];
                int nextX = curX + dx[i];

                if(nextY < 0 || nextY >= ySize ||nextX < 0 || nextX >= xSize){continue;}
                int effort=abs(heights[curY][curX]-heights[nextY][nextX]);
                int nextEffort=max(curEffort,effort);

                if(nextEffort < efforts[nextY][nextX])
                {
                    efforts[nextY][nextX] = nextEffort;
                    pq.push({nextEffort, {nextY, nextX}});
                }
            }

        }
        return efforts[ySize-1][xSize-1];

    }
};