class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> unique;
        int result = 0;
        int front = 0;
        int back = 0;



        for (int back = 0; back < s.length(); back++) {

            while (unique.find(s[back]) != unique.end()) {
                unique.erase(s[front]);
                front++;
                
                
            }

            unique.insert(s[back]);
            result = max(result, back - front + 1);


        }

        return result;
        
    }
};
