class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int y=matrix.size();
        int x=matrix[0].size();
        vector<pair<int,int>> points;
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(matrix[i][j]==0)
                {
                    points.push_back({i,j});
                }
            }
        }
        for(int i=0;i<points.size();i++)
        {
            int row = points[i].first;
            int col = points[i].second;

            // 해당 행 전체를 0으로
            for(int j=0;j<x;j++)
            {
                matrix[row][j] = 0;
            }

            // 해당 열 전체를 0으로
            for(int j=0;j<y;j++)
            {
                matrix[j][col] = 0;
            }
        }
    }
};
