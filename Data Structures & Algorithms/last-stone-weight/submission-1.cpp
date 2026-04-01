class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> maxHeap;
        for (int stone : stones) {
            maxHeap.push(stone);

        }
        while (maxHeap.size() > 1) {
            int firstTop = maxHeap.top();
            maxHeap.pop();
            int secondTop = maxHeap.top();
            maxHeap.pop();

            if (firstTop > secondTop) {
                maxHeap.push(firstTop - secondTop);

            }
  
        }

        if (maxHeap.empty()) {
            return 0;

        } else {
            return maxHeap.top();
        }
        
    }
};
