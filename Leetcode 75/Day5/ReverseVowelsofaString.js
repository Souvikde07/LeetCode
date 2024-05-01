/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
    const letters = s.split('')
    let i = 0
    let j = letters.length-1
    const vowels = ['a','e', 'i','o','u', 'A','E','I','O','U']

    while(i<j){
        const left = letters[i]
        const right = letters[j]
        if(!vowels.includes(left)){
            i++
        }else if(!vowels.includes(right)){
            j--
        }else{
            letters[i] = right
            i++
            letters[j]=left
            j--
        }
    }
    return letters.join('')
};