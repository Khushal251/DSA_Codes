// class JSXDemo extends React.Component{
//     render(){
//         return (
//             <div>
//             <h1>My Image</h1>
//             <img src="https://cdn.pixabay.com/photo/2015/12/01/20/28/road-1072823__340.jpg" />
//             </div>
//         );
//     }
// }
// class JSXDemo extends React.Component{
//     render(){
//         return (
//             <div>
//             <h1>My number is: {2*8.4}</h1>
//             </div>
//         );
//     }
// }

// function getMood(){
//     const moods=['Angry','Hungry','Silly','Quite','Paranoid'];
//     return moods[Math.floor(Math.random()*moods.length)];
//     // return moods[2];
// }

// class JSXDemo extends React.Component{
//     render(){
//         return (
//             <div>
//             <h1>My mood is: {getMood()}</h1>
//             </div>
//         );
//     }
// }

function getNum(){
    return Math.floor(Math.random()*10)+1;
}

// class JSXDemo extends React.Component{
//     render(){
//         const num=getNum();
//         return (
//             <div>
//             <h1>Your number is: {num}</h1>
//             <p>{num==7 ? 'congrats!' : 'Unlucky!'}</p>
//             {num==7 ? <img src="https://cdn.pixabay.com/photo/2015/12/01/20/28/road-1072823__340.jpg"/>:null}
//             </div>
//         );
//     }
// }

// class JSXDemo extends React.Component{
//     render(){
//         const num=getNum();
//         let msg;
//         if(num==7){
//             msg=<div>
//             <p>{num==7 ? 'congrats!' : 'Unlucky!'}</p>
//             {num==7 ? <img src="https://cdn.pixabay.com/photo/2015/12/01/20/28/road-1072823__340.jpg"/>:null}
//             </div>
//         }
//         else{
//             msg="Bad!"
//         }
//         return (
//             <div>
//             <h1>Your number is: {num}</h1>
//             {msg}
//             </div>
//         );
//     }
// }

class App extends React.Component{
    render(){
        return (
            <div>
                <Hello/>
            </div>
        )
    }
}

ReactDOM.render(<App/>,document.querySelector('#root'));