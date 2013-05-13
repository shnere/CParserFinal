cp $1 orig
cp $1 base
cd orig
./symbol.out $1
cat cuadruples.txt
./assembler.out > assembly.a
cat assembly.a
java -jar ../simulator.jar
