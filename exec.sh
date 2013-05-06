cp $1 orig
cp $1 base
cd orig
./a.out $1
cd ../base
./C_Compiler < $1