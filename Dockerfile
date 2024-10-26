# Use an official Ubuntu image as a base
FROM ubuntu:22.04

# Set environment variables to avoid interaction during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    g++-11 \
    libssl-dev \
    neovim \
    curl \
    git \
    libsfml-dev \
    && apt-get clean

RUN update-alternatives --install /usr/bin/editor editor /usr/bin/nvim 60 && \
    update-alternatives --set editor /usr/bin/nvim

# Set the work directory
WORKDIR /work

COPY . /work

CMD ["/bin/bash"]