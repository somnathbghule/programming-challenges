#gdb --batch --command=cmds.gdb --args ./programming-challenges < 02_08_04_CryptKicker.txt
b writeOutput()
run 
p *this
