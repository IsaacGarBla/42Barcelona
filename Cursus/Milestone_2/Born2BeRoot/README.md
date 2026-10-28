*Este proyecto ha sido creado como parte del plan de estudios de 42 por igarcia-.*

# Born2beRoot

# Índice

- [1. Descripción](#1-descripción)
  - [1.1 Principales decisiones de diseño](#11-principales-decisiones-de-diseño)
    - [1.1.1 Entorno de virtualización](#111-entorno-de-virtualización)
    - [1.1.2 Sistema operativo elegido](#112-sistema-operativo-elegido)
    - [1.1.3 Particionado](#113-particionado)
    - [1.1.4 Elección del firewall](#114-elección-del-firewall)

- [2. Implementación](#2-implementación)
  - [2.1 Creación de la Máquina Virtual](#21-creación-de-la-máquina-virtual)
  - [2.2 Instalación de Debian](#22-instalación-de-debian)
    - [2.2.1 Particionado](#221-particionado)
    - [2.2.2 Gestor de paquetes](#222-gestor-de-paquetes)
    - [2.2.3 GRUB Boot Loader](#223-grub-boot-loader)
    - [2.2.4 Instalación del resto de servicios](#224-instalación-del-resto-de-servicios)
    - [2.2.5 SUDO y grupos de usuarios](#225-sudo-y-grupos-de-usuarios)
    - [2.2.6 SSH](#226-ssh)
    - [2.2.7 Instalación de UFW](#227-instalación-de-ufw)
    - [2.2.8 Aplicación de políticas de seguridad](#228-aplicación-de-políticas-de-seguridad)
    - [2.2.9 Monitoring.sh y Crontab](#229-monitoringsh-y-crontab)

- [3. Bonus part](#3-bonus-part)
  - [3.1 Instalación de Lighttpd](#31-instalación-de-lighttpd)
  - [3.2 Instalación de WordPress](#32-instalación-de-wordpress)
  - [3.3 Instalación de MariaDB](#33-instalación-de-mariadb)
  - [3.4 Instalación de PHP](#34-instalación-de-php)
  - [3.5 Configuración de WordPress](#35-configuración-de-wordpress)
  - [3.6 Instalación de un servidor Web adicional: NGINX](#36-instalación-de-un-servidor-web-adicional-nginx)
    - [3.6.1 ¿Qué servidor instalar?](#361-qué-servidor-instalar)
    - [3.6.2 Instalación de NGINX](#362-instalación-de-nginx)

- [4. Comparativas Técnicas](#4-comparativas-técnicas)
  - [4.1 Debian vs Rocky Linux](#41-debian-vs-rocky-linux)
  - [4.2 AppArmor vs SELinux](#42-apparmor-vs-selinux)
  - [4.3 UFW vs firewalld](#43-ufw-vs-firewalld)
  - [4.4 VirtualBox vs UTM](#44-virtualbox-vs-utm)

- [5. Recursos](#5-recursos)
  - [5.1 Documentación oficial](#51-documentación-oficial)
  - [5.2 Tutoriales utilizados](#52-tutoriales-utilizados)
  - [5.3 Uso de Inteligencia Artificial](#53-uso-de-inteligencia-artificial)

# 1. Descripción

Born2beRoot es un proyecto de Administración de Sistemas que forma parte del itinerario de 42 cuyo objetivo es introducir los conceptos fundamentales de virtualización, gestión de servidores Linux y securización de sistemas.

El proyecto consiste en instalar y configurar una máquina virtual utilizando VirtualBox o UTM, implementando una serie de requisitos relacionados con la gestión de usuarios, políticas de contraseñas, configuración de SSH, firewall, sudo, LVM y monitorización del sistema.

A través de este proyecto se adquieren conocimientos prácticos sobre la administración de sistemas Linux, una habilidad esencial en entornos profesionales de infraestructura y ciberseguridad.

## 1.1 Principales decisiones de diseño

### 1.1.1 Entorno de virtualización 

Tal y como se indica en el *subject*, el entorno de virtualización utilizado para desarrollar el proyecto es VirtualBox.

### 1.1.2 Sistema operativo elegido

Para este proyecto se ha elegido **Debian** como sistema operativo principal.

Debian es una distribución GNU/Linux reconocida por su estabilidad, seguridad y enorme comunidad de usuarios. Además, el propio enunciado recomienda Debian para estudiantes que se inician en la administración de sistemas. 【1-4352b3】

| Ventajas | Desventajas |
|----------------|---------|
| Gran estabilidad<BR>Amplia documentación<BR>Comunidad muy activa<BR>Fácil aprendizaje para principiantes<BR>Excelente gestión de paquetes mediante APT|Algunos paquetes pueden no estar tan actualizados como en otras distribuciones<BR>Menor orientación al entorno empresarial que Rocky Linux

Su elección se justifica por:

| Motivo | Detalle |
|----------|---------|
| Facilidad de uso | Más adecuado para iniciarse en Linux |
| Documentación | Gran cantidad de recursos disponibles |
| Estabilidad | Excelente para servidores |
| Comunidad | Una de las mayores comunidades Linux |
| Compatibilidad | Integración sencilla de AppArmor, UFW y SSH |
| Recomendación del proyecto | Recomendado explícitamente para principiantes |

### 1.1.3 Particionado

El disco se ha configurado, con la previsión de implementar el BONUS, utilizando:

- LVM (Logical Volume Manager).
- Particiones cifradas.
- Separación lógica de datos del sistema.

Esta configuración permite:

- Mayor flexibilidad para ampliar volúmenes.
- Mejor organización del almacenamiento.
- Mayor seguridad gracias al cifrado.

### 1.1.4 Elección del firewall

Se ha elegido Uncomplicated FireWall por ser, de las opciones propuestas, la de menor complejidad para alguien que se inicia en la configuración de este tipo de tecnología.

 Motivo | Detalle |
|----------------|-----|
| Facilidad de uso | Muy alta debido a su sencillez |
| Gestión de reglas | Simple gestión de reglas | 
| Curva de aprendizaje | Baja, ideal para iniciarse |

# 2. Implementación

## 2.1 Creación de la Máquina Virtual

Se crea una máquina desde el entorno gráfico de VirtualBox con las siguientes características:

- Nombre: **Born2beroot**
- Carpeta: **/home/igarcia-/sgoinfre/igarcia-/VirtualBox VMs**
- Imagen ISO: **No seleccionada**
- Tipo: **Linux**
- Versión: **Debian (64 bit)**
- Memoria base: **2048 Mb**
- Procesadores: **2**
- Disco Virtual: **30Gb**

En un paso posterior, se asocia la imagen ISO de Debian mínima necesaria para la instalación (descargable desde https://www.debian.org/distrib/netinst).

## 2.2 Instalación de Debian

Una vez creada la máquina virtual, procedemos a la instalación de Debian, seleccionando **Install**, con las siguientes  características:

- Idioma: **English**
- País: **España**
- Configuración local: **EE. UU. (no existe la opción de seleccionar España)**
- Distribución de teclado: **America English**
- Hostname: **igarcia-**
- Nombre de dominio: **vacío**
- Contraseña de root: **<*root_pass*>**
- Nombre de la cuenta de usuario: **igarcia-**
- Usuario cuenta: **igarcia-**
- Contraseña usuario: **<*user_pass*>**
- Zona temporal: **Madrid**

### 2.2.1 Particionado

Crearemos las siguientes particiones para obtener la estructura siguiente:

- Partición primaria.
- Partición lógica.
  - Volumen encriptado
  - Configuración del LVM.
  - Creación del grupo de volúmenes
  - Creación de 7 volúmenes lógicos.

```text
/dev/sda
├── /dev/sda1                  → /boot (500 Mb)
├── /dev/sda2
└── /dev/sda5
    └── /dev/mapper/sda5_crypt
        ├── LVMGroup-root      → /        (10 Gb)
        ├── LVMGroup-swap      → [SWAP]   (2.3 Gb)
        ├── LVMGroup-home      → /home    (5 Gb)
        ├── LVMGroup-var       → /var     (3 Gb)
        ├── LVMGroup-srv       → /srv     (3 Gb)
        ├── LVMGroup-tmp       → /tmp     (3 Gb)
        └── LVMGroup-var--log  → /var/log (4 Gb)
```
### 2.2.2 Gestor de paquetes

Se configura el gestor de paquetes (Package Manager) con:

- Mirror Country: **Spain**
- Debian Archive Mirror: **deb.debian.org**
- HTTP Proxy: **Ninguno**
- Selección de software: **Instalación mínima, desmarcamos todas las opciones**

### 2.2.3 GRUB Boot Loader

Necesario para el arranque, en este último paso indicaremos **Sí**, seleccionando el único disco disponible (la partición primaria que creamos en pasos anteriores) y el sistema estará listo para reiniciarse y arrancar Debian.

### 2.2.4 Instalación del resto de servicios

Arrancamos Debian en la máquina virtual (MV) y nos identificamos con el usuario/pass que hemos introducido durante la instalación inicial (igarcia-/<*passw*>).

### 2.2.5 SUDO y grupos de usuarios

Procedemos a la instalación de SUDO con el siguiente comando:

```bash
apt install sudo
```

Tras la instalación, reiniciamos la máquina virtual.

```text
sudo reboot
```

Verificamos la instalación, adquiriendo rol de root (nos solicitará la contraseña de root creada durante la instalación inicial) y consultando la versión instalada.

```bash
su (pas)
sudo -V
```

Creamos un grupo de usuarios

```bash
sudo addgroup user42
```

Podemos verificar si se ha creado correctamente con el comando:
```bash
sudo getent group user42
```

Añadimos el usuario creado durante la instalación (**igarcia-** en este caso al grupo creado y al grupo sudo)

```bash
sudo adduser igarcia- user42
sudo adduser igarcia- sudo
```

Podemos verificar que las acciones se han realizado correctamente consultando los grupos a los que pertenece el usuario:

```bash
sudo getent group sudo user42
```

### 2.2.6 SSH

Instalamos el servicio SSH con el siguiente comando:

```bash
sudo apt update 
sudo apt install openssh-server
```

Verificamos la instalación:

```bash
sudo service ssh status
```

Configuramos SSH de acuerdo a lo solicitado:

- Cambiar el puerto al 4242 y desactivar root

  ```bash
  su 
  nano /etc/ssh/sshd_config
  ```

  **#Port 22** -> cambiamos por **Port 4242**
  
  **#PermitRootLogin prohibit-password** -> cambiamos por **PermitRootLogin no**

  ```bash
  su 
  nano /etc/ssh/ssh_config
  ```

  **#Port 22** -> cambiamos por **Port 4242**

Reiniciamos el servicio:

```bash
sudo service ssh status
```

Verificamos cambios.

```bash
sudo service ssh status
```

Podemos realizar una prueba, conectando desde el host al anfitrión:

```bash
sudo service ssh status

```bash
ssh igarcia-@localhost -p **puerto**
```

Donde **puerto** será el que tengamos definido en la tabla port forwarding de la máquina virtual.

### 2.2.7 Instalación de UFW

Instalamos el paquete UFW:

```bash
sudo apt install ufw
```

Activamos el firewall:

```bash
sudo ufw enable
```

Permitimos el puerto 4242 (para poder acceder por SSH):

```bash
sudo ufw allow 4242
sudo ufw status
```

### 2.2.8 Aplicación de políticas de seguridad

Políticas SUDO:

Creamos el fichero de configuración y el directorio para almacenar los log tal y como se solicita en el subject:

```bash
touch /etc/sudoers.d/sudo_config
mkdir /var/log/sudo
```

Editamos el fichero que hemos creado:
```bash
nano /etc/sudoers.d/sudo_config
```

Para añadir los siguientes comandos:

```text
Defaults  passwd_tries=3
Defaults  badpass_message="Mensaje de error personalizado"
Defaults  logfile="/var/log/sudo/sudo.log"
Defaults  log_input, log_output
Defaults  iolog_dir="/var/log/sudo"
Defaults  requiretty
Defaults  secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```

Políticas de contraseñas:

Editamos el fichero *login.defs* para definir las comprobaciones básicas:
```bash
nano /etc/login.defs
```

**PASS_MAX_DAYS 99999** -> cambiamos por **PASS_MAX_DAYS 30**
  
**PASS_MIN_DAYS 0** -> cambiamos por **PASS_MIN_DAYS 2**

**PASS_WARN_AGE 7** -> Mantenemos igual

Instalamos la herramienta que nos permitirá reforzar la seguridad de las contraseñas, estableciendo restricciones adicionales:

```bash
sudo apt install libpam-pwquality
```

Editamos la configuración:

```bash
nano /etc/pam.d/common-password
```

Localizamos la línea que contiene "retry=3" y añadimos a continuación:

```text
minlen=10 ucredit=-1 dcredit=-1 lcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```

### 2.2.9 Monitoring.sh y Crontab

De acuerdo con lo descrito en el subject, se implementa un script que se ejecutará regularmente (cada 10') mostrando información del estado del sistema. Concretamente:

- Arquitectura del sistema.
- Número de CPU físicas.
- Número de CPU virtuales.
- Uso de memoria RAM.
- Uso de almacenamiento.
- Carga de CPU.
- Fecha del último reinicio.
- Estado de LVM.
- Conexiones activas.
- Usuarios conectados.
- Dirección IP y MAC.
- Número de comandos ejecutados con sudo.

Para ejecutarlo de forma individual, desde el directorio raíz del usuario:

```bash
./monitoring.sh
```

Para crear una tarea repetitiva que ejecute el script cada 10 minutos, utilizaremos cron y la herramienta Crontab (con privilegios SUDO) para editar . 

Editaremos el archivo de configuración de Crontab:

```bash
sudo crontab -u root -e
o
sudo crontab -e
```

Y añadimos la línea que ejecutará nuestro script:

```text
*/10 * * * * sh /path_to_file.sh
```

Consultar esta guía https://www.hostinger.com/es/tutoriales/sintaxis-crontab/ o la documentación oficial de Debian (https://manpages.debian.org/testing/cron/crontab.5.en.html) para entender cómo hay que crear las líneas en el fichero.

# 3. Bonus part

Para el bonus, instalaremos WordPress y un servidor web adicional, en este caso NGINX.
Además, necesitaremos:

- Lighttpd: servidor web básico
- MariaDB: base de datos de soporte, con una configuración mínima.
- PHP: lenguaje de programación para poder implementar páginas web dinámicas.

## 3.1 Instalación de Lighttpd

Instalamos el paquete:

```bash
sudo apt install lighttpd
```

Abrimos el puerto 80 y verificamos.

```bash
sudo ufw allow 80
sudo ufw status
```

## 3.2 Instalación de WordPress

Necesitaremos la herramienta wget para poder descargar el paquete de WordPress y la herramienta zip para poder descomprimirlo.

```bash
sudo apt install wget zip
```

Nos desplazamos al directorio */var/www*

```bash
cd /var/www
```

Descargamos el archivo de la página oficial de WordPress.

```bash
sudo wget https://wordpress.org/latest.zip
```

Lo descomprimimos. Esto creará una carpeta llamada *wordpress*.

```bash
sudo unzip latest.zip
```

Cambiamos el nombre a la carpeta *html* existente (para no perder el contenido), renombramos la carpeta *wordpress* como *html* (para mantener la configuración por defecto el servidor Web) y ajustamos los permisos:

```bash
sudo mv html/ html_old/
sudo mv wordpress/ html
sudo chmod -R 755 html
```

## 3.3 Instalación de MariaDB

Instalamos el paquete correspondiente a la base de datos MariaDB.

```bash
sudo apt install mariadb-server
```

Ejecutamos un script que incluye el propio paquete para dotar de mayor seguridad a la base de datos (BBDD):

```bash
sudo mariadb_secure_installation
```

Nos hará varias preguntas:

- Switch to unix_socket authentication? → N
- Change the root password? → N
- Remove anonymous users? → Y
- Disallow root login remotely? → Y 
- Remove test database and access to it? → Y 
- Reload privilege tables now? → Y

Una vez instalada, crearemos la BBDD que usará WP, un usuario y le daremos todos los privilegios sobre la BBDD

```bash
sudo mariadb
CREATE DATABASE wp_database;
SHOW DATABASES;
CREATE USER 'igarcia-'@'localhost' IDENTIFIED BY '12345';
GRANT ALL PRIVILEGES ON wp_database.* TO 'igarcia-'@'localhost';
FLUSH PRIVILEGES;
```

## 3.4 Instalación de PHP

Instalamos los paquetes de PHP necesarios:

```bash
sudo apt install php-cgi php-mysql
```

## 3.5 Configuración de WordPress

En el directorio donde hemos dejado WordPress (/var/www/html) creamos un duplicado del archivo de configuración de ejemplo y lo editamos:

```bash
cd /var/www/html
cp wp-config-sample.php wp-config.php
nano wp-config.php
```

Tenemos que cambiar los valores DB_NAME, DB_USER y DB_PASSWORD por los que hemos creado durante la creación de la BBDD:

- DB_NAME=*wp_database*
- DB_USER=*igarcia-*
- DB_PASSWORD=*12345* 

Activamos los módulos *fastcgi* y *fastcgi-php* en Lighttpd para mejorar el rendimiento de las aplicaciones web en general y de las desarrolladas en PHP en particular:

```bash
sudo lighty-enable-mod fastcgi
sudo lighty-enable-mod fastcgi-php
sudo service lighttpd force-reload
```

Por último, accedemos a la página de administración de WordPress para terminar la configuración:


```text
http://localhost:puerto/wp-admin/
```

> [!NOTA]
> El valor de *puerto* dependerá de la configuración de Port Forwarding que se haya realizado en la VirtualBox para esta máquina virtual. En este caso, se ha elegido el *8080() para derivarlo al puerto 80 donde está escuchando el servidor. 

## 3.6 Instalación de un servidor Web adicional: NGINX

### 3.6.1 ¿Qué servidor instalar?

Para elegir qué servidor Web instalar, se revisan las principales características de Apache, NGINX y LiteSpeed.


| Servidor Web | Ventajas principales | Desventajas principales | Consumo de recursos |
|--------------|---------------------|-------------------------|---------------------|
| **NGINX** | • Arquitectura asíncrona ultra eficiente frente a tráfico masivo.<br>• Excelente rendimiento como proxy inverso y balanceador de carga.<br>• Consumo de RAM muy optimizado y constante. | • Configuración de reglas dinámicas más compleja.<br>• No soporta archivos de configuración por carpeta como `.htaccess`.<br>• Curva de aprendizaje inicial ligeramente más alta. | **Bajo** |
| **Apache2** | • Máxima flexibilidad y compatibilidad gracias a sus módulos.<br>• Soporte nativo para archivos `.htaccess` (configuración por carpeta).<br>• Enorme comunidad y abundante documentación en Internet. | • Su arquitectura basada en procesos consume más memoria RAM.<br>• El rendimiento puede degradarse ante picos elevados de tráfico o ataques DDoS. | **Alto** |
| **LiteSpeed** | • Velocidad muy elevada y optimización nativa para WordPress mediante LSCache.<br>• Reemplazo directo de Apache, compatible con archivos `.htaccess`.<br>• Gestión moderna de recursos basada en eventos. | • Software comercial que requiere licencia para aprovechar todas sus funcionalidades.<br>• La versión gratuita (OpenLiteSpeed) presenta limitaciones de configuración automática. | **Bajo** |


Se ha elegido NGINX por dos razones fundamentales:

1. Arquitectura de Proxy Inverso: Al configurar NGINX en el puerto público (80/443) actuando como escudo, este puede recibir las peticiones web y redirigirlas internamente a tu instalación actual de Lighttpd (reubicada en un puerto interno como el 8080). Es lo más parecido a un entorno real y profesional.
2. Rendimiento y consumo de recursos, aspecto que cobra especial relevancia al tratarse de una máquina virtual. 

### 3.6.2 Instalación de NGINX

Primero de todo, modificamos el servidor existente (lighttpd) para que pase a escuchar en el puerto 8080 en lugar del 80, que será el que configuraremos para NGINX.

Lo haremos editando el fichero de configuración y reiniciando el servicio:

```bash
sudo nano /etc/lighttpd/lighttpd.conf
...
Cambiamos server.port = 80 por server.port = 8080
...
sudo systemctl restart lighttpd
```

Comprobamos que ufw tiene permitido el puerto 8080 y, en caso contrario, lo permitimos.

```bash
sudo ufw status verbose 
```

A continuación, instalamos el paquete que contiene el servidor NGINX y comprobamos que está activo:

```bash
sudo apt update 
sudo apt install nginx -y
sudo systemctl status nginx
```

Configuramos NGINX como proxy inverso hacia el servidor lighttpd sobre el que está instalado nuestro WordPress.

```bash
sudo nano /etc/nginx/sites-available/default
```

Configuramos NGINX para que actúe como proxy y envíe al servidor los parámetros necesarios:

```text
location / {
        proxy_pass http://127.0.0.1:8080;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded-for;
        proxy_set_header X-Forwarded-Proto $scheme;
        proxy_set_header X-Forwarded-Port $server_port;
        proxy_set_header X-Forwarded-Host $http_host;

```

- **proxy_pass** -> envía todo a la dirección indicada.
- **proxy_set_header Host $host** -> pasa al servidor lighttpd el dominio solicitado.
- **proxy_set_header X-Real-IP $remote_addr** -> pasa la dirección IP origen de la petición; 
- **proxy_set_header X-Forwarded-For $proxy_add_x_forwarded-for** -> incluye la IP en una lista de direcciones por las que ha pasado esta petición, para mejorar la seguridad.
- **proxy_set_header X-Forwarded-Proto $scheme** -> indica a lighttpd si se trata de una petición HTTP o HTTPS.
- **proxy_set_header X-Forwarded-Port $server_port** -> indica a lighttpd el puerto desde el que se ha realizado la petición.
- **proxy_set_header X-Forwarded-Host $http_host** -> indica a lighttpd el host *completo* desde el que se ha realizado la petición, incluyendo el puerto.

> [!NOTA]
> Se puede utilizar el comando **sudo nginx -t** para validar que el fichero de configuración es correcto.

Por último, incluimos en la configuración de WordPress las líneas necesarias para que toda redirección se haga al puerto correcto:


```bash
sudo nano /etc/www/html/wp-config.php
```

Al inicio del archivo:

```php
if (isset($_SERVER['HTTP_X_FORWARDED_HOST'])) {
    $_SERVER['HTTP_HOST'] = $_SERVER['HTTP_X_FORWARDED_HOST'];
} 

define('WP_HOME', 'http://' . $_SERVER['HTTP_HOST']);
define('WP_SITEURL', 'http://' . $_SERVER['HTTP_HOST']);
```

Y verificamos que podemos acceder al servicio de WordPress:

```text
http://localhost:puerto/wp-admin/
```

Donde puerto será el que tengamos configurado en el port forwarding de la máquina virtual.

# 4. Comparativas Técnicas

## 4.1 Debian vs Rocky Linux

La principal ventaja de Debian frente a Rocky Linux, y el motivo de su elección es su universalidad, su gran cantidad de software disponible, su sencillez (comparado con Rocky Linux) y la gran cantidad de documentación disponible.
En contra, es un sistema más conservador y si se requiere compatibilidad con hardware muy moderno puede ser difícil su implementación. En este punto, Rocky Linux cuenta con la ventaja del desarrollo empresarial del ciclo de Red Hat Enterprise Linux.

| Característica | Debian (Stable) | Rocky Linux |
|----------------|-----------------|-------------|
| Origen / Filosofía | 100% comunitario e independiente | Clon empresarial respaldado por el ecosistema RHEL |
| Paquetería | `.deb`<br>Gestor: `apt` | `.rpm`<br>Gestores: `dnf` / `yum` |
| Seguridad por defecto | Basada en permisos estándar y AppArmor | Más estricta gracias a `SELinux` activado por defecto |
| Consumo de recursos | Muy ligero<br>Ideal para VPS y máquinas con pocos recursos | Ligero, aunque requiere algo más de recursos base |
| Público objetivo | Usuarios generales y administradores | Entornos empresariales |
| Facilidad de aprendizaje | Alta | Media |
| Estabilidad | Muy alta | Muy alta |
| Documentación | Muy abundante | Muy orientada a entornos empresariales |
| Ventaja principal | Sencillez y comunidad | Compatibilidad empresarial |
| Desventaja principal | Software algo más conservador | Mayor complejidad inicial |

## 4.2 AppArmor vs SELinux

| Característica | AppArmor | SELinux |
|----------------|-----------|----------|
| Modelo de seguridad | Basado en perfiles | Basado en políticas y contextos |
| Configuración | Sencilla | Compleja |
| Curva de aprendizaje | Baja | Alta |
| Distribuciones principales | Debian y Ubuntu | Rocky, Fedora y RHEL |
| Granularidad | Media | Muy alta |
| Flexibilidad | Moderada | Elevada |
| Ventaja principal | Fácil administración | Máximo nivel de control |
| Desventaja principal | Menor capacidad de personalización | Configuración más difícil |

## 4.3 UFW vs firewalld

| Característica | UFW | firewalld |
|----------------|-----|-----------|
| Distribuciones habituales | Debian y Ubuntu | Rocky, Fedora y RHEL |
| Facilidad de uso | Muy alta | Media |
| Gestión de reglas | Simple | Basada en zonas y servicios |
| Configuración dinámica | No | Sí |
| Curva de aprendizaje | Baja | Media |
| Ventaja principal | Sencillez | Flexibilidad |
| Desventaja principal | Menos funcionalidades avanzadas, no es un servicio| Mayor complejidad |

## 4.4 VirtualBox vs UTM

| Característica | VirtualBox | UTM |
|----------------|------------|-----|
| Plataforma principal | Windows, Linux y macOS | macOS |
| Compatibilidad Apple Silicon | Limitada | Excelente |
| Popularidad | Muy alta | Media |
| Documentación disponible | Muy amplia | Correcta |
| Rendimiento en Macs ARM | Inferior | Superior |
| Facilidad de configuración | Alta | Alta |
| Ventaja principal | Universal y ampliamente utilizado | Optimizado para Apple Silicon |
| Desventaja principal | Menor rendimiento en ARM | Menor adopción general |

# 5. Recursos

## 5.1 Documentación oficial

- Debian Documentation:
  https://www.debian.org/doc/

- OpenSSH Documentation:
  https://www.openssh.com/

- AppArmor Documentation:
  https://apparmor.net/

- UFW Documentation:
  https://wiki.ubuntu.com/UncomplicatedFirewall

- LVM Documentation:
  https://sourceware.org/lvm2/


## 5.2 Tutoriales utilizados

- Guía Born2beroot
  https://noreply.gitbook.io/born2beroot

- Documentación Crontab
  https://www.hostinger.com/es/tutoriales/sintaxis-crontab/

## 5.3 Uso de Inteligencia Artificial

La IA se utilizó como herramienta de apoyo para:

- Comprender conceptos de administración de sistemas.
- Aprender la configuración de SSH y UFW.
- Resolver dudas sobre qué comandos utilizar para la construcción del script.
- Construir la base sobre la que realizar la documentación técnica, ayudar a dar formato Markdown al fichero README.md y correcciones ortográficas.

Las siguientes tareas fueron realizadas manualmente:

- Instalación del sistema operativo.
- Configuración de usuarios y grupos.
- Configuración de SSH.
- Configuración del firewall.
- Implementación de políticas de contraseñas.
- Configuración de sudo.
- Creación y prueba del script monitoring.sh.
- Validación completa del proyecto.
