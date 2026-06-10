class SmallestInfiniteSet {
private:
    int small = 0;
    set<int> s; // to maintain the values added back in the infintie set

public:
    SmallestInfiniteSet() {
        small = 1;
    }
    
    int popSmallest() {
        if(s.empty()) // smallest value present in variable (as set is empty)
            return small++;
        if(small < *s.begin()) // smallest value present in variable
            return small++;
        else // smallest value present in set
        {
            int small2 = *s.begin();
            s.erase(s.begin()); // delete the smallest value from set
            return small2;
        }
    }
    
    void addBack(int num) {
        if(num < small) // new smallest value found
            s.insert(num);
    }
};
/*
# set maintains values in increasing order
# s.begin() gives the pointer to the first value in the set s
# *s.begin() gives the first value, ie, the smallest value in the set s  
*/

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */