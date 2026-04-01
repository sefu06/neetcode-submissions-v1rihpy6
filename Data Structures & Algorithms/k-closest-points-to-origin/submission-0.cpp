class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue <pair<int, vector<int>>, vector<pair<int, vector<int>>>,greater<>> minHeap;
    vector<vector<int>> result;

        for (vector<int> point : points) {
            int distance = point[0]*point[0] + point[1]*point[1];
            minHeap.push({distance, point});

        }

        for (int i = 0; i < k; i++) {
            result.push_back(minHeap.top().second);
            minHeap.pop();


        }

        return result;
        
    }
};
