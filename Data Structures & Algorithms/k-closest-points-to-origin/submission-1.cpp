class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<vector<int>> result;

        for (vector<int> point : points) {
            int distance = point[0] * point[0] + point[1] * point[1];
            minHeap.push({distance, point[0], point[1]});
        }

        for (int i = 0; i < k; i++) {
            vector<int> point;
            vector<int> top = minHeap.top();
            minHeap.pop();
            point.push_back(top[1]);
            point.push_back(top[2]);

            result.push_back(point);


        }

        return result;
        
    }
};
