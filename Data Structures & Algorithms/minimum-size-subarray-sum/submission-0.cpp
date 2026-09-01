class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int arrSize=nums.size();
        int left=0;
        int right=0;
        int curSum=0;
        int answer=1e9;

        for (int right = 0; right < arrSize; right++)
        {
            curSum += nums[right];

            while (curSum >= target)
            {
                answer = min(answer, right - left + 1);

                curSum -= nums[left];
                left++;
            }
        }

        if (answer == 1e9)
            return 0;

        return answer;
    }
};