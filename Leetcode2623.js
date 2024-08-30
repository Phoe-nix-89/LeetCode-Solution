
/* https://leetcode.com/problems/memoize/?envType=study-plan-v2&envId=30-days-of-javascript */

/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let mp1 = new Map();
    let mp2 = new Map();
    let mp3 = new Object();
    return function(...args) {
        if(args.length == 1){
            if(fn.name == "fib"){
                if(mp1.has(args[0])) return mp1.get(args[0]);
                let t = fn(args[0]);
                mp1.set(args[0],t);
                return t;
            }
            else{
                if(mp2.has(args[0])) return mp2.get(args[0]);
                let t = fn(args[0]);
                mp2.set(args[0],t);
                return t;
            }
        }
        else{
            if(mp3.hasOwnProperty([args[0],args[1]])) return mp3[[args[0],args[1]]];
            let t = fn(args[0],args[1]);
            mp3[[args[0],args[1]]] = t;
            //console.log(mp3);
            return t;
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */