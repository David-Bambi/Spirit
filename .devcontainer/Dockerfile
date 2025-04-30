FROM ubuntu:latest


RUN apt update -y && apt install -y \
   build-essential \
   cmake \
   git \
   pkg-config\
   curl \
   wget \
   vim \
   gdb \
   ninja-build \
   python3 \
   libx11-dev \
   libgl1-mesa-dev \
   libxi-dev \
   libxrandr-dev \
   libxinerama-dev \
   libxkbcommon-dev \
   libwayland-dev \
   libudev-dev \
   wayland-protocols \
   libxcursor-dev \
   clang-tidy \
   clang-format \
   cmake-format \
   mesa-utils \
   x11-apps \
   && apt clean

CMD ["bash"]