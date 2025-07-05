# Liquid glass
A shader inspired by Apple's [Liquid Glass](https://en.wikipedia.org/wiki/Liquid_Glass) design language. 

It renders a squircle with a shader that approximates a signed distance field to
emulate refraction. With some blur, noise and a bit of glow, it ends up looking
somewhat like glass.

## Building
Make sure to recursively initialize submodules. Either clone with:
```sh
git clone https://github.com/OverShifted/LiquidGlass --recursive
```
or run
```sh
git submodule update --init --recursive
```
after cloning normally.

Then you just need to build the CMake project by running `./build.sh`, or executing these commands:
```sh
cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
cmake --build build
```

## Screenshots
![Full effect](https://raw.githubusercontent.com/OverShifted/LiquidGlass/refs/heads/master/assets/showcase/full.png)

![Just refraction](https://raw.githubusercontent.com/OverShifted/LiquidGlass/refs/heads/master/assets/showcase/just-refraction.png)

![Just refraction, but inverted](https://raw.githubusercontent.com/OverShifted/LiquidGlass/refs/heads/master/assets/showcase/just-refraction-inverted.png)
