/*
 * reservoir.cpp
 *
 *  Created on: Oct 26, 2021
 *      Author: bio
 */
#include "reservoir.h"

void SampleEdge(pair<unsigned,unsigned> edge)
{
	double rand_ = (double)rand() / ((double)RAND_MAX+1.0);
	if(cur_graph_size<=M)
	{
		p_reservoir[cur_popBack_pos]=edge;

		hash_table_insert_edge(edge,cur_popBack_pos);

		cur_popBack_pos++;
	}
	else if(rand_<(((float)M)/((float)cur_graph_size)))
	{
		cur_popBack_pos = rand()%M;
		hash_table_delete_edge(p_reservoir[cur_popBack_pos],cur_popBack_pos);

		//update reservoir edges
		p_reservoir[cur_popBack_pos]=edge;
		hash_table_insert_edge(edge,cur_popBack_pos);

		//update counters
		globalN=globalN-localN[cur_popBack_pos];
		localN[cur_popBack_pos]=0;

		//update neighbor lists
		neighbor[2*cur_popBack_pos].clear();
		neighbor[2*cur_popBack_pos+1].clear();
	}
}


void SampleEdge_improve(pair<unsigned,unsigned> edge)
{
	double rand_ = (double)rand() / ((double)RAND_MAX+1.0);
	if(cur_graph_size<=M)
	{
		p_reservoir[cur_popBack_pos]=edge;

		hash_table_insert_edge(edge,cur_popBack_pos);

		cur_popBack_pos++;
	}
	else if(rand_<(((float)M)/((float)cur_graph_size)))
	{
		cur_popBack_pos = rand()%M;
		hash_table_delete_edge(p_reservoir[cur_popBack_pos],cur_popBack_pos);

		//update reservoir edges
		p_reservoir[cur_popBack_pos]=edge;
		hash_table_insert_edge(edge,cur_popBack_pos);

		//update neighbor lists
		neighbor[2*cur_popBack_pos].clear();
		neighbor[2*cur_popBack_pos+1].clear();
	}
}

void SampleEdge_FullyDynamic(pair<unsigned,unsigned> edge)
{
	double rand_ = (double)rand() / ((double)RAND_MAX+1.0);
	if(nb==0&&ng==0)
	{
		if(cur_res_size<M)
		{
			cur_popBack_pos=cur_popBack_pos_vec.back();
			cur_popBack_pos_vec.pop_back();
			p_reservoir[cur_popBack_pos]=edge;

			hash_table_insert_edge(edge,cur_popBack_pos);

			cur_popBack_pos++;
			cur_res_size++;
		}
		else if(rand_<(((float)M)/((float)cur_graph_size)))
		{
			cur_popBack_pos = rand()%M;
			hash_table_delete_edge(p_reservoir[cur_popBack_pos],cur_popBack_pos);

			//update reservoir edges
			p_reservoir[cur_popBack_pos]=edge;
			hash_table_insert_edge(edge,cur_popBack_pos);

			//update counters
			globalN=globalN-localN[cur_popBack_pos];
			localN[cur_popBack_pos]=0;

			//update neighbor lists
			neighbor[2*cur_popBack_pos].clear();
			neighbor[2*cur_popBack_pos+1].clear();
		}
	}
	else if(rand_<((float)nb)/((float)nb+(float)ng))
	{
		cur_popBack_pos=cur_popBack_pos_vec.back();
		cur_popBack_pos_vec.pop_back();

		p_reservoir[cur_popBack_pos]=edge;
		hash_table_insert_edge(edge,cur_popBack_pos);
		cur_res_size++;

		nb--;
	}
	else
	{
		ng--;
	}
}
