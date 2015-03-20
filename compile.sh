rm -rf build
mkdir build
cd build
cmake -DUSEVECEXTENSIONS=ON -DUSE_BOOST_SIMD=ON -DUSEAVX=ON ..
make clean
make
cd ..
