# What is SSH?
SSH (**S**ecure **Sh**ell) is a service/protocol used for remote connection to a server through a secure channel in which all information is encrypted. Although it can be used for functionalities such as "tunneling" to pass data from another non-secure protocol through SSH. It uses a client/server architecture and incorporates connection encryption.

SSH is the evolution of other older and insecure protocols like telnet. The SSH protocol provides the following types of protection:
- After the initial connection, the client can verify that it is connecting to the same server it was previously connected to, thanks to the certificates.
- The client transmits its authentication information to the server using strong 128-bit encryption.
- All data sent and received during the session is transferred using 128-bit encryption, which makes it extremely difficult to decipher and read.
- The client has the possibility to forward X11 applications from the server. This technique, called X11 forwarding, provides a secure means of using graphical applications over a network.

## Location in the OSI model

![OSI Model Layers](OSI_Model.png)

SSH is a communication protocol that sits at least Layer 7 (Application) of the OSI Model. Strictly speaking SSH covers OSI layers 5, 6 and 7, because it provides the application connection interface (layer 7), a procedure for (des)encryption and transfer (layer 6) and session authentication management with/without encryption by special channels (layer 5).

As for the layers that SSH uses, they would be:
- **Application:** SSH
- **Transport:** TCP
- **Network:** IP (IPv4 and IPv6)

![SHH Layers in the OSI model](SSH_LayersOSI.svg)
