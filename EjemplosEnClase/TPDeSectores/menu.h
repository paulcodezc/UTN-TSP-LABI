#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

typedef struct
{
    int codigo;
    char descripcion[51];
    float importe;
    int isEmpty;

}eMenu;


// Acá van los prototipos


/**
 * \brief Deja un poco de espacio y espera que ingreses una tecla para continuar
 * \param
 * \param
 * \return -
 *
 */
void wait();

int menu();

/**
 * \brief Inicializa el array de estructuras
 * \param eGenerica lista[] array a inicializar
 * \param limite el tamaño del array
 * \return
 *
 */
void initMenu(eMenu lista[], int limite);


/**
 * \brief Muestra los isEmpty de la estructura para testear que esten libres
 * \param eGenerica lista[] array a mostrar
 * \param limite el tamaño del array
 * \return
 *
 */
void mostrarInitMenu(eMenu lista[], int limite);



/**
 * \brief Busca en la estructura eGenerica un espacio libre
 * \param eMenu lista[] array a buscar el espacio libre
 * \param limite el tamaño del array
 * \return devuelve el indice libre encontrado, de lo contrario [-1]
 *
 */
int buscarEspacioLibreM(eMenu lista[], int limite);

/**
 * \brief Agrega un nuevo menu al sistema
 * \param eMenu lista[] array donde cargara el menu
 * \param limite el tamaño del array
 * \return devuelve [0] si salio todo bien
 *
 */
int altaMenus(eMenu lista[], int limite);


/**
 * \brief Muestra los menus del sistema
 * \param eMenu lista[] array a mostrar
 * \param limite el tamaño del array
 * \return
 *
 */
int mostrarMenus(eMenu lista[], int limite);



/**
 * \brief Busca en el array un codigo
 * \param eMenu lista[] el array donde se buscara el dni
 * \param limite tamaño del array
 * \param codigo a buscar
 * \return devuelve la posion del dni encontrado, caso contrario [-1] si no lo encuentra
 *
 */
int buscarPorCodigo(eMenu lista[], int limite, int codigo);


/**
 * \brief Muestra un menu
 * \param eGenerica emp el array a mostrar
 * \param i el indice del array a mostrar
 * \return
 *
 */
void mostrarUnMenu(eMenu menu[], int i);


/**
 * \brief Da de baja un menu
 * \param eMenu lista el array de menus
 * \param limite el tamaño del array
 * \return [0] si se da baja logica
 *
 */
int bajaMenus(eMenu lista[], int limite);



/**
 * \brief Harcodea algunos menus
 * \param eMenu lista el array a cargar
 * \param limite el tamaño del array
 * \return
 *
 */
void hardcodeoMenus(eMenu lista[], int limite);



/**
 * \brief Permite modificar algun menu por importe y descripcion
 * \param eMenu lista el array para modificar
 * \param limite el tamaño del array
 * \return [0] si salio todo bien
 *
 */
int modificarMenus(eMenu lista[], int limite);



/**
 * \brief Muestra la lista de menus en el sistema
 * \param eMenu lista el array a mostrar
 * \param limite el tamaño del array
 * \return
 *
 */
void listarMenus(eMenu lista[], int limite);



/**
 * \brief Ordena los Menus por importe y descripcion
 * \param eMenu lista el array para ordenar
 * \param limite el tamaño del array
 * \return [0] si salio todo bien
 *
 */
int ordenarXImporteYDes(eMenu lista[], int limite);


#endif // MENU_H_INCLUDED
