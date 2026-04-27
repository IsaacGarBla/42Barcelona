*Este proyecto ha sido creado como parte del currículo de 42 por igarcia-.*

# ft_printf

## Descripción
El proyecto **ft_printf** consiste en reprogramar la función `printf` de la biblioteca estándar de C (`libc`). El objetivo principal es crear una función versátil capaz de gestionar argumentos variables mediante el uso de **funciones variádicas** (`va_list`). A través de este reto, se profundiza en el análisis de cadenas de formato y la conversión de diferentes tipos de datos a texto plano de salida.

## Especificaciones Técnicas

### 1. Tipos de Datos (Especificadores)

En el proyecto base, se gestionan los siguientes tipos de datos:

| Especificador | Descripción |
| :--- | :--- |
| `%c` | Imprime un único carácter. |
| `%s` | Imprime una cadena de caracteres (string). |
| `%p` | Imprime un puntero `void *` en formato hexadecimal. |
| `%d` / `%i` | Imprime un número entero con signo en base 10. |
| `%u` | Imprime un número decimal sin signo en base 10. |
| `%x` | Imprime un número hexadecimal (base 16) en minúsculas. |
| `%X` | Imprime un número hexadecimal (base 16) en mayúsculas. |
| `%%` | Imprime el símbolo del porcentaje literal. |

### 2. Flags (Modificadores)

Como bonus, se gestionan los siguientes flags que modifican como se muestran los datos en la pantalla.

| Flag | Descripción |
| :---: | :--- |
| `-` | Justifica a la izquierda el resultado dentro del ancho de campo dado. |
| `0` | Rellena con ceros a la izquierda en lugar de espacios. |
| `.` | Define la precisión (dígitos mínimos en números o max. caracteres en strings). |
| `#` | Formato alternativo: antepone `0x`/`0X` a hexadecimales no nulos. |
| `+` | Fuerza la impresión del signo (+ o -) para valores numéricos. |
| ` ` (espacio) | Si no hay signo, inserta un espacio en blanco antes de valores positivos. |

#### 2.1 Matriz de Compatibilidad (Flags vs Tipos)

No todos los flag afectan a todos los tipos de datos. La siguiente matriz muestra qué flags afectan a cada uno de ellos:

| Flag | %c | %s | %p | %d / %i | %u | %x / %X |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| `-` | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| `0` | ❌ | ❌ | ❌ | ✅ | ✅ | ✅ |
| `.` | ❌ | ✅ | ❌ | ✅ | ✅ | ✅ |
| `#` | ❌ | ❌ | ❌ | ❌ | ❌ | ✅ |
| `+` | ❌ | ❌ | ❌ | ✅ | ❌ | ❌ |
| ` ` | ❌ | ❌ | ❌ | ✅ | ❌ | ❌ |

## Instrucciones

### Automatización con Makefile
El proyecto incluye un `Makefile` que gestiona la compilación de la librería y su dependencia con `libft`. A continuación se detalla su contenido principal:

```makefile
NAME = libftprintf.a

# Directories
SRC_DIR = ./srcs
INC_DIR = ./includes
OBJ_DIR = ./objs
LIBFT_DIR = ./libft
LIBFT   = $(LIBFT_DIR)/libft.a 

# File sources
MY_SOURCES = ft_printf.c ft_printf_c.c ft_printf_s.c ft_printf_di.c \
             ft_printf_p.c ft_printf_u.c ft_printf_x.c ft_printnbr_f.c \
             ft_putnchar.c
				
SRCS	= $(addprefix $(SRC_DIR)/, $(MY_SOURCES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(MY_SOURCES:.c=.o))

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		cp $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJS)

$(LIBFT):
		make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -fPIC -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)
		@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME)
		@$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re
```
### Compilación y Uso

Para generar la biblioteca `libftprintf.a` (que incluye la biblioteca `libft`) basta que una vez clonado el repositorio que contiene los fuentes ejecutes el comando make.

1. Para compilar la librería:
   ```bash
   make
   ```
2. Para usarla en tu código:
   ```c
   #include "includes/ft_printf.h"
   ```
3. Para compilar tu programa principal vinculando la librería:
   ```bash
   cc main.c libftprintf.a -o mi_programa
   ```
4. Incluye el encabezado en tu archivo fuente y enlaza la librería al compilar:
   ```c
   #include "ft_printf.h"
   ```
   ```bash
   cc main.c libftprintf.a -o mi_programa
   ```
## Elección de Algoritmo y Estructura de Datos
Se ha implementado un **parsing secuencial** de la cadena. Al detectar un `%`, un motor de búsqueda identifica flags, ancho de campo y el especificador final.

Se utiliza **recursividad** para las conversiones numéricas de bases (10 y 16), lo que permite imprimir los dígitos en el orden correcto sin necesidad de buffers temporales adicionales, optimizando el uso de la memoria al aprovechar la pila de llamadas.

## Recursos

### Referencias
- Comando ```man``` del sistema operativo.
- [Documentación oficial de printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Guía de funciones variádicas en C (va_start, va_arg)](https://en.cppreference.com/w/c/variadic)

### Uso de IA
Se ha utilizado IA para las siguientes tareas:
- **Consulta funcionamiento de los flags:** Explicación en detalle de como afecta cada uno de los flag a los diferentes tipos de datos.
- **Evaluación del comportamiento de los flags:** Uso de ejemplos para ver, de forma rápida y sin programar código, el resultado de aplicar uno o varios flag a los diferentes tipos de datos.
- **Maquetación del README:** Organización de tablas y estructura de Markdown según las normas específicas del currículo de 42.



