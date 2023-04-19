def my_csv_parser(inp, del)
    rows = inp.split("\n")
    rows.map { |row| row.split(del) }
end