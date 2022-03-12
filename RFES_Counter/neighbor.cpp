/*
 * neighbor.cpp
 *
 *  Created on: Oct 26, 2021
 *      Author: bio
 */

#include "neighbor.h"

void UpdateNeiborNodeList(pair<unsigned,unsigned> edge)
{
	unsigned a=hash_function(edge.first);
	unsigned b=hash_function(edge.second);

	if(a==b)
	{
		for(unsigned i=0;i<hash_table[a].size();i++)
		{
			if(edge.first==p_reservoir[hash_table[a][i]].first)
			{
				neighbor[2*hash_table[a][i]].push_back(edge.second);
				if(find_node(neighbor[2*hash_table[a][i]+1],edge.second))
				{
					localN[hash_table[a][i]]++;
					globalN++;
				}
			}
			if(edge.first==p_reservoir[hash_table[a][i]].second)
			{
				neighbor[2*hash_table[a][i]+1].push_back(edge.second);
				if(find_node(neighbor[2*hash_table[a][i]],edge.second))
				{
					localN[hash_table[a][i]]++;
					globalN++;
				}
			}
			if(edge.second==p_reservoir[hash_table[a][i]].first)
			{
				neighbor[2*hash_table[a][i]].push_back(edge.first);
				if(find_node(neighbor[2*hash_table[a][i]+1],edge.first))
				{
					localN[hash_table[a][i]]++;
					globalN++;
				}
			}
			if(edge.second==p_reservoir[hash_table[a][i]].second)
			{
				neighbor[2*hash_table[a][i]+1].push_back(edge.first);
				if(find_node(neighbor[2*hash_table[a][i]],edge.first))
				{
					localN[hash_table[a][i]]++;
					globalN++;
				}
			}
		}
	}
	else
	{
		for(unsigned i=0;i<hash_table[a].size();i++)
		{
			if(edge.first==p_reservoir[hash_table[a][i]].first)
			{
				neighbor[2*hash_table[a][i]].push_back(edge.second);
				if(find_node(neighbor[2*hash_table[a][i]+1],edge.second))
				{
					localN[hash_table[a][i]]++;
					globalN++;
				}
			}
			if(edge.first==p_reservoir[hash_table[a][i]].second)
			{
				neighbor[2*hash_table[a][i]+1].push_back(edge.second);
				if(find_node(neighbor[2*hash_table[a][i]],edge.second))
				{
					localN[hash_table[a][i]]++;
					globalN++;
				}
			}
		}

		for(unsigned i=0;i<hash_table[b].size();i++)
		{

			if(edge.second==p_reservoir[hash_table[b][i]].first)
			{
				neighbor[2*hash_table[b][i]].push_back(edge.first);
				if(find_node(neighbor[2*hash_table[b][i]+1],edge.first))
				{
					localN[hash_table[b][i]]++;
					globalN++;
				}
			}
			if(edge.second==p_reservoir[hash_table[b][i]].second)
			{
				neighbor[2*hash_table[b][i]+1].push_back(edge.first);
				if(find_node(neighbor[2*hash_table[b][i]],edge.first))
				{
					localN[hash_table[b][i]]++;
					globalN++;
				}
			}
		}
	}
}

void UpdateNeiborNodeList_improve(pair<unsigned,unsigned> edge)
{
	unsigned a=hash_function(edge.first);
	unsigned b=hash_function(edge.second);

	if(a==b)
	{
		for(unsigned i=0;i<hash_table[a].size();i++)
		{
			if(edge.first==p_reservoir[hash_table[a][i]].first)
			{
				neighbor[2*hash_table[a][i]].push_back(edge.second);
				if(find_node(neighbor[2*hash_table[a][i]+1],edge.second))
				{
					float tmp=((float)cur_graph_size)/((float)M);
					if(tmp>=1)
					{
						globalN_improve+=tmp;
					}
					else
					{
						globalN_improve+=1;
					}
				}
			}
			if(edge.first==p_reservoir[hash_table[a][i]].second)
			{
				neighbor[2*hash_table[a][i]+1].push_back(edge.second);
				if(find_node(neighbor[2*hash_table[a][i]],edge.second))
				{
					float tmp=((float)cur_graph_size)/((float)M);
					if(tmp>=1)
					{
						globalN_improve+=tmp;
					}
					else
					{
						globalN_improve+=1;
					}
				}

			}
			if(edge.second==p_reservoir[hash_table[a][i]].first)
			{
				neighbor[2*hash_table[a][i]].push_back(edge.first);
				if(find_node(neighbor[2*hash_table[a][i]+1],edge.first))
				{
					float tmp=((float)cur_graph_size)/((float)M);
					if(tmp>=1)
					{
						globalN_improve+=tmp;
					}
					else
					{
						globalN_improve+=1;
					}
				}
			}
			if(edge.second==p_reservoir[hash_table[a][i]].second)
			{
				neighbor[2*hash_table[a][i]+1].push_back(edge.first);
				if(find_node(neighbor[2*hash_table[a][i]],edge.first))
				{
					float tmp=((float)cur_graph_size)/((float)M);
					if(tmp>=1)
					{
						globalN_improve+=tmp;
					}
					else
					{
						globalN_improve+=1;
					}
				}
			}
		}
	}
	else
	{
		for(unsigned i=0;i<hash_table[a].size();i++)
		{
			if(edge.first==p_reservoir[hash_table[a][i]].first)
			{
				neighbor[2*hash_table[a][i]].push_back(edge.second);
				if(find_node(neighbor[2*hash_table[a][i]+1],edge.second))
				{
					float tmp=((float)cur_graph_size)/((float)M);
					if(tmp>=1)
					{
						globalN_improve+=tmp;
					}
					else
					{
						globalN_improve+=1;
					}
				}
			}
			if(edge.first==p_reservoir[hash_table[a][i]].second)
			{
				neighbor[2*hash_table[a][i]+1].push_back(edge.second);
				if(find_node(neighbor[2*hash_table[a][i]],edge.second))
				{
					float tmp=((float)cur_graph_size)/((float)M);
					if(tmp>=1)
					{
						globalN_improve+=tmp;
					}
					else
					{
						globalN_improve+=1;
					}
				}

			}
		}

		for(unsigned i=0;i<hash_table[b].size();i++)
		{
			if(edge.second==p_reservoir[hash_table[b][i]].first)
			{
				neighbor[2*hash_table[b][i]].push_back(edge.first);
				if(find_node(neighbor[2*hash_table[b][i]+1],edge.first))
				{
					float tmp=((float)cur_graph_size)/((float)M);
					if(tmp>=1)
					{
						globalN_improve+=tmp;
					}
					else
					{
						globalN_improve+=1;
					}
				}
			}
			if(edge.second==p_reservoir[hash_table[b][i]].second)
			{
				neighbor[2*hash_table[b][i]+1].push_back(edge.first);
				if(find_node(neighbor[2*hash_table[b][i]],edge.first))
				{
					float tmp=((float)cur_graph_size)/((float)M);
					if(tmp>=1)
					{
						globalN_improve+=tmp;
					}
					else
					{
						globalN_improve+=1;
					}
				}
			}
		}
	}
}

void UpdateNeiborNodeList_FullyDynamic(pair<unsigned,unsigned> edge,unsigned w)
{
	unsigned a=hash_function(edge.first);
	unsigned b=hash_function(edge.second);

	if(w==1)
	{
		if(a==b)
		{
			for(unsigned i=0;i<hash_table[a].size();i++)
			{
				if(edge.first==p_reservoir[hash_table[a][i]].first)
				{
					neighbor[2*hash_table[a][i]].push_back(edge.second);
					if(find_node(neighbor[2*hash_table[a][i]+1],edge.second))
					{
						localN[hash_table[a][i]]++;
						globalN++;
					}
				}
				if(edge.first==p_reservoir[hash_table[a][i]].second)
				{
					neighbor[2*hash_table[a][i]+1].push_back(edge.second);
					if(find_node(neighbor[2*hash_table[a][i]],edge.second))
					{
						localN[hash_table[a][i]]++;
						globalN++;
					}
				}
				if(edge.second==p_reservoir[hash_table[a][i]].first)
				{
					neighbor[2*hash_table[a][i]].push_back(edge.first);
					if(find_node(neighbor[2*hash_table[a][i]+1],edge.first))
					{
						localN[hash_table[a][i]]++;
						globalN++;
					}
				}
				if(edge.second==p_reservoir[hash_table[a][i]].second)
				{
					neighbor[2*hash_table[a][i]+1].push_back(edge.first);
					if(find_node(neighbor[2*hash_table[a][i]],edge.first))
					{
						localN[hash_table[a][i]]++;
						globalN++;
					}
				}
			}
		}
		else
		{
			for(unsigned i=0;i<hash_table[a].size();i++)
			{
				if(edge.first==p_reservoir[hash_table[a][i]].first)
				{
					neighbor[2*hash_table[a][i]].push_back(edge.second);
					if(find_node(neighbor[2*hash_table[a][i]+1],edge.second))
					{
						localN[hash_table[a][i]]++;
						globalN++;
					}
				}
				if(edge.first==p_reservoir[hash_table[a][i]].second)
				{
					neighbor[2*hash_table[a][i]+1].push_back(edge.second);
					if(find_node(neighbor[2*hash_table[a][i]],edge.second))
					{
						localN[hash_table[a][i]]++;
						globalN++;
					}
				}
			}

			for(unsigned i=0;i<hash_table[b].size();i++)
			{

				if(edge.second==p_reservoir[hash_table[b][i]].first)
				{
					neighbor[2*hash_table[b][i]].push_back(edge.first);
					if(find_node(neighbor[2*hash_table[b][i]+1],edge.first))
					{
						localN[hash_table[b][i]]++;
						globalN++;
					}
				}
				if(edge.second==p_reservoir[hash_table[b][i]].second)
				{
					neighbor[2*hash_table[b][i]+1].push_back(edge.first);
					if(find_node(neighbor[2*hash_table[b][i]],edge.first))
					{
						localN[hash_table[b][i]]++;
						globalN++;
					}
				}
			}
		}
	}
	else
	{
		if(a==b)
		{
			for(unsigned i=0;i<hash_table[a].size();i++)
			{
				if(edge.first==p_reservoir[hash_table[a][i]].first)
				{
					int x=-1;
					for(unsigned j=0;j<neighbor[2*hash_table[a][i]].size();j++)
					{
						if(neighbor[2*hash_table[a][i]][j]==edge.second)
						{
							x=j;
							break;
						}
					}
					if(x!=-1)
					{
						neighbor[2*hash_table[a][i]][x]=neighbor[2*hash_table[a][i]].back();
						neighbor[2*hash_table[a][i]].pop_back();
					}
					if(x!=-1&&find_node(neighbor[2*hash_table[a][i]+1],edge.second))
					{
						localN[hash_table[a][i]]--;
						globalN--;
					}
				}
				if(edge.first==p_reservoir[hash_table[a][i]].second)
				{
					int x=-1;
					for(unsigned j=0;j<neighbor[2*hash_table[a][i]+1].size();j++)
					{
						if(neighbor[2*hash_table[a][i]+1][j]==edge.second)
						{
							x=j;
							break;
						}
					}
					if(x!=-1)
					{
						neighbor[2*hash_table[a][i]+1][x]=neighbor[2*hash_table[a][i]+1].back();
						neighbor[2*hash_table[a][i]+1].pop_back();
					}
					if(x!=-1&&find_node(neighbor[2*hash_table[a][i]],edge.second))
					{
						localN[hash_table[a][i]]--;
						globalN--;
					}
				}
				if(edge.second==p_reservoir[hash_table[a][i]].first)
				{
					int x=-1;
					for(unsigned j=0;j<neighbor[2*hash_table[a][i]].size();j++)
					{
						if(neighbor[2*hash_table[a][i]][j]==edge.first)
						{
							x=j;
							break;
						}
					}
					if(x!=-1)
					{
						neighbor[2*hash_table[a][i]][x]=neighbor[2*hash_table[a][i]].back();
						neighbor[2*hash_table[a][i]].pop_back();
					}
					if(x!=-1&&find_node(neighbor[2*hash_table[a][i]+1],edge.first))
					{
						localN[hash_table[a][i]]--;
						globalN--;
					}
				}
				if(edge.second==p_reservoir[hash_table[a][i]].second)
				{
					int x=-1;
					for(unsigned j=0;j<neighbor[2*hash_table[a][i]+1].size();j++)
					{
						if(neighbor[2*hash_table[a][i]+1][j]==edge.first)
						{
							x=j;
							break;
						}
					}
					if(x!=-1)
					{
						neighbor[2*hash_table[a][i]+1][x]=neighbor[2*hash_table[a][i]+1].back();
						neighbor[2*hash_table[a][i]+1].pop_back();
					}
					if(x!=-1&&find_node(neighbor[2*hash_table[a][i]],edge.first))
					{
						localN[hash_table[a][i]]--;
						globalN--;
					}
				}
			}
		}
		else
		{
			for(unsigned i=0;i<hash_table[a].size();i++)
			{
				if(edge.first==p_reservoir[hash_table[a][i]].first)
				{
					int x=-1;
					for(unsigned j=0;j<neighbor[2*hash_table[a][i]].size();j++)
					{
						if(neighbor[2*hash_table[a][i]][j]==edge.second)
						{
							x=j;
							break;
						}
					}
					if(x!=-1)
					{
						neighbor[2*hash_table[a][i]][x]=neighbor[2*hash_table[a][i]].back();
						neighbor[2*hash_table[a][i]].pop_back();
					}
					if(x!=-1&&find_node(neighbor[2*hash_table[a][i]+1],edge.second))
					{
						localN[hash_table[a][i]]--;
						globalN--;
					}
				}
				if(edge.first==p_reservoir[hash_table[a][i]].second)
				{
					int x=-1;
					for(unsigned j=0;j<neighbor[2*hash_table[a][i]+1].size();j++)
					{
						if(neighbor[2*hash_table[a][i]+1][j]==edge.second)
						{
							x=j;
							break;
						}
					}
					if(x!=-1)
					{
						neighbor[2*hash_table[a][i]+1][x]=neighbor[2*hash_table[a][i]+1].back();
						neighbor[2*hash_table[a][i]+1].pop_back();
					}
					if(x!=-1&&find_node(neighbor[2*hash_table[a][i]],edge.second))
					{
						localN[hash_table[a][i]]--;
						globalN--;
					}
				}
			}

			for(unsigned i=0;i<hash_table[b].size();i++)
			{

				if(edge.second==p_reservoir[hash_table[b][i]].first)
				{
					int x=-1;
					for(unsigned j=0;j<neighbor[2*hash_table[b][i]].size();j++)
					{
						if(neighbor[2*hash_table[b][i]][j]==edge.first)
						{
							x=j;
							break;
						}
					}
					if(x!=-1)
					{
						neighbor[2*hash_table[b][i]][x]=neighbor[2*hash_table[b][i]].back();
						neighbor[2*hash_table[b][i]].pop_back();
					}
					if(x!=-1&&find_node(neighbor[2*hash_table[b][i]+1],edge.first))
					{
						localN[hash_table[b][i]]--;
						globalN--;
					}
				}
				if(edge.second==p_reservoir[hash_table[b][i]].second)
				{
					int x=-1;
					for(unsigned j=0;j<neighbor[2*hash_table[b][i]+1].size();j++)
					{
						if(neighbor[2*hash_table[b][i]+1][j]==edge.first)
						{
							x=j;
							break;
						}
					}
					if(x!=-1)
					{
						neighbor[2*hash_table[b][i]+1][x]=neighbor[2*hash_table[b][i]+1].back();
						neighbor[2*hash_table[b][i]+1].pop_back();
					}
					if(x!=-1&&find_node(neighbor[2*hash_table[b][i]],edge.first))
					{
						localN[hash_table[b][i]]--;
						globalN--;
					}
				}
			}
		}
	}
}
