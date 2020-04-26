# compile o .cpp antes

# usage: ./run-test-cases.sh TESTS_FOLDER (from _test-cases/)
# example: ./run-test-cases.sh regional-2019/M

cd _test-cases
mkdir $1/my-output

for file in $1/input/*
do 
   file=$(basename $file)
   ./../e < $1/input/$file > $1/my-output/$file && ./$1/compare/cpp $1/output/$file $1/my-output/$file
done