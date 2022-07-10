const input = require("fs")
  .readFileSync("예제.txt")
  .toString()
  .trim()
  .split(" ");

const [n, k] = input[0].split(" ");

function solution(n, k) {
  const queue = [];
  const answer = [];
  for (let i = 1; i <= n; i++) queue.push(i);

  console.log(queue);

  let count = 1;
  while (queue.length) {
    const shiftItem = queue.shift();
    if (count % k === 0) {
      answer.push(shiftItem);
    } else {
      queue.push(shiftItem);
    }
    count += 1;
  }

  console.log(`<${answer.join(", ")}>`);
}

solution(n, k);
