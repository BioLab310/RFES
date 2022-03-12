/*
 * hash.h
 *
 *  Created on: Oct 26, 2021
 *      Author: bio
 */

#ifndef HASH_H_
#define HASH_H_
#include "Basic.h"


extern vector< vector<unsigned> > hash_table;
extern unsigned hash_table_size;

void hash_table_initial();
void hash_table_insert(unsigned node,unsigned res_index);
void hash_table_delete(unsigned node,unsigned res_index);
unsigned hash_function(unsigned a);
void hash_table_insert_edge(pair<unsigned,unsigned> edge,unsigned res_index);
void hash_table_delete_edge(pair<unsigned,unsigned> edge,unsigned res_index);
int find_in_res(pair<unsigned,unsigned> edge);

#endif /* HASH_H_ */
