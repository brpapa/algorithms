# exec: ./compile-and-run.sh PATH

PATH=$1
EXT=${PATH##*.}

if [[ ${EXT} == "cpp" ]]; then
   /usr/bin/g++ ${PATH} -std=gnu++14 -O2 -lm -o e && ./e < input > output
elif [[ ${EXT} == "py" ]]; then
   /usr/bin/python3 ${PATH} < input > output
fi

