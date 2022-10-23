# Packages
from flask import Flask, jsonify, request  # Paquetes para la crear la API
from flask_mysqldb import MySQL  # Paquete para la conexión con MySQL
from config import config  # Paquete para la configuración de la conexión con MySQL

# Entities
from models.entities.User import User # Importar la entidad User
from models.entities.Category import Category # Importar la entidad Category
from models.entities.Product import Product # Importar la entidad Product
from models.entities.Order import Order # Importar la entidad Order

# Models
from models.ModelUser import ModelUser # Importar el modelo de usuario
from models.ModelCategory import ModelCategory # Importar el modelo de categoría
from models.ModelProduct import ModelProduct # Importar el modelo de producto
from models.ModelOrder import ModelOrder # Importar el modelo de orden

app = Flask(__name__)  # Instancia de Flask
app.config.from_object(config['development']) # Agregamos la configuración de la conexión con MySQL a la instancia de Flask
db = MySQL(app)  # Instancia de MySQL

# Rutas para peticiones REST
# Ruta login
@app.route('/login', methods=['POST']) # Ruta para el login se le indica que solo acepta peticiones POST
def login(): # Función para el login
    # Obtenemos los datos del usuario
    user = User(None, request.json['username'], request.json['password'], None, None, None) # Se crea un objeto de tipo User con los datos del usuario
    logger_user = ModelUser.login(db, user) # Se llama al método login de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
    if logger_user is not None: # Si el usuario existe
        return jsonify(logger_user.__dict__) # Devolver el objeto de tipo User en formato JSON
    else: # Si el usuario no existe
        return jsonify({"error": "Usuario o contraseña incorrectos"}) # Devolver un mensaje de error

# Ruta registro
@app.route('/register', methods=['POST']) # Ruta para el registro se le indica que solo acepta peticiones POST
def register(): # Función para el registro
    # Obtenemos los datos del usuario
    user = User(0, request.json['username'], request.json['password'], request.json['email'], request.json['fullname']) # Se crea un objeto de tipo User con los datos del usuario
    if ModelUser.register(db, user): # Se llama al método register de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        return jsonify({"success": "Usuario registrado correctamente"}) # Devolver un mensaje de éxito
    else: # Si el usuario no se ha podido registrar
        return jsonify({"error": "El usuario ya existe"}) # Devolver un mensaje de error

# Ruta logout
@app.route('/logout', methods=['POST']) # Ruta para el logout se le indica que solo acepta peticiones POST
def logout(): # Función para el logout
    # Obtenemos los datos del usuario
    user = User(request.json['id'], None, None, None, None, None, request.json['auth_token']) # Se crea un objeto de tipo User con los datos del usuario
    return ModelUser.logout(db, user) # Se llama al método logout de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL


# Ruta de error
@app.route('/error')
def error(message):
    return jsonify({"error": "Error en la petición", "message": message})

# Ruta para obtener los datos del usuario, sesión activa requerida
@app.route('/user', methods=['GET']) # Ruta para obtener los datos del usuario se le indica que solo acepta peticiones GET
def get_user(): # Función para obtener los datos del usuario
    # Obtenemos el token del header
    token = request.headers.get('token') # Se obtiene el token del header
    user = User(None, None, None, None, None, None, {'token': token}) # Se crea un objeto de tipo User con el token
    if token is not None: # Si el token no es nulo
        user = ModelUser.get_user_by_id(db, user) # Se llama al método get_user_by_id de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        if user is not None: # Si el usuario existe
            return jsonify(user.__dict__) # Devolver el objeto de tipo User en formato JSON
        else: # Si el usuario no existe
            return error("No se ha encontrado una sesión activa") # Devolver un mensaje de error
    else: # Si el token es nulo
        return error("El token no ha sido enviado") # Devolver un mensaje de error

# Ruta para guardar una categoría, sesión activa requerida y rol admin
@app.route('/category/save', methods=['POST']) # Ruta para guardar una categoría se le indica que solo acepta peticiones POST
def saveCategory(): # Función para guardar una categoría
    # Obtenemos el token del header
    token = request.headers.get('token') # Se obtiene el token del header

    if token is not None: # Si el token no es nulo
        user = ModelUser.get_user_by_id(db, User(None, None, None, None, None, None, {'token': token})) # Se llama al método get_user_by_id de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        if user is not None: # Si el usuario existe
            category = Category(0, request.json['name'], request.json['description']) # Se crea un objeto de tipo Category con los datos de la categoría
            intent = ModelCategory.save(db, category, user) # Se llama al método save de la clase ModelCategory y se le pasa el objeto de tipo Category, el objeto de tipo User y la instancia de MySQL
            if intent == 200: # Si la categoría se ha guardado correctamente
                return jsonify({"success": "Categoría guardada correctamente"}) # Devolver un mensaje de éxito
            elif (intent == 409): # Si la categoría ya existe
                return jsonify({"error": "La categoría ya existe"}) # Devolver un mensaje de error
            elif (intent == 401): # Si el usuario no tiene permisos
                return jsonify({"error": "No tienes permisos para realizar esta acción"}) # Devolver un mensaje de error
        else: # Si el usuario no existe
            return error("No se ha encontrado una sesión activa") # Devolver un mensaje de error
    else: # Si el token es nulo
        return error("El token no ha sido enviado") # Devolver un mensaje de error

# Ruta para actualizar una categoría, sesión activa requerida y rol admin
@app.route('/category/update', methods=['POST']) # Ruta para actualizar una categoría se le indica que solo acepta peticiones POST
def updateCategory(): # Función para actualizar una categoría
    # Obtenemos el token del header
    token = request.headers.get('token') # Se obtiene el token del header

    if token is not None: # Si el token no es nulo
        user = ModelUser.get_user_by_id(db, User(None, None, None, None, None, None, {'token': token})) # Se llama al método get_user_by_id de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        if user is not None: # Si el usuario existe
            category = Category(request.json['id'], request.json['name'], request.json['description']) # Se crea un objeto de tipo Category con los datos de la categoría
            intent = ModelCategory.update(db, category, user) # Se llama al método update de la clase ModelCategory y se le pasa el objeto de tipo Category, el objeto de tipo User y la instancia de MySQL
            if intent == 200: # Si la categoría se ha actualizado correctamente
                return jsonify({"success": "Categoría actualizada correctamente"}) # Devolver un mensaje de éxito
            elif (intent == 409): # Si la categoría ya existe
                return jsonify({"error": "La categoría ya existe"}) # Devolver un mensaje de error
            elif (intent == 401): # Si el usuario no tiene permisos
                return jsonify({"error": "No tienes permisos para realizar esta acción"}) # Devolver un mensaje de error
        else: # Si el usuario no existe
            return error("No se ha encontrado una sesión activa") # Devolver un mensaje de error
    else: # Si el token es nulo
        return error("El token no ha sido enviado") # Devolver un mensaje de error


# Ruta para eliminar una categoría, sesión activa requerida y rol admin
@app.route('/category/delete', methods=['POST']) # Ruta para eliminar una categoría se le indica que solo acepta peticiones POST
def deleteCategory(): # Función para eliminar una categoría
    # Obtenemos el token del header
    token = request.headers.get('token') # Se obtiene el token del header
    if token is not None: # Si el token no es nulo
        user = ModelUser.get_user_by_id(db, User(None, None, None, None, None, None, {'token': token})) # Se llama al método get_user_by_id de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        if user is not None: # Si el usuario existe
            category = Category(request.json['id']) # Se crea un objeto de tipo Category con el id de la categoría
            intent = ModelCategory.delete(db, category, user) # Se llama al método delete de la clase ModelCategory y se le pasa el objeto de tipo Category, el objeto de tipo User y la instancia de MySQL
            if intent == 200: # Si la categoría se ha eliminado correctamente
                return jsonify({"success": "Categoría eliminada correctamente"}) # Devolver un mensaje de éxito
            elif (intent == 401): # Si el usuario no tiene permisos
                return jsonify({"error": "No tienes permisos para realizar esta acción"}) # Devolver un mensaje de error
        else: # Si el usuario no existe
            return error("No se ha encontrado una sesión activa") # Devolver un mensaje de error
    else: # Si el token es nulo
        return error("El token no ha sido enviado") # Devolver un mensaje de error

# Ruta para obtener todas las categorías
@app.route('/category', methods=['GET']) # Ruta para obtener todas las categorías se le indica que solo acepta peticiones GET
def getCategories(): # Función para obtener todas las categorías
    categories = ModelCategory.get_all(db) # Se llama al método get_all de la clase ModelCategory y se le pasa la instancia de MySQL
    return jsonify(categories) # Devolver un json con todas las categorías

# Ruta para obtener una categoría by id
@app.route('/category/<id>', methods=['GET']) # Ruta para obtener una categoría by id se le indica que solo acepta peticiones GET
def getCategory(id): # Función para obtener una categoría by id
    category = ModelCategory.get_by_id(db, id) # Se llama al método get_by_id de la clase ModelCategory y se le pasa la instancia de MySQL y el id de la categoría
    return jsonify(category) # Devolver un json con la categoría

# Ruta para obtener todas las categorías by name
@app.route('/category/name/<name>', methods=['GET']) # Ruta para obtener todas las categorías by name se le indica que solo acepta peticiones GET
def getCategoriesByName(name): # Función para obtener todas las categorías by name
    categories = ModelCategory.get_by_name(db, name) # Se llama al método get_by_name de la clase ModelCategory y se le pasa la instancia de MySQL y el nombre de la categoría
    return jsonify(categories) # Devolver un json con todas las categorías

# Ruta para guardar un producto, sesión activa requerida y rol admin
@app.route('/product/save', methods=['POST']) # Ruta para guardar un producto se le indica que solo acepta peticiones POST
def saveProduct(): # Función para guardar un producto
    # Obtenemos el token del header
    token = request.headers.get('token') # Se obtiene el token del header

    if token is not None: # Si el token no es nulo
        user = ModelUser.get_user_by_id(db, User(None, None, None, None, None, None, {'token': token})) # Se llama al método get_user_by_id de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        if user is not None: # Si el usuario existe
            product = Product(0, request.json['name'], request.json['description'], request.json['price'], request.json['stock'], request.json['category_id']) # Se crea un objeto de tipo Product con los datos del producto
            intent = ModelProduct.save(db, product, user) # Se llama al método save de la clase ModelProduct y se le pasa el objeto de tipo Product, el objeto de tipo User y la instancia de MySQL
            if intent == 200: # Si el producto se ha guardado correctamente
                return jsonify({"success": "Producto guardado correctamente"}) # Devolver un mensaje de éxito
            elif (intent == 409): # Si el producto ya existe
                return jsonify({"error": "El producto ya existe"}) # Devolver un mensaje de error
            elif (intent == 401): # Si el usuario no tiene permisos
                return jsonify({"error": "No tienes permisos para realizar esta acción"}) # Devolver un mensaje de error
        else: # Si el usuario no existe
            return error("No se ha encontrado una sesión activa") # Devolver un mensaje de error
    else: # Si el token es nulo
        return error("El token no ha sido enviado") # Devolver un mensaje de error

# Actualizar un producto, sesión activa requerida y rol admin
@app.route('/product/update', methods=['POST']) # Ruta para actualizar un producto se le indica que solo acepta peticiones POST
def updateProduct(): # Función para actualizar un producto
    # Obtenemos el token del header
    token = request.headers.get('token') # Se obtiene el token del header
    if token is not None: # Si el token no es nulo
        user = ModelUser.get_user_by_id(db, User(None, None, None, None, None, None, {'token': token})) # Se llama al método get_user_by_id de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        if user is not None: # Si el usuario existe
            product = Product(request.json['id'], request.json['name'], request.json['description'], request.json['price'], request.json['stock'], request.json['category_id']) # Se crea un objeto de tipo Product con los datos del producto
            intent = ModelProduct.update(db, product, user) # Se llama al método update de la clase ModelProduct y se le pasa el objeto de tipo Product, el objeto de tipo User y la instancia de MySQL
            if intent == 200: # Si el producto se ha actualizado correctamente 
                return jsonify({"success": "Producto actualizado correctamente"}) # Devolver un mensaje de éxito
            elif (intent == 409): # Si el producto ya existe
                return jsonify({"error": "El producto ya existe"}) # Devolver un mensaje de error
            elif (intent == 401):  # Si el usuario no tiene permisos
                return jsonify({"error": "No tienes permisos para realizar esta acción"}) # Devolver un mensaje de error
        else: # Si el usuario no existe
            return error("No se ha encontrado una sesión activa") # Devolver un mensaje de error
    else: # Si el token es nulo
        return error("El token no ha sido enviado") # Devolver un mensaje de error


@app.route('/product/delete', methods=['DELETE']) # Ruta para eliminar un producto se le indica que solo acepta peticiones DELETE
def deleteProduct(): # Función para eliminar un producto
    # Obtenemos el token del header
    token = request.headers.get('token') # Se obtiene el token del header
    if token is not None: # Si el token no es nulo
        user = ModelUser.get_user_by_id(db, User(None, None, None, None, None, None, {'token': token})) # Se llama al método get_user_by_id de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        if user is not None: # Si el usuario existe
            product = Product(request.json['product_id']) # Se crea un objeto de tipo Product con el id del producto
            intent = ModelProduct.delete(db, product, user) # Se llama al método delete de la clase ModelProduct y se le pasa el objeto de tipo Product, el objeto de tipo User y la instancia de MySQL
            if intent == 200: # Si el producto se ha eliminado correctamente
                return jsonify({"success": "Producto eliminado correctamente"}) # Devolver un mensaje de éxito
            elif (intent == 401): # Si el usuario no tiene permisos
                return jsonify({"error": "No tienes permisos para realizar esta acción"}) # Devolver un mensaje de error
        else: # Si el usuario no existe
            return error("No se ha encontrado una sesión activa") # Devolver un mensaje de error
    else: # Si el token es nulo
        return error("El token no ha sido enviado") # Devolver un mensaje de error


