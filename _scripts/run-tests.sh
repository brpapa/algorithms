# executar na raiz do projeto
# chmod u+x THIS_FILE_PATH, se não tiver permissão

#! compile o .cpp antes

#! exec: ./run-tests.sh TESTS_FOLDER (from _tests/)
#  e.g.: ./run-tests.sh regional-2019/M

cd _tests
mkdir $1/my-output

for file in $1/input/*
do 
   file=$(basename $file)
   ./../e < $1/input/$file > $1/my-output/$file && ./$1/compare/cpp $1/output/$file $1/my-output/$file
done