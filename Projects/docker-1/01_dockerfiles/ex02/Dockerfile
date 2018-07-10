FROM ruby

RUN apt-get update -y
RUN gem install rails
RUN apt-get install nodejs -y

ONBUILD COPY . /opt/app

ONBUILD WORKDIR /opt/app

ONBUILD RUN bundle install
ONBUILD RUN rails db:migrate
ONBUILD RUN rails db:seed
