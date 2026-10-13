# Guía Completa: Entornos Virtuales, Subdependencias y Poetry

## 1. Qué aísla un entorno virtual (y qué NO)

Un entorno virtual (`venv`) actúa como una caja de arena (*sandbox*) local para paquetes e intérpretes de Python. Lo que hace es manipular las variables de entorno (específicamente el `PATH` de tu sistema) para que, cuando escribas `python` o `pip`, tu terminal busque dentro de la carpeta de ese entorno virtual en lugar de las carpetas globales del sistema.

### 📦 Lo que SÍ aísla:
* **Paquetes de terceros (`site-packages`):** Cada entorno tiene su propio directorio privado para las librerías instaladas. El Proyecto A puede usar `pandas==1.5` mientras que el Proyecto B usa `pandas==2.2` sin que interfieran entre sí.
* **El binario del intérprete de Python:** Un entorno virtual apunta o contiene una versión específica del ejecutable de Python. Puedes tener un entorno ejecutando Python 3.9 y otro con Python 3.12.
* **Scripts ejecutables:** Cualquier herramienta de línea de comandos instalada a través de `pip` (como `black`, `flake8` o `pytest`) se guarda dentro de la carpeta `bin/` (o `Scripts/` en Windows) de ese entorno.

### ❌ Lo que NO aísla:
* **Librerías del sistema operativo:** Muchos paquetes de Python dependen de extensiones en C o binarios a nivel de sistema operativo (como `libpq` para PostgreSQL o `CUDA` para aprendizaje automático). Un entorno virtual no puede aislar esto; depende por completo de los binarios del sistema anfitrión.
* **Variables de entorno del sistema:** No oculta ni aísla las variables globales de tu máquina (como el `PATH` general, la variable `HOME` o tus claves de API guardadas en el sistema), a menos que las borres explícitamente.
* **Acceso al hardware y al sistema de archivos:** No es un contenedor (como Docker) ni una máquina virtual. El código que se ejecuta en un `venv` sigue teniendo acceso completo a tus archivos, red y hardware con los mismos permisos que tu usuario.
* **Límites de seguridad y confianza:** Un entorno virtual no te protege de paquetes maliciosos. Si haces `pip install` de un malware dentro de un `venv`, este puede infectar y comprometer tu ordenador exactamente igual.

---

## 2. ¿Qué es una subdependencia? (El caso de `requests`)

Una **subdependencia** (también llamada dependencia indirecta o transitoria) es una librería que otra librería necesita para funcionar.

Cuando instalas `requests` para hacer peticiones HTTP, los desarrolladores reutilizan componentes existentes para la gestión de redes de bajo nivel y certificados de seguridad. La cadena de dependencias se estructura así:

1. **Tu proyecto** depende de ➡️ `requests` *(Dependencia directa)*
2. **`requests`** depende de ➡️ `urllib3`, `certifi`, `idna`, `charset-normalizer` *(Subdependencias)*

Si ejecutas `pip freeze` tras instalar únicamente `requests`, verás que tu entorno ha descargado de forma automática todas estas subdependencias secundarias:
* `certifi`
* `charset-normalizer`
* `idna`
* `urllib3`

### El riesgo en un `requirements.txt` básico
Si en tu archivo `requirements.txt` solo especificas `requests==2.32.3`, `pip` resolverá las subdependencias buscando **la última versión disponible en PyPI** cada vez que reconstruyas el entorno (por ejemplo, en un servidor de producción). Si el equipo de `urllib3` lanza una actualización que introduce un cambio incompatible o un error, tu aplicación se romperá en el despliegue aunque tú no hayas modificado tu código.

---

## 3. ¿Por qué elegir Poetry sobre un simple `requirements.txt`?

**Poetry** sustituye la gestión manual basada en archivos de texto plano por un flujo de trabajo moderno y determinista enfocado en proyectos.

### Tabla comparativa técnica

| Característica | `requirements.txt` básico | Poetry (`pyproject.toml`) |
| :--- | :--- | :--- |
| **Resolución de dependencias** | Mínima / Lista plana. Puede provocar conflictos ocultos de versiones. | Avanzada. Analiza todo el árbol de dependencias antes de instalar. |
| **Rastreo de subdependencias** | Ninguno (a menos que satures el archivo congelándolo todo con `pip freeze`). | Automático y estricto a través del archivo de bloqueo `poetry.lock`. |
| **Control de versión de Python** | Ninguno. Permite la instalación en entornos con versiones de Python incompatibles. | Obligatorio. Se define y verifica la compatibilidad de Python en la configuración. |
| **Gestión del entorno** | Creación (`python -m venv venv`) y activación manuales. | Automatizada en segundo plano al interactuar con el proyecto. |
| **Sincronización del entorno** | No elimina los paquetes obsoletos si los borras manualmente del archivo. | `poetry install --sync` borra automáticamente cualquier paquete en desuso. |
| **Entornos Separados** | Requiere múltiples archivos (`requirements-dev.txt`, `requirements-prod.txt`). | Soporta grupos nativos de desarrollo y producción dentro del mismo archivo. |
