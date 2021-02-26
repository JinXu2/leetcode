/*
766. 托普利茨矩阵
给你一个 m x n 的矩阵 matrix 。如果这个矩阵是托普利茨矩阵，返回 true ；否则，返回 false 。

如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵 。



示例 1：


输入：matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
输出：true
解释：
在上述矩阵中, 其对角线为:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。
各条对角线上的所有元素均相同, 因此答案是 True 。
*/

//以下为Java语言
//最简单的方便一条条对角线来看 但是这样要两个循环吧 还要考虑边界 更简单的是 将每一个元素与自己左上角的元素进行对比

class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int m=matrix.length,n=martrix[0].length;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]!=matrix[i-1][j-1])
                {
                    return false;
                }
            }
        }
        return true;
    }
}

//进阶如果一次最多只能将矩阵的一行加载到内存中 将每一行复制到一个连续数组中，随后在读取下一行时，就与内存中此前保存的数组进行比较。

class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int m=matrix.length,n=martrix[0].length;
        int[] temp = new int[n];
        temp=matrix[0];
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(temp[j-1]!=matrix[i][j])
                {
                    return false;
                }
            }
            temp=matrix[i];
        }
    }
}

//对于进阶问题二，一次只能将不完整的一行加载到内存中，我们将整个矩阵竖直切分成若干子矩阵，并保证两个相邻的矩阵至少有一列或一行是重合的，然后判断每个子矩阵是否符合要求。

