class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        int s1=nums1.size();
        int s2=nums2.size();
        stack<int> st;
        unordered_map<int,int> curInfo;
        st.push(nums2[0]);
        for(int i=1;i<s2;i++)
        {
            int cur=nums2[i];
            while(!st.empty())
            {
                if(st.top()<cur)
                {
                    curInfo.insert({st.top(),cur});
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            st.push(cur);
        }
        for(int i=0;i<s1;i++)
        {
            if(curInfo.find(nums1[i])==curInfo.end())
            {
                answer.push_back(-1);
            }
            else
            {
                answer.push_back(curInfo[nums1[i]]);
            }
        }
        // for(int i=0;i<s1;i++)
        // {
        //     cout<<answer[i];
        // }
        return answer;
    }
};