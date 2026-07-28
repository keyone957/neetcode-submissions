class Solution {
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        bool pVisit[101][101]={false};
        bool aVisit[101][101]={false};
        queue<pair<int,int>> pQ;
        queue<pair<int,int>> aQ;
        int y=heights.size();
        int x=heights[0].size();
        vector<vector<int>> answer;
        for(int i=0;i<x;i++)
        {
            pQ.push({0,i});
            pVisit[0][i]=true;
        }
        for(int i=0;i<y;i++)
        {
            if(!pVisit[i][0])
            {
                pQ.push({i,0});
                pVisit[i][0]=true;
            }
        }

        for(int i=0;i<x;i++)
        {
            aQ.push({y-1,i});
            aVisit[y-1][i]=true;
        }
        for(int i=0;i<y;i++)
        {
            if(!aVisit[i][x-1])
            {
                aQ.push({i,x-1});
                aVisit[i][x-1]=true;
            }
        }

        while(!pQ.empty())
        {
            pair<int,int> cur=pQ.front();pQ.pop();
            for(int i=0;i<4;i++)
            {
                int nextX=cur.second+dx[i];
                int nextY=cur.first+dy[i];
                if(nextX<0||nextY<0||nextX>=x||nextY>=y) continue;
                if(pVisit[nextY][nextX]) continue;
                if(heights[cur.first][cur.second]>heights[nextY][nextX])continue;
                pQ.push({nextY,nextX});
                pVisit[nextY][nextX]=true;

            }
        }

        while(!aQ.empty())
        {
            pair<int,int> cur=aQ.front();aQ.pop();
            for(int i=0;i<4;i++)
            {
                int nextX=cur.second+dx[i];
                int nextY=cur.first+dy[i];
                if(nextX<0||nextY<0||nextX>=x||nextY>=y) continue;
                if(aVisit[nextY][nextX]) continue;
                if(heights[cur.first][cur.second]>heights[nextY][nextX])continue;
                aQ.push({nextY,nextX});
                aVisit[nextY][nextX]=true;

            }
        }
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(aVisit[i][j]&&pVisit[i][j])
                {
                    answer.push_back({i,j});
                }
            }
        }
        return answer;

    }
};
