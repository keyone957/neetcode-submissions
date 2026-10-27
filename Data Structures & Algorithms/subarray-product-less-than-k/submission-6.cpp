class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int aSize=nums.size();
        int answer=0;
        int left=0;

        if(k<=1)
        {
            return 0;
        }

        // 누적 로그 배열
        vector<double> prefix(aSize+1,0);

        for(int i=0;i<aSize;i++)
        {
            prefix[i+1]=prefix[i]+log(nums[i]);
        }

        double target=log(k);

        while(left<aSize)
        {
            int low=left;
            int high=aSize-1;
            int right=left-1;

            while(low<=high)
            {
                int mid=low+(high-low)/2;

                // nums[left]부터 nums[mid]까지의 곱을
                // 로그의 합으로 비교
                double curSum=prefix[mid+1]-prefix[left];

                if(curSum<target-1e-10)
                {
                    right=mid;
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }

            answer+=right-left+1;
            left++;
        }

        return answer;
    }
};