#!bin/bash

valgrind ./minishell << "end"
<< EOF cat
$USER
$USER$USER
$?
$?$?
$USER$?$USER
$$$
EOF
end