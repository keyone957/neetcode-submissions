class Solution {
public:
    string reorganizeString(string s) {
        string answer;
        int alphaCnt[26]={};
        int size=s.size();
        priority_queue<pair<int ,char>> pq;
        //문자가 나온 횟수 , 문자
        for(int i=0;i<size;i++)
        {
            alphaCnt[s[i]-'a']++;
        }
        int maxCnt=-1;
        for(int i=0;i<26;i++)
        {
            maxCnt=max(maxCnt,alphaCnt[i]);
            if(alphaCnt[i]>0)
            {
                pq.push({alphaCnt[i],i+'a'});
            }
        }
        if(maxCnt>(size+1)/2)
        // 가장 많이 나온 값이 이 값을 초과하면
        //사이사이에 다른 문자를 넣어서 연속적으로 문자 배치 방지가 불가능함 
        //따라서 이때는 불가능한 경우
        {
            return "";
        }
        char checkStr='-';
        for(int i=0;i<size;i++)
        {
            char cur=pq.top().second;
            int cnt=pq.top().first;
            pq.pop();
            if(cur!=checkStr)
            {
                cnt--;
                if(cnt>0)
                {
                    pq.push({cnt,cur});
                }
                answer+=cur;
                checkStr=cur;
            }
            else
            {
                if(pq.empty())
                {
                    //다른 문자 선택할 수 없음?
                }
                char cur2=pq.top().second;
                int cnt2=pq.top().first;
                pq.pop();
                cnt2--;
                if(cnt2>0)
                {
                    pq.push({cnt2,cur2});
                }
                pq.push({cnt,cur});
                answer+=cur2;
                checkStr=cur2;
                //두번째 문자 사용?
            }
            
        }
        
        return answer;
        
    }
};