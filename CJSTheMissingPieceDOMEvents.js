// let me=document.querySelector('#hub')
// me.onclick=function(){
//     console.log("YEEEEEEE!!!")
//     console.log("WOOOOOOO!!!")
// }

// function greet(){
//     console.log("Stop touching me")
// }
// me.onmouseenter=greet;
// let num=document.querySelector('#new')
// // num.addEventListener('click',function(){   
// //     alert('clicked it') 
// // })

// //or
// num.addEventListener('click',greet())


// function shout(){
//     console.log("shout")
// }
// function twist(){
//     console.log("twist")
// }
// let snt=document.querySelector('#snt')
// snt.addEventListener('click',shout,{once:true})
// snt.addEventListener('click',twist)

// let clr=document.querySelector('#clr')
// clr.addEventListener('click',function (){
//     document.body.style.backgroundColor='yellow'
// }) 

// const input=document.querySelector('input');
// input.addEventListener('keydown',function(e){
//     // console.log("KEYDOWN")
//     console.log(e.key)
//     console.log(e.code)
// })

// const form=document.querySelector("#shelterForm")
// const inn=document.querySelector("#catName")
// const list=document.querySelector("#cats")
// form.addEventListener("submit",function(e){
//     e.preventDefault();   //if we dont do this it the form will go to the shelter
//     console.log("Submited!!!");
//     const catName=inn.value;
//     const newLI=document.createElement("LI")
//     newLI.innerText=catName;
//     list.append(newLI);
// })


// const tweetForm=document.querySelector('#tweetForm')
// const tweetsContainer=document.querySelector('#Tweets')
// tweetForm.addEventListener('submit',function(e){
//     // const usernameinput=document.querySelectorAll('input')[0];
//     // const tweetinput=document.querySelectorAll('input')[1];
//     console.log("Submited!!!")
//     e.preventDefault();

//     // const username=tweetForm.elements.username.value;
//     // const tweet=tweetForm.elements.tweet.value;
//     const usernameInput=tweetForm.elements.username;
//     const tweetInput=tweetForm.elements.tweet;
    
//     addTweet(usernameInput.value,tweetInput.value);

//     usernameInput.value='';
//     tweetInput.value='';

    
    
// })

// const addTweet=(username,tweet)=>{
//     const newTweet=document.createElement('li');
//     const bTag=document.createElement('b');
//     bTag.append(username)
//     newTweet.append(bTag);
//     newTweet.append(`- ${tweet}`)
//     console.log(newTweet);
//     tweetsContainer.append(newTweet);
    
// }

// const input = document.querySelector('input');
// const h1=document.querySelector('h1');

// input.addEventListener('change',function(e){
//     console.log("Cascade");
// })

// input.addEventListener('input',function(e){
//     h1.innerText=input.value;
// })

// const btn=document.querySelector('#btn');
// const para=document.querySelector('#para');
// const sec=document.querySelector('#sec');

// btn.addEventListener("click",function(){
//     alert('button clicked')
//     // e.stopPropagation()  // it stops the upcoming exicution
//     // console.log("yesss")
// })
// para.addEventListener("click",function(e){
//     alert('para clicked')
//     e.stopPropagation()
//     // console.log("yesss")
// })
// sec.addEventListener("click",function(){
//     alert('sec clicked')
//     // console.log("yesss")
// })







const tweetForm=document.querySelector('#tweetForm')
const tweetsContainer=document.querySelector('#Tweets')
tweetForm.addEventListener('submit',function(e){
    // const usernameinput=document.querySelectorAll('input')[0];
    // const tweetinput=document.querySelectorAll('input')[1];
    console.log("Submited!!!")
    e.preventDefault();

    // const username=tweetForm.elements.username.value;
    // const tweet=tweetForm.elements.tweet.value;
    const usernameInput=tweetForm.elements.username;
    const tweetInput=tweetForm.elements.tweet;
    
    addTweet(usernameInput.value,tweetInput.value);

    usernameInput.value='';
    tweetInput.value='';
  
})

const addTweet=(username,tweet)=>{
    const newTweet=document.createElement('li');
    const bTag=document.createElement('b');
    bTag.append(username)
    newTweet.append(bTag);
    newTweet.append(`- ${tweet}`)
    console.log(newTweet);
    tweetsContainer.append(newTweet);
    
}


const lis = document.querySelectorAll('li')
for(let li of lis)
{
    li.addEventListener('click',function(){
        li.remove();
    })  //This code delete the the list elements which is already present not of those which are added newly
}

tweetsContainer.addEventListener('click',function(e){
    e.target.nodeName==='LI' && e.target.remove();  //This will remove the new elements in the list also
})
