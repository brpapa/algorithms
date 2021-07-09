# usage: ./mark-problem-as-solved.sh JUDGE-FOLDER-PATH PROBLEM-NAME-WITH-EXTENSION

file_md="./scripts/index-solutions/runner.py"

git add $1/$2

python3 ${file_md}

git add --update
