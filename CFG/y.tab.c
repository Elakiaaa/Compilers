#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 2 "threeaddr.y"
	#include<bits/stdc++.h>
	typedef long long ll;
	using namespace std;
	int yylex();
	void yyerror(char *s);
	
	/*for 3addr*/
	int tempcount=0;
	int getTemp();
	typedef struct node
	{
		string  addr, array;
		pair<string,vector<ll> > type;
		vector<ll> trueList,falseList,nextList;
		int instNum;
	}NODE;

	NODE* makeNode()
	{
		NODE *temp=new NODE();
		ostringstream ss;
		ss<<"t"<<getTemp();
		temp->addr=ss.str();
		ss.str("");
		temp->array="";
		return temp;
	}
	NODE* makeNode(string *x)
	{
		NODE *temp=new NODE();
		temp->addr=*x;
		temp->array="";
		return temp;
	}

	/*for symbol table*/
	deque<string> s;
	deque<int> vars;
	deque<int> blocks;
	int blocknum=-1,varnum=0;
	string currType;
	map<ll,map<string,pair<pair<string,vector<ll> >,string> > > table;/*blockno,varname,type,dimensions,value*/
	map<string,ll> width;
	ll getWidth(pair<string,vector<ll> > type);
	string to_string(ll val);
	ll to_int(string val);
	void insertID(int bno,string varname);
	void printTable();

	/* for backpatch*/
	int instCounter=0;
	map<ll,string> instList;
	int nextInst();
	vector<ll> merge(vector<ll> a,vector<ll> b);
	void backpatch(vector<ll> list,int num);
	void displayInst();

	/*for Control Flow Graph*/
	map<ll,vector<string> > basicBlock;
	set<ll> leaders;
	vector<vector<ll> > bbgraph;
	void genBasicBlock();
	void findLeaders();

