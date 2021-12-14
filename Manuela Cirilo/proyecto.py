import csv
import json

# convertir un archivo csv a formato json
sv_file = open('vuelos/info.csv', 'r')
json_file = open('vuelos/info.json', 'w')

# archivo csv a lista separada por puntos y comas
csv_reader = csv.DictReader(sv_file, delimiter=';')


# lista vacia para guardar los datos
vuelos = []


# recorrer la lista de datos
for row in csv_reader:
    # guardar los datos en la lista
    vuelos.append(row)


# convertir la lista a json
json_string = json.dumps(vuelos, indent=4, sort_keys=True)


# escribir el json en el archivo
json_file.write(json_string)


# cerrar los archivos
sv_file.close()
json_file.close()


