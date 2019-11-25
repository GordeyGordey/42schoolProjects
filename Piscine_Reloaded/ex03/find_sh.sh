#!/bin/sh
find . -type f -name "*.sh" | sed "s#.*/##" | rev | cut -f 2- -d "." | rev
