/*
 * Basic.cpp
 *
 *  Created on: Oct 26, 2021
 *      Author: bio
 */

#include "Basic.h"

pair<unsigned,unsigned> *p_reservoir;
unsigned M;
vector< vector <unsigned> > neighbor;
unsigned globalN;
unsigned * localN;
unsigned cur_graph_size;
unsigned cur_popBack_pos;

//for RFES_Improve
float globalN_improve;

//for RFES_FullyDynamic
unsigned nb;
unsigned ng;
unsigned cur_res_size;
vector<unsigned> cur_popBack_pos_vec;

