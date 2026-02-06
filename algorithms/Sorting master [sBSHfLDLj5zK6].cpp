#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <algorithm>
#include <iomanip>

using namespace std;

class SortingMaster{
private:
    static inline const int SEPARATOR_LINE_LENGTH = 30;

    typedef unordered_map<string, void(*)(vector<int>&)> Str_FnPtr;

    static const Str_FnPtr& getAlgoMap(){
        static const Str_FnPtr mp = {
            {"bubble", &bubbleSort},
            {"selection", &selectionSort},
            {"insertion", &insertionSort},
            {"shell", &shellSort},
            {"merge", [](vector<int>& nums){
                    mergeSort(nums, 0, (int)nums.size() - 1);
                }
            },
            {"heap", &heapSort},
            {"heap_iterative", &heapSort_iterative},
            {"quick", [](vector<int>& nums){
                    quickSort(nums, 0, (int)nums.size() - 1);
                }
            },
            {"quick_tail", [](vector<int>& nums){
                    quickSort_tail(nums, 0, (int)nums.size() - 1);
                }
            },
            {"pigeonhole", &pigeonholeSort},
            {"counting", &countingSort},
            {"radix", &radixSort},
            {"radix_bucket", &radixSort_bucket},
            {"library", [](vector<int>& nums){
                    sort(nums.begin(), nums.end());
                }
            },
            {"library_stable", [](vector<int>& nums){
                    stable_sort(nums.begin(), nums.end());
                }
            },
        };
        
        return mp;
    }

    // ------------ Bubble-sort | START ------------ //
    // T.C.=O(n^2)
    // S.C.=O(1) 
    // Stable | In-place
    static void bubbleSort(vector<int>& nums){
        const int n = nums.size();
        
        for(int i=0; i<n-1; i++){
            bool isSwapped = false;
    
            for(int j=0; j<n-i-1; j++)
                if(nums[j] > nums[j+1]){
                    swap(nums[j], nums[j+1]);
                    isSwapped = true;
                }
    
            if(!isSwapped)
                break;
        }
    }
    // ------------ Bubble-sort | END ------------ //
    
    // ------------ Selection-sort | START ------------ //
    // T.C.=O(n^2)
    // S.C.=O(1)
    // Not-Stable | In-place
    static void selectionSort(vector<int>& nums){
        const int n = nums.size();
        
        for(int i=0; i<n-1; i++){
            int minVal = nums[i];
            int idx = i;
    
            for(int j=i+1; j<n; j++)
                if(nums[j] < minVal){
                    minVal = nums[j];
                    idx = j;
                }
                
            if(idx != i)
                swap(nums[i], nums[idx]);
        }
    }
    // ------------ Selection-sort | END ------------ //
    
    // ------------ Insertion-sort | START ------------ //
    // T.C.=O(n^2)
    // S.C.=O(1)
    // Stable | In-place
    static void insertionSort(vector<int>& nums){
        const int n = nums.size();
        
        for(int i=1; i<n; i++){
            for(int j=i; j>0; j--){
                if(nums[j-1] > nums[j])
                    swap(nums[j-1], nums[j]);
                else
                    break;
            }
        }
    }

    // ------------ Insertion-sort | END ------------ //

    // ------------ Shell-sort | START ------------ //
    // T.C. = O(n*log(n)) best, O(n^2) worst, O(n^1.25 - n^1.50) avg
    // S.C. = O(1)
    // Not-Stable | In-place
    static void shellSort(vector<int>& nums){
        const int n = nums.size();

        for(int gap = n/2; gap > 0; gap /= 2){
            for(int i=gap; i<n; i++){
                int temp = nums[i];
                int j = i;
                // shift the elements > temp to the right to make space
                for(; j >= gap && nums[j - gap] > temp; j -= gap)
                    nums[j] = nums[j - gap];
                // add temp to its correct position
                nums[j] = temp;
            }
        }
    }
    // ------------ Shell-sort | END ------------ //
    
