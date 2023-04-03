# FROM alpine:latest
# RUN apk add --no-cache build-base
FROM debian:latest
RUN apt update \
	&& apt upgrade \
	&& apt install -y build-essential gdb \
	&& rm -rf /var/lib/apt/lists/*
RUN mkdir /42
VOLUME /42
# docker build -t 42_docker .
# docker run -it -v %cd%:/42 42_docker
