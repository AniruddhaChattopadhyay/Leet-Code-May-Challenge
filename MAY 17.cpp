Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

class Solution {
public:
    void print(unordered_map<char,int> mp){
        for(auto m:mp){
            cout<<m.first<<" "<<m.second<<" ";
        }
        cout<<endl;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,int> p_char_freq;
        if(s.length()<p.length()){
            return ans;
        }
        else{
            for(char c:p){
                p_char_freq[c]++;
            }
            unordered_map<char,int> mp;
            int p_len = p.length();
            for(int i=0;i<s.length();i++){
                mp[s[i]]++;
                //print(mp);
                //cout<<mp.size();
                if(i>=p_len-1){
                    //cout<<i<<endl;
                    // bool flag = true;
                    // for(auto m:mp){
                    //     if(p_char_freq[m.first]!=m.second){
                    //         //print(mp);
                    //         flag = false;
                    //         //cout<<i<<endl;
                    //         break;
                    //     }
                    // }
                    // if(flag)
                    if(mp == p_char_freq)
                        ans.push_back(i-(p_len-1));
                }
                int index = i-(p_len-1);
                if(index>=0){
                    if (mp[s[index]] == 1)
                        mp.erase(s[index]);
                    else
                        mp[s[index]]--;
                }
            }
        }
        return ans;
    }
};