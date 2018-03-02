#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 209. Minimum Size Subarray Sum
class Solution {
public:
    // 暴力解法，超时
    // 时间复杂度: O(n^3)
    // 空间复杂度: O(1)
    int minSubArrayLen(int s, vector<int>& nums) {
        
        assert(s > 0);

        int res = nums.size() + 1;
        for (int l = 0; l < nums.size(); l++)
            for (int r = l; r <nums.size(); r++) {
                int sum = 0;
                for (int i = l; i <= r; i++)
                    sum += nums[i];
                if (sum >= s)
                    res = min(res, r - l + 1);
            }

        if (res == nums.size() + 1)
            return 0;

        return res;
    }
    
    // 优化暴力解
    // 时间复杂度: O(n^2)
    // 空间复杂度: O(n)
    int minSubArrayLenI(int s, vector<int>& nums) {
        
        assert(s > 0);
        
        // sums[i]存放nums[0...i-1]的和
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++)
            sums[i] = sums[i-1] + nums[i-1];
            
        int res = nums.size() + 1;
        for (int l = 0; l < nums.size(); l++)
            for (int r = l; l < nums.size(); r++) {
                // 使用sums[r+1] - sums[l]快速获得nums[l...r]的和
                if (sum[r+1] - sums[l] >= s)
                    res = min(res, r - l + 1);
            }
        
        if (res == nums.size() + 1)
            return 0;
            
        return res;
    }
};

int main()
{
    int nums[] = {2, 3, 1, 2, 4, 3};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    int s = 7;

    cout << Solution().minSubArrayLen(s, vec) << endl;

    return 0;    
}
