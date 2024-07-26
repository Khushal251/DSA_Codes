console.log('hello')


// TYPE CONVERSION

let myvar=String(34);
console.log(myvar,(typeof myvar))

let boolvar=String(true);
console.log(boolvar,(typeof boolvar))

let arr=String([1,4,7,8])
console.log(arr.length,(typeof arr))
arr=[1,4,7,8]
console.log(arr.length,(typeof arr))

let i=35;
console.log(i.toString())
console.log(i.toString(),typeof(i.toString()))


let stri=Number("234")
stri=Number("23dfa4")
console.log(stri,(typeof stri));

let number=parseInt('34.456')
let numb=parseFloat('23.876')  /* or  let numb=Number('23.876')  */
console.log(number,(typeof number));
console.log(numb,(typeof numb));

console.log(numb.toFixed(5))   /* 5 digits after decimal point*/


// TYPE COERCION

// let mystr= "645";
// let mynum= 23;
// console.log(mystr+mynum)   /* prefers to convert number into a string*/

let mystr= Number("645");
let mynum= 23;
console.log(mystr+mynum)
