import {inject} from '@loopback/core';
import {DefaultCrudRepository} from '@loopback/repository';
import {MongoDataSource} from '../datasources';
import {Estudiantes, EstudiantesRelations} from '../models';

export class EstudiantesRepository extends DefaultCrudRepository<
  Estudiantes,
  typeof Estudiantes.prototype.id,
  EstudiantesRelations
> {
  constructor(
    @inject('datasources.mongo') dataSource: MongoDataSource,
  ) {
    super(Estudiantes, dataSource);
  }
}
