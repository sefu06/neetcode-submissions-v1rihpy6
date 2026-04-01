class Solution {
public:
    int characterReplacement(string s, int k) {
        int front = 0;
        int result = 0;
        int maxFreq = 0;
        vector<int> freq(26, 0);

       

        for (int back = 0; back < s.length(); back++) {
            freq[s[back] - 'A']++;
            maxFreq = max(maxFreq, freq[s[back] - 'A']);

            while (back-front+1 > maxFreq+k) { //invalid window
                freq[s[front]-'A']--;
                front++;


            }
            result = max(result, back-front+1);
            

            
           
        
    }

    return result;

    }

};
