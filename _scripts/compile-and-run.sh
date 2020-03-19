# exec: ./compile-and-run.sh PATH

PATH=$1
EXT=${PATH##*.}

if [[ ${EXT} == "cpp" ]]; then
   /usr/bin/g++ ${PATH} -std=gnu++14 -O2 -lm -o z && ./z < z.in > z.out
elif [[ ${EXT} == "py" ]]; then
   /usr/bin/python3 ${PATH} < z.in > z.out
fi

