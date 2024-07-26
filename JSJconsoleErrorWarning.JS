console.time('your program took')
console.log('Hello World');
console.log(4+36);
console.log(36);
console.log([2,8,4,6,4]);
console.log({harry:'this',marks:34})
console.table({harry:'this', marks:34})
// or
const car1 = {name:"Audi", model:"A4"}
const car2 = {name:"Volvo", model:"XC90"}
const car3 = {name:"Ford", model:"Fusion"}
console.table([car1, car2, car3]);

console.warn('This is warning')
// console.clear()
console.timeEnd('your program took')
// console.assert(200<189,'this is not possible')
console.error('this is error')