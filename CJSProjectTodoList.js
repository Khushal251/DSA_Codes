let input = prompt("What do you want to do")
let todos = ["Dudh lana hai", "Chai banani hai"]
while (input !== "quit") {
    if (input === "list") {
        console.log("****************")
        for (let i = 0; i < todos.length; i++) {
            console.log(`${i}: ${todos[i]}`)

        }
        console.log("****************")
    }

    else if (input === "new") {
        let temp = prompt("OK! What is the new you wanted to do")
        todos.push(temp)
        console.log(`${temp} is added to the list`)
    }
    else if(input==="delete")
    {
        let hash=parseInt(prompt("OK! Enter the index to delete"))
        if(!Number.isNaN(hash))
        {
            let del=todos.splice(hash,1)
            console.log(`${del} has been deleted from the list`)
        }
        else
        {
            console.log("Enter index is not valid")
        }
    }

input = prompt("What do you want to do")



}
console.log("OK quit the app")