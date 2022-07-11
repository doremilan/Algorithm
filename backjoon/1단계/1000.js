const input = require("fs")
  .readFileSync("예제.txt")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

let a = input[0];
let b = input[1];

function solution(a, b) {
  let answer = a + b;
  console.log(answer);
}

solution(a, b);

// const fs = require('fs');
// const inputData = fs.readFileSync(0, 'utf8').toString().split(' ');

// const A = parseInt(inputData[0]);
// const B = parseInt(inputData[1]);

// console.log(A+B);
