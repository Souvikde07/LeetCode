/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    let m = word1.length
    let n = word2.length
    let result = ''
    const maxLength = Math.max(word1.length, word2.length);
    for(let i=0; i < maxLength; i++){
        if(i<m) result += m[i]
        if(i<n) result += n[i]
    }
    return result
};