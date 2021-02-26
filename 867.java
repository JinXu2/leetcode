/*
867. 转置矩阵
给你一个二维整数数组 matrix， 返回 matrix 的 转置矩阵 。

矩阵的 转置 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
*/


class Solution {
    public int[][] transpose(int[][] matrix) {
        int m=matrix.length;
        int n=matrix[0].length;
        /*我这样想是不行的 这得是m=n才可以
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<n;j++)
        }*/
        int[][] res = new int[n][m];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                res[j][i]=matrix[i][j];
            }
        }
        return res;
    }
}
