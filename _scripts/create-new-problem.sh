# exec: ./new-problem.sh JUDGE-NAME PROBLEM-ID-WITHOUT-CPP

if [[ -e "$1/$2.cpp" ]]
then
   open $1/$2.cpp
else
   echo "#include <iostream>\n#include <vector>\nusing namespace std;\n\nint main() {\n   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\n   return 0;\n}" > $1/$2.cpp
   open $1/$2.cpp
fi