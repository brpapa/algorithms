# usage: ./mark-problem-as-solved.sh JUDGE-NAME PROBLEM-NAME-WITH-EXTENSION

file_csv="./_scripts/auto-problems-csv.cpp"
file_md="./_scripts/auto-readme-md.py"
file_cache="./_scripts/files-tracked-on-git.txt"

git add $1/$2
git ls-files > ${file_cache}

if [[ ! -e "${file_csv%.cpp}" ]]
then
   g++ -std=gnu++14 ${file_csv} -o ${file_csv%.cpp}
fi

# create .csv
./${file_csv%.cpp}

# create .md
python ${file_md}

git add --update
