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

	block_data.emplace(ChunkBlock(8, 0), new Block(446, 446, 446, 446, 446, 446, 
												2, 0, true, false, true));
	block_data.emplace(ChunkBlock(9, 0), new Block(-1, -1, -1, -1, -1, -1, 
												2, 0, true, false, true));
	block_data.emplace(ChunkBlock(10, 0), new Block(447, 447, 447, 447, 447, 447, 
												2, 0, true, false, true));
	block_data.emplace(ChunkBlock(11, 0), new Block(-1, -1, -1, -1, -1, -1, 
												2, 0, true, false, true));
	

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
												1, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(18, 0));
	block_data.emplace(ChunkBlock(18, 1), new Block(44, 44, 44, 44, 44, 44, 
												1, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(18, 1));
	block_data.emplace(ChunkBlock(18, 2), new Block(45, 45, 45, 45, 45, 45, 
												1, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(18, 2));
	block_data.emplace(ChunkBlock(18, 3), new Block(46, 46, 46, 46, 46, 46, 
												1, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(18, 3));
	block_data.emplace(ChunkBlock(19, 0), new Block(47, 47, 47, 47, 47, 47, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(19, 0));
	block_data.emplace(ChunkBlock(19, 1), new Block(48, 48, 48, 48, 48, 48, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(19, 1));
	block_data.emplace(ChunkBlock(20, 0), new Block(49, 49, 49, 49, 49, 49, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(20, 0));
	block_data.emplace(ChunkBlock(21, 0), new Block(50, 50, 50, 50, 50, 50, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(21, 0));
	block_data.emplace(ChunkBlock(22, 0), new Block(51, 51, 51, 51, 51, 51, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(22, 0));
	block_data.emplace(ChunkBlock(23, 0), new Block(131, 131, 53, 132, 132, 132, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(23, 0));
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
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(27, 0));
	block_data.emplace(ChunkBlock(28, 0), new Block(62, 62, 62, 62, 62, 62, 
												2, 3, true, false, false));
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
	block_data.emplace(ChunkBlock(37, 0), new Block(89, 89, 89, 89, 89, 89, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(37, 0));
	block_data.emplace(ChunkBlock(38, 0), new Block(90, 90, 90, 90, 90, 90, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(38, 0));
	block_data.emplace(ChunkBlock(38, 1), new Block(91, 91, 91, 91, 91, 91, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(38, 1));
	block_data.emplace(ChunkBlock(38, 2), new Block(92, 92, 92, 92, 92, 92, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(38, 2));
	block_data.emplace(ChunkBlock(38, 3), new Block(93, 93, 93, 93, 93, 93, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(38, 3));
	block_data.emplace(ChunkBlock(38, 4), new Block(94, 94, 94, 94, 94, 94, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(38, 4));
	block_data.emplace(ChunkBlock(38, 5), new Block(95, 95, 95, 95, 95, 95, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(38, 5));
	block_data.emplace(ChunkBlock(38, 6), new Block(96, 96, 96, 96, 96, 96, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(38, 6));
	block_data.emplace(ChunkBlock(38, 7), new Block(97, 97, 97, 97, 97, 97, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(38, 7));
	block_data.emplace(ChunkBlock(38, 8), new Block(98, 98, 98, 98, 98, 98, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(38, 8));
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


	block_data.emplace(ChunkBlock(43, 0), new Block(103, 103, 104, 104, 104, 104, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(43, 0));
	block_data.emplace(ChunkBlock(43, 1), new Block(54, 55, 56, 56, 56, 56, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(43, 1));
	block_data.emplace(ChunkBlock(43, 2), new Block(16, 16, 16, 16, 16, 16, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(43, 2));
	block_data.emplace(ChunkBlock(43, 3), new Block(15, 15, 15, 15, 15, 15, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(43, 3));
	block_data.emplace(ChunkBlock(43, 4), new Block(105, 105, 105, 105, 105, 105, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(43, 4));
	block_data.emplace(ChunkBlock(43, 5), new Block(185, 185, 185, 185, 185, 185, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(43, 5));
	block_data.emplace(ChunkBlock(43, 6), new Block(203, 203, 203, 203, 203, 203, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(43, 6));
	block_data.emplace(ChunkBlock(43, 7), new Block(263, 263, 263, 263, 263, 263, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(43, 7));


	//SLAVS!

	block_data.emplace(ChunkBlock(44, 0), new Block(103, 103, 104, 104, 104, 104, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(44, 0));
	block_data.emplace(ChunkBlock(44, 1), new Block(54, 55, 56, 56, 56, 56, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(44, 1));
	block_data.emplace(ChunkBlock(44, 2), new Block(16, 16, 16, 16, 16, 16, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(44, 2));
	block_data.emplace(ChunkBlock(44, 3), new Block(15, 15, 15, 15, 15, 15, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(44, 3));
	block_data.emplace(ChunkBlock(44, 4), new Block(105, 105, 105, 105, 105, 105, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(44, 4));
	block_data.emplace(ChunkBlock(44, 5), new Block(185, 185, 185, 185, 185, 185, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(44, 5));
	block_data.emplace(ChunkBlock(44, 6), new Block(203, 203, 203, 203, 203, 203, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(44, 6));
	block_data.emplace(ChunkBlock(44, 7), new Block(263, 263, 263, 263, 263, 263, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(44, 7));


	block_data.emplace(ChunkBlock(45, 0), new Block(105, 105, 105, 105, 105, 105, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(45, 0));
	block_data.emplace(ChunkBlock(46, 0), new Block(106, 108, 107, 107, 107, 107, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(46, 0));
	block_data.emplace(ChunkBlock(47, 0), new Block(16, 16, 109, 109, 109, 109, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(47, 0));
	block_data.emplace(ChunkBlock(48, 0), new Block(110, 110, 110, 110, 110, 110, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(48, 0));
	block_data.emplace(ChunkBlock(49, 0), new Block(111, 111, 111, 111, 111, 111, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(49, 0));


	block_data.emplace(ChunkBlock(50, 0), new Block(112, 112, 112, 112, 112, 112, 
												1, 11, true, false, false));
	registered_blocks.push_back(ChunkBlock(50, 0));

	//TODO: FIRE

	block_data.emplace(ChunkBlock(52, 0), new Block(113, 113, 113, 113, 113, 113, 
												1, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(52, 0));

	//TODO: STAIRS
	//TODO: BLOCK ENTITY CHEST

	block_data.emplace(ChunkBlock(55, 0), new Block(114, 114, 114, 114, 114, 114, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(55, 0));

	block_data.emplace(ChunkBlock(56, 0), new Block(116, 116, 116, 116, 116, 116, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(56, 0));
	block_data.emplace(ChunkBlock(57, 0), new Block(117, 117, 117, 117, 117, 117, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(57, 0));
	block_data.emplace(ChunkBlock(58, 0), new Block(118, 16, 120, 119, 119, 119, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(58, 0));


	block_data.emplace(ChunkBlock(59, 0), new Block(128, 128, 128, 128, 128, 128, 
												1, 8, true, false, false));
	registered_blocks.push_back(ChunkBlock(59, 0));

	block_data.emplace(ChunkBlock(60, 0), new Block(129, 11, 11, 11, 11, 11, 
												2, 7, true, false, false));
	registered_blocks.push_back(ChunkBlock(60, 0));
	block_data.emplace(ChunkBlock(61, 0), new Block(131, 131, 134, 132, 132, 132, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(61, 0));
	block_data.emplace(ChunkBlock(62, 0), new Block(131, 131, 133, 132, 132, 132, 
												0, 0, false, true, false));
	registered_blocks.push_back(ChunkBlock(62, 0));


	block_data.emplace(ChunkBlock(65, 0), new Block(137, 137, 137, 137, 137, 137, 
												1, 4, true, false, false));
	registered_blocks.push_back(ChunkBlock(65, 0));

	block_data.emplace(ChunkBlock(66, 0), new Block(138, 138, 138, 138, 138, 138, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(66, 0));

	block_data.emplace(ChunkBlock(70, 0), new Block(1, 1, 1, 1, 1, 1, 
												1, 9, true, false, false));
	registered_blocks.push_back(ChunkBlock(70, 0));
	block_data.emplace(ChunkBlock(72, 0), new Block(16, 16, 16, 16, 16, 16, 
												1, 9, true, false, false));
	registered_blocks.push_back(ChunkBlock(72, 0));
	//TODO: SIGN, DOOR, LADDER, STAIRS, SIGN, LEVER, DOOR

	block_data.emplace(ChunkBlock(73, 0), new Block(143, 143, 143, 143, 143, 143, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(73, 0));
	block_data.emplace(ChunkBlock(74, 0), new Block(143, 143, 143, 143, 143, 143, 
												0, 0, false, true, false));
	registered_blocks.push_back(ChunkBlock(74, 0));

	block_data.emplace(ChunkBlock(75, 0), new Block(144, 144, 144, 144, 144, 144, 
												1, 11, true, true, false));
	registered_blocks.push_back(ChunkBlock(75, 0));
	block_data.emplace(ChunkBlock(76, 0), new Block(145, 145, 145, 145, 145, 145, 
												1, 11, true, true, false));
	registered_blocks.push_back(ChunkBlock(76, 0));
	

	//TODO: TORCH, BUTTON


	block_data.emplace(ChunkBlock(78, 0), new Block(146, 146, 146, 146, 146, 146, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(78, 0));

	block_data.emplace(ChunkBlock(79, 0), new Block(147, 147, 147, 147, 147, 147, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(79, 0));
	block_data.emplace(ChunkBlock(80, 0), new Block(146, 146, 146, 146, 146, 146, 
												1, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(80, 0));

	block_data.emplace(ChunkBlock(81, 0), new Block(148, 150, 149, 149, 149, 149, 
												1, 10, true, false, false));
	registered_blocks.push_back(ChunkBlock(81, 0));

	block_data.emplace(ChunkBlock(82, 0), new Block(151, 151, 151, 151, 151, 151, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(82, 0));
	block_data.emplace(ChunkBlock(83, 0), new Block(152, 152, 152, 152, 152, 152, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(83, 0));
	block_data.emplace(ChunkBlock(84, 0), new Block(153, 154, 154, 154, 154, 154, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(84, 0));

	//TODO: FENCE!

	block_data.emplace(ChunkBlock(86, 0), new Block(155, 155, 158, 156, 156, 156, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(86, 0));
	block_data.emplace(ChunkBlock(87, 0), new Block(159, 159, 159, 159, 159, 159, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(87, 0));
	block_data.emplace(ChunkBlock(88, 0), new Block(160, 160, 160, 160, 160, 160, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(88, 0));
	block_data.emplace(ChunkBlock(89, 0), new Block(161, 161, 161, 161, 161, 161, 
												0, 0, false, true, false));
	registered_blocks.push_back(ChunkBlock(89, 0));
	
	//TODO: PORTAL

	block_data.emplace(ChunkBlock(91, 0), new Block(155, 155, 157, 156, 156, 156, 
												0, 0, false, true, false));
	registered_blocks.push_back(ChunkBlock(91, 0));

	//TODO: CAKE, REPEATERS


	block_data.emplace(ChunkBlock(95, 0), new Block(168, 168, 168, 168, 168, 168, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 0));
	block_data.emplace(ChunkBlock(95, 1), new Block(169, 169, 169, 169, 169, 169, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 1));
	block_data.emplace(ChunkBlock(95, 2), new Block(170, 170, 170, 170, 170, 170, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 2));
	block_data.emplace(ChunkBlock(95, 3), new Block(171, 171, 171, 171, 171, 171, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 3));
	block_data.emplace(ChunkBlock(95, 4), new Block(172, 172, 172, 172, 172, 172, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 4));
	block_data.emplace(ChunkBlock(95, 5), new Block(173, 173, 173, 173, 173, 173, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 5));
	block_data.emplace(ChunkBlock(95, 6), new Block(174, 174, 174, 174, 174, 174, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 6));
	block_data.emplace(ChunkBlock(95, 7), new Block(175, 175, 175, 175, 175, 175, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 7));
	block_data.emplace(ChunkBlock(95, 8), new Block(176, 176, 176, 176, 176, 176, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 8));
	block_data.emplace(ChunkBlock(95, 9), new Block(177, 177, 177, 177, 177, 177, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 9));
	block_data.emplace(ChunkBlock(95, 10), new Block(178, 178, 178, 178, 178, 178, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 10));
	block_data.emplace(ChunkBlock(95, 11), new Block(179, 179, 179, 179, 179, 179, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 11));
	block_data.emplace(ChunkBlock(95, 12), new Block(180, 180, 180, 180, 180, 180, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 12));
	block_data.emplace(ChunkBlock(95, 13), new Block(181, 181, 181, 181, 181, 181, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 13));
	block_data.emplace(ChunkBlock(95, 14), new Block(182, 182, 182, 182, 182, 182, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 14));
	block_data.emplace(ChunkBlock(95, 15), new Block(183, 183, 183, 183, 183, 183, 
												2, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(95, 15));

	//TODO: TRAPDOOR
	block_data.emplace(ChunkBlock(97, 0), new Block(1, 1, 1, 1, 1, 1, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(97, 0));
	block_data.emplace(ChunkBlock(97, 1), new Block(15, 15, 15, 15, 15, 15, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(97, 1));
	block_data.emplace(ChunkBlock(97, 2), new Block(185, 185, 185, 185, 185, 185, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(97, 2));
	block_data.emplace(ChunkBlock(97, 3), new Block(186, 186, 186, 186, 186, 186, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(97, 3));
	block_data.emplace(ChunkBlock(97, 4), new Block(187, 187, 187, 187, 187, 187, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(97, 4));
	block_data.emplace(ChunkBlock(97, 5), new Block(188, 188, 188, 188, 188, 188, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(97, 5));


	block_data.emplace(ChunkBlock(98, 0), new Block(185, 185, 185, 185, 185, 185, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(98, 0));
	block_data.emplace(ChunkBlock(98, 1), new Block(186, 186, 186, 186, 186, 186, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(98, 1));
	block_data.emplace(ChunkBlock(98, 2), new Block(187, 187, 187, 187, 187, 187, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(98, 2));
	block_data.emplace(ChunkBlock(98, 3), new Block(188, 188, 188, 188, 188, 188, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(98, 3));
	block_data.emplace(ChunkBlock(99, 0), new Block(190, 190, 190, 190, 190, 190, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(99, 0));
	block_data.emplace(ChunkBlock(100, 0), new Block(189, 189, 189, 189, 189, 189, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(100, 0));

	block_data.emplace(ChunkBlock(101, 0), new Block(191, 191, 191, 191, 191, 191, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(101, 0));

	block_data.emplace(ChunkBlock(102, 0), new Block(192, 49, 49, 49, 49, 49, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(102, 0));

	block_data.emplace(ChunkBlock(103, 0), new Block(193, 193, 194, 194, 194, 194, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(103, 0));
	block_data.emplace(ChunkBlock(104, 0), new Block(195, 195, 195, 195, 195, 195, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(104, 0));
	block_data.emplace(ChunkBlock(105, 0), new Block(197, 197, 197, 197, 197, 197, 
												1, 1, true, false, false));
	registered_blocks.push_back(ChunkBlock(105, 0));

	//TODO: FENCE GATE, STAIRS

	block_data.emplace(ChunkBlock(106, 0), new Block(199, 199, 199, 199, 199, 199, 
												1, 4, true, false, false));
	registered_blocks.push_back(ChunkBlock(106, 0));

	block_data.emplace(ChunkBlock(110, 0), new Block(200, 11, 201, 201, 201, 201, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(110, 0));

	block_data.emplace(ChunkBlock(111, 0), new Block(202, 202, 202, 202, 202, 202, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(111, 0));

	//TODO: RAIL

	block_data.emplace(ChunkBlock(112, 0), new Block(203, 203, 203, 203, 203, 203, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(112, 0));

	//TODO: LOTS OF STUFF
	block_data.emplace(ChunkBlock(115, 0), new Block(206, 206, 206, 206, 206, 206, 
												1, 8, true, false, false));
	registered_blocks.push_back(ChunkBlock(115, 0));

	
	block_data.emplace(ChunkBlock(121, 0), new Block(219, 219, 219, 219, 219, 219, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(121, 0));
	
	block_data.emplace(ChunkBlock(123, 0), new Block(221, 221, 221, 221, 221, 221, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(123, 0));
	block_data.emplace(ChunkBlock(124, 0), new Block(222, 222, 222, 222, 222, 222, 
												0, 0, false, true, false));
	registered_blocks.push_back(ChunkBlock(124, 0));
	block_data.emplace(ChunkBlock(125, 0), new Block(16, 16, 16, 16, 16, 16, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(125, 0));
	block_data.emplace(ChunkBlock(125, 1), new Block(17, 17, 17, 17, 17, 17, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(125, 1));
	block_data.emplace(ChunkBlock(125, 2), new Block(18, 18, 18, 18, 18, 18, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(125, 2));
	block_data.emplace(ChunkBlock(125, 3), new Block(19, 19, 19, 19, 19, 19, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(125, 3));
	block_data.emplace(ChunkBlock(125, 4), new Block(20, 20, 20, 20, 20, 20, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(125, 4));
	block_data.emplace(ChunkBlock(125, 5), new Block(21, 21, 21, 21, 21, 21, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(125, 5));

	block_data.emplace(ChunkBlock(126, 0), new Block(16, 16, 16, 16, 16, 16, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(126, 0));
	block_data.emplace(ChunkBlock(126, 1), new Block(17, 17, 17, 17, 17, 17, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(126, 1));
	block_data.emplace(ChunkBlock(126, 2), new Block(18, 18, 18, 18, 18, 18, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(126, 2));
	block_data.emplace(ChunkBlock(126, 3), new Block(19, 19, 19, 19, 19, 19, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(126, 3));
	block_data.emplace(ChunkBlock(126, 4), new Block(20, 20, 20, 20, 20, 20, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(126, 4));
	block_data.emplace(ChunkBlock(126, 5), new Block(21, 21, 21, 21, 21, 21, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(126, 5));


	//TODO: LOTS OF STUFF

	block_data.emplace(ChunkBlock(129, 0), new Block(226, 226, 226, 226, 226, 226, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(129, 0));

	//TODO: LOTS OF STUFF

	block_data.emplace(ChunkBlock(132, 0), new Block(228, 228, 228, 228, 228, 228, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(132, 0));
	block_data.emplace(ChunkBlock(133, 0), new Block(229, 229, 229, 229, 229, 229, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(133, 0));

	//TODO: LOTS OF STUFF

	block_data.emplace(ChunkBlock(137, 0), new Block(230, 230, 230, 230, 230, 230, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(137, 0));

	//TODO: LOTS OF STUFF

	block_data.emplace(ChunkBlock(141, 0), new Block(247, 247, 247, 247, 247, 247, 
												1, 8, true, false, false));
	registered_blocks.push_back(ChunkBlock(141, 0));
	block_data.emplace(ChunkBlock(142, 0), new Block(251, 251, 251, 251, 251, 251, 
												1, 8, true, false, false));
	registered_blocks.push_back(ChunkBlock(142, 0));
	

	block_data.emplace(ChunkBlock(147, 0), new Block(101, 101, 101, 101, 101, 101, 
												1, 9, true, false, false));
	registered_blocks.push_back(ChunkBlock(147, 0));
	block_data.emplace(ChunkBlock(148, 0), new Block(102, 102, 102, 102, 102, 102, 
												1, 9, true, false, false));
	registered_blocks.push_back(ChunkBlock(148, 0));

	block_data.emplace(ChunkBlock(151, 0), new Block(258, 259, 259, 259, 259, 259, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(151, 0));

	block_data.emplace(ChunkBlock(152, 0), new Block(261, 261, 261, 261, 261, 261, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(152, 0));
	block_data.emplace(ChunkBlock(153, 0), new Block(262, 262, 262, 262, 262, 262, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(153, 0));

	//TODO: HOPPER

	block_data.emplace(ChunkBlock(155, 0), new Block(263, 265, 264, 264, 264, 264, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(155, 0));
	block_data.emplace(ChunkBlock(155, 1), new Block(267, 267, 266, 266, 266, 266, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(155, 1));
	block_data.emplace(ChunkBlock(155, 2), new Block(269, 269, 268, 268, 268, 268, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(155, 2));

	//TODO: STAIRS & RAIL


	block_data.emplace(ChunkBlock(157, 0), new Block(270, 270, 270, 270, 270, 270, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(157, 0));
	block_data.emplace(ChunkBlock(158, 0), new Block(131, 131, 273, 132, 132, 132, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(158, 0));

	block_data.emplace(ChunkBlock(159, 0), new Block(274, 274, 274, 274, 274, 274, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 0));
	block_data.emplace(ChunkBlock(159, 1), new Block(275, 275, 275, 275, 275, 275, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 1));
	block_data.emplace(ChunkBlock(159, 2), new Block(276, 276, 276, 276, 276, 276, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 2));
	block_data.emplace(ChunkBlock(159, 3), new Block(277, 277, 277, 277, 277, 277, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 3));
	block_data.emplace(ChunkBlock(159, 4), new Block(278, 278, 278, 278, 278, 278, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 4));
	block_data.emplace(ChunkBlock(159, 5), new Block(279, 279, 279, 279, 279, 279, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 5));
	block_data.emplace(ChunkBlock(159, 6), new Block(280, 280, 280, 280, 280, 280, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 6));
	block_data.emplace(ChunkBlock(159, 7), new Block(281, 281, 281, 281, 281, 281, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 7));
	block_data.emplace(ChunkBlock(159, 8), new Block(282, 282, 282, 282, 282, 282, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 8));
	block_data.emplace(ChunkBlock(159, 9), new Block(283, 283, 283, 283, 283, 283, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 9));
	block_data.emplace(ChunkBlock(159, 10), new Block(284, 284, 284, 284, 284, 284, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 10));
	block_data.emplace(ChunkBlock(159, 11), new Block(285, 285, 285, 285, 285, 285, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 11));
	block_data.emplace(ChunkBlock(159, 12), new Block(286, 286, 286, 286, 286, 286, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 12));
	block_data.emplace(ChunkBlock(159, 13), new Block(287, 287, 287, 287, 287, 287, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 13));
	block_data.emplace(ChunkBlock(159, 14), new Block(288, 288, 288, 288, 288, 288, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 14));
	block_data.emplace(ChunkBlock(159, 15), new Block(289, 289, 289, 289, 289, 289, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(159, 15));



	block_data.emplace(ChunkBlock(160, 0), new Block(168, 168, 168, 168, 168, 168, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 0));
	block_data.emplace(ChunkBlock(160, 1), new Block(169, 169, 169, 169, 169, 169, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 1));
	block_data.emplace(ChunkBlock(160, 2), new Block(170, 170, 170, 170, 170, 170, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 2));
	block_data.emplace(ChunkBlock(160, 3), new Block(171, 171, 171, 171, 171, 171, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 3));
	block_data.emplace(ChunkBlock(160, 4), new Block(172, 172, 172, 172, 172, 172, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 4));
	block_data.emplace(ChunkBlock(160, 5), new Block(173, 173, 173, 173, 173, 173, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 5));
	block_data.emplace(ChunkBlock(160, 6), new Block(174, 174, 174, 174, 174, 174, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 6));
	block_data.emplace(ChunkBlock(160, 7), new Block(175, 175, 175, 175, 175, 175, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 7));
	block_data.emplace(ChunkBlock(160, 8), new Block(176, 176, 176, 176, 176, 176, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 8));
	block_data.emplace(ChunkBlock(160, 9), new Block(177, 177, 177, 177, 177, 177, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 9));
	block_data.emplace(ChunkBlock(160, 10), new Block(178, 178, 178, 178, 178, 178, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 10));
	block_data.emplace(ChunkBlock(160, 11), new Block(179, 179, 179, 179, 179, 179, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 11));
	block_data.emplace(ChunkBlock(160, 12), new Block(180, 180, 180, 180, 180, 180, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 12));
	block_data.emplace(ChunkBlock(160, 13), new Block(181, 181, 181, 181, 181, 181, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 13));
	block_data.emplace(ChunkBlock(160, 14), new Block(182, 182, 182, 182, 182, 182, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 14));
	block_data.emplace(ChunkBlock(160, 15), new Block(183, 183, 183, 183, 183, 183, 
												2, 5, true, false, false));
	registered_blocks.push_back(ChunkBlock(160, 15));


	block_data.emplace(ChunkBlock(161, 0), new Block(306, 306, 306, 306, 306, 306, 
												1, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(161, 0));
	block_data.emplace(ChunkBlock(161, 1), new Block(307, 307, 307, 307, 307, 307, 
												1, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(161, 1));
	block_data.emplace(ChunkBlock(162, 0), new Block(308, 308, 309, 309, 309, 309, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(162, 0));
	block_data.emplace(ChunkBlock(162, 1), new Block(310, 310, 311, 311, 311, 311, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(162, 1));

	//TODO: STAIRS

	block_data.emplace(ChunkBlock(165, 0), new Block(312, 312, 312, 312, 312, 312, 
												1, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(165, 0));

	//TODO: SPECIAL + TRAPDOOR

	block_data.emplace(ChunkBlock(168, 0), new Block(314, 314, 314, 314, 314, 314, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(168, 0));
	block_data.emplace(ChunkBlock(168, 1), new Block(315, 315, 315, 315, 315, 315, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(168, 1));
	block_data.emplace(ChunkBlock(168, 2), new Block(316, 316, 316, 316, 316, 316, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(168, 2));
	block_data.emplace(ChunkBlock(169, 0), new Block(317, 317, 317, 317, 317, 317, 
												0, 0, false, true, false));
	registered_blocks.push_back(ChunkBlock(169, 0));

	block_data.emplace(ChunkBlock(170, 0), new Block(318, 318, 319, 319, 319, 319, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(170, 0));


	block_data.emplace(ChunkBlock(171, 0), new Block(73, 73, 73, 73, 73, 73, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 0));
	block_data.emplace(ChunkBlock(171, 1), new Block(74, 74, 74, 74, 74, 74, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 1));
	block_data.emplace(ChunkBlock(171, 2), new Block(75, 75, 75, 75, 75, 75, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 2));
	block_data.emplace(ChunkBlock(171, 3), new Block(76, 76, 76, 76, 76, 76, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 3));
	block_data.emplace(ChunkBlock(171, 4), new Block(77, 77, 77, 77, 77, 77, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 4));
	block_data.emplace(ChunkBlock(171, 5), new Block(78, 78, 78, 78, 78, 78, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 5));
	block_data.emplace(ChunkBlock(171, 6), new Block(79, 79, 79, 79, 79, 79, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 6));
	block_data.emplace(ChunkBlock(171, 7), new Block(80, 80, 80, 80, 80, 80, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 7));
	block_data.emplace(ChunkBlock(171, 8), new Block(81, 81, 81, 81, 81, 81, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 8));
	block_data.emplace(ChunkBlock(171, 9), new Block(82, 82, 82, 82, 82, 82, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 9));
	block_data.emplace(ChunkBlock(171, 10), new Block(83, 83, 83, 83, 83, 83, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 10));
	block_data.emplace(ChunkBlock(171, 11), new Block(84, 84, 84, 84, 84, 84, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 11));
	block_data.emplace(ChunkBlock(171, 12), new Block(85, 85, 85, 85, 85, 85, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 12));
	block_data.emplace(ChunkBlock(171, 13), new Block(86, 86, 86, 86, 86, 86, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 13));
	block_data.emplace(ChunkBlock(171, 14), new Block(87, 87, 87, 87, 87, 87, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 14));
	block_data.emplace(ChunkBlock(171, 15), new Block(88, 88, 88, 88, 88, 88, 
												2, 3, true, false, false));
	registered_blocks.push_back(ChunkBlock(171, 15));

	block_data.emplace(ChunkBlock(172, 0), new Block(320, 320, 320, 320, 320, 320, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(172, 0));
	block_data.emplace(ChunkBlock(173, 0), new Block(321, 321, 321, 321, 321, 321, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(173, 0));
	block_data.emplace(ChunkBlock(174, 0), new Block(322, 322, 322, 322, 322, 322, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(174, 0));

	//TODO: LOTS OF STUFF


	block_data.emplace(ChunkBlock(178, 0), new Block(260, 259, 259, 259, 259, 259, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(178, 0));
	block_data.emplace(ChunkBlock(179, 0), new Block(337, 338, 339, 339, 339, 339, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(179, 0));
	block_data.emplace(ChunkBlock(179, 1), new Block(337, 338, 341, 341, 341, 341, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(179, 1));
	block_data.emplace(ChunkBlock(179, 2), new Block(337, 338, 340, 340, 340, 340, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(179, 2));

	//TODO: STAIRS

	block_data.emplace(ChunkBlock(181, 0), new Block(337, 338, 339, 339, 339, 339, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(181, 0));
	block_data.emplace(ChunkBlock(182, 0), new Block(337, 338, 339, 339, 339, 339, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(182, 0));

	//FENCES DOORS AND SHIT

	
	block_data.emplace(ChunkBlock(201, 0), new Block(356, 356, 356, 356, 356, 356, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(201, 0));
	block_data.emplace(ChunkBlock(202, 0), new Block(358, 358, 357, 357, 357, 357, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(202, 0));

	//TODO: STAIRS

	block_data.emplace(ChunkBlock(204, 0), new Block(356, 356, 356, 356, 356, 356, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(204, 0));

	block_data.emplace(ChunkBlock(205, 0), new Block(359, 359, 359, 359, 359, 359, 
												2, 6, true, false, false));
	registered_blocks.push_back(ChunkBlock(205, 0));

	block_data.emplace(ChunkBlock(206, 0), new Block(359, 359, 359, 359, 359, 359, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(206, 0));

	block_data.emplace(ChunkBlock(207, 0), new Block(363, 363, 363, 363, 363, 363, 
												1, 8, true, false, false));
	registered_blocks.push_back(ChunkBlock(207, 0));

	block_data.emplace(ChunkBlock(208, 0), new Block(364, 11, 365, 365, 365, 365, 
												2, 7, true, false, false));
	registered_blocks.push_back(ChunkBlock(208, 0));

	//TODO: SPECIAL

	block_data.emplace(ChunkBlock(210, 0), new Block(234, 234, 234, 234, 234, 234, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(210, 0));
	block_data.emplace(ChunkBlock(211, 0), new Block(238, 238, 238, 238, 238, 238, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(211, 0));


	block_data.emplace(ChunkBlock(212, 0), new Block(366, 366, 366, 366, 366, 366, 
												1, 0, true, false, false));
	registered_blocks.push_back(ChunkBlock(212, 0));
	block_data.emplace(ChunkBlock(213, 0), new Block(370, 370, 370, 370, 370, 370, 
												0, 0, false, true, false));
	registered_blocks.push_back(ChunkBlock(213, 0));
	block_data.emplace(ChunkBlock(214, 0), new Block(371, 371, 371, 371, 371, 371, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(214, 0));
	block_data.emplace(ChunkBlock(215, 0), new Block(372, 372, 372, 372, 372, 372, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(215, 0));
	block_data.emplace(ChunkBlock(216, 0), new Block(373, 373, 374, 374, 374, 374, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(216, 0));

	//TODO: SPECIAL

	block_data.emplace(ChunkBlock(218, 0), new Block(375, 377, 376, 378, 377, 377, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(218, 0));


	block_data.emplace(ChunkBlock(219, 0), new Block(380, 380, 380, 380, 380, 380, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(219, 0));
	block_data.emplace(ChunkBlock(220, 0), new Block(381, 381, 381, 381, 381, 381, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(220, 0));
	block_data.emplace(ChunkBlock(221, 0), new Block(382, 382, 382, 382, 382, 382, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(221, 0));
	block_data.emplace(ChunkBlock(222, 0), new Block(383, 383, 383, 383, 383, 383, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(222, 0));
	block_data.emplace(ChunkBlock(223, 0), new Block(384, 384, 384, 384, 384, 384, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(223, 0));
	block_data.emplace(ChunkBlock(224, 0), new Block(385, 385, 385, 385, 385, 385, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(224, 0));
	block_data.emplace(ChunkBlock(225, 0), new Block(386, 386, 386, 386, 386, 386, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(225, 0));
	block_data.emplace(ChunkBlock(226, 0), new Block(387, 387, 387, 387, 387, 387, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(226, 0));
	block_data.emplace(ChunkBlock(227, 0), new Block(388, 388, 388, 388, 388, 388, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(227, 0));
	block_data.emplace(ChunkBlock(228, 0), new Block(389, 389, 389, 389, 389, 389, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(228, 0));
	block_data.emplace(ChunkBlock(229, 0), new Block(390, 390, 390, 390, 390, 390, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(229, 0));
	block_data.emplace(ChunkBlock(230, 0), new Block(391, 391, 391, 391, 391, 391, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(230, 0));
	block_data.emplace(ChunkBlock(231, 0), new Block(392, 392, 392, 392, 392, 392, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(231, 0));
	block_data.emplace(ChunkBlock(232, 0), new Block(393, 393, 393, 393, 393, 393, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(232, 0));
	block_data.emplace(ChunkBlock(233, 0), new Block(394, 394, 394, 394, 394, 394, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(233, 0));
	block_data.emplace(ChunkBlock(234, 0), new Block(395, 395, 395, 395, 395, 395, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(234, 0));


	block_data.emplace(ChunkBlock(235, 0), new Block(396, 396, 396, 396, 396, 396, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(235, 0));
	block_data.emplace(ChunkBlock(236, 0), new Block(397, 397, 397, 397, 397, 397, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(236, 0));
	block_data.emplace(ChunkBlock(237, 0), new Block(398, 398, 398, 398, 398, 398, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(237, 0));
	block_data.emplace(ChunkBlock(238, 0), new Block(399, 399, 399, 399, 399, 399, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(238, 0));
	block_data.emplace(ChunkBlock(239, 0), new Block(400, 400, 400, 400, 400, 400, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(239, 0));
	block_data.emplace(ChunkBlock(240, 0), new Block(401, 401, 401, 401, 401, 401, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(240, 0));
	block_data.emplace(ChunkBlock(241, 0), new Block(402, 402, 402, 402, 402, 402, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(241, 0));
	block_data.emplace(ChunkBlock(242, 0), new Block(403, 403, 403, 403, 403, 403, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(242, 0));
	block_data.emplace(ChunkBlock(243, 0), new Block(404, 404, 404, 404, 404, 404, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(243, 0));
	block_data.emplace(ChunkBlock(244, 0), new Block(405, 405, 405, 405, 405, 405, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(244, 0));
	block_data.emplace(ChunkBlock(245, 0), new Block(406, 406, 406, 406, 406, 406, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(245, 0));
	block_data.emplace(ChunkBlock(246, 0), new Block(407, 407, 407, 407, 407, 407, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(246, 0));
	block_data.emplace(ChunkBlock(247, 0), new Block(408, 408, 408, 408, 408, 408, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(247, 0));
	block_data.emplace(ChunkBlock(248, 0), new Block(409, 409, 409, 409, 409, 409, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(248, 0));
	block_data.emplace(ChunkBlock(249, 0), new Block(410, 410, 410, 410, 410, 410, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(249, 0));
	block_data.emplace(ChunkBlock(250, 0), new Block(411, 411, 411, 411, 411, 411, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(250, 0));


	block_data.emplace(ChunkBlock(251, 0), new Block(412, 412, 412, 412, 412, 412, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 0));
	block_data.emplace(ChunkBlock(251, 1), new Block(413, 413, 413, 413, 413, 413, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 1));
	block_data.emplace(ChunkBlock(251, 2), new Block(414, 414, 414, 414, 414, 414, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 2));
	block_data.emplace(ChunkBlock(251, 3), new Block(415, 415, 415, 415, 415, 415, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 3));
	block_data.emplace(ChunkBlock(251, 4), new Block(416, 416, 416, 416, 416, 416, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 4));
	block_data.emplace(ChunkBlock(251, 5), new Block(417, 417, 417, 417, 417, 417, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 5));
	block_data.emplace(ChunkBlock(251, 6), new Block(418, 418, 418, 418, 418, 418, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 6));
	block_data.emplace(ChunkBlock(251, 7), new Block(419, 419, 419, 419, 419, 419, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 7));
	block_data.emplace(ChunkBlock(251, 8), new Block(420, 420, 420, 420, 420, 420, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 8));
	block_data.emplace(ChunkBlock(251, 9), new Block(421, 421, 421, 421, 421, 421, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 9));
	block_data.emplace(ChunkBlock(251, 10), new Block(422, 422, 422, 422, 422, 422, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 10));
	block_data.emplace(ChunkBlock(251, 11), new Block(423, 423, 423, 423, 423, 423, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 11));
	block_data.emplace(ChunkBlock(251, 12), new Block(424, 424, 424, 424, 424, 424, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 12));
	block_data.emplace(ChunkBlock(251, 13), new Block(425, 425, 425, 425, 425, 425, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 13));
	block_data.emplace(ChunkBlock(251, 14), new Block(426, 426, 426, 426, 426, 426, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 14));
	block_data.emplace(ChunkBlock(251, 15), new Block(427, 427, 427, 427, 427, 427, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(251, 15));


	block_data.emplace(ChunkBlock(252, 0), new Block(428, 428, 428, 428, 428, 428, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 0));
	block_data.emplace(ChunkBlock(252, 1), new Block(429, 429, 429, 429, 429, 429, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 1));
	block_data.emplace(ChunkBlock(252, 2), new Block(430, 430, 430, 430, 430, 430, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 2));
	block_data.emplace(ChunkBlock(252, 3), new Block(431, 431, 431, 431, 431, 431, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 3));
	block_data.emplace(ChunkBlock(252, 4), new Block(432, 432, 432, 432, 432, 432, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 4));
	block_data.emplace(ChunkBlock(252, 5), new Block(433, 433, 433, 433, 433, 433, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 5));
	block_data.emplace(ChunkBlock(252, 6), new Block(434, 434, 434, 434, 434, 434, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 6));
	block_data.emplace(ChunkBlock(252, 7), new Block(435, 435, 435, 435, 435, 435, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 7));
	block_data.emplace(ChunkBlock(252, 8), new Block(436, 436, 436, 436, 436, 436, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 8));
	block_data.emplace(ChunkBlock(252, 9), new Block(437, 437, 437, 437, 437, 437, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 9));
	block_data.emplace(ChunkBlock(252, 10), new Block(438, 438, 438, 438, 438, 438, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 10));
	block_data.emplace(ChunkBlock(252, 11), new Block(439, 439, 439, 439, 439, 439, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 11));
	block_data.emplace(ChunkBlock(252, 12), new Block(440, 440, 440, 440, 440, 440, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 12));
	block_data.emplace(ChunkBlock(252, 13), new Block(441, 441, 441, 441, 441, 441, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 13));
	block_data.emplace(ChunkBlock(252, 14), new Block(442, 442, 442, 442, 442, 442, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 14));
	block_data.emplace(ChunkBlock(252, 15), new Block(443, 443, 443, 443, 443, 443, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(252, 15));

}
BlockData BlockData::instance;

BlockData *BlockData::InstancePointer()
{
	return &instance;
}