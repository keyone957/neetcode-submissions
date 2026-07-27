class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<int> adj[26]; 
        int indegree[26]={};
        string answer;
        int wSize=words.size();
        fill(indegree,indegree+26,-1);
        int wordCnt=0;
        for(int i=0;i<wSize;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                int idx= words[i][j]-'a';
                if(indegree[idx]==-1)
                {
                    indegree[idx]=0;
                    wordCnt++;
                }
            }
        }
        for(int i=0;i<wSize-1;i++)
        {
            string first=words[i];
            string second =words[i+1];
            int minSize=min(first.size(),second.size());
            bool isDifferent=false;
            //안되는 경우를 찾기 위한 bool값
            for(int j=0;j<minSize;j++)
            {
                auto it=find(adj[first[j]-'a'].begin(),adj[first[j]-'a'].end(),second[j]-'a');
                if(first[j]!=second[j])//만약에 첫번째로 다른 문자가 나왔을 때
                {
                    isDifferent=true;
                    if(it==adj[first[j]-'a'].end())
                    //중복된 간선이 있는지 확인하고 중복된 간선이 아니라면 넣고 indegree증가
                    {
                        adj[first[j]-'a'].push_back(second[j]-'a');
                        indegree[second[j]-'a']++;
                    }
                    break;
                }
            }
            if(!isDifferent&&(first.size()>second.size()))
            {
                return "";
            }
        }
        queue<int> q;
     
        for(int i=0;i<26;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            answer+=cur+'a';
            for(int i=0;i<adj[cur].size();i++)
            {
                int next=adj[cur][i];
                indegree[next]--;
                if(indegree[next]==0)
                {
                    q.push(next);
                }
            }
        }
        if(answer.size()!=wordCnt)
        {

            return "";
        }
        return answer;
    }
};
