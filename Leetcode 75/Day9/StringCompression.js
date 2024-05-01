/**
 * @param {character[]} chars
 * @return {number}
 */
var compress = function(chars) {
    let i=0, len = 0
    while(i<chars.length){
        let curChar=chars[i]
        chars[len++] = curChar

        let count = 0
        while(i<chars.length && curChar == chars[i]){
            count ++
            i++
        }
        if (count>1){
            count = count.toString().split('')
            for(let c of count){
                chars[len++] = c
            }
        }
    }
    return len
};