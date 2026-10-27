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
            //현재 구간의 곱이 k이상이면 조건을 만족하지 못함
            //따라서 k미만이 될때 까지 left를 이동시켜 구간을 나눔
            {
                curMulti/=nums[left];
                //제외된 구간을 현재 값에서 제거
                left++;
            }
            

            answer+=right-left+1;
            right++;
        }

        return answer;
    }
};