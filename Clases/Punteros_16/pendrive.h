typedef struct
{
    int codigo;
    int estado;
    char marca [25];
    int capacidad;
    float precio;

}ePendrive;


int menu();
void inicializarLista(ePendrive *pen,int cantidad);
int buscarLibre(ePendrive *pen,int cantidad);
int siguienteId(ePendrive *pen,int limite);
int cargarPendriveParam(ePendrive* pen, int codigo, char marca[], int capacidad, float precio);
int cargarPendrive (ePendrive* pen);
void mostrarPendrive(ePendrive* pen);