@app.route('/product', methods=['GET']) # Ruta para obtener un producto se le indica que solo acepta peticiones GET
def getProducts(): # Función para obtener un producto
    products = ModelProduct.get_all(db) # Se llama al método get_all de la clase ModelProduct y se le pasa la instancia de MySQL
    return jsonify(products) # Devolver los productos en formato JSON


@app.route('/product/<id>', methods=['GET']) # Ruta para obtener un producto se le indica que solo acepta peticiones GET
def getProduct(id): # Función para obtener un producto
    product = ModelProduct.get_by_id(db, id) # Se llama al método get_by_id de la clase ModelProduct y se le pasa la instancia de MySQL y el id del producto
    return jsonify(product) # Devolver el producto en formato JSON


@app.route('/product/name/<name>', methods=['GET']) # Ruta para obtener un producto se le indica que solo acepta peticiones GET
def getProductsByName(name): # Función para obtener un producto
    products = ModelProduct.get_by_name(db, name) # Se llama al método get_by_name de la clase ModelProduct y se le pasa la instancia de MySQL y el nombre del producto
    return jsonify(products) # Devolver los productos en formato JSON


@app.route('/product/category/<id>', methods=['GET']) # Ruta para obtener un producto se le indica que solo acepta peticiones GET
def getProductsByCategory(id): # Función para obtener un producto
    products = ModelProduct.get_by_category(db, id) # Se llama al método get_by_category de la clase ModelProduct y se le pasa la instancia de MySQL y el id de la categoría
    return jsonify(products) # Devolver los productos en formato JSON


@app.route('/product/pagination/<page>', methods=['GET']) # Ruta para obtener un producto se le indica que solo acepta peticiones GET
def getProductsByPagination(page): # Función para obtener un producto
    products = ModelProduct.get_by_pagination(db, page, 9) # Se llama al método get_by_pagination de la clase ModelProduct y se le pasa la instancia de MySQL, el número de página y el número de productos por página
    return jsonify(products) # Devolver los productos en formato JSON


@app.route('/product/search/<search>', methods=['GET']) # Ruta para obtener un producto se le indica que solo acepta peticiones GET
def getProductsBySearch(search): # Función para obtener un producto
    products = ModelProduct.get_by_search(db, search) # Se llama al método get_by_search de la clase ModelProduct y se le pasa la instancia de MySQL y la cadena de búsqueda
    return jsonify(products) # Devolver los productos en formato JSON


@app.route('/product/search/category/<search>/<id>', methods=['GET']) # Ruta para obtener un producto se le indica que solo acepta peticiones GET
def getProductsBySearchAndCategory(search, id): # Función para obtener un producto
    products = ModelProduct.get_by_search_and_category(db, search, id) # Se llama al método get_by_search_and_category de la clase ModelProduct y se le pasa la instancia de MySQL, la cadena de búsqueda y el id de la categoría
    return jsonify(products) # Devolver los productos en formato JSON


@app.route('/product/decrease', methods=['POST']) # Ruta para disminuir el stock de un producto se le indica que solo acepta peticiones POST
def decreaseStock(): # Función para disminuir el stock de un producto
    # Obtenemos el token del header
    token = request.headers.get('token') # Se obtiene el token del header

    if token is not None: # Si el token no es nulo
        user = ModelUser.get_user_by_id(db, User(None, None, None, None, None, None, {'token': token})) # Se llama al método get_user_by_id de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        if user is not None: # Si el usuario existe
            product = Product(request.json['product_id'], None, None, None, request.json['stock'], None) # Se crea un objeto de tipo Product con el id del producto y el stock a disminuir
            intent = ModelProduct.decrease_stock(db, product, user) # Se llama al método decrease_stock de la clase ModelProduct y se le pasa el objeto de tipo Product, el objeto de tipo User y la instancia de MySQL
            if intent == 200: # Si el stock se ha disminuido correctamente
                return jsonify({"success": "Stock actualizado correctamente"}) # Devolver un mensaje de éxito
            elif (intent == 401): # Si el usuario no tiene permisos
                return jsonify({"error": "No tienes permisos para realizar esta acción"}) # Devolver un mensaje de error
        else: # Si el usuario no existe
            return error("No se ha encontrado una sesión activa") # Devolver un mensaje de error
    else: # Si el token es nulo
        return error("El token no ha sido enviado") # Devolver un mensaje de error


