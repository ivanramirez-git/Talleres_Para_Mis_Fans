/******************************************************************************
 *
 * policom-def.h: Definicion de complejos y polinomio de tipo complejos
 *
 * Programmer: Cristobal Guzman Poblete
 *
 * Santiago de Chile, 07/04/2022
 *
 ******************************************************************************/
 
 
 
/*definicion de complejo, siendo r la parte real y i la parte imaginario
 *
 */
struct com {
    float r;
    float i;
};



/*definicion de una lista de los terminos de un polinomio con una lista con coef el coeficiente de uno de los termino del polinomio
 *exp el exponente de ese termino de polinomio
 */
struct politerm {
    struct com coef;
    unsigned int exp;
    struct politerm *next;
};

