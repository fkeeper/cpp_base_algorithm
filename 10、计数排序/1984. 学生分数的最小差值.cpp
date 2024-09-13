class Solution {
    void countingSort(vector<int>& a, int m) {
        int n = a.size();
        int* count = new int[m + 1];
        memset(count, 0, sizeof(int) * (m + 1));
        for (int i = 0; i < n; ++i) {
            count[a[i]]++;
        }
        int s = 0;
        for (int v = 0; v <= m; ++v) {
            while (count[v]) {
                a[s++] = v;
                --count[v];
            }
        }
        delete[] count;
    }
public:
    int minimumDifference(vector<int>& nums, int k) {
        countingSort(nums, 100000);
        int ret = 100000000;
        for (int i = 0; i + k - 1 < nums.size(); ++i) {
            int l = i;
            int r = i + k - 1;
            ret = min(ret, nums[r] - nums[l]);
        }
        return ret;
    }
};