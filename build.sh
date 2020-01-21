cd Minecraft
make -j16 -f MakefileGame
cp EBOOT.PBP ../Game/
cp Minecraft.prx ../Game/
cp Minecraft.elf ../Game/
mv EBOOT.PBP ../../Game/
mv Minecraft.prx ../../Game/
mv Minecraft.elf ../../Game/
cd ..
