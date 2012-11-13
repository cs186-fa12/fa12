# This script recompiles and restarts postgres, making sure to take in header file changes.

# Clean .h folders to make sure we find changes.
make clean -C src/include/utils/
make clean -C src/include/nodes/

# Compile!
make -j4 2>&1 | tee make_output.tmp # eff bash

# Error checking
numError=`cat make_output.tmp | grep "*** .* Error " | wc -l`
numWarning=`cat make_output.tmp | grep ": warning:" | wc -l`

# Print out errors/warnings we found
if [ $numError != '0' ]; then
    make # Remake to show compiler errors
    echo -e "\e[00;31mERROR:\e[00m Compilation failed."
    exit
fi

# Install the changes
make install

if [ $numWarning == '1' ]; then
    echo -e "\e[00;33m$numWarning compiler warning detected. Check make_output.tmp!\e[00m"
elif [ $numWarning != '0' ]; then
    echo -e "\e[00;33m$numWarning compiler warnings detected. Check make_output.tmp!\e[00m"
else
    echo ">> No compiler warnings from changed sources."
fi

# Restart postgres
$HOME/pgsql/bin/pg_ctl -m fast -D $HOME/pgsql/data -o "-p 11111" stop
cat /dev/null > log.txt
$HOME/pgsql/bin/pg_ctl -D ~/pgsql/data -o "-p 11111 -s" -l hw5.log start

echo -e "\e[00;32mReady to go!\e[00m"
echo -e "Connect to the db using pgsql, or check the server logs from hw5.log!"