## Raytracer

[![Build Status](https://travis-ci.com/Pleuvens/RayTracer.svg?branch=master)](https://travis-ci.com/Pleuvens/RayTracer)
[![codecov](https://codecov.io/gh/Pleuvens/Raytracer/branch/master/graph/badge.svg)](https://codecov.io/gh/Pleuvens/Raytracer)

This is a Raytracer in C++ made following The RayTracer Challenge by Jamis Buck

This project is using CMake version 3.15.3-2

## Compile the project

In order to compile this project you need to execute the following commands:

```
prompt$ mkdir build
prompt$ cd build
prompt$ cmake ..
prompt$ make
prompt$ ./Raytracer
```

## Launch Testsuite

In order to launch the testsuite you need to execute the following commands:

```
prompt$ mkdir build
prompt$ cd build
prompt$ cmake .. -DCMAKE_BUILD_TYPE=Test
prompt$ make
prompt$ ./Tests
```
