class Solution {
    int cnt[26] = {};
    int cur[26] = {};

public:
    vector<int> findAnagrams(string s, string p) {
        int pSize = p.size();
        int sSize = s.size();
        vector<int> answer;

        if (sSize < pSize)
        {
            return answer;
        }

        for (int i = 0; i < pSize; i++)
        {
            cur[p[i] - 'a']++;
        }

        for (int i = 0; i < sSize; i++)
        {
            cnt[s[i] - 'a']++;

            if (i >= pSize)
            {
                cnt[s[i - pSize] - 'a']--;
            }

            if (i >= pSize - 1)
            {
                bool isSame = true;

                for (int j = 0; j < 26; j++)
                {
                    if (cnt[j] != cur[j])
                    {
                        isSame = false;
                        break;
                    }
                }

                if (isSame)
                {
                    answer.push_back(i - pSize + 1);
                }
            }
        }

        return answer;
    }
};