# usage: ./new-problem.sh JUDGE-NAME PROBLEM-ID-WITHOUT-CPP

if [[ -e "$1/$2.cpp" ]]
then
   open $1/$2.cpp
else
   echo "#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n   \n   return 0;\n}" > $1/$2.cpp
   open $1/$2.cpp
fi