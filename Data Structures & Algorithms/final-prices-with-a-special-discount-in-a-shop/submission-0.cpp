class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int aSize=prices.size();
        stack<int> st;
        st.push(0);
        vector<int> answer;
        answer=prices;
        for(int i=1;i<aSize;i++)
        {
            while(!st.empty())
            {
                if(answer[st.top()]>=prices[i])
                {
                    answer[st.top()]=prices[st.top()]-prices[i];
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            st.push(i);
        }
        return answer;
    }
};
