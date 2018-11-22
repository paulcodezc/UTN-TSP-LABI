#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#define ESTRUCTURAGENERICA_H_INCLUDED
typedef struct
{
    char nombre[50];
    //------------
    char password[50];
    int idGenerica;
    int idProducto;
    int estado;
}eUsuario;

typedef struct
{
    char nombre[50];
    char usuario[50];
    float precio;
    int stock;
    int idProducto;
    int cantVentas;
    int estado;
}eProducto;

#endif // ESTRUCTURAGENERICA_H_INCLUDED

int eUsuario_init(eUsuario[],int limite);
void hardcodeUsuarios(eUsuario listado[], int limite);
void menu();
int eUsuario_siguienteId(eUsuario[] ,int limite);
int eUsuario_buscarLugarLibre(eUsuario listado[],int limite);
int eUsuario_alta(eUsuario listado[] ,int limite);
int eUsuario_baja(eUsuario listado[] ,int limite);
int eUsuario_modificar(eUsuario listado[] ,int limite);
int eUsuario_buscarPorId(eUsuario[] ,int limite, int id);
//********************************************//
int getString(char* input, char message[]);
int getInt(int* input, char message[]);
int getFloat(float* input,char message[]);
int getSN(char* input, char message[], char eMessage[]);
int eUsuario_mostrarLista(eUsuario listado[], int limite);
int eProducto_mostrarLista(eProducto listado[], int limiteP);
int validarId(eUsuario listado[], int limite, int id);
//********************************************//
int eProducto_publicarProducto(eUsuario listado[] ,int limite, eProducto listadoP[], int limiteP);
int eProducto_init(eProducto listado[],int limiteP);
void hardcodeProductos(eProducto listado[], int limitep);
int eProducto_buscarLugarLibre(eProducto listado[],int limiteP);
int mostrarProductosdeUsuarios(eProducto listadoP[], int limiteP, eUsuario listado[], int limite, int id);
int eProducto_modificarPublicacion(eProducto listadoP[], int limiteP, eUsuario listado[], int limite);
int eProducto_cancelarPublicacion(eProducto listadoP[], int limiteP, eUsuario listado[], int limite);
