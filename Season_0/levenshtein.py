def my_levenshtein(s1, s2):
    num = 0
    if len(s1) != len(s2):
        return -1
    else:
        for i, j in zip(range(len(s1)), range(len(s2))):
            if s1[i] != s2[j]:
                num += 1
        return num

# print(my_levenshtein("GGACTGA", "GGACTGA"))
# print(my_levenshtein("ACCAGGG", "ACTATGG"))
# print(my_levenshtein("GGACGGATTCTG", "AGG"))
# print(my_levenshtein("", ""))