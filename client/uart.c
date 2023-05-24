#include <coresrv/syscalls.h>

#include <stdint.h>

#include <stdio.h>

#include <stdlib.h>

#include <rtl/countof.h>

#include <uart/uart.h>

 

#define UART1_RX_PIN (13)

#define UART2_TX_PIN (14)

 

 

#define UART3_RX_PIN (15)

#define UART4_TX_PIN (16)

 

 

#define UART5_RX_PIN (17)

#define UART6_TX_PIN (18)

 

 

char str2[] = "Open duplicate element\n"; // строка которую будем выводить в порт

char str3[] = "Сlose the relay\n"; // строка которую будем выводить в порт

char str4[] = "The system is working!\n";

char str5[] = "Сlose duplicate element\n";

 

 

int main(void)

{

static const char str[] = "Turn on the alarm!\n"; // строка которую будем выводить в порт

Retcode rc;

UartHandle uartH = KDF_INVALID_HANDLE;

 

printf(str); // не сработает т.к. нет vfs

 

rc = UartInit(); // иницилизирует и настраевает UART для работы на прием и передачу с заданной скоростью, проверкой четности и 8-ми битным форматом данных с одним стоповым битом

 

if (rc != UART_OK) { // если в com-порт пришло недоступное значение, то выводим ошибку

printf("UartInit() failed\n"); // выводит в интерфейс

printk("UartInit() failed\n"); // выводит в журнал

return EXIT_FAILURE;

}

 

rc = UartOpenPort(PORT_NAME, &uartH); // открываем порт PORT_NAME

 

if (rc != UART_OK) { // если пришло недоступное значение, то выводим ошибку

printf("UartOpenPort() %s failed\n", PORT_NAME); // выводит в интерфейс

printk("UartOpenPort() %s failed\n", PORT_NAME); // выводит в журнал

return EXIT_FAILURE;

}

 

rtl_size_t i; // (записываем в переменную i значение из порта )

 

for (i = 0; i < rtl_countof(str4) - 1; ++i) // посылаем в порт сообщение из str4

UartWriteByte(uartH, (uint8_t)str4[i]);

printf("The message from str has been sent to the port\n", PORT_NAME); // выводит в интерфейс

 

return EXIT_SUCCESS;

 

if (rc == '1') // если пришла 1

{

printf("ALARM! WATER!\n", UART1_RX_PIN); // выводит в интерфейс

printk("ALARM! WATER!\n", UART1_RX_PIN); // выводит в журнал

 

/* Open port. */

rc = UartOpenPort(UART1_RX_PIN, &uartH); // открываем порт UART1

rtl_size_t i;

for (i = 0; i < rtl_countof(str) - 1; ++i) // посылаем в порт сообщение из str

UartWriteByte(uartH, (uint8_t)str[i]);

printf("The message from str has been sent to the port\n", UART1_RX_PIN); // выводит в интерфейс

 

return EXIT_SUCCESS;

 

rc = UartOpenPort(UART1_RX_PIN, &uartH); // открываем порт UART1_RX_PIN

 

for (i = 0; i < rtl_countof(str3) - 1; ++i) // посылаем в порт сообщение из str3

UartWriteByte(uartH, (uint8_t)str3[i]);

printf("The message from str has been sent to the port\n", UART1_RX_PIN); // выводит в интерфейс

 

rc = UartOpenPort(UART2_TX_PIN, &uartH); // открываем порт UART2_TX_PIN дублирующий

// rtl_size_t i;

for (i = 0; i < rtl_countof(str2) - 1; ++i) // посылаем в порт сообщение из str2

UartWriteByte(uartH, (uint8_t)str2[i]);

printf("The message from str2 has been sent to the port\n", UART2_TX_PIN); // выводит в интерфейс

 

return EXIT_SUCCESS;

 

 

}

 

if (rc == '2') // если пришла 2

{

printf("ALARM! GAS!\n", UART3_RX_PIN); // выводит в интерфейс

printk("ALARM! GAS!\n", UART3_RX_PIN); // выводит в журнал

 

/* Open port. */

rc = UartOpenPort(UART3_RX_PIN, &uartH); // открываем порт UART3_RX_PIN

rtl_size_t i;

for (i = 0; i < rtl_countof(str) - 1; ++i) // посылаем в порт сообщение из str

UartWriteByte(uartH, (uint8_t)str[i]);

printf("The message from str has been sent to the port\n", UART3_RX_PIN ); // выводит в интерфейс

 

return EXIT_SUCCESS;

 

rc = UartOpenPort(UART3_RX_PIN, &uartH); // открываем порт UART3_RX_PIN

 

for (i = 0; i < rtl_countof(str3) - 1; ++i) // посылаем в порт сообщение из str3

UartWriteByte(uartH, (uint8_t)str3[i]);

printf("The message from str has been sent to the port\n", UART3_RX_PIN); // выводит в интерфейс

 

 

return EXIT_SUCCESS;

rc = UartOpenPort(UART4_TX_PIN, &uartH); // открываем порт UART4_TX_PIN дублирующий

 

for (i = 0; i < rtl_countof(str2) - 1; ++i) // посылаем в порт сообщение из str2

UartWriteByte(uartH, (uint8_t)str2[i]);

printf("The message from str2 has been sent to the port\n", UART4_TX_PIN); // выводит в интерфейс

 

}

 

if (rc == '3') // если пришла 3

{

printf("ALARM! FIRE!\n", UART5_RX_PIN); // выводит в интерфейс

printk("ALARM! FIRE!\n", UART5_RX_PIN); // выводит в журнал

 

rc = UartOpenPort(UART5_RX_PIN , &uartH); // открываем порт UART5_RX_PIN

rtl_size_t i;

for (i = 0; i < rtl_countof(str) - 1; ++i) // посылаем в порт сообщение из str

UartWriteByte(uartH, (uint8_t)str[i]);

printf("The message from str has been sent to the port\n", UART5_RX_PIN ); // выводит в интерфейс

return EXIT_SUCCESS;

 

rc = UartOpenPort(UART5_RX_PIN, &uartH); // открываем порт UART5_RX_PIN

for (i = 0; i < rtl_countof(str3) - 1; ++i) // посылаем в порт сообщение из str3

UartWriteByte(uartH, (uint8_t)str3[i]);

printf("The message from str has been sent to the port\n", UART5_RX_PIN); // выводит в интерфейс

}

if (rc == '4') // если пришла 4

{

printf("THE SYSTEM HAS BEEN RESTORED!\n", UART6_TX_PIN); // выводит в интерфейс

printk("THE SYSTEM HAS BEEN RESTORED!\n", UART6_TX_PIN); // выводит в журнал

 

rc = UartOpenPort(UART2_TX_PIN , &uartH); // открываем порт UART2_TX_PIN

rtl_size_t i;

for (i = 0; i < rtl_countof(str5) - 1; ++i) // посылаем в порт сообщение из str 5

UartWriteByte(uartH, (uint8_t)str[i]);

printf("The message from str has been sent to the port\n", UART2_TX_PIN ); // выводит в интерфейс

return EXIT_SUCCESS;

 

}

if (rc == '5') // если пришла 5

{

printf("THE SYSTEM HAS BEEN RESTORED!\n", UART6_TX_PIN); // выводит в интерфейс

printk("THE SYSTEM HAS BEEN RESTORED!\n", UART6_TX_PIN); // выводит в журнал

 

rc = UartOpenPort(UART4_TX_PIN , &uartH); // открываем порт UART4_TX_PIN

rtl_size_t i;

for (i = 0; i < rtl_countof(str5) - 1; ++i) // посылаем в порт сообщение из str 5

UartWriteByte(uartH, (uint8_t)str[i]);

printf("The message from str has been sent to the port\n", UART2_TX_PIN ); // выводит в интерфейс

return EXIT_SUCCESS;

 

}

if (rc == '6') // если пришла 6

{

printf("THE SYSTEM HAS BEEN RESTORED!\n", UART6_TX_PIN); // выводит в интерфейс

printk("THE SYSTEM HAS BEEN RESTORED!\n", UART6_TX_PIN); // выводит в журнал

 

rc = UartOpenPort(UART5_RX_PIN , &uartH); // открываем порт UART5_RX_PIN

rtl_size_t i;

for (i = 0; i < rtl_countof(str5) - 1; ++i) // посылаем в порт сообщение из str 5

UartWriteByte(uartH, (uint8_t)str[i]);

printf("The message from str has been sent to the port\n", UART5_RX_PIN ); // выводит в интерфейс

return EXIT_SUCCESS;

 

}

 

 

}
