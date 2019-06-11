echo off
PATH=c:\pspsdk\bin;%cd%;
make
move EBOOT.PBP ../Game/
pause