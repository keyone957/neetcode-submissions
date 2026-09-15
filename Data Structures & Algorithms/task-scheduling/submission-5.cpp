class Solution {
int count[26]={};
public:
    int leastInterval(vector<char>& tasks, int n) {
        int arrSize=tasks.size();
        for(int i=0;i<arrSize;i++)
        {
            count[tasks[i]-'A']++;
        }

        int maxCnt=*max_element(count,count+26);
        int maxTypeCnt = 0;

        for (int i = 0; i < 26; i++)
        {
            if (count[i] == maxCnt)
            {
                maxTypeCnt++;
            }
        }
        int answer;
        answer=(maxCnt-1)*(n+1)+maxTypeCnt;
        
        answer=max(arrSize,answer);

        return answer;
    }
};
