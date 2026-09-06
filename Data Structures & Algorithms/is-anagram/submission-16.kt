class Solution {
    fun isAnagram(s: String, t: String): Boolean {
        val sset: Map<Char, Int> = s.groupingBy({it}).eachCount()
        val tset: Map<Char, Int> = t.groupingBy({it}).eachCount()
        println(sset)
        return sset == tset
    }
}
