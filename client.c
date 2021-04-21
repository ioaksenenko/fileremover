#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
<<<<<<< HEAD
=======
#include <stdlib.h>
#include <stdio.h>
>>>>>>> 2306faa2b66f33c07e01c02eb382dad1389bf5d4
#include <unistd.h>
#include <string.h>
#include "erproc.h"

int main() {
<<<<<<< HEAD
    // открываем сокет
    int client = Socket(AF_INET, SOCK_STREAM, 0);
    // также понадобится переменная для указания адреса
    struct sockaddr_in addr = {0};
    // также указываем семейство протоколов IPv4
    addr.sin_family = AF_INET;
    // указываем на какой порт будем стучаться
    addr.sin_port = htons(34543);
    // задаем IP адрес, к которому будем подключаться
    Inet_pton(AF_INET, "127.0.0.1", (struct sockaddr *) &addr.sin_addr);
    // подключаемся к созданному адресу
    Connect(client, (struct sockaddr *) &addr, sizeof addr);
    // создаем переменную для хранения имени файла, который будем удалять
    char filename[256];
    printf("Enter the name of the file you want to delete: ");
    // просим пользователя ввести имя файла, записываем его в переменную filename
    scanf("%s", filename);
    // передаем имя файла
    write(client, filename, strlen(filename));
    // объявляем переменную, куда прочитаем ответ сервера
    char response[256];
    // читаем ответ сервера
    int nread = Read(client, response, 256);
    // выводим на экран ответ сервера
    write(STDOUT_FILENO, response, nread);
    // закрываем соединение клиента
    close(client);
=======
    int fd = Socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(34543);
    Inet_pton(AF_INET, "192.168.98.100", (struct sockaddr *) &addr.sin_addr);
    Connect(fd, (struct sockaddr *) &addr, sizeof addr);
    char filename[256];
    printf("Enter the name of the file you want to delete: ");
    scanf("%s", filename);
    write(fd, filename, strlen(filename));
    char buf[256];
    int nread;
    nread = read(fd, buf, 256);
    if (nread == -1) {
    	perror("read failed");
	exit(EXIT_FAILURE);
    }
    if (nread == 0) {
    	printf("EOF occured\n");
    }
    write(STDOUT_FILENO, buf, nread);
    close(fd);
>>>>>>> 2306faa2b66f33c07e01c02eb382dad1389bf5d4
    return 0;
}
