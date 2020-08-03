# usage: ./quick-submit.sh JUDGE-FOLDER-PATH

JUDGE=$1
JUDGE=${JUDGE:10}

if [[ $JUDGE == "live-archive" ]]; then
   JUDGE="live_archive"
fi

# no support
if [[ $JUDGE != "live_archive" ]] && [[ $JUDGE != "uva" ]]; then
   return
fi

URL_uva="https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=25&page=submit_problem"
URL_live_archive="https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=25"

URL=URL_$JUDGE
open "${!URL}"
