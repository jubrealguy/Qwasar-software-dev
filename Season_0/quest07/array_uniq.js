function my_array_uniq(arr_list) {
    return Array.from(new Set(arr_list));
};

//console.log(my_array_uniq([1, 1, 1, 2, 3, 4, 1]));