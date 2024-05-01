/**
 * @param {number[]} arr
 * @return {boolean}
 */
//with hashmap and a set
//Time =O(n)
var uniqueOccurrences = function(arr) {
    let map = new Map()
    let set = new Set()

    for(let e of arr){
        if(map.has(e)){
            map.set(e,map.get(e)+1)
        }
        else{
            map.set(e,1)
        }
    }
    for (let freq of map.values()){
        if(set.has(freq)) return false
        set.add(freq)
    }
    return true
};
//less runtime :
var uniqueOccurrences = function(arr) {
    const map = {}
    for(let i=0; i<arr.length; i++) map[arr[i]] = 1 + (map[arr[i]] || 0)
    const set = new Set()
    for(const key in map){
        const freq = map[key]
        if(set.has(freq))return false
        set.add(freq)
    }
    return true
};