class Solution {
    fun characterReplacement(s: String, k: Int): Int {
        var left = 0
        var maxLength = 0
        var maxFreq = 0
        val charCounts = IntArray(26)

        for (right in s.indices) {
            val rightCharIndex = s[right] - 'A'
            charCounts[rightCharIndex]++
            maxFreq = maxOf(maxFreq, charCounts[rightCharIndex])
            val windowLength = right - left + 1
            if (windowLength - maxFreq > k) {
                val leftCharIndex = s[left] - 'A'
                charCounts[leftCharIndex]--
                left++
            }
            maxLength = maxOf(maxLength, right - left + 1)
        }
        return maxLength
    }
}