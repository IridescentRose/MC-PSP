cd Minecraft
make -j16 -f MakefileGame
mv EBOOT.PBP ../Game/
mv Minecraft.prx ../Game/
mv Minecraft.elf ../Game/
cd ..
