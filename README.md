# Simple Shell!

This is the second *big* project on our low level programming curriculum at holberton school.

## How to use

compile it with:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh` 

execute it with:

`./hsh`

## builtin commands

### cd

use `cd` to change directory like so:

`cd <directory>`

Passing `cd` alone will change directory to $HOME.

### exit

use `exit` to exit the terminal with an optinal status.

`exit <status>`

passing `exit` alone will exit with status 0.

### env

use `env` to print environment variables

