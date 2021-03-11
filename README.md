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

# Getting Started (Linux - Ubuntu or Unbuntu based)

1. Download ZIP or clone repository

2. Install compiler, build tools, and libraries

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

2. Install CMake, compiler, build tools, and libraries

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
