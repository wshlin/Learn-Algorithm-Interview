#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // time complexity  : O(n)
    // space complexity : O(n)
    void moveZeroes(vector<int>& nums) {
        
        vector<int> nonZeroElements;
        
        // place all non-zero elements in vec in nonZeroElements
        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                nonZeroElements.push_back(nums[i]);
        
        // place all the elements in nonZeroElements in the order of nums
        for (int i = 0; i < nonZeroElements.size(); i++)
            nums[i] = nonZeroElements[i];
        
        // place the rest of nums as 0
        for (int i = nonZeroElements.size(); i < nums.size(); i++)
            nums[i] = 0;
    }
    
    // time complexity  : O(n)
    // space complexity : O(1)
    void moveZeroesI(vector<int>& nums) {
        
        int k = 0; // in nums, [0...k) elements are non-zero elements
 
        // After traversing the ith element,  
        // we guarantee all non-zero element in [0...i] are in order of [0...k)       
        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                nums[k++] = nums[i];
                
        // place the rest of nums as 0     
        for (int i = k; i< nums.size(); i++)
            nums[i] = 0;
    }
    
    void moveZeroesII(vector<int>& nums) {
        
        int k = 0;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                swap(nums[k++], nums[i]);
    }

    void moveZeroesIII(vector<int>& nums) {
        
        int k = 0; // in nums, [0...k) elements are non-zero elements

        // After traversing the ith element,  
        // we guarantee all non-zero element in [0...i] are in order of [0...k)
        // at the same time, [k..i] is zero
        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                if (k != i)
                    swap(nums[k++], nums[i]);
                else
                    k ++;
    }
};

int main()
{
    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));

    Solution().moveZeroes(vec);

    for (int i=0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}

