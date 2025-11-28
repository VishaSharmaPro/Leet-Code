// Yeh meri javascript ki  sabse pehli problem thi 
// Date == 28 Nov 2025
// link = https://www.youtube.com/watch?v=IDZ-0tGbUI0
// youtube channel = Programing for begineers
checkPrime = (number) =>{
  if(number ===1 || number <1){
    return 'Not Prime'
  }else{
    for(let i = 2;i<=number/2;i++){
      if(number%i===0){
        return 'Not Prime'
      }
    }
    return 'Prime'
  }
}
console.log(checkPrime(7))
