
/* https://leetcode.com/problems/array-reduce-transformation/?envType=study-plan-v2&envId=30-days-of-javascript */

/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let t = init;
    nums.forEach((elem) => {
        let temp = fn(t,elem);
        t = temp;
    });

    return t;
};