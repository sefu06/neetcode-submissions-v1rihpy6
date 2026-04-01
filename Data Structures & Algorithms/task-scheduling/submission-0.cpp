class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         vector<int> count(26, 0);
         int time = 0;
        for (char task : tasks) {
            count[task - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (int cnt : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }

        queue<pair<int, int>> q;
        

        while (maxHeap.size() != 0 || q.size() != 0) {
            time++;
            int freq = 0;
            if (maxHeap.size() != 0) {
            freq = maxHeap.top();
            maxHeap.pop();
            }
            

            if (freq-1 > 0) {
            q.push({freq-1, time + n});
            }

            if (q.size() != 0 && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();

            }



        }

        return time;
        
    }
};
