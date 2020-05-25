Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

 

Example 1:



Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
 

Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.



class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        vector<vector<int>>::iterator ptrA; 
        vector<vector<int>>::iterator ptrB; 
        ptrA = A.begin();
        ptrB = B.begin();
        while(ptrA!=A.end() && ptrB!=B.end()){
            vector<int> v(2,0);
            int s1 = (*ptrA)[0];
            int e1 = (*ptrA)[1];
            int s2 = (*ptrB)[0];
            int e2 = (*ptrB)[1];
            
            if(s2<=e1 && e2>=s1){
                v[0] = max(s1,s2);
                v[1] = min(e1,e2); 
                ans.push_back(v);
            }
            if(e1<e2)
                ptrA++;
            else if(e2<e1)
                ptrB++;
            else{
                ptrA++;
                ptrB++;
            }
        }
        return ans;
    }
};