class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int xSize=matrix[0].size();
        int ySize=matrix.size();
        bool x[201]={};
        bool y[201]={};
        for(int i=0;i<ySize;i++)
        {
            for(int j=0;j<xSize;j++)
            {
                if(matrix[i][j]==0)
                {
                    x[j]=true;
                    y[i]=true;
                }
            }
        }
        // true인 행을 전부 0으로
        for(int i = 0; i < ySize; i++)
        {
            if(y[i])
            {
                for(int j = 0; j < xSize; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // true인 열을 전부 0으로
        for(int j = 0; j < xSize; j++)
        {
            if(x[j])
            {
                for(int i = 0; i < ySize; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
