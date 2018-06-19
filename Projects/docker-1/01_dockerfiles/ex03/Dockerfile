FROM debian

#Create non-root user
RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install sudo -y
RUN useradd -m test && echo "test:test" | chpasswd && adduser test sudo
RUN echo "test ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
USER test

#Install base dependencies
RUN sudo apt-get install postgresql postgresql-contrib libpq-dev redis-server libicu-dev cmake g++ libkrb5-dev libre2-dev ed pkg-config graphicsmagick libsqlite3-dev -y

# Install Ruby
RUN sudo apt-get install curl git libssl-dev libreadline-dev zlib1g-dev bzip2 gcc -y
RUN git clone https://github.com/rbenv/rbenv.git ~/.rbenv
ENV PATH=$HOME/.rbenv/bin:$PATH
RUN eval "$(rbenv init -)"
RUN mkdir -p "$(rbenv root)"/plugins
RUN git clone https://github.com/rbenv/ruby-build.git "$(rbenv root)"/plugins/ruby-build
RUN rbenv install 2.4.4
RUN rbenv global 2.4.4

# Install Bundler
RUN gem install bundler

# Install Node and Yarn
RUN sudo apt-get install gpg -y
RUN curl -sL https://deb.nodesource.com/setup_8.x | sudo -E bash -
RUN sudo apt-get install nodejs -y
RUN curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | sudo apt-key add -
RUN echo "deb https://dl.yarnpkg.com/debian/ stable main" | sudo tee /etc/apt/sources.list.d/yarn.list
RUN sudo apt-get update && sudo apt-get install yarn -y

# Install Go
WORKDIR $HOME/local
RUN sudo apt-get install wget -y
RUN wget https://storage.googleapis.com/golang/go1.9.6.linux-amd64.tar.gz
RUN tar -xzvf go1.9.6.linux-amd64.tar.gz
ENV GOROOT=$HOME/local/go
ENV PATH=$PATH:$GOROOT/bin

# Install SQLite3
RUN gem install sqlite3 -v '1.3.13'

RUN gem install gitlab-development-kit
RUN gdk init
WORKDIR gitlab-development-kit
RUN gdk install

ENTRYPOINT gdk run
