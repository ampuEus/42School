# Brief introduction to web pages
***Versión en [español](9_Breve_Introduccion_a_las_paginasWeb.md)***

A simple definition would be *document available on the www (**W**orld **W**ide **W**eb) encoded according to their standards and in a specific language known as HTML*. **The web is a Internet application** thanks to which you can transfer data (the **URLs**, **U**niform **R**esource **L**ocators, of web pages) via HTTP (** H**yper**t**ext **T**transfer **P**rotocol)

**To access them, internet browsers are used** (eg: Mozilla Firefox, Opera, Chrome...), this is responsible for receiving the encoded information of the document and showing it to the user in a "readable" way.

**For a browser to find the URL of the web page, it must be hosted in an accessible place on the Internet** so that a user through the browser downloads the information from the page and appears on the computer. Here **web servers** come into play, broadly speaking they are computers that **are always on and connected to the internet** in which the web page is hosted and deliver its content when it is requested.

![Web flow + frameworks](Frontend_and_backend_frameworks.png)

In the image above you can see 2 things:
1. The interaction between the user and the server. As the user through his computer asks the server for information on the web page and the server responds.
2. Some of the different tools (known as *frameworks*) that exist to create web pages. Each one used to create a part of it.

## Parts of a web page
From a programming point of view, there are two well-differentiated parts: the client part, also known as the front-end, and the server part, also known as the back-end.

### front-end
It is the part of a website that is user-facing. It is the part that you see and interact with when you search for something in the web browser. But of course there is much more to it than that. The main technologies on which it is based are:
- **HTML** (**H**yper**T**ext **M**arkup **L**anguage). It can be said that it is the skeleton of a web page. It is used to structure the content/texts of a web page and also tells the web browser how to display it.
- **CSS** (**C**ascading **S**tyle **S**heets). It describes to browsers more specific information about the display and style of content, such as the size and color of text.
- **JavaScript**. It allows you to create more complex elements like interactive maps and animated graphics. It runs both in the browser and on the server, which makes it versatile.

Tools have been created over time to make front-end development easier, ranging from content management systems (CMS) like WordPress and Drupal to libraries and frameworks like React, Angular, and Vue. Libraries and frameworks allow you to use a model to create web parts like buttons instead of creating a new one each time.

#### What is [WordPress](https://wordpress.org/)?
WordPress is a free and open source CMS that is quite versatile, which makes it a very popular choice among content management systems. CMS allow you to create and maintain simple web pages in a simple way without the need for much technical knowledge.

### Back end
It's the part of the website you don't see. It is responsible for storing and organizing the data, and ensuring that everything on the client side actually works. The backend communicates with the frontend, sending and receiving information to be displayed as a web page. For example, every time a contact form is filled out, a web address is entered, or a purchase is made (any client-side user interaction), the browser sends a request to the server side, which returns information in the form of of frontend code that the browser can interpret and display.

The back-end can be divided into three aspects:
- **Logic of the code**, are the functionalities that the server has. To encode them, specific languages ​​such as PHP, node.js or python are used, each of these languages ​​has its advantages and disadvantages. For example, **PHP** is good at integrating with HTML, but worse at asynchronous programming.
- **Web server**, is the server that can interpret requests from web browsers. For this purpose there are different services such as; Apache, NGINX or Lighttp. In the case of **Ligthttp**, it is an open source server specially designed to be fast and have a low server memory consumption, it also has an intelligent management of the server's CPU load and its consumption of memory this.
- **Database**, is the place where data is stored and related in a logical unit. For communication with the database, a server is used (which can be the web server itself or be a separate one) called *back-end server*. To manage databases there are specific languages such as MariaDB, PostgresSQL or MoongoDB. In the case of **MariaDB** it is a free and open source database manager, based on MySQL.
