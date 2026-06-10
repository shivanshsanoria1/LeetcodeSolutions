class MyCalendarTwo {
private:
    // intervals which don't cause a 
    // triple-booking at any moment of time
    vector<pair<int, int>> intervals;
    // intersection part of any 2 intervals from intervals[]
    vector<pair<int, int>> intersect2;

    // returns true if the intervals [s1, e1) and [s2, e2) intersect
    bool doesIntersect(int s1, int e1, int s2, int e2){
        return e1 <= s2 || e2 <= s1 ? false : true;
    }

public:
    MyCalendarTwo() {
        this->intervals.clear();
        this->intersect2.clear();
    }
    
    // T.C.=O(n^2)
    // n: num of times book() is called
    bool book(int start, int end) {
        int s1 = start, e1 = end;

        // [s1, e1) intersected with the intersection 
        // of 2 intervals, thus causing a triple-booking
        for(auto [s2, e2]: intersect2)
            if(doesIntersect(s1, e1, s2, e2))
                return false;

        // find the possible intersection of [s1, e1)  
        // with all the intervals added previously
        for(auto [s2, e2]: intervals)
            if(doesIntersect(s1, e1, s2, e2))
                intersect2.push_back({max(s1, s2), min(e1, e2)});

        // add [s1, e1) in intervals[] as 
        // it doesn't cause a triple-booking
        intervals.push_back({s1, e1});

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

/*
# for 2 intervals [s1, e1) and [s2, e2):
# no intersection if: 
  e1 <= s2 or e2 <= s1
# intersection part: 
  [ max(s1, s2), min(e1, e2) )
*/