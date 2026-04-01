class Solution {
    /*
    my thinking:
    perform bfs with words in wordlist, we do this by:
    first check if end word not in wordlist return 0;

    add beginWord in the queue. then while queue is not empty, 
    pop first word in queue.
    if word = endword return steps
    add all possible next words to queue
    */
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end())
            return 0;

            queue<pair<int, string>> q;
            unordered_set<string> visited;

            q.push({1, beginWord});
            visited.insert(beginWord);

            while (!q.empty()) {
                pair<int, string> front = q.front();
                q.pop();
                string word = front.second;
                int steps = front.first;
                if (word == endWord) {
                    return steps;

                }

                 for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) continue;

                    word[i] = c;

                    if (wordSet.count(word) && !visited.count(word)) {
                        visited.insert(word);
                        q.push({steps + 1, word});
                    }
                }

                word[i] = original; // restore
            }

            }

            return 0;
        
    }

    
};
