class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        auto lb = lower_bound(arr.begin(), arr.end(), target);
    
    // Check agar target array me exist hi nahi karta
    if (lb == arr.end() || *lb != target) {
        return {-1, -1};
    }
    
    auto ub = upper_bound(arr.begin(), arr.end(), target);
    
    int first = lb - arr.begin();
    int last = (ub - arr.begin()) - 1;
    
    return {first, last};
    }
};