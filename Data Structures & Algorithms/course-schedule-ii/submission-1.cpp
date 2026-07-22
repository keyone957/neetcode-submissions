class Solution {
/*
예를 들어, 쌍 [0, 1]은  1->0 을 수강해야 함을 나타냅니다.
*/
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& arr) {
        queue<int> q;
        int arrSize=arr.size();
        vector<int> linkedList[1001];
        int indegree [1001];
        vector<int> answer;
        for(int i=0;i<arrSize;i++)
        {
            int start=arr[i][1];
            int end=arr[i][0];
            linkedList[start].push_back(end);
            indegree[end]++;
        }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int cur=q.front();q.pop();
            answer.push_back(cur);
            for(int i=0;i<linkedList[cur].size();i++)
            {
                int next=linkedList[cur][i];
                indegree[next]--;
                if(indegree[next]==0)
                {
                    q.push(next);
                }
            }
        }
        if(answer.size()!=numCourses)
        {
            answer.clear();
        }
        return answer;
    }
};
