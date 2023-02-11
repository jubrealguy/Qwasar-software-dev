function my_count_on_it(strArr) {
    new_arr = [];
    for (var i = 0; i < strArr.length; i++) {
        new_arr.push(strArr[i].length);
    }
    return new_arr;
};

//console.log(my_count_on_it(["This", "is", "the", "way"]));