*Este proyecto ha sido creado como parte del plan de estudios de 42 por igarcia-.*

# Born2beRoot

# Índice

- [1. Descripción](#1-descripción)
  - [1.1 Principales decisiones de diseño](#11-principales-decisiones-de-diseño)
    - [1.1.1 Entorno de virtualización](#111-entorno-de-virtualización)
    - [1.1.2 Sistema operativo elegido](#112-sistema-operativo-elegido)
    - [1.1.3 Particionado](#113-particionado)
    - [1.1.4 Elección del FW](#114-elección-del-fw)

- [2. Implementación](#2-implementación)
  - [2.1 Creación de la Máquina Virtual](#21-creación-de-la-maquina-virtual)
  - [2.2 Instalación de Debian](#22-instalación-de-debian)
    - [2.2.1 Particionado](#221-particionado)
    - [2.2.2 Gestor de paquetes](#222-gestor-de-paquetes)
    - [2.2.3 GRUB Boot Loader](#223-grub-boot-loader)
    - [2.2.4 Instalación del resto de servicios](#224-instalación-del-resto-de-servicios)
    - [2.2.4 SUDO y grupos de usuarios](#224-sudo-y-grupos-de-usuarios)
    - [2.2.5 SSH](#225-ssh)
    - [2.2.6 Instalación de UFW](#226-instalación-de-ufw)
    - [2.2.7 Aplicación políticas de seguridad](#227-aplicación-políticas-de-seguridad)
    - [2.2.8 Monitoring.sh y Crontab](#228-monitoringsh-y-crontab)

- [3. Comparativas Técnicas](#3comparativas-técnicas)
  - [3.1 Debian vs Rocky Linux](#31-debian-vs-rocky-linux)
  - [3.2 AppArmor vs SELinux](#32-apparmor-vs-selinux)
  - [3.3 UFW vs firewalld](#33-ufw-vs-firewalld)
  - [3.4 VirtualBox vs UTM](#34-virtualbox-vs-utm)

- [4. Recursos](#4-recursos)
  - [4.1 Documentación oficial](#41-documentación-oficial)
  - [4.2 Tutoriales utilizados](#42-tutoriales-utilizados)
  - [4.3 Uso de Inteligencia Artificial](#43-uso-de-inteligencia-artificial)


## 1. Descripción

Born2beRoot es un proyecto de Administración de Sistemas que forma parte del itinerario de 42 cuyo objetivo es introducir los conceptos fundamentales de virtualización, gestión de servidores Linux y securización de sistemas.

El proyecto consiste en instalar y configurar una máquina virtual utilizando VirtualBox o UTM, implementando una serie de requisitos relacionados con la gestión de usuarios, políticas de contraseñas, configuración de SSH, firewall, sudo, LVM y monitorización del sistema.

A través de este proyecto se adquieren conocimientos prácticos sobre la administración de sistemas Linux, una habilidad esencial en entornos profesionales de infraestructura y ciberseguridad.

---

### 1.1 Principales decisiones de diseño

#### 1.1.1 Entorno de virtualización 

Tal y como se indica en el *subject*, el entorno de virtualización es en el que se desarrolla el proyecto es VirtualBox

#### 1.1.2 Sistema operativo elegido

Para este proyecto se ha elegido **Debian** como sistema operativo principal.

Debian es una distribución GNU/Linux reconocida por su estabilidad, seguridad y enorme comunidad de usuarios. Además, el propio enunciado recomienda Debian para estudiantes que se inician en la administración de sistemas. 【1-4352b3】

| Ventajas | Desventajas |
|----------------|---------|
| Gran estabilidad<BR>Amplia documentacion<BR>Comunidad muy activa<BR>Fácil aprendizaje para principiantes<BR>Excelente gestión de paquetes mediante APT|Algunos paquetes pueden no estar tan actualizados como en otras distribuciones<BR>Menor orientación al entorno empresarial que Rocky Linux

Su elección se justifica por:

| Motivo | Detalle |
|----------|---------|
| Facilidad de uso | Más adecuado para iniciarse en Linux |
| Documentación | Gran cantidad de recursos disponibles |
| Estabilidad | Excelente para servidores |
| Comunidad | Una de las mayores comunidades Linux |
| Compatibilidad | Integración sencilla de AppArmor, UFW y SSH |
| Recomendación del proyecto | Recomendado explícitamente para principiantes |

#### 1.1.3 Particionado

El disco se ha configurado, con la previsión de implementar el BONUS, utilizando:

- LVM (Logical Volume Manager).
- Particiones cifradas.
- Separación lógica de datos del sistema.

Esta configuración permite:

- Mayor flexibilidad para ampliar volúmenes.
- Mejor organización del almacenamiento.
- Mayor seguridad gracias al cifrado.

#### 1.1.4 Elección del FW

Se ha elegido Uncomplicated FireWall por ser, de las opciones propuestas, la de menor complejidad para alguien que se inicia en la configuración de este tipo de tecnología.

 Motivo | Detalle |
|----------------|-----|
| Facilidad de uso | Muy alta debido a su sencillez |
| Gestión de reglas | Simple gestión de reglas | 
| Curva de aprendizaje | Baja, ideal para iniciarse |

## 2. Implementación

### 2.1 Creación de la Maquina Virtual

Se crea ha creado una máquina desde el entorno gráfico de Virtual Box con las siguientes características:

- Nombre: **Born2beroot**
- Carpeta: **/home/igarcia-/sgoinfre/igarcia-/VirtualBox VMs**
- Imagen ISO: **No seleccionada**
- Tipo: **Linux**
- Versión: **Debian (64 bit)**
- Memoria base: **2048 Mb**
- Processors: **2**
- Disco Virtual: **30Gb**

En un paso posterior, se asocia la imagen ISO de Debian mínima necesaria para la instalación (descargable desde https://www.debian.org/distrib/netinst).

### 2.2 Instalación de Debian

Arrancando la máquina virtual previamente creada, procedemos a la instalación de Debian desde el menú inicial con la opción **Install** seleccionando las siguientes carácterísticas:

- Idioma: **English**
- País: **España**
- Configuración local: **EE. UU. (no existe la opción de seleccionar España)**
- Distribución de teclado: **America English**
- Hostname: **igarcia-**
- Domain name: **vacío**
- Contraseña de root: **<*root_pass*>**
- Nonmbre cuenta de usuario: **igarcia-**
- Usuario cuenta: **igarcia-**
- Contraseña usuario: **<*user_pass*>**
- Zona temporal: **Madrid**

#### 2.2.1 Particionado

Crearemos las siguientes particiones para obtener la estructura siguiente:

- Parcición primaria.
- Partición logica.
  - Volumen encriptado
  - Configuración del LVM.
  - Creación grupo de volúmenes
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
#### 2.2.2 Gestor de paquetes

Se configura el gestor de paquetes (Package Manager) con:

- Mirror Country: **Spain**
- Debian Archive Mirror: **deb.debian.org**
- HTTP Proxy: **Ninguno**
- Selección de software: **Instalación mínima, desmarcamos todas las opciones**

#### 2.2.3 GRUB Boot Loader

Necesario para el arranque, en este último paso indicaremos **Sí**, seleccionando el único disco disponible (la partición primaria que creamos en pasos anteriores) y el sistema estará listo para reiniciarse y arrancar Debian.

#### 2.2.4 Instalación del resto de servicios

Arrancamos Debian en la máquina virtual (MV) y nos identificamos con el usuario/pass que hemos introducido durante la instalación inicial (igarcia-/<*passw*>).

#### 2.2.4. SUDO y grupos de usuarios

Procedemos a la instalación de SUDO con el siguiente comando:
```bash
apt install sudo
```
Tras la instalación, reiniciamos la máquina virtual.
```text
sudo reboot
```
Verificamos la intalación, adquiriendo rol de root (nos solicitará la pass de root creada durante la instalación inicial) y consultando la versión instalada.
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

#### 2.2.5 SSH

Instalamos el servicio SSH con el siguiente comando:

```bash
sudo apt updata 
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
#### 2.2.6 Instalación de UFW

Instalamos el paquete UFW:

```bash
sudo apt install ufw
```
Activamos el FW:

```bash
sudo ufw enable
```

Permitimos el puerto 4242 (para poder acceder por SSH):

```bash
sudo ufw allow 4242
sudo ufw status
```

#### 2.2.7 Aplicación políticas de seguridad

Políticas SUDO:

Creamos el fichero de configuración y el directorio para almacenar los log tal y como se solicita en el subjetc:
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

#### 2.2.8 Monitorig.sh y Crontab

De acuerdo con lo descrito en el subjet, se implementa un scrip que se ejecutará regularmente (cada 10') mostrando información del estado del sistema. Concretamente:

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

Consultar esta guía https://www.hostinger.com/es/tutoriales/sintaxis-crontab/ o la documentación oficial de Debian (https://manpages.debian.org/testing/cron/crontab.5.en.html) para entender como hay que crear las líneas en el fichero.

## 3. Comparativas Técnicas

### 3.1 Debian vs Rocky Linux

La principal ventaja de Debian, frente a Rocky Linus, y el motivo de su elección es su universalidad, su gran cantidad de software disponible, su sencillez (comparad con Rocky Linux) y la gran cantidad de documentación disponible.
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

### 3.2 AppArmor vs SELinux

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

### 3.3 UFW vs firewalld

| Característica | UFW | firewalld |
|----------------|-----|-----------|
| Distribuciones habituales | Debian y Ubuntu | Rocky, Fedora y RHEL |
| Facilidad de uso | Muy alta | Media |
| Gestión de reglas | Simple | Basada en zonas y servicios |
| Configuración dinámica | No | Sí |
| Curva de aprendizaje | Baja | Media |
| Ventaja principal | Sencillez | Flexibilidad |
| Desventaja principal | Menos funcionalidades avanzadas, no es un servicio| Mayor complejidad |

### 3.4 VirtualBox vs UTM

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

## 4. Recursos

### 4.1 Documentación oficial

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



### 4.2 Tutoriales utilizados

- Guía Born2beroot
  https://noreply.gitbook.io/born2beroot

- Documentación Crontab
  https://www.hostinger.com/es/tutoriales/sintaxis-crontab/

### 4.3 Uso de Inteligencia Artificial

La IA se utilizó como herramienta de apoyo para:

- Comprender conceptos de administración de sistemas.
- Aprender la configuración de SSH y UFW.
- Resolver dudas sobre qué comandos utilizar para la construcción del script.
- Contruir la base sobre la que realizar la documentación técnica y ayudar a dar formato Markdown al fichero README.md.

Las siguientes tareas fueron realizadas manualmente:

- Instalación del sistema operativo.
- Configuración de usuarios y grupos.
- Configuración de SSH.
- Configuración del firewall.
- Implementación de políticas de contraseñas.
- Configuración de sudo.
- Creación y prueba del script monitoring.sh.
- Validación completa del proyecto.




