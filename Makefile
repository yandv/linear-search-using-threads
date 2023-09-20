criador:
	gcc -o out/criador.exe criador.c 
	./out/criador.exe 256
	./out/criador.exe 512
	./out/criador.exe 1024
	./out/criador.exe 2048
	./out/criador.exe 4096
	./out/criador.exe 8192
	./out/criador.exe 32768
	./out/criador.exe 131072
	./out/criador.exe 1048576
	

testador:
	gcc -o out/buscar-thread.exe buscar-thread.c 
	gcc -o out/buscar-sem-thread.exe buscar-sem-thread.c 
	clear
	time ./out/buscar-thread.exe 1048576 1708
	time ./out/buscar-sem-thread.exe 1048576 1708