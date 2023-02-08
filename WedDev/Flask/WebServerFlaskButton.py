from flask import Flask, render_template
app = Flask(__name__)

@app.route('/')
def index():
  return render_template('WebServerButton.html')

@app.route('/my-link/')
def my_link():
  print ('I got clicked!')
  return 'Click.'

if __name__ == '__main__':
    host = "127.0.0.1"
    app.run(host=host, port=57123)
