class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";

        }

       
        unordered_map<char, int> need, window;
        int matches = 0;

        for (char c : t) {
            need[c]++;

        }
   int have = 0, needCount = need.size();
    int left = 0, minLen = INT_MAX, start = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        window[c]++;

        if (need.count(c) && window[c] == need[c]) {
            have++;
        }

        while (have == needCount) {
            // update result
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            // shrink from left
            char l = s[left];
            window[l]--;
            if (need.count(l) && window[l] < need[l]) {
                have--;
            }
            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}



    };
