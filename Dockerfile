FROM debian:latest

RUN apt update \
	&& apt upgrade -y \
	&& apt install -y build-essential gdb python3 python3-pip \
	&& rm -rf /var/lib/apt/lists/*

RUN python3 -m pip install --upgrade pip setuptools \
	&& python3 -m pip install norminette \
	&& pip3 cache purge \
	&& pip3 config set global.disable-pip-version-check true

RUN mkdir /42
VOLUME /42


# docker build -t dev .
# docker run -it -v %cd%:/42 dev
