# C++ Tutorial by Roundbeargames

Indie game developer from South Korea
<br>
https://youtube.com/roundbeargames


# Getting Started (Windows)

1. Download ZIP (or clone using a Git client of your choice)

2. Open .sln files using Visual Studio 2019 Community

    https://visualstudio.microsoft.com/downloads

# Getting Started (Linux - Ubuntu or Unbuntu based)

1. Install compiler, build tools, and libraries

```
sudo apt install g++
sudo apt install build-essential libglu1-mesa-dev libpng-dev
```

2. Navigate to a project folder

3. Compile and run

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

# Tutorial Videos

https://youtube.com/playlist?list=PLWYGofN_jX5Apmb8pJUD8NN3KskHW2lcy
