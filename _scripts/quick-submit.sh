# usage: ./quick-submit.sh JUDGE-NAME

FOLDER=$1

if [[ $FOLDER == "live-archive" ]]; then
   FOLDER="live_archive"
fi

# no support
if [[ $FOLDER != "live_archive" ]] && [[ $FOLDER != "uva" ]]; then
   return
fi

URL_uva="https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=25&page=submit_problem"
URL_live_archive="https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=25"

URL=URL_$FOLDER
open "${!URL}"
