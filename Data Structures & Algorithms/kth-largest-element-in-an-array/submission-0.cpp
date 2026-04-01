class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<>> maxHeap;

        for (int num : nums) {
            maxHeap.push(num);

        }

        int result = 0;

        for (int i = 0; i < k; i++) {
            result = maxHeap.top();
            maxHeap.pop();

        }

        return result;
        
    }
};
