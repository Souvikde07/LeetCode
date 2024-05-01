/**
 * @param {string} s
 * @return {string}
 */

var reverseWords = function(s) {
    let words= s.split(' ')
    let res= ''

    for(let i=words.length-1;i>=0;i--){
        if(words[i].length == 0) continue
        else {
            if(res.length == 0) res += words[i]
            else res += " " + words[i]
        }
    }
    return res
};
/*var reverseWords = function(s) {
    return s.trim().split(" ").filter(w=>w).reverse().join(' ')
};*/