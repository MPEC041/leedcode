
class NumArray {
private:
    vector<int> pref; 

public:
    NumArray(vector<int>& nums) {
        pref = nums;
        for (int i = 1; i < pref.size(); i++) {
            pref[i] += pref[i - 1]; 
        }
    }
    
    int sumRange(int left, int right) {
        
        if (left == 0) {
            return pref[right];
        }
        
        return pref[right] - pref[left - 1];
    }
};
