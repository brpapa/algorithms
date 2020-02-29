# exec: ./mark-problem-as-solved.sh JUDGE-NAME PROBLEM-NAME-WITH-EXTENSION

file1="_scripts/auto-csv.cpp"
file2="_scripts/auto-md.py"

git add $1/$2
git ls-files > files-tracked-on-git.txt

if [[ ! -e "${file1%.cpp}" ]]
then
   g++ -std=gnu++14 ${file1} -o ${file1%.cpp}
fi

# create .csv
./${file1%.cpp}

# create .md
python ${file2}

git add --update
