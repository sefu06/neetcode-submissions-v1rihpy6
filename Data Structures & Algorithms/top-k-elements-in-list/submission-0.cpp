class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map <int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

        }

        vector <pair<int, int>> arr;
        for (const auto& p: freq) {
            arr.push_back({p.second, p.first});

        }

        sort(arr.rbegin(), arr.rend());

        vector<int> result; 

        for (int j = 0; j < k ; ++j) {
            result.push_back(arr[j].second);
            

        }

        return result;
    }
};
