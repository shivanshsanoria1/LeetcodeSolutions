class OrderedStream {
private:
    vector<string> data;
    int idx = -1;

public:
    OrderedStream(int n) {
        data.resize(n+1, "");
        this->idx = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        data[idKey] = value;

        vector<string> ans;
        while(idx < data.size() && data[idx].length() > 0)
        {
            ans.push_back(data[idx]);
            idx++;
        }

        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */