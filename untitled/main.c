#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>


int main() {
    /*
     *Cosntantes
     */
    struct sockaddr_in direccionServidor;
    int servidor = socket(AF_INET, SOCK_STREAM, 0);
    direccionServidor.sin_family = AF_INET;
    direccionServidor.sin_addr.s_addr = INADDR_ANY;
    direccionServidor.sin_port = htons(8080);
    /*
     * Abre el servidor para escuchar en el puerto 8080
     */
    if (bind(servidor, (struct sockaddr *) &direccionServidor, sizeof(direccionServidor)) != 0) {
        perror("Falló el bind");
    }

    printf("Estoy escuchando\n");
    listen(servidor, 100);

    /*
     *Queda abierta la conexcion para clientes en el loop
     */
    struct sockaddr_in direccionCliente;
    unsigned int len;


    while (1) {
        int cliente = accept(servidor, (struct sockaddr *)  &direccionCliente, &len);

        printf("Recibí una conexión en %d!!\n", cliente);
        send(cliente, "Hola, desde el server!", 22, 0);
        send(cliente, ":)\n", 4, 0);
        //------------------------------

        char *buffer = (char *) malloc(5);
        int bytesRecibidos = recv(cliente, buffer, 1000, 0);
        if (bytesRecibidos <= 0) {
            perror("Se desconecto.");
        }


        buffer[bytesRecibidos] = '\0';
        printf("Me llegaron %d bytes con %s\n", bytesRecibidos, buffer);
        free(buffer);
    }


    return 0;
}