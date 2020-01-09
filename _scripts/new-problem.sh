# executar na raiz do projeto
# chmod u+x THIS_FILE_PATH, se não tiver permissão

#! exec: ./new-problem.sh JUDGE-NAME PROBLEM-NAME-WITHOUT-CPP

if [[ -e "$1/$2" ]]
then
   open $1/$2.cpp
else
   touch $1/$2.cpp && open $1/$2.cpp
fi