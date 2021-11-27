#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getDescripcion(char* cadena, int len);
static int getNumeroEntero(int* pResultado);
static int getFlotante(float* pResultado);

static int getNombre(char* cadena, int len);
static int getString(char* cadena, int len);
static int esNombre(char* cadena, int len);

static int esNumeroEntero(char* cadena, int len);
static int esNumeroFlotante(char* cadena, int len);

static int esDescripcion(char* cadena, int len);


/**
 * \brief Solicita un nombre o apellido al usuario, luego de su verificación devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria, donde se alojará el resultado de la función.
 * \param len Es la longitud del array resultado.
 * \param mensaje Mensaje a mostrar al usuario para el ingreso del nombre o apellido.
 * \param mensajeError Mensaje de error, en caso de que el nombre o apellido ingresado por el usuario sea erróneo.
 * \param reintentos Cantidad de reintentos.
 * \return Retorna 0 si obtuvo el nombre o apellido y -1 si tuvo algún error.
 *
 */
int utn_getNombre(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[4096];

	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos > -1)
	{
		do{
			printf("%s", mensaje);
			if( !getNombre(bufferString,sizeof(bufferString)))
			{
				retorno = 0;
				strncpy(pResultado,bufferString,len);
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

/**
 * \brief Obtiene una cadena válida como nombre o apellido.
 * \param pResultado Puntero al espacio de memoria, donde se alojará el resultado de la función.
 * \param len Define el tamaño de la cadena.
 * \return Retorna 0 si obtuvo el nombre o apellido y -1 si tuvo algun error.
 *
 */
static int getNombre(char* cadena, int len)
{
    int retorno=-1;
    char bufferString[4096];

    if( cadena != NULL &&
    	len > 0 &&
    	!getString(bufferString,sizeof(bufferString)) &&
		esNombre(bufferString,sizeof(bufferString)) &&
		strnlen(bufferString,sizeof(bufferString)) < len)
    	{
    		strncpy(cadena,bufferString,len);
			retorno = 0;
		}
    return retorno;
}
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'len - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida.
 * \param len Define el tamaño de la cadena.
 * \return Retorna 0 si se obtiene una cadena y -1 si tuvo algún error.
 *
 */
static int getString(char* cadena, int len)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(cadena,bufferString,len);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre o apellido válido.
 * \param cadena Cadena de caracteres a analizar.
 * \param \param len Define el tamaño de la cadena.
 * \return Retorna 1 si la cadena es válida y 0 si no lo es.
 *
 */
static int esNombre(char* cadena, int len)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && len > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < len; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, luego de su verificación devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria, donde se alojará el resultado de la función.
 * \param mensaje Mensaje a mostrar al usuario para el ingreso del numero.
 * \param mensajeError Mensaje de error, en caso de que el número ingresado por el usuario sea erróneo.
 * \param minimo Es el numero maximo a ser aceptado.
 * \param maximo Es el minimo minimo a ser aceptado.
 * \return Retorna 0 si obtuvo el nombre o apellido y -1 si tuvo algún error.
 *
 */
int utn_getNumeroEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos > -1)
	{
		do
		{
			printf("%s",mensaje);
			if(	!getNumeroEntero(&bufferInt) &&
				bufferInt >= minimo &&
				bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

/**
 * \brief Obtiene una cadena válida como un numero entero.
 * \param pResultado Puntero al espacio de memoria, donde se alojará el resultado de la función.
 * \return Retorna 0 si obtuvo el numero entero y -1 si tuvo algún error.
 *
 */
static int getNumeroEntero(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];//*************************************

    if(	pResultado != NULL &&
    	!getString(bufferString,sizeof(bufferString)) &&
		esNumeroEntero(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString);
	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un numero entero válido.
 * \param cadena Cadena de caracteres a analizar.
 * \param \param len Define el tamaño de la cadena.
 * \return Retorna 1 si la cadena es un numero entero y 0 si no lo es.
 *
 */
static int esNumeroEntero(char* cadena, int len)
{
	int retorno = 0;
	int i;
	if(cadena != NULL && len > 0)
	{
		retorno = 1;
		for(i=0;i<len && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita una descripción al usuario, luego de su verificación devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria, donde se alojará el resultado de la función.
 * \param len Es la longitud del array resultado.
 * \param mensaje Mensaje a mostrar al usuario para el ingreso de la descripción.
 * \param mensajeError Mensaje de error, en caso de que la descripción ingresada por el usuario sea errónea.
 * \param reintentos Cantidad de reintentos.
 * \return Retorna 0 si obtuvo la descripción y -1 si tuvo algún error.
 *
 */
int utn_getDescripcion(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[4096];

	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos > -1)
	{
		do{
			printf("%s", mensaje);
			if( !getDescripcion(bufferString,sizeof(bufferString)) )
			{
				retorno = 0;
				strncpy(pResultado,bufferString,len);
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

/**
 * \brief Obtiene una cadena válida como una descripción.
 * \param pResultado Puntero al espacio de memoria, donde se alojará el resultado de la función.
 * \param len Define el tamaño de la cadena.
 * \return Retorna 0 si obtuvo la descripción y -1 si tuvo algun error.
 *
 */
static int getDescripcion(char* cadena, int len)
{
    int retorno=-1;
    char bufferString[4096];

    if( cadena != NULL &&
    	len > 0 &&
    	!getString(bufferString,sizeof(bufferString)) &&
		esDescripcion(bufferString,sizeof(bufferString)) &&
		strnlen(bufferString,sizeof(bufferString)) < len)
    	{
    		strncpy(cadena,bufferString,len);
			retorno = 0;
		}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es una descripción.
 * \param cadena Cadena de caracteres a analizar.
 * \param \param len Define el tamaño de la cadena.
 * \return Retorna 1 si la cadena es válida y 0 si no lo es.
 *
 */
static int esDescripcion(char* cadena, int len)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && len > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < len; i++)
		{
			if( cadena[i] != '.' &&
				cadena[i] != ',' &&
				cadena[i] != ' ' &&
				(cadena[i] < 'A' || cadena[i] > 'Z' ) &&
				(cadena[i] < 'a' || cadena[i] > 'z' ) &&
				(cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Solicita un numero al usuario, luego de su verificación devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria, donde se alojará el resultado de la función.
 * \param mensaje Mensaje a mostrar al usuario para el ingreso del numero.
 * \param mensajeError Mensaje de error, en caso de que el número ingresado por el usuario sea erróneo.
 * \param minimo Es el numero maximo a ser aceptado.
 * \param maximo Es el minimo minimo a ser aceptado.
 * \return Retorna 0 si obtuvo el numero entero y -1 si tuvo algún error.
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos > -1)
	{
		do
		{
			printf("%s",mensaje);
			if(	!getFlotante(&bufferFloat) &&
				bufferFloat >= minimo &&
				bufferFloat <= maximo)
			{
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

/**
 * \brief Obtiene una cadena válida como un numero flotante.
 * \param pResultado Puntero al espacio de memoria, donde se alojará el resultado de la función.
 * \return Retorna 0 si obtuvo el numero flotante y -1 si tuvo algún error.
 *
 */
static int getFlotante(float* pResultado)
{
    int retorno=-1;
    char bufferString[50];//*************************************

    if(	pResultado != NULL &&
    	!getString(bufferString,sizeof(bufferString)) &&
		esNumeroFlotante(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atof(bufferString);
	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un numero flotante válido.
 * \param cadena Cadena de caracteres a analizar.
 * \param \param len Define el tamaño de la cadena.
 * \return Retorna 1 si la cadena es un numero flotante y 0 si no lo es.
 *
 */
static int esNumeroFlotante(char* cadena, int len)
{
	int retorno = 0;
	int i;
	int contadorPuntos = 0;
	if(cadena != NULL && len > 0)
	{
		retorno = 1;
		for(i=0;i<len && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;//Itera una vez mas.
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}
