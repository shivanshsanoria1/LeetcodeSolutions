class Solution {
private:
    // returns the rightmost index of the item <= key
    int binarySearch(vector<pair<int, int>>& items, int key){
        int left = 0, right = items.size()-1;
        int idx = -1;

        while(left <= right){
            int mid = left + (right - left)/2;
            auto [cost, cap] = items[mid];

            if(cost <= key){
                idx = mid;
                left = mid + 1;
            }else
                right = mid - 1;
        }

        return idx;
    }
    
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    // sorting + prefix-max + binary-search
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int, int>> items;
        for(int i=0; i<n; i++)
            items.push_back({costs[i], capacity[i]});

        // sort in increasing order of cost and then by capacity
        sort(items.begin(), items.end());

        // find the prefix max1 and max2
        // (index of max1, index of max2)
        vector<pair<int, int>> prefixMax(n);
        prefixMax[0] = {0, -1};
        for(int i=1; i<n; i++){
            auto [i1, i2] = prefixMax[i-1];

            int max1 = items[i1].second;
            int max2 = i2 >= 0 ? items[i2].second : 0;

            int curr = items[i].second;

            if(curr >= max1){
                max2 = max1;
                max1 = curr;

                i2 = i1;
                i1 = i;
            }else if(curr > max2){
                max2 = curr;

                i2 = i;
            }

            prefixMax[i] = {i1, i2};
        }
        
        // convert condition to ans <= budget, instead of ans < budget
        budget--; 
        int ans = 0;
        for(int i=0; i<n; i++){
            auto [cost, cap] = items[i];
            int budgetLeft = budget - cost;

            if(budgetLeft < 0)
                break;
            else if(budgetLeft == 0){
                ans = max(ans, cap);
                continue;
            }

            int idx = binarySearch(items, budgetLeft);

            if(idx == -1){
                ans = max(ans, cap);
                continue;
            }

            auto [i1, i2] = prefixMax[idx];
            int max1 = items[i1].second;
            int max2 = i2 >= 0 ? items[i2].second : 0;

            // always choose max1, except when the
            // curr capacity is itself the max then choose max2 
            ans = max(ans, cap + (i1 == i ? max2 : max1));
        }

        return ans;
    }
};