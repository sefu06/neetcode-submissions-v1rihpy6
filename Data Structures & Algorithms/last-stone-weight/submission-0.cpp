class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> maxHeap;

        for (int stone : stones) {
        maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int heaviest = maxHeap.top();
            maxHeap.pop();
            int secondHeaviest = maxHeap.top();
            maxHeap.pop();

            if (heaviest != secondHeaviest) {
                int newWeight = heaviest - secondHeaviest;
                maxHeap.push(newWeight);

            }

        }

        if (maxHeap.size() == 0) {
            return 0;

        } else {
            return maxHeap.top();
        }
        
    }
};
