# executar na raiz do projeto
# chmod u+x THIS_FILE_PATH, se não tiver permissão

#! exec: ./new-problem.sh JUDGE-NAME PROBLEM-NAME-WITHOUT-CPP

if [[ -e "$1/$2" ]]
then
   open $1/$2.cpp
else
   echo "#include <iostream>\n#include <vector>\nusing namespace std;\n\nint main() {\n\tios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\n\treturn 0;\n}" > $1/$2.cpp
   open $1/$2.cpp
fi