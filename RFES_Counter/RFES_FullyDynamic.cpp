/*
 * RFES_FullyDynamic.cpp
 *
 *  Created on: Oct 29, 2021
 *      Author: bio
 */
#include "RFES_FullyDynamic.h"

void RFES_FullyDynamic(char * input_graph_filename)
{
	//initial
	p_reservoir=(pair<unsigned,unsigned> *)malloc(sizeof(pair<unsigned,unsigned>)*M);
	neighbor.resize(2*M);
	localN=(unsigned *)malloc(sizeof(unsigned)*M);

	globalN=0;
	for(unsigned i=0;i<M;i++)
	{
		localN[i]=0;
		neighbor[i].clear();
		neighbor[i+M].clear();
	}
	cur_res_size=0;
	cur_popBack_pos=0;
	cur_graph_size=0;
	cur_popBack_pos_vec.clear();
	for(unsigned i=0;i<M;i++)
	{
		cur_popBack_pos_vec.push_back(M-1-i);
	}
	nb=0;
	ng=0;

	pair<int,int> edge;
	unsigned u,v,w;
	hash_table_initial();

	struct timeval tvs,tve;
	gettimeofday(&tvs,NULL);


	ifstream stream(input_graph_filename);
	string line;
	while(!stream.eof())
	{
		line.clear();
		getline(stream, line);
		istringstream iss(line, istringstream::in);
		iss >> u >> v >> w;

		cur_graph_size++;
		edge=make_pair(u,v);

		if(cur_graph_size%10000==0)
		{
			gettimeofday(&tve,NULL);
			double span = tve.tv_sec-tvs.tv_sec + (tve.tv_usec-tvs.tv_usec)/1000000.0;
			cout <<"time cost for " << cur_graph_size/10000 << ":" <<span<<endl;
			cout << "the number of triangles:" << globalN <<endl;
		}

		if(w==1)
		{
			SampleEdge(edge);
			UpdateNeiborNodeList_FullyDynamic(edge,w);
		}
		else
		{
			int x=find_in_res(edge);
			if(x!=-1)
			{
				hash_table_delete_edge(p_reservoir[x],x);

				//update counters
				globalN=globalN-localN[x];
				localN[x]=0;

				//update neighbor lists
				neighbor[2*x].clear();
				neighbor[2*x+1].clear();

				cur_popBack_pos_vec.push_back(x);

				UpdateNeiborNodeList_FullyDynamic(edge,w);
				cur_res_size--;
				nb++;
			}
			else
			{
				UpdateNeiborNodeList_FullyDynamic(edge,w);
				ng++;
			}
		}

	}
	cout << globalN << endl;
	cout << cur_popBack_pos << endl;

	free(p_reservoir);
	free(localN);
	neighbor.clear();
	cur_popBack_pos_vec.clear();
}

