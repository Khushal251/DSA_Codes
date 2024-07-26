const num=[2,4,6,8,10]

function print(element)
{
    console.log(element);
}

num.forEach(print)
//or
num.forEach(function(value){
    console.log(value)
})

const ans=num.map(function(value){     //Map is same as for each as it applys the function to every value but the difference is that it stores the returning value of each function call in a new array
    return value*2;

})

for(let i=0;i<num.length;i++)
{
    console.log(ans[i])
}


//3 ways to declare a finction

function add(x,y){
    return x+y;
}

const addi=function(x,y){
    return x+y;
}

const addition=(x,y)=>{
    return x+y;
}

console.log(add(2,4))
console.log(addi(2,4))
console.log(addition(2,4))


const sum=(x,y)=>{    //note= ${this.name} here this function won't work inside arrow function 
    return x+y;
}
//another syntax of arroww function is just replace {} with () and remove return
const suming=(x,y)=>(
    x+y
)
console.log(sum(3,5))
console.log(suming(3,5))

// SetTimeOuts
// console.log("Hello...")
// setTimeout(()=>{
//     console.log("are you still there..."),3000
// })
// console.log("Bye")

// const id=setInterval(()=>{console.log("Ha Ha Ha"),3000})
clearInterval()

let numbers=[1,2,3,4,5,6,7,8,9]

//filters
let newnumbers=numbers.filter((value)=>{   //filters makes a new array for those values which returns true with the given condition
    return value%2==0
})
console.log(newnumbers)

//every
let check=numbers.every((value)=>{    //every returns true if every value returns true for the given condition
    return value<20
})
console.log(check)

//Some
let checking=numbers.some((value)=>{    //some returns true if some of the value returns true for the given condition
    return value>5
})
console.log(checking)

//Reduce
let answer=numbers.reduce((accumulator,currentValue)=>{    //First the accumulator taks the first element of the arry and current value stores the second element in it
    return accumulator+currentValue                        //and the function return there sum in the first call, now for the second call stores the previous return value 
})                                                         //and current stores next element of the given array and the process continues

console.log(answer)