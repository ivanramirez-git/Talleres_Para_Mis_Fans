
# [ { header: 'Nit o Cedula', propertyPath: 'idNumber', type: tableTypes.string, }, { header: 'Tipo Id', propertyPath: 'docType', type: tableTypes.label, labels: [ { value: 'cc', label: 'Cedula', bgcolor: '#2ED110', fontColor: '#fff' }, { value: 'passport', label: 'Pasaporte', bgcolor: '#23547b', fontColor: '#fff' }, { value: 'rut', label: 'Rut', bgcolor: '#E42828', fontColor: '#fff' }, { value: 'nit', label: 'Nit', bgcolor: '#F1E400', fontColor: '#fff' }, ] }, { header: 'Digito V', propertyPath: 'verificationDigit', type: tableTypes.string, }, { header: 'Tipo Persona', propertyPath: 'personType', type: tableTypes.label, labels: [ { value: 'person', label: 'Natural', bgcolor: '#2ED110', fontColor: '#fff' }, { value: 'company', label: 'Juridica', bgcolor: '#23547b', fontColor: '#fff' }, ] }, { header: 'Razon social', propertyPath: 'companyName', type: tableTypes.string, }, { header: 'Nombre', propertyPath: 'name', type: tableTypes.string, }, { header: 'Segundo Nombre', propertyPath: 'secondName', type: tableTypes.string, }, { header: 'Apellido', propertyPath: 'lastName', type: tableTypes.string, }, { header: 'Segundo Apellido', propertyPath: 'secondLastName', type: tableTypes.string, }, { header: 'Dirección', propertyPath: 'address', type: tableTypes.string, }, { header: 'Ciudad', propertyPath: 'location.name', type: tableTypes.string, }, { header: 'Depto', propertyPath: 'contryState.name', type: tableTypes.string, }, { header: 'Pais', propertyPath: 'country.name', type: tableTypes.string, }, { header: 'Tipo', propertyPath: 'type', type: tableTypes.label, labels: [ { value: 'person', label: 'Natural', bgcolor: '#2ED110', fontColor: '#fff' }, { value: 'company', label: 'Juridica', bgcolor: '#23547b', fontColor: '#fff' }, ] }, { header: 'Celular', propertyPath: 'mobileNumber', type: tableTypes.string, }, { header: 'Telefono', propertyPath: 'landNumber', type: tableTypes.string, }, { header: 'Email', propertyPath: 'email', type: tableTypes.string, }, { header: 'Acciones', propertyPath: '', type: tableTypes.actions, width: "100px", actions: [ { label: 'Editar', type: 'edit' }, ] } ]

import random
import string
import json
import os
import sys
import time

# Funcion para generar un numero de identificacion
def generateIdNumber():
    idNumber = random.randint(100000000, 999999999)
    return idNumber

# Funcion para generar un digito de verificacion
def generateVerificationDigit():
    verificationDigit = random.randint(10, 99)
    return verificationDigit

# Funcion para generar un tipo de documento
def generateDocType():
    docTypes = ['cc', 'passport', 'rut', 'nit']
    docType = random.choice(docTypes)
    return docType

# Funcion para generar un tipo de persona
def generatePersonType():
    personTypes = ['person', 'company']
    personType = random.choice(personTypes)
    return personType

# Funcion para generar un nombre
def generateName():
    name = ''.join(random.choice(string.ascii_lowercase) for i in range(5))
    return name

# Funcion para generar un segundo nombre
def generateSecondName():
    secondName = ''.join(random.choice(string.ascii_lowercase) for i in range(5))
    return secondName

# Funcion para generar un apellido
def generateLastName():
    lastName = ''.join(random.choice(string.ascii_lowercase) for i in range(5))
    return lastName

# Funcion para generar un segundo apellido
def generateSecondLastName():
    secondLastName = ''.join(random.choice(string.ascii_lowercase) for i in range(5))
    return secondLastName

# Funcion para generar una direccion
def generateAddress():
    # Ejemplo de direccion: Calle 123
    firstPartTypes = ['Calle', 'Carrera', 'Avenida', 'Diagonal', 'Transversal', 'Circunvalar', 'Autopista', 'Callejón']
    firstPart = random.choice(firstPartTypes)
    secondPart = random.randint(1, 999)
    address = firstPart + ' ' + str(secondPart)
    return address

