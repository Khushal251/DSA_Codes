// setTimeout(()=>{
//     document.body.style.backgroundColor='red';
// },4000)

setTimeout(()=>{
    document.body.style.backgroundColor='red';
    setTimeout(()=>{
        document.body.style.backgroundColor='orange';
        setTimeout(()=>{
            document.body.style.backgroundColor='blue';
        },3000)
    },1000)
},1000)