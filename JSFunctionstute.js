console.log("this is me");

 function greet(name,varo="greetings from javascript ")   /* "greetings from javascript" is hte default value*/
{
    console.log(varo + name);

    console.log(name + " is a good boy");
}

function sum(a,b,c)
{
    let d=a+b+c;
    return d;
}

let name="harry";
let name1="shubham";
let name2="vijay";
let name3="abhinav";

let greettext="good morning ";
greet(name,greettext);
greet(name1,greettext);
greet(name2,greettext);
greet(name3);
console.log(sum(1,2,3));