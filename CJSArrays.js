let colors=['red','green',"yellow"]
console.log(colors)
console.log(colors.length)
colors.push('banana')
colors.push('car')
console.log(colors)
colors.pop()
console.log(colors)

// Push=add to end
// Pop=remove from end
// shift=remove from start
// unshift=add from start


let temp=[12,23,34,45,56,67]
console.log(temp)
temp.shift()
temp.shift()
console.log(temp)
temp.unshift(100)
console.log(temp)

let cats=['Arushi','Deepika']
let dogs=['Dhruv','Khushal']

console.log(cats.concat(dogs))
console.log(dogs.concat(cats))

console.log(cats.includes('Arushi'))
console.log(cats.includes('Ryu'))

console.log(cats.indexOf('Deepika'))
console.log(cats.indexOf('Kaju'))

console.log(cats.reverse())

let vibe=[10,20,30,40,50]
// console.log(vibe.slice(2,4))
// console.log(vibe)

// console.log(vibe.slice(-2))
// console.log(vibe)

// console.log(vibe.splice(1,2))   //delete 2 elements starting from index 1
// console.log(vibe)

// console.log(vibe.splice(1,3,'khushal'))  //delete 2 elements starting from index 1
// console.log(vibe)

console.log(vibe.splice(2,0,'Hero'))   // add Hero at index 2  without deleting any element
console.log(vibe)

console.log([1,2,3]===[1,2,3]);   //false becasue === compares address
let num=[1,2,3]
let numcopy=num;     // here by default it is compared by refrence as numcopy = &num as in C++
num.push(100)
console.log(num) 
console.log(numcopy)    // 100 will be add in both the arrays

const hello=[11,22,33]
hello.push(100)  // we can change the  contents of  this const array because we are changing the contents not the address of the array
console.log(hello) 

let gameboard=[[1,2,3],[10,20,30],[11,22,33]]
console.log(gameboard)
console.log(gameboard[1][1])



