# usage: ./open-problem-statement.sh JUDGE-NAME PROBLEM-ID-WITHOUT-CPP

JUDGE=$1
FILE=$2

FILE_uva=${FILE::${#FILE}-2}"/${FILE}.pdf"
FILE_codeforces=${FILE/-//}
FILE_uri=${FILE}
FILE_spoj=${FILE}

BASE_URL_uva="https://onlinejudge.org/external/"
BASE_URL_codeforces="https://codeforces.com/problemset/problem/"
BASE_URL_uri="https://www.urionlinejudge.com.br/judge/problems/view/"
BASE_URL_spoj="https://spoj.com/problems/"

file_judge=FILE_$1
url_judge=BASE_URL_$1
open "${!url_judge}${!file_judge}"