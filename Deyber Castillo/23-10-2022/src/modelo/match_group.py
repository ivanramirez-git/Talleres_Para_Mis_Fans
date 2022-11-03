

class MatchGroup:
    def __init__(self, id = 0, group_id = 0, team_1 = 0, team_2 = 0, score_1 = None, score_2 = None, date = None, status = ''):
        self.id = id
        self.group_id = group_id
        self.team_1 = team_1
        self.team_2 = team_2
        self.score_1 = score_1
        self.score_2 = score_2
        self.date = date
        self.status = status

    def __str__(self):
        return 'MatchGroup: [id: {}, group_id: {}, team_1: {}, team_2: {}, score_1: {}, score_2: {}, date: {}, status: {}]'.format(self.id, self.group_id, self.team_1, self.team_2, self.score_1, self.score_2, self.date, self.status)

    def __repr__(self):
        return self.__str__()

    def save(self, db):
        try:
            cursor = db.connection.cursor()
            sql = """INSERT INTO matches_group (group_id, team_1, team_2, score_1, score_2, date, status) VALUES ({}, {}, {}, {}, {}, '{}', '{}')""".format(self.group_id, self.team_1, self.team_2, self.score_1, self.score_2, self.date, self.status)
            cursor.execute(sql)
            db.connection.commit()
            self.id = cursor.lastrowid
            return self.id
        except Exception as ex:
            raise Exception(ex)

    def update(self, db):
        try:
            cursor = db.connection.cursor()
            sql = """UPDATE matches_group SET group_id = {}, team_1 = {}, team_2 = {}, score_1 = {}, score_2 = {}, date = '{}', status = '{}' WHERE id = {}""".format(self.group_id, self.team_1, self.team_2, self.score_1, self.score_2, self.date, self.status, self.id)
            cursor.execute(sql)
            db.connection.commit()
            return self.id
        except Exception as ex:
            raise Exception(ex)

    def delete(self, db):
        try:
            cursor = db.connection.cursor()
            sql = """DELETE FROM matches_group WHERE id = {}""".format(self.id)
            cursor.execute(sql)
            db.connection.commit()
            return self.id
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get(self, db, id):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM matches_group WHERE id = {}""".format(id)
            cursor.execute(sql)
            data = cursor.fetchone()
            if data:
                self.id = data[0]
                self.group_id = data[1]
                self.team_1 = data[2]
                self.team_2 = data[3]
                self.score_1 = data[4]
                self.score_2 = data[5]
                self.date = data[6]
                self.status = data[7]
            else:
                return None
            return self
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get_all(self, db):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM matches_group"""
            cursor.execute(sql)
            data = cursor.fetchall()
            return data
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get_by_group(self, db, group_id):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM matches_group WHERE group_id = {}""".format(group_id)
            cursor.execute(sql)
            data = cursor.fetchall()
            return data
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get_count(self, db):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT COUNT(*) FROM matches_group"""
            cursor.execute(sql)
            data = cursor.fetchone()
            return data[0]
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get_by_team(self, db, team_id):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM matches_group WHERE team_1 = {} OR team_2 = {}""".format(team_id, team_id)
            cursor.execute(sql)
            data = cursor.fetchall()
            return data
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get_by_id(self, db, id):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM matches_group WHERE id = {}""".format(id)
            cursor.execute(sql)
            data = cursor.fetchone()
            return data
        except Exception as ex:
            raise Exception(ex)


    

    # cur.execute("CREATE TABLE IF NOT EXISTS `groups` (`id` int(11) NOT NULL AUTO_INCREMENT,`name` varchar(50) NOT NULL,`team_1` int(11) NOT NULL,`team_2` int(11) NOT NULL,`team_3` int(11) NOT NULL,`team_4` int(11) NOT NULL,PRIMARY KEY (`id`),UNIQUE KEY `name` (`name`),KEY `team_1` (`team_1`),KEY `team_2` (`team_2`),KEY `team_3` (`team_3`),KEY `team_4` (`team_4`),CONSTRAINT `groups_ibfk_1` FOREIGN KEY (`team_1`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,CONSTRAINT `groups_ibfk_2` FOREIGN KEY (`team_2`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,CONSTRAINT `groups_ibfk_3` FOREIGN KEY (`team_3`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,CONSTRAINT `groups_ibfk_4` FOREIGN KEY (`team_4`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1;")
    # cur.execute("CREATE TABLE IF NOT EXISTS `matches_group` (`id` int(11) NOT NULL AUTO_INCREMENT,`group_id` int(11) NOT NULL,`team_1` int(11) NOT NULL,`team_2` int(11) NOT NULL,`score_1` int(11) DEFAULT NULL,`score_2` int(11) DEFAULT NULL,`date` datetime DEFAULT NULL,`status` varchar(50) NOT NULL,PRIMARY KEY (`id`),KEY `group_id` (`group_id`),KEY `team_1` (`team_1`),KEY `team_2` (`team_2`),CONSTRAINT `matches_group_ibfk_1` FOREIGN KEY (`group_id`) REFERENCES `groups` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,CONSTRAINT `matches_group_ibfk_2` FOREIGN KEY (`team_1`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,CONSTRAINT `matches_group_ibfk_3` FOREIGN KEY (`team_2`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1;")

    @classmethod
    def create_match_groups(self, db):
        # Crear todos los posibles partidos de un grupo por cada grupo
        try:
            # validar que existan 8 grupos y que cada grupo tenga 4 equipos
            cursor = db.connection.cursor()
            sql = """SELECT COUNT(*) FROM groups"""
            cursor.execute(sql)
            data = cursor.fetchone()
            if data[0] != 8:
                print("No se pueden crear los partidos de los grupos porque no existen 8 grupos")
                return False
                
            # Eliminar todos los datos de la tabla matches_group
            sql = """DELETE FROM matches_group"""
            cursor.execute(sql)
            db.connection.commit()
            # Crear los partidos
            sql = """SELECT * FROM groups"""
            cursor.execute(sql)
            data = cursor.fetchall()
            for group in data:
                # construir los partidos
                teams = [group[2], group[3], group[4], group[5]]
                # todas las combinaciones de 2 equipos
                for i in range(0, 4):
                    for j in range(i+1, 4):
                        sql = """INSERT INTO matches_group (group_id, team_1, team_2, status) VALUES ({}, {}, {}, '{}')""".format(group[0], teams[i], teams[j], 'Pendiente')
                        cursor.execute(sql)
                        print("Partido creado: {} vs {}".format(teams[i], teams[j]))
            db.connection.commit()
            print("Partidos de grupos creados")
            return True
        except Exception as ex:
            raise Exception(ex)


# Abstract class
# Name: MatchGroup
# Attributes: id, group_id, team_1, team_2, score_1, score_2, date, status
# Methods: save, update, delete, get, get_all, get_by_group, get_count, get_by_team, get_by_id