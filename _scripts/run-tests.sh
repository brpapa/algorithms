# executar na raiz do projeto
# chmod u+x THIS_FILE_PATH, se não tiver permissão

#! compile o .cpp e set path antes de executar
path="_tests/regional-2019/M"

mkdir $path/my-output

for file in $path/input/*
do 
   file=$(basename $file)
   ./e < $path/input/$file > $path/my-output/$file && ./$path/compare/cpp $path/output/$file $path/my-output/$file
done