function name() {
    // let name1 = "Khushal"
    // var name2 = "Aniket";
    function sum()
    {
        console.log("Hello")
    }
}

// console.log(name1)   // var can be excessed from outside the function but i dont know why here it is not
// console.log(name2)
console.log("Happy New Year")
// sum()


let multiply= function (x,y){     // Here you can declare a function without giving it a name just by saving it into a variable 
    return x*y;
}

console.log(multiply(3,4))

function calltwice(funk)
{
    funk()
    funk()
}
function temp()
{
    console.log("Lets do this")
}
calltwice(temp);


// const subject={
//     multiply: function (num1,num2)
//     {
//         return num1*num2
//     },

//     add: function(num1,num2)
//     {
//         return num1+num2;
//     }
// }

//Or you can also do this

const subject={
    multiply(num1,num2)
    {
        return num1*num2
    },
    
    add(num1,num2)
    {
        return num1+num2;
    }
}
console.log(subject.multiply(2,4))

const cat={
    name:'jerry',
    class: "New",
    colour:'Black',
    meow(){
        // console.log(name)    //Not excessible
        console.log(this.name)
        console.log(`Blue steel says ${this.name}`)
    }
}

cat.meow()

// hello.toUpperCase()    //it will gives an error because hello isn nothing
try{
    hello.toUpperCase() 
}
catch{
    console.log("ERROR!!!")
}
console.log("Continue")

function honey(s){
    try{
        console.log(s.toUpperCase())
    }
    catch{
        console.log("The given argument is not a string")
    }
}

honey('khushal')
honey(45)