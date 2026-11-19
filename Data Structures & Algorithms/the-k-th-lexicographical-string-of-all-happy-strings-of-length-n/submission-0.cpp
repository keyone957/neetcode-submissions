class Solution {
    vector<string> cur;
    string path;
    int count;

    void dfs(int cnt)
    {
        if (cnt == count)
        {
            cur.push_back(path);
            return;
        }

        for (int i = 0; i < 3; i++)
        {
            char c = 'a' + i;

            // 이전 문자와 현재 문자가 같으면 건너뛰기
            if (!path.empty() && path.back() == c)
            {
                continue;
            }

            // 현재 문자 선택
            path.push_back(c);

            // 다음 문자 탐색
            dfs(cnt + 1);

            // 선택했던 문자 제거 (백트래킹)
            path.pop_back();
        }
    }

public:
    string getHappyString(int n, int k) {
        string answer = "";
        count = n;

        dfs(0);

        // k번째 문자열이 존재하지 않는 경우
        if (k > cur.size())
        {
            return "";
        }

        answer = cur[k - 1];

        return answer;
    }
};