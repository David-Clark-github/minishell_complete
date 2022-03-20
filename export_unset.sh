./minishell << end
export toto
export toto=
env
export toto=azr
env
export toto=toto
env
export titi=titi
env
export tutu="tutu "
env
unset
env
unset titu
env
unset toto tiit tutu
env
unset toto
env

end
#cat minish
# diff minish vraish
