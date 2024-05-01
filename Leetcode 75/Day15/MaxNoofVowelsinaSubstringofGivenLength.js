/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxVowels = function(s, k) {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u'])

  let max = 0 // Max number of vowels in any window
  let current = 0 // Number of vowels in the current window

  // Count the total number of vowels from the first window
  for (let i = 0; i < k; i++) {
    if (vowels.has(s[i])) max++
  }
  
  if (max === k) return max // Return if the `k` is hit

  current = max // Set the current to the max

  // Sliding window technique
  for (let i = 1; i <= s.length - k; i++) {
    if (vowels.has(s[i - 1])) current-- // Remove the left-most vowel
    if (vowels.has(s[i + k - 1])) current++ // Add the right-most vowel

    if (current === k) return current // Return if the `k` is hit
    if (current > max) max = current // Set `max` to the `current` value, if greater
  }

  return max
};