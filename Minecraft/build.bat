echo off
PATH=c:\pspsdk\bin;%cd%;
make
move EBOOT.PBP ../Game/
cd ../Game/
pause
EBOOT.PBP