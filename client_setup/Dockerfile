FROM docker.io/library/ubuntu:16.04

WORKDIR /home

RUN apt update
RUN apt install -y build-essential git vim net-tools iputils-ping
RUN git clone https://github.com/ioaksenenko/fileremover

WORKDIR /home/fileremover

CMD ["/sbin/init"]