#!/bin/bash

valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--show-reachable=yes \
	--track-origins=yes \
	--track-fds=yes\
	--trace-children=yes \
	--verbose \
	--log-file=valerr \
	"$@"