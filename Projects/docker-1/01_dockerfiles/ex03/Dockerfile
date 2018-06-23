FROM debian

# Install base packages
RUN apt-get update -y && \
	apt-get install sudo postgresql postgresql-contrib \
		libpq-dev redis-server libicu-dev cmake g++ \
		libkrb5-dev libre2-dev ed pkg-config graphicsmagick \
		libsqlite3-dev curl git libssl-dev libreadline-dev \
		zlib1g-dev bzip2 gcc gpg wget -y

# Install NodeJS
RUN curl -sL https://deb.nodesource.com/setup_8.x | bash -
RUN apt-get update && apt-get install nodejs -y

# Install Yarn
RUN curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | apt-key add -
RUN echo "deb https://dl.yarnpkg.com/debian/ stable main" | tee /etc/apt/sources.list.d/yarn.list
RUN apt-get update && apt-get install yarn -y

# Install Go
RUN useradd --user-group --create-home test
WORKDIR /home/test/local
RUN wget https://storage.googleapis.com/golang/go1.9.6.linux-amd64.tar.gz
RUN tar -xzvf go1.9.6.linux-amd64.tar.gz
USER test
RUN echo 'export GOROOT="/home/test/local/go"' >> /home/test/.bash_profile

# Install Ruby
RUN git clone https://github.com/rbenv/rbenv.git /home/test/.rbenv
RUN echo 'export PATH="/home/test/.rbenv/bin:$PATH:$GOROOT/bin"' >> /home/test/.bash_profile
RUN echo 'eval "$(rbenv init -)"' >> /home/test/.bash_profile
RUN mkdir /home/test/.rbenv/plugins
RUN git clone https://github.com/rbenv/ruby-build.git /home/test/.rbenv/plugins/ruby-build
SHELL ["bash", "-lc"]
RUN rbenv install 2.4.4 && rbenv global 2.4.4

# Install Gems
RUN gem install bundler sqlite3:1.3.13

RUN gem install gitlab-development-kit
WORKDIR /home/test
RUN gdk init
WORKDIR gitlab-development-kit
RUN gdk install

#Post-install
RUN echo 0.0.0.0 > host
RUN gdk reconfigure

ENTRYPOINT gdk run
