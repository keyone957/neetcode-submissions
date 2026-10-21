class StockSpanner {
stack<pair<int,int>>st;
int curDay=0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int answer=1;
        curDay++;
        if(curDay==1)
        {
            st.push({price,curDay}); 
            return 1;
        }
        while(!st.empty())
        {
            if(st.top().first<=price)
            {
                st.pop();
                if(!st.empty())
                {
                    answer=curDay-st.top().second;
                }                
                else
                {
                    answer=curDay;
                }
            }
            else break;
        }
        st.push({price,curDay});
        
        return answer;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */