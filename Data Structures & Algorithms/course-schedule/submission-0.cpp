class Solution {
    /*
    cycles in the graph mean that it is impossible to complete all courses.
    To detect cycles we  to a dfs, put it in a hash set and then if we add smth that 
    is alr in the hash set we have s cycle and return false
    */
public:
unordered_map<int, vector<int>> preMap;
unordered_set<int> visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i]={};

        }

        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);

        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;

            }

        }

        return true;

        
    }


    bool dfs(int crs) {
        if (visiting.count(crs)) {
            return false;

        }

        if (preMap[crs].empty()) {
            return true;

        }

        visiting.insert(crs);
        for (int pre : preMap[crs]) {
            if (!dfs(pre)) {
                return false;

            }

        }
        visiting.erase(crs);
        preMap[crs].clear();
        return true;

    }
};
