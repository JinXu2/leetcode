/*
424. 替换后的最长重复字符
给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。

注意：字符串长度 和 k 不会超过 104。



示例 1：

输入：s = "ABAB", k = 2
输出：4
解释：用两个'A'替换为两个'B',反之亦然。
*/

//双指针方法 或者说 滑动窗口 控制开始与结束
/*
本题可以先退化成考虑 K=0K=0 的情况，此时题目就变成了求解字符串中最长连续子串长度问题了。
我们先可以通过这个特例先了解一下滑动窗口的求解过程

https://leetcode-cn.com/problems/longest-repeating-character-replacement/solution/tong-guo-ci-ti-liao-jie-yi-xia-shi-yao-shi-hua-don/


如果当前字符串中的出现次数最多的字母个数 +K+K 大于串长度，那么这个串就是满足条件的

historyCharMax 保存滑动窗口内相同字母出现次数的 历史 最大值，通过判断窗口宽度 (right - left + 1)(right−left+1) 是否大于 historyCharMax + KhistoryCharMax+K 来决定窗口是否做滑动，否则窗口就扩张。


*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> map(26);
        if(s.empty())
        {
            return 0;
        }
        int left=0;
        int right=0;

        int historyMax=0;
        for(right=0;right<s.length();right++)
        {
            int index=s[right]-'A';
            map[index]++;
            historyMax=max(historyMax,map[index]);
            if(right-left+1-historyMax>k)
            {
                map[s[left]-'A']--;
                left++;
            }

        }
        return right-left;
    }
};

