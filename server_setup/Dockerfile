FROM docker.io/library/ubuntu:16.04

WORKDIR /home

RUN apt update
RUN apt install -y build-essential git vim
RUN git clone https://github.com/ioaksenenko/fileremover

WORKDIR /home/fileremover

RUN touch /etc/systemd/system/fileremover.service
RUN echo "[Service]\nExecStart=/home/fileremover/server\nRestart=always" >> /etc/systemd/system/fileremover.service
RUN systemctl start fileremover

ENTRYPOINT ["/sbin/init"]