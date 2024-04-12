const fs = require('fs');
const jsonData = fs.readFileSync('../test_graphs/Reksio_Graph.json');
const data = JSON.parse(jsonData);

let sumOfOutDegree = 0;
for(let i=1; i<17;i++){
    sumOfOutDegree+= data[i].length;
}

console.log(sumOfOutDegree)
console.log(sumOfOutDegree / 16)