class Solution {
public:
    int trap(vector<int>& height) {
        int aSize=height.size();
        stack<int> st;// 인덱스 저장
        st.push(0);
        int answer=0;
        for(int i=1;i<aSize;i++)
        {
            while(!st.empty())
            {
                if(height[st.top()]<height[i])
                {
                    int curIndx=st.top();
                    st.pop();
                    if(st.empty()) break;
                    int curH=min(height[st.top()],height[i])-height[curIndx];
                    int water=curH*(i-st.top()-1);
                    answer+=water;
                }
                else break;
            }
            st.push(i);
        }

        return answer;
    }
};
