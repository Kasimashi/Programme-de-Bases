## Compile this project

```
mkdir build && cd build
cmake -G "Unix Makefiles" ..
make
```

Output :
```
make
[ 20%] Building C object src/CMakeFiles/MyStaticLib.dir/sum.c.obj
[ 40%] Building C object src/CMakeFiles/MyStaticLib.dir/function.c.obj
[ 60%] Linking C static library libMyStaticLib.a
[ 60%] Built target MyStaticLib
[ 80%] Building C object src/CMakeFiles/StaticTest.dir/main.c.obj
[100%] Linking C executable StaticTest.exe
[100%] Built target StaticTest
```