class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();

        // 항상 smaller가 더 작은 배열이 되도록 설정
        vector<int>& smaller = (size1 <= size2) ? nums1 : nums2;
        vector<int>& bigger = (size1 <= size2) ? nums2 : nums1;

        int left=0;
        int right=smaller.size();
        int totalSize=size1+size2;
        while(left<=right)
        {
            // smaller에서 왼쪽 집합에 넣을 원소 개수
            int smallerSize = (left + right) / 2;

            // bigger에서 왼쪽 집합에 넣을 원소 개수
            int biggerSize = ((totalSize + 1) / 2) - smallerSize;

            int l1, r1, l2, r2;
            // smaller 왼쪽 집합의 가장 큰 값
            if(smallerSize == 0)
            {
                l1 = INT_MIN;
            }
            else
            {
                l1 = smaller[smallerSize - 1];
            }

            // smaller 오른쪽 집합의 가장 작은 값
            if(smallerSize == smaller.size())
            {
                r1 = INT_MAX;
            }
            else
            {
                r1 = smaller[smallerSize];
            }

            // bigger 왼쪽 집합의 가장 큰 값
            if(biggerSize == 0)
            {
                l2 = INT_MIN;
            }
            else
            {
                l2 = bigger[biggerSize - 1];
            }

            // bigger 오른쪽 집합의 가장 작은 값
            if(biggerSize == bigger.size())
            {
                r2 = INT_MAX;
            }
            else
            {
                r2 = bigger[biggerSize];
            }

            // 올바른 분할을 찾은 경우
            if(l1 <= r2 && l2 <= r1)
            {
                // 전체 원소 개수가 짝수
                if(totalSize % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                // 전체 원소 개수가 홀수
                else
                {
                    return max(l1, l2);
                }
            }

            // smaller에서 왼쪽으로 너무 많이 가져온 경우
            else if(l1 > r2)
            {
                right = smallerSize - 1;
            }

            // smaller에서 왼쪽으로 너무 적게 가져온 경우
            else
            {
                left = smallerSize + 1;
            }
            

        }
        return 0;
    }
};
