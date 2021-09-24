#ifndef UTN_H_
#define UTN_H_

int menu(int a, int b, int* rtdo);
int sumar(int a, int b);
/** \brief calcula la suma de 2 parametros ingresados
 *
 * \param el primer parametro que se ingresa
 * \param el segundo parametro que se ingresa
 * \return el reultado de la suma de los 2 parametros ingresados
 *
 */

int restar (int a, int b);
/** \brief calcula la resta de 2 parametros ingresados
 *
 * \param el primer parametro que se ingresa
 * \param el segundo parametro que se ingresa
 * \return el resultado de la resta de los 2 parametros ingresados
 *
 */

int multiplicar(int a, int b);
/** \brief calcula la multiplicacion entre 2 parametros ingresados
 *
 * \param el primer parametro que se ingresa
 * \param el segundo parametro que se ingresa
 * \return  resultado de la multiplicacion de los 2 parametros ingresados
 *
 */

float dividir(int a, int b);
/** \brief calcula la division entre 2 parametros ingresados
 *
 * \param el primer parametro ingresado
 * \param el segundo parametro ingresado
 * \return el resultado de la division de los 2 parametros ingresados
 *
 */

int factorial(int a);
/** \brief calcula la el factorial de un numero ingresado
 * \param el primer parametro ingresado
 * \return el resultado del factorial
 *
 */
void rtdoFactorial(int a, int factorial );

#endif /* UTN_H_ */
