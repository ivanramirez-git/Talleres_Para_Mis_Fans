package tc.aspects;

import org.aspectj.lang.annotation.Aspect;


/**
 * Complete este aspecto para que haga lo siguiente:
 * 1 (50%). Intercepte todos los llamados (call) a los getters en el paquete tc.aspects.data 
 *   que retornen un dato de tipo String y que hayan sido llamados desde la clase UniversityApplication
 * 		- Imprima por pantalla la firma completa del método interceptado y la línea en el código donde se produjo la intercepción
 * 
 * 2 (50%). Intercepte todas las ejecuciones (execution) a los setters en el paquete tc.aspects.data 
 *   que estén anotados con @Auditable4
 * 		- Imprima por pantalla la firma completa del método interceptado y el valor retornado por el método
 */
@Aspect
public class TallerAspect {


}
