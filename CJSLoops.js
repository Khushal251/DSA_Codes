// let guess=parseInt(prompt("Enter the number"))
// let num=10;

// while(guess<num)
// {
//     if(guess<num)
//     {
//         guess=parseInt(prompt("Number is less than 10 so enter again"))
//     }
//     else
//     {
//         break;
//     }
// }
// console.log("Got it")



for (let i = 0; i < 5; i++) {
    
    console.log(11)
    
}

let army=[2,4,6,3]
for(let value of army)
{
    console.log(value)
}

const set=[
    [1,2,4],
    [11,22,33],
    [55,66,77]
]

for(let value1 of set)
{
    for(let value2 of value1)
    {
        console.log(value2)
    }
}

for(let value of "Hello World")
{
    console.log(value)
}

const subject={
    math: 11,
    chemistry: 22,
    physics: 33
}

for(let value in subject)     // for in is used where there is objects where value is key 
{
    console.log(`${value} scored ${subject[value]} marks`)
}

console.log(Object.keys(subject))   // Give us an array of keys
console.log(Object.values(subject))  // Give us an array of values


let total=0;
for(let value of Object.values(subject))
{
    total=total+value;
}
console.log(total);

