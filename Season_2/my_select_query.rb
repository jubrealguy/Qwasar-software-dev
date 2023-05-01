require 'csv'

class MySelectQuery
    def initialize(content)
        @rows = CSV.parse(content, headers: true)
    end

    def where(column, criteria)
        result = []
        @rows.filter do |row|
            if row[column] == criteria
                result << row.to_hash.values.join(',')
            end
        end
        result
    end
end