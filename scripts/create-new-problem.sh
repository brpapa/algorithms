# usage: ./new-problem.sh JUDGE PROBLEM-ID-WITHOUT-CPP

# TEMPLATE='#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n\tint T; cin >> T;\n\twhile (T--) {\n\t\tint ans;\n\t\tprintf("%d\\n", ans);\n\t}\n\treturn 0;\n}'
TEMPLATE='#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\n\nint main() {\n\treturn 0;\n}'

if [[ -e "solutions/$1/$2.cpp" ]]; then
   "solutions/$1/$2.cpp"
else
   echo $TEMPLATE > "solutions/$1/$2.cpp"
   open "solutions/$1/$2.cpp"
fi
