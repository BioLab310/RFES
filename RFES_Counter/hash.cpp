/*
 * hash.cpp
 *
 *  Created on: Oct 26, 2021
 *      Author: bio
 */
#include "hash.h"

vector< vector<unsigned> > hash_table;
unsigned hash_table_size=10000;

unsigned hash_function(unsigned a)
{
	return a%hash_table_size;
}

void hash_table_initial()
{
	hash_table.resize(hash_table_size);
	cout << hash_table.size() << endl;
	for(unsigned i=0;i<hash_table_size;i++)
	{
		hash_table[i].clear();
	}
}

void hash_table_insert(unsigned node,unsigned res_index)
{
	hash_table[hash_function(node)].push_back(res_index);
}

void hash_table_delete(unsigned node,unsigned res_index)
{
	if(hash_table[hash_function(node)].size()==0)
	{
		return;
	}
	else
	{
		if(hash_table[hash_function(node)].back()==res_index)
		{
			hash_table[hash_function(node)].pop_back();
		}
		else
		{
			unsigned i;
			for(i=0;i<hash_table[hash_function(node)].size();i++)
			{
				if(hash_table[hash_function(node)][i]==res_index)
				{
					break;
				}
			}
			hash_table[hash_function(node)][i]=hash_table[hash_function(node)].back();
			hash_table[hash_function(node)].pop_back();
		}
	}
}

void hash_table_insert_edge(pair<unsigned,unsigned> edge,unsigned res_index)
{
	unsigned a=hash_function(edge.first);
	unsigned b=hash_function(edge.second);
	if(a==b)
	{
		hash_table[a].push_back(res_index);
	}
	else
	{
		hash_table[a].push_back(res_index);
		hash_table[b].push_back(res_index);
	}
}

void hash_table_delete_edge(pair<unsigned,unsigned> edge,unsigned res_index)
{
	unsigned a=hash_function(edge.first);
	unsigned b=hash_function(edge.second);
	if(a==b)
	{
		hash_table_delete(edge.first,res_index);
	}
	else
	{
		hash_table_delete(edge.first,res_index);
		hash_table_delete(edge.second,res_index);
	}
}

int find_in_res(pair<unsigned,unsigned> edge)
{
	unsigned a=hash_function(edge.first);
	unsigned b=hash_function(edge.second);

	if(a==b)
	{
		for(unsigned i=0;i<hash_table[a].size();i++)
		{
			if(edge.first==p_reservoir[hash_table[a][i]].first&&
					edge.second==p_reservoir[hash_table[a][i]].second)
			{
				return hash_table[a][i];
			}
			if(edge.first==p_reservoir[hash_table[a][i]].second&&
								edge.second==p_reservoir[hash_table[a][i]].first)
			{
				return hash_table[a][i];
			}
		}
	}
	else
	{
		for(unsigned i=0;i<hash_table[a].size();i++)
		{
			if(edge.first==p_reservoir[hash_table[a][i]].first&&
					edge.second==p_reservoir[hash_table[a][i]].second)
			{
				return hash_table[a][i];
			}
			if(edge.first==p_reservoir[hash_table[a][i]].second&&
					edge.second==p_reservoir[hash_table[a][i]].first)
			{
				return hash_table[a][i];
			}
		}
		for(unsigned i=0;i<hash_table[b].size();i++)
		{
			if(edge.first==p_reservoir[hash_table[b][i]].first&&
					edge.second==p_reservoir[hash_table[b][i]].second)
			{
				return hash_table[a][i];
			}
			if(edge.first==p_reservoir[hash_table[b][i]].second&&
					edge.second==p_reservoir[hash_table[b][i]].first)
			{
				return hash_table[a][i];
			}
		}
	}
	return -1;

}


