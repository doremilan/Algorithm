const input = require("fs")
  .readFileSync("/dev/stdin")
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