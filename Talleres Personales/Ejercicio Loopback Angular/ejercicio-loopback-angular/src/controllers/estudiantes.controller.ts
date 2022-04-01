import {
  Count,
  CountSchema,
  Filter,
  FilterExcludingWhere,
  repository,
  Where,
} from '@loopback/repository';
import {
  post,
  param,
  get,
  getModelSchemaRef,
  patch,
  put,
  del,
  requestBody,
  response,
} from '@loopback/rest';
import {Estudiantes} from '../models';
import {EstudiantesRepository} from '../repositories';

export class EstudiantesController {
  constructor(
    @repository(EstudiantesRepository)
    public estudiantesRepository : EstudiantesRepository,
  ) {}

  @post('/estudiantes')
  @response(200, {
    description: 'Estudiantes model instance',
    content: {'application/json': {schema: getModelSchemaRef(Estudiantes)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(Estudiantes, {
            title: 'NewEstudiantes',
            exclude: ['id'],
          }),
        },
      },
    })
    estudiantes: Omit<Estudiantes, 'id'>,
  ): Promise<Estudiantes> {
    return this.estudiantesRepository.create(estudiantes);
  }

  @get('/estudiantes/count')
  @response(200, {
    description: 'Estudiantes model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(Estudiantes) where?: Where<Estudiantes>,
  ): Promise<Count> {
    return this.estudiantesRepository.count(where);
  }

  @get('/estudiantes')
  @response(200, {
    description: 'Array of Estudiantes model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(Estudiantes, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(Estudiantes) filter?: Filter<Estudiantes>,
  ): Promise<Estudiantes[]> {
    return this.estudiantesRepository.find(filter);
  }

  @patch('/estudiantes')
  @response(200, {
    description: 'Estudiantes PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(Estudiantes, {partial: true}),
        },
      },
    })
    estudiantes: Estudiantes,
    @param.where(Estudiantes) where?: Where<Estudiantes>,
  ): Promise<Count> {
    return this.estudiantesRepository.updateAll(estudiantes, where);
  }

  @get('/estudiantes/{id}')
  @response(200, {
    description: 'Estudiantes model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(Estudiantes, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.string('id') id: string,
    @param.filter(Estudiantes, {exclude: 'where'}) filter?: FilterExcludingWhere<Estudiantes>
  ): Promise<Estudiantes> {
    return this.estudiantesRepository.findById(id, filter);
  }

  @patch('/estudiantes/{id}')
  @response(204, {
    description: 'Estudiantes PATCH success',
  })
  async updateById(
    @param.path.string('id') id: string,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(Estudiantes, {partial: true}),
        },
      },
    })
    estudiantes: Estudiantes,
  ): Promise<void> {
    await this.estudiantesRepository.updateById(id, estudiantes);
  }

  @put('/estudiantes/{id}')
  @response(204, {
    description: 'Estudiantes PUT success',
  })
  async replaceById(
    @param.path.string('id') id: string,
    @requestBody() estudiantes: Estudiantes,
  ): Promise<void> {
    await this.estudiantesRepository.replaceById(id, estudiantes);
  }

  @del('/estudiantes/{id}')
  @response(204, {
    description: 'Estudiantes DELETE success',
  })
  async deleteById(@param.path.string('id') id: string): Promise<void> {
    await this.estudiantesRepository.deleteById(id);
  }
}
