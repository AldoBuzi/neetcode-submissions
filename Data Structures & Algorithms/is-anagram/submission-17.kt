class Solution {
    fun isAnagram(s: String, t: String): Boolean {
        val sset: Map<Char, Int> = s.groupingBy({it}).eachCount()
        val tset: Map<Char, Int> = t.groupingBy({it}).eachCount()
        return sset == tset
    }
}
