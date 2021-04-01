# Printf
> _printf is a custom implementation of the native C printf function. This version of printf prints strings, characters and numbers. It will print a reversed string, numbers in binary, and will also encode strings in rot13.

## Environment
Printf was developed and tested with `Ubuntu 14.04 LTS`

#### Example main.c and output
```
#include "headerfile.h"

int main(void)
{
	_printf("Hello %s\n", "World");
	return (0);
}
=========================================
$ gcc -Wall -Wextra -Werror -pedantic -Wno-format *.c *.h -o printf
$ ./printf
$ Hello World
$
```

#### Key:

% +

- c - char
- d - digit
- i - integers
- b - binary
- s - string
- r - reverse string
- R - rot13 string

## File Contents

|   **File**   |   **Description**   |
| -------------- | --------------------- |
| \_printf.c | The printf function |
| headerfile.h   | Header file containing all function prototypes and struct declarations |
| printfunctions.c  | File containing main print functions |
| advancedfuncs.c | File containing additional print functions |

## Function Descriptions
| **Function** | **Description** |
| -------------- | ----------------- |
|int print(char c)| Writes a character to stdout|
|int printstring(va_list list)|Prints strings|
|int printchar(va_list list)|Prints a character|
|int printint(va_list list)|Prints integers|
|int printbinary(va_list)|Prints numbers in binary|
|int printrev(va_list list)|Prints a reverse string|
|int printrot13(va_list)|Prints strings in rot13|
