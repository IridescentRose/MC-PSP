#include "BlockData.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

BlockData::BlockData()
{

}

void BlockData::loadBlockData()
{
	//AIR
	block_data.emplace(ChunkBlock(0, 0), new Block(-1, -1, -1, -1, -1, -1, 
												0, 0, true, false, false));

	//STONE
	block_data.emplace(ChunkBlock(1, 0), new Block(1, 1, 1, 1, 1, 1, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(1, 0));
	//GRANITE
	block_data.emplace(ChunkBlock(1, 1), new Block(2, 2, 2, 2, 2, 2, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(1, 1));
	//POLISHED GRANITE
	block_data.emplace(ChunkBlock(1, 2), new Block(3, 3, 3, 3, 3, 3, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(1, 2));
	//DIORITE
	block_data.emplace(ChunkBlock(1, 3), new Block(4, 4, 4, 4, 4, 4, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(1, 3));
	//POLISHED DIORITE
	block_data.emplace(ChunkBlock(1, 4), new Block(5, 5, 5, 5, 5, 5, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(1, 4));
	//ANDESITE
	block_data.emplace(ChunkBlock(1, 5), new Block(6, 6, 6, 6, 6, 6, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(1, 5));
	//POLISHED ANDESITE
	block_data.emplace(ChunkBlock(1, 6), new Block(7, 7, 7, 7, 7, 7, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(1, 6));
	//GRASS
	block_data.emplace(ChunkBlock(2, 0), new Block(8, 11, 9, 9, 9, 9, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(2, 0));
	//DIRT
	block_data.emplace(ChunkBlock(3, 0), new Block(11, 11, 11, 11, 11, 11, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(3, 0));
	//COARSE DIRT
	block_data.emplace(ChunkBlock(3, 1), new Block(12, 12, 12, 12, 12, 12, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(3, 1));
	//PODZOL
	block_data.emplace(ChunkBlock(3, 2), new Block(13, 11, 14, 14, 14, 14, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(3, 2));
	//COBBLE
	block_data.emplace(ChunkBlock(4, 0), new Block(15, 15, 15, 15, 15, 15, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(4, 0));
	//WOOD
	block_data.emplace(ChunkBlock(5, 0), new Block(16, 16, 16, 16, 16, 16, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(5, 0));
	block_data.emplace(ChunkBlock(5, 1), new Block(17, 17, 17, 17, 17, 17, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(5, 1));
	block_data.emplace(ChunkBlock(5, 2), new Block(18, 18, 18, 18, 18, 18, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(5, 2));
	block_data.emplace(ChunkBlock(5, 3), new Block(19, 19, 19, 19, 19, 19, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(5, 3));
	block_data.emplace(ChunkBlock(5, 4), new Block(20, 20, 20, 20, 20, 20, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(5, 4));
	block_data.emplace(ChunkBlock(5, 5), new Block(21, 21, 21, 21, 21, 21, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(5, 5));
	block_data.emplace(ChunkBlock(6, 0), new Block(22, 22, 22, 22, 22, 22, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(6, 0));
	block_data.emplace(ChunkBlock(6, 1), new Block(23, 23, 23, 23, 23, 23, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(6, 1));
	block_data.emplace(ChunkBlock(6, 2), new Block(24, 24, 24, 24, 24, 24, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(6, 2));
	block_data.emplace(ChunkBlock(6, 3), new Block(25, 25, 25, 25, 25, 25, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(6, 3));
	block_data.emplace(ChunkBlock(6, 4), new Block(26, 26, 26, 26, 26, 26, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(6, 4));
	block_data.emplace(ChunkBlock(6, 5), new Block(27, 27, 27, 27, 27, 27, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(6, 5));
	block_data.emplace(ChunkBlock(7, 0), new Block(28, 28, 28, 28, 28, 28, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(7, 0));
	block_data.emplace(ChunkBlock(8, 0), new Block(-1, -1, -1, -1, -1, -1, 
												0, 0, true, false, true));
	block_data.emplace(ChunkBlock(9, 0), new Block(-1, -1, -1, -1, -1, -1, 
												0, 0, true, false, true));
	block_data.emplace(ChunkBlock(10, 0), new Block(-1, -1, -1, -1, -1, -1, 
												0, 0, true, false, true));
	block_data.emplace(ChunkBlock(11, 0), new Block(-1, -1, -1, -1, -1, -1, 
												0, 0, true, false, true));
	block_data.emplace(ChunkBlock(12, 0), new Block(29, 29, 29, 29, 29, 29, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(12, 0));
	block_data.emplace(ChunkBlock(12, 1), new Block(30, 30, 30, 30, 30, 30, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(12, 1));
	block_data.emplace(ChunkBlock(13, 0), new Block(31, 31, 31, 31, 31, 31, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(13, 0));
	block_data.emplace(ChunkBlock(14, 0), new Block(32, 32, 32, 32, 32, 32, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(14, 0));
	block_data.emplace(ChunkBlock(15, 0), new Block(33, 33, 33, 33, 33, 33, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(15, 0));
	block_data.emplace(ChunkBlock(16, 0), new Block(34, 34, 34, 34, 34, 34, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(16, 0));
	block_data.emplace(ChunkBlock(17, 0), new Block(35, 35, 36, 36, 36, 36, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(17, 0));
	block_data.emplace(ChunkBlock(17, 1), new Block(37, 37, 38, 38, 38, 38, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(17, 1));
	block_data.emplace(ChunkBlock(17, 2), new Block(39, 39, 40, 40, 40, 40, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(17, 2));
	block_data.emplace(ChunkBlock(17, 3), new Block(41, 41, 42, 42, 42, 42, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(17, 3));
	block_data.emplace(ChunkBlock(18, 0), new Block(43, 43, 43, 43, 43, 43, 
												0, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(18, 0));
	block_data.emplace(ChunkBlock(18, 1), new Block(44, 44, 44, 44, 44, 44, 
												0, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(18, 1));
	block_data.emplace(ChunkBlock(18, 2), new Block(45, 45, 45, 45, 45, 45, 
												0, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(18, 2));
	block_data.emplace(ChunkBlock(18, 3), new Block(46, 46, 46, 46, 46, 46, 
												0, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(18, 3));
	block_data.emplace(ChunkBlock(19, 0), new Block(47, 47, 47, 47, 47, 47, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(19, 0));
	block_data.emplace(ChunkBlock(19, 1), new Block(48, 48, 48, 48, 48, 48, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(19, 1));
	block_data.emplace(ChunkBlock(20, 0), new Block(49, 49, 49, 49, 49, 49, 
												0, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(20, 0));
	block_data.emplace(ChunkBlock(21, 0), new Block(50, 50, 50, 50, 50, 50, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(21, 0));
	block_data.emplace(ChunkBlock(22, 0), new Block(51, 51, 51, 51, 51, 51, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(22, 0));
	block_data.emplace(ChunkBlock(23, 0), new Block(130, 130, 53, 131, 131, 131, 
												0, 0, false, false, false));
	block_data.emplace(ChunkBlock(24, 0), new Block(54, 55, 56, 56, 56, 56, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(24, 0));
	block_data.emplace(ChunkBlock(24, 1), new Block(54, 55, 58, 58, 58, 58, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(24, 1));
	block_data.emplace(ChunkBlock(24, 2), new Block(54, 55, 57, 57, 57, 57, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(24, 2));
	block_data.emplace(ChunkBlock(25, 0), new Block(59, 59, 59, 59, 59, 59, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(25, 0));
	block_data.emplace(ChunkBlock(26, 0), new Block(-1, -1, -1, -1, -1, -1, 
												0, 0, false, false, true));
	block_data.emplace(ChunkBlock(27, 0), new Block(60, 60, 60, 60, 60, 60, 
												1, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(27, 0));
	block_data.emplace(ChunkBlock(28, 0), new Block(62, 62, 62, 62, 62, 62, 
												1, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(28, 0));
	block_data.emplace(ChunkBlock(29, 0), new Block(70, 70, 70, 70, 69, 72, 
												0, 0, false, false, true));
	block_data.emplace(ChunkBlock(30, 0), new Block(64, 64, 64, 64, 64, 64, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(30, 0));
	block_data.emplace(ChunkBlock(31, 0), new Block(67, 67, 67, 67, 67, 67, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(31, 0));
	block_data.emplace(ChunkBlock(31, 1), new Block(65, 65, 65, 65, 65, 65, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(31, 1));
	block_data.emplace(ChunkBlock(31, 2), new Block(66, 66, 66, 66, 66, 66, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(31, 2));
	block_data.emplace(ChunkBlock(32, 0), new Block(67, 67, 67, 67, 67, 67, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(32, 0));
	block_data.emplace(ChunkBlock(33, 0), new Block(70, 70, 70, 70, 68, 72, 
												0, 0, false, false, true));
	block_data.emplace(ChunkBlock(34, 0), new Block(-1, -1, -1, -1, -1, -1, 
												0, 0, false, false, true));
	block_data.emplace(ChunkBlock(35, 0), new Block(73, 73, 73, 73, 73, 73, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 0));
	block_data.emplace(ChunkBlock(35, 1), new Block(74, 74, 74, 74, 74, 74, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 1));
	block_data.emplace(ChunkBlock(35, 2), new Block(75, 75, 75, 75, 75, 75, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 2));
	block_data.emplace(ChunkBlock(35, 3), new Block(76, 76, 76, 76, 76, 76, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 3));
	block_data.emplace(ChunkBlock(35, 4), new Block(77, 77, 77, 77, 77, 77, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 4));
	block_data.emplace(ChunkBlock(35, 5), new Block(78, 78, 78, 78, 78, 78, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 5));
	block_data.emplace(ChunkBlock(35, 6), new Block(79, 79, 79, 79, 79, 79, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 6));
	block_data.emplace(ChunkBlock(35, 7), new Block(80, 80, 80, 80, 80, 80, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 7));
	block_data.emplace(ChunkBlock(35, 8), new Block(81, 81, 81, 81, 81, 81, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 8));
	block_data.emplace(ChunkBlock(35, 9), new Block(82, 82, 82, 82, 82, 82, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 9));
	block_data.emplace(ChunkBlock(35, 10), new Block(83, 83, 83, 83, 83, 83, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 10));
	block_data.emplace(ChunkBlock(35, 11), new Block(84, 84, 84, 84, 84, 84, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 11));
	block_data.emplace(ChunkBlock(35, 12), new Block(85, 85, 85, 85, 85, 85, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 12));
	block_data.emplace(ChunkBlock(35, 13), new Block(86, 86, 86, 86, 86, 86, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 13));
	block_data.emplace(ChunkBlock(35, 14), new Block(87, 87, 87, 87, 87, 87, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 14));
	block_data.emplace(ChunkBlock(35, 15), new Block(88, 88, 88, 88, 88, 88, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(35, 15));
	block_data.emplace(ChunkBlock(36, 0), new Block(89, 89, 89, 89, 89, 89, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(36, 0));
	block_data.emplace(ChunkBlock(37, 0), new Block(90, 90, 90, 90, 90, 90, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(37, 0));
	block_data.emplace(ChunkBlock(37, 1), new Block(91, 91, 91, 91, 91, 91, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(37, 1));
	block_data.emplace(ChunkBlock(37, 2), new Block(92, 92, 92, 92, 92, 92, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(37, 2));
	block_data.emplace(ChunkBlock(37, 3), new Block(93, 93, 93, 93, 93, 93, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(37, 3));
	block_data.emplace(ChunkBlock(37, 4), new Block(94, 94, 94, 94, 94, 94, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(37, 4));
	block_data.emplace(ChunkBlock(37, 5), new Block(95, 95, 95, 95, 95, 95, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(37, 5));
	block_data.emplace(ChunkBlock(37, 6), new Block(96, 96, 96, 96, 96, 96, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(37, 6));
	block_data.emplace(ChunkBlock(37, 7), new Block(97, 97, 97, 97, 97, 97, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(37, 7));
	block_data.emplace(ChunkBlock(37, 8), new Block(98, 98, 98, 98, 98, 98, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(37, 8));
	block_data.emplace(ChunkBlock(39, 0), new Block(99, 99, 99, 99, 99, 99, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(39, 0));
	block_data.emplace(ChunkBlock(40, 0), new Block(100, 100, 100, 100, 100, 100, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(40, 0));
	block_data.emplace(ChunkBlock(41, 0), new Block(101, 101, 101, 101, 101, 101, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(41, 0));
	block_data.emplace(ChunkBlock(42, 0), new Block(102, 102, 102, 102, 102, 102, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(42, 0));


}
BlockData BlockData::instance;

BlockData *BlockData::InstancePointer()
{
	return &instance;
}