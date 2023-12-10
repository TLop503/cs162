echo "Setting up + running linked_list"
echo
echo
cd ./linked_list
echo "running make clean"
make clean
echo "running make"
make
echo "running valgrind"
valgrind --leak-check=full --show-leak-kinds=all ./linklist
echo
echo
read -p "Press enter to continue"
echo
echo
echo "Setting up + running recursion"
cd ../recursion
echo "running make clean"
make clean
echo "running make"
make
echho "running valgrind"
valgrind --leak-check=full --show-leak-kinds=all ./recur
echo
read -p "Press enter to continue"
echo
echo
cd ../
echo "For extra credit:"
echo "The TA grading this is: "
echo $USER

{ echo "TA Grading is: $USER"; cat README.txt; } >README.new && mv README.new README.txt


