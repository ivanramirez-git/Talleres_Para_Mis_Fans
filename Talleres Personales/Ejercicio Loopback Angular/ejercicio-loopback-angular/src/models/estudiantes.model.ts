import {Entity, model, property} from '@loopback/repository';

@model()
export class Estudiantes extends Entity {
  @property({
    type: 'string',
    id: true,
    generated: true,
  })
  id?: string;

  @property({
    type: 'string',
    required: true,
  })
  nombre: string;

  @property({
    type: 'number',
  })
  ingreso?: number;


  constructor(data?: Partial<Estudiantes>) {
    super(data);
  }
}

export interface EstudiantesRelations {
  // describe navigational properties here
}

export type EstudiantesWithRelations = Estudiantes & EstudiantesRelations;
