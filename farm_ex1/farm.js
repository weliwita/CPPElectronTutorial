const myAddon = require('./build/Release/addon')  
console.log(myAddon.WhoIsThis())  

for (let i = 0; i < 6; i++) {  
  console.log(`native addon increment: ${myAddon.Increment(i)}`)
}