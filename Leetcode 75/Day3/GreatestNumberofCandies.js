/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function(candies, extraCandies) {
    var output = []
    var maxCandies = Math.max(...candies)
    for(var i=0;i<candies.length;i++){
        if(candies[i]+extraCandies >= maxCandies){
            output.push(true)
        }
        else{
            output.push(false)
        }
    }
    return output
};

/*Best time complexity:
var kidsWithCandies = function(candies, extraCandies) {
    let mx=Math.max(...candies)
    return candies.map((item)=>(item + extraCandies) >=mx)
};
*/