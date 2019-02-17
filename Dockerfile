FROM ubuntu:16.04

RUN apt-get update && apt-get install -y binutils build-essential \
    python3-pip python3-dev \
    sysstat strace
RUN rm -rf /var/lib/apt/lists/*

RUN pip3 install --upgrade pip

WORKDIR /work

COPY . .

CMD ["bash"]
