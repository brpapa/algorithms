# executar na raiz do projeto
# chmod u+x THIS_FILE_PATH, se não tiver permissão

#! compile o .cpp antes

#! exec: ./run-tests.sh TESTS_FOLDER (from _tests/)
#  e.g.: ./run-tests.sh regional-2019/M

mkdir _tests/$1/my-output

for file in _tests/$1/input/*
do 
   file=$(basename $file)
   ./e < _tests/$1/input/$file > _tests/$1/my-output/$file && ./_tests/$1/compare/cpp _tests/$1/output/$file _tests/$1/my-output/$file
done