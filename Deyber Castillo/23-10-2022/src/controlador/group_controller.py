

# Abstract class
# Name: Group
# Description: Class for the groups of the tournament
# Atributes: id, name, team_1, team_2, team_3, team_4
# Methods: __init__, __str__, __repr__, save, update, delete, get, get_all, get_teams_by_name, get_teams_by_id, get_count, get_teams_without_group

from modelo.group import Group
from modelo.user import User

class GroupController:

    # Save, only admins can do this
    @classmethod
    def save(self, db, group: Group, user: User):
        if user.is_admin(db):
            if group.save(db):
                return 200
            else:
                return 409
        else:
            return 401

    # Update, only admins can do this
    @classmethod
    def update(self, db, group: Group, user: User):
        if user.is_admin(db):
            if group.update(db):
                return 200
            else:
                return 409
        else:
            return 401

    # Delete, only admins can do this
    @classmethod
    def delete(self, db, group: Group, user: User):
        if user.is_admin(db):
            print('Group: ', group)
            if group.delete(db):
                return 200
            else:
                return 409
        else:
            return 401

    # Get group by id
    @classmethod
    def get(self, db, id: int):
        try:
            return Group.get(db, id)
        except Exception as ex:
            raise Exception(ex)

    # Get all groups
    @classmethod
    def get_all(self, db):
        try:
            return Group.get_all(db)
        except Exception as ex:
            raise Exception(ex)

    # Get teams by name
    @classmethod
    def get_teams_by_name(self, db, name: str):
        try:
            return Group.get_teams_by_name(db, name)
        except Exception as ex:
            raise Exception(ex)

    # Get teams by id
    @classmethod
    def get_teams_by_id(self, db, id: int):
        try:
            return Group.get_teams_by_id(db, id)
        except Exception as ex:
            raise Exception(ex)

    # Get count of groups
    @classmethod
    def get_count(self, db):
        try:
            return Group.get_count(db)
        except Exception as ex:
            raise Exception(ex)

    # Get teams without group
    @classmethod
    def get_teams_without_group(self, db):
        try:
            return Group.get_teams_without_group(db)
        except Exception as ex:
            raise Exception(ex)



# Abstract class
# Name: GroupController
# Description: Group controller
# Attributes: None
# Methods:
"""
+ save(self, db, group, user)
+ update(self, db, group, user)
+ delete(self, db, group, user)
+ get(self, db, id)
+ get_all(self, db)
+ get_teams_by_name(self, db, name)
+ get_teams_by_id(self, db, id)
+ get_count(self, db)
+ get_teams_without_group(self, db)
"""


