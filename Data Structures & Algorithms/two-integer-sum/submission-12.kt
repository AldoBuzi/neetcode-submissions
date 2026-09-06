class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
    val mymap = mutableMapOf<Int,Int>()
    for ((idx, value) in nums.withIndex()) {
        if (mymap.contains(value)) {
            return intArrayOf(mymap[value]!!, idx)
        }
        mymap[target - value] = idx
    }
    return intArrayOf(-1,-1)
}
}
