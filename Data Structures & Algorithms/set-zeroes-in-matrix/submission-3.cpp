class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int xSize = matrix[0].size();
        int ySize = matrix.size();

        bool firstRowZero = false;

        // 첫 번째 행과 열을 마커로 사용
        for (int i = 0; i < ySize; i++)
        {
            for (int j = 0; j < xSize; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // j번째 열을 0으로 만들어야 함
                    matrix[0][j] = 0;

                    if (i > 0)
                    {
                        // i번째 행을 0으로 만들어야 함
                        matrix[i][0] = 0;
                    }
                    else
                    {
                        // 첫 번째 행 자체가 0이 되어야 함
                        firstRowZero = true;
                    }
                }
            }
        }

        // 마커를 이용해서 내부 영역 처리
        for (int i = 1; i < ySize; i++)
        {
            for (int j = 1; j < xSize; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 첫 번째 열 처리
        if (matrix[0][0] == 0)
        {
            for (int i = 0; i < ySize; i++)
            {
                matrix[i][0] = 0;
            }
        }

        // 첫 번째 행 처리
        if (firstRowZero)
        {
            for (int j = 0; j < xSize; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }
};