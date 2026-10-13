class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int arrSize=temperatures.size();
        stack<int> st;
        vector<int>answer(arrSize,0);
        st.push(0);
        for(int i=1;i<arrSize;i++)
        {
            // int cur=temperatures[i];
            while(!st.empty())
            {
                if(temperatures[st.top()]<temperatures[i])
                {
                    // answer.push_back(i-st.top());
                    answer[st.top()]=i-st.top();
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            st.push(i);
        }
        // for(int i=0;i<answer.size();i++)
        // {
        //     cout<<answer[i]<<' ';
        // }
        return answer;
    }
};
