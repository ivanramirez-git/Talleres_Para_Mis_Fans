
# -- TABLA categories: id, name, description
# CREATE TABLE IF NOT EXISTS `categories` (
#   `id` int(11) NOT NULL AUTO_INCREMENT,
#   `name` varchar(50) NOT NULL,
#   `description` varchar(255) NOT NULL,
#   PRIMARY KEY (`id`)
# ) ENGINE = InnoDB DEFAULT CHARSET = utf8;

class Category:
    def __init__(self, id, name='', description=''):
        self.id = id
        self.name = name
        self.description = description

    def __str__(self):
        return f'Category: {self.id}, {self.name}, {self.description}'

    def save(self, db):
        # Consultamos si existe una categoría con el mismo nombre
        if self.get_by_name(db, self.name) is None:
            try:
                cursor = db.connection.cursor()
                sql = """INSERT INTO categories (name, description) VALUES ('{}', '{}')""".format(
                    self.name, self.description)
                cursor.execute(sql)
                db.connection.commit()
                return True
            except Exception as ex:
                raise Exception(ex)
        else:
            return False

    def update(self, db):
        try:
            cursor = db.connection.cursor()
            sql = """UPDATE categories SET name = '{}', description = '{}' WHERE id = {}""".format(
                self.name, self.description, self.id)
            cursor.execute(sql)
            db.connection.commit()
            return True
        except Exception as ex:
            raise Exception(ex)

    def delete(self, db):
        try:
            cursor = db.connection.cursor()
            sql = """DELETE FROM categories WHERE id = {}""".format(self.id)
            cursor.execute(sql)
            db.connection.commit()
            return True
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get_all(cls, db):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM categories"""
            cursor.execute(sql)
            data = cursor.fetchall()
            categories = []
            category_aux = {}
            for category in data:
                category_aux['id'] = category[0]
                category_aux['name'] = category[1]
                category_aux['description'] = category[2]
                categories.append(category_aux)
                category_aux = {}

            return categories
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get_by_id(cls, db, id):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM categories WHERE id = {}""".format(id)
            cursor.execute(sql)
            data = cursor.fetchone()
            category = {}
            if data is not None:
                category['id'] = data[0]
                category['name'] = data[1]
                category['description'] = data[2]
            else:
                category = None
            return category
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get_by_name(cls, db, name):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM categories WHERE name = '{}'""".format(name)
            cursor.execute(sql)
            data = cursor.fetchone()
            category = {}
            if data is not None:
                category['id'] = data[0]
                category['name'] = data[1]
                category['description'] = data[2]
            else:
                category = None
            return category
        except Exception as ex:
            raise Exception(ex)


# Abstract class
# Name: Category
# Description: Category entity
# Atributes: id, name, description
# Methods: __init__, __str__, save, update, delete, get_all, get_by_id, get_by_name
