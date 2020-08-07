
#ifndef UNTITLED_SERVER_H
#define UNTITLED_SERVER_H

#define PORT 8080
#define TAM_MAXIMO 80

/*
 * Parse del json a string para envirarlo en el server
 */
char *jsonParser();

/*
 * Encergado de crear el server para esperar al cliente
 *
 */
void server();



/*
 * constantes del server
 * todas las necesarias para establecer la conexion y mandar los mensajes
 */
int server_fd, new_socket, valread;
struct sockaddr_in address;
int opt = 1;
int addrlen = sizeof(address);
char buffer[1024] = {0};

/*
 * variables del juego
 */
int vidas = 2;
/*
 * Comandos de mensajes en el flow de la consola
 */
int comando;
int comando2;
/*
 * manejo de comandos en cosola
 */
void manejoComandos(int comando);
/*
 * manejo de comandos en consola para crear un fantasma de acuerdo con los requerimientos
 */
void manejoFantasma(int comando);
/*
 * manejo de comandos para generar las pastillas
 */
void manejoPastillas(int comando, int comando2);
int xPos;
int yPos;
//puntos de la fruta
int fPuntos;
/*
 * Varialbles del Json
 */
json_object * jobj;



#endif //UNTITLED_SERVER_H
