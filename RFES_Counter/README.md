# RFES: Reservoir-based the First Edge Sampling for Global Triangle Estimation in Large Graph Streams

Release Date: 15th November, 2021

Author

	~Changyong Yu (Northeastern University in CHINA)
	~Huimin Liu (Northeastern University in CHINA)
	~Zihan Ling(Northeastern University in CHINA)
                ~Tianmei Ren(Northeastern University in CHINA)
                ~Haitao Ma(Northeastern University in CHINA)
                ~Yuhai Zhao(Northeastern University in CHINA)

1.Introduction

RFES is a reservoir-based the first edge sampling algorithm, which is used to approximate count global triangles in large graph streams. 

	RFES also realizes the accurate counting of global triangles in small graphs.

	We all assume that the graphs are undirected, and the graphs themselves have no self-loops.

	There is a shortcoming of RFES. The RFES algorithm still needs a certain amount of memory to store the neighbor node lists corresponding to the nodes of the edges in the reservoir under a given reservoir capacity. Compared with other fixed-memory sampling algorithms, it may take up more memory space. However, compared with the fixed-probability sampling algorithm, the RFES algorithm does not consume computer memory. We think it is also acceptable to take up a slightly larger computer to store in exchange for more accurate global triangle counting.

	Overall, RFES can accurately and quickly count triangles in large graph streams. We believe that RFES will be a better algorithm for the study of triangle counting in large-scale graph streams.


2.Test Data

	The RFES algorithm approximately counts global triangles in large graph streams. The datasets are in .txt format, where each dataset contains three pieces of information {source node, destination node, edge addition/deletion}. The real datasets we use in the paper can be downloaded from the following website: http://snap.stanford.edu.


3.Building Notes

Our directory contains only a content : 1.codes to count the global triangles in large graph streams.

	$ make

After that, you can type commands to run tests using RFES. RFES provides 5 methods, four of which are used to count the triangles in the graph stream, and the fifth method is used to generate the full-dynamic datasets required by the experiment. Specifically, B, I and F correspond to three versions of RFES in this paper, and method E is an accurate triangle counting algorithm. Method G is used to generate full-dynamic graph streams randomly, and the generated full-dynamic graph stream datasets are used to test RFES-FD algorithm.


4.Usage Notes

1)E method. Count the number of real triangles in a graph stream.

	$ ./RFES_Counter -g dataset.txt -method  E  

Running test:

	$ ./RFES_Counter -g example.txt -method  E

	Input files:
		A graph dataset: example.txt
	Output files:
		The true number of the edges and the true number of the triangles in the graph.


2)B method. 
	$ ./RFES_Counter -g dataset.txt -method  B -resSize M

Running test:

	$ ./RFES_Counter -g example.txt -method  B -resSize 10000

	Input files:
		A insertion-only graph dataset: example.txt; Reservoir capacity: M
	Output files:
		When the reservoir capacity is 10000, the approximate result of the global triangle in the graph.


3)I method. 

	$ ./RFES_Counter -g dataset.txt -method  I -resSize M

Running test:

	$ ./RFES_Counter -g example.txt -method  I -resSize 10000

	Input files:
		A insertion-only graph dataset: example.txt; Reservoir capacity: M
	Output files:
		When the reservoir capacity is 10000, the approximate result of the global triangle in the graph.


4)F method. 

	 $ ./RFES_Counter -g dataset.txt -method  F -resSize M

Running test:

	$ ./RFES_Counter -g example.txt_new -method  F -resSize 10000

	Input files:
		A fully-dynamic graph dataset: example.txt_new; Reservoir capacity: M
	Output files:
		When the reservoir capacity is 10000, the approximate result of the global triangle in the graph.


5)G method. 
	$ ./RFES_Counter -g dataset.txt -method  G -p n

Running test:

	$ ./RFES_Counter -g example.txt -method  G -p 0.1

	Input files:
		A graph dataset: example.txt; Probability of edge deletion: n(numbers between 0 and 1)

	Output files:
		The example.txt is transformed into a full-dynamic graph dataset example.txt_new with a certain edge deletion probability n.


5.Parameter Settings

The format of a parameter of RFES in the command line is a pair of strings, here we denote the pair as (-p, [q]) or (-p,<q>). String p is the name of the parameter. String q is the value of the parameter input in the command line. [q] represents that the parameter is a optional parameter. <q> represents that the parameter is a necessary parameter.

@parameter (-g,<graph.txt>)

	Parameter 'g' gives the file name of a dataset. For example, '-g'="exapmle.txt", example.txt is a text file.

@parameter (-method,[method])

	Parameter 'method' selects the counting method during the experimental test.

@parameter (-resSize, <reservoir capacity>)

	Parameter 'resSize' sets the reservoir capacity used in the experiment. Please note that the reservoir capacity is not the total memory consumption of the entire experiment, because RFES also needs a certain amount of memory to save the neighbor node lists corresponding to the edges in the reservoir.

@parameter (-seed, [random seed])

	Parameter 'seed' determines the number of experiments for this method. In fact, it is for multiple experiments to reduce experimental errors. 

@parameter (-p, [probability of edge deletion])

	When using the G method to generate a fully-dynamic dataset, an edge deletion probability is required, and its value is between 0 and 1.


6.Contacts

	Please e-mail your feedback at cyyneu@126.com.







