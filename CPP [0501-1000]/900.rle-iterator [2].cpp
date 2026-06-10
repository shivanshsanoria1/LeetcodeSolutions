class RLEIterator {
private:
    // { num, freq }
    vector<pair<int, int>> encoding;
    
    int idx = 0;

public:
    RLEIterator(vector<int>& encoding) {
        for(int i=encoding.size()-1; i>=0; i -= 2)
            if(encoding[i-1] > 0)
                this->encoding.push_back({encoding[i], encoding[i-1]});

        this->idx = this->encoding.size() - 1;
    }
    
    int next(int n) {
        for(int i=idx; i>=0; i--)
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
                idx--;
                encoding.pop_back();
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