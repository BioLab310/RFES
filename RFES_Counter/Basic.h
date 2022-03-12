/*
 * Basic.h
 *
 *  Created on: Oct 26, 2021
 *      Author: bio
 */

#ifndef BASIC_H_
#define BASIC_H_


#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<fstream>
#include<algorithm>
#include<map>
#include <math.h>
#include <sstream>
#include <sys/time.h>


using namespace std;

extern pair<unsigned,unsigned> *p_reservoir;
extern unsigned M;
extern vector< vector <unsigned> > neighbor;
extern unsigned globalN;
extern unsigned * localN;
extern unsigned cur_graph_size;
extern unsigned cur_popBack_pos;

//for Improve
extern float globalN_improve;

//for Fully Dynamic
extern unsigned nb;
extern unsigned ng;
extern unsigned cur_res_size;
extern vector<unsigned> cur_popBack_pos_vec;



#endif /* BASIC_H_ */
