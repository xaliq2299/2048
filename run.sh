mv Makefile grid
cd grid
make grid
mv Makefile ..
cd ..

mv Makefile movements
cd movements
make movements
mv Makefile ..
cd ..

cd grid
mv * ../src
cd ..

cd movements
mv * ../src
cd ..

mv Makefile src
cd src
make src
mv Makefile ..
mv grid.c grid.h ../grid
mv left* right* movement* up* down* ../movements
mv *.o ..
cd ..

mkdir bin
mv *.o bin
mv Makefile bin
cd bin
make 2048
mv 2048 Makefile ..
cd ..