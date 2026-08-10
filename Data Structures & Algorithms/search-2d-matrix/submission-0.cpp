class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int y=matrix.size();
        int x=matrix[0].size();
        int left=0;
        int right=y*x-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            int midY=mid/x;
            int midX=mid%x;
            if(matrix[midY][midX]<target)
            {
            
                 left=mid+1;
            }
            else if(matrix[midY][midX]>target)
            {
                right=mid-1;
            }
            else
            {
                return true;
            }


        }
        return false;
    }
};
