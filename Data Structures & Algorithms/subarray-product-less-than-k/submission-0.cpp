class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int aSize=nums.size();
        int left=0;
        int right=0;
        int curMulti=1;
        int answer=0;

        while(right<aSize)
        {
            curMulti*=nums[right];

            while(curMulti>=k && left<=right)
            {
                curMulti/=nums[left];
                left++;
            }

            answer+=right-left+1;
            right++;
        }

        return answer;
    }
};