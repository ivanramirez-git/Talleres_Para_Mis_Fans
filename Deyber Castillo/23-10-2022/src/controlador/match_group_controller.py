


# Abstract class
# Name: MatchGroup
# Attributes: id, group_id, team_1, team_2, score_1, score_2, date, status
# Methods: save, update, delete, get, get_all, get_by_group, get_count, get_by_team, get_by_id

from modelo.match_group import MatchGroup
from modelo.user import User

class MatchGroupController:
    
        # Save, only admins can do this
        @classmethod
        def save(self, db, match_group: MatchGroup, user: User):
            if user.is_admin(db):
                if match_group.save(db):
                    return 200
                else:
                    return 409
            else:
                return 401
    
        # Update, only admins can do this
        @classmethod
        def update(self, db, match_group: MatchGroup, user: User):
            if user.is_admin(db):
                if match_group.update(db):
                    return 200
                else:
                    return 409
            else:
                return 401
    
        # Delete, only admins can do this
        @classmethod
        def delete(self, db, match_group: MatchGroup, user: User):
            if user.is_admin(db):
                if match_group.delete(db):
                    return 200
                else:
                    return 409
            else:
                return 401
    
        # Get match group by id
        @classmethod
        def get(self, db, id: int):
            try:
                return MatchGroup.get(db, id)
            except Exception as ex:
                raise Exception(ex)
    
        # Get all match groups
        @classmethod
        def get_all(self, db):
            try:
                return MatchGroup.get_all(db)
            except Exception as ex:
                raise Exception(ex)
    
        # Get match groups by group
        @classmethod
        def get_by_group(self, db, group_id: int):
            try:
                return MatchGroup.get_by_group(db, group_id)
            except Exception as ex:
                raise Exception(ex)
    
        # Get count of match groups
        @classmethod
        def get_count(self, db):
            try:
                return MatchGroup.get_count(db)
            except Exception as ex:
                raise Exception(ex)
    
        # Get match groups by team
        @classmethod
        def get_by_team(self, db, team_id: int):
            try:
                return MatchGroup.get_by_team(db, team_id)
            except Exception as ex:
                raise Exception(ex)
    
        # Get match group by id
        @classmethod
        def get_by_id(self, db, id: int):
            try:
                return MatchGroup.get_by_id(db, id)
            except Exception as ex:
                raise Exception(ex)

        @classmethod
        def create_match_groups(self,db):
            try:
                print("Creating match groups CONTROLER")
                return MatchGroup.create_match_groups(db)
            except Exception as ex:
                raise Exception(ex)



# Abstract class
# Name: MatchGroupController
# Description: Match group controller
# Attributes: None
# Methods:
"""
+ save(self, db, match_group, user)
+ update(self, db, match_group, user)
+ delete(self, db, match_group, user)
+ get(self, db, id)
+ get_all(self, db)
+ get_by_group(self, db, group_id)
+ get_count(self, db)
+ get_by_team(self, db, team_id)
+ get_by_id(self, db, id)
"""

