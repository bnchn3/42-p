FROM debian

ENV TS3SERVER_LICENSE accept

RUN apt-get update -y
RUN apt-get install wget bzip2 -y

RUN useradd teamspeak
WORKDIR /home/teamspeak

RUN wget http://dl.4players.de/ts/releases/3.0.13.8/teamspeak3-server_linux_amd64-3.0.13.8.tar.bz2
RUN tar xfvj teamspeak3-server_linux_amd64-3.0.13.8.tar.bz2

EXPOSE 9987/udp
EXPOSE 30033
EXPOSE 10011

WORKDIR teamspeak3-server_linux_amd64
USER teamspeak
ENTRYPOINT ["sh", "ts3server_minimal_runscript.sh"]