    // ------------ Merge-sort | START ------------ //
    static void merge(vector<int>& nums, const int left, const int mid, const int right){
        vector<int> temp1;
        for(int i = left; i <= mid; i++)
            temp1.push_back(nums[i]);
    
        vector<int> temp2;
        for(int i = mid + 1; i <= right; i++)
            temp2.push_back(nums[i]);
    
        int i=0, j=0;
        int k = left;
    
        for(; i < temp1.size() && j < temp2.size(); k++){
            if(temp1[i] <= temp2[j]){
                nums[k] = temp1[i];
                i++;
            }else{
                nums[k] = temp2[j];
                j++;
            }
        }
    
        for(;i < temp1.size(); i++, k++)
            nums[k] = temp1[i];
    
        for(;j < temp2.size(); j++, k++)
            nums[k] = temp2[j];
    }
    
    // T.C.=O(n*log(n))
    // S.C.=O(n)
    // Stable | Not In-place
    static void mergeSort(vector<int>& nums, const int left, const int right){
        if(left >= right)
            return;
    
        const int mid = left + (right - left)/2;
    
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
    
        merge(nums, left, mid, right);
    }
    // ------------ Merge-sort | END ------------ //
    
    // ------------ Heap-sort | START ------------ //
    // make the heap (rooted at i) valid and 
    // containing the elements in index window [0, n)
    static void heapify(vector<int>& nums, const int n, const int i){
        const int left = 2*i + 1;
        const int right = 2*i + 2;
        
        int idx = i;
        
        if(left < n && nums[left] > nums[idx])
            idx = left;
        if(right < n && nums[right] > nums[idx])
            idx = right;
        
        // curr node is already the largest so heap is valid
        if(idx == i)
            return;
        
        // swap the curr node val with the max among the left and right child
        swap(nums[i], nums[idx]);
        // check for the heap rooted at idx
        heapify(nums, n, idx);
    }
    
    // T.C.=O(n*log(n))
    // S.C.=O(log(n))
    // Not-Stable | In-place
    static void heapSort(vector<int>& nums){
        const int n = nums.size();
        
        // build the initial max-heap by calling
        // heapify on all the non-leaf nodes
        for(int i=n/2-1; i>=0; i--)
            heapify(nums, n, i);
        
        for(int i=n-1; i>0; i--){
            // swap the max element (index 0) with 
            // the last unsorted element (index i)
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }
    // ------------ Heap-sort | END ------------ //

    // ------------ Heap-sort (iterative) | START ------------ //
    // make the heap (rooted at i) valid and 
    // containing the elements in index window [0, n)
    static void heapify_iterative(vector<int>& nums, const int n, int i){
        while(2*i+1 < n){
            const int left = 2*i + 1;
            const int right = 2*i + 2;
            
            int idx = i;
            
            if(nums[left] > nums[idx])
                idx = left;
            if(right < n && nums[right] > nums[idx])
                idx = right;
            
            // curr node is already the largest so heap is valid
            if(idx == i)
                break;
            
            // swap the curr node val with the max among the left and right child
            swap(nums[i], nums[idx]);
            
            i = idx;
        }
    }
    
    // T.C.=O(n*log(n))
    // S.C.=O(1)
    // Not-Stable | In-place
    static void heapSort_iterative(vector<int>& nums){
        const int n = nums.size();
        
        // build the initial max-heap by calling
        // heapify on all the non-leaf nodes
        for(int i=n/2-1; i>=0; i--)
            heapify_iterative(nums, n, i);
        
        for(int i=n-1; i>0; i--){
            // swap the max element (index 0) with 
            // the last unsorted element (index i)
            swap(nums[0], nums[i]);
            heapify_iterative(nums, i, 0);
        }
    }
    // ------------ Heap-sort (iterative) | END ------------ //
    
    // ------------ Quick-sort | START ------------ //
    // lomuto-partition-algorithm
    // returns the index of pivot element in the nums[left, ..., right]
    static int partition(vector<int>& nums, const int left, const int right){
        // choose the last element as pivot
        const int pivot = nums[right];
        int i = left - 1;
        
        for(int j=left; j<right; j++){
            if(nums[j] <= pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        
        swap(nums[i+1], nums[right]);
        
        return i+1;
    }
    
    // T.C.=O(n*log(n)) best/avg, O(n^2) worst
    // S.C.=O(log(n)) best/avg, O(n) worst 
    // Not-Stable | In-place
    static void quickSort(vector<int>& nums, const int left, const int right){
        if(left >= right)
            return;
        
        const int idx = partition(nums, left, right);
        
        // elements in index range [0, idx-1] are <= nums[idx]
        quickSort(nums, left, idx - 1);
        // elements in index range [idx+1, right] are > nums[idx]
        quickSort(nums, idx + 1, right);
    }
    // ------------ Quick-sort | END ------------ //

    // ------------ Quick-sort (tail-recursion) | START ------------ //
    // lomuto-partition-algorithm
    // returns the index of pivot element in the nums[left, ..., right]
    static int partition_tail(vector<int>& nums, int left, int right){
        // choose the last element as pivot
        const int pivot = nums[right];
        int i = left - 1;
        
        for(int j=left; j<right; j++){
            if(nums[j] <= pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        
        swap(nums[i+1], nums[right]);
        
        return i+1;
    }
    
    // T.C.=O(n*log(n)) best/avg, O(n^2) worst
    // S.C.=O(log(n)) 
    // Not-Stable | In-place
    static void quickSort_tail(vector<int>& nums, int left, int right){
        while(left < right){
            const int idx = partition_tail(nums, left, right);

            const int leftSize = idx - left + 1;
            const int rightSize = right - idx + 1;

            if(leftSize < rightSize){
                // elements in index range [0, idx-1] are <= nums[idx]
                quickSort_tail(nums, left, idx - 1);
                left = idx + 1;
            }else{
                // elements in index range [idx+1, right] are > nums[idx]
                quickSort_tail(nums, idx + 1, right);
                right = idx - 1;
            }
        }
    }
    // ------------ Quick-sort (tail-recursion)  | END ------------ //

    // ------------ Pigeonhole-sort | START ------------ //
    // T.C.=O(n + r), r: maxVal - minVal
    // S.C.=O(r), r: maxVal - minVal
    // Not-Stable | Not In-place
    static void pigeonholeSort(vector<int>& nums){
        const int maxVal = *max_element(nums.begin(), nums.end());
        const int minVal = *min_element(nums.begin(), nums.end());

        const int offset = minVal < 0 ? -minVal : 0;

        vector<int> freq(maxVal + 1 + offset, 0);

        for(const int num: nums)
            freq[num + offset]++;

        for(int num=0, i=0; num < freq.size(); num++)
            while(freq[num]--)
                nums[i++] = num - offset;
    }
    // ------------ Pigeonhole-sort | END ------------ //

    // ------------ Counting-sort | START ------------ //
    // T.C.=O(n + r), r: maxVal - minVal
    // S.C.=O(n + r), r: maxVal - minVal
    // Stable | Not In-place
    static void countingSort(vector<int>& nums){
        const int maxVal = *max_element(nums.begin(), nums.end());
        const int minVal = *min_element(nums.begin(), nums.end());

        const int offset = minVal < 0 ? -minVal : 0;

        vector<int> freq(maxVal + 1 + offset, 0);

        for(const int num: nums)
            freq[num + offset]++;

        // calculate prefix-sum to find the 
        // actual index of each num in the sorted vector
        for(int i=1; i<freq.size(); i++)
            freq[i] += freq[i-1];

        const int n = nums.size();
        vector<int> temp(n, 0);
        for(int i=n-1; i>=0; i--)
            temp[--freq[nums[i] + offset]] = nums[i];

        // copy temp[] into nums[]
        nums = temp;
    }
    // ------------ Counting-sort | END ------------ //

    // ------------ Radix-sort | START ------------ //
    // T.C.=O(m*(n + 10)), m: digits in the abs max num
    // S.C.=O(n + 10)
    // Stable | Not In-place
    static void radixSort(vector<int>& nums){
        const int maxVal = *max_element(nums.begin(), nums.end());
        const int minVal = *min_element(nums.begin(), nums.end());
        
        const int offset = minVal < 0 ? -minVal : 0;
        
        for(int m=1; (maxVal + offset) / m > 0; m *= 10){
            vector<int> freq(10, 0);

            for(const int num: nums){
                const int dig = ((num + offset) / m) % 10;
                freq[dig]++;
            }
            
            // calculate prefix-sum to find the 
            // actual index of each num in the sorted vector
            for(int i=1; i<freq.size(); i++)
                freq[i] += freq[i-1];

            const int n = nums.size();
            vector<int> temp(n, 0);
            for(int i=n-1; i>=0; i--){
                const int dig = ((nums[i] + offset) / m) % 10;
                temp[--freq[dig]] = nums[i];
            }

            // copy temp[] into nums[]
            nums = temp;
        }
    }
    // ------------ Radix-sort | END ------------ //

    // ------------ Radix-sort (bucket) | START ------------ //
    // T.C.=O(m*(n + 10)), m: digits in the abs max num
    // S.C.=O(n + 10)
    // Stable | Not In-place
    static void radixSort_bucket(vector<int>& nums){
        const int maxVal = *max_element(nums.begin(), nums.end());
        const int minVal = *min_element(nums.begin(), nums.end());
        
        const int offset = minVal < 0 ? -minVal : 0;
        
        for(int m=1; (maxVal + offset) / m > 0; m *= 10){
            vector<vector<int>> groups(10);

            for(const int num: nums){
                const int dig = ((num + offset) / m) % 10;
                groups[dig].push_back(num);
            }

            int i=0;
            for(int dig=0; dig<10; dig++)
                for(const int num: groups[dig])
                    nums[i++] = num;
        }
    }
    // ------------ Radix-sort (bucket) | END ------------ //
    
    static void logMsg(const string& msg){
        if(ENABLE_LOG)
            cout<<msg<<endl;
    }

    static void logImpMsg(const string& msg){
        cout<<msg<<endl;
    }

    static void printBenchmarkResults(const vector<pair<int, string>>& times){
        const int colIdWidth = 6;
        const int colNameWidth = 16;
        const int colTimeWidth = 12;

        cout<<left
            <<setw(colIdWidth)<<"Rank"
            <<setw(colNameWidth)<<"Algorithm"
            <<setw(colTimeWidth)<<"Time (in us)"
            <<endl;
        cout<<string(colIdWidth + colNameWidth + colTimeWidth, '-')<<endl;

        int maxTime = 0;
        for(const auto& [time_us, _]: times)
            maxTime = max(maxTime, time_us);

        int rank = 1;
        for(const auto& [time_us, algoName]: times)
            cout<<left
                <<setw(colIdWidth)<<rank++
                <<setw(colNameWidth)<<algoName
                <<setw(colTimeWidth)<<to_string(time_us).insert(0, to_string(maxTime).length() - to_string(time_us).length(), ' ')
                <<endl;
                
        cout<<string(colIdWidth + colNameWidth + colTimeWidth, '-')<<endl;
    }

    static bool validate_n(const int n){
        const int MAX_VEC_SIZE = 100000; // 10^5

        if(n < 1 || n > MAX_VEC_SIZE){
            logImpMsg("Value of n must be in range [1, " + to_string(MAX_VEC_SIZE) + "]");
            return false;
        }

        return true;
    }

    static bool validate_minMaxInt(const int minVal, const int maxVal){
        const int MIN_INT_VAL = -100000; // -10^5
        const int MAX_INT_VAL = 100000; // +10^5

        if(minVal < MIN_INT_VAL || maxVal > MAX_INT_VAL){
            logImpMsg("Integer value must be in range [" + to_string(MIN_INT_VAL) + ", " + to_string(MAX_INT_VAL) + "]");
            return false;
        }
        
        if(minVal > maxVal){
            logImpMsg("Min-value must be <= Max-value");
            return false;
        }

        return true;
    }

    static bool validate_iterations(const int iterations){
        const int MAX_ITERATIONS_BECNHMARK = 100;

        if(iterations < 1 || iterations > MAX_ITERATIONS_BECNHMARK){
            logImpMsg("Number of iterations must be in range [1, " + to_string(MAX_ITERATIONS_BECNHMARK) + "]");
            return false;
        }

        return true;
    }

    static bool validate_listSize(const vector<string>& list){
        if(list.empty()){
            logImpMsg("Algo list cannot be empty");
            return false;
        }

        return true;
    }

    static bool runBenchmark_root(const int n, const int minVal, const int maxVal, const int iterations, const unordered_set<string>& algoNames){
        logMsg("Running Benchmark... (for n = " + to_string(n) + ")" + 
            (iterations > 1 ? ", (" + to_string(iterations) + " iterations)" : ""));
        
        // algo-name -> total time (in microsec) to run (for iterations)
        unordered_map<string, int> algoRunTimeMap;
        
        ENABLE_LOG = false;
        for(int t=1; t<=iterations; t++){
            vector<int> nums = generateRandomVector(n, minVal, maxVal);

            for(const auto& algoName: algoNames){
                vector<int> temp = nums;
                    
                algoRunTimeMap[algoName] += calculateAlgoRunTime_us(temp, algoName);
            }
        }
        ENABLE_LOG = true;

        vector<pair<int, string>> algoRunTimes;
        for(const auto& [algoName, totalTime]: algoRunTimeMap)
            algoRunTimes.push_back({totalTime / iterations, algoName});

        sort(algoRunTimes.begin(), algoRunTimes.end());
        
        printBenchmarkResults(algoRunTimes);

        return true;
    }

public:
    SortingMaster(){}
    
    static inline bool ENABLE_LOG = true;

    // returns a vector of size n filled with random int in range [minVal, maxVal]
    static vector<int> generateRandomVector(int n, int minVal, int maxVal){
        if(!(validate_n(n) && validate_minMaxInt(minVal, maxVal)))
            return {};
        
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(minVal, maxVal);
        
        vector<int> nums;
        for(int i=0; i<n; i++)
            nums.push_back(distrib(gen));
            
        return nums;
    }
    
    static void printVector(const vector<int>& nums){
        for(const int num: nums)
            cout<<num<<" ";
        cout<<endl;
    }
    
    static void listAlgoNames(){
        const auto& mp = getAlgoMap();
        int id = 1;
        
        for(const auto& [algoName, _]: mp){
            cout<<id<<". "<<algoName;
            if(id++ < (int)mp.size())
                cout<<", ";
        }
        
        cout<<endl;
    }

    static bool runAlgo(vector<int>& nums, const string& algoName){
        const auto& mp = getAlgoMap();
        
        const auto itr = mp.find(algoName);

        if(itr == mp.end()){
            logImpMsg("Invalid algo. name: " + algoName);
            logImpMsg("Available algo. names: ");
            listAlgoNames();
            cout<<string(SEPARATOR_LINE_LENGTH, '-')<<endl<<endl;
            return false;
        }
        
        logMsg("Before Sorting: ");
        if(ENABLE_LOG)
            printVector(nums);
        logMsg("Running " + algoName + "-sort... ");

        itr->second(nums);

        logMsg("After Sorting: ");
        if(ENABLE_LOG){
            printVector(nums);
            cout<<string(SEPARATOR_LINE_LENGTH, '-')<<endl<<endl;
        }
        
        return true;
    }

    static int calculateAlgoRunTime_us(vector<int>& nums, const string& algoName){
        const auto startTime = chrono::high_resolution_clock::now();

        runAlgo(nums, algoName);

        const auto endTime = chrono::high_resolution_clock::now();
        const auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

        return duration.count();
    }

    // run all the algos to becnhmark
    static bool runBenchmark(const int n, const int minVal, const int maxVal){
        return runBenchmark(n, minVal, maxVal, 1);
    }

    // run all the algos to becnhmark (for specified iterations)
    static bool runBenchmark(const int n, const int minVal, const int maxVal, const int iterations){
        if(!(validate_n(n) && validate_minMaxInt(minVal, maxVal) && validate_iterations(iterations)))
            return false;

        const auto& algoMap = getAlgoMap();
        unordered_set<string> algoNames;
        for(const auto& [algoName, _]: algoMap)
            algoNames.insert(algoName);
        
        return runBenchmark_root(n, minVal, maxVal, iterations, algoNames);
    }

    // run only specific algos to becnhmark
    static bool runSpecificBenchmark(const int n, const int minVal, const int maxVal, const vector<string>& algoList){
        return runSpecificBenchmark(n, minVal, maxVal, 1, algoList);
    }

    // run only specific algos to becnhmark (for specified iterations)
    static bool runSpecificBenchmark(const int n, const int minVal, const int maxVal, const int iterations, const vector<string>& algoList){
        if(!(validate_n(n) && validate_minMaxInt(minVal, maxVal) && validate_iterations(iterations) && validate_listSize(algoList)))
            return false;

        const auto& algoMap = getAlgoMap();
        unordered_set<string> algoNames;
        for(const string& algoName: algoList)
            if(algoMap.find(algoName) != algoMap.end())
                algoNames.insert(algoName);
        
        if(algoNames.empty()){
            logImpMsg("No valid algo name found!");
            return false;
        }

        return runBenchmark_root(n, minVal, maxVal, iterations, algoNames);
    }
};

int main() {
    vector<int> nums = SortingMaster::generateRandomVector(10, -50, 50);
    
    // SortingMaster::runAlgo(nums, "bubble");
    // SortingMaster::runAlgo(nums, "selection");
    // SortingMaster::runAlgo(nums, "insertion");
    // SortingMaster::runAlgo(nums, "shell");
    // SortingMaster::runAlgo(nums, "merge");
    // SortingMaster::runAlgo(nums, "heap");
    // SortingMaster::runAlgo(nums, "heap_iterative");
    // SortingMaster::runAlgo(nums, "quick");
    // SortingMaster::runAlgo(nums, "quick_tail");
    // SortingMaster::runAlgo(nums, "pigeonhole");
    // SortingMaster::runAlgo(nums, "counting");
    // SortingMaster::runAlgo(nums, "radix");
    // SortingMaster::runAlgo(nums, "radix_bucket");
    
    SortingMaster::runBenchmark(1300, -1000, 1000);
    SortingMaster::runBenchmark(1300, -1000, 1000, 12);

    // SortingMaster::runSpecificBenchmark(1300, -1000, 1000, {"bubble", "selection", "insertion", "shell"});
    // SortingMaster::runSpecificBenchmark(1300, -1000, 1000, 12, {"merge", "heap", "heap_iterative", "quick", "quick_tail"});
    // SortingMaster::runSpecificBenchmark(1300, -1000, 1000, 12, {"pigeonhole", "counting", "radix", "radix_bucket"});
    
    // SortingMaster::runAlgo(nums, "wrong_name");
        
    return 0;
}

/*
g++ "./algorithms/Sorting master [sBSHfLDLj5zK6].cpp" -o "./algorithms/compiled/Sorting master [sBSHfLDLj5zK6]"
"./algorithms/compiled/Sorting master [sBSHfLDLj5zK6]"
*/