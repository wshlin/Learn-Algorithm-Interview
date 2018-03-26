#include <iostream>
#include <vector>
#include <map>
#include <set> // for intersectII()

using namespace std;

// 350. Intersection of Two Arrays II
class Solution {
public:
    // 针对 STL map 的使用
    // 时间复杂度: O(nlogn)
    // 空间复杂度: O(n)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> record;
        for(int i = 0 ; i < nums1.size() ; i ++)
            record[nums1[i]] += 1;

        vector<int> resultVector;
        for(int i = 0 ; i < nums2.size() ; i ++)
            if(record[nums2[i]] > 0){
                resultVector.push_back(nums2[i]);
                record[nums2[i]] --;
            }

        return resultVector;
    }
    
    vector<int> intersectI(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> record;
        for(int i = 0 ; i < nums1.size() ; i ++)
            if(record.find(nums1[i]) == record.end())
                record.insert(make_pair(nums1[i],1));
            else
                record[nums1[i]] += 1;

        vector<int> resultVector;
        for(int i = 0 ; i < nums2.size() ; i ++)
            if(record.find(nums2[i]) != record.end() &&
               record[nums2[i]] > 0){

                resultVector.push_back(nums2[i]);
                record[nums2[i]] --;
                if(record[nums2[i]] == 0)
                    record.erase(nums2[i]);
            }

        return resultVector;
    }
    
    vector<int> intersectII(vector<int>& nums1, vector<int>& nums2) {

        multiset<int> record;
        for(int num: nums1)
            record.insert(num);

        multiset<int> result;
        for(int num: nums2){
            multiset<int>::iterator iter = record.find(num);
            if( iter != record.end()){
                result.insert(num);
                record.erase(iter);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};

int main() {

    int nums1[] = {1, 2, 2, 1};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));

    int nums2[] = {2, 2};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));

    vector<int> res = Solution().intersect(vec1, vec2);
    for(int i = 0 ; i < res.size() ; i ++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
