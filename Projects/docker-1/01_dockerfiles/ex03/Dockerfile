FROM debian

USER test
RUN apt-get update -y && apt-get upgrade -y

# Install Ruby
RUN apt-get install curl git libssl-dev libreadline-dev zlib1g-dev -y
RUN curl -fsSL https://github.com/rbenv/rbenv-installer/raw/master/bin/rbenv-installer | bash
ENV PATH=$PATH:/root/.rbenv/bin
RUN eval "$(rbenv init -)"
RUN rbenv install 2.4.4

# Install Bundler
RUN gem install bundler

# Install Node and Yarn
RUN apt-get install gpg -y
RUN curl -sL https://deb.nodesource.com/setup_8.x | bash -
RUN apt-get install nodejs -y
RUN curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | apt-key add -
RUN echo "deb https://dl.yarnpkg.com/debian/ stable main" | tee /etc/apt/sources.list.d/yarn.list
RUN apt-get update && apt-get install yarn -y

# Install Go
WORKDIR $HOME/local
RUN apt-get install wget -y
RUN wget https://storage.googleapis.com/golang/go1.9.6.linux-amd64.tar.gz
RUN tar -xzvf go1.9.6.linux-amd64.tar.gz
ENV GOROOT=$HOME/local/go
ENV PATH=$PATH:$GOROOT/bin

# Install other dependencies
RUN apt-get install postgresql postgresql-contrib libpq-dev redis-server libicu-dev cmake g++ libkrb5-dev libre2-dev ed pkg-config graphicsmagick libsqlite3-dev
RUN gem install sqlite3 -v '1.3.13'

RUN gem install gitlab-development-kit
RUN gdk init
WORKDIR gitlab-development-kit
RUN gdk install
