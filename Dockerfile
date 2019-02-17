FROM ubuntu:16.04

RUN apt-get update \
    && apt-get install -y binutils \
    && apt-get install -y build-essential \
    && apt-get install -y sysstat

WORKDIR /work

COPY . .
