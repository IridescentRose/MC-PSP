PATH=c:\pspsdk\bin;%cd%;
make clean
cd ../Game/
del EBOOT.PBP
cd ../Minecraft
make
move EBOOT.PBP ../Game/
cd ../Game/
pause
EBOOT.PBP
