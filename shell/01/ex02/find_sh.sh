find . -type f -name '*.sh' | xargs basename -a | sed 's/\.sh$//'
