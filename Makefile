OBJ = main.o
CC = g++

compile: $(OBJ)
	@echo [CPP] Link tss...
	@$(CC) -fpermissive -W -w -fstack-check -o tss main.o
	@echo [CPP] Finished!
	@echo "–––––––––––––––––––––––––––"
	@rm main.o

main.o:
	@clear
	@echo "–––––––––––––––––––––––––––"
	@echo [CPP] Compile tss...
	@$(CC) -fpermissive -W -w -fstack-check -c main.cpp
	@echo [CPP] Finished!
	@echo "–––––––––––––––––––––––––––"

windows:
	@clear
	@echo "[ MINGW-W64 ] Compile and Link main.cpp to tss.EXE..."
	@i686-w64-mingw32-g++ -W -fstack-check -static -static-libstdc++ -static-libgcc -lpthread -fpermissive -c main.cpp
	@i686-w64-mingw32-g++ -W -fstack-check -static -static-libstdc++ -static-libgcc -lpthread -fpermissive -o tss.exe main.o
	@echo "[ MINGW-W64 ] Finished!"
	@rm main.o

test: compile
	@clear
	@./tss tests/test.tss

install: compile
	@echo "[CP] tss /bin/"
	@sudo cp tss /bin/
	@echo [CP] Finished!
	@echo "–––––––––––––––––––––––––––"
