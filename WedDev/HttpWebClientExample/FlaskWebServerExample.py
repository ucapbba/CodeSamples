# -*- coding: utf-8 -*-

# Importing flask module in the project is mandatory
# An object of Flask class is our WSGI application.
from flask import Flask
from flask import Flask, jsonify, request
 
# Flask constructor takes the name of
# current module (__name__) as argument.
app = Flask(__name__)

incomes = [
    { 'description': 'salary', 'amount': 5000 }
]
# The route() function of the Flask class is a decorator,
# which tells the application which URL should call
# the associated function.
@app.route('/')
# ‘/’ URL is bound with hello_world() function.
def hello_world():
    return 'Hello World'

@app.route('/incomes')
def get_incomes():
    return jsonify(incomes)

@app.route('/incomes', methods=['POST'])
def add_income():
    incomes.append(request.get_json())
    return '', 204

@app.route('/test', methods=['POST', 'GET'])
def dotest():
      print ('testing')

# main driver function
if __name__ == '__main__': 
    # run() method of Flask class runs the application
    # on the local development server.
    app.run()
    
