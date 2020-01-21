# exec: ./problem-solved.sh JUDGE-NAME PROBLEM-NAME-WITHOUT-CPP

# !checar antes se arquivo já foi marcado como resolvido
git add $1/$2.cpp
# git commit -m "solved: $2 from $1"
# git push origin master
git ls-files > _scripts/files-tracked-on-git.lock