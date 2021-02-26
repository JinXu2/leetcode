/*
1128. 等价多米诺骨牌对的数量
给你一个由一些多米诺骨牌组成的列表 dominoes。

如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。

形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。

在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。



示例：

输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
输出：1
*/

//一开始肯定想要用哈希 但是自己看题目就可以直接把数对看成是 一个两位数

class Solution{
public:
    //如果有2个一样的+1 3个一样的是 +2+1 4个一样的是+3+2+1 所以巧妙利用了res[num]这个计数工具    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        vector<int> nums(100);
        int ret=0;
        for(auto& it: dominoes)
        {
            int val = it[0]<it[1]? it[0]*10+it[1] :it[1]*10+it[0];
            ret+=nums[val];
            nums[val]++;
        }
        return ret;
    }
};