# add_product_to_order(self, db, user: User, product: Product, quantity: int):
@app.route('/order/add', methods=['POST']) # Ruta para añadir un producto a un pedido se le indica que solo acepta peticiones POST
def addProductToOrder(): # Función para añadir un producto a un pedido
    # Obtenemos el token del header
    token = request.headers.get('token') # Se obtiene el token del header

    if token is not None: # Si el token no es nulo
        user = ModelUser.get_user_by_id(db, User(None, None, None, None, None, None, {'token': token})) # Se llama al método get_user_by_id de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        if user is not None: # Si el usuario existe
            product = ModelProduct.get_by_id(db, request.json['product_id']) # Se llama al método get_by_id de la clase ModelProduct y se le pasa la instancia de MySQL y el id del producto
            if product is None:  # Si el producto no existe
                return error("El producto no existe") # Devolver un mensaje de error
            intent = ModelOrder.add_product_to_order(db, user, product, request.json['quantity']) # Se llama al método add_product_to_order de la clase ModelOrder y se le pasa el objeto de tipo User, el objeto de tipo Product, la instancia de MySQL y la cantidad
            if intent == 200: # Si el producto se ha añadido correctamente
                return jsonify({"success": "Orden actualizada correctamente"}) # Devolver un mensaje de éxito
            elif (intent == 401): # Si el usuario no tiene permisos
                return jsonify({"error": "No tienes permisos para realizar esta acción"}) # Devolver un mensaje de error
            else: # Si el producto no se ha añadido correctamente
                return error("Error en la petición")    # Devolver un mensaje de error
        else:  # Si el usuario no existe
            return error("No se ha encontrado una sesión activa") # Devolver un mensaje de error
    else: # Si el token es nulo
        return error("El token no ha sido enviado") # Devolver un mensaje de error


@app.route('/order', methods=['GET']) # Ruta para obtener un pedido se le indica que solo acepta peticiones GET
def getOrders(): # Función para obtener un pedido
    # Obtenemos el token del header
    token = request.headers.get('token') # Se obtiene el token del header

    if token is not None: # Si el token no es nulo
        user = ModelUser.get_user_by_id(db, User(None, None, None, None, None, None, {'token': token})) # Se llama al método get_user_by_id de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        if user is not None: # Si el usuario existe
            orders = ModelOrder.get_all(db, user) # Se llama al método get_all de la clase ModelOrder y se le pasa el objeto de tipo User y la instancia de MySQL
            return jsonify(orders) # Devolver los pedidos en formato JSON
        else: # Si el usuario no existe
            return error("No se ha encontrado una sesión activa") # Devolver un mensaje de error
    else: # Si el token es nulo
        return error("El token no ha sido enviado") # Devolver un mensaje de error

# close_order(self, db, user: User):


@app.route('/order/close', methods=['GET']) # Ruta para cerrar un pedido se le indica que solo acepta peticiones GET
def closeOrder():  # Función para cerrar un pedido
    # Obtenemos el token del header
    token = request.headers.get('token') # Se obtiene el token del header

    if token is not None: # Si el token no es nulo
        user = ModelUser.get_user_by_id(db, User(None, None, None, None, None, None, {'token': token})) # Se llama al método get_user_by_id de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        if user is not None: # Si el usuario existe
            intent = ModelOrder.close_order(db, user) # Se llama al método close_order de la clase ModelOrder y se le pasa el objeto de tipo User y la instancia de MySQL
            if intent == 200: # Si el pedido se ha cerrado correctamente
                return jsonify({"success": "Orden cerrada correctamente"}) # Devolver un mensaje de éxito
            elif (intent == 401): # Si el usuario no tiene permisos
                return jsonify({"error": "No tienes permisos para realizar esta acción"}) # Devolver un mensaje de error
            else: # Si el pedido no se ha cerrado correctamente
                return error("Error en la petición") # Devolver un mensaje de error
        else: # Si el usuario no existe
            return error("No se ha encontrado una sesión activa") # Devolver un mensaje de error
    else: # Si el token es nulo
        return error("El token no ha sido enviado") # Devolver un mensaje de error


# Inicio del programa
if __name__ == '__main__': # Si el programa se ejecuta directamente
    app.run() # Se ejecuta la aplicación
