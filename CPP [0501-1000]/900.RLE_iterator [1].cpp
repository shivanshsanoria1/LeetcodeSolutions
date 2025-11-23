class RLEIterator {
private:
    // { num, freq }
    vector<pair<int, int>> encoding;
    int idx = 0;

public:
    RLEIterator(vector<int>& encoding) {
        for(int i=0; i<encoding.size(); i += 2)
            if(encoding[i] > 0)
                this->encoding.push_back({encoding[i+1], encoding[i]});
    }
    
    int next(int n) {
        for(int i=idx; i<encoding.size(); i++)
        {
            auto& [num, freq] = encoding[i];

            if(freq >= n)
            {
                freq -= n;
                return num;
            }
            else
            {
                n -= freq;
                freq = 0;
                idx++;
            }
        }
        
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */