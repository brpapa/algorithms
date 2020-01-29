# exec: ./mark-problem-as-solved.sh JUDGE-NAME PROBLEM-NAME-WITHOUT-CPP

git add $1/$2.cpp
git ls-files > _scripts/files-tracked-on-git.lock
./_scripts/run-auto-scripts.sh