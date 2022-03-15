# -*- coding: utf-8 -*-
"""
Created on Mon Mar 14 16:47:23 2022

@author: baugstein
"""
import json

data = {
    'employees' : [
        {
            'name' : 'John Doe',
            'department' : 'Marketing',
            'place' : 'Remote'
        },
        {
            'name' : 'Jane Doe',
            'department' : 'Software Engineering',
            'place' : 'Remote'
        },
        {
            'name' : 'Don Joe',
            'department' : 'Software Engineering',
            'place' : 'Office'
        }
    ]
}


json_string = json.dumps(data)
print(json_string)

# Directly from dictionary
with open('json_data.json', 'w') as outfile:
    json.dump(json_string, outfile)
  
# Using a JSON string
with open('json_data.json', 'w') as outfile:
    outfile.write(json_string)
    
with open('json_data.json') as json_file:
    data = json.load(json_file)
    print(data)

print("")    

print(data['employees'][1])
print(data['employees'][0]['name'])
print("")  


    
  
