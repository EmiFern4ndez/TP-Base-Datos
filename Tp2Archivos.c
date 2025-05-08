#include <stdio.h>
#include <stdlib.h>
#define datos 40
#define fechas 12

typedef struct socio{
    int num;
    int dni;
    char apeynom[datos];
    char domicilo[datos];
    char nacimiento[fechas];
    char asociacion[fechas];
}Socio;

typedef struct lista{
    Socio dato;
    struct lista *sig;
} *Lista;

void leerSocio(Socio *s){
    printf("Ingrese el numero:");
    scanf("%d", &s->num);
    // Limpiar el buffer de entrada después de leer un entero
    while (getchar() != '\n');
    printf("Ingrese el dni:");
    scanf("%d", &s->dni);
    // Limpiar el buffer de entrada después de leer un entero
    while (getchar() != '\n');
    printf("Ingrese el Apellido y Nombre:");
    fgets(s->apeynom, datos, stdin);
    // Eliminar el salto de línea que fgets puede agregar al final
    s->apeynom[strcspn(s->apeynom, "\n")] = 0;
    printf("Ingrese el Domicilio:");
    fgets(s->domicilo, datos, stdin);
    s->domicilo[strcspn(s->domicilo, "\n")] = 0;
    printf("Ingrese el nacimiento:");
    fgets(s->nacimiento, fechas, stdin);
    s->nacimiento[strcspn(s->nacimiento, "\n")] = 0;
    printf("Ingrese la fecha de asociacion:");
    fgets(s->asociacion, fechas, stdin);
    s->asociacion[strcspn(s->asociacion, "\n")] = 0;
} 

void mostrarSocio(Socio s){
    printf("---------------------------\n");
    printf("|Numero: %d                |\n", s.num);
    printf("|Dni: %d                   |\n", s.dni);
    printf("|Apellido y nombre: %s     |\n", s.apeynom);
    printf("|Domicilio: %s             |\n", s.domicilo);
    printf("|Fecha de nacimiento: %s   |\n", s.nacimiento);
    printf("|Fecha de asociacion: %s   |\n", s.asociacion);\
    printf("---------------------------\n");
}

int existe(char nomArch[datos], int num){
    FILE *arch;
    arch = fopen(nomArch, "rb");
    int ok = 0;
    Socio socio;
    if (arch != NULL){
        while (fread(&socio, sizeof(Socio), 1, arch) && (ok != 1)){
            if (socio.num == num && socio.num != 0){
                ok = 1;
            }
        }
        fclose(arch);
    }else
        fclose(arch);
    return ok;
}

void alta(char nomArch[datos], Socio s){
    if (!existe(nomArch, s.num)){
        FILE *arch;
        arch = fopen(nomArch, "ab");
        if (arch != NULL){
            fwrite(&s, sizeof(Socio), 1, arch);
            fclose(arch);
        }else {
            printf("\nError al abrir el archivo\n");
        }
    }else {
        printf("\nEl socio ya existe\n");
    }
}

void baja(char nomArch[datos], int num){
    FILE *arch;
    arch = fopen(nomArch, "rb+");
    if (arch != NULL){
        Socio socio;
        if (existe(nomArch, num)){
            while (fread(&socio, sizeof(Socio), 1, arch)){
                if (socio.num == num){
                    socio.num = 0;
                    fseek(arch, -sizeof(Socio), SEEK_CUR); // Retrocede al inicio del registro
                    fwrite(&socio, sizeof(Socio), 1, arch);
                    fflush(arch);
                }
            }
            fclose(arch);
            printf("\nSe elimino con exito el socio\n");
        }else{
            fclose(arch);
            printf("\nNo existe el socio\n");
        }
    }
}

void listarSocios(char nomArch[datos]){
    FILE *arch;
    arch = fopen(nomArch, "rb");
    int cantSocios = 0;
    if (arch != NULL){
        Socio socio;
        while (fread(&socio, sizeof(Socio), 1, arch)){
            if (socio.num != 0){
                printf(" *************************\n Nombre y apellido: %s\n Dni: %d\n Numero de socio: %d\n Fech. Nacimiento: %s\n Fech. Asociacion: %s\n *************************\n \n", socio.apeynom, socio.dni, socio.num, socio.nacimiento, socio.asociacion);
                cantSocios++;
            }
        }
        if (cantSocios == 0){
            printf("El archivo no tiene socios registrados\n");
        }
    }
    fclose(arch);
}

void mostrarMenu(){
    printf("---------------------------\n");
    printf("|         MENU            |\n");
    printf("| 1) Dar de alta un socio |\n");
    printf("| 2) Dar de baja un socio |\n");
    printf("| 3) Buscar socio         |\n");
    printf("| 4) Listar socio         |\n");
    printf("| 5) Salir                |\n");
    printf("---------------------------\n");
}

void menu(char nomArch[datos]){
    int opcion;
    Socio s;
    int numSocio;
    mostrarMenu();
    scanf("%d", &opcion);
    while (opcion < 1 || opcion > 5) {
        printf("\nOpcion incorrecta. Ingrese una opcion valida (1-5): \n");
        mostrarMenu();
        scanf("%d", &opcion);
    }

    while(opcion != 5){
        switch (opcion){
            case 1:{
                leerSocio(&s);
                alta(nomArch, s);
                break;
            }

            case 2:{
                printf("\nIngrese el numero del socio que quieres eliminar:");
                scanf("%d", &numSocio);
                baja(nomArch, numSocio);
                break;
            }

            case 3:{
                printf("\nIngrese el numero del socio que quieres buscar: ");
                scanf("%d", &numSocio);
                if (existe(nomArch, numSocio)){
                    printf("\nExiste el socio con numero: %d\n", numSocio);
                }else{
                    printf("\nNo existe el socio\n");
                }
                break;
            }

            case 4:{
                listarSocios(nomArch);
                break;
            }

            case 5:
                break;
        }

        mostrarMenu();
        scanf("%d", &opcion);
        while (opcion < 1 || opcion > 5) {
            printf("Opcion incorrecta. Ingrese una opcion valida (1-5): \n");
            mostrarMenu();
            scanf("%d", &opcion);
        }
    }
}

int main(){
    char nomArch[datos];
    printf("Ingrese el nombre del archivo:");
    scanf("%s", nomArch);
    menu(nomArch);
    return 0;
}
