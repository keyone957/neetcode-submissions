class Solution {
public:
    int search(vector<int>& nums, int target) {
        int arrSize=nums.size();
        int left=0;
        int right=arrSize-1;
        int mid=0;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<nums[right])
            //오른쪽에 정렬
            {
                if(nums[mid]<target&&target<=nums[right])
                {
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            else
            //왼쪽에 정렬
            {
                if(nums[left]<=target&&target<nums[mid])
                {
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
        }
        return -1;
    }
};
