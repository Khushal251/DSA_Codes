console.log('welcome')

// SINGLE ELEMENT SELECTOR
let element =document.getElementById('myfirst')
// element=element.className
// element=element.childNodes
// element=element.parentNode
// element.style.color='yellow'
// element.innerText='Harry is a good boy'
// element.innerHTML='<h2>Harry is a good boy</h2>'
// console.log(element)
// console.log(element.innerHTML)

// let sel=document.querySelector('#myfirst')
// sel=document.querySelector('.child')
// sel=document.querySelector('div')   //first div
// sel.style.color='yellow'
// console.log(sel)

// MULTIPLE ELEMENT SELECTOR
// let elems=document.getElementsByClassName('child')
// console.log(elems)
// console.log(elems[0])
// console.log(elems[2])

// let elems=document.getElementsByClassName('container')
// console.log(elems[0].getElementsByClassName('child'))

let elems=document.getElementsByTagName('div')
// // console.log(elems)
// Array.from(elems).forEach(element => {
//     console.log(element);
//     element.style.color='blue';
    
// });

for(let index =0;index<elems.length;index++)
{
    const element=elems[index];
    console.log(element);
    element.style.color='blue';

}

