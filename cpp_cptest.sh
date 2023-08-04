
#!/bin/bash

problem_name=$1
test_dir=test/${problem_name}
base_url=${problem_name%_*}

# make test directory
if [ ! -e ${test_dir} ]; then
    oj dl -d test/${problem_name} https://atcoder.jp/contests/${base_url}/tasks/${problem_name//-/_}
fi

g++ cpp_problems/${problem_name}.cpp -o cpp_problems/tmp.out

if [ $? -ne 0 ]; then
  echo "Compiling was failed"
  exit
fi

oj test -c "./cpp_problems/tmp.out" -d test/${problem_name}
