class TaskManager {
private:
    // userId -> {taskId}
    unordered_map<int, unordered_set<int>> mp1;
    // taskId -> {userId, priority}
    unordered_map<int, pair<int, int>> mp2;
    // {priority, taskId}
    set<pair<int, int>> s;

public:
    TaskManager(vector<vector<int>>& tasks) {
        this->mp1.clear();
        this->mp2.clear();
        this->s.clear();

        for(vector<int>& task: tasks)
        {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];

            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp1[userId].insert(taskId);
        mp2[taskId] = {userId, priority};
        s.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = mp2[taskId];

        mp2.erase(taskId);
        mp2[taskId] = {userId, newPriority};

        s.erase({oldPriority, taskId});
        s.insert({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        auto [userId, priority] = mp2[taskId];

        mp1[userId].erase(taskId);
        if(mp1[userId].empty())
            mp1.erase(userId);

        mp2.erase(taskId);
        s.erase({priority, taskId});
    }
    
    int execTop() {
        if(s.empty())
            return -1;

        auto itr = --s.end();
        auto [priority, taskId] = *itr;
        int userId = mp2[taskId].first;

        mp1[userId].erase(taskId);
        if(mp1[userId].empty())
            mp1.erase(userId);
            
        mp2.erase(taskId);
        s.erase(itr);

        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */