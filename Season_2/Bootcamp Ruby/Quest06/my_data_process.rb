require 'json'
 def add_values(result, key, value)
   result[key] ||= {}
   result[key][value] ||= 0
   result[key][value] += 1
 end
 
 def my_data_process(content_str)
     result = {
         "Gender" => {},
         "Email" => {},
         "Age" => {},
         "City" => {},
         "Device" => {},
         "Order At" => {},
       }
     
   content_str.shift
   content_str.each do |line|
     values = line.split(',')
     add_values(result, "Gender", values[0])
     add_values(result, "Email", values[4].split('@').last)
     add_values(result, "Age", values[5])
     add_values(result, "City", values[6])
     add_values(result, "Device", values[7])
     add_values(result, "Order At", values[9])
   end
 
 return result.to_json
 end