# auto-scripts são aqueles executados antes de todo push

if [[ ! -e "_scripts/auto-md-local" ]]
then
   g++ -std=gnu++14 _scripts/auto-md-local.cpp -o _scripts/auto-md-local
fi

if [[ ! -e "_scripts/auto-md" ]]
then
   g++ -std=gnu++14 _scripts/auto-md.cpp -o _scripts/auto-md
fi

if [[ ! -e "_scripts/auto-csv" ]]
then
   g++ -std=gnu++14 _scripts/auto-csv.cpp -o _scripts/auto-csv
fi

./_scripts/auto-md-local
./_scripts/auto-md
./_scripts/auto-csv
git add --update