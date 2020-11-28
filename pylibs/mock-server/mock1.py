from flask import Flask, json
from flask_cors import CORS

companies = [{"id": 1, "name": "Company One"}, {"id": 2, "name": "Company Two"}]

api = Flask(__name__)
CORS(api)

@api.route('/companies', methods=['GET'])
def get_companies():
  return json.dumps(companies)

@api.route('/auth', methods=['POST'])
def auth():
  return json.dumps(companies)

if __name__ == '__main__':
    api.run()