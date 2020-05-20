Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()){
            return false;
        }
        int len = s1.length();
        map<char,int> mp,freq;
        for(char c:s1){
            freq[c]++;
        }
        for(int i=0;i<s2.size();i++)
        {
            mp[s2[i]]++;
            if(i>=len-1){
                bool flag = true;
                for(auto m:mp){
                    if(freq[m.first] != m.second)
                    {
                        flag = false;
                    }
                }
                if(flag){
                    return true;
                }
                
                if(mp[s2[i+1-len]] == 1){
                    mp.erase(s2[i+1-len]);
                }
                else{
                    mp[s2[i+1-len]]--;
                }
            }
        }
        return false;
    }
};