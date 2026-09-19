class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // 두 포인터가 가리키는 문자를 교환
            std::swap(s[left], s[right]);
            
            // 포인터 이동
            left++;
            right--;
        }
    }
};