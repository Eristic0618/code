// https://leetcode.cn/problems/lemonade-change/description/
// 在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
// 每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
// 注意，一开始你手头没有任何零钱。
// 给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

// 贪心算法
class Solution
{
public:
    int countfive;
    int countten;

    bool lemonadeChange(vector<int> &bills)
    {
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
                countfive++;
            else if (bills[i] == 10)
            {
                if (countfive == 0)
                    return false;
                countfive--;
                countten++;
            }
            else
            {
                if (countten && countfive)
                {
                    countten--;
                    countfive--;
                }
                else if (countfive >= 3)
                    countfive -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};