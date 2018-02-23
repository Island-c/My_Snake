#ifndef MAP_H
#define MAP_H

#include<vector>
#include"point.h"

class Map
{

public:
	Map() 
	{

	for (int i = 1; i <= 30; ++i)
	{
		initmap.emplace_back(Point(1,i));
		initmap.emplace_back(Point(30,i));
		initmap.emplace_back(Point(i, 1));
		initmap.emplace_back(Point(i,30));
	}

	}
	void PrintInitmap();
private:
	std::vector<Point> initmap;
};

#endif