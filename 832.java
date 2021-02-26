/*
832. 翻转图像
给定一个二进制矩阵 A，我们想先水平翻转图像，然后反转图像并返回结果。

水平翻转图片就是将图片的每一行都进行翻转，即逆序。例如，水平翻转 [1, 1, 0] 的结果是 [0, 1, 1]。

反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。例如，反转 [0, 1, 1] 的结果是 [1, 0, 0]。
*/


//最简单直接模拟来实现 会遍历两边 遍历一边的话：就考虑每一种01翻转和反转后的情况
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int n=A.length;
        for(int i=0;i<n;i++)
        {
            int left=0,right=n-1;
            while(left<right)
            {
                if(A[i][left]==A[i][right])
                {
                    A[i][left]^=1;
                    A[i][right]^=1;
                }
                left++;
                right--;
            }
            if(left==right)
            {
                A[i][right]^=1;
            }
        }
        return A;
    }
}
