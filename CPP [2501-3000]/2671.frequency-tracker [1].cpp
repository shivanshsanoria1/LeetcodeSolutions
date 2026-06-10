class FrequencyTracker {
private:
    // num -> freq
    unordered_map<int, int> numMap;
    // freq -> count
    unordered_map<int, int> freqMap;

public:
    FrequencyTracker() {
        this->numMap.clear();
        this->freqMap.clear();
    }
    
    // T.C.=O(1)
    void add(int number) {
        // 'number' found in map
        if(numMap.find(number) != numMap.end())
        {
            int oldFreq = numMap[number];

            freqMap[oldFreq]--;
            if(freqMap[oldFreq] == 0)
                freqMap.erase(oldFreq);
        }

        numMap[number]++;
        int newFreq = numMap[number];
        freqMap[newFreq]++;
    }
    
    // T.C.=O(1)
    void deleteOne(int number) {
        // 'number' not found in map
        if(numMap.find(number) == numMap.end())
            return;
        
        int oldFreq = numMap[number];

        freqMap[oldFreq]--;
        if(freqMap[oldFreq] == 0)
            freqMap.erase(oldFreq);
        
        if(oldFreq > 1)
            freqMap[oldFreq - 1]++;

        numMap[number]--;
        if(numMap[number] == 0)
            numMap.erase(number);
    }
    
    // T.C.=O(1)
    bool hasFrequency(int frequency) {
        return freqMap.find(frequency) != freqMap.end();
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */