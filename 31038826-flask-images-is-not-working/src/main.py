from flask import Flask, send_from_directory, render_template
from flask_images import Images
import os
app = Flask(__name__)

app.config['UPLOAD_FOLDER'] = 'uploads'
app.secret_key = 'monkey'
images = Images(app)


@app.route('/')
def index():
    return render_template('index.html')


@app.route('/uploads/<filename>')
def download_file(filename):
    return send_from_directory(app.config['UPLOAD_FOLDER'], filename)

if __name__ == '__main__':
    app.run(debug=True)
