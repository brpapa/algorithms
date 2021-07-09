# usage: ./open-problem-statement.sh JUDGE-FOLDER-PATH PROBLEM-ID-WITHOUT-CPP

JUDGE=$1
JUDGE=${JUDGE:10}
FILE=$2

if [[ $JUDGE == "live-archive" ]]
then
   JUDGE="live_archive"
fi

# ignore if is no supported
if [[ $JUDGE != "uva" ]] && [[ $JUDGE != "live_archive" ]] && [[ $JUDGE != "codeforces" ]] && [[ $JUDGE != "uri" ]] && [[ $JUDGE != "spoj" ]] && [[ $JUDGE != "timus" ]] && [[ $JUDGE != "kattis" ]]
then
   return
fi

FILE_uva=${FILE::${#FILE}-2}"/${FILE}.pdf"
FILE_live_archive=${FILE::${#FILE}-2}"/${FILE}.pdf"
FILE_codeforces=${FILE/-//}
FILE_uri=${FILE}
FILE_spoj=${FILE}
FILE_timus=${FILE}
FILE_kattis=${FILE}

BASE_URL_uva="https://onlinejudge.org/external/"
BASE_URL_live_archive="https://icpcarchive.ecs.baylor.edu/external/"
BASE_URL_codeforces="https://codeforces.com/problemset/problem/"
BASE_URL_uri="https://www.urionlinejudge.com.br/judge/problems/view/"
BASE_URL_spoj="https://spoj.com/problems/"
BASE_URL_timus="https://acm.timus.ru/problem.aspx?space=1&num="
BASE_URL_kattis="https://open.kattis.com/problems/"

url_judge=BASE_URL_$JUDGE
file_judge=FILE_$JUDGE
open "${!url_judge}${!file_judge}"
