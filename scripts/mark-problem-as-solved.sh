# usage: ./mark-problem-as-solved.sh JUDGE-FOLDER-PATH PROBLEM-NAME-WITH-EXTENSION

file_md="./scripts/auto-readme-md.py"

git add $1/$2

if [[ ! -e "${file_csv%.cpp}" ]]
then
   g++ -std=gnu++14 ${file_csv} -o ${file_csv%.cpp}
fi

# create README.md
python ${file_md}

git add --update
