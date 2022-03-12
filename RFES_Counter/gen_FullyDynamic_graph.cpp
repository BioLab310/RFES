/*
 * gen_FullyDynamic_graph.cpp
 *
 *  Created on: Oct 29, 2021
 *      Author: bio
 */

#include "gen_FullyDynamic_graph.h"
void gen_FD_graph(char * fp,double p)
{
	//p=0:convert two colomns to three colomns
	ifstream in(fp);
	string newFileName(fp);
	newFileName=newFileName+"_new";
	ofstream out(newFileName.c_str());
	vector < pair<unsigned,unsigned> > ve;
	ve.clear();
	vector < unsigned > ve_sub_id;

	unsigned x=0,y=0;
	unsigned r=1;
	unsigned rr=0;
	unsigned u,v,w;
	string line;
	pair<unsigned,unsigned> edge;

	while(!in.eof())
	{
		line.clear();
		if(!getline(in, line))
		{
			break;
		}
		x++;
		y++;
		istringstream iss(line, istringstream::in);
		iss >> u >> v;
		out << u <<" " <<  v << " " << r << endl;

		double rand1_ = (double)rand() / ((double)RAND_MAX+1.0);
		if(rand1_ < p)
		{
			unsigned id_tmp;
			if(ve.size()>=100)
			{
				id_tmp=rand()%ve.size();
				if(find(ve_sub_id.begin(),ve_sub_id.end(),id_tmp)==ve_sub_id.end())
				{
					y++;
					out << ve[id_tmp].first <<" " <<  ve[id_tmp].second << " " << rr << endl;
					ve_sub_id.push_back(id_tmp);
				}
			}
		}

		edge=make_pair(u,v);
		ve.push_back(edge);
	}

	ve.clear();
	ve_sub_id.clear();
	cout << x << "	" << y << endl;
}

