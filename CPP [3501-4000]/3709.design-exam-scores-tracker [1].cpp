class ExamTracker {
private:
    vector<int> times;
    vector<long long int> prefixSum;

    // returns index of the closest element >= key
    int findStartIdx(int key){
        int left = 0, right = times.size()-1;
        int idx = -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(times[mid] >= key){
                idx = mid;
                right = mid - 1;
            }
            else // times[mid] < k
                left = mid + 1;
        }

        return idx;
    }

    // returns index of the closest element <= key
    int findEndIdx(int key){
        int left = 0, right = times.size()-1;
        int idx = -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(times[mid] <= key){
                idx = mid;
                left = mid + 1;
            }
            else // times[mid] > key
                right = mid - 1;
        }

        return idx;
    }

public:
    ExamTracker() {
        this->times.clear();
        this->prefixSum.clear();
    }
    
    void record(int time, int score) {
        times.push_back(time);

        long long int prevVal = prefixSum.empty() ? 0 : prefixSum.back();
        prefixSum.push_back(prevVal + score);
    }
    
    long long totalScore(int startTime, int endTime) {
        int startIdx = findStartIdx(startTime);
        int endIdx = findEndIdx(endTime);

        if(startIdx == -1 || endIdx == -1)
            return 0;

        return prefixSum[endIdx] - (startIdx - 1 >= 0 ? prefixSum[startIdx - 1] : 0);
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */