
#ifndef UTN_H_
#define UTN_H_
int utn_getNombre(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);

int utn_getNumeroEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getDescripcion(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);


#endif /* UTN_H_ */
