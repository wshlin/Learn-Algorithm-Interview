#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
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
    
    void moveZeroesI(vector<int>& nums) {
        
        int k = 0;
        
        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                nums[k++] = nums[i];
             
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
        
        int k = 0;

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

