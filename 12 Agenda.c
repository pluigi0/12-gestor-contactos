//LIBRERIAS USADAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PROTOTIPOS DE LAS FUNCIONES
void vacio();
void menuPrincipal();
void titulo();
void agregarContactos();
void listarContactos();
void modificarContacto();
void buscarContacto();
void eliminarContacto();

//ESTRUCTURA CON VARIABLES DINAMICAS Y PUNTEROS
struct agenda{
	char *nombres;
	char *correo;
	char *telefono;
	int estado;
}arreglo[10];


int main(){
	vacio();
	menuPrincipal();
}


//FUNCION QUE MUESTRA EN PANTALLA EL MENU DE OPCIONES
void menuPrincipal(){
	int op;
	
	do{
		system("cls");
		titulo();
		printf("MENU PRINCIPAL\n\n");
		printf("1. Agregar nuevos contactos.\n");
		printf("2. Listar todos los contactos.\n");
		printf("3. Modificar el detalle de los contactos.\n");
		printf("4. Buscar contactos guardados.\n");
		printf("5. Eliminar contactos telefonicos.\n");
		printf("6. Salir del Programa\n\n");
		printf("Ingrese opcion: ");
		scanf("%i",&op);	
	}while(op < 1 || op > 6);
	
	switch(op){
		case 1:
			agregarContactos();
			break;
			
		case 2:
			listarContactos();
			break;
		
		case 3:
			modificarContacto();
			break;
		
		case 4:
			buscarContacto();
			break;
		
		case 5:
			eliminarContacto();
			break;
		
		case 6:
			exit(0);
			break;
	}
}

//FUNCION QUE PERMITE AGREGAR UN CONTACTO
void agregarContactos(){
	int i,j, n_cuenta, rep, aux = 0;
	char nombres[75], telefono[25], correo[25];
	
	system("cls");
	titulo();
	printf("AGREGAR NUEVOS CONTACTOS\n\n");
	fflush(stdin); //LIMPIA BUFFER
	
	for(i = 0; i < 10; i++){
		if(arreglo[i].estado == 0){
			aux = 1;
			
			printf("Ingrese nombres:            ");
			gets(nombres);
			
			arreglo[i].nombres = (char*)malloc((strlen(nombres)+1)*sizeof(char)); //ASIGNAMOS ESPACIO
			if(arreglo[i].nombres == NULL){
				printf("\nNo se ha podido reservar memoria/\n");
				exit(1);
			}
			strcpy(arreglo[i].nombres,nombres);
			
			
			printf("Ingrese telefono:           ");
			gets(telefono);
			
			arreglo[i].telefono = (char*)malloc((strlen(telefono)+1)*sizeof(char)); //ASIGNAMOS ESPACIO
			if(arreglo[i].telefono == NULL){
				printf("\nNo se ha podido reservar memoria/\n");
				exit(1);
			}
			strcpy(arreglo[i].telefono,telefono);
			
			
			printf("Ingrese correo electronico: ");
			gets(correo);
			
			arreglo[i].correo = (char*)malloc((strlen(correo)+1)*sizeof(char));
			if(arreglo[i].correo == NULL){
				printf("\nNo se ha podido reservar memoria/\n");
				exit(1);
			}
			strcpy(arreglo[i].correo,correo);
				
			arreglo[i].estado = 1;
			printf("\nSe agrego el contacto correctamente.\n");
			system("pause");
			menuPrincipal();
		}
	}
	
	if(aux == 0){
		printf("\nNo se pueden registrar mas clientes.\n");
		system("pause");
		menuPrincipal();
	}	
}

//FUNCION QUE MUESTRA EN PANTALLA A TODOS LOS CONTACTOS REGISTRADOS
void listarContactos(){
	int i, aux = 0;
	
	system("cls");
	titulo();
	printf("LISTA DE CONTACTOS\n\n");
	
	for(i = 0; i < 10; i++){
		if(arreglo[i].estado == 1){
			aux++;
			printf("Nombres:         %s\n",arreglo[i].nombres);
			printf("Telefono:        %s\n",arreglo[i].telefono);
			printf("Correo:          %s\n\n",arreglo[i].correo);		
			printf("---------------------------------------\n\n");
		}
	}
	
	if(aux == 0){
		printf("No se encontraron Contactos registrados!\n");
	}
	
	system("pause");
	menuPrincipal();
}