#line 68 "threeaddr.y"
typedef union{
	typedef struct node NODE;
	string *str;
	NODE *node;

} YYSTYPE;
#line 95 "y.tab.c"
#define KEY 257
#define AND 258
#define OR 259
#define NOT 260
#define RELOP 261
#define ID 262
#define VAL 263
#define SC 264
#define CM 265
#define PL 266
#define MI 267
#define MUL 268
#define DIV 269
#define POW 270
#define OP 271
#define CL 272
#define AO 273
#define AC 274
#define EQ 275
#define BO 276
#define BC 277
#define UNR 278
#define TRUE 279
#define FALSE 280
#define IF 281
#define ELSE 282
#define WHILE 283
#define YYERRCODE 256
short yylhs[] = {                                        -1,
   22,    0,   15,   15,   15,   15,   15,   15,   12,   13,
   14,   23,   17,   16,   16,   16,   24,   18,   20,   20,
   21,   21,   25,   19,   19,   11,   11,    9,    9,   10,
    1,    1,    1,    2,    2,    2,    2,    2,    3,    4,
    5,    5,    5,    5,    6,    6,    6,    7,    7,    8,
    8,    8,    8,    8,
};
short yylen[] = {                                         2,
    0,    2,    1,    1,    1,    1,    1,    1,    6,   10,
    7,    0,    4,    3,    1,    0,    0,    5,    2,    4,
    4,    0,    0,    4,    0,    4,    4,    4,    4,    1,
    4,    4,    1,    2,    3,    3,    1,    1,    0,    0,
    3,    3,    1,    1,    3,    3,    1,    3,    1,    3,
    1,    1,    1,    2,
};
short yydefred[] = {                                      1,
    0,    0,    0,    0,   12,    0,   39,    0,    7,    3,
    4,    5,   15,    0,    6,    8,    0,   17,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   53,    0,    0,    0,    0,   47,    0,    0,    0,    0,
    0,    0,    0,   37,   38,    0,   33,    0,    0,    0,
    0,   14,    0,    0,    0,    0,   54,    0,    0,    0,
    0,   28,    0,    0,    0,   27,   13,   34,    0,    0,
   39,   39,   39,    0,    0,   29,   26,    0,   20,   23,
   18,   50,    0,    0,   45,   46,   48,   35,    0,    0,
    0,    0,   39,   21,    0,   32,   31,    0,    0,   24,
   40,   11,   39,    0,   10,
};
short yydgoto[] = {                                       1,
   46,   47,   26,  103,   48,   35,   36,   37,   38,   40,
    9,   10,   11,   12,   13,   14,   15,   16,   56,   18,
   28,    2,   21,   29,   95,
};
short yysindex[] = {                                      0,
    0, -249, -251, -257,    0, -226,    0, -232,    0,    0,
    0,    0,    0,    0,    0,    0, -224,    0, -172, -172,
 -249, -223, -198, -172, -172, -249, -179, -199, -169, -166,
    0, -172, -172,  -75, -243,    0, -184, -154, -214, -151,
 -162, -223, -223,    0,    0, -252,    0,  -84, -223,  -73,
 -140,    0, -144, -131, -251, -128,    0, -154,  -70, -172,
 -172,    0, -172, -172, -172,    0,    0,    0, -237,  -82,
    0,    0,    0, -172, -230,    0,    0, -224,    0,    0,
    0,    0, -243, -243,    0,    0,    0,    0, -223, -223,
 -249, -214,    0,    0, -169,    0,    0, -143, -249,    0,
    0,    0,    0, -249,    0,
};
short yyrindex[] = {                                      0,
    0,  138,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    4,    0,    0, -210,    0,    0,    0,
 -136,    0,    0,    0,    0,    0,    0, -160, -117, -158,
    0,    0,    0,    0, -107,    0, -187, -141, -115,    0,
 -245,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -124,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -210,    0,    0,
    0,    0, -103,  -86,    0,    0,    0,    0,    0,    0,
    0, -212,    0,    0, -117,    0,    0,    1,    0,    0,
    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
   26,  -39,   -5,    0,  -10,   61,   29,  121,   -2,  137,
    0,    0,    0,    0,  -21,  145,    0,    0,   73,  115,
   96,    0,    0,    0,    0,
};
#define YYTABLESIZE 287
short yytable[] = {                                       8,
    9,   23,   68,    2,   52,   71,   72,    3,   34,   39,
   17,   39,    4,   50,   39,   19,   39,   20,    8,   73,
   71,   72,   59,    8,   63,   64,    5,   71,   72,   58,
   39,    6,   70,    7,   88,   39,   42,   39,   30,   31,
   24,   93,   25,   32,   22,   36,   36,   43,   27,   96,
   97,   60,   61,   22,   22,   44,   45,   58,   58,   36,
   58,   58,   58,   92,   22,   89,   90,   91,   69,   98,
   49,   49,   49,   49,   75,   54,   49,  102,   49,   49,
   49,   49,  105,   53,   49,   65,   49,   99,    8,   30,
   31,   85,   86,   87,   32,   55,    8,  104,   33,   51,
   51,    8,   51,   19,   19,   51,   19,   51,   51,   51,
   51,   51,   66,   51,   67,   51,   44,   44,   24,   44,
   83,   84,   44,   77,   44,   44,   52,   52,   52,   78,
   44,   79,   44,   52,   52,   81,   52,   16,  101,   52,
   16,   52,   52,   52,   52,   52,   25,   52,   30,   52,
   43,   43,   57,   43,   41,   41,   43,   41,   43,   43,
   41,   51,   41,   41,   43,   41,   43,  100,   41,   80,
   41,   42,   42,   94,   42,    0,   74,   42,   74,   42,
   42,   60,   61,   60,   61,   42,    0,   42,    0,   82,
   60,   61,   60,   61,    0,   60,   61,    0,   62,    0,
   76,   82,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    9,    0,    0,
   39,    0,    9,    0,    0,   39,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    9,    9,    0,   39,
    0,    9,    0,    9,   39,    0,   39,
};
short yycheck[] = {                                       2,
    0,    7,   42,    0,   26,  258,  259,  257,   19,   20,
  262,  257,  262,   24,   25,  273,  262,  275,   21,  272,
  258,  259,   33,   26,  268,  269,  276,  258,  259,   32,
  276,  281,   43,  283,  272,  281,  260,  283,  262,  263,
  273,  272,  275,  267,  271,  258,  259,  271,  273,   89,
   90,  266,  267,  264,  265,  279,  280,   60,   61,  272,
   63,   64,   65,   74,  275,   71,   72,   73,   43,   91,
  258,  259,  271,  261,   49,  275,  264,   99,  266,  267,
  268,  269,  104,  263,  272,  270,  274,   93,   91,  262,
  263,   63,   64,   65,  267,  265,   99,  103,  271,  258,
  259,  104,  261,  264,  265,  264,  273,  266,  267,  268,
  269,  270,  264,  272,  277,  274,  258,  259,  273,  261,
   60,   61,  264,  264,  266,  267,  268,  269,  270,  274,
  272,  263,  274,  258,  259,  264,  261,    0,  282,  264,
  277,  266,  267,  268,  269,  270,  264,  272,  264,  274,
  258,  259,   32,  261,  258,  259,  264,  261,  266,  267,
  264,   25,  266,  267,  272,   21,  274,   95,  272,   55,
  274,  258,  259,   78,  261,   -1,  261,  264,  261,  266,
  267,  266,  267,  266,  267,  272,   -1,  274,   -1,  272,
  266,  267,  266,  267,   -1,  266,  267,   -1,  274,   -1,
  274,  272,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,
  257,   -1,  262,   -1,   -1,  262,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,   -1,  276,
   -1,  281,   -1,  283,  281,   -1,  283,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 283
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KEY","AND","OR","NOT","RELOP",
"ID","VAL","SC","CM","PL","MI","MUL","DIV","POW","OP","CL","AO","AC","EQ","BO",
"BC","UNR","TRUE","FALSE","IF","ELSE","WHILE",
};
char *yyrule[] = {
"$accept : ss",
"$$1 :",
"ss : $$1 stmt_list",
"stmt : if",
"stmt : ifelse",
"stmt : while",
"stmt : block",
"stmt : a",
"stmt : decl",
"if : IF OP bool CL m stmt",
"ifelse : IF OP bool CL m stmt ELSE n m stmt",
"while : WHILE m OP bool CL m stmt",
"$$2 :",
"block : BO $$2 stmt_list BC",
"stmt_list : stmt_list m stmt",
"stmt_list : stmt",
"stmt_list :",
"$$3 :",
"decl : KEY id $$3 d SC",
"id : ID arr",
"id : ID arr EQ VAL",
"arr : AO VAL AC arr",
"arr :",
"$$4 :",
"d : CM id $$4 d",
"d :",
"a : l EQ r SC",
"a : ID EQ r SC",
"l : ID AO e AC",
"l : l AO e AC",
"r : e",
"bool : bool OR m bb",
"bool : bool AND m bb",
"bool : bb",
"bb : NOT bb",
"bb : OP bool CL",
"bb : e RELOP e",
"bb : TRUE",
"bb : FALSE",
"m :",
"n :",
"e : e PL t",
"e : e MI t",
"e : t",
"e : l",
"t : t MUL f",
"t : t DIV f",
"t : f",
"f : g POW f",
"f : g",
"g : OP e CL",
"g : ID",
"g : l",
"g : VAL",
"g : MI g",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 245 "threeaddr.y"

void genFlowGraph()
{
	bbgraph.resize(basicBlock.size());
	for(map<ll,vector<string> >::iterator it=basicBlock.begin();it!=basicBlock.end();it++)
	{
		ll ind=-1;
		string lastStmt=it->second.back();
		if((ind=lastStmt.rfind("goto"))!=-1)
		{
			bbgraph[it->first].push_back(to_int(lastStmt.substr(ind+5)));
			if(ind!=0 && it->first!=basicBlock.size()-1)
			{
				bbgraph[it->first].push_back(it->first+1);
			}
		}
		else
		{
			if(it->first!=basicBlock.size()-1)
				bbgraph[it->first].push_back(it->first+1);
		}
	}
}
void displayFlowGraph()
{
	cout<<"Flow Graph:"<<endl;
	for(ll i=0;i<bbgraph.size();i++)
	{
		cout<<i<<": ";
		for(ll j=0;j<bbgraph[i].size();j++)
		{
			cout<<bbgraph[i][j]<<" ";
		}
		cout<<endl;
	}
}
void findLeaders()
{
	bool flag=true;
	for(map<ll,string>::iterator it=instList.begin();it!=instList.end();it++)
	{
		if(flag)
		{
			leaders.insert(it->first);
			ll ind=it->second.rfind("goto");
			if(ind!=-1)
			{
				leaders.insert(to_int(it->second.substr(ind+5)));
				flag=true;
				continue;
			}
			flag=false;
		}
		ll ind=it->second.rfind("goto");
		if(ind!=-1)
		{
			leaders.insert(to_int(it->second.substr(ind+5)));
			flag=true;
			continue;
		}
	}
}
void displayLeaders()
{
	cout<<"Leaders:"<<endl;
	for(set<ll>::iterator it=leaders.begin();it!=leaders.end();it++)
	{
		cout<<*it<<endl;
	}
}
void genBasicBlock()
{
	findLeaders();
	map<ll,ll> lineToBlock;
	ll bbno=-1;
	for(map<ll,string>::iterator it=instList.begin();it!=instList.end();it++)
	{
		if(leaders.find(it->first)!=leaders.end())
		{
			bbno++;
		}
		lineToBlock[it->first]=bbno;
	}
	bbno=-1;
	for(map<ll,string>::iterator it=instList.begin();it!=instList.end();it++)
	{
		if(leaders.find(it->first)!=leaders.end())
		{
			bbno++;
		}
		ll ind=-1;
		string bbinst=it->second;
		if((ind=it->second.rfind("goto"))!=-1)
		{
			bbinst=it->second.substr(0,ind+5) + to_string(lineToBlock[to_int(it->second.substr(ind+5))]);
		}
		basicBlock[bbno].push_back(bbinst);
	}
}
void displayBasicBlocks()
{
	cout<<"Basic Blocks:"<<endl;
	for(map<ll,vector<string> >::iterator it=basicBlock.begin();it!=basicBlock.end();it++)
	{
		cout<<"Block "<<it->first<<":"<<endl;
		for(ll i=0;i<it->second.size();i++)
		{
			cout<<"\t"<<it->second[i]<<endl;
		}
		cout<<endl;
	}
}
void displayInst()
{
	cout<<"Three Address Statements:"<<endl;
	for(map<ll,string>::iterator it=instList.begin();it!=instList.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	cout<<endl;
}

int getTemp()
{
	return tempcount++;
}
int nextInst()
{
	return instCounter++;
}
vector<ll> merge(vector<ll> a,vector<ll> b)
{
	a.insert(a.end(),b.begin(),b.end());
	return a;
}
void backpatch(vector<ll> list,int num)
{
	for(ll i=0;i<list.size();i++)
	{
		if(instList[list[i]].find("goto")==instList[list[i]].length()-4)
		{
			instList[list[i]]+=" "+to_string(num);
		}
	}
}
void insertID(int bno,string varname)
{
	string type,value;
	int ind=varname.find(" ");
	if(ind!=-1)
	{
		type=varname.substr(0,ind);
		varname=varname.substr(ind+1);
	}
	ind=varname.find("=");
	value="";
	if(ind!=-1)
	{
		value=varname.substr(ind+1);
		varname=varname.substr(0,ind);
	}
	ind=varname.find("[");
	vector<ll> dims;
	if(ind!=-1)
	{
		string indexes=varname.substr(ind);
		varname=varname.substr(0,ind);
		for(ll i=0;i<indexes.length();i++)
		{
			if(indexes[i]=='[' || indexes[i]==']')
				indexes[i]=' ';
		}
		istringstream in(indexes.c_str());
		int dim;
		while(in>>dim)
		{
			dims.push_back(dim);
		}
	}
	table[bno][varname]=make_pair(make_pair(type,dims),value);
}
ll getWidth(pair<string,vector<ll> > type)
{
	ll ans=width[type.first];
	for(ll i=1;i<type.second.size();i++)
	{
		ans=ans*type.second[i];
	}
	return ans;
}
void printTable()
{
	for(map<ll,map<string,pair<pair<string,vector<ll> >,string> > >::iterator it=table.begin();it!=table.end();it++)
	{
		cout<<it->first<<endl;
		for(map<string,pair<pair<string,vector<ll> >,string> >::iterator it2=it->second.begin();it2!=it->second.end();it2++)
		{
			cout<<it2->first<<" "<<it2->second.first.first<<" "<<it2->second.second;
			for(vector<ll>::iterator it3=it2->second.first.second.begin();it3!=it2->second.first.second.end();it3++)
				cout<<*it3<<' ';
			cout<<endl;
		}
		cout<<endl;
	}
}
void setWidths()
{
	width["int"]=4;
	width["float"]=4;
	width["char"]=1;
	width["double"]=8;
}
string to_string(ll val)
{
	ostringstream ss;
	ss<<val;
	return ss.str();
}
ll to_int(string val)
{
	istringstream ss(val);
	ll x;
	ss>>x;
	return x;
}
void yyerror(char* s)
{
	cout<<s<<endl;
	exit(0);
}
int main()
{
	setWidths();
	yyparse();
	displayInst();
	genBasicBlock();
	displayBasicBlocks();
	genFlowGraph();
	displayFlowGraph();
}
#line 601 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 82 "threeaddr.y"
{
			blocknum++;
			blocks.push_back(blocknum);
			vars.push_back(varnum);
			varnum=0;
		}
break;
case 2:
#line 88 "threeaddr.y"
{}
break;
case 3:
#line 90 "threeaddr.y"
{yyval.node=new NODE();yyval.node->nextList=yyvsp[0].node->nextList;}
break;
case 4:
#line 91 "threeaddr.y"
{yyval.node=new NODE();yyval.node->nextList=yyvsp[0].node->nextList;}
break;
case 5:
#line 92 "threeaddr.y"
{yyval.node=new NODE();yyval.node->nextList=yyvsp[0].node->nextList;}
break;
case 6:
#line 93 "threeaddr.y"
{yyval.node=new NODE();yyval.node->nextList=yyvsp[0].node->nextList;}
break;
case 7:
#line 94 "threeaddr.y"
{yyval.node=new NODE();yyval.node->nextList=yyvsp[0].node->nextList;}
break;
case 8:
#line 95 "threeaddr.y"
{yyval.node=new NODE();yyval.node->nextList=yyvsp[0].node->nextList;}
break;
case 9:
#line 97 "threeaddr.y"
{
								yyval.node=new NODE();
								backpatch(yyvsp[-3].node->trueList,yyvsp[-1].node->instNum);
								yyval.node->nextList=merge(yyvsp[-3].node->falseList,yyvsp[0].node->nextList);
							}
break;
case 10:
#line 102 "threeaddr.y"
{
											yyval.node=new NODE();
											backpatch(yyvsp[-7].node->trueList,yyvsp[-5].node->instNum);
											backpatch(yyvsp[-7].node->falseList,yyvsp[-1].node->instNum);
											yyval.node->nextList=merge(yyvsp[-4].node->nextList,yyvsp[-2].node->nextList);
											yyval.node->nextList=merge(yyval.node->nextList,yyvsp[0].node->nextList);
										}
break;
case 11:
#line 109 "threeaddr.y"
{
									yyval.node=new NODE();
									backpatch(yyvsp[-3].node->trueList,yyvsp[-1].node->instNum);
									backpatch(yyvsp[0].node->nextList,yyvsp[-5].node->instNum);
									instList[nextInst()]="goto "+to_string(yyvsp[-5].node->instNum);
									yyval.node->nextList=yyvsp[-3].node->falseList;
								}
break;
case 12:
#line 116 "threeaddr.y"
{
			blocknum++;
			blocks.push_back(blocknum);
			for(int i=0;i<s.size();i++)
			{
				insertID(blocknum,s[i]);
			}
			vars.push_back(varnum);
			varnum=0;
		}
break;
case 13:
#line 127 "threeaddr.y"
{
			blocks.pop_back();
			for(int i=0;i<varnum;i++)
				s.pop_back();
			varnum=vars.back();
			vars.pop_back();	
			yyval.node=new NODE();
			yyval.node->nextList=yyvsp[-1].node->nextList;
		}
break;
case 14:
#line 136 "threeaddr.y"
{
								yyval.node=new NODE();
								backpatch(yyvsp[-2].node->nextList,yyvsp[-1].node->instNum);
								yyval.node->nextList=yyvsp[0].node->nextList;
							}
break;
case 15:
#line 141 "threeaddr.y"
{yyval.node->nextList=yyvsp[0].node->nextList;}
break;
case 16:
#line 141 "threeaddr.y"
{}
break;
case 17:
#line 142 "threeaddr.y"
{
				varnum++;s.push_back(*yyvsp[-1].str+" "+*yyvsp[0].str);
				insertID(blocks.back(),*yyvsp[-1].str+" "+*yyvsp[0].str);
				currType=*yyvsp[-1].str;
			}
break;
case 18:
#line 146 "threeaddr.y"
{yyval.node=new NODE();}
break;
case 19:
#line 148 "threeaddr.y"
{yyval.str=new string(*yyvsp[-1].str+*yyvsp[0].str);}
break;
case 20:
#line 148 "threeaddr.y"
{yyval.str=new string(*yyvsp[-3].str+*yyvsp[-2].str+*yyvsp[-1].str+*yyvsp[0].str);}
break;
case 21:
#line 150 "threeaddr.y"
{yyval.str=new string(*yyvsp[-3].str+*yyvsp[-2].str+*yyvsp[-1].str+*yyvsp[0].str);}
break;
case 22:
#line 150 "threeaddr.y"
{yyval.str=new string("");}
break;
case 23:
#line 152 "threeaddr.y"
{
			varnum++;s.push_back(currType+" "+*yyvsp[0].str);
			insertID(blocks.back(),currType+" "+*yyvsp[0].str);
		}
break;
case 25:
#line 155 "threeaddr.y"
{}
break;
case 26:
#line 157 "threeaddr.y"
{instList[nextInst()]=yyvsp[-3].node->array+"["+yyvsp[-3].node->addr+"]= "+yyvsp[-1].node->addr;	}
break;
case 27:
#line 158 "threeaddr.y"
{
	  					if(table[blocks.back()].find(*yyvsp[-3].str)==table[blocks.back()].end())
						{
							yyerror("variable not declared");
						}
	  					instList[nextInst()]=*yyvsp[-3].str+" = "+yyvsp[-1].node->addr;
	  					yyval.node=new NODE();
	  				}
break;
case 28:
#line 167 "threeaddr.y"
{
					yyval.node=makeNode();
					yyval.node->array=*yyvsp[-3].str;
					if(table[blocks.back()].find(*yyvsp[-3].str)==table[blocks.back()].end())
					{
						yyerror("variable not declared");
					}
					yyval.node->type=table[blocks.back()][*yyvsp[-3].str].first;
					instList[nextInst()]=yyval.node->addr+" = "+yyvsp[-1].node->addr+" * "+to_string(getWidth(yyval.node->type));
				}
break;
case 29:
#line 178 "threeaddr.y"
{
		 			NODE *myTemp=makeNode();
		 			yyval.node=makeNode();
		 			yyval.node->array=yyvsp[-3].node->array;
		 			yyval.node->type=yyvsp[-3].node->type;
		 			yyval.node->type.second.erase(yyval.node->type.second.begin());
		 			instList[nextInst()]=myTemp->addr + " = "+yyvsp[-1].node->addr +" * "+to_string(getWidth(yyval.node->type));
		 			instList[nextInst()]=yyval.node->addr+" = "+yyvsp[-3].node->addr+ " + " + myTemp->addr;
		 		}
break;
case 30:
#line 187 "threeaddr.y"
{yyval.node=yyvsp[0].node;}
break;
case 31:
#line 189 "threeaddr.y"
{
					yyval.node=new NODE();
					backpatch(yyvsp[-3].node->falseList,yyvsp[-1].node->instNum);
					yyval.node->trueList=merge(yyvsp[-3].node->trueList,yyvsp[0].node->trueList);
					yyval.node->falseList=yyvsp[0].node->falseList;
				}
break;
case 32:
#line 195 "threeaddr.y"
{
	 				yyval.node=new NODE();
	 				backpatch(yyvsp[-3].node->trueList,yyvsp[-1].node->instNum);
	 				yyval.node->trueList=yyvsp[0].node->trueList;
	 				yyval.node->falseList=merge(yyvsp[-3].node->falseList,yyvsp[0].node->falseList);
				}
break;
case 33:
#line 201 "threeaddr.y"
{yyval.node=new NODE();yyval.node->trueList=yyvsp[0].node->trueList;yyval.node->falseList=yyvsp[0].node->falseList;}
break;
case 34:
#line 203 "threeaddr.y"
{yyval.node=new NODE();yyval.node->trueList=yyvsp[0].node->falseList;yyval.node->falseList=yyvsp[0].node->trueList;}
break;
case 35:
#line 204 "threeaddr.y"
{yyval.node=new NODE();yyval.node->trueList=yyvsp[-1].node->trueList;yyval.node->falseList=yyvsp[-1].node->falseList;}
break;
case 36:
#line 205 "threeaddr.y"
{
	    				yyval.node=new NODE();
	    				yyval.node->trueList.push_back(nextInst());
	    				instList[yyval.node->trueList.back()]="if("+yyvsp[-2].node->addr+" "+*yyvsp[-1].str+" "+yyvsp[0].node->addr+") goto";
	    				yyval.node->falseList.push_back(nextInst());
	    				instList[yyval.node->falseList.back()]="goto";
	    			}
break;
case 37:
#line 212 "threeaddr.y"
{yyval.node=new NODE();yyval.node->trueList.push_back(nextInst());instList[yyval.node->trueList.back()]="goto";}
break;
case 38:
#line 213 "threeaddr.y"
{yyval.node=new NODE();yyval.node->falseList.push_back(nextInst());instList[yyval.node->falseList.back()]="goto";}
break;
case 39:
#line 215 "threeaddr.y"
{yyval.node=new NODE();yyval.node=new NODE();yyval.node->instNum=instCounter;}
break;
case 40:
#line 216 "threeaddr.y"
{yyval.node=new NODE();yyval.node->nextList.push_back(nextInst());instList[yyval.node->nextList.back()]="goto";}
break;
case 41:
#line 218 "threeaddr.y"
{yyval.node=makeNode();instList[nextInst()]=yyval.node->addr+" = "+yyvsp[-2].node->addr+" + "+yyvsp[0].node->addr;}
break;
case 42:
#line 219 "threeaddr.y"
{yyval.node=makeNode();instList[nextInst()]=yyval.node->addr+" = "+yyvsp[-2].node->addr+" - "+yyvsp[0].node->addr;}
break;
case 43:
#line 220 "threeaddr.y"
{yyval.node=yyvsp[0].node;}
break;
case 44:
#line 221 "threeaddr.y"
{yyval.node=makeNode();instList[nextInst()]=yyval.node->addr+" = "+yyvsp[0].node->array+"["+yyvsp[0].node->addr+"]";}
break;
case 45:
#line 223 "threeaddr.y"
{yyval.node=makeNode();instList[nextInst()]=yyval.node->addr+" = "+yyvsp[-2].node->addr+" * "+yyvsp[0].node->addr;}
break;
case 46:
#line 224 "threeaddr.y"
{yyval.node=makeNode();instList[nextInst()]=yyval.node->addr+" = "+yyvsp[-2].node->addr+" / "+yyvsp[0].node->addr;}
break;
case 47:
#line 225 "threeaddr.y"
{yyval.node=yyvsp[0].node;}
break;
case 48:
#line 227 "threeaddr.y"
{yyval.node=makeNode();instList[nextInst()]=yyval.node->addr+" = "+yyvsp[-2].node->addr+" ^ "+yyvsp[0].node->addr;}
break;
case 49:
#line 228 "threeaddr.y"
{yyval.node=yyvsp[0].node;}
break;
case 50:
#line 230 "threeaddr.y"
{yyval.node=yyvsp[-1].node;}
break;
case 51:
#line 231 "threeaddr.y"
{
	 		if(table[blocks.back()].find(*yyvsp[0].str)==table[blocks.back()].end())
			{
				yyerror("variable not declared");
			}
			yyval.node=makeNode(yyvsp[0].str);
		}
break;
case 52:
#line 238 "threeaddr.y"
{
	 		yyval.node=makeNode();instList[nextInst()]=yyval.node->addr+" = "+yyvsp[0].node->array+"["+yyvsp[0].node->addr+"]";
	 	}
break;
case 53:
#line 241 "threeaddr.y"
{yyval.node=makeNode(yyvsp[0].str);}
break;
case 54:
#line 242 "threeaddr.y"
{yyval.node=makeNode();instList[nextInst()]=yyval.node->addr+" = - "+yyvsp[0].node->addr;}
break;
#line 1091 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
