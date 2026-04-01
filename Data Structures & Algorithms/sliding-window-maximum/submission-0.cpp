class Solution {
    /*
    initialize sliding window with left=0, right=k-1
    add the indices and values of the first window into a max heap.
    then for each new window we check if index is still in that window and
    then if it isnt, we remove from the heap until we find a place in the array
    that is in the window.
    */
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int left = 0;
        int right = k-1;
        priority_queue<pair<int,int>> maxHeap;

        for (int i = 0; i < k; i++) {
            maxHeap.push({nums[i], i});
        }

        left++;
        right++;

        result.push_back(maxHeap.top().first);

        while (right < nums.size()) {
            maxHeap.push({nums[right], right});
            
            while (left > maxHeap.top().second ||  maxHeap.top().second > right ) {
                maxHeap.pop();
            }

            result.push_back(maxHeap.top().first);

            left++;
            right++;


        }

        return result;
        
    }
};
