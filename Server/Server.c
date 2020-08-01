#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include<json-c/json.h>
#define PORT 8080
#define TAM_MAXIMO 80

char *jsonParser();

void server();
/*
 * constantes del server
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
 * Comandos
 */
char comando[TAM_MAXIMO];
int main(int argc, char *argv[]) {

    printf("Ingrese un comando\n");
    scanf("%[^\n]",comando);

    printf("%s",comando);
    server();
}


/*
 * Mensaje Json
 *Crea el mensaje json que se va a enviar a cliente
 */
char *jsonMsj() {
    // se crea un objeto json
    json_object * jobj = json_object_new_object();

    /*Se crea un json obj de tipo int*/
    json_object *jint = json_object_new_int(vidas);

    json_object_object_add(jobj,"vidas", jint);


    return json_object_to_json_string(jobj);

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
    // Forcefully attaching socket to the port 8080
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
    //Lectura del mensaje cliente
    valread = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);
    printf("Comando enviado\n");
    close(server_fd);
    printf("******************************Conexion cerrada**************************************************\n");
}