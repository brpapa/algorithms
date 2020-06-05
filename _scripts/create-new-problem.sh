# usage: ./new-problem.sh JUDGE-NAME PROBLEM-ID-WITHOUT-CPP

# TEMPLATE='#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n\tint T; cin >> T;\n\twhile (T--) {\n\t\tint ans;\n\t\tprintf("%d\\n", ans);\n\t}\n\treturn 0;\n}'
TEMPLATE='#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n\treturn 0;\n}'

if [[ -e "$1/$2.cpp" ]]; then
   open $1/$2.cpp
else
   echo $TEMPLATE > $1/$2.cpp
   open $1/$2.cpp
fi
