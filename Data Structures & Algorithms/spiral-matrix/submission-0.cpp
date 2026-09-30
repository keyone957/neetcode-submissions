class Solution {
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int x=matrix[0].size();
        int y=matrix.size();
        bool visit[20][20]={};
        int curX=0;
        int curY=0;
        int dir=0;
        visit[curY][curX]=true;
        while(true)
        {
            answer.push_back(matrix[curY][curX]);
            if(answer.size()==x*y)
            {
                break;
            }
            int nx=curX+dx[dir];
            int ny=curY+dy[dir];
            if (nx < 0 || ny < 0 || nx >= x || ny >= y || visit[ny][nx])
            {
                dir = (dir + 1) % 4;
                nx = curX + dx[dir];
                ny = curY + dy[dir];
            }
            curX = nx;
            curY = ny;
            visit[curY][curX] = true;
        }
        return answer;
    }
};
