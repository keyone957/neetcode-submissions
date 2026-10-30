class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int aSize=nums1.size();
        int bSize=nums2.size();
        int left=m-1;
        int right=n-1;
        int nums1P=m+n-1; //=> nums1 배열에 들어갈 위치.
        while(left>=0&&right>=0)
        {
            int lVal=nums1[left];
            int rVal=nums2[right];
            if(lVal<rVal)
            {
                nums1[nums1P]=rVal;
                nums1P--;
                right--;
            }
            else
            {
                nums1[nums1P]=lVal;
                nums1P--;
                left--;
            }
        }
        if(right>=0)
        {
            while(right>=0)
            {
                nums1[nums1P]=nums2[right];
                nums1P--;
                right--;
            }

        }
        
    }
};