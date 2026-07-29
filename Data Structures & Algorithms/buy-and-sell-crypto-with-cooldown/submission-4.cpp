class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)
        {
            return 0;
        }
        int dp[1001][2]={};
        /*
        i번째 날에 주식을 보유 중일 때 최대 이익 dp[i][0]
        i번째 날에 주식을 보유하지 않았을 때 최대 이익 dp[i][1]
        */
        dp[0][0]=-prices[0];
        //0일차에 주식 매수 팔지 않았으니 순이득은 산 주식의 가격
        dp[0][1]=0;
        //안사면 그냥 0

        dp[1][0]= max(dp[0][0],-prices[1]);
        //1일차 주식 보유
        //0번째 날 산 주식 계속 보유중인  vs 
        //0번째에 안사고 1일차에 처음 주식사는 이익
        dp[1][1]=max(dp[0][1],dp[0][0]+prices[1]);
        //1일차 주식 미보유
        //0일차에 안사고 1일차에도 안살때 이득 vs
        //0일차에 산 주식을 1일차에 판매 한 경우의 이득
        
        for(int i=2;i<prices.size();i++)
        {
           dp[i][0]=max(dp[i-1][0],dp[i-2][1]-prices[i]);
           //i번째 주식 보유했을 때
           //전날 보유했을 때 vs
           //쿨다운 종료 후 오늘 새로 매수 했을 때.
           dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]);
        }

       return dp[prices.size()-1][1];
    }
};
