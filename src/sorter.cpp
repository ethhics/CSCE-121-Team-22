#include "defs.h"

struct List{
	int place;
	string name;
	int score;
};

int main(){
	
ifstream ist{"highscore.txt"};
if(!ist)error("cant open");

vector<List>highscore;
	int place;
	string name;
	int score;

while(ist>>place>>name>>score){
	highscore.push_back(List{place,name,score});
}

ist.close();

int f;
string n;
cout<<"input highscore"<<endl;
cin>>f;
cout<<"input name"<<endl;
cin>>n;

if(f>highscore[4].score){
	highscore[4].score=f;
	highscore[4].name=n;

	if(f>highscore[3].score){
		highscore[4].score=highscore[3].score;
		highscore[3].score=f;
		highscore[4].name=highscore[3].name;
		highscore[3].name=n;
}
		if(f>highscore[2].score){
			highscore[3].score=highscore[2].score;
			highscore[2].score=f;
			highscore[3].name=highscore[2].name;
			highscore[2].name=n;
}
			if(f>highscore[1].score){
				highscore[2].score=highscore[1].score;
				highscore[1].score=f;
				highscore[2].name=highscore[1].name;
				highscore[1].name=n;
}
				if(f>highscore[0].score){
					highscore[1].score=highscore[0].score;
					highscore[0].score=f;
					highscore[1].name=highscore[0].name;
					highscore[0].name=n;
}
}
else{
	cout<<"did not make high score \n";
}


ofstream ost{"highscore.txt"};
ost.trunc;




	for(int i=0; i<highscore.size(); ++i)
		ost<<highscore[i].place<<'\t'<<highscore[i].name<<'\t'<<highscore[i].score<<'\n';
	

	
return 0;

}

