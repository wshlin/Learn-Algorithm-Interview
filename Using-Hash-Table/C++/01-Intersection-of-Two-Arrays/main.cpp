#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 349. Intersection of Two Arrays
class Solution {
public:
    // 针对 STL set 的使用
    // 时间复杂度: O(nlogn)
    // 空间度咋度: O(n)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> record;
        for (int i = 0; i < nums1.size(); i++)
            record.insert(nums1[i]);

        set<int> resultSet;
        for (int i = 0; i < nums2.size(); i++)
            if (record.find(nums2[i]) != record.end())
                resultSet.insert(nums2[i]);

        vector<int> resultVector;
        for (set<int>::iterator iter = resultSet.begin(); iter != resultSet.end(); iter++)
            resultVector.push_back(*iter);

        return resultVector;
    }
    
    vector<int> intersectionI(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> record(nums1.begin(), nums1.end());

        set<int> resultSet;
        for (int i = 0; i < nums2.size(); i++)
            if (record.find(nums2[i]) != record.end())
                resultSet.insert(nums2[i]);

        return vector<int>(resultSet.begin(), resultSet.end());
    }
};

int main()
{
    int nums1[] = {1, 2, 2, 1};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));

    int nums2[] = {2, 2};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));

    vector<int> res = Solution().intersectionI(vec1, vec2);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;    
}
