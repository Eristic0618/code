//给定一个字符串 s ，验证 s 是否是 回文串 ，只考虑字母和数字字符，可以忽略字母的大小写。
// 本题中，将空字符串定义为有效的 回文串 。
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        int flag = 0;
        while(l < r)
        {
            while(!isdigit(s[l]) && !isupper(s[l]) && !islower(s[l]) && l < r)
                l++;
            while(!isdigit(s[r]) && !isupper(s[r]) && !islower(s[r]) && l < r)
                r--;
            if(islower(s[l])) 
                s[l] = s[l] - 'a' + 'A';
            if(islower(s[r])) 
                s[r] = s[r] - 'a' + 'A';
            cout << s[l] << " " << s[r] << endl;
            if(s[l] == s[r])
                l++, r--;
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            return false;
        return true;
    }
};