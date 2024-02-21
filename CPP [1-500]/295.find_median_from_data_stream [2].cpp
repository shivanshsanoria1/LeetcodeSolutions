class MedianFinder {
private:
    multiset<int> s;

public:
    MedianFinder() {
        s.clear();
    }
    
    void addNum(int num) { // T.C.=O(logn)
        s.insert(num);
    }
    
    double findMedian() { // T.C.=O(n)
        auto it = s.begin();
        if(s.size() % 2 == 1)
        {
            int mid = s.size()/2;
            advance(it, mid); // advance iterator by 'mid' positions
            return *it;
        }
        int mid = s.size()/2 - 1;
        advance(it, mid); // advance iterator by 'mid' positions
        int val1 = *it;
        it++;
        return (val1 + *it) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */