#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <unordered_map>
#include <chrono>
#include <algorithm>
#include <iomanip>

using namespace std;

class Sorting{
private:
    // ------------ Bubble-sort | START ------------ //
    // T.C.=O(n^2), S.C.=O(1) | Stable | In-place
    static void bubbleSort(vector<int>& nums){
        int n = nums.size();
        
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
    // T.C.=O(n^2), S.C.=O(1) | Unstable | In-place
    static void selectionSort(vector<int>& nums){
        int n = nums.size();
        
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
    // T.C.=O(n^2), S.C.=O(1) | Stable | In-place
    static void insertionSort(vector<int>& nums){
        int n = nums.size();
        
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
    
    // ------------ Merge-sort | START ------------ //
    static void merge(vector<int>& nums, int left, int mid, int right){
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
    
    // T.C.=O(n*log(n)), S.C.=O(n) | Stable | Not In-place
    static void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right)
            return;
    
        int mid = left + (right - left)/2;
    
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
    
        merge(nums, left, mid, right);
    }
    // ------------ Merge-sort | END ------------ //
    
    // ------------ Heap-sort | START ------------ //
    // make the heap (rooted at i) valid and 
    // containing the elements in index window [0, n)
    static void heapify(vector<int>& nums, int n, int i){
        int left = 2*i + 1;
        int right = 2*i + 2;
        
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
    
    // T.C.=O(n*log(n)), S.C.=O(log(n)) | Unstable | In-place
    static void heapSort(vector<int>& nums){
        int n = nums.size();
        
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
    static void heapify_iterative(vector<int>& nums, int n, int i){
        while(2*i+1 < n){
            int left = 2*i + 1;
            int right = 2*i + 2;
            
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
    
    // T.C.=O(n*log(n)), S.C.=O(1) | Unstable | In-place
    static void heapSort_iterative(vector<int>& nums){
        int n = nums.size();
        
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
    static int partition(vector<int>& nums, int left, int right){
        // choose the last element as pivot
        int pivot = nums[right];
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
    // Unstable | In-place
    static void quickSort(vector<int>& nums, int left, int right){
        if(left >= right)
            return;
        
        int idx = partition(nums, left, right);
        
        // elements in index range [0, idx-1] are <= nums[idx]
        quickSort(nums, left, idx - 1);
        // elements in index range [idx+1, right] are > nums[idx]
        quickSort(nums, idx + 1, right);
    }
    // ------------ Quick-sort | END ------------ //
    
    typedef unordered_map<string, void(*)(vector<int>&)> Str_FnPtr;

    static const Str_FnPtr& getAlgoMap(){
        static const Str_FnPtr mp = {
            {"bubble", &bubbleSort},
            {"selection", &selectionSort},
            {"insertion", &insertionSort},
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
        };
        
        return mp;
    }

public:
    Sorting(){}
    
    static inline bool enableLog = true;
    
    static void printVector(const vector<int>& nums){
        for(int num: nums)
            cout<<num<<" ";
        cout<<endl;
    }
    
    static void listAlgoNames(){
        const auto& mp = Sorting::getAlgoMap();
        int id = 1;
        
        for(const auto& [algoName, _]: mp){
            cout<<id<<". "<<algoName;
            if(id < (int)mp.size())
                cout<<", ";
            id++;
        }
        
        cout<<endl;
    }

    static bool runAlgo(vector<int>& nums, const string& algoName){
        const auto& mp = Sorting::getAlgoMap();
        
        auto itr = mp.find(algoName);

        if(itr == mp.end()){
            if(Sorting::enableLog){
                cout<<"Invalid algo. name: "<<algoName<<endl;
                cout<<"Available algo. names: "<<endl;
                Sorting::listAlgoNames();
                cout<<string(30, '-')<<endl<<endl;
            }
            return false;
        }

        if(Sorting::enableLog){
            cout<<"Before Sorting: ";
            Sorting::printVector(nums);   
        }

        if(Sorting::enableLog)
            cout<<"Running "<<algoName<<"-sort... "<<endl;

        itr->second(nums);

        if(Sorting::enableLog){
            cout<<"After Sorting: ";
            Sorting::printVector(nums);
            cout<<string(30, '-')<<endl<<endl;
        }
        
        return true;
    }
    
    static vector<int> generateRandomVector(int n, int minVal, int maxVal){
        if(n <= 0){
            cout<<"value of n must be > 0"<<endl;
            return {};
        }
        
        if(minVal > maxVal){
            cout<<"Min-value must be <= Max-value"<<endl;
            return {};
        }
        
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(minVal, maxVal);
        
        vector<int> nums;
        for(int i=0; i<n; i++)
            nums.push_back(distrib(gen));
            
        return nums;
    }
    
    static void runBenchmark(int n){
        cout<<"Running Benchmark... (for n = "<<n<<")"<<endl;
        
        vector<int> nums = Sorting::generateRandomVector(n, 1, 50);
        const auto& mp = Sorting::getAlgoMap();
        vector<pair<int, string>> times;
        
        Sorting::enableLog = false;
        for(const auto& [algoName, _]: mp){
            vector<int> temp = nums;
            
            auto startTime = chrono::high_resolution_clock::now();

            Sorting::runAlgo(temp, algoName);

            auto endTime = chrono::high_resolution_clock::now();
            
            auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);
            
            times.push_back({duration.count(), algoName});
        }
        Sorting::enableLog = true;
        
        sort(times.begin(), times.end());
        
        const int colIdWidth = 6;
        const int colNameWidth = 16;
        const int colTimeWidth = 12;
        
        cout<<left
            <<setw(colIdWidth)<<"S.No."
            <<setw(colNameWidth)<<"Algorithm"
            <<setw(colTimeWidth)<<"Time (in us)"
            <<endl;
        cout<<string(colIdWidth + colNameWidth + colTimeWidth, '-')<<endl;
        
        int id = 1;
        for(auto [time_us, algoName]: times)
            cout<<left
                <<setw(colIdWidth)<<id++
                <<setw(colNameWidth)<<algoName
                <<setw(colTimeWidth)<<time_us
                <<endl;
                
        cout<<string(colIdWidth + colNameWidth + colTimeWidth, '-')<<endl;
    }
};

int main() {
    // vector<int> nums = { 9, 4, 3, 8, 10, 2, 5, 4, 4 };
    vector<int> nums = Sorting::generateRandomVector(10, 1, 50);
    
    // Sorting::runAlgo(nums, "bubble");
    // Sorting::runAlgo(nums, "selection");
    // Sorting::runAlgo(nums, "insertion");
    // Sorting::runAlgo(nums, "merge");
    // Sorting::runAlgo(nums, "heap");
    // Sorting::runAlgo(nums, "heap_iterative");
    // Sorting::runAlgo(nums, "quick");
    
    Sorting::runBenchmark(1300);
        
    return 0;
}