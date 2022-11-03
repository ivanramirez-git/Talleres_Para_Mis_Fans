
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

from modelo.team import Team # Importar la clase Team
from modelo.user import User # Importar la clase User


# Abstract class
# Name: Team
# Description: Team entity
# Attributes: id, name
# Methods: __init__, __str__, save, update, delete, get_all, get_by_id, get_by_name, get_count

class TeamController:

    # Save, only admins can do this
    @classmethod
    def save(self, db, team: Team, user: User):
        if user.is_admin(db):
            if team.save(db):
                return 200
            else:
                return 409
        else:
            return 401

    # Update, only admins can do this
    @classmethod
    def update(self, db, team: Team, user: User):
        if user.is_admin(db):
            if team.update(db):
                return 200
            else:
                return 409
        else:
            return 401

    # Delete, only admins can do this
    @classmethod
    def delete(self, db, team: Team, user: User):
        if user.is_admin(db):
            if team.delete(db):
                return 200
            else:
                return 409
        else:
            return 401

    # Get all teams
    @classmethod
    def get_all(self, db):
        try:
            return Team.get_all(db)
        except Exception as ex:
            raise Exception(ex)

    # Get team by id
    @classmethod
    def get_by_id(self, db, id: int):
        try:
            return Team.get_by_id(db, id)
        except Exception as ex:
            raise Exception(ex)

    # Get team by name
    @classmethod
    def get_by_name(self, db, name: str):
        try:
            return Team.get_by_name(db, name)
        except Exception as ex:
            raise Exception(ex)

    # Get count of teams
    @classmethod
    def get_count(self, db):
        try:
            return Team.get_count(db)
        except Exception as ex:
            raise Exception(ex)


# Abstract class
# Name: TeamController
# Description: Team controller
# Attributes: None
# Methods:
"""
+ save(self, db, team, user)
+ update(self, db, team, user)
+ delete(self, db, team, user)
+ get_all(self, db)
+ get_by_id(self, db, id)
+ get_by_name(self, db, name)
+ get_count(self, db)
"""



