# -*- coding: utf-8 -*-
"""
Created on Wed Feb  8 08:02:29 2023

@author: baugstein
"""
from flask import Flask
from flask import Flask, jsonify, request,json
 


# Flask constructor takes the name of
# current module (__name__) as argument.
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello World'

@app.route('/form_example', methods=['POST'])
def handle_form():
    print(request.form.get('name'))
    print(request.form.get('age'))
    return request.form


@app.route('/string_example', methods=['POST'])
def handle_non_json():
    data = json.loads(request.data)
    return data

if __name__ == '__main__': 
    host = "127.0.0.1"
    app.run(host=host, port=57123)

#post method 
#curl -X POST -H "Content-type: application/json" -d "{\"name\" : \"John\", \"age\" : \"5\"}" "http://127.0.0.1:57123/string_example"
#note data isn't processed