#include "Map.h"
#include <iostream>
#include<assert.h>

bool Land::put( const Plant& plant)
{
	if(isStood_) return false;

	plant_ = new Plant*();
    *plant_ = plant ;
	isStood_ = true;

    plant_->displayinfo();

	return true;
}

Land::~Land()
{
	if(plant_ != nullptr)
	{
        delete plant_;
        isStood_ = false;
	}
}

Map::Map(int land_num)
{
	if(!(land_num > 0 && land_num <= max_land_num))
		throw "Number of Land should less than " + max_land_num;

	for(int i = 0 ; i < land_num ; ++i)
	{
		Land tmp;
		lands_.push_back(tmp);
	}
}

