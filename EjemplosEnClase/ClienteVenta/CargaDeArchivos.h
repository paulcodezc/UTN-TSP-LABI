#ifndef CargaDeArchivos_H_INCLUDED
#define CargaDeArchivos_H_INCLUDED


int cargarArchClientesTexto(char* path, LinkedList* pArrayListEmployee);

int cargarArchClientesBinario(char* path, LinkedList* pArrayListEmployee);

int parser_ClientesDesdeTexto(FILE* pFile, LinkedList* pArrayListEmployee);

int parser_ClientesDesdeBinario(FILE* pFile, LinkedList* pArrayListEmployee);

int guardarClientesComoTexto(char* path, LinkedList* pArrayListEmployee);

int guardarClientesComoBinario(char* path, LinkedList* pArrayListEmployee);


/*******************************************************/

int parser_VentasDesdeTexto(FILE* pFile, LinkedList* pArrayListVentas);

int parser_VentasDesdeBinario(FILE* pFile, LinkedList* pArrayListVentas);

int cargarArchVentasTexto(char* path, LinkedList* pArrayListVentas);

int cargarArchVentasBinario(char* path, LinkedList* pArrayListVentas);

int guardarVentasComoTexto(char* path, LinkedList* pArrayListVentas);

int guardarVentasComoBinario(char* path, LinkedList* pArrayListVentas);


#endif // CargaDeArchivos_H_INCLUDED
