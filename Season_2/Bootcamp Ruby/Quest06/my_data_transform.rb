require 'date'
 
 def transform_age(age)
     if age.to_i < 21
      return "1->20"
     elsif age.to_i < 41
         return "21->40"
     elsif age.to_i < 66
         return "41->65"
     else
         return "66->99"
     end    
 end
 
 
 def transform_email(email)
     result = []
     email.each_line do |i|
       row = i.chomp.split('@')
       result << row[1] if row.length == 2
     end
     result
 end
 
 def transform_time(time)
     datetime_object = DateTime.parse(time)
     if datetime_object.hour < 12
         return "morning"
     elsif datetime_object.hour < 18
             return "afternoon"
     else
         return "evening"
     end
     return datetime_object
 end
 
 def my_data_transform(content_str)
      result = []
      index = 0
      result << content_str.lines.first.strip
     content_str.each_line.with_index do |line, i|
         values = line.chomp.split(',')
 
       if values.length > 1 && i > 0
         
          
          values[5] = transform_age(values[5])
          values[4] = transform_email(values[4])
          values[9] = transform_time(values[9])
        
          index = index + 1
  
         result << values.join(',')
      end 
     end
     result  
 
 end