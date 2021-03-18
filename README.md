# C++ Tutorial by Roundbeargames

Indie game developer from South Korea
<br>
https://youtube.com/roundbeargames

![samplescreenshot](https://i.imgur.com/HDtWwa2.jpg)

<br>

# Getting Started (Windows)

1. Download ZIP or clone repository

2. Open .sln files using Visual Studio 2019 Community

    https://visualstudio.microsoft.com/downloads

<br>

# Getting Started (Linux - Ubuntu)

1. Download ZIP or clone repository

2. Install compiler and packages

```
sudo apt install g++ build-essential libglu1-mesa-dev libpng-dev
```

3. Navigate to a project folder and compile

```
//for example, "001 thinking in terms of 1s and 0s" folder
g++ -o sample main.cpp -std=c++17
./sample
```

```
//projects that use olcPixelGameEngine (under "olcPixelGameEngine projects" folder)
g++ -o sample main.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
./sample
```

<br>

# Getting Started (CMake)

1. Download ZIP or clone repository

2. Install CMake, compiler, and packages

```
sudo apt install cmake g++ build-essential libglu1-mesa-dev libpng-dev
```

2. Navigate to CMakeLists.txt (under "olcPixelGameEngine projects" folder) and compile

```
cmake .
make
./sample
```

<br>

# Tutorial Videos

https://youtube.com/playlist?list=PLWYGofN_jX5Apmb8pJUD8NN3KskHW2lcy

<br>

# C++ Fighting Game
https://github.com/RoundBearChoi/CPP_FightingGame

<br>

# License (OLC-3)

This project uses olcPixelGameEngine by OneLoneCoder

<br>

Copyright 2018, 2019, 2020, 2021 OneLoneCoder.com

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions or derivations of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions or derivative works in binary form must reproduce the above copyright notice. This list of conditions and the following disclaimer must be reproduced in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
