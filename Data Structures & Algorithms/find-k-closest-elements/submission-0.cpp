class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int arrSize=arr.size();
        int left=0;
        int right=arrSize-1;
        for(int i=0;i<arrSize-k;i++)
        {
            if (abs(arr[left] - x) > abs(arr[right] - x))
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        vector<int> answer;
        for(int i=left;i<=right;i++)
        {

            answer.push_back(arr[i]);
        }


        return answer;
    }
};