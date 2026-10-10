class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "C") {
                scores.pop_back();
            }
            else if (operations[i] == "D") {
                scores.push_back(scores.back() * 2);
            }
            else if (operations[i] == "+") {
                int size = scores.size();
                scores.push_back(scores[size - 1] + scores[size - 2]);
            }
            else {
                scores.push_back(stoi(operations[i]));
            }
        }

        int answer = 0;
        for (int i = 0; i < scores.size(); i++) {
            answer += scores[i];
        }

        return answer;
    }
};