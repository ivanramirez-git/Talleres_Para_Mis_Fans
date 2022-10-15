
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
# Atributes: id, name, description
# Methods: __init__, __str__, save, update, delete, get_all, get_by_id, get_by_name

from .entities.Category import Category
from .entities.User import User


class ModelCategory:

    # Save, only admins can do this
    @classmethod
    def save(self, db, category: Category, user: User):
        if user.is_admin(db):
            return category.save(db)
        else:
            return False
