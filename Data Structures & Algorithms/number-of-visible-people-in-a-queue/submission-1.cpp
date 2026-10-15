class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int aSize=heights.size();
        stack<int> st;
        vector<int> answer(aSize,0);
        for(int i=0;i<aSize;i++)
        {
           while (!st.empty())
           {
            if (heights[st.top()] < heights[i]) 
            {
                answer[st.top()]++;
                st.pop();
            } 
            else
            {
                break;
            }
        }
        if (!st.empty()) {
            answer[st.top()]++;
        }
        st.push(i);
        }
        return answer;
        
    }
};