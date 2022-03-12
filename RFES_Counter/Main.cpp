#include "Basic.h"
#include "reservoir.h"
#include "counter.h"
#include "neighbor.h"
#include "hash.h"
#include "RFES_Base.h"
#include "RFES_Improve.h"
#include "RFES_FullyDynamic.h"
#include "gen_FullyDynamic_graph.h"
#include "exact_counter.h"

void print_usage() {
	cout << "RFES Reachability Index" << endl;
	cout << "Usage: minVbl -g <GRAPHFILE> -q <QUERYFILE> [-k <SIZE>] [-d <DELTA>]" << endl;
	cout << "Description:\n"
         "-g <GRAPHFILE> is the name of the input graph in gra format.\n"
         "-q <QUERYFILE> contains a line of <src> <dest> <reachability> for each query.\n"
         "-k <SIZE> sets the value of parameter k, default value is 2.\n"
         "-d <DELTA> sets the value of parameter delta, default value is 2.\n" << endl;
}

int main(int argc, char *argv[])
{
	char *input_graph_filename;
	char Method=' ';
	string h="";
	int random_seed;
	double p;
	unsigned en=0;

	for (int i = 0; i < argc; ++i) {
		string arg = argv[i];
		if (arg == "-g") {         // graph file
			input_graph_filename = argv[++i];
		}else if (arg == "-resSize") {  // index size constraint
			M = atoi(argv[++i]);
		}else if (arg == "-method") {  // index size constraint
			Method = argv[++i][0];
		}else if (arg == "-seed") {  // delta-minV BL
			random_seed = atoi(argv[++i]);
		}else if (arg == "-eNO") {  // delta-minV BL
			en = atoi(argv[++i]);
		}else if (arg == "-p") {  // delta-minV BL
			p = atof(argv[++i]);
		}else if (arg == "-h") {  // delta-minV BL
			h = "help";
		}
	}

	srand(random_seed);
	if(h == "help") {
		print_usage();
		return 1;
	}
	if(Method=='B')
	{
		RFES_Base(input_graph_filename);
	}
	else if(Method=='I')
	{
		RFES_Improve(input_graph_filename);
	}
	else if(Method=='F')
	{
		RFES_FullyDynamic(input_graph_filename);
	}
	else if(Method=='G')
	{
		gen_FD_graph(input_graph_filename,p);
	}
	else if(Method=='E')
	{
		exact_counting(input_graph_filename,en);
	}

}
