# exec: ./mark-problem-as-solved.sh JUDGE-NAME PROBLEM-NAME-WITHOUT-CPP

git add $1/$2.cpp
git ls-files > _scripts/files-tracked-on-git.lock

# compile and run auto scripts
for file in _scripts/*.cpp
do
   if [[ ! -e "${file%.cpp}" ]]
   then
      g++ -std=gnu++14 ${file} -o ${file%.cpp}
   fi
   ./${file%.cpp}
done

git add --update