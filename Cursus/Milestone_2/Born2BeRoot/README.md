*Este proyecto ha sido creado como parte del plan de estudios de 42 por <login>.*

# Born2beRoot

## Descripción

Born2beRoot es un proyecto de Administración de Sistemas que forma parte del itinerario de 42 cuyo objetivo es introducir los conceptos fundamentales de virtualización, gestión de servidores Linux y securización de sistemas.

El proyecto consiste en instalar y configurar una máquina virtual utilizando VirtualBox o UTM, implementando una serie de requisitos relacionados con la gestión de usuarios, políticas de contraseñas, configuración de SSH, firewall, sudo, LVM y monitorización del sistema.

A través de este proyecto se adquieren conocimientos prácticos sobre la administración de sistemas Linux, una habilidad esencial en entornos profesionales de infraestructura y ciberseguridad.

---

### Principales decisiones de diseño

#### Entorno de virtualización 

Tal y como se indica en el *subject*, el entorno de virtualización es en el que se desarrolla el proyecto es VirtualBox

#### Sistema operativo elegido

Para este proyecto se ha elegido **Debian** como sistema operativo principal.

Debian es una distribución GNU/Linux reconocida por su estabilidad, seguridad y enorme comunidad de usuarios. Además, el propio enunciado recomienda Debian para estudiantes que se inician en la administración de sistemas. 【1-4352b3】

| Ventajas | Desventajas |
|----------------|---------|
| Gran estabilidad<BR>Amplia documentacion<BR>Comunidad muy activa<BR>Fácil aprendizaje para principiantes<BR>Excelente gestión de paquetes mediante APT|Algunos paquetes pueden no estar tan actualizados como en otras distribuciones<BR>Menor orientación al entorno empresarial que Rocky Linux

##### Justificación

| Aspecto | Motivo |
|----------|---------|
| Facilidad de uso | Más adecuado para iniciarse en Linux |
| Documentación | Gran cantidad de recursos disponibles |
| Estabilidad | Excelente para servidores |
| Comunidad | Una de las mayores comunidades Linux |
| Compatibilidad | Integración sencilla de AppArmor, UFW y SSH |
| Recomendación del proyecto | Recomendado explícitamente para principiantes |

#### Particionado

El disco se ha configurado utilizando:

- LVM (Logical Volume Manager).
- Particiones cifradas.
- Separación lógica de datos del sistema.

Esta configuración permite:

- Mayor flexibilidad para ampliar volúmenes.
- Mejor organización del almacenamiento.
- Mayor seguridad gracias al cifrado.

### Implementación


#### Políticas de seguridad

Se han implementado las siguientes medidas:

- SSH escuchando en el puerto 4242.
- Acceso SSH al usuario root deshabilitado.
- Firewall UFW activo.
- Política de contraseñas robusta.
- Caducidad periódica de contraseñas.
- Restricciones avanzadas para sudo.
- Registro de todas las acciones realizadas con sudo.

#### Gestión de usuarios

El sistema incluye:

- Usuario root.
- Usuario personal.
- Grupo `sudo`.
- Grupo `user42`.

#### Servicios instalados

- OpenSSH Server
- UFW
- AppArmor
- Cron
- Monitoring Script (`monitoring.sh`)

---

### Comparativas Técnicas

#### Debian vs Rocky Linux

La principal ventaja de Debia, frente a Rocky Linus, y el motivo de su elección es su universalidad, su gran cantidad de software disponible, su sencillez (comparad con Rocky Linux) y la gran cantidad de documentación disponible.
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


#### AppArmor vs SELinux

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

#### UFW vs firewalld

| Característica | UFW | firewalld |
|----------------|-----|-----------|
| Distribuciones habituales | Debian y Ubuntu | Rocky, Fedora y RHEL |
| Facilidad de uso | Muy alta | Media |
| Gestión de reglas | Simple | Basada en zonas y servicios |
| Configuración dinámica | No | Sí |
| Curva de aprendizaje | Baja | Media |
| Ventaja principal | Sencillez | Flexibilidad |
| Desventaja principal | Menos funcionalidades avanzadas | Mayor complejidad |

#### VirtualBox vs UTM

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

---

## Pasos para la realización del proyecto

### Instalación de la máquina virtual

1. Crear una máquina virtual utilizando VirtualBox o UTM.
2. Instalar Debian estable.
3. Configurar particiones cifradas mediante LVM.
4. Configurar el hostname terminado en `42`.
5. Crear el usuario personal.
6. Añadirlo a los grupos:
   - sudo
   - user42

### Configuración SSH

Editar:

```bash
sudo nano /etc/ssh/sshd_config
```

Configurar:

```text
Port 4242
PermitRootLogin no
```

Reiniciar el servicio:

```bash
sudo systemctl restart ssh
```

### Configuración del Firewall

Activar UFW:

```bash
sudo ufw enable
```

Abrir el puerto SSH:

```bash
sudo ufw allow 4242
```

Comprobar el estado:

```bash
sudo ufw status
```

### Script de monitorización

Ejecutar:

```bash
./monitoring.sh
```

El script muestra:

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

---

## Estructura del proyecto

```text
Born2beRoot/
├── README.md
├── signature.txt
└── monitoring.sh
```

---

## Recursos

### Documentación oficial

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

### Tutoriales utilizados

- Guías de administración Linux.
- Documentación oficial de VirtualBox.
- Manuales de Bash scripting.
- Recursos del currículo de 42.

### Uso de Inteligencia Artificial

La IA se utilizó como herramienta de apoyo para:

- Comprender conceptos de administración de sistemas.
- Entender el funcionamiento de LVM.
- Resolver dudas sobre AppArmor.
- Aprender la configuración de SSH y UFW.
- Mejorar la documentación técnica y la redacción del proyecto.

Las siguientes tareas fueron realizadas manualmente:

- Instalación del sistema operativo.
- Configuración de usuarios y grupos.
- Configuración de SSH.
- Configuración del firewall.
- Implementación de políticas de contraseñas.
- Configuración de sudo.
- Creación y prueba del script monitoring.sh.
- Validación completa del proyecto.

---

## Características implementadas

- Máquina virtual Debian.
- SSH en el puerto 4242.
- Acceso root por SSH deshabilitado.
- UFW activo.
- AppArmor activo.
- LVM con particiones cifradas.
- Política fuerte de contraseñas.
- Configuración avanzada de sudo.
- Script de monitorización automática.
- Gestión segura de usuarios y grupos.

---

## Autor

Alumno de 42

Login: `<login>`
