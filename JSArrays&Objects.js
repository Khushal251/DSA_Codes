console.log('hello')


    //    ARRAYS


let marks=[34,65,42,89,45]
const fruits=['orange','apple','pinapple']
const mixed=['str',12,[5,7]]

const arr= new Array(23,45,76,'alpha')
console.log(marks)
console.log(fruits)
console.log(mixed)
console.log(arr)
console.log(fruits[1])

console.log(arr.length)
console.log(Array.isArray(mixed))
console.log(Array.isArray('asdf'))

arr[0]='harry'
console.log(arr)
let elementarray=arr[0]
console.log(elementarray)

let value=marks.indexOf(45)
console.log(value)


// Mutating/Modifing
marks.push(1001)   /* add at end */
marks.unshift(2020)   /* add at start */
console.log(marks)    

marks.pop()
marks.shift()
console.log(marks)

// marks.splice(2,3); 
// console.log(marks)

// marks.reverse()
// console.log(marks)

// let marks2=[1,2,3,4]
// marks=marks.concat(marks2)
// console.log(marks)

// marks=marks.concat('khushal')
// console.log(marks)


    //  OBJECTS


let obj={
    name: 'harry',
    channel: 'COH',
    isActice: true,
    marks: [1,4,5,2]
}

console.log(obj)
console.log(obj.marks)
console.log(obj['marks'])






