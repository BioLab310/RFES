/*
 * counter.cpp
 *
 *  Created on: Oct 26, 2021
 *      Author: bio
 */

#include "counter.h"

unsigned find_node(vector<unsigned>a,unsigned node)
{
	for(unsigned i=0;i<a.size();i++)
	{
		if(a[i]==node)
		{
			return 1;
		}
	}
	return 0;
}
void UpdateCounters(pair<unsigned,unsigned> edge)
{

}



