#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int freq_p[256] = {0};
        int freq_s[256] = {0};
        int l = 0, r = - 1;
        vector<int> res;
        
        for (int i = 0; i < p.size(); i++)
            freq_p[p[i]] ++;
        
        while (r+1 < s.size()) {
            
            r++;
            freq_s[s[r]] ++;
            
            if (r-l+1 > p.size())
                freq_s[s[l++]] --;
            
            if (r-l+1 == p.size() && same(freq_p, freq_s))
                res.push_back(l);
        }
        
        return res;
    }
    
private:
    bool same(int* freq_p, int* freq_s)
    {
        for (int i=0; i<256; i++)
            if (freq_p[i] != freq_s[i])
                return false;
        return true;
    }
};

void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    string s1 = "cbaebabacd";
    string p1 = "abc";
    printVec(Solution().findAnagrams(s1, p1));
    // [0, 6]

    // ---

    string s2 = "abab";
    string p2 = "ab";
    printVec(Solution().findAnagrams(s2, p2));

    return 0;
}
