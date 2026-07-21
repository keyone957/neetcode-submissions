class Solution {
int dp1[101];//첫번째 집부터 시작 해서 마지막 집을 제외하는 경우
int dp2[101];//두번째 집부터 시작해서 마지막 집에서 끝남
public:
    int rob(vector<int>& nums) {
        
        int arrSize=nums.size();
        if (arrSize == 1) return nums[0];
        dp1[0]=nums[0];
        dp1[1]=max(nums[1],nums[0]);
        for(int i=2;i<arrSize-1;i++)
        {
            dp1[i]=max(dp1[i-1],dp1[i-2]+nums[i]);
        }

        dp2[0]=0;
        dp2[1]=nums[1];
        for(int i=2;i<arrSize;i++)
        {
            dp2[i]=max(dp2[i-1],dp2[i-2]+nums[i]);
        }
        return max(dp2[arrSize-1],dp1[arrSize-2]);
    }
};
