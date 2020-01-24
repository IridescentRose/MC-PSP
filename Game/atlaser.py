from PIL import Image, ImageOps
import sys
 

test_img = Image.open("assets/minecraft/textures/blocks/dirt.png")

size = test_img.size
test_img.close()

default_size = size[0]

#New image must be 25 * size by 25 * size

ROWS = 32
COLUMNS = 32

atlas = Image.new("RGBA", (ROWS * default_size, COLUMNS * default_size), 0)


# TEST FOR NOW, load from file later!
if len(sys.argv) - 1 == 0:
    fp = open("blocktex_list.txt", "r")
else:
    fp = open("itemtex_list.txt", "r")


line = fp.readline()

count = 0
while line:
    if len(sys.argv) - 1 == 0:
        img = Image.open("assets/minecraft/textures/blocks/" + line.strip() + ".png")
        img_flip = ImageOps.mirror(img) 
        atlas.paste( img_flip, ( (count % COLUMNS) * default_size, count // COLUMNS * default_size))
    else:
        img = Image.open("assets/minecraft/textures/items/" + line.strip() + ".png")
        img_flip = ImageOps.mirror(img) 
        atlas.paste( img_flip, ( (count % COLUMNS) * default_size, count // COLUMNS * default_size))
    line = fp.readline()
    count = count + 1

fp.close()

if len(sys.argv) - 1 == 0:
    atlas.save("assets/minecraft/textures/terrain_atlas.png", "PNG")
else:
    atlas.save("assets/minecraft/textures/items_atlas.png", "PNG")

