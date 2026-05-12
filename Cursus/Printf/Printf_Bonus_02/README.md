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
El proyecto incluye un `Makefile` que gestiona la compilación de la librería y su dependencia con `libft`. A continuación se detalla su contenido principal, incluyendo las reglas `name` y `bonus`.

```makefile
NAME = libftprintf.a

# Directories
SRC_DIR = ./src
INC_DIR = ./include
SRC_DIR_BONUS = ./src_bonus
INC_DIR_BONUS = ./include_bonus
OBJ_DIR = ./objs
OBJ_DIR_BONUS = ./objs_bonus
LIB_DIR = ./lib
LIBFT   = ./libft/libft.a 
LIBFT_DIR = ./libft

# File sources to compile
MY_SOURCES =	ft_printf.c \
				ft_printf_c.c \
				ft_printf_s.c \
				ft_printf_di.c \
				ft_printf_p.c \
				ft_printf_u.c \
				ft_printf_x.c \
				ft_printnbr_f.c \
				ft_putnchar.c

MY_SOURCES_BONUS = 	ft_printf_bonus.c \
					ft_printf_c_bonus.c \
					ft_printf_s_bonus.c \
					ft_printf_di_bonus.c \
					ft_printf_p_bonus.c \
					ft_printf_u_bonus.c \
					ft_printf_x_bonus.c \
					ft_printnbr_f_bonus.c \
					ft_putnchar_bonus.c

# Add directory prefix to the sources and objects
SRCS	= $(addprefix $(SRC_DIR)/, $(MY_SOURCES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(MY_SOURCES:.c=.o))

SRCS_BONUS	= $(addprefix $(SRC_DIR_BONUS)/, $(MY_SOURCES_BONUS))
OBJS_BONUS	= $(addprefix $(OBJ_DIR_BONUS)/, $(MY_SOURCES_BONUS:.c=.o))

#Compiler and flags
CC		= cc
CFLAGS	= -Wall -Werror -Wextra  -gdwarf-4 -I$(LIBFT_DIR)

all: $(NAME)

#Create the library
$(NAME): $(LIBFT) $(OBJS) Makefile
		cp $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJS)

bonus:	$(LIBFT) $(OBJS_BONUS)
		cp $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJS_BONUS)

$(LIBFT):
		make -C $(LIBFT_DIR)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -I$(INC_DIR) -fPIC -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
		@mkdir -p $(OBJ_DIR_BONUS)
		$(CC) $(CFLAGS) -I$(INC_DIR_BONUS) -fPIC -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)
		rm -rf $(OBJ_DIR_BONUS)
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
   #include "ft_printf.h"
   ```
3. Para compilar tu programa principal vinculando la librería:
   ```bash
   cc -I$(libdir) main.c libftprintf.a -o mi_programa
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



