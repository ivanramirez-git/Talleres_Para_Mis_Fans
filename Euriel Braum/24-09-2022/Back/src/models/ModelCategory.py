
# -- TABLA categories: id, name, description
# CREATE TABLE IF NOT EXISTS `categories` (
#   `id` int(11) NOT NULL AUTO_INCREMENT,
#   `name` varchar(50) NOT NULL,
#   `description` varchar(255) NOT NULL,
#   PRIMARY KEY (`id`)
# ) ENGINE = InnoDB DEFAULT CHARSET = utf8;

# Abstract class
# Name: Category
# Description: Category entity
# Attributes: id, name, description
# Methods: __init__, __str__, save, update, delete, get_all, get_by_id, get_by_name

from .entities.Category import Category # Importa la clase Category del módulo entities
from .entities.User import User # Importa la clase User del módulo entities


class ModelCategory: # Clase ModelCategory

    # Save, only admins can do this
    @classmethod # Metodo estatico
    def save(self, db, category: Category, user: User): # Método para guardar una categoria
        if user.is_admin(db): # Si el usuario es administrador
            if category.save(db): # Si la categoria se guarda
                return 200 # Retorna 200
            else: # Si no
                return 409  # Retorna 409
        else: # Si no
            return 401  # Retorna 401

    # Update, only admins can do this
    @classmethod # Metodo estatico
    def update(self, db, category: Category, user: User): # Método para actualizar una categoria
        if user.is_admin(db): # Si el usuario es administrador
            if category.update(db): # Si la categoria se actualiza
                return 200 # Retorna 200
            else: # Si no
                return 409 # Retorna 409
        else: # Si no
            return 401 # Retorna 401

    # Delete, only admins can do this
    @classmethod # Metodo estatico
    def delete(self, db, category: Category, user: User): # Método para eliminar una categoria
        if user.is_admin(db): # Si el usuario es administrador
            if category.delete(db): # Si la categoria se elimina
                return 200 # Retorna 200
            else: # Si no
                return 409 # Retorna 409
        else: # Si no
            return 401 # Retorna 401

    # Get all categories
    @classmethod  # Metodo estatico
    def get_all(self, db): # Método para obtener todas las categorias
        try: # Intenta
            return Category.get_all(db) # Retorna todas las categorias
        except Exception as ex: # Si no
            raise Exception(ex) # Lanza una excepción

    # Get category by id
    @classmethod # Metodo estatico
    def get_by_id(self, db, id): # Método para obtener una categoria por id
        try: # Intenta
            return Category.get_by_id(db, id) # Retorna la categoria por id
        except Exception as ex: # Si no
            raise Exception(ex) # Lanza una excepción

    # Get category by name
    @classmethod # Metodo estatico
    def get_by_name(self, db, name): # Método para obtener una categoria por nombre
        try: # Intenta
            return Category.get_by_name(db, name)  # Retorna la categoria por nombre
        except Exception as ex: # Si no
            raise Exception(ex) # Lanza una excepción


# Abstract class
# Name: ModelCategory
# Description: Category model
# Attributes: None
# Methods:
"""
+ save(self, db, category, user)
+ update(self, db, category, user)
+ delete(self, db, category, user)
+ get_all(self, db)
+ get_by_id(self, db, id)
+ get_by_name(self, db, name)
"""