//FUNCION QUE PERMITE MODIFICAR LOS DETALLES DE UN CONTACTO
void modificarContacto(){
	int i, opcion, aux = 0;
	char nombres[75];
	
	system("cls");
	titulo();
	fflush(stdin); //LIMPIA BUFFER
	
	printf("MODIFICAR DETALLE DE CONTACTO\n\n");
	printf("Ingrese Nombres del Contacto: ");
	gets(nombres);
	
	for(i = 0; i < 10 && aux == 0; i++){
		if(strcmpi(nombres,arreglo[i].nombres)==0 && arreglo[i].estado == 1) {
			system("cls");
			titulo();
			printf("ACTUALIZAR INFORMACION DE CUENTA\n\n");
			printf("1. Nombres:          %s\n",arreglo[i].nombres);
			printf("2. Telefono:         %s\n",arreglo[i].telefono);
			printf("3. Correo:           %s\n",arreglo[i].correo);
			
			do{
				printf("Ingrese opcion a actualizar: ");
				scanf("%i",&opcion);
			}while(opcion < 1 || opcion > 3);
			fflush(stdin);
			
			switch(opcion){
				case 1:
					printf("\nNombres del Contacto:   %s\n",arreglo[i].nombres);
					printf("Ingrese nuevos Nombres: ");
					gets(arreglo[i].nombres);
					
					printf("\nSe actualizo correctamente la informacion.\n");
					break;
					
				case 2:
					printf("\nTelefono actual:        %s\n",arreglo[i].telefono);
					printf("Ingrese nuevo Telefono: ");
					gets(arreglo[i].telefono);
					
					printf("\nSe actualizo correctamente la informacion.\n");
					break;
					
				case 3:
					printf("Correo actual:          %s\n",arreglo[i].correo);
					printf("Ingrese nuevo Correo: ");
					gets(arreglo[i].correo);
					
					printf("\nSe actualizo correctamente la informacion.\n");
					break;
			}
			
			aux = 1;
		}
	}
	
	if(aux == 0){
		printf("\nNo se encontro a ningun contacto con este Nombre.\n");
	}
	
	system("pause");
	menuPrincipal();
}

//FUNCION QUE PERMITE BUSCAR A UN CONTACTO EN ESPECIFICO
void buscarContacto(){
	int i, opcion, aux = 0;
	char nombres[75];
	
	system("cls");
	titulo();
	fflush(stdin); //LIMPIA BUFFER
	
	printf("BUSCAR CONTACTO\n\n");
	printf("Ingrese Nombres del Contacto a buscar: ");
	gets(nombres);
	
	for(i = 0; i < 10 && aux == 0; i++){
		if(strcmpi(nombres,arreglo[i].nombres)==0 && arreglo[i].estado == 1){
			system("cls");
			titulo();
			printf("CONTACTO ENCONTRADO!\n\n");
			printf("Nombres:          %s\n",arreglo[i].nombres);
			printf("Telefono:         %s\n",arreglo[i].telefono);
			printf("Correo:           %s\n\n",arreglo[i].correo);
			
			aux = 1;
		}
	}
	
	if(aux == 0){
		printf("\nNo se encontro a ningun contacto con este Nombre.\n");
	}
	
	system("pause");
	menuPrincipal();
}

//FUNCION QUE PERMITE ELIMINAR UN CONTACTO
void eliminarContacto(){
	int i, aux = 0;
	char nombres[75];
	
	system("cls");
	titulo();
	printf("ELIMINAR CONTACTO\n\n");
	fflush(stdin); //LIMPIA BUFFER
	
	printf("Ingrese Nombres del contacto a eliminar: ");
	gets(nombres);
	
	for(i = 0; i < 10; i++){
		if(strcmpi(nombres,arreglo[i].nombres)==0 && arreglo[i].estado == 1){
			system("cls");
			titulo();
			printf("ELIMINAR CONTACTO\n\n");
			arreglo[i].estado = 0;
			aux = 1;
			printf("El contacto ha sido eliminado correctamente.\n");
		}
	}
	
	if(aux == 0){
		printf("\nNumero de Contacto no existe.\n");
	}
	
	system("pause");
	menuPrincipal();
}




//FUNCION QUE MUESTRA EL ENCABEZADO O TITULO DEL PROGRAMA
void titulo(){
	static char titulo[50] = "    GESTOR DE CONTACTOS SIMPLE";
	static char linea[50] = "==================================";
	printf("\t\t\t\t\t%s\n",linea);
	printf("\t\t\t\t\t%s\n",titulo);
	printf("\t\t\t\t\t%s\n\n\n",linea);
}


//FUNCION QUE ASIGNA EL VALOR DE 0 A LA VARIABLE ESTADO DEL ARREGLO
void vacio(){
	int i;
	for(i = 0; i < 10; i++){
		arreglo[i].estado = 0;
	}
}
