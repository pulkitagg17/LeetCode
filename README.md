# LeetCode
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int lenght = 0;
        int i = 0;
        int j = 0;
        int cnt = 0;

        while(j<s.size()){
            cnt += abs(s[j]-t[j]);

            while(cnt>maxCost){
                cnt -= abs(s[i]-t[i]);
                i++;
            }
            lenght = max(lenght , j-i+1);
            j++;
        }
        return lenght;
    }
};
