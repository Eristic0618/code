//����һ���ַ��� s ����֤ s �Ƿ��� ���Ĵ� ��ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
// �����У������ַ�������Ϊ��Ч�� ���Ĵ� ��
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