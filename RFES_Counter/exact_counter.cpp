/*
 * exact_counter.cpp
 *
 *  Created on: Nov 1, 2021
 *      Author: bio
 */
#include "exact_counter.h"

unsigned gN;

vector <unsigned> nv;
vector <vector <unsigned> > nn;

int find_pos(unsigned node)
{
	int r;
	r=-1;
	unsigned hash_id=hash_function(node);

	for(unsigned i=0;i<hash_table[hash_id].size();i++)
	{
		if(nv[hash_table[hash_id][i]]==node)
		{
			return hash_table[hash_id][i];
		}
	}
	return r;
}

unsigned intersection_size(vector<unsigned> a,vector<unsigned> b)
{
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	unsigned r=0,p=0,q=0;
	while(p!=a.size()&&q!=b.size())
	{
		if(a[p]<b[q])
		{
			p++;
		}
		else if(a[p]>b[q])
		{
			q++;
		}
		else
		{
			r++;
			p++;
			q++;
		}
	}
	return r;
}

void update_nn(pair<unsigned,unsigned> edge,unsigned label)
{
	if(label==1)
	{
		int tmp=find_pos(edge.first);
		if(tmp!=-1)
		{
			nn[tmp].push_back(edge.second);
		}
		else
		{
			unsigned ss;
			ss=nv.size();
			vector<unsigned> tmp_ve;
			tmp_ve.clear();
			tmp_ve.push_back(edge.second);
			nn.push_back(tmp_ve);
			hash_table_insert(edge.first,ss);
			nv.push_back(edge.first);
		}

		tmp=find_pos(edge.second);
		if(tmp!=-1)
		{
			nn[tmp].push_back(edge.first);
		}
		else
		{
			unsigned ss;
			ss=nv.size();
			vector<unsigned> tmp_ve;
			tmp_ve.clear();
			tmp_ve.push_back(edge.first);
			nn.push_back(tmp_ve);
			hash_table_insert(edge.second,ss);
			nv.push_back(edge.second);
		}
	}
	else
	{
		int tmp=find_pos(edge.first);
		if(tmp!=-1)
		{
			for(unsigned i=0;i<nn[tmp].size();i++)
			{
				if(nn[tmp][i]==edge.second)
				{
					nn[tmp][i]=nn[tmp].back();
					nn[tmp].pop_back();
					break;
				}
			}
		}

		tmp=find_pos(edge.second);
		if(tmp!=-1)
		{
			for(unsigned i=0;i<nn[tmp].size();i++)
			{
				if(nn[tmp][i]==edge.first)
				{
					nn[tmp][i]=nn[tmp].back();
					nn[tmp].pop_back();
					break;
				}
			}
		}
	}
}

void exact_counting(char * fp,unsigned eN)
{
	//en=0:the total edges in the file
	ifstream in(fp);

	gN=0;
	nn.clear();
	nv.clear();
	hash_table_initial();

	unsigned u,v,w;
	string line;
	pair<unsigned,unsigned> edge;
	unsigned en=0;

	while((!in.eof()&&en<eN&&(eN!=0))||(!in.eof()&&eN==0))
	{
		line.clear();
		if(!getline(in, line))
		{
			break;
		}
		en++;
		istringstream iss(line, istringstream::in);
		iss >> u >> v >> w;

		edge=make_pair(u,v);
		int pos1,pos2;
		pos1=find_pos(u);
		pos2=find_pos(v);
		if(pos1!=-1&&pos2!=-1)
		{
			if(w==1)
			{
				gN+=intersection_size(nn[pos1],nn[pos2]);
			}
			else
			{
				gN-=intersection_size(nn[pos1],nn[pos2]);
			}
		}
		update_nn(edge,w);
	}

	cout << en << endl;
	cout << gN << endl;

}

