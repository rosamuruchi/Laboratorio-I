#define TAMU 100
#define TAMP 1000
typedef struct
{
    char nombre[50];
    int password;
    int idUsuarios;
    int calificacion;
    int estado;
}eUsuarios;


typedef struct
{
    int idProducto;
    int idUsuario;
    char nombre[50];
    float precio;
    int stock;
    int cantidadVendida;
    int estado;
}eProductos;



//USUARIOS//

int inicializarListaUsuarios( eUsuarios listado[],int limite);
void inicializarUsuariosHardCode(eUsuarios usuarios[],int limite);

int buscarLugarLibre(eUsuarios lista[],int limite);

void auxMostrarLista(eUsuarios lista[],int limite);
void altadeUsuarios(eUsuarios lista[],int limite);
void mostrarListaUsuarios(eUsuarios lista[],int limite);
int buscarPorId(eUsuarios lista[] ,int limite, int auxId);
void modificarDatos(eUsuarios lista[], int limite);
void bajaUsuarios (eUsuarios lista[], int limite);

//PRODUCTOS//


int inicializarListaProductos( eProductos lista[],int limite);
void inicializarProductosHardCode(eProductos productos[],int limite);

int buscarLugarLibreProducto(eProductos lista[],int limite);
int siguienteIdProducto(eProductos lista[],int limite);
void publicarProductos (eProductos lista[], int limite);

void mostrarListaProductos(eProductos lista[],int limite);
void modificarPublicacion(eProductos lista [],int limite);
