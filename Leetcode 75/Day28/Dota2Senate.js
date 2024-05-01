/**
 * @param {string} senate
 * @return {string}
 */
var predictPartyVictory = function(senate) {
    const length = senate.length
    const radQ = []
    const direQ = []

    for (let i = 0; i<length; i++){
        if(senate[i]==='R'){
            radQ.push(i)
        }
        else{
            direQ.push(i)
        }
    }
    while(radQ.length> 0 && direQ.length>0){
        r = radQ.shift()
        d = direQ.shift()

        if(d<r){
            direQ.push(d+length)
        }
        else{
            radQ.push(r+length)
        }
    }
    return radQ.length > 0 ? 'Radiant' : 'Dire'
};