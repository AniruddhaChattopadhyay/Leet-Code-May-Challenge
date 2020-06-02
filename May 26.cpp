Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> prev_occurence;
        prev_occurence[0] = 0;
        int ans=0;
        int pref =0;
        for(int i=0;i<nums.size();i++){
            pref += nums[i]==1?1:-1;
            if(prev_occurence.count(pref)==1){
                ans = max(ans,i+1-prev_occurence[pref]);
            }
            else{
                prev_occurence[pref] = i+1;
            }
        }
        return ans;
    }
};