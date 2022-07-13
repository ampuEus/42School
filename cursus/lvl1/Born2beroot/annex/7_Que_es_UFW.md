# ¿Qué es UFW?
***[English](7_What_is_UFW.md) version***

Durante mucho tiempo, la seguridad de Linux estuvo en manos de *iptables* (que funciona con el sistema *netfilter* subyacente). Aunque increíblemente poderoso, iptables es complicado, especialmente para los usuarios más nuevos. Para aprovechar al máximo ese sistema, puede llevar semanas o meses ponerse al día. Afortunadamente, existe UFW (**U**ncomplicated **F**ire**w**all) una interfaz mucho más simple para iptables que proporciona un marco mucho más fácil de usar para administrar netfilter y una interfaz de línea de comandos para trabajar con el firewall.

[Aquí](https://wiki.debian.org/es/Uncomplicated%20Firewall%20%28ufw%29) te dejo una pequeña guía de como usarlo junto a una [cheatsheet](UFW_Cheatsheet.pdf) con los comandos más recurrentes de UFW y monitorización de la red.

## ¿Qué es un firewall?
Un firewall es un dispositivo de seguridad de la red que monitorea el tráfico de red (entrante y saliente) y decide si permite o bloquea tráfico específico en función de un conjunto definido de reglas de seguridad.

Los firewalls han constituido una primera línea de defensa en seguridad de la red durante más de 25 años. Establecen una barrera entre las redes internas protegidas y controladas en las que se puede confiar y redes externas que no son de confianza, como Internet.

Un firewall puede ser hardware, software o ambos.
