# API: http://api.football-data.org/v4/competitions/2014/teams
# headers: {'X-Auth-Token': '9b3189caec1a43398d2ad432a825a0a5'}
# Middleware para obtener los informacion del api sin necesidad de usar el token

import time
import json
import requests

print("Api Football Data is running...")

# Importar librerias

# Declarar variables
url = "http://api.football-data.org/v4"
token = "9b3189caec1a43398d2ad432a825a0a5"
headers = {"X-Auth-Token": token}

# Peticiones http


def get_teams():
    response = requests.get(url + "/competitions/2014/teams", headers=headers)
    return response.json()


print("Teams... ")
# guardar datos en un archivo "teams.json"
with open("teams.json", "w") as outfile:
    json.dump(get_teams(), outfile)
    print("Teams saved!")
