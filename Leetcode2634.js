/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

/* https://leetcode.com/problems/filter-elements-from-array/?envType=study-plan-v2&envId=30-days-of-javascript */

var filter = function(arr, fn) {
    let temp = [];
    arr.forEach((elem,i) => {
        if(fn(elem,i)){
            temp.push(elem);
        }
    });

    return temp;
};