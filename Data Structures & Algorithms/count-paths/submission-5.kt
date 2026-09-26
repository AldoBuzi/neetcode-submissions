class Solution {
    fun uniquePaths(m: Int, n: Int): Int {
        val matrix = Array(m) { IntArray(n) }
        for (i in matrix.indices) {
            for (j in matrix[i].indices) {
                if (i == 0 || j == 0) {
                    matrix[i][j] = 1
                } else {
                    matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1]
                }
            }
        }
        return matrix[m - 1][n - 1]
    }
}