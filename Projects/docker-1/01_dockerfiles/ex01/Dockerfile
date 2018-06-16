FROM debian

EXPOSE 9987/udp
EXPOSE 30033
EXPOSE 10011

ENV TS3SERVER_LICENSE accept

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install wget bzip2 -y

RUN wget http://dl.4players.de/ts/releases/3.0.13.8/teamspeak3-server_linux_amd64-3.0.13.8.tar.bz2
RUN tar xfvj teamspeak3-server_linux_amd64-3.0.13.8.tar.bz2

WORKDIR teamspeak3-server_linux_amd64
ENTRYPOINT ["sh", "ts3server_minimal_runscript.sh"]
