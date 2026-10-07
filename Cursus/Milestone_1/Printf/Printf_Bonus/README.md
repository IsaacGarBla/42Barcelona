*Este proyecto ha sido creado como parte del currículo de 42 por igarcia-.*

# ft_printf

## Descripción
El proyecto ft_printf consiste en reprogramar la función printf de la biblioteca estándar de C (libc). El objetivo principal es crear una función versátil capaz de gestionar argumentos variables mediante el uso de funciones variádicas (`va_list`). A través de este reto, se profundiza en el análisis de cadenas de formato y la conversión de diferentes tipos de datos a texto plano de salida.

---

## Especificaciones Técnicas

### 1. Parte Obligatoria: Tipos de Datos (Especificadores)
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

### 2. Parte Bonus: Flags (Modificadores)
La versión bonus gestiona cualquier combinación de los siguientes flags, los cuales modifican drásticamente el formato de la salida en pantalla:


| Flag | Descripción |
| :--- | :--- |
| `-` | Justifica a la izquierda el resultado dentro del ancho de campo dado. |
| `0` | Rellena con ceros a la izquierda en lugar de espacios. |
| `.` | Define la precisión (dígitos mínimos en números o máx. caracteres en strings). |
| `#` | Formato alternativo: antepone `0x` / `0X` a hexadecimales no nulos. |
| `+` | Fuerza la impresión del signo (`+` o `-`) para valores numéricos. |
| ` ` *(espacio)* | Si no hay signo, inserta un espacio en blanco antes de valores positivos. |

#### 2.1 Matriz de Compatibilidad (Flags vs Tipos)
No todos los flags afectan a todos los tipos de datos. La siguiente matriz detalla el comportamiento exacto implementado:


| Flag | `%c` | `%s` | `%p` | `%d` / `%i` | `%u` | `%x` / `%X` |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **-** | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| **0** | ❌ | ❌ | ❌ | ✅ | ✅ | ✅ |
| **.** | ❌ | ✅ | ❌ | ✅ | ✅ | ✅ |
| **#** | ❌ | ❌ | ❌ | ❌ | ❌ | ✅ |
| **+** | ❌ | ❌ | ❌ | ✅ | ❌ | ❌ |
| *(espacio)* | ❌ | ❌ | ❌ | ✅ | ❌ | ❌ |

---

## Instrucciones y Automatización

El proyecto incluye un `Makefile` preparado para compilar tanto la versión obligatoria como la versión bonus de forma independiente y automatizada.

### Makefile
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

#### 1. Versión Estándar (Obligatoria)
Para generar la biblioteca base sin flags adicionales:
```bash
make
```
Incluye la cabecera correspondiente en tu código:
```c
#include "ft_printf.h"
```

#### 2. Versión con Bonus (Flags avanzados)
Para incluir la lógica completa de gestión de flags y modificadores avanzados:
```bash
make bonus
```
Incluye la cabecera específica del bonus en tu código:
```c
#include "ft_printf_bonus.h"
```

#### Vinculación del ejecutable
Para compilar tu programa principal enlazando la librería generada:
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o mi_programa
```

---

## Elección de Algoritmo y Estructura de Datos
Se ha implementado un parsing secuencial de la cadena. Al detectar un `%`, un motor de búsqueda identifica secuencialmente los flags repetidos, el ancho de campo mínimo, la precisión (`.`) y, finalmente, el especificador de tipo de dato.

Se utiliza recursividad para las conversiones numéricas de bases (10 y 16). Esto permite imprimir los dígitos en el orden correcto sin necesidad de recurrir a buffers temporales dinámicos adicionales de almacenamiento, optimizando estrictamente el uso de la memoria al aprovechar la pila de llamadas del sistema.

---

## Recursos

### Referencias
- Comando `man` del sistema operativo.
- Documentación oficial de `printf(3)`.
- Guía de funciones variádicas en C (`va_start`, `va_arg`, `va_copy`, `va_end`).

### Uso de IA
Se ha utilizado IA para las siguientes tareas:
- **Consulta de funcionamiento de los flags:** Explicación en detalle de cómo afecta cada uno de los flags a los diferentes tipos de datos según el estándar POSIX.
- **Evaluación del comportamiento:** Uso de ejemplos y casos límite (*edge cases*) de combinaciones conflictivas de flags para predecir el resultado en la salida.
- **Maquetación del README:** Organización estructural del Markdown y diseño de las tablas funcionales.


