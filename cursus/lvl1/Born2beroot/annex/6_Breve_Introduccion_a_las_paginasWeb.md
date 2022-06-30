# Breve introducción a las paginas web
Una definición simple sería *documento disponible en la www (**W**orld **W**ide **W**eb) codificado según sus estándares y con en un lenguaje específico conocido como HTML*. **La web es una aplicación de Internet** gracias al cual puede transferir datos (los **URLs**, **U**niform **R**esource **L**ocators, de las paginas web) a través de HTTP (**H**yper**t**ext **T**ransfer **P**rotocol)

**Para acceder a ellas se usan navegadores de internet** (ej.: Mozilla Firefox, Opera, Chrome...), esto se encargas de recibir la información codificada del documento y mostrársela al usuario de forma "legible".

**Para que un navegador encuentre el URL de la página web, está debe estar alojada en un lugar accesible en Internet** para que un usuario a través del navegador la información de la página se descargue y aparezca en el ordenador. Aquí **entran en juego los servidores web**, a grandes rasgos son ordenadores que **están siempre encendidos y conectados a internet** en los cuales se aloja la página web y entregan el contenido de esta cuando es solicitada.

![Flujo de información de las web + frameworks](Frontend_and_backend_frameworks.png)

En la imagen de arriba se pueden ver 2 cosas:
1. La interacción entre el usuario y el servidor. Como el usuario mediante su ordenador pide al servidor la información de la página web y el servidor le responde.
2. Algunos de las diferentes herramientas (conocidas como *frameworks*) que existen para crear páginas web. Cada uno utilizado para crear una parte de esta.

## Partes de una página web
Desde el punto de vista de la programación existen dos partes bien diferenciadas, la parte del cliente también conocida como front-end y la parte del servidor conocida como back-end.

### Front-end
Es la parte de un sitio web que está orientada al usuario. Es la parte que ves e interactúas cuando buscas algo en el navegador web. Pero, por supuesto, hay mucho más que eso. A las tecnologías principales en las que se basa son:
- **HTML** (**H**yper**T**ext **M**arkup **L**anguage). Se puede decir que es el esqueleto de una página web. Se utiliza para estructurar el contenido/textos de una página web y también le dice al navegador web cómo mostrarlo.
- **CSS** (**C**ascading **S**tyle **S**heets). Describe a los navegadores información más específica sobre la visualización y estilo de contenido, como el tamaño y el color del texto.
- **JavaScript**. Te permite crear elementos más complejos como mapas interactivos y gráficos animados. Se ejecuta tanto en el navegador como en el servidor, lo que lo hace versátil.

Con el paso del tiempo para facilitar el desarrollo del front-end se han ido creando herramientas, que van desde sistemas de administración de contenido (CMS) como WordPress y Drupal hasta bibliotecas y marcos como React, Angular y Vue. Las bibliotecas y los marcos le permiten usar un modelo para crear elementos web como botones en lugar de crear uno nuevo cada vez.

#### ¿Qué es [WordPress](https://wordpress.org/)?
WordPress es un CMS gratuito y de código abierto bastante polivalente lo que lo hace una opción muy popular entre los sistemas de gestión de contenido. Los CMS permites crear y mantener páginas web sencillas de forma simple sin necesidad de tener muchos conocimientos técnicos.

### Back-end
Es la parte del sitio web que no ve. Es responsable de almacenar y organizar los datos, y de garantizar que todo en el lado del cliente realmente funcione. El backend se comunica con el frontend, enviando y recibiendo información para ser mostrada como una página web. Por ejemplo, cada vez que se completa un formulario de contacto, se introduce una dirección web o se realiza una compra (cualquier interacción del usuario en el lado del cliente), el navegador envía una solicitud al lado del servidor, que devuelve información en forma de código frontend que el navegador puede interpretar y mostrar.

El back-end se puede dividir en tres aspectos:
- **Lógica del código**, son las funcionalidades que tiene el servidor. Para codificarlas se usan lenguajes específicos como son PHP, node.js o python, cada uno de estos lenguajes tienen sus ventajas y desventajas. Por ejemplo, **PHP** es bueno en integración con HTML, pero es peor en programación asíncrona.
- **Servidor web**, es el servidor que puede interpretar las peticiones de los navegadores web. Para este propósito existen diferentes servicios como por ejemplo; Apache, NGINX o Lighttp. En el caso de **Ligthttp**, se trata de un servidor de código abierto especialmente diseñado para ser rápido y tener un consumo de memoria del servidor bajo, también tiene una gestión inteligente de la carga de la CPU del servidor y su consumo de memoria este.
- **Database**, es el lugar donde se almacenan y relacionan los datos en una unidad lógica. Para la comunicación con la base de datos se utiliza un servidor (que puede ser el propio servidor web o estar el otro separado) llamado *servidor back-end*. Para gestionar las bases de datos existen lenguajes específicos como son MariaDB, PostgresSQL o MoongoDB. En el caso de **MariaDB** se trata de un administrador de base de datos gratuito y de código abierto, basado en MySQL.
