/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    fun isValidBST(root: TreeNode?): Boolean {
        val (result, _, _) = isValid(root)
        return result
    }

    /*private fun isValid(node: TreeNode?, min: Int?, max: Int?): Boolean {
        if (node == null) return true

        if (min != null && node.`val` <= min) return false
        if (max != null && node.`val` >= max) return false
        return isValid(node.left, min, node.`val`) && 
               isValid(node.right, node.`val`, max)
    }*/
    private fun isValid(node: TreeNode?): Triple<Boolean, Int?, Int?> {
    if (node == null) return Triple(true, null, null)

    val (is_l_ok, l_min, l_max) = isValid(node.left)
    val (is_r_ok, r_min, r_max) = isValid(node.right)

    val leftIsOk = l_max == null || node.`val` > l_max
    val rightIsOk = r_min == null || node.`val` < r_min
    val isCurrentOk = is_l_ok && is_r_ok && leftIsOk && rightIsOk
    val currentMin = l_min ?: node.`val`
    val currentMax = r_max ?: node.`val`

    return Triple(isCurrentOk, currentMin, currentMax)
}
}