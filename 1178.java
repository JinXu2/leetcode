/*
1178. ������
������˷����й����������һ��Ӣ�İ������С��Ϸ���������²¿��ɡ�

���յ����� puzzle ���ַ�����ʽ���������һ������ word ��������������������ô���Ϳ��������յף�

���� word �а������� puzzle �ĵ�һ����ĸ��
���� word �е�ÿһ����ĸ������������ puzzle ���ҵ���
���磬������յ������� "abcdefg"����ô������Ϊ�յ׵ĵ����� "faced", "cabbage", �� "baggage"���� "beefed"��������ĸ "a"���Լ� "based"�����е� "s" û�г����������У���
����һ�������� answer�������е�ÿ��Ԫ�� answer[i] ���ڸ����ĵ����б� words �п�����Ϊ�������� puzzles[i] ����Ӧ���յ׵ĵ�����Ŀ��



ʾ����

���룺
words = ["aaaa","asas","able","ability","actt","actor","access"],
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
�����[1,1,3,2,4,0]
���ͣ�
1 �����ʿ�����Ϊ "aboveyz" ���յ� : "aaaa"
1 �����ʿ�����Ϊ "abrodyz" ���յ� : "aaaa"
3 �����ʿ�����Ϊ "abslute" ���յ� : "aaaa", "asas", "able"
2 �����ʿ�����Ϊ "absoryz" ���յ� : "aaaa", "asas"
4 �����ʿ�����Ϊ "actresz" ���յ� : "aaaa", "asas", "actt", "access"
û�е��ʿ�����Ϊ "gaswxyz" ���յף���Ϊ�б��еĵ��ʶ�������ĸ 'g'��
*/

class Solution {
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        Map<Integer,Integer> frequency = new HashMap<Integer,Integer>();
        for(String word:words){
            int mask=0;
            for(int i=0;i<word.length();i++)
            {
                char ch=word.charAt(i);
                //26����ĸ 26��λ�� �о���1 ����Ҫ���Ƽ���λ�ã�ȡ��
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
            //ö���Ӽ�
            int mask = 0;
            for(int i=1;i<7;i++)
            {
                //������һ�� ���puzzle��6λ�Ķ�������
                mask |=(1 << (puzzle.charAt(i)-'a'));
            }
            int subset = mask;
            //�����Ӽ��ķ�ʽ ˵���Ƕ����Ʊ�ʾ����Ϊ01�����������������Ҫ��ԭ��ȡ�룬������ԭ����0�ľ�һֱ����0 i - 1ʹ��ĩβ��0ȫ�����1����������&s��ԭ����0��λ�������Ҳ������1������ԭ����1��λ���γ��˲���-1��ģʽ
            do{
                //�ѵ�һλҲ���ȥ
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
