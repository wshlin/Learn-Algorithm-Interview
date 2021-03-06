#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// 3. Longest Substring Without Repeating Characters
class Solution {
public:
    // 滑动窗口
    // 时间复杂度: O(len(s))
    // 空间复杂度: O(len(charset))
    int lengthOfLongestSubstring(string s) {
        
        int freq[256] = {0};

        int l = 0, r = -1; // 滑窗为s[l...r]
        int res = 0;
        
        // 这个循环从 l=0, r=-1 这个空窗口开始
        // 到 l=s.size(), r=size()-1 这个空窗口截止
        // 在每次循环里逐渐改变窗口，维护freq，并记录当前窗口中是否找到了一个新的最优值
        while (l < s.size()) {
        
            if (r + 1 < s.size() && freq[s[r+1]] == 0)
                freq[s[++r]] ++;
            else
                freq[s[l++]] --;
            
            res = max(res, r-l+1);
        }

        return res;
    }
};

int main()
{
    cout << Solution().lengthOfLongestSubstring( "abcabcbb" )<<endl; //3
    cout << Solution().lengthOfLongestSubstring( "bbbbb" )<<endl;    //1
    cout << Solution().lengthOfLongestSubstring( "pwwkew" )<<endl;   //3
    cout << Solution().lengthOfLongestSubstring( "c" )<<endl;        //1
    cout << Solution().lengthOfLongestSubstring( "" )<<endl;         //0
    
    return 0;    
}
