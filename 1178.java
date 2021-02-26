/*
1178. 猜字谜
外国友人仿照中国字谜设计了一个英文版猜字谜小游戏，请你来猜猜看吧。

字谜的迷面 puzzle 按字符串形式给出，如果一个单词 word 符合下面两个条件，那么它就可以算作谜底：

单词 word 中包含谜面 puzzle 的第一个字母。
单词 word 中的每一个字母都可以在谜面 puzzle 中找到。
例如，如果字谜的谜面是 "abcdefg"，那么可以作为谜底的单词有 "faced", "cabbage", 和 "baggage"；而 "beefed"（不含字母 "a"）以及 "based"（其中的 "s" 没有出现在谜面中）。
返回一个答案数组 answer，数组中的每个元素 answer[i] 是在给出的单词列表 words 中可以作为字谜迷面 puzzles[i] 所对应的谜底的单词数目。



示例：

输入：
words = ["aaaa","asas","able","ability","actt","actor","access"],
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
输出：[1,1,3,2,4,0]
解释：
1 个单词可以作为 "aboveyz" 的谜底 : "aaaa"
1 个单词可以作为 "abrodyz" 的谜底 : "aaaa"
3 个单词可以作为 "abslute" 的谜底 : "aaaa", "asas", "able"
2 个单词可以作为 "absoryz" 的谜底 : "aaaa", "asas"
4 个单词可以作为 "actresz" 的谜底 : "aaaa", "asas", "actt", "access"
没有单词可以作为 "gaswxyz" 的谜底，因为列表中的单词都不含字母 'g'。
*/

class Solution {
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        Map<Integer,Integer> frequency = new HashMap<Integer,Integer>();
        for(String word:words){
            int mask=0;
            for(int i=0;i<word.length();i++)
            {
                char ch=word.charAt(i);
                //26个字母 26个位置 有就是1 所以要左移几个位置，取或
                mask |= (1<<(ch-'a'));
            }
            if(Integer.bitCount(mask)<=7)
            {
                frequency.put(mask,frequency.getOrDefault(mask,0)+1);
            }

        }
        List<Integer> ans = new ArrayList<Integer>();
        for(String puzzle:puzzles)
        {
            int total=0;
            //枚举子集
            int mask = 0;
            for(int i=1;i<7;i++)
            {
                //跟上面一样 获得puzzle后6位的二进制数
                mask |=(1 << (puzzle.charAt(i)-'a'));
            }
            int subset = mask;
            //生成子集的方式 说的是二进制表示上面为01的排列组合情况，因此要与原来取与，这样子原本是0的就一直会是0 i - 1使得末尾的0全部变成1，但是由于&s，原来是0的位无论如何也不会变成1，但是原来是1的位就形成了不断-1的模式
            do{
                //把第一位也算进去
                int s = subset | (1 <<(puzzle.charAt(0)-'a'));
                if(frequency.containsKey(s)){
                    total+=frequency.get(s);
                }
                subset = (subset-1) & mask;
            }while(subset!=mask);

            ans.add(total);
        }
        return ans;
    }
}
