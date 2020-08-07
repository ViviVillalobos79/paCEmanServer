#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <json-c/json.h>
#include "Server.h"
#define PORT 8080
#define TAM_MAXIMO 801


int main(int argc, char *argv[]) {
    while (1) {
        printf("Comandos disponibles\n");
        printf("1 - Crear fantasma\n");
        printf("2 -Crear pastilla\n");
        printf("3 -Crear fruta\n");
        printf(">");
        //scanf("%[^\n]", comando);
        scanf("%d", &comando);
        manejoComandos(comando);
        server();
    }
}

void manejoComandos(int comando) {
    // se crea un objeto json
    jobj = json_object_new_object();
    if (comando == 1){
        printf("Comandos disponibles\n");
        printf("1 - Clyde\n");
        printf("2 - Blinky\n");
        printf("3 - Pinky\n");
        printf("4 - Inky\n");
        printf(">");
        scanf("%d", &comando2);
        manejoFantasma(comando2);
    }if (comando == 2){
        printf("ingrese posX para pastilla\n");
        printf(">");
        scanf("%d", &xPos);
        printf("ingrese posY para pastilla\n");
        printf(">");
        scanf("%d", &yPos);
        manejoPastillas(xPos,yPos);
    }if (comando == 3){
        printf("ingrese puntos para fruta\n");
        printf(">");
        scanf("%d", &fPuntos);
        /*Se crea un json obj de tipo int*/
        json_object *jint1 = json_object_new_int(fPuntos);
        json_object_object_add(jobj,"fPuntos", jint1);
    }
}

void manejoFantasma(int comando) {
    jobj = json_object_new_object();
    if (comando == 1){
        /*Se crea un json obj de tipo int*/
        json_object *jstr = json_object_new_string("Clyde");
        json_object_object_add(jobj,"fantasma", jstr);
    }if (comando == 2){
        //*Se crea un json obj de tipo int*/
        json_object *jstr = json_object_new_string("Blinky");
        json_object_object_add(jobj,"fantasma", jstr);
    }if (comando == 3){
        /*Se crea un json obj de tipo int*/
        json_object *jstr = json_object_new_string("Pinky");
        json_object_object_add(jobj,"fantasma", jstr);
    }if (comando == 4){
        /*Se crea un json obj de tipo int*/
        json_object *jstr = json_object_new_string("Inky");
        json_object_object_add(jobj,"fantasma", jstr);
    }
}
void manejoPastillas(int comando, int comando2) {
    jobj = json_object_new_object();
    /*Se crea un json obj de tipo int*/
    json_object *jint = json_object_new_int(xPos);
    json_object_object_add(jobj,"xPill", jint);
    /*Se crea un json obj de tipo int*/
    json_object *jint1 = json_object_new_int(yPos);
    json_object_object_add(jobj,"yPill", jint1);
}





/*
 * Mensaje Json
 *Crea el mensaje json que se va a enviar a cliente
 */
char *jsonMsj() {
    const char *jsonString = json_object_to_json_string(jobj);

    return (char *)jsonString;

}

/*
 * Server
 * crea el server y espera la conexion del cliente para mandarle todos los datos
 * en un mensaje json
 */
void server(){
    // Desctriptor de socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Asignado puerto y paramatros
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );



    printf("******************************Esperando conexion del cliente**********************************\n");
    // definicion del socket en el puerto 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }


    //Envio de mensaje al cliente
    send(new_socket, jsonMsj(), strlen(jsonMsj()), 0);
    send(new_socket, "\n", strlen("\n"), 0);

    //Lectura del mensaje cliente
    valread = recv(new_socket, buffer, 1024,0);

    printf("%s\n", buffer);
    printf("Comando enviado\n");

    close(new_socket);
    close(server_fd);
    printf("******************************Conexion cerrada**************************************************\n");
}
