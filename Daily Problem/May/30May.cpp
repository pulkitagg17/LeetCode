/*
1442. Count Triplets That Can Form Two Arrays of Equal XOR
Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.

 

Example 1:

Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
Example 2:

Input: arr = [1,1,1,1,1]
Output: 10
*/

// Approach 1: three loops and kaam khatam

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();

        for(int i=0 ; i<n ; i++){
            for(int j=i+1; j<n ; j++){
                int a=0;
                for(int k=i ; k<j ; k++ ){
                    a ^= arr[k];
                }

                int b=0;
                for(int k=j ; k<n ; k++ ){
                    b ^= arr[k];

                    if(a==b) ans++;
                }
            }
        }
        return ans;
    }
};

Approach 2: 
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();

        for(int i=0 ; i<n ; i++){
            int val = arr[i];
                for(int k=i+1 ; k<n ; k++ ){
                    val ^= arr[k];

                    if(val==0) 
                        ans += (k-i);
                }
        }
        return ans;
    }
};