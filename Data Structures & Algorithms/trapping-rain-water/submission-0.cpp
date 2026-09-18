class Solution {
public:
    int trap(vector<int>& height) {
        int answer=0;
        int arrSize=height.size();
        int left=0;
        int right=arrSize-1;
        int leftMax=height[left];
        int rightMax=height[right];
        while(left<right)
        {
            if(height[left]<height[right])
            {
                if(leftMax>height[left])
                {
                    answer+=leftMax-height[left];
                }
                else
                {
                    leftMax=height[left];
                }
                left++;
                
            }
            else
            {
                if(rightMax>height[right])
                {
                    answer+=rightMax-height[right];
                }
                else
                {
                    rightMax=height[right];
                }
                right--;
            }
        }
        return answer;
    }
};
