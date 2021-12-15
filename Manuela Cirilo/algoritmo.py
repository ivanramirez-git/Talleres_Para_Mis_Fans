def cargar_datos_csv():
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

    return vuelos

"""
# Retornar los datos en una lista cargando un archivo excel xlsx
def cargar_datos_xlsx():
    import xlrd
    import json

    # abrir el archivo excel
    book = xlrd.open_workbook('vuelos/info.xlsx')

    # obtener la hoja de calculo
    sheet = book.sheet_by_index(0)

    # lista vacia para guardar los datos
    vuelos = []

    # recorrer la hoja de calculo
    for row in range(1, sheet.nrows):
        # obtener los datos de la fila
        datos = sheet.row_values(row)

        # guardar los datos en la lista
        vuelos.append(datos)

    # convertir la lista a json
    json_string = json.dumps(vuelos, indent=4, sort_keys=True)

    # retornar la lista de datos
    return vuelos
"""