<<<<<<< HEAD
#include <sys/types.h> // для использования констант, передаваемых в функцию socket
#include <sys/socket.h> // для использования функции socket
#include <netinet/in.h> // для использования структуры sockaddr_in, которая нужна для определения адреса по протоколу IPv4
#include <arpa/inet.h> // для использования функции htons, которая изменяет порядок байт порта от хоста к сети
#include <unistd.h> // для использования функции read
#include <string.h> // для использования функции strlen
#include "erproc.h"

int main() {
    // открываем сокет
    // AF_INET - семейство протоколов IPv4
    // SOCK_STREAM - для использования протокола TCP
    // третий параметр определяет протокол нижележащего уровня
    // для использования протокола по умолчанию необходимо указать 0
    int server = Socket(AF_INET, SOCK_STREAM, 0);
    // устанавливаем настройкy SO_REUSEADDR сокета для возможности связывания сервера с портом 
    // даже если существуют ранее установленные соединения, использующие этот порт
    // SOL_SOCKET - задает уровень сокетов
    Setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));
    // создаем структуру для хранения адреса
    struct sockaddr_in addr = {0};
    // задаем семейство протоколов IPv4
    addr.sin_family = AF_INET;
    // устанавливаем порт (может быть любое значение)
    addr.sin_port = htons(34543);
    // связываем сервер с данным адресом
    Bind(server, (struct sockaddr *) &addr, sizeof addr);
    // запускаем прослушивание входящий соединений
    // второй параметр указывает, сколько клиентов может ожидать в очереди
    Listen(server, 5);
    // записываем в переменную размер адреса (понадобится для подключения клиента)
    socklen_t addrlen = sizeof addr;
    // принимаем клиента
    int client = Accept(server, (struct sockaddr *) &addr, &addrlen);
    // буфер для хранения информации, переданной клиентом (имени удаляемого файла)
    char filename[256];
    // читаем то, что передал клиент в буфер
    int nread = Read(client, filename, 256);
    // удаляем файл
    Remove(filename);
    // объявляем буфер для хранения ответа от сервера
    char response[512];
    // записываем туда, что удаление прошло успешно
    sprintf(response, "File '%s' deleted successfully.\n", filename);
    // передаем ответ клиенту
    write(client, response, strlen(response));
    // ждем одну секунду
    sleep(1);
    // закрываем соединения
    close(client);
    close(server);
    return 0;
}
=======
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "erproc.h"

int main() {
    int server = Socket(AF_INET, SOCK_STREAM, 0);
    if (setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(34543);
    Bind(server, (struct sockaddr *) &addr, sizeof addr);
    Listen(server, 5);
    socklen_t addrlen = sizeof addr;
    int client = Accept(server, (struct sockaddr *) &addr, &addrlen);
    int nread;
    char filename[256];
    nread = read(client, filename, 256);
    if (nread == -1) {
    	perror("reed failed");
	exit(EXIT_FAILURE);
    }
    if (nread == 0) {
    	printf("END OF FILE occured\n");
    }
    Remove(filename);
    char response[512];
    sprintf(response, "File '%s' deleted successfully.\n", filename);
    write(client, response, strlen(response));
    sleep(1);
    close(client);
    close(server);
    return 0;
}
>>>>>>> 2306faa2b66f33c07e01c02eb382dad1389bf5d4
