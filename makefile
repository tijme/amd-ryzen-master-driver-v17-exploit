INPUTNAME := AMDRyzenMasterDriverV17Exploit
BOFNAME := RyzenMasterExploit
CC_x64 := x86_64-w64-mingw32-gcc
CC_x86 := i686-w64-mingw32-gcc

all:
	$(CC_x64) -Wl,--stack,4096000 -c ./$(INPUTNAME).c -o ./$(BOFNAME).x64.o -masm=intel -DBOF 
	$(CC_x86) -Wl,--stack,4096000 -c ./$(INPUTNAME).c -o ./$(BOFNAME).x86.o -masm=intel -DBOF 
	$(CC_x64) ./$(INPUTNAME).c -o ./$(BOFNAME).x64.exe -masm=intel -lole32 -loleaut32 -lntdll
	$(CC_x86) ./$(INPUTNAME).c -o ./$(BOFNAME).x86.exe -masm=intel -lole32 -loleaut32 -lntdll

clean:
	rm ./$(BOFNAME).*.exe ./$(BOFNAME).*.o