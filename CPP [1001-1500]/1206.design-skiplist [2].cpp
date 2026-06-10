class Skiplist {
private:
    // { num, freq }
    // always kept sorted in increasing order of num
    vector<pair<int, int>> vec;

    // returns the index of 'target' if found and -1 otherwise
    int getIndex(int target) {
        int left = 0, right = vec.size()-1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(vec[mid].first == target)
                return mid;
            else if(vec[mid].first < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }

public:
    Skiplist() {
        this->vec.clear();
    }
    
    // T.C.=O(logn)
    bool search(int target) {
        return getIndex(target) == -1 ? false : true;
    }
    
    // T.C.=O(n)
    void add(int num) {
        int idx = getIndex(num);

        // 'num' found
        if(idx != -1)
        {
            vec[idx].second++;
            return;
        }

        // add a new pair to the vector
        vec.push_back({num, 1});

        // move the newly added pair to its correct position
        for(int i=vec.size()-1; i>0; i--)
        {
            if(vec[i-1].first > vec[i].first)
                swap(vec[i-1], vec[i]);
            else
                break;
        }
    }
    
    // T.C.=O(n)
    bool erase(int num) {
        int idx = getIndex(num);

        // 'num' not found
        if(idx == -1)
            return false;

        // decrement the freq of num
        vec[idx].second--;

        if(vec[idx].second > 0)
            return true;

        // freq of num has now reached 0 so remove it from the vector
        // by bubbling it to the end and then popping
        for(int i=idx; i<vec.size()-1; i++)
            vec[i] = vec[i+1];
        vec.pop_back();

        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */