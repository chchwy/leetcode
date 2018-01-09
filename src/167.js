/**
 * 167. Two Sum II - Input array is sorted
 * @author chchwy
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    for (var i = 0; i < numbers.length; i += 1) {
        for (var j = i + 1; j < numbers.length; j += 1) {
            if (numbers[i] + numbers[j] === target) {
                return [i+1, j+1];
            }
            
            var diff = target - numbers[i];
            if (numbers[j] >= diff)
                break;
        }
    }
};
