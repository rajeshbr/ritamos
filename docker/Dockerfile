FROM ubuntu:24.04

ARG USERNAME=developer
ARG UID=501
ARG GID=20

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && apt install -y \
   sudo \
   build-essential \
   git \
   cmake \
   ninja-build \
   bc \
   bison \
   flex \
   cpio \
   rsync \
   unzip \
   wget \
   curl \
   vim \
   nano \
   python3 \
   python3-pip \
   file \
   xz-utils \
   qemu-system-arm \
   qemu-system-aarch64 \
   gcc-aarch64-linux-gnu \
   g++-aarch64-linux-gnu \
   gdb-multiarch \
   libssl-dev \
   libncurses-dev \
   libelf-dev \
   pkg-config

RUN groupadd -o -g ${GID} ${USERNAME}

RUN useradd \
   -m \
   -u ${UID} \
   -g ${GID} \
   -s /bin/bash \
   ${USERNAME}

RUN echo "${USERNAME} ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

USER ${USERNAME}

WORKDIR /workspace