locations = [
    {
        'name': 'Colombia',
        'id': 1,
        'code': 'CO',
        'parent': None,
        'type': 'country'
    },
    {
        'name': 'Estados Unidos',
        'id': 2,
        'code': 'US',
        'parent': None,
        'type': 'country'
    },
    {
        'name': 'España',
        'id': 3,
        'code': 'ES',
        'parent': None,
        'type': 'country'
    },
    {
        'name': 'Antioquia',
        'id': 4,
        'code': 'ANT',
        'parent': 1,
        'type': 'state'
    },
    {
        'name': 'Bello',
        'id': 14,
        'code': 'BEL',
        'parent': 4,
        'type': 'city'
    },
    {
        'name': 'Medellin',
        'id': 15,
        'code': 'MED',
        'parent': 4,
        'type': 'city'
    },
    {
        'name': 'Rionegro',
        'id': 16,
        'code': 'RIO',
        'parent': 4,
        'type': 'city'
    },
    {
        'name': 'Atlantico',
        'id': 5,
        'code': 'ATL',
        'parent': 1,
        'type': 'state'
    },
    {
        'name': 'Barranquilla',
        'id': 17,
        'code': 'BAR',
        'parent': 5,
        'type': 'city'
    },
    {
        'name': 'Soledad',
        'id': 18,
        'code': 'SOL',
        'parent': 5,
        'type': 'city'
    },
    {
        'name': 'Boyaca',
        'id': 6,
        'code': 'BOY',
        'parent': 1,
        'type': 'state'
    },
    {
        'name': 'Tunja',
        'id': 19,
        'code': 'TUN',
        'parent': 6,
        'type': 'city'
    },
    {
        'name': 'Sogamoso',
        'id': 20,
        'code': 'SOG',
        'parent': 6,
        'type': 'city'
    },
    {
        'name': 'Duitama',
        'id': 21,
        'code': 'DUI',
        'parent': 6,
        'type': 'city'
    },
    {
        'name': 'State of New York',
        'id': 7,
        'code': 'WA',
        'parent': 2,
        'type': 'state'
    },{
        'name': 'New York',
        'id': 22,
        'code': 'NY',
        'parent': 7,
        'type': 'city'
    },
    {
        'name': 'Manhattan',
        'id': 23,
        'code': 'MAN',
        'parent': 7,
        'type': 'city'
    },
    {
        'name': 'Brooklyn',
        'id': 24,
        'code': 'BRO',
        'parent': 7,
        'type': 'city'
    },
    {
        'name': 'California',
        'id': 8,
        'code': 'CA',
        'parent': 2,
        'type': 'state'
    },
    {
        'name': 'Los Angeles',
        'id': 25,
        'code': 'LA',
        'parent': 8,
        'type': 'city'
    },
    {
        'name': 'San Francisco',
        'id': 26,
        'code': 'SF',
        'parent': 8,
        'type': 'city'
    },
    {
        'name': 'San Diego',
        'id': 27,
        'code': 'SD',
        'parent': 8,
        'type': 'city'
    },
    {
        'name': 'Florida',
        'id': 9,
        'code': 'FL',
        'parent': 2,
        'type': 'state'
    },
    {
        'name': 'Miami',
        'id': 28,
        'code': 'MI',
        'parent': 9,
        'type': 'city'
    },
    {
        'name': 'Orlando',
        'id': 29,
        'code': 'OR',
        'parent': 9,
        'type': 'city'
    },
    {
        'name': 'Tampa',
        'id': 30,
        'code': 'TA',
        'parent': 9,
        'type': 'city'
    },
    {
        'name': 'Comunidad de Madrid',
        'id': 13,
        'code': 'CM',
        'parent': 3,
        'type': 'state'
    },
    {
        'name': 'Madrid',
        'id': 31,
        'code': 'MAD',
        'parent': 13,
        'type': 'city'
    },
    {
        'name': 'Catallunya',
        'id': 32,
        'code': 'CAT',
        'parent': 3,
        'type': 'state'
    },
    {
        'name': 'Barcelona',
        'id': 33,
        'code': 'BAR',
        'parent': 32,
        'type': 'city'
    },
    {
        'name': 'Badalona',
        'id': 34,
        'code': 'BAD',
        'parent': 32,
        'type': 'city'
    }
]

# Funcion para generar una ciudad
def generateCity():
    citys = []
    for location in locations:
        if location['type'] == 'city':
            citys.append(location)
    return random.choice(citys)

# Funcion para generar un company name
def generateCompanyName():
    typesEnd = ['SAS', 'Org', 'Corp', 'Ltda', 'Inc']
    typeEnd = random.choice(typesEnd)
    companyName = generateName() + ' ' + typeEnd
    return companyName


# Funcion para generar un telefono
def generatePhone():
    phone = random.randint(1000000, 9999999)
    return phone

# Funcion para generar un email
def generateEmail(name=None, lastName=None):
    if name == None or lastName == None:
        name = generateName()
        lastName = generateLastName()
    # name + conectorTypes + lastName + number + @ + domainTypes + . + domain
    conectorTypes = ['.', '_', '']
    conector = random.choice(conectorTypes)
    number = random.randint(1, 999)
    domainTypes = ['gmail', 'hotmail', 'yahoo', 'outlook']
    domainType = random.choice(domainTypes)
    domain = random.choice(domainTypes) + '.com'
    email = name + conector + lastName + str(number) + '@' + domain
    return email

# Construir una cadena a partir de una expresion regular
def generateStringFromRegex(regex):

    # Obtener el tipo de dato
    dataType = regex[1]

    # Obtener el numero de caracteres, num esta en formato {num}
    extractedNum = regex[regex.find('{') + 1:regex.find('}')]
    numChars = int(extractedNum)
    

    # Obtener el tipo de dato
    if dataType == 'a':
        dataType = string.ascii_lowercase
    elif dataType == 'A':
        dataType = string.ascii_uppercase
    elif dataType == 'n':
        dataType = string.digits
    elif dataType == 'x':
        dataType = string.ascii_letters + string.digits

    # Generar la cadena
    generatedString = ''.join(random.choice(dataType) for i in range(numChars))

    return generatedString


# if main
if __name__ == '__main__':
    # Construir un archivo de n registros con s nombre del archivo, se pasan por argumentos
    if len(sys.argv) == 3:
        # Numero de registros
        n = int(sys.argv[1])
        # Nombre del archivo
        fileName = sys.argv[2]
        # Crear el archivo
        file = open(fileName, 'w')
        # Algoritmos para generar data falsa con el siguiente formato
        '''
            {
            idNumber: 116456123,
            docType: 'cc',
            verificationDigit: 57,
            personType: 'person',
            companyName: "",
            name: "John",
            secondName: "Doe",
            lastName: "Smith",
            secondLastName: "Smith",
            address: "Calle 123",
            location: { name: "Bogota" },
            contryState: { name: "Bogota" },
            country: { name: "Colombia" },
            type: 'person',
            mobileNumber: "123456789",
            landNumber: "123456789",
            email: "johndoe@yopmail.com",
            custom: [a-d]{7}
            },
        '''
        file.write('export const data = [')
        # Crear el archivo
        for i in range(n):
            # Generar un registro
            idNumber = generateIdNumber()
            docType = generateDocType()
            verificationDigit = generateVerificationDigit()
            type = generatePersonType()
            companyName = generateCompanyName()
            name = generateName()
            secondName = generateSecondName()
            lastName = generateLastName()
            secondLastName = generateSecondLastName()
            address = generateAddress()
            mobileNumber = generatePhone()
            landNumber = generatePhone()
            email = generateEmail(name, lastName)
            city = generateCity()
            contryState = {}
            for location in locations:
                if location['id'] == city['parent']:
                    contryState = location
            country = {}
            for location in locations:
                if location['id'] == contryState['parent']:
                    country = location
            regex = '[a-d]{7}'
            custom = generateStringFromRegex(regex)

            # Crear el registro
            record = {
                'id': i,
                'idNumber': idNumber,
                'docType': docType,
                'verificationDigit': verificationDigit,
                'type': type,
                'personType': type,
                'companyName': companyName,
                'name': name,
                'secondName': secondName,
                'lastName': lastName,
                'secondLastName': secondLastName,
                'address': address,
                'location': city,
                'city': city,
                'state': contryState,
                'country': country,
                'mobileNumber': mobileNumber,
                'landNumber': landNumber,
                'email': email,
                'custom': custom,
            }
            # Escribir la linea en el archivo
            file.write(json.dumps(record) + ',')
        file.write('];')
        # Cerrar el archivo
        file.close()
    else:
        print('Error: Se debe pasar como argumentos el numero de registros y el nombre del archivo')
        print('Ejemplo: python3 generateData.py 1000 data.txt')
