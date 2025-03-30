FROM ubuntu:22.04

# Install build essentials
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libsdl2-dev \
    lcov \
    gcovr \
    libbenchmark-dev

# Configure container
WORKDIR /keeperfx
COPY . .

# Entry point for builds
ENTRYPOINT ["/bin/bash"]