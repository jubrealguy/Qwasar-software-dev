function my_average_mark(obj_list) {
    let sum = 0;
    let len = obj_list.length;
    for (var i = 0; i < len; i++) {
        sum = sum + obj_list[i]['integer'];
    }
    if (isNaN(sum)) {sum = 0};
    var result = (sum/len).toFixed(1);
};

console.log(my_average_mark([
    {"string": "John", "integer": 7},
    {"string": "Margot", "integer": 8},
    {"string": "Jules", "integer": 4},
    {"string": "Marco", "integer": 19}
   ]));

console.log(my_average_mark([
    {"string": "Quentin", "integer": 1},
    {"string": "Fred", "integer": 1},
    {"string": "Julia", "integer": 18},
    {"string": "stephanie", "integer": 13}
]));

console.log(my_average_mark([]));