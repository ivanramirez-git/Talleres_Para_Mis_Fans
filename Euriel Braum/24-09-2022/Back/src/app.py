# Packages
from flask import Flask, jsonify, request
from flask_mysqldb import MySQL
from config import config

# Entities
from models.entities.User import User
from models.entities.Category import Category
from models.entities.Product import Product
from models.entities.Order import Order

# Models
from models.ModelUser import ModelUser
from models.ModelCategory import ModelCategory
from models.ModelProduct import ModelProduct
from models.ModelOrder import ModelOrder

app = Flask(__name__)
app.config.from_object(config['development'])
db = MySQL(app)

# Ruta login


@app.route('/login', methods=['POST'])
def login():
    # Obtenemos los datos del usuario
    print(request.json)
    user = User(None, request.json['username'],
                request.json['password'], None, None, None)
    logger_user = ModelUser.login(db, user)
    if logger_user is not None:
        return jsonify(logger_user.__dict__)
    else:
        return jsonify({"error": "Usuario o contraseña incorrectos"})

# Ruta registro


@app.route('/register', methods=['POST'])
def register():
    # Obtenemos los datos del usuario
    print(request.json)
    user = User(0, request.json['username'], request.json['password'],
                request.json['email'], request.json['fullname'])
    if ModelUser.register(db, user):
        return jsonify({"success": "Usuario registrado correctamente"})
    else:
        return jsonify({"error": "El usuario ya existe"})

# Ruta logout


@app.route('/logout', methods=['POST'])
def logout():
    # Obtenemos los datos del usuario
    print(request.json)
    user = User(request.json['id'], None, None,
                None, None, None, request.json['auth_token'])
    return ModelUser.logout(db, user)


# Ruta de error
@app.route('/error')
def error(message):
    return jsonify({"error": "Error en la petición", "message": message})

# Ruta para obtener los datos del usuario, sesión activa requerida


@app.route('/user', methods=['GET'])
def get_user():
    # Obtenemos el token del header
    token = request.headers.get('token')
    u = User(None, None, None, None, None, None, {'token': token})

    if token is not None:
        user = ModelUser.get_user_by_id(
            db, u)
        if user is not None:
            return jsonify(user.__dict__)
        else:
            return error("No se ha encontrado una sesión activa")
    else:
        return error("El token no ha sido enviado")

# Ruta para guardar una categoría, sesión activa requerida y rol admin


@app.route('/category/save', methods=['POST'])
def saveCategory():
    # Obtenemos el token del header
    token = request.headers.get('token')

    if token is not None:
        user = ModelUser.get_user_by_id(
            db, User(None, None, None, None, None, None, {'token': token}))
        if user is not None:
            category = Category(
                0, request.json['name'], request.json['description'])
            intent = ModelCategory.save(db, category, user)
            if intent == 200:
                return jsonify({"success": "Categoría guardada correctamente"})
            elif (intent == 409):
                return jsonify({"error": "La categoría ya existe"})
            elif (intent == 401):
                return jsonify({"error": "No tienes permisos para realizar esta acción"})
        else:
            return error("No se ha encontrado una sesión activa")
    else:
        return error("El token no ha sido enviado")

# Ruta para actualizar una categoría, sesión activa requerida y rol admin


@app.route('/category/update', methods=['POST'])
def updateCategory():
    # Obtenemos el token del header
    token = request.headers.get('token')

    if token is not None:
        user = ModelUser.get_user_by_id(
            db, User(None, None, None, None, None, None, {'token': token}))
        if user is not None:
            category = Category(
                request.json['id'], request.json['name'], request.json['description'])
            intent = ModelCategory.update(db, category, user)
            if intent == 200:
                return jsonify({"success": "Categoría actualizada correctamente"})
            elif (intent == 409):
                return jsonify({"error": "La categoría ya existe"})
            elif (intent == 401):
                return jsonify({"error": "No tienes permisos para realizar esta acción"})
        else:
            return error("No se ha encontrado una sesión activa")
    else:
        return error("El token no ha sido enviado")


# Ruta para eliminar una categoría, sesión activa requerida y rol admin


@app.route('/category/delete', methods=['POST'])
def deleteCategory():
    # Obtenemos el token del header
    token = request.headers.get('token')

    if token is not None:
        user = ModelUser.get_user_by_id(
            db, User(None, None, None, None, None, None, {'token': token}))
        if user is not None:
            category = Category(request.json['id'])
            intent = ModelCategory.delete(db, category, user)
            if intent == 200:
                return jsonify({"success": "Categoría eliminada correctamente"})
            elif (intent == 401):
                return jsonify({"error": "No tienes permisos para realizar esta acción"})
        else:
            return error("No se ha encontrado una sesión activa")
    else:
        return error("El token no ha sido enviado")

# Ruta para obtener todas las categorías


@app.route('/category', methods=['GET'])
def getCategories():
    categories = ModelCategory.get_all(db)
    return jsonify(categories)

# Ruta para obtener una categoría by id


@app.route('/category/<id>', methods=['GET'])
def getCategory(id):
    category = ModelCategory.get_by_id(db, id)
    return jsonify(category)

# Ruta para obtener todas las categorías by name


@app.route('/category/name/<name>', methods=['GET'])
def getCategoriesByName(name):
    categories = ModelCategory.get_by_name(db, name)
    return jsonify(categories)


# Path: src\models\ModelProduct.py
# Abstract model
# Name: ModelProduct
# Description: Product model
# Class methods: save, delete, update, get_all, get_by_id, get_by_name, get_by_category, get_by_pagination, get_by_search, get_by_search_and_category, decrease_stock

