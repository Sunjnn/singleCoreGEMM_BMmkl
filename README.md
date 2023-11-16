# singleCoreGEMM_BMmkl

Benchmark of MKL for single core GEMM.

## build and run

### manually

Environment variables needed to be set before build.

``` bash
source setvars.sh
```

Build this project in directory `build`.
Follow commands below.

``` bash
mkdir build && cd build
cmake .. --DCMAKE_CXX_COMPILER=icpx
make
```

Run in directory `build`.

``` bash
./singleCoreGEMM_BMmkl [size]
```

### automatically

Run the script `run.sh` to build and run automatically.
It will execute GEMM with sizes [8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768].

``` bash
bash run.sh
```
