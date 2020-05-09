# usage: ./open-problem-statement.sh FOLDER-NAME PROBLEM-ID-WITHOUT-CPP

FOLDER=$1
FILE=$2

# no support
if [[ $FOLDER == "code-jam" ]]
then
   return
fi

# overwrite FOLDER and FILE with the respective judge name and problem id
if [[ $FOLDER == "icpc" ]]
then
   arr=()
   IFS='-' read -ra ADDR <<< "$FILE"
   for i in "${ADDR[@]}"; do
      arr+=("$i")
   done

   FOLDER=${arr[2]}
   FILE=${arr[3]}
fi

FILE_uva=${FILE::${#FILE}-2}"/${FILE}.pdf"
FILE_codeforces=${FILE/-//}
FILE_uri=${FILE}
FILE_spoj=${FILE}

BASE_URL_uva="https://onlinejudge.org/external/"
BASE_URL_codeforces="https://codeforces.com/problemset/problem/"
BASE_URL_uri="https://www.urionlinejudge.com.br/judge/problems/view/"
BASE_URL_spoj="https://spoj.com/problems/"

url_judge=BASE_URL_$FOLDER
file_judge=FILE_$FOLDER
open "${!url_judge}${!file_judge}"
