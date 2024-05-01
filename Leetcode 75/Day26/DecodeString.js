/**
 * @param {string} s
 * @return {string}
 */
var decodeString = function(s) {
    let counts = [];
    let resultStack = [];
    resultStack.push([]);
    let k = 0;

    for (let ch of s) {
        if (ch >= '0' && ch <= '9') {
            k = k * 10 + parseInt(ch, 10);
        } else if (ch === '[') {
            counts.push(k);
            resultStack.push([]);
            k = 0;
        } else if (ch === ']') {
            let temp = resultStack.pop().join('');
            let count = counts.pop();
            resultStack[resultStack.length - 1].push(temp.repeat(count));
        } else {
            resultStack[resultStack.length - 1].push(ch);
        }
    }

    return resultStack.pop().join('');
};