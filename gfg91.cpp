#include <bits/stdc++.h>
using namespace std;

class TaskManager {
public:
    unordered_map<int, pair<int, int>> mpp; // taskId -> {userId, priority}
    priority_queue<tuple<int,int,int>> pq;  // {priority, taskId, userId}

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &it : tasks) {
            int userId = it[0], taskId = it[1], priority = it[2];
            mpp[taskId] = {userId, priority};
            pq.push({priority, taskId, userId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mpp[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        if (mpp.find(taskId) == mpp.end()) return; // task doesn’t exist
        int userId = mpp[taskId].first;
        mpp[taskId].second = newPriority;
        pq.push({newPriority, taskId, userId});
    }
    
    void rmv(int taskId) {
        mpp.erase(taskId); // lazy deletion (heap still has old entry)
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId, userId] = pq.top();
            // check if still valid
            if (mpp.find(taskId) != mpp.end() && 
                mpp[taskId].second == priority && 
                mpp[taskId].first == userId) {
                
                // valid -> erase & return
                mpp.erase(taskId);
                pq.pop();
                return userId;
            }
            pq.pop(); // stale entry -> discard
        }
        return -1; // no tasks
    }
};
