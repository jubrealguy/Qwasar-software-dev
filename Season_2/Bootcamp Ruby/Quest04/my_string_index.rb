def my_string_index(haystack, needle)
    for i in 0..haystack.length
        if needle == haystack[i]
            return i
            break
        end
    end
    return -1
end