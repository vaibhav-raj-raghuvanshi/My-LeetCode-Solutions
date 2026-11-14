/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {    
        toBe: function(exp){
            if (val === exp){
                return true;
            }
            throw new Error("Not Equal");
        },
        notToBe: function(exp){
            if (val !== exp){
                return true;
            }
            throw new Error("Equal");
        }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */