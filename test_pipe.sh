./minishell << end
echo > /dev/full | export tutu=tutu
echo \$?
pwd > /dev/full | env > /dev/full
end
#cat minish
# diff minish vraish
