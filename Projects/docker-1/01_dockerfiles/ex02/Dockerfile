FROM ruby

RUN apt-get update -y && apt-get install sqlite3
RUN gem install rails
RUN apt-get install nodejs -y

ONBUILD COPY . /opt/app

ONBUILD WORKDIR /opt/app

ONBUILD RUN bundle install
ONBUILD RUN rake db:migrate
ONBUILD RUN rake db:seed
