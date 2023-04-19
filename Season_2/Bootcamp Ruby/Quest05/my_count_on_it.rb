def my_count_on_it(arr)
    len_arr = Array.new
    for i in 0..arr.length-1
        len_arr[i] = arr[i].length
    end
    return len_arr
end