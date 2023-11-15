rm -rf build
mkdir build
source setvars.sh
cd build
cmake .. -DCMAKE_CXX_COMPILER=icpx
make

elements=(8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768)

for element in "${elements[@]}"
do
    ./singleCoreGEMM_BMmkl $element
done
