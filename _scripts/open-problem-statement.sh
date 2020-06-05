# usage: ./open-problem-statement.sh FOLDER-NAME PROBLEM-ID-WITHOUT-CPP

FOLDER=$1
FILE=$2

# no support
if [[ $FOLDER == "code-jam" ]]
then
   return
fi

# warning
if [[ $FOLDER == "live-archive" ]]
then
   FOLDER="live_archive"
fi

FILE_uva=${FILE::${#FILE}-2}"/${FILE}.pdf"
FILE_live_archive=${FILE::${#FILE}-2}"/${FILE}.pdf"
FILE_codeforces=${FILE/-//}
FILE_uri=${FILE}
FILE_spoj=${FILE}

BASE_URL_uva="https://onlinejudge.org/external/"
BASE_URL_live_archive="https://icpcarchive.ecs.baylor.edu/external/"
BASE_URL_codeforces="https://codeforces.com/problemset/problem/"
BASE_URL_uri="https://www.urionlinejudge.com.br/judge/problems/view/"
BASE_URL_spoj="https://spoj.com/problems/"

url_judge=BASE_URL_$FOLDER
file_judge=FILE_$FOLDER
open "${!url_judge}${!file_judge}"