@app.route('/product/save', methods=['POST'])
def saveProduct():
    # Obtenemos el token del header
    token = request.headers.get('token')

    if token is not None:
        user = ModelUser.get_user_by_id(
            db, User(None, None, None, None, None, None, {'token': token}))
        if user is not None:
            product = Product(
                0, request.json['name'], request.json['description'], request.json['price'], request.json['stock'], request.json['category_id'])
            intent = ModelProduct.save(db, product, user)
            if intent == 200:
                return jsonify({"success": "Producto guardado correctamente"})
            elif (intent == 409):
                return jsonify({"error": "El producto ya existe"})
            elif (intent == 401):
                return jsonify({"error": "No tienes permisos para realizar esta acción"})
        else:
            return error("No se ha encontrado una sesión activa")
    else:
        return error("El token no ha sido enviado")


@app.route('/product/update', methods=['POST'])
def updateProduct():
    # Obtenemos el token del header
    token = request.headers.get('token')

    if token is not None:
        user = ModelUser.get_user_by_id(
            db, User(None, None, None, None, None, None, {'token': token}))
        if user is not None:
            product = Product(
                request.json['id'], request.json['name'], request.json['description'], request.json['price'], request.json['stock'], request.json['category_id'])
            intent = ModelProduct.update(db, product, user)
            if intent == 200:
                return jsonify({"success": "Producto actualizado correctamente"})
            elif (intent == 409):
                return jsonify({"error": "El producto ya existe"})
            elif (intent == 401):
                return jsonify({"error": "No tienes permisos para realizar esta acción"})
        else:
            return error("No se ha encontrado una sesión activa")
    else:
        return error("El token no ha sido enviado")


@app.route('/product/delete', methods=['POST'])
def deleteProduct():
    # Obtenemos el token del header
    token = request.headers.get('token')

    if token is not None:
        user = ModelUser.get_user_by_id(
            db, User(None, None, None, None, None, None, {'token': token}))
        if user is not None:
            product = Product(request.json['id'])
            intent = ModelProduct.delete(db, product, user)
            if intent == 200:
                return jsonify({"success": "Producto eliminado correctamente"})
            elif (intent == 401):
                return jsonify({"error": "No tienes permisos para realizar esta acción"})
        else:
            return error("No se ha encontrado una sesión activa")
    else:
        return error("El token no ha sido enviado")


@app.route('/product', methods=['GET'])
def getProducts():
    products = ModelProduct.get_all(db)
    return jsonify(products)


@app.route('/product/<id>', methods=['GET'])
def getProduct(id):
    product = ModelProduct.get_by_id(db, id)
    return jsonify(product)


@app.route('/product/name/<name>', methods=['GET'])
def getProductsByName(name):
    products = ModelProduct.get_by_name(db, name)
    return jsonify(products)


@app.route('/product/category/<id>', methods=['GET'])
def getProductsByCategory(id):
    products = ModelProduct.get_by_category(db, id)
    return jsonify(products)


@app.route('/product/pagination/<page>', methods=['GET'])
def getProductsByPagination(page):
    products = ModelProduct.get_by_pagination(db, page, 9)
    return jsonify(products)


@app.route('/product/search/<search>', methods=['GET'])
def getProductsBySearch(search):
    products = ModelProduct.get_by_search(db, search)
    return jsonify(products)


@app.route('/product/search/category/<search>/<id>', methods=['GET'])
def getProductsBySearchAndCategory(search, id):
    products = ModelProduct.get_by_search_and_category(db, search, id)
    return jsonify(products)


@app.route('/product/decrease', methods=['POST'])
def decreaseStock():
    # Obtenemos el token del header
    token = request.headers.get('token')

    if token is not None:
        user = ModelUser.get_user_by_id(
            db, User(None, None, None, None, None, None, {'token': token}))
        if user is not None:
            product = Product(
                request.json['id'], None, None, None, request.json['stock'], None)
            intent = ModelProduct.decrease_stock(db, product, user)
            if intent == 200:
                return jsonify({"success": "Stock actualizado correctamente"})
            elif (intent == 401):
                return jsonify({"error": "No tienes permisos para realizar esta acción"})
        else:
            return error("No se ha encontrado una sesión activa")
    else:
        return error("El token no ha sido enviado")


# add_product_to_order(self, db, user: User, product: Product, quantity: int):
@app.route('/order/add', methods=['POST'])
def addProductToOrder():
    # Obtenemos el token del header
    token = request.headers.get('token')

    if token is not None:
        user = ModelUser.get_user_by_id(
            db, User(None, None, None, None, None, None, {'token': token}))
        if user is not None:
            product = ModelProduct.get_by_id(db, request.json['product_id'])
            if product is None:
                return error("El producto no existe")
            intent = ModelOrder.add_product_to_order(
                db, user, product, request.json['quantity'])
            if intent == 200:
                return jsonify({"success": "Orden actualizada correctamente"})
            elif (intent == 401):
                return jsonify({"error": "No tienes permisos para realizar esta acción"})
            else:
                return error("Error en la petición")
        else:
            return error("No se ha encontrado una sesión activa")
    else:
        return error("El token no ha sido enviado")


@app.route('/order', methods=['GET'])
def getOrders():
    # Obtenemos el token del header
    token = request.headers.get('token')

    if token is not None:
        user = ModelUser.get_user_by_id(
            db, User(None, None, None, None, None, None, {'token': token}))
        if user is not None:
            orders = ModelOrder.get_all(db, user)
            return jsonify(orders)
        else:
            return error("No se ha encontrado una sesión activa")
    else:
        return error("El token no ha sido enviado")


# Inicio del programa
if __name__ == '__main__':
    app.run()
