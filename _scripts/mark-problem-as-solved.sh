# exec: ./mark-problem-as-solved.sh JUDGE-NAME PROBLEM-NAME-WITH-EXTENSION

file1="_scripts/auto-csv.cpp"
file2="_scripts/auto-md.py"

git add $1/$2
git ls-files > _scripts/files-tracked-on-git.lock

# create .csv
if [[ ! -e "${file1%.cpp}" ]]
then
   g++ -std=gnu++14 ${file1} -o ${file1%.cpp}
fi
./${file1%.cpp}

# create .md
python ${file2}


git add --update
