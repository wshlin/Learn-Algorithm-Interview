#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;

// 167. Two Sum II - Input array is sorted

class Solution {
public:
    // 暴力枚举法
    // 时间复杂度: O(n^2)
    // 空间复杂度: O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        assert(numbers.size() >= 2);

        for (int i = 0; i < numbers.size(); i++)
            for (int j = i+1; j<numbers.size(); j++)
                if (numbers[i] + numbers[j] == target) {
                    int res[2] = {i+1, j+1};
                    return vector<int>(res, res+2);
                }

        throw invalid_argument("the input has no solution");
    }
    
    // 二分搜索法
    // 时间复杂度: O(nlogn)
    // 空间复杂度: O(1)
    vector<int> twoSumI(vector<int>& numbers, int target) {

        assert(numbers.size() >= 2);

        for(int i = 0 ; i < numbers.size() - 1 ; i ++){
            int j = binarySearch(numbers, i+1, numbers.size()-1, target - numbers[i]);
            if(j != -1){
                int res[2] = {i+1, j+1};
                return vector<int>(res, res+2);
            }
        }

        throw invalid_argument("the input has no solution");
    }
    
    // 对撞指针
    // 时间复杂度: O(n)
    // 空间复杂度: O(1)
    vector<int> twoSumII(vector<int>& numbers, int target) {

        assert(numbers.size() >= 2);

        int l = 0, r = numbers.size() - 1;
        while(l < r){

            if(numbers[l] + numbers[r] == target){
                int res[2] = {l+1, r+1};
                return vector<int>(res, res+2);
            }
            else if(numbers[l] + numbers[r] < target)
                l ++;
            else // numbers[l] + numbers[r] > target
                r --;
        }

        throw invalid_argument("the input has no solution");
    }
    
private:
    int binarySearch(const vector<int> &nums, int l, int r, int target){

        assert(l >= 0 && l < nums.size());
        assert(r >= 0 && r < nums.size());

        while(l <= r){

            int mid = l + (r - l)/2;
            if(nums[mid] == target)
                return mid;
            if(target > nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }
};

int main()
{
    int nums[] = {2, 7, 11, 15};
    vector<int> vec(nums, nums + sizeof(nums) / sizeof(int));
    int target = 9;

    vector<int> res = Solution().twoSum(vec, target);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout<<endl;

    return 0;    
}
