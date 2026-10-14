class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> answer;
        int aSize=heights.size();
        /*
        단조 감소 스택
        처음으로 오른쪽에서 현재 건물보다 
        큰 걸 만나면 answer배열에 넣지 않고 순회 끝
        */
        stack<int> st;
        st.push(0);

        for(int i=1;i<aSize;i++)
        {
            while(!st.empty())
            {
                if(heights[st.top()]<=heights[i])
                {
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            st.push(i);
        }
        int s=st.size();
        for(int i=s;i>0;i--)
        {
            answer.push_back(st.top());
            st.pop();
        }
        sort(answer.begin(),answer.end());
        return answer;
    }
};