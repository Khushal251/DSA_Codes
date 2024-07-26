// function printTheWord(){
//     console.log("This is a function call")
// }
// printTheWord()

// function goodMorning(name){
//     console.log(`Good Morning ${name} have a nice day`)
// }

// goodMorning('Khushal')

// console.log(("This is a function call").toUpperCase())

// function goodNight(name,time){
//     console.log(`Good Night ${name} time is ${time}`)
// }

// goodNight("Dipesh",12)

// function sum(num1,num2){
//     let x=num1+num2;
//     return x;
// }
// console.log(sum(5,3))


// function lastElement(arr)
// {
//     // console.log(arr.length)
//     console.log(arr[arr.length-1])
    
    
// }
// arr=[1,2,3]
// lastElement(arr);

// function capitalize(s){
//     s.charAt(0).toUpperCase()
//     return s;
// }
// console.log(capitalize("romo"))
// let l="romero"
// console.log(l.charAt(0).toUpperCase())
// console.log(l)
// console.log(l.slice(1))

// function sumArray(arr)
// {
//     let sum=0;
//     // for(let value in arr)
//     // {
//     //     sum=sum+parseInt(value);
//     // }
//     for(let i=0;i<arr.length;i++)
//     {
//         sum=sum+parseInt(arr[i])
//     }
//     return sum;
// }

// console.log(sumArray([2,4,4]))

const day={
    0:null,
    1:"Monday",
    2:"Tuesday",
    3:"Wednesday",
    4:"Thursday",
    5:"Friday",
    6:"Saturday",
    7:"Sunday"
};
function returnDay(num)
{
    
    return day.num;

}

console.log(returnDay(3))

