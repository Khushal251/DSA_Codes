// class App extends React.Component{
//     render(){
//         return (
//             <div>
//                 <Hello to="Ringo" from="Paul"/>
//                 <Hello to="Cher" from="Sonny"/>
//             </div>
//         )
//     }
// }

// class App extends React.Component{
//     render(){
//         return (
//             <div>
//                 <Hello 
//                 to="Ringo" 
//                 from="Paul" 
//                 num={3} 
//                 data={[1,2,3,4]}
//                 isFunny={true}
//                 />
//             </div>
//         )
//     }
// }

// class App extends React.Component{
//     render(){
//         return (
//             <div>
//                 <Hello 
//                 to="Ringo" 
//                 from="Paul" 
//                 bangs={4}
//                 />
//             </div>
//         )
//     }
// }

// class App extends React.Component{
//     render(){
//         return (
//             <div>
//                 <Hello 
//                 to="Ringo" 
//                 from="Paul" 
//                 bangs={4}
//                 img="https://cdn.pixabay.com/photo/2015/12/01/20/28/road-1072823__340.jpg"
//                 />
//             </div>
//         )
//     }
// }

class App extends React.Component{
    render(){
        return (
            <div>
                <h1>Slot Machine</h1>
                <Machine 
                s1="😂"
                s2="❤"
                s3="🤞"
                />
                
            </div>
        )
    }
} 

// class Machine extends React.Component{
//     render(){
//         const{s1,s2,s3}=this.props;
//         const winner=(s1===s2) && (s2===s3);


//         return(
//         <div>
//             <p>{s1} {s2} {s3}</p>
//             <p>{winner ? 'Winner!' : 'Loser!'}</p>

//         </div>
//         )
        
//     }
// }

// class App extends React.Component{
//     render(){
//         return (
//             <div>
//                 <Hello 
//                 name="Ryuk"
//                 hobbies={['football','dance','games']}
//                 />
                
//             </div>
//         )
//     }
// } 

// class App extends React.Component{
//     render(){
//         return (
//             <div>
//                 <Hello 
//                 to="Ringo" 
//                 from="Paul" 
//                 bangs={4}
//                 />
//                 <Hello 
//                 to="George"  
//                 bangs={6}    //here we didnt pass any from
//                 />
//             </div>
//         )
//     }
// }




ReactDOM.render(<App/>,document.querySelector('#root'));