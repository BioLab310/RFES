/*
 * neighbor.h
 *
 *  Created on: Oct 26, 2021
 *      Author: bio
 */

#ifndef NEIGHBOR_H_
#define NEIGHBOR_H_
#include "Basic.h"
#include "hash.h"
#include "counter.h"

void UpdateNeiborNodeList(pair<unsigned,unsigned> edge);
void UpdateNeiborNodeList_improve(pair<unsigned,unsigned> edge);
void UpdateNeiborNodeList_FullyDynamic(pair<unsigned,unsigned> edge,unsigned w);
#endif /* NEIGHBOR_H_ */
