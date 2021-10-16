
#ifndef UTN_H_
#define UTN_H_
int getString(char* cadena, int longitud);
int esNumerica(char* cadena, int limite);
int getInt(int* pResultado);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getString(char* cadena, int longitud);
int esFlotante(char* cadena);
int getFloat(float* pResultado);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int esNombre(char* cadena,int longitud);
int getNombre(char* pResultado, int longitud);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int esDescripcion(char* cadena,int longitud);
int getDescripcion(char* pResultado, int longitud);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

#endif /* UTN_H_ */
