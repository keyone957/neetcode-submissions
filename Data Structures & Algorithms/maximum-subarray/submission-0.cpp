class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int aSize=nums.size();
        int answer=nums[0];
        int curSum=nums[0];

        for(int i=1;i<aSize;i++)
        {
           curSum = max(curSum + nums[i], nums[i]);
           answer = max(curSum, answer);
        }


        return answer;
    }
};
