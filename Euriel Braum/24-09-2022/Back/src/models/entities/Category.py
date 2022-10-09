
# -- TABLA categories: id, name, description
# CREATE TABLE IF NOT EXISTS `categories` (
#   `id` int(11) NOT NULL AUTO_INCREMENT,
#   `name` varchar(50) NOT NULL,
#   `description` varchar(255) NOT NULL,
#   PRIMARY KEY (`id`)
# ) ENGINE = InnoDB DEFAULT CHARSET = utf8;

class Category:
    def __init__(self, id, name, description):
        self.id = id
        self.name = name
        self.description = description

    def __str__(self):
        return f'Category: {self.id}, {self.name}, {self.description}'

    def save(self, db):
        try:
            cursor = db.connection.cursor()
            sql = """INSERT INTO categories (name, description) VALUES ('{}', '{}')""".format(
                self.name, self.description)
            cursor.execute(sql)
            db.connection.commit()
            return True
        except Exception as ex:
            raise Exception(ex)

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
            return data
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get_by_id(cls, db, id):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM categories WHERE id = {}""".format(id)
            cursor.execute(sql)
            data = cursor.fetchone()
            return data
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get_by_name(cls, db, name):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM categories WHERE name = '{}'""".format(name)
            cursor.execute(sql)
            data = cursor.fetchone()
            return data
        except Exception as ex:
            raise Exception(ex)
