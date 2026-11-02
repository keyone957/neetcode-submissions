class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int arrSize=nums.size();
        int left=0;
        int right=arrSize-1;
        int mid=0;

        while(left<=right)
        {
            mid=(left+right)/2;
            int lVal=nums[left];
            int rVal=nums[right];
            int midVal=nums[mid];
            if(lVal<midVal)
            //왼쪽 구간 정렬
            {
                if(lVal <= target && target < midVal)
                //왼쪽 구간에 만약에 
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else if(lVal==midVal)
            {
                left++;
            }
            else
            //오른쪽 구간이 정렬
            {
                if(rVal>=target&&target>midVal)
                {
                    right=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            if(midVal==target)
            {
                return true;
            }
        }
    
        
        

        return false;
    }
};