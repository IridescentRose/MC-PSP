#include <iostream>
#include <stdio.h>
#include <typeinfo>

struct Block {
	uint8_t ID, meta, topAtlas, bottomAtlas, frontAtlas, backAtlas, leftAtlas, rightAtlas, meshType;
	bool breakable, transparent, lightSource, special;
};

int main(){
    std::cout << "Welcome to the Minecraft BlockData Generator for Minecraft-PSP: \n" << std::endl;

    std::cout << "Please enter the data as asked for below." << std::endl; 
    std::cout << "Thank you. Type 0 as the ID to quit.\n" << std::endl;

    FILE* f = fopen("../../Game/assets/blockData.dat", "wb");

    int num = 0;

    struct Block def;
    def = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1};

    fwrite(&def, sizeof(Block), 1, f);

    while(true){
        struct Block b;

        std::cout << "Block ID: ";
        scanf("%d", (int*)&b.ID);

        std::cout << b.ID;

        if(b.ID <= 0)
            break;
        

        std::cout << "Block Metadata: ";
        scanf("%d", (int*)&b.meta);

        std::cout << "Atlases (space separated) in this order: Top Bottom Front Back Left Right" << std::endl;
        
        scanf("%d %d %d %d %d %d", (int*)&b.topAtlas, (int*)&b.bottomAtlas, (int*)&b.frontAtlas, (int*)&b.backAtlas, (int*)&b.leftAtlas, (int*)&b.rightAtlas);

        std::cout << "Mesh Type: (0 - solid, 1 - flora, 2 - liquid)" << std::endl;
        scanf("%d", (int*)&b.meshType);

        std::cout << "Breakable: ";
        scanf("%d", (int*)&b.breakable);

        std::cout << "Transparent: ";
        scanf("%d", (int*)&b.transparent);

        std::cout << "Light Source: ";
        scanf("%d", (int*)&b.lightSource);

        std::cout << "Special: ";
        scanf("%d", (int*)&b.special);

        std::cout << std::endl << std::endl;

        fwrite(&b, sizeof(Block), 1, f);
        num++;
    }

    std::cout << "Number of Blocks: " << std::endl;

    fclose(f);

    return 0;

}