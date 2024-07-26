// class Hello extends React.Component{
//     render(){
//         return <h1>Hello There</h1>

//     }
// }

// class Hello extends React.Component{
//     render(){
//         return <h1>Hello {this.props.to} from {this.props.from}</h1>

//     }
// }

// class Hello extends React.Component{
//     render(){
//         console.log(this.props)
//         return <h1>Hello {this.props.to} from {this.props.from} number is {this.props.num} and data is {this.props.data[1]}  </h1>

//     }
// }

// class Hello extends React.Component{
//     render(){
//         let ans="!".repeat(this.props.bangs)
//         return <h1>Hello {this.props.to} from {this.props.from} {ans}</h1>

//         

//     }
// }

// class Hello extends React.Component{
//     render(){
//         let ans="!".repeat(this.props.bangs)
//         return(
//         <div>
//         <p><h1>Hello {this.props.to} from {this.props.from} {ans}</h1></p>
//         <img src={this.props.img}/>
//         </div>
//         )

//     }
// }


// class Hello extends React.Component {
//     render() {
//         const { name, hobbies } = this.props;
//         return (
//             <div>
//                 <h1>{name}</h1>
//                 <ul>
//                     {hobbies.map(h => <li>{h}</li>)}
//                 </ul>
//             </div>
//         )

//     }
// }

// class Hello extends React.Component{
//     static defaultProps={
//         from: 'Anonymous'
//     }
//     render(){
//         let bangs="!".repeat(this.props.bangs)
//         return <h1>Hello {this.props.to} from {this.props.from} {bangs}</h1>
//         //here from is not passed so we it didnt show anything
//         //thats why we declare static

        

//     }
// }