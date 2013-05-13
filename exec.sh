cp $1 orig
cp $1 base
cd orig
./tree.out $1
./symbol.out $1 > ../cuadruples.txt