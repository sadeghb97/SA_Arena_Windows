#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string.h>
#include <string>
#include <limits.h>
#include <stdlib.h>
#include <ctime>
#include <windows.h>

using namespace std;

void beforeStrWhere(const char*,int);
void beforeStrWhere(stringstream &,int);
void strwhere(const char*,int,int);
void strwhere(const char*,int);
int sstreamLength(stringstream &);
void strwhere(stringstream &,int,int);
void strwhere(stringstream &,int);
void setConsoleColor(const char *);
void space(int);
void cadr_dash(int,bool noEndl=false);
void swap(int &,int &);
void swap(int [],int [],int n);
void colorStringPrint(string);
void ccsPrint(stringstream &);
int getColorNum(string);
void setColor(int,bool);
void setColor(int);
void setColor(const char *);
bool randYesNo();

class player;
class team;
class match;
class competition;
struct teamGameStat;
struct date;
class inputProfile;
class FileNames;

bool existFile(char*);
bool isDataFileAndReady(istream&);
bool isDataFile(char*);
bool isDataFile(const char*);
bool save(char*,team,team, match *,inputProfile);
bool save(const char*,team,team, match *,inputProfile);
bool saveAs(team,team, match *,inputProfile);
bool saveTxt(char*,team,team, match *,inputProfile);
bool saveTxt(const char*,team,team, match *,inputProfile);
bool load(team &, team &, match *,inputProfile&);
//bool load(const char*,team &, team &, match *);
bool loadTxt(char*,team &, team &, match *,inputProfile &);
bool loadTxt(const char*,team &, team &, match *,inputProfile &);
bool lostDataWarning(team,team,match *,inputProfile,bool showWarn=false);
bool exitApp(team,team,match *,inputProfile);
bool mainMenu(team&,team&,match *,inputProfile&,const char*);
bool enterTeams(team&,team&);
int generateNewPrId(team,team);
int choiceMatch(match *,team,team);
void externalShowAllPrs(const char *);
int getNumGames(match *);
void add_game(match *,team &,team &, inputProfile &);
void editGame(match *,team &,team &);
void showWALTable(teamGameStat, teamGameStat , bool, bool);
void print_passage(char *);
void details_repair(match *, team &,team &);
void silentDetailsRepair(match *, team &,team &);
void competition_stats(team ,team ,match []);
void subsume_players(team,team);
void show_game(match *,team,team);
void moratab(int[][3],int,int,int);
void newTermPlayers(team,team,match *);
void correctData(team &, team &, match *,inputProfile&);

int stringToInt(char []);
int nextInt();
bool printCheckChoice (int,int,int);
bool easycheck (int, int, int);
bool ukEasycheck (int, int, int,bool);
bool ukEasycheck (int, int, int);
int inputChoice(int,int);
bool sure();

void printError(const char*);
void sucPrint(const char*);
void rulePrint(const char*);
void blackPrint(const char*);
void typeWarning();
void typeRule();
void typeError();
void noBoldBlackPrint(const char*);
void boldGreenPrint(const char*);
void boldRedPrint(const char*);


char* DATA_FILE_NAME;
char* NULL_PATH_STRING;
char* EXE_APP_NAME;
bool IS_SAVED;


struct date{
	bool isEmpty;
	int year;
	int month;
	int day;
	
	date(){
		isEmpty=true;
	}
	date(int y, int m, int d){
		year=y;
		month=m;
		day=d;
		isEmpty=false;
	}
};


class inputProfile{
    bool numCards;
    bool date;
    bool stats;
    bool areas;
    bool players;
    bool overalls;
    bool goals;
    bool assists;
    bool goalsTimes;
    bool cards;
    bool cardsTimes;
    bool mom;
    bool conf;
    
    public:
    inputProfile(){
        date=true;
        stats=true;
        areas=true;
        players=true;
        overalls=true;
        goals=true;
        assists=true;
        goalsTimes=true;
        numCards=true;
        cards=true;
        cardsTimes=true;
        mom=true;
        conf=true;
    }
    
    bool getDate(){ return date;}
    bool getStats(){ return stats;}
    bool getAreas(){ return areas;}
    bool getPlayers(){ return players;}
    bool getOveralls(){ return overalls;}
    bool getGoals(){ return goals;}
    bool getAssists(){ return assists;}
    bool getGoalsTimes(){ return goalsTimes;}
    bool getNumCards(){ return numCards;}
    bool getCards(){ return cards;}
    bool getCardsTimes(){ return cardsTimes;}
    bool getMom(){ return mom;}
    bool getConf(){ return conf;}
    
    int getNumSettings(){ return 13;}
    
    void saveTxt(ostream &f1){
        f1<<numCards<<endl;
        f1<<date<<endl;
        f1<<stats<<endl;
        f1<<areas<<endl;
        f1<<players<<endl;
        f1<<overalls<<endl;
        f1<<goals<<endl;
        f1<<assists<<endl;
        f1<<goalsTimes<<endl;
        f1<<cards<<endl;
        f1<<cardsTimes<<endl;
        f1<<mom<<endl;
        f1<<conf<<endl;
    }
    
    void loadTxt(istream &f1){
        f1>>numCards;
        f1>>date;
        f1>>stats;
        f1>>areas;
        f1>>players;
        f1>>overalls;
        f1>>goals;
        f1>>assists;
        f1>>goalsTimes;
        f1>>cards;
        f1>>cardsTimes;
        f1>>mom;
        f1>>conf;
        f1.ignore();
    }
    
    void enableAll(){
        date=true;
        stats=true;
        areas=true;
        players=true;
        overalls=true;
        goals=true;
        assists=true;
        goalsTimes=true;
        numCards=true;
        cards=true;
        cardsTimes=true;
        mom=true;
        conf=true;
    }
    
    void disableAll(){
        date=false;
        stats=false;
        areas=false;
        players=false;
        overalls=false;
        goals=false;
        assists=false;
        goalsTimes=false;
        numCards=false;
        cards=false;
        cardsTimes=false;
        mom=false;
        conf=false;
    }
    
    void printSettings(){
        int num=0;
        cout<<++num<<": "; if(date) boldGreenPrint("Date\n"); else noBoldBlackPrint("Date (Disabled)\n");
        cout<<++num<<": "; if(stats) boldGreenPrint("Game Stats\n"); else noBoldBlackPrint("Game Stats (Disabled)\n");
        cout<<++num<<": "; if(areas) boldGreenPrint("Attacking Areas\n"); else noBoldBlackPrint("Attacking Areas (Disabled)\n");
        cout<<++num<<": "; if(players) boldGreenPrint("Teams Line Ups\n"); else noBoldBlackPrint("Teams Line Ups (Disabled)\n");
        cout<<++num<<": "; if(overalls) boldGreenPrint("Players Overall Ratings\n"); else noBoldBlackPrint("Players Overall Ratings (Disabled)\n");
        cout<<++num<<": "; if(goals) boldGreenPrint("Goals Scorers\n"); else noBoldBlackPrint("Goals Scorers (Disabled)\n");
        cout<<"----"<<++num<<": "; if(assists) boldGreenPrint("Assists\n"); else noBoldBlackPrint("Assists (Disabled)\n");
        cout<<"----"<<++num<<": "; if(goalsTimes) boldGreenPrint("Goals Time\n"); else noBoldBlackPrint("Goals Time (Disabled)\n");
        cout<<++num<<": "; if(numCards) boldGreenPrint("Number Of Cards\n"); else noBoldBlackPrint("Number Of Cards (Disabled)\n");
        cout<<++num<<": "; if(cards) boldGreenPrint("Cards Details\n"); else noBoldBlackPrint("Cards Details (Disabled)\n");
        cout<<"----"<<++num<<": "; if(cardsTimes) boldGreenPrint("Cards Time\n"); else noBoldBlackPrint("Cards Time (Disabled)\n");
        cout<<++num<<": "; if(mom) boldGreenPrint("Man Of The Match\n"); else noBoldBlackPrint("Man Of The Match (Disabled)\n");
        cout<<++num<<": "; if(conf) boldGreenPrint("Conference\n"); else noBoldBlackPrint("Conference (Disabled)\n");
    }
    
    void settings(){
        int n=getNumSettings();
        int choice;
        cout<<endl;
        boldRedPrint("Game Input Settings Session:\n");
        typeRule(); cout<<"Enter 1 To "<<n<<" For Toggle\n";
        typeRule(); cout<<"Enter "<<n+1<<" For Enable All\n";
        typeRule(); cout<<"Enter "<<n+2<<" For Disable All\n";
        typeRule(); cout<<"Enter "<<n+3<<" For Quit\n";
        while(true){
            cout<<endl;
            boldRedPrint("Game Input Settings:\n");
            printSettings();
            cout<<endl<<"Enter Your Choice: ";
            choice=inputChoice(1,n+3);
            switch(choice){
                case 1: date=!date; break;
                case 2: stats=!stats; break;
                case 3: areas=!areas; break;
                case 4: players=!players; break;
                case 5: overalls=!overalls; break;
                case 6: goals=!goals; break;
                case 7: assists=!assists; break;
                case 8: goalsTimes=!goalsTimes; break;
                case 9: numCards=!numCards; break;
                case 10: cards=!cards; break;
                case 11: cardsTimes=!cardsTimes; break;
                case 12: mom=!mom; break;
                case 13: conf=!conf; break;
                case 14: enableAll(); break;
                case 15: disableAll(); break;
            }
            if(choice==n+3) break;
        }
    }
};


class FileNames{
    int length;
    string fn[300];
    
	public:
    
    FileNames(){
        length=0;
    }
    
    void delOlds(){
        if(length<=200) return;
        int step=length-200;
        for(int i=0; 200>i; i++){
            fn[i]=fn[i+step];
        }
        length=200;
    }
    
    bool choiceMenu(char* inputFN){
        int printIndex=0;
        int choice;
        string isfd[300];
        
        start:
        cout<<endl;
        setColor("BOLDBLUE");
        cout<<"Load:\n";
        setColor("RESET");
        for(int i=0; length>i; i++){
            char tempFN[256];
            strcpy(tempFN,fn[i].c_str());
            if(isDataFile(tempFN)){
                isfd[printIndex]=fn[i];
                setColor("BOLDBLUE");
                cout<<++printIndex<<": ";
                setColor("RESET");
                cout<<fn[i]<<endl;
            }
        }
        
        setColor("BOLDBLUE");
        cout<<printIndex+1<<": ";
        setColor("RESET");
        cout<<"Enter Another File Name\n";
        setColor("BOLDBLUE");
        cout<<printIndex+2<<": ";
        setColor("RESET");
        cout<<"Cancel\n";
        cout<<endl<<"Enter Your Choice: ";
        choice=inputChoice(1,printIndex+2);
        
        if(choice<=printIndex){
            strncpy(inputFN,isfd[choice-1].c_str(),256);
            append(inputFN);
            return true;
        }
        else if(choice==printIndex+1){
            userinput:
            char userFN[256];
            cout<<endl<<"Enter File Name: ";
            cin.getline(userFN,256);
            if(isDataFile(userFN)){
                string str(userFN);
                append(str);
                strncpy(inputFN,userFN,256);
                return true;
            }
            else{
                cout<<endl;
                if(existFile(userFN)) printError("Invalid File!\n");
                else printError("File Not Found!\n");
                cout<<endl;
                setColor("BOLDRED");
                cout<<"Next Work?\n";
                setColor("RESET");
                cout<<"1: Try Again\n";
                cout<<"2: Go to File Names Menu\n";
                cout<<"3: Cancel\n";
                cout<<endl;
                cout<<"Enter Your Choice: ";
                int choice=inputChoice(1,3);
                if(choice==1) goto userinput;
                else if(choice==2) goto start;
                else return false;
            }
        }
        
        else if(choice==printIndex+2) return false;
        
        throw -1;
    }
    
    void append(string str){
        if(length==299) delOlds();
        int index;
        for(index=0; length>index && fn[index].compare(str)!=0; index++);
        if(index<length){
            for(int i=index; i>0; i--){
                fn[i]=fn[i-1];
            }
            fn[0]=str;
        }
        else{
            fn[index]=str;
            length++;
        }
        save();
    }
    
    void save(){
        fstream f1("configs.bin" , ios::out | ios::binary);
        f1.write(reinterpret_cast<char *>(&length), sizeof(length));
        for(int i=0; length>i; i++){
            int size = (fn[i].size());
            f1.write(reinterpret_cast<char *>(&size), sizeof(int));
            f1.write(fn[i].c_str(), size);
	}
        f1.close();
    }
    
    void load(){
        fstream f1("configs.bin" , ios::in | ios::binary);
        if(f1){
            f1.read(reinterpret_cast<char *>(&length), sizeof(length));
            for(int i=0; length>i; i++){
                int size;
                char *buf;
                f1.read(reinterpret_cast<char *>(&size), sizeof(int));
                buf = new char[size];
                f1.read(buf, size);
                fn[i] = "";
                fn[i].append(buf, size);
            }
            f1.close();
        }
    }
};


class player{
	bool exist;
	char name[30];
	int id;
    int number;
    int overallRating;
	int post;
	int apps;
	int goals;
	int assists;
	int hatTricks;
	int mom;
	int rc;
	int yc;
	char temp[10];
	public:
	player(){
        overallRating=0;
        exist=0; apps=0; goals=0; assists=0;
        hatTricks=0;
        mom=0; rc=0; yc=0; id=0;
	}
        
    player(player* pr){
		exist=pr->sendexist();
		strcpy(name,pr->sendname());
		id=pr->getId();
		number=pr->getNumber();
        post=pr->getPost(); 
		
        overallRating=pr->overallRating;
		apps=pr->sendapps();
		goals=pr->sendgoals();
		assists=pr->sendass();
		hatTricks=pr->getHatTricks();
		mom=pr->sendmom();
		rc=pr->sendrc();
		yc=pr->sendyc(); 
	}
	
	void input(char *str,int n,int num,int idInput){
		if(easycheck(n,1,5)==0) throw -1;
		if(strcasecmp(str,"")==0) throw -1;
		strcpy(name,str);
		post=n;
        number=num;
        id=idInput;
        exist=1;
        overallRating=-2;
	}
        
	void edit(char *str,int n){
		if(easycheck(n,1,5)==0) throw -1;
		if(strcasecmp(str,"")==0) throw -1;
		strcpy(name,str);
		post=n;
        exist=1;
	}
        
    player clone(){
        return player(this);
    }
        
    void remove(){
        exist=0; name[0]=0; post=0;
        overallRating=0;
        apps=0; goals=0; assists=0;
        hatTricks=0;
        mom=0; rc=0; yc=0; id=0;
    }
	
	void zero(void){
        overallRating=-2;
        apps=0; goals=0; assists=0; mom=0; rc=0; yc=0;
	}
	
	void saveTxt(ostream &f1){
		f1<<exist<<endl;
		f1<<name<<endl;
		f1<<id<<endl;
        f1<<overallRating<<endl;
        f1<<number<<endl;
		f1<<post<<endl;
		f1<<apps<<endl;
		f1<<goals<<endl;
		f1<<assists<<endl;
		f1<<hatTricks<<endl;
		f1<<mom<<endl;
		f1<<rc<<endl;
		f1<<yc<<endl;
	}
	
	void loadTxt(istream &f1){
		f1>>exist;
		f1.ignore();
		f1.getline(name,30);
		f1>>id;
        f1>>overallRating;
        f1>>number;
		f1>>post;
		f1>>apps;
		f1>>goals;
		f1>>assists;
		f1>>hatTricks;
		f1>>mom;
		f1>>rc;
		f1>>yc;
		f1.ignore();
	}
        
    void setNumber(int n){
        number=n;
    }
	
	bool sendexist(void){ return exist;}
    int getOverallRating(){ return overallRating;}
	int sendgoals(void){ return goals;}
	int sendapps(void){ return apps;}
	int sendass(void){ return assists;}
	int sendmom(void){ return mom;}
	int sendrc(void){ return rc;}
	int sendyc(void){ return yc;}
    int getId(void){ return id;}
    int getNumber(){ return number;}
    int getPost(void){ return post;}
	int getHatTricks(){ return hatTricks;}
	char* sendname(void){ return name;}
	void change_id(int t){ id=t;}
	void app_p(void){ apps++;}
	void goal_p(void){ goals++;}
	void ass_p(void){ assists++;}
	void momPlus(){ mom+=2;}
    void secondMomPlus(){ mom++;}
	void rc_p(void){ rc++;}
	void yc_p(void){ yc++;}
	void hatTrikPlus(int p){
		if(p<1) throw -1;
		hatTricks+=p;
	}
	
    void setOverall(int ov){
        if(!ukEasycheck(ov,1,109)) throw -1; 
        overallRating=ov;
    }
    
    int dynamicGet(const char* index){
		if(strcasecmp(index,"number")==0) return number;
		else if (strcasecmp(index,"post")==0) return post;
		else if (strcasecmp(index,"overallRating")==0) return overallRating;
		else throw -1;
	}
        
    static void printPost(int post){
        if(post<1 || post>5) throw -1;
        switch(post){
            case 1: setColor("BOLDBLACK"); cout<<"GoalKeaper"; break;
            case 2: setColor("BOLDCYAN"); cout<<"Defender"; break;
            case 3: setColor("BOLDGREEN"); cout<<"Central Midfielder"; break;
            case 4: setColor("BOLDGREEN"); cout<<"Attacking Midfielder"; break;
            case 5: setColor("BOLDRED"); cout<<"Forward"; break;
        }
        setColor("RESET");
    }
        
	static void printOverallRating(int ov){
	    if(!ukEasycheck(ov,1,109)) throw -1;
	    if(ov==-2){
			cout<<"UK";
			return;
	    }
	    if(ov>74 && ov<80) setColor("GREEN");
	    else if(ov<85) setColor("YELLOW");
	    else if(ov<90) setColor("BOLDYELLOW");
	    else if(ov>=90) setColor("BOLDRED");
	    cout<<ov;
	    setColor("RESET");
	}
	
	static string getOverallString(double ov){
		stringstream temp;
		string ss;
	    if(ov==-2){
			ss="UK";
			return ss;
	    }
	    if(ov<75) temp<<"$$BLK"; 
	    else if(ov<80) temp<<"$0GRN";
	    else if(ov<85) temp<<"$0YEL";
	    else if(ov<90) temp<<"$$YEL";
	    else if(ov>=90) temp<<"$$RED";
		temp<<setprecision(3)<<ov;
		temp<<"$0RST";
		ss=temp.str();
		return ss;
	}
        
	void show(void){
        if(exist==1){
            cout<<endl <<"Name: " <<name <<endl;
            cout<<"Number: " <<number<<endl;
            cout<<"ID: " <<id<<endl;
            cout<<"Post: "; printPost(post); cout<<endl;
            cout<<"Overall Rating: "; cout<<"("; printOverallRating(overallRating); cout<<")"; cout<<endl;
            cout<<"Tedade Bazi: " <<apps <<endl;
            cout<<"Goals: " <<goals <<endl;
            cout<<"Assists: " <<assists <<endl;
            cout<<"Hat Tricks: " <<hatTricks <<endl;
            cout<<"Man Of The Match: " <<mom <<endl;
            cout<<"Yellow Card: " <<yc <<endl;
            cout<<"Red Card: " <<rc <<endl;
        }
        else if(exist==0) cout<< "This player does not exist !"<<endl;
	}
        
    void namePostShow(){
        if(number>0){
            setColor("BOLDMAGENTA");
            cout<<number;
            setColor("RESET");
            cout<<" | ";
        }
        setColor("BOLDBLUE");
        cout<<name;
        setColor("RESET");
        cout<<" | ";
        printPost(post);
		if(overallRating!=-2){
			cout<<" | ";
			printOverallRating(overallRating);
		}
    }
    
	friend class team;
	friend class match;
};


class team{
	static int count;
	bool exist;
	char temp[10];
	char name[30];
	int id;
	int apps;
	int goals;
	int rc;
	int yc;
	int wins;
	int lose;
	int draw;
	int possess;
	int shots[2];
	int fouls[2];
	int corners;
	int fk;
	int pass_c;
	int cross;
	int interc;
	int tackles;
	int saves;
	
	public:
	player pr[200];
	
	team(){
		exist=0; id=0; apps=0; goals=0; rc=0; yc=0; wins=0; lose=0; draw=0;
		possess=0; corners=0; fk=0; pass_c=0; cross=0; interc=0; tackles=0; saves=0;
		for(int i=0; 2>i; i++){
			shots[i]=0;
			fouls[i]=0;
		}
	}
       
        
	int getNumPrs(){
		int num;
		for(num=0; pr[num].sendexist(); num++);
		return num;
	}

        
	bool input(void){
		int choice;
		choice=0;
		input:
		if(choice==2) cout<<endl;
		cout<<"Enter name: ";
		cin.getline(name,30);
                
		do{
			cout<<"Enter ID (1 Or 2): ";
			id=nextInt();
		}while(!printCheckChoice(id,1,2));
            
		setColor("BOLDBLUE");
		cout<<"\nName: "<<name<<" | ID: "<<id<<endl;
		setColor("RESET");
		cout<<endl<<"Do you want to edit? (1:No | 2:Yes | 3:Cancel Entering Team)\n";
		choice=inputChoice(1,3);
		if(choice==2) goto input;
		if(choice==3) return false;
		exist=1;
		return true;
	}
            
	void zero(void){
		apps=0; goals=0; rc=0; yc=0; wins=0; lose=0; draw=0;
		possess=0; corners=0; fk=0; pass_c=0; cross=0; interc=0; tackles=0; saves=0;
		for(int i=0; 2>i; i++){
			shots[i]=0;
			fouls[i]=0;
		}
	}
        
	int generateRandomNumber(int post){
		if(post<1 || post>5) throw -1;
		int gk[]={1,12,23,31,51,0};
		int cb[]={2,3,4,5,21,25,29,30,33,0};
		int cmf[10]={6,16,26,24,22,28,0};
		int amf[10]={7,8,17,27,13,18,32,0};
		int cf[10]={9,10,11,19,20,14,15,0};
		bool used[201];
		for(int i=1; 201>i; i++) used[i]=false;
		int tp;
		tp=getNumPrs();
		for(int i=0; tp>i; i++) used[getPrFromIndex(i).getNumber()]=true;
		int *nums;
		switch(post){
			case 1: nums=gk; break;
			case 2: nums=cb; break;
			case 3: nums=cmf; break;
			case 4: nums=amf; break;
			case 5: nums=cf; break;
		}
            
		bool empty=false;
		for(int i=0; nums[i]!=0; i++){
			if(!used[nums[i]]){
				empty=true;
				if(randYesNo()) return nums[i];
			}
			if(nums[i+1]==0 && empty) i=-1;
		}
            
		empty=false;
		for(int i=34; 201>i; i++){
			if(!used[i]){
				empty=true;
				if(randYesNo()) return i;
			}
			if(i+1==201 && empty) i=0;
		}
		throw -1;
	}
	
	void saveTxt(ostream &f1){
		f1<<exist<<endl;
		f1<<name<<endl;
		f1<<id<<endl;
		f1<<apps<<endl;
		f1<<goals<<endl;
		f1<<rc<<endl;
		f1<<yc<<endl;
		f1<<wins<<endl;
		f1<<lose<<endl;
		f1<<draw<<endl;
		f1<<possess<<endl;
		f1<<shots[0]<<endl;
		f1<<shots[1]<<endl;
		f1<<fouls[0]<<endl;
		f1<<fouls[1]<<endl;
		f1<<corners<<endl;
		f1<<fk<<endl;
		f1<<pass_c<<endl;
		f1<<cross<<endl;
		f1<<interc<<endl;
		f1<<tackles<<endl;
		f1<<saves<<endl;
		int t;
		for(t=0; pr[t].sendexist(); t++);
		f1<<t<<endl;
		for(int i=0; t>i; i++) pr[i].saveTxt(f1);
	}
	
	void loadTxt(istream &f1){
		f1>>exist;
		f1.ignore();
		f1.getline(name,30);
		f1>>id;
		f1>>apps;
		f1>>goals;
		f1>>rc;
		f1>>yc;
		f1>>wins;
		f1>>lose;
		f1>>draw;
		f1>>possess;
		f1>>shots[0];
		f1>>shots[1];
		f1>>fouls[0];
		f1>>fouls[1];
		f1>>corners;
		f1>>fk;
		f1>>pass_c;
		f1>>cross;
		f1>>interc;
		f1>>tackles;
		f1>>saves;
		int t;
		f1>>t;
		f1.ignore();
		for(int i=0; t>i; i++) pr[i].loadTxt(f1);
	}
	
	int getWins(){ return wins;}
	bool sendexist(void){ return exist;}
	int sendid(void){ return id;}
	void app_p(void){ apps++;}
	void goal_p(void){ goals++;}
	void rc_p(void){ rc++;}
	void yc_p(void){ yc++;}
	void win_p(void){ wins++;}
	void lose_p(void){ lose++;}
	void draw_p(void){ draw++;}
	void possess_p(int a){ possess+=a;}
	void shots0_p(int a){ shots[0]+=a;}
	void fouls0_p(int a){ fouls[0]+=a;}
	void shots1_p(int a){ shots[1]+=a;}
	void fouls1_p(int a){ fouls[1]+=a;}
	void corners_p(int a){ corners+=a;}
	void fk_p(int a){ fk+=a;}
	void pass_c_p(int a){ pass_c+=a;}
	void cross_p(int a){ cross+=a;}
	void interc_p(int a){ interc+=a;}
	void tackles_p(int a){ tackles+=a;}
	void saves_p(int a){ saves+=a;}
	char* getName(){return name;}
	void printname(void){ cout<<name;}
	
	void show(void){
		setColor("BOLDRED");
		cout<<"\nName: "<<name;
		setColor("RESET");
		cout<<endl;
		cout<<"ID: "<<id<<endl;
		if(apps==0) cout<<"\nIn team hanuz mosabeghat ra shoru nakarde ast.\n";
		else{
			cout<<"Apps: "<<apps<<endl;
			cout<<"Wins: "<<wins<<endl;
			cout<<"Draws: "<<draw<<endl;
			cout<<"Loses: "<<lose<<endl;
			cout<<"Wins Percent: "<<(double)wins/apps*100<<"%"<<endl;
			cout<<"Goals: "<<goals<<endl;
			cout<<"Goals Per Game: "<<(double)goals/apps<<endl;
			cout<<"Yellow Cards: "<<yc<<endl;
			cout<<"Yellow Cards Per Game: "<<(double)yc/apps<<endl;
			cout<<"Red Cards: "<<rc<<endl;
			cout<<"Red Cards Per Game: "<<(double)rc/apps<<endl;
			cout<<"Possession Per Game: "<<(double)possess/apps<<endl;
			cout<<"Shots(On Target): "<<shots[0]<<"("<<shots[1]<<")"<<endl;
			cout<<"Shots(On Target) Per Game: "<<(double)shots[0]/apps<<"("<<(double)shots[1]/apps<<")"<<endl;
			cout<<"Fouls(Offside): "<<fouls[0]<<"("<<fouls[1]<<")"<<endl;
			cout<<"Fouls(Offside) Per Game: "<<(double)fouls[0]/apps<<"("<<(double)fouls[1]/apps<<")"<<endl;
			cout<<"Corners: "<<corners<<endl;
			cout<<"Corners Per Game: "<<(double)corners/apps<<endl;
			cout<<"Free Kicks: "<<fk<<endl;
			cout<<"Free Kicks Per Game: "<<(double)fk/apps<<endl;
			cout<<"Pass Completed Per Game: "<<(double)pass_c/apps<<endl;
			cout<<"Crosses: "<<cross<<endl;
			cout<<"Crosses Per Game: "<<(double)cross/apps<<endl;
			cout<<"Interception: "<<interc<<endl;
			cout<<"Interception Per Game: "<<(double)interc/apps<<endl;
			cout<<"Tackles: "<<tackles<<endl;
			cout<<"Tackles Per Game: "<<(double)tackles/apps<<endl;
			cout<<"Saves: "<<saves<<endl;
			cout<<"Saves Per Game: "<<(double)saves/apps<<endl;
			
		}
	}
	
    void sortPrs(const char* sortBy, bool moreToFewer=false){
		for(int i=0; getPrFromIndex(i).sendexist(); i++){
			int first=getPrFromIndex(i).dynamicGet(sortBy);
			int newIndex=-1;
			for(int j=i+1; getPrFromIndex(j).sendexist(); j++){
				if((moreToFewer && getPrFromIndex(j).dynamicGet(sortBy)>first)	
				|| (!moreToFewer && getPrFromIndex(j).dynamicGet(sortBy)<first)){
					newIndex=j;
					first=getPrFromIndex(j).dynamicGet(sortBy);
				}
			}
			
			if(newIndex!=-1){
				player temp=getPrFromIndex(i).clone();
				pr[i]=getPrFromIndex(newIndex).clone();
				pr[newIndex]=temp;
			}
		}	
	}
	
	static void sortPrs(player *argPrs,const char* sortBy, bool moreToFewer=false){
		for(int i=0; argPrs[i].sendexist(); i++){
			int first=argPrs[i].dynamicGet(sortBy);
			int newIndex=-1;
			for(int j=i+1; argPrs[j].sendexist(); j++){
				if((moreToFewer && argPrs[j].dynamicGet(sortBy)>first)	
				|| (!moreToFewer && argPrs[j].dynamicGet(sortBy)<first)){
					newIndex=j;
					first=argPrs[j].dynamicGet(sortBy);
				}
			}
			
			if(newIndex!=-1){
				player temp=argPrs[i].clone();
				argPrs[i]=argPrs[newIndex].clone();
				argPrs[newIndex]=temp;
			}
		}	
	}
	
	void printPlayersNumbersTable(){
		int s,t,lineNum,maxLength;
		stringstream cadr;
		stringstream prColor;
		player tmpPrs[200];
		for(int i=0; 200>i; i++) tmpPrs[i]=pr[i].clone();
		
		s=3;
		t=20;
		lineNum=3;
		maxLength=2+(lineNum*t);
		cadr<<"$$BLU";
		prColor<<"$0MAG";
		
		cout<<endl;
		sortPrs(tmpPrs,"number");
		
		space(s); ccsPrint(cadr); cadr_dash(maxLength); setColor("RESET");
		for(int i=0; tmpPrs[i].sendexist(); i+=lineNum){
			space(s); ccsPrint(cadr); cout<<"|"; ccsPrint(prColor);
			int j;
			for(j=i; j-i<lineNum && tmpPrs[j].sendexist(); j++){
				stringstream prNow;
				prNow<<tmpPrs[j].getNumber()<<": "<<tmpPrs[j].sendname();
				strwhere(prNow,t,1);
			}
			if(j-i!=lineNum){
				for(int k=0; lineNum-(j-i)>k; k++) space(t);
			}
			ccsPrint(cadr); cout<<"|"<<endl;
		}
		space(s); ccsPrint(cadr); cadr_dash(maxLength); setColor("RESET");
	}
	
	void showSqadList(void){
		if(pr[0].sendexist()==0) cout<<"\nThis team till now have not any players\n";
		else{
			while(true){
				setColor("BOLDGREEN");
				cout<<"\nSquad List:\n";
				setColor("RESET");
				for(int i=0; pr[i].exist!=0; i++){
					pr[i].namePostShow();
					cout<<endl;
				}
				
				int num=0;
				cout<<endl;
				setColor("BOLDRED");
				cout<<"Next Work?"<<endl;
				setColor("RESET");
				cout<<++num<<": Show a Player Details\n";
				cout<<++num<<": Sort by Numbers\n";
				cout<<++num<<": Sort by Posts\n";
				cout<<++num<<": Sort by Overall Ratings\n";
				cout<<++num<<": Back To Team Menu\n";
				cout<<"Enter Your Choice: ";
				int choice=inputChoice(1,num);
				if(choice==1){
					show_a_player:
					int ind;
					cout<<endl<<"Enter Player Club Number: ";
					ind=nextInt();
					
					try{
						getPrFromNumber(ind).show();
					}
					catch(int ex){
						cout<<endl<<"There is no Player with this Number!"<<endl;
					}
					
					cout<<endl;
					setColor("BOLDRED");
					cout<<"Next Work?"<<endl;
					setColor("RESET");
					cout<<"1: Show Squad List\n2: Show another Player Details\n3: Back To Team Menu\n";
					cout<<"Enter Your Choice: ";
					int choice=inputChoice(1,3);
					if(choice==2) goto show_a_player;
					else if(choice==3) return;
				}
				else if(choice==2) sortPrs("number");
				else if(choice==3) sortPrs("post");
				else if(choice==4) sortPrs("overallRating",true);
				else if(choice==5) return;
			}
		}
	}
	
	void show_det_prs(void){
		if(pr[0].sendexist()==0) cout<<"\nThis team till now have not any players\n";
		else{
			setColor("BOLDGREEN");
            cout<<"\nDetailed Players List:\n";
            setColor("RESET");
			for(int i=0; pr[i].exist!=0; i++){	
				setColor("BOLDGREEN");
                cout<<endl<<"Player "<<i+1<<":  ";
                setColor("RESET");
				pr[i].show();
			}
		}
	}
        
    player& getPrFromIndex(int index){
        return pr[index];
    }
        
    player& getPrFromId(int id){
        for(int i=0; pr[i].sendexist(); i++){
            if(pr[i].getId()==id) return pr[i]; 
        }
        throw -1;
    }
        
    player& getPrFromNumber(int number){
        for(int i=0; pr[i].sendexist(); i++){
            if(pr[i].getNumber()==number) return pr[i]; 
        }
        throw -1;
    }
        
    int getPrIdFromNumber(int number){
        return getPrFromNumber(number).getId();
    }
        
    int getPrIndexFromNumber(int number){
        for(int i=0; pr[i].sendexist(); i++){
            if(pr[i].getNumber()==number) return i; 
        }
        throw -1;
    }
    
    int getPrIndexFromId(int Id){
        for(int i=0; pr[i].sendexist(); i++){
            if(pr[i].getId()==Id) return i; 
        }
        throw -1;
    }
	
	int getPlayerID(char *str){
		for(int i=0; pr[i].sendexist(); i++){
			if(strcasecmp(pr[i].sendname(), str)==0) return i;
		}
		return -1;
	}
       
	bool existNumber(int number){
		for(int i=0; pr[i].sendexist(); i++){
			if(pr[i].getNumber()==number) return true; 
		}
		return false;
	}
        
	bool prAllowDelete(int index){
		if(!pr[index].sendexist()) throw -1;
		return pr[index].sendapps()<=0;
	}
        
    void inputPrDetails(char nameVar[],int& post,int index){
        input:
        cout<<"\nPlayer "<<index+1 <<":\n";
		cout<<"Enter Name: ";
		cin.getline(nameVar,30);
		if(getPlayerID(nameVar)!=-1){
            printError("This Player has already bean Added\n");
			cout<<"\nTry Again? (1:Yes | 2:No)\n";
            int choice=inputChoice(1,2);
            if(choice==1) goto input;
			else return;
		}
        cout<<"Enter Post (1-5): ";
        post=inputChoice(1,5);
    }
	
	void add_prs(team other){
		int choice,i,post;
		char nameVar[30];
		do{
			for(i=0; pr[i].sendexist()!=0; i++);
			if(i>=200){
				cout<<"\nError!!! Full Capacity\n"; 
				break;
			}
                        
            input:
			inputPrDetails(nameVar,post,i);
                        
            setColor("BOLDBLUE");
            cout<<endl<<"Name: "<<nameVar<<" | Post: ";
            player::printPost(post);
            cout<<endl;
                        
            setColor("BOLDRED");
            cout<<endl<<"Next Work?\n";
            setColor("RESET");
            cout<<"1: Enter Another Player\n2: Edit\n3: Refuse Last Entry And Back\n4: Apply And Back To Recent Menu\n\n";
            cout<<"Enter Your Choice: ";
            choice=inputChoice(1,4);
            if(choice==2) goto input;
            if(choice==3) return;
			pr[i].input(nameVar,post,generateRandomNumber(post),generateNewPrId(*this,other));
            IS_SAVED=false;
		} while(choice==1);
	}
	
	void editPrNumbers(){
		int index,otherIndex;
		printPlayersNumbersTable();
		cout<<endl;
        typeRule();
        cout<<"For Edit Number Of a player: \n";
        cout<<"Enter Player Number | New Player Number | And Then Apply\n";
        typeRule();
        cout<<"Enter 0 for End of Editing Numbers\n";
        while(true){
            wh:
            int one,two;
            cout<<endl;
            cout<<"Enter Player Number or Zero to Quit: ";
            one=nextInt();
			if(one==0) return;
			if(one<0 || one>200){
				cout<<endl;
				typeError();
				cout<<"Invalid Number! Try again.\n";
				goto wh;
			}
			if(!existNumber(one)){
				cout<<endl;
				typeError();
				cout<<"There is No Player With This Number! Try again.\n";
				goto wh;
			}
			else index=getPrIndexFromNumber(one);
			
			cout<<"Enter New Player Number: ";
			two=nextInt();
			if(two<0 || two>200){
				cout<<endl;
				typeError();
				cout<<"Invalid Player Number! Try again.\n";
				goto wh;
			}
			
			otherIndex=-1;
            if(existNumber(two)){
                otherIndex=getPrIndexFromNumber(two);
                setColor("BOLDBLUE");
                cout<<pr[index].sendname()<<" ("<<pr[index].getNumber()<<" -> <- "<<pr[otherIndex].getNumber()<<") "<<pr[otherIndex].sendname();
                setColor("RESET");
                cout<<endl;
            }
            else{
                setColor("BOLDBLUE");
                cout<<pr[index].sendname()<<" ("<<pr[index].getNumber()<<" -> "<<two<<")"<<endl;
                setColor("RESET");
            }
            
            cout<<"Do You Apply (1:Yes | 2:No): ";
			if(inputChoice(1,2)==2) goto wh;

            pr[index].setNumber(two);
            if(otherIndex>=0) pr[otherIndex].setNumber(one);
            char temp[70];
            sprintf(temp,"%s Number Changed From %d to %d\n",pr[index].sendname(),one,two);
            sucPrint(temp);
            IS_SAVED=false;
            cout<<endl;
            printPlayersNumbersTable();
		}
	}
        
    void editPrs(team other){
        int inpNumber;
        int choice;
        start:
        if(getNumPrs()==0){
            cout<<"\nThere is No Player to Edit\n";
            return;
        }
        
        cout<<endl<<"Enter the Number of the Player that you want to Edit: ";
        inpNumber=nextInt();
        while(!existNumber(inpNumber)){
            cout<<endl;
            if(inpNumber>INT_MAX-2) printError("Invalid Id Input!\n");
            else printError("There is No Player With This Number\n");
            cout<<endl<<"Next Work? (1:Try Again | 2: Cancel Editing): ";
            choice=inputChoice(1,2);
            if(choice==2) return;
            cout<<endl<<"Enter the Number of the Player that you want to Edit: ";
            inpNumber=nextInt();
        }
        int index=getPrIndexFromNumber(inpNumber);
            
            
        cout<<endl;
        pr[index].namePostShow();
        cout<<endl;
            
        int preCh=2;
        int aftCh=2;
        int canDel=0;
        int tch;
        cout<<endl;
        setColor("BOLDRED");
        cout<<"Next Work?\n";
        setColor("RESET");
        cout<<"1: Edit This Player\n";
        cout<<"2: Change Number\n";
        if(prAllowDelete(index)){
            canDel=1;
        }
            
        if(canDel) cout<<preCh+1<<": Delete This Player\n";
        cout<<preCh+2-(canDel==0)<<": Edit Another Player\n";
        cout<<preCh+3-(canDel==0)<<": Cancel And Back to Recent Menu\n";
            
        tch=preCh+aftCh+canDel;
        cout<<"\nEnter Your Choice: ";
        choice=inputChoice(1,tch);
        if(choice==tch) return;
        if(choice==tch-1) goto start;
        else if(choice==1){
			char nameVar[30];
            int post;
            input:
			inputPrDetails(nameVar,post,index);
            cout<<endl;      
            setColor("BOLDBLUE");
            cout<<endl<<"Name: "<<nameVar<<" | Post: ";
            player::printPost(post);
            cout<<endl;
            sucPrint("The Player Edited Successfully\n");
                        
            cout<<endl;
            setColor("BOLDRED");
            cout<<"Next Work?\n";
            setColor("RESET");
            cout<<"1: Edit Another Player\n";
            cout<<"2: Edit Again\n";
            cout<<"3: Back\n";
            cout<<"4: Cancel This Edit\n";
            cout<<endl<<"Enter Your Choice: ";
            choice=inputChoice(1,4);
            if(choice==2) goto input;
            if(choice==4){
                cout<<endl;
                sucPrint("Changes Of This Player Ignored!\n");
                return;
            }
            pr[index].edit(nameVar,post);
            IS_SAVED=false;
            if(choice==1){
                goto start;
            }
            return;
		}
            
        else if(choice==2){
            changenumber:
            int newNum;
            int otherIndex=-1;
            cout<<endl<<"Enter new Number: ";
            newNum=inputChoice(1,200);
            if(existNumber(newNum)){
                otherIndex=getPrIndexFromNumber(newNum);
                cout<<endl;
                setColor("BOLDBLUE");
                cout<<pr[index].sendname()<<" ("<<pr[index].getNumber()<<" -> <- "<<pr[otherIndex].getNumber()<<") "<<pr[otherIndex].sendname();
                setColor("RESET");
                cout<<endl;
            }
            else{
                cout<<endl;
                setColor("BOLDBLUE");
                cout<<pr[index].sendname()<<" ("<<pr[index].getNumber()<<" -> "<<newNum<<")"<<endl;
                setColor("RESET");
            }
            cout<<endl;
            setColor("BOLDRED");
            cout<<"Are you sure?\n";
            setColor("RESET");
            cout<<"1: Yes\n";
            cout<<"2: Enter New Number\n";
            cout<<"3: Edit Another Player\n";
            cout<<"4: Cancel the Change And Back\n";
            cout<<"\nEnter Your Choice: ";
            int choice=inputChoice(1,4);
            if(choice==2) goto changenumber;
            else if(choice==3){
                IS_SAVED=false;
                goto start;
            }
            else if(choice==4) return;
            else if(choice==1){
                int oldNumber=pr[index].getNumber();
                pr[index].setNumber(newNum);
                if(otherIndex>=0) pr[otherIndex].setNumber(oldNumber);
                cout<<endl;
                char temp[70];
                sprintf(temp,"%s Number Changed From %d to %d\n",pr[index].sendname(),oldNumber,newNum);
                sucPrint(temp);
                IS_SAVED=false;
                            
                cout<<endl;
                setColor("BOLDRED");
                cout<<"Next Work?\n";
                setColor("RESET");
                cout<<"1: Edit Another Player\n";
                cout<<"2: Back\n";
                choice=inputChoice(1,2);
                if(choice==1) goto start;
                if(choice==2) return;
            }
        }
            
        else if(canDel && choice==(preCh+1)){
            cout<<endl<<"Are You Sure? (1:Yes 2:No): ";
            choice=inputChoice(1,2);
            if(choice==1){
                int i;
                char printName[30];
                strcpy(printName,pr[index].sendname());
                for(i=index; pr[i+1].sendexist(); i++) pr[i]=pr[i+1].clone();
                pr[i].remove();
                cout<<endl;
                setColor("GREEN");
                cout<<printName<<" Deleted From This Team\n";
                setColor("RESET");
                    
                cout<<endl<<"Next Work? (1:Edit Another Player | 2: Back)\n";
                choice=inputChoice(1,2);
                if(choice==1) goto start;
                return;
            }
                
        }
            
    }
        
	void teamManage(team other){
		int choice;
		while(1){
			cout<<"\n";
			setColor("BOLDRED");
			printname();
			cout<<" Session:\n";
			setColor("RESET");
			cout<<"1: Show Team Results\n";
			cout<<"2: Add Players\n";
			cout<<"3: Edit Players\n";
			cout<<"4: Change Player Numbers\n";
			cout<<"5: Show Squad List \n";
			cout<<"6: Show Detailed Player List\n";
			cout<<"7: Back to main\n";
			
			cout<<endl<<"Enter your choice: ";
			choice=inputChoice(1,7);
			
			switch(choice){
				case 1: show(); break;
				case 2: add_prs(other); break;
				case 3: editPrs(other); break;
				case 4: editPrNumbers(); break;
				case 5: showSqadList(); break;
				case 6: show_det_prs(); break;
			}
			if (choice==7) break;
		}
	}
        
	friend class match;
	friend class competition;
	friend void compare(team,team,double,double,int,int);
	friend void compare_teams(team,team);
	friend void top_scorers(team,team);
};


struct teamGameStat{
	char name[40];
	double nSub;
	double nGoals;
	double possess;
	double shots[2];
	double fouls[2];
	double corners;
	double fk;
	double passC;
	double cross;
	double interc;
	double tackles;
	double saves;
	double nCards[2];
	
	//teamGameStat(){}
	teamGameStat(char teamName[],int defValue){
		strcpy(name,teamName);
		nSub=defValue; nGoals=defValue; possess=defValue; shots[0]=defValue; shots[1]=defValue;
		fouls[0]=defValue; fouls[1]=defValue; corners=defValue; fk=defValue; passC=defValue;
		cross=defValue; interc=defValue; tackles=defValue; saves=defValue; nCards[0]=defValue; nCards[1]=defValue;
	}
	
	bool isComplete(){
		if(nSub>=0 && nGoals>=0 && possess>=0 && shots[0]>=0 && shots[1]>=0 && fouls[0]>=0 && fouls[1]>=0 && corners>=0
		&& fk>=0 && passC>=0 && cross>=0 && interc>=0 && tackles>=0 && saves>=0 && nCards[0]>=0 && nCards[1]>=0){
			return true;
		}
		return false;
	}
	
	void convertToPerGame(int number[]){
		int num=-1;
		if(number[++num]>0){ nGoals/=number[num];} else{ nGoals=-2;}
		if(number[++num]>0){ possess/=number[num];} else{ possess=-2;}
		
		if(number[++num]>0){ shots[0]/=number[num]; shots[1]/=number[num];}
		else{ shots[0]=-2; shots[1]=-2;}
			
		if(number[++num]>0){ fouls[0]/=number[num]; fouls[1]/=number[num];}
		else{ fouls[0]=-2; fouls[1]=-2;}
		
		if(number[++num]>0){ corners/=number[num];} else{ corners=-2;}
		if(number[++num]>0){ fk/=number[num];} else{ fk=-2;}
		if(number[++num]>0){ passC/=number[num];} else{ passC=-2;}
		if(number[++num]>0){ cross/=number[num];} else{ cross=-2;}
		if(number[++num]>0){ interc/=number[num];} else{ interc=-2;}
		if(number[++num]>0){ tackles/=number[num];} else{ tackles=-2;}
		if(number[++num]>0){ saves/=number[num];} else{ saves=-2;}
		
		if(number[++num]>0){ nCards[0]/=number[num]; nCards[1]/=number[num];}
		else{ nCards[0]=-2; nCards[1]=-2;}
		
		if(number[++num]>0){ nSub/=number[num];} else{ nSub=-2;}
	}
};


class match{
    public:
	bool exist;
	int year;
	int month;
	int day;
	int res;      // 1:Team 1 | 2:Team 2 | 3: Draw
	int t1_prs[11];
	int t2_prs[11];
	int t1_pov[11];
	int t2_pov[11];
	int t1_tt;
	int t2_tt;
	int t1_tvz[3];
	int t2_tvz[3];
	int t1_tov[3];
	int t2_tov[3];
	int mom[2][2];
	int t1_goals;
	int t2_goals;
	int t1_possess;
	int t2_possess;
	int t1_shots[2];
	int t2_shots[2];
	int t1_fouls[2];
	int t2_fouls[2];
	int t1_corners;
	int t2_corners;
	int t1_fk;
	int t2_fk;
	int t1_pass_c;
	int t2_pass_c;
	int t1_cross;
	int t2_cross;
	int t1_interc;
	int t2_interc;
	int t1_tackles;
	int t2_tackles;
	int t1_saves;
	int t2_saves;
    int t1_left;
    int t1_center;
    int t1_right;
    int t2_left;
    int t2_center;
    int t2_right;        
	int t1_tc[3];      //[0]:Yellow [1]:Red [2]:Sum
	int t2_tc[3];
	int tg;
	int tcards;
	int cards[28][5];
	int goals[30][5];
	char t1_conf[1200];
	char t2_conf[1200];
	char temp[20];
        
	public:
	match(){
        exist=0;
        year=0; month=0; day=0;
        for(int i=0; 11>i; i++) t1_prs[i]=0;
        for(int i=0; 11>i; i++) t2_prs[i]=0;
        for(int i=0; 11>i; i++) t1_pov[i]=0;
        for(int i=0; 11>i; i++) t2_pov[i]=0;
        t1_tt=0; t2_tt=0;
        for(int i=0; 3>i; i++) t1_tvz[i]=0;
        for(int i=0; 3>i; i++) t2_tvz[i]=0;
        for(int i=0; 3>i; i++) t1_tov[i]=0;
        for(int i=0; 3>i; i++) t2_tov[i]=0;
        for(int i=0; 2>i; i++) mom[0][i]=0;
        for(int i=0; 2>i; i++) mom[1][i]=0;
        t1_goals=0; t2_goals=0; t1_possess=0; t2_possess=0;
        for(int i=0; 2>i; i++) t1_shots[i]=0;
        for(int i=0; 2>i; i++) t2_shots[i]=0;
        for(int i=0; 2>i; i++) t1_fouls[i]=0;
        for(int i=0; 2>i; i++) t2_fouls[i]=0;
        t1_corners=0; t2_corners=0; t1_fk=0; t2_fk=0;
        t1_pass_c=0; t2_pass_c=0; t1_cross=0; t2_cross=0; t1_interc=0; t2_interc=0;
        t1_tackles=0; t2_tackles=0; t1_saves=0; t2_saves=0;
        t1_left=0; t1_center=0; t1_right=0;
        t2_left=0; t2_center=0; t2_right=0;
        for(int i=0; 3>i; i++) t1_tc[i]=0;
        for(int i=0; 3>i; i++) t2_tc[i]=0;
        tg=0;
        for(int i=0; 28>i; i++) for(int j=0; 5>j; j++) cards[i][j]=0;
        for(int i=0; 30>i; i++) for(int j=0; 5>j; j++) goals[i][j]=0;
        t1_conf[0]=0; t2_conf[0]=0;
	}
        
	void set_goals(team,team,bool edit=false);
	void set_possess_shots(team,team,bool edit=false);
	void set_fouls_corners(team,team,bool edit=false);
	void set_fk_passc_cross(team,team,bool edit=false);
	void set_ic_tackle_save(team,team,bool edit=false);
	void setLineup(team,bool,bool edit=false);
	void set_goals_scorers(team,team,inputProfile&,bool edit=false, bool checkAfterEdit=false);
	void set_tcards(team,team,bool edit=false);
	void set_cards(team,team,inputProfile&,bool edit=false, bool checkAfterEdit=false);
	void set_mom(team,team,inputProfile&,bool edit=false, bool checkAfterEdit=false);
	void set_conf(team,team,bool edit=false);
	void setPlayersHatTricks(team &,team &);
        
        
	bool sendexist(void){ return exist;}
	int getResult(){ return res;}
	
	int ** getGoals(){
		int ** out;
		out=new int*[30];
		for(int i=0; 30>i; i++) out[i]=new int[5];
		for(int i=0; 30>i; i++) for(int j=0; 5>j; j++) out[i][j]=goals[i][j];
		return out;
	}
	
	void zero(void){
		exist=0;
		year=0; month=0; day=0;
		for(int i=0; 11>i; i++) t1_prs[i]=0;
		for(int i=0; 11>i; i++) t2_prs[i]=0;
		for(int i=0; 11>i; i++) t1_pov[i]=0;
		for(int i=0; 11>i; i++) t2_pov[i]=0;
		t1_tt=0; t2_tt=0;
		for(int i=0; 3>i; i++) t1_tvz[i]=0;
		for(int i=0; 3>i; i++) t2_tvz[i]=0;
		for(int i=0; 3>i; i++) t1_tov[i]=0;
		for(int i=0; 3>i; i++) t2_tov[i]=0;
		for(int i=0; 2>i; i++) mom[0][i]=0;
		for(int i=0; 2>i; i++) mom[1][i]=0;
		t1_goals=0; t2_goals=0; t1_possess=0; t2_possess=0;
		for(int i=0; 2>i; i++) t1_shots[i]=0;
		for(int i=0; 2>i; i++) t2_shots[i]=0;
		for(int i=0; 2>i; i++) t1_fouls[i]=0;
		for(int i=0; 2>i; i++) t2_fouls[i]=0;
		t1_corners=0; t2_corners=0; t1_fk=0; t2_fk=0;
		t1_pass_c=0; t2_pass_c=0; t1_cross=0; t2_cross=0; t1_interc=0; t2_interc=0;
		t1_tackles=0; t2_tackles=0; t1_saves=0; t2_saves=0;
		t1_left=0; t1_center=0; t1_right=0;
		t2_left=0; t2_center=0; t2_right=0;
		for(int i=0; 3>i; i++) t1_tc[i]=0;
		for(int i=0; 3>i; i++) t2_tc[i]=0;
		tg=0;
		for(int i=0; 28>i; i++) for(int j=0; 5>j; j++) cards[i][j]=0;
		for(int i=0; 30>i; i++) for(int j=0; 5>j; j++) goals[i][j]=0;
		*t1_conf=0; *t2_conf=0;
	}
	
	void saveTxt(ostream &f1){
		f1<<exist<<endl;
		f1<<year<<endl;
		f1<<month<<endl;
		f1<<day<<endl;
		f1<<res<<endl;
		for(int i=0; 11>i; i++) f1<<t1_prs[i]<<endl;
		for(int i=0; 11>i; i++) f1<<t2_prs[i]<<endl;
		for(int i=0; 11>i; i++) f1<<t1_pov[i]<<endl;
		for(int i=0; 11>i; i++) f1<<t2_pov[i]<<endl;
		f1<<t1_tt<<endl;
		f1<<t2_tt<<endl;
		for(int i=0; 3>i; i++) f1<<t1_tvz[i]<<endl;
		for(int i=0; 3>i; i++) f1<<t2_tvz[i]<<endl;
		for(int i=0; 3>i; i++) f1<<t1_tov[i]<<endl;
		for(int i=0; 3>i; i++) f1<<t2_tov[i]<<endl;
		for(int i=0; 2>i; i++) for(int j=0; 2>j; j++) f1<<mom[i][j]<<endl;
		f1<<t1_goals<<endl;
		f1<<t2_goals<<endl;
		f1<<t1_possess<<endl;
		f1<<t2_possess<<endl;
		for(int i=0; 2>i; i++) f1<<t1_shots[i]<<endl;
		for(int i=0; 2>i; i++) f1<<t2_shots[i]<<endl;
		for(int i=0; 2>i; i++) f1<<t1_fouls[i]<<endl;
		for(int i=0; 2>i; i++) f1<<t2_fouls[i]<<endl;
		f1<<t1_corners<<endl;
		f1<<t2_corners<<endl;
		f1<<t1_fk<<endl;
		f1<<t2_fk<<endl;
		f1<<t1_pass_c<<endl;
		f1<<t2_pass_c<<endl;
		f1<<t1_cross<<endl;
		f1<<t2_cross<<endl;
		f1<<t1_interc<<endl;
		f1<<t2_interc<<endl;
		f1<<t1_tackles<<endl;
		f1<<t2_tackles<<endl;
		f1<<t1_saves<<endl;
		f1<<t2_saves<<endl;
		f1<<t1_left<<endl;
		f1<<t1_center<<endl;
		f1<<t1_right<<endl;
		f1<<t2_left<<endl;
		f1<<t2_center<<endl;
		f1<<t2_right<<endl;
		for(int i=0; 3>i; i++) f1<<t1_tc[i]<<endl;
		for(int i=0; 3>i; i++) f1<<t2_tc[i]<<endl;
		f1<<tg<<endl;
		f1<<tcards<<endl;
		for(int i=0; 28>i; i++) for(int j=0; 5>j; j++) f1<<cards[i][j]<<endl;
		for(int i=0; 30>i; i++) for(int j=0; 5>j; j++) f1<<goals[i][j]<<endl;
		f1<<t1_conf<<endl;
		f1<<t2_conf<<endl;
	}
	
	void loadTxt(istream &f1){
		f1>>exist;
		f1>>year;
		f1>>month;
		f1>>day;
		f1>>res;
		for(int i=0; 11>i; i++) f1>>t1_prs[i];
		for(int i=0; 11>i; i++) f1>>t2_prs[i];
		for(int i=0; 11>i; i++) f1>>t1_pov[i];
		for(int i=0; 11>i; i++) f1>>t2_pov[i];
		f1>>t1_tt;
		f1>>t2_tt;
		for(int i=0; 3>i; i++) f1>>t1_tvz[i];
		for(int i=0; 3>i; i++) f1>>t2_tvz[i];
		for(int i=0; 3>i; i++) f1>>t1_tov[i];
		for(int i=0; 3>i; i++) f1>>t2_tov[i];
		for(int i=0; 2>i; i++) for(int j=0; 2>j; j++) f1>>mom[i][j];
		f1>>t1_goals;
		f1>>t2_goals;
		f1>>t1_possess;
		f1>>t2_possess;
		for(int i=0; 2>i; i++) f1>>t1_shots[i];
		for(int i=0; 2>i; i++) f1>>t2_shots[i];
		for(int i=0; 2>i; i++) f1>>t1_fouls[i];
		for(int i=0; 2>i; i++) f1>>t2_fouls[i];
		f1>>t1_corners;
		f1>>t2_corners;
		f1>>t1_fk;
		f1>>t2_fk;
		f1>>t1_pass_c;
		f1>>t2_pass_c;
		f1>>t1_cross;
		f1>>t2_cross;
		f1>>t1_interc;
		f1>>t2_interc;
		f1>>t1_tackles;
		f1>>t2_tackles;
		f1>>t1_saves;
		f1>>t2_saves;
		f1>>t1_left;
		f1>>t1_center;
		f1>>t1_right;
		f1>>t2_left;
		f1>>t2_center;
		f1>>t2_right;
		for(int i=0; 3>i; i++) f1>>t1_tc[i];
		for(int i=0; 3>i; i++) f1>>t2_tc[i];
		f1>>tg;
		f1>>tcards;
		for(int i=0; 28>i; i++) for(int j=0; 5>j; j++) f1>>cards[i][j];
		for(int i=0; 30>i; i++) for(int j=0; 5>j; j++) f1>>goals[i][j];
		f1.ignore();
		f1.getline(t1_conf,1200);
		f1.getline(t2_conf,1200);
	}
	
	void set_date(bool edit=false){
		int bar,error,choice;
		cout<<"\nEnter Date of Match (Year | Month | Day)\n";
		bar=0;
		do{
			error=0;
			bar++;
			if(bar>1){ cout<<endl; setColor("BOLDYELLOW"); cout<<"Adade vorudi Na motabarand. Try Again\n"; setColor("RESET"); cout<<endl;}
			if(!edit){
				cin>>year>>month>>day;
				cin.ignore();
			}
			edit=false;
			
			if(((year<1300 || year>1500) && year !=-2) || ((month<1 || month>12) && month!=-2) || ((day<1 || day>31) && day!=-2)){
				error=1;
			}
		} while (error==1);
		
		if(year==-2){ month=-2; day=-2;}
		if(month==-2) day=-2;
		cout<<endl; setColor("BOLDBLUE"); cout<<"Date Of Match: ";
		if(year!=-2) cout<<year<<"/"; else cout<<"UK"<<"/";
		
		if(month!=-2 && month>9) cout<<month<<"/";
		else if(month!=-2 && month<10)cout<<"0"<<month<<"/";
		else cout<<"UK"<<"/";
		
		if(day!=-2 && day>9){
			cout<<day;
			setColor("RESET");
			cout<<endl;
		} 
		else if(day!=-2 && day<10){
			cout<<"0"<<day;
			setColor("RESET");
			cout<<endl;
		} 
		else{
			cout<<"UK";
			setColor("RESET");
			cout<<endl;
		}
		
		cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
		choice=inputChoice(1,2);
		if(choice==2) set_date();
	}
        
    void setAttackingAreas(team tm1,team tm2,bool edit=false){
        stringstream temp1;
        stringstream temp2;
        stringstream temp3;
        stringstream temp4;
        stringstream temp5;
        stringstream temp6;
        int choice,error=0;
        
        start:
        temp1.str("");
        temp2.str("");
        temp3.str("");
        temp4.str("");
        temp5.str("");
        temp6.str("");
        if(edit){
            edit=false;
            goto finalaproval;
        }

        cout<<"\nEnter "<<tm1.getName()<<" Attacking Areas (Left,Center,Right): ";
        t1_left=nextInt();
        t1_center=nextInt();
        t1_right=nextInt();
        
        cout<<"\nEnter "<<tm2.getName()<<" Attacking Areas (Left,Center,Right): ";
        t2_left=nextInt();
        t2_center=nextInt();
        t2_right=nextInt();

        finalaproval:
        error=0;
        if(t1_left==-2) temp1<<"UK";
        else if(t1_left<0 || t1_left>(INT_MAX-2)) temp1<<"Null";
        else temp1<<t1_left<<"%";
        
        if(t1_center==-2) temp2<<"UK";
        else if(t1_center<0 || t1_center>(INT_MAX-2)) temp2<<"Null";
        else temp2<<t1_center<<"%";
        
        if(t1_right==-2) temp3<<"UK";
        else if(t1_right<0 || t1_right>(INT_MAX-2)) temp3<<"Null";
        else temp3<<t1_right<<"%";
        
        if(t2_left==-2) temp4<<"UK";
        else if(t2_left<0 || t2_left>(INT_MAX-2)) temp4<<"Null";
        else temp4<<t2_left<<"%";
        
        if(t2_center==-2) temp5<<"UK";
        else if(t2_center<0 || t2_center>(INT_MAX-2)) temp5<<"Null";
        else temp5<<t2_center<<"%";
        
        if(t2_right==-2) temp6<<"UK";
        else if(t2_right<0 || t2_right>(INT_MAX-2)) temp6<<"Null";
        else temp6<<t2_right<<"%";
        
        cout<<endl;
        setColor("BOLDBLUE");
        cout<<tm1.getName()<<" Attacking Areas: Left: "; ccsPrint(temp1);
		cout<<" | Center: "; ccsPrint(temp2);
		cout<<" | Right: "; ccsPrint(temp3); cout<<endl;

        cout<<tm2.getName()<<" Attacking Areas: Left: "; ccsPrint(temp4);
		cout<<" | Center: "; ccsPrint(temp5);
		cout<<" | Right: "; ccsPrint(temp6); cout<<endl;
        setColor("RESET");
        
        if(!ukEasycheck(t1_left,1,100) ||
			!ukEasycheck(t1_center,1,100) ||
			!ukEasycheck(t1_right,1,100) ||
			!ukEasycheck(t2_left,1,100) ||
			!ukEasycheck(t2_center,1,100) ||
			!ukEasycheck(t2_right,1,100)
        ){
            cout<<endl;
            typeError();
            cout<<"Invalid Values!\n";
            error=1;
        }
        
        else{
            if(t1_left!=-2 && t1_center!=-2 && t1_right!=-2 && (t1_left+t1_center+t1_right)!=100){
                cout<<endl;
                typeError();
                cout<<"The Sum Of "<<tm1.getName()<<" Attacking Areas Is Not 100\n";
                error=1;
            }
            if(t2_left!=-2 && t2_center!=-2 && t2_right!=-2 && (t2_left+t2_center+t2_right)!=100){
                if(!error) cout<<endl;
                typeError();
                cout<<"The Sum Of "<<tm2.getName()<<" Attacking Areas Is Not 100\n";
                error=1;
            }
        }
        
        if(error==1){
            cout<<endl;
            setColor("BOLDYELLOW");
            cout<<"Attacking Areas Entered by Mistake! Please Try Again.\n";
            setColor("RESET");
            goto start;
        }
            
        
        cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
        choice=inputChoice(1,2);
        if(choice==2){ goto start;}	
    }
    
    void printOverallsPrs(team tm1,team tm2){
        const int scrLength=90;
        int t,c,s;
		stringstream ts1[14];
		stringstream ts2[14];
        stringstream cadr;

		for(int i=0; 14>i; i++){
			ts1[i].str("");
			ts2[i].str("");
		}

		for(int i=0; 11>i; i++){
            ts1[i]<<i+1<<": ";
            if(t1_prs[i]==-2) ts1[i]<<"UK";
            else{
                ts1[i]<<tm1.getPrFromNumber(t1_prs[i]).sendname();
				ts1[i]<<" ("<<player::getOverallString(t1_pov[i])<<")";
            }
        }

		for(int i=0; 11>i; i++){
            ts2[i]<<i+1<<": ";
            if(t2_prs[i]==-2) ts2[i]<<"UK";
            else{
                ts2[i]<<tm2.getPrFromNumber(t2_prs[i]).sendname();
                //if(t2_pov[i]>0) ts2[i]<<" ("<<t2_pov[i]<<")";
                //else ts2[i]<<" (UK)";
				ts2[i]<<" ("<<player::getOverallString(t2_pov[i])<<")";
            }
        }

		for(int i=11; 14>i; i++){
            if(t1_tt>i-11){
				ts1[i]<<i+1<<": ";
                if(t1_tvz[i-11]==-2){
                    ts1[i]<<"UK";
                }
                else{
                    ts1[i]<<tm1.getPrFromNumber(t1_tvz[i-11]).sendname();
                    //if(t1_tov[i-11]>0) ts1[i]<<" ("<<t1_tov[i-11]<<")";
                    //else ts1[i]<<" (UK)";
					ts1[i]<<" ("<<player::getOverallString(t1_tov[i-11])<<")";
                }
            }
		}

		for(int i=11; 14>i; i++){
            if(t2_tt>i-11){
				ts2[i]<<i+1<<": ";
                if(t2_tvz[i-11]==-2) ts2[i]<<"UK";
                else{
                    ts2[i]<<tm2.getPrFromNumber(t2_tvz[i-11]).sendname();
                    //if(t2_tov[i]>0) ts2[i-11]<<" ("<<t2_tov[i-11]<<")";
                    //else ts2[i]<<" (UK)";
					ts2[i]<<" ("<<player::getOverallString(t2_tov[i-11])<<")";
                }
            }
		}

		cout<<endl<<endl;

        cadr<<"$$BLU";
		setColor("BOLDBLUE"); beforeStrWhere("Players Overalls Ratings",scrLength); setColor("RESET");cout<<endl;
		s=21; t=23;
		c=2+(t*2);
		space(s); ccsPrint(cadr); cadr_dash(c,true); setColor("RESET");cout<<endl;
		for(int i=0; 11>i; i++){
            space(s); ccsPrint(cadr); cout<<"|"; setColor("RESET");
            strwhere(ts1[i],t,1);
            strwhere(ts2[i],t,1);
            ccsPrint(cadr); cout<<"|"; setColor("RESET"); cout<<endl; 
		}
		
		space(s); ccsPrint(cadr); cadr_dash(c,true); setColor("RESET");cout<<endl;
		for(int i=11; 14>i; i++){
            space(s); ccsPrint(cadr); cout<<"|"; setColor("RESET");
            strwhere(ts1[i],t,1);
            strwhere(ts2[i],t,1);
            ccsPrint(cadr); cout<<"|"; setColor("RESET");cout<<endl;		
		}
		space(s); ccsPrint(cadr); cadr_dash(c,true); setColor("RESET");cout<<endl;
    }
    
    void setOverallPrs(team tm1,team tm2,bool edit=false){
		bool runFunc=false;
		for(int i=0; 11>i && !runFunc; i++){
			if(t1_prs[i]>0){
				runFunc=true;
			}
		}

		for(int i=0; 11>i && !runFunc; i++){
			if(t2_prs[i]>0){
				runFunc=true;
			}
		}

		for(int i=0; 3>i && !runFunc; i++){
			if(t1_tvz[i]>0){
				runFunc=true;
			}
		}

		for(int i=0; 3>i && !runFunc; i++){
			if(t2_tvz[i]>0){
				runFunc=true;
			}
		}

		if(!runFunc) return;
		if(edit){
			if(!runFunc){
				cout<<endl<<"There is no Known Player To Edit Overall Ratings";
				return;
			}
			edit=false;
			goto editing;
		}

        for(int i=0; 11>i; i++){
            if(t1_prs[i]>0){
                t1_pov[i]=tm1.getPrFromNumber(t1_prs[i]).getOverallRating();
            }
            else t1_pov[i]=-1;
        }

        for(int i=0; 11>i; i++){
            if(t2_prs[i]>0){
                t2_pov[i]=tm2.getPrFromNumber(t2_prs[i]).getOverallRating();
            }
            else t2_pov[i]=-1;
        }

        for(int i=0; 3>i; i++){
            if(t1_tvz[i]>0){
                t1_tov[i]=tm1.getPrFromNumber(t1_tvz[i]).getOverallRating();
            }
            else t1_tov[i]=-1;
        }

        for(int i=0; 3>i; i++){
            if(t2_tvz[i]>0){
                t2_tov[i]=tm2.getPrFromNumber(t2_tvz[i]).getOverallRating();
            }
            else t2_tov[i]=-1;
        }

        editing:
        printOverallsPrs(tm1,tm2);
        
		cout<<endl;
        typeRule();
        cout<<"For Edit Overall Rating Of a player: \n";
        cout<<"Enter Team Id | Player List Number | New Overall Rating\n";
        typeRule();
        cout<<"Enter 3 for End of Editing Overall Ratings\n";
        typeRule();
        cout<<"Unknown Overall Rating = -2\n";

        while(true){
            wh:
            int one,two,three;
            cout<<endl;
            cout<<"Enter Team Id or Three to Quit: ";
            one=nextInt();
            if(!easycheck(one,1,3)){
                cout<<endl;
                typeError();
                cout<<"First Input Most be 1 or 2 (Team Id) Or 3 for Quit\n";
                cout<<"Please Try Again.\n";
                goto wh;
            }
            
            if(one==3){
				if(sure()) break;
				else goto wh;
			}
			
            cout<<"Enter Player List Number: ";
            two=nextInt();
            if(one==1){
                if(!easycheck(two,1,11+t1_tt)){
                    cout<<endl;
                    typeError();
                    cout<<"Second Input Most Be Player List Number (1 to "<<11+t1_tt<<"!\n";
                    cout<<"Please Try Again.\n";
                    goto wh;
                }
                else if((two<=11 && t1_prs[two-1]<0) || (two>11 && t1_tvz[two-1-11]<0)){
                    cout<<endl;
                    typeError();
					cout<<"This List number's Player Is Unknown!\n";
                    cout<<"Please Try Again.\n";
                    goto wh;
				}
            }
            
            else if(one==2){
                if(!easycheck(two,1,11+t2_tt)){
                    cout<<endl;
                    typeError();
                    cout<<"Second Input Most Be Player List Number (1 to "<<11+t2_tt<<"!\n";
                    cout<<"Please Try Again.\n";
                    goto wh;
                }
                else if((two<=11 && t2_prs[two-1]<0) || (two>11 && t2_tvz[two-1-11]<0)){
                    cout<<endl;
                    typeError();
					cout<<"This List number's Player Is Unknown!\n";
                    cout<<"Please Try Again.\n";
                    goto wh;
				}
            }
            
            cout<<"Enter New Overall Rating: ";
            three=nextInt();
            if(!ukEasycheck(three,1,109)){
                cout<<endl;
                typeError();
                cout<<"Third Input Most Be New Overall Rating (1 to 109) or UK Number(-2)\n";
                cout<<"Please Try Again.\n";
                goto wh;
            }
            
            cout<<endl;
            setColor("BOLDBLUE");
            if(one==1){
                cout<<tm1.getName()<<" - ";
                if(two<=11){
                    cout<<tm1.getPrFromNumber(t1_prs[two-1]).sendname()<<": ";
                    if(t1_pov[two-1]==-2) cout<<"UK -> ";
                    else cout<<t1_pov[two-1]<<" -> ";
                    cout<<three<<endl;
                    t1_pov[two-1]=three;
                }
                else if(two>11){
                    cout<<tm1.getPrFromNumber(t1_tvz[two-1-11]).sendname()<<": ";
                    if(t1_tov[two-1-11]==-2) cout<<"UK -> ";
                    else cout<<t1_tov[two-1-11]<<" -> ";
                    cout<<three<<endl;
                    t1_tov[two-1-11]=three;
                }
            }
            else if(one==2){
                cout<<tm2.getName()<<" - ";
                if(two<=11){
                    cout<<tm2.getPrFromNumber(t2_prs[two-1]).sendname()<<": ";
                    if(t2_pov[two-1]==-2) cout<<"UK -> ";
                    else cout<<t2_pov[two-1]<<" -> ";
                    cout<<three<<endl;
                    t2_pov[two-1]=three;
                }
                else if(two>11){
                    cout<<tm2.getPrFromNumber(t2_tvz[two-1-11]).sendname()<<": ";
                    if(t2_tov[two-1-11]==-2) cout<<"UK -> ";
                    else cout<<t2_tov[two-1-11]<<" -> ";
                    cout<<three<<endl;
                    t2_tov[two-1-11]=three;
                }
            }
            setColor("RESET");
            cout<<endl;
            printOverallsPrs(tm1,tm2);
        }
    }
    
    double getTeamStrength(team tm){
		int sum=0;
		int *pov;
		int *tov;
		int tt;
		int num;
		
		if(tm.sendid()==1){
			pov=t1_pov;
			tov=t1_tov;
			tt=t1_tt;
		}
		else if(tm.sendid()==2){
			pov=t2_pov;
			tov=t2_tov;
			tt=t2_tt;	
		}
		num=11+tt;
		
		for(int i=0; 11>i; i++){
			if(pov[i]>0) sum+=pov[i];
			else return -1;
		}
		
		for(int i=0; tt>i; i++){
			if(tov[i]>0) sum+=tov[i];
			else return -1;
		}
		return (double)sum/num;
	}
	
	int ** getPlayersStats(){
		int ** prStats;
		prStats=new int*[28];
		for(int i=0; 28>i; i++) prStats[i]=new int[4];    //0:Team | 1:Player ID | 2:Goals | 3:Assists
		for(int i=0; 28>i; i++) for(int j=0; 4>j; j++) prStats[i][j]=0;
		if(tg==0){
			prStats[0][0]=0;
			return prStats;
		}
		for(int i=0; tg>i; i++){
			int scorerID;
			int assisterID;
			int teamID;
			int firstEmptyIndex;
			int scorerIndex=-1;
			int assisterIndex=-1;
			
			teamID=goals[i][0];
			scorerID=goals[i][2];
			assisterID=goals[i][3];
			if(scorerID!=-2 && scorerID!=-1){
				for(int j=0; 28>j; j++){
					if(prStats[j][0]==teamID && prStats[j][1]==scorerID){
						scorerIndex=j;
						break;
					}
					else if(prStats[j][0]==0){
						firstEmptyIndex=j;
						break;
					}
				}
				if(scorerIndex==-1){
					prStats[firstEmptyIndex][0]=teamID;
					prStats[firstEmptyIndex][1]=scorerID;
					prStats[firstEmptyIndex][2]=1;
					prStats[firstEmptyIndex][3]=0;
				}
				else{
					prStats[scorerIndex][2]++;
				}
			}
			
			if(assisterID!=-2 && assisterID!=-1){
				for(int j=0; 28>j; j++){
					if(prStats[j][0]==teamID && prStats[j][1]==assisterID){
						assisterIndex=j;
						break;
					}
					else if(prStats[j][0]==0){
						firstEmptyIndex=j;
						break;
					}
				}
				
				if(assisterIndex==-1){
					prStats[firstEmptyIndex][0]=teamID;
					prStats[firstEmptyIndex][1]=assisterID;
					prStats[firstEmptyIndex][2]=0;
					prStats[firstEmptyIndex][3]=1;
				}
				else{
					prStats[assisterIndex][3]++;
				}
			}
		}
		
		return prStats;
	}
        
	bool isPlayedThisId(int team,int input){
		if(team==1){
			for(int i=0; 11>i; i++) if(t1_prs[i]==-2 || t1_prs[i]==input) return true;
			for(int i=0; 3>i; i++) if(t1_tvz[i]==-2 || t1_tvz[i]==input) return true;
			return false;
		}
		else if(team==2){
			for(int i=0; 11>i; i++) if(t2_prs[i]==-2 || t2_prs[i]==input) return true;
			for(int i=0; 3>i; i++) if(t2_tvz[i]==-2 || t2_tvz[i]==input) return true;
			return false;
		}
		throw -1;
	}
        
        
	bool prCanEnter(int number,team tm, bool enteredMatch=false){
		player pr;
		int checking;
		if(enteredMatch){
			try{
				pr=tm.getPrFromNumber(number);
			}
			catch(int ex){
				return false;
			}
			int id=tm.getPrIdFromNumber(number);
			checking=id;
		}
		else{
			if(tm.existNumber(number)) checking=number;
			else return false;
		}
            
		if(tm.sendid()==1){
			for(int i=0; 11>i; i++){
				if(t1_prs[i]==checking || t1_prs[i]==-2) return true;
			}
			for(int i=0; 3>i; i++){
				if(t1_tvz[i]==checking || t1_tvz[i]==-2) return true;
			}
			return false;
		}
            
		else if(tm.sendid()==2){
			for(int i=0; 11>i; i++){
				if(t2_prs[i]==checking || t2_prs[i]==-2) return true;
			}
			for(int i=0; 3>i; i++){
				if(t2_tvz[i]==checking || t2_tvz[i]==-2) return true;
			}
			return false;
		}
		throw -1;
	}
        
	bool enterCard(int i,team tm1,team tm2,inputProfile& inpSettings,bool edit=false){
		int temp[5];
		int choice;
		bool error=true;
		bool first=true;
            
		while(error){
			error=false;
			if(edit){
				edit=false;
				temp[0]=cards[i][0];
				temp[1]=cards[i][2];
				temp[2]=cards[i][3];
				if(cards[i][4]==-2) temp[3]=-2;    
				else if(cards[i][1]==1){
					if(cards[i][4]>=45){
						temp[3]=45;
						temp[4]=cards[i][4]-45;
					}
					else{
						temp[3]=cards[i][4];
					}
				}
                        
				else if(cards[i][1]==2){
					if(cards[i][4]>=90){
						temp[3]=90;
						temp[4]=cards[i][4]-90;
					}
					else{
						temp[3]=cards[i][4];
					}
				}
				goto finderror;
			}
                
			if(!first){
				mistake:
				cout<<"\nYou Entered The Card By Mistake!\n";
				setColor("BOLDRED");
				cout<<"\nNext Work?\n";
				setColor("RESET");
				cout<<"1:Try Again\n2: Edit Game Input Settings\n3: Go to Number of Goals Session\n";
				cout<<"4: Go to Line Up Session\n";
				cout<<"\nEnter Your Choice: ";
				choice =inputChoice(1,4);
				if(choice==2){
					inpSettings.settings();
					goto mistake;
				}
                    
				else if(choice==3){
					set_tcards(tm1,tm2);
					return false;
				}
				else if(choice==4){
					setColor("BOLDRED");
					cout<<"Works:\n";
					setColor("RESET");
					cout<<"1: Enter Complete Teams Line Ups\n";
					cout<<"2: Enter "<<tm1.getName()<<" Line Up\n";
					cout<<"3: Enter "<<tm2.getName()<<" Line Up\n";
					cout<<"4: Cancel And Try Again to Entering Goal\n";
					choice=inputChoice(1,4);
					if(choice==1){
						setFirstLineup(tm1);
						setFirstLineup(tm2);
						setSubLineup(tm1);
						setSubLineup(tm2);
					}
					else if(choice==2){
						setFirstLineup(tm1);
						setSubLineup(tm1);
					}
					else if(choice==3){
						setFirstLineup(tm2);
						setSubLineup(tm2);
					}
					if(choice!=4) return false;
				}
				cout<<endl;
			}
			
			first=false;
			if(!first) cout<<"Enter The Card: ";
			temp[0]=nextInt();
			temp[1]=nextInt();
			temp[2]=nextInt();
			if(inpSettings.getCardsTimes()) temp[3]=nextInt(); else temp[3]=-2;
			if(temp[3]==45 || temp[3]==90) temp[4]=nextInt();
                
			finderror:
			cout<<endl;
			if(!easycheck(temp[0],1,2)){
				printError("Team Id is Invalid (Most Be 1 Or 2)\n");
				error=true;
			}
			
			if(!easycheck(temp[1],1,2)){
				printError("Card Color is Invalid (Most Be 1 Or 2)\n");
				error=true;
			}
			
			if(temp[2]!=-2){
				if(temp[2]>INT_MAX-2) printError("Player Number is Invalid!\n");
				else if((temp[0]==1 && !tm1.existNumber(temp[2])) || (temp[0]==2 && !tm2.existNumber(temp[2]))){
					printError("Player: There is No Player With This Number!\n");
					error=true;
				}
				
				else if((temp[0]==1 && !prCanEnter(temp[2],tm1)) || (temp[0]==2 && !prCanEnter(temp[2],tm2))){
					printError("Player: This Player Not entered This Game!\n");
					error=true;
				}
			}
			
			if(!ukEasycheck(temp[3],1,90)){
				printError("Normal Time is Invalid (Most Be Between 1 To 90)\n");
				error=true;
			}
			if((temp[3]==45 || temp[3]==90) && !ukEasycheck(temp[4],0,15)){
				printError("Extra Time is Invalid (Most Be Between 0 To 15)\n");
				error=true;
			}
                
		}
		cards[i][0]=temp[0];
		if(temp[3]==-2) cards[i][1]=-2;
		else if(temp[3]<=45) cards[i][1]=1;
		else cards[i][1]=2;
		cards[i][2]=temp[1];
		cards[i][3]=temp[2];
		cards[i][4]=temp[3];
		if(cards[i][4]==45 || cards[i][4]==90) cards[i][4]+=temp[4];
		return true;
	}
        
        
	bool cardErrorAfterEdit(int i,team tm1,team tm2){
		if(!easycheck(cards[i][0],1,2)){
			return true;
		}
            
		if(!easycheck(cards[i][1],1,2)){
			return true;
		}
            
		if(!easycheck(cards[i][2],1,2)){
			return true;
		}
		if(cards[i][3]!=-2){
			if((cards[i][0]==1 && !prCanEnter(cards[i][3],tm1)) || (cards[i][0]==2 && !prCanEnter(cards[i][3],tm2))){
				return true;
			}
		}
		if(!ukEasycheck(cards[i][4],1,105)){
			return true;
		}
		return false;
	}
        
	void printCard(int i,team tm1,team tm2,inputProfile inpSettings){
		stringstream temp1;
		stringstream temp2;
		stringstream temp3;
		stringstream temp4;
		stringstream temp5;
		temp1.str("");
		temp2.str("");
		temp3.str("");
		temp4.str("");
		temp5.str("");
		
		if(cards[i][0]==1) temp1<<tm1.name;
		else if(cards[i][0]==2) temp1<<tm2.name;
		
		if(cards[i][1]==1) temp2<<"First Half";
		else if(cards[i][1]==2) temp2<<"Second Half";
		else if(cards[i][0]==-2) temp2<<"UK";
		
		if(cards[i][2]==1) temp3<<"Yellow";
		else if(cards[i][2]==2) temp3<<"Red";
		
		if(cards[i][3]==-2) temp4<<"UK";
		else if(cards[i][0]==1) temp4<<tm1.getPrFromNumber(cards[i][3]).sendname();
		else if(cards[i][0]==2) temp4<<tm2.getPrFromNumber(cards[i][3]).sendname();
		
		if(cards[i][4]==-2) temp5<<"UK"; else temp5<<cards[i][4];
		ccsPrint(temp1); 
		
		if(inpSettings.getCardsTimes()){
			cout<<" | ";
			ccsPrint(temp2);
		}
		cout<<" | "; ccsPrint(temp3);
		cout<<" | "; ccsPrint(temp4);
		if(inpSettings.getCardsTimes()){ 
			cout<<" | ";
			ccsPrint(temp5);
		}
		cout<<endl;
	}
        
	bool enterGoal(int i,team tm1,team tm2,inputProfile& inpSettings,bool edit=false){
		int temp[5];
		int choice;
		bool error=true;
		bool first=true;
            
		while(error){
			error=false;
			if(edit){
				first=false;
				edit=false;
				temp[0]=goals[i][0];
				temp[1]=goals[i][2];
				temp[2]=goals[i][3];
				if(goals[i][4]==-2) temp[3]=-2;
				else if(goals[i][1]==1){
					if(goals[i][4]>=45){
						temp[3]=45;
						temp[4]=goals[i][4]-45;
					}
					else{
						temp[3]=goals[i][4];
					}
				}
                        
				else if(goals[i][1]==2){
					if(goals[i][4]>=90){
						temp[3]=90;
						temp[4]=goals[i][4]-90;
					}
					else{
						temp[3]=goals[i][4];
					}
				}
				goto finderror;
			}
                
			if(!first){
				mistake:
				cout<<"\nYou Entered The Goal By Mistake!\n";
				setColor("BOLDRED");
				cout<<"\nNext Work?\n";
				setColor("RESET");
				cout<<"1:Try Again\n2: Edit Game Input Settings\n3: Go to Number of Goals Session\n";
				cout<<"4: Go to Line Up Session\n";
				cout<<"\nEnter Your Choice: ";
				choice =inputChoice(1,4);
				if(choice==2){
					inpSettings.settings();
					goto mistake;
				}
                    
				else if(choice==3){
					set_goals(tm1,tm2);
					return false;
				}
				else if(choice==4){
					setColor("BOLDRED");
					cout<<"Works:\n";
					setColor("RESET");
					cout<<"1: Enter Complete Teams Line Ups\n";
					cout<<"2: Enter "<<tm1.getName()<<" Line Up\n";
					cout<<"3: Enter "<<tm2.getName()<<" Line Up\n";
					cout<<"4: Cancel And Try Again to Entering Goal\n";
					choice=inputChoice(1,4);
					if(choice==1){
						setFirstLineup(tm1);
						setFirstLineup(tm2);
						setSubLineup(tm1);
						setSubLineup(tm2);
					}
					else if(choice==2){
						setFirstLineup(tm1);
						setSubLineup(tm1);
					}
					else if(choice==3){
						setFirstLineup(tm2);
						setSubLineup(tm2);
					}
					if(choice!=4) return false;
				}
				cout<<endl;
			}
			
			if(!first) cout<<"Enter The Goal: ";
			first=false;
			temp[0]=nextInt();
			temp[1]=nextInt();
			if(inpSettings.getAssists()) temp[2]=nextInt(); else temp[2]=-2;
			if(inpSettings.getGoalsTimes()) temp[3]=nextInt(); else temp[3]=-2;
			if(temp[3]==45 || temp[3]==90) temp[4]=nextInt();
                
			finderror:
			cout<<endl;
			if(!easycheck(temp[0],1,2)){
				printError("Team Id is Invalid (Most Be 1 Or 2)\n");
				cout<<endl<<"KONUN: "<<temp[0]<<endl;
				error=true;
			}

			if(temp[1]!=-2 && temp[1]!=-1){
				if(temp[1]>INT_MAX-2) printError("Scorer Number is Invalid!\n");
				else if((temp[0]==1 && !tm1.existNumber(temp[1])) || (temp[0]==2 && !tm2.existNumber(temp[1]))){
					printError("Scorer: There is No Player With This Number!\n");
					error=true;
				}
				else if((temp[0]==1 && !prCanEnter(temp[1],tm1)) || (temp[0]==2 && !prCanEnter(temp[1],tm2))){
					printError("Scorer: This Player Not entered This Game!\n");
					error=true;
				}
			}

			if(temp[2]!=-2 && temp[2]!=-1){
				if(temp[2]>INT_MAX-2) printError("Assister Number is Invalid!\n");
				else if((temp[0]==1 && !tm1.existNumber(temp[2])) || (temp[0]==2 && !tm2.existNumber(temp[2]))){
					printError("Assister: There is No Player With This Number!\n");
					error=true;
				}
				else if((temp[0]==1 && !prCanEnter(temp[2],tm1)) || (temp[0]==2 && !prCanEnter(temp[2],tm2))){
					printError("Assister: This Player Not entered This Game!\n");
					error=true;
				}
			}

			if(!ukEasycheck(temp[3],1,90)){
				printError("Normal Time is Invalid (Most Be Between 1 To 90)\n");
				error=true;
				continue;
			}

			if((temp[3]==45 || temp[3]==90) && !ukEasycheck(temp[4],0,15)){
				printError("Extra Time is Invalid (Most Be Between 0 To 15)\n");
				error=true;
			}
		}

		goals[i][0]=temp[0];
		if(temp[3]==-2) goals[i][1]=-2;
		else if(temp[3]<=45) goals[i][1]=1;
		else goals[i][1]=2;
		goals[i][2]=temp[1];
		goals[i][3]=temp[2];
		goals[i][4]=temp[3];
		if(goals[i][4]==45 || goals[i][4]==90) goals[i][4]+=temp[4];
		return true;
	}
        
	bool goalErrorAfterEdit(int i,team tm1, team tm2){
		if(!easycheck(goals[i][0],1,2)){
			return true;
		}
            
		if(!ukEasycheck(goals[i][1],1,2)){
			return true;
		}
            
		if(goals[i][2]!=-2 || goals[i][2]!=-1){
			if((goals[i][0]==1 && !prCanEnter(goals[i][2],tm1)) || (goals[i][0]==2 && !prCanEnter(goals[i][2],tm2))){
				return true;
			}
		}

		if(goals[i][3]!=-2 && goals[i][3]!=-1){
			if((goals[i][0]==1 && !prCanEnter(goals[i][3],tm1)) || (goals[i][0]==2 && !prCanEnter(goals[i][3],tm2))){
				return true;
			}
		}

		if(!ukEasycheck(goals[i][4],1,105)){
			return true;
		}
		return false;
	}
        
	void printGoal(int i,team tm1, team tm2,inputProfile inpSettings){
		stringstream temp1;
		stringstream temp2;
		stringstream temp3;
		stringstream temp4;
		stringstream temp5;
		temp1.str("");
		temp2.str("");
		temp3.str("");
		temp4.str("");
		temp5.str("");
			
		if(goals[i][0]==1) temp1<<tm1.name;
		else if(goals[i][0]==2) temp1<<tm2.name;
			
		if(goals[i][1]==1) temp2<<"First Half";
		else if(goals[i][1]==2) temp2<<"Second Half";
		else if(goals[i][1]==-2) temp2<<"UK";
			
		if(goals[i][2]==-1) temp3<<"OG";
		else if(goals[i][2]==-2) temp3<<"UK";
		else if(goals[i][0]==1) temp3<<tm1.getPrFromNumber(goals[i][2]).sendname();
		else if(goals[i][0]==2) temp3<<tm2.getPrFromNumber(goals[i][2]).sendname();
		else temp3<<"Null";
			
		if(goals[i][3]==-1) temp4<<"WA"; 
		else if(goals[i][3]==-2) temp4<<"UK";
		else if(goals[i][0]==1) temp4<<tm1.getPrFromNumber(goals[i][3]).sendname();
		else if(goals[i][0]==2) temp4<<tm2.getPrFromNumber(goals[i][3]).sendname();
			
		if(goals[i][4]==-2) temp5<<"UK"; else temp5<<goals[i][4];
		ccsPrint(temp1);
		
		if(inpSettings.getGoalsTimes()){
			cout<<" | ";
			ccsPrint(temp2);
		}
		
		cout<<" | "; ccsPrint(temp3);
		if(inpSettings.getAssists()){
			cout<<" | ";
			ccsPrint(temp4);
		}
		
		if(inpSettings.getGoalsTimes()){
			cout<<" | ";
			ccsPrint(temp5);
		}
		cout<<endl;
	}			
	
	
	int dynamicGet(const char * index){
		if(strcasecmp(index,"exist")==0) return exist;
		else if (strcasecmp(index,"res")==0) return res;
		else if (strcasecmp(index,"t1_goals")==0) return t1_goals;
		else if (strcasecmp(index,"t2_goals")==0) return t2_goals;
		else if (strcasecmp(index,"tg")==0) return tg;
		else if (strcasecmp(index,"tcards")==0) return tcards;
		else if (strcasecmp(index,"t1_corners")==0) return t1_corners;
		else if (strcasecmp(index,"t2_corners")==0) return t2_corners;
		else if (strcasecmp(index,"t1_cross")==0) return t1_cross;
		else if (strcasecmp(index,"t2_cross")==0) return t2_cross;
		else if (strcasecmp(index,"t1_fk")==0) return t1_fk;
		else if (strcasecmp(index,"t2_fk")==0) return t2_fk;
		else if (strcasecmp(index,"t1_interc")==0) return t1_interc;
		else if (strcasecmp(index,"t2_interc")==0) return t2_interc;
		else if (strcasecmp(index,"t1_pass_c")==0) return t1_pass_c;
		else if (strcasecmp(index,"t2_pass_c")==0) return t2_pass_c;
		else if (strcasecmp(index,"t1_possess")==0) return t1_possess;
		else if (strcasecmp(index,"t2_possess")==0) return t2_possess;
		else if (strcasecmp(index,"t1_saves")==0) return t1_saves;
		else if (strcasecmp(index,"t2_saves")==0) return t2_saves;
		else if (strcasecmp(index,"t1_shotsOne")==0) return t1_shots[0];
		else if (strcasecmp(index,"t2_shotsOne")==0) return t2_shots[0];
		else if (strcasecmp(index,"t1_shotsTwo")==0) return t1_shots[1];
		else if (strcasecmp(index,"t2_shotsTwo")==0) return t2_shots[1];
		
		else if (strcasecmp(index,"t1_foulsOne")==0) return t1_fouls[0];
		else if (strcasecmp(index,"t2_foulsOne")==0) return t2_fouls[0];
		else if (strcasecmp(index,"t1_foulsTwo")==0) return t1_fouls[1];
		else if (strcasecmp(index,"t2_foulsTwo")==0) return t2_fouls[1];
		else if (strcasecmp(index,"t1_tackles")==0) return t1_tackles;
		else if (strcasecmp(index,"t2_tackles")==0) return t2_tackles;
		else if (strcasecmp(index,"t1DifGoals")==0) return t1_goals-t2_goals;
		else if (strcasecmp(index,"t2DifGoals")==0) return t2_goals-t1_goals;
		else if (strcasecmp(index,"t1YC")==0) return t1_tc[0];
		else if (strcasecmp(index,"t1RC")==0) return t1_tc[1];
		else if (strcasecmp(index,"t2YC")==0) return t2_tc[0];
		else if (strcasecmp(index,"t2RC")==0) return t2_tc[1];
		
		else if (strcasecmp(index,"t1_left")==0) return t1_left;
		else if (strcasecmp(index,"t2_left")==0) return t2_left;
		else if (strcasecmp(index,"t1_center")==0) return t1_center;
		else if (strcasecmp(index,"t2_center")==0) return t2_center;
		else if (strcasecmp(index,"t1_right")==0) return t1_right;
		else if (strcasecmp(index,"t2_right")==0) return t2_right;
		else throw -1;
	}
	        
	void setFirstLineup(team tm){
		setLineup(tm,true);
	}
	
	void setSubLineup(team tm){
		setLineup(tm,false);
	}
        
	void convertNumbersToID(team tm1,team tm2){
		for(int k=0; 11>k; k++){
			if(t1_prs[k]>0) t1_prs[k]=tm1.getPrFromNumber(t1_prs[k]).getId();
		}
		for(int k=0; 11>k; k++){
			if(t2_prs[k]>0) t2_prs[k]=tm2.getPrFromNumber(t2_prs[k]).getId();
		}
        
		for(int k=0; 3>k; k++){
			if(t1_tvz[k]>0) t1_tvz[k]=tm1.getPrFromNumber(t1_tvz[k]).getId();
		}
		for(int k=0; 3>k; k++){
			if(t2_tvz[k]>0) t2_tvz[k]=tm2.getPrFromNumber(t2_tvz[k]).getId();
		}
        
		for(int k=0; 2>k; k++){
			if(mom[k][0]>0){
				if(mom[k][1]==1) mom[k][0]=tm1.getPrFromNumber(mom[k][0]).getId();
				else if(mom[k][1]==2) mom[k][0]=tm2.getPrFromNumber(mom[k][0]).getId();
			}
		}
        
		for(int k=0; 28>k; k++){
			if(cards[k][3]>0){
				if(cards[k][0]==1) cards[k][3]=tm1.getPrFromNumber(cards[k][3]).getId();
				if(cards[k][0]==2) cards[k][3]=tm2.getPrFromNumber(cards[k][3]).getId();
			}
		}
        
		for(int k=0; 30>k; k++){
			if(goals[k][2]>0){
				if(goals[k][0]==1) goals[k][2]=tm1.getPrFromNumber(goals[k][2]).getId();
				if(goals[k][0]==2) goals[k][2]=tm2.getPrFromNumber(goals[k][2]).getId();
			}
			
			if(goals[k][3]>0){
				if(goals[k][0]==1) goals[k][3]=tm1.getPrFromNumber(goals[k][3]).getId();
				if(goals[k][0]==2) goals[k][3]=tm2.getPrFromNumber(goals[k][3]).getId();
			}
		}
	}
        
	void convertIDToNumbers(team tm1,team tm2){
		for(int k=0; 11>k; k++){
			if(t1_prs[k]>0) t1_prs[k]=tm1.getPrFromId(t1_prs[k]).getNumber();
		}
		
		for(int k=0; 11>k; k++){
			if(t2_prs[k]>0) t2_prs[k]=tm2.getPrFromId(t2_prs[k]).getNumber();
		}
        
		for(int k=0; 3>k; k++){
			if(t1_tvz[k]>0) t1_tvz[k]=tm1.getPrFromId(t1_tvz[k]).getNumber();
		}
		
		for(int k=0; 3>k; k++){
			if(t2_tvz[k]>0) t2_tvz[k]=tm2.getPrFromId(t2_tvz[k]).getNumber();
		}
        
		for(int k=0; 2>k; k++){
			if(mom[k][0]>0){
				if(mom[k][1]==1) mom[k][0]=tm1.getPrFromId(mom[k][0]).getNumber();
				else if(mom[k][1]==2) mom[k][0]=tm2.getPrFromId(mom[k][0]).getNumber();
			}
		}
        
		for(int k=0; 28>k; k++){
			if(cards[k][3]>0){
				if(cards[k][0]==1) cards[k][3]=tm1.getPrFromId(cards[k][3]).getNumber();
				if(cards[k][0]==2) cards[k][3]=tm2.getPrFromId(cards[k][3]).getNumber();
			}
		}
        
		for(int k=0; 30>k; k++){
			if(goals[k][2]>0){
				if(goals[k][0]==1) goals[k][2]=tm1.getPrFromId(goals[k][2]).getNumber();
				if(goals[k][0]==2) goals[k][2]=tm2.getPrFromId(goals[k][2]).getNumber();
			}
			if(goals[k][3]>0){
				if(goals[k][0]==1) goals[k][3]=tm1.getPrFromId(goals[k][3]).getNumber();
				if(goals[k][0]==2) goals[k][3]=tm2.getPrFromId(goals[k][3]).getNumber();
			}
		}
	}
        
		
	void input_game(team tm1,team tm2,inputProfile& inpSettings){
		if(inpSettings.getDate()) set_date();
		else setUkDate();
                
		set_goals(tm1,tm2);
                
		if(inpSettings.getStats()){
			set_possess_shots(tm1,tm2);
			set_fouls_corners(tm1,tm2);
			set_fk_passc_cross(tm1,tm2);
			set_ic_tackle_save(tm1,tm2);
		}
		else setUkStats();
            
		if(inpSettings.getAreas()) setAttackingAreas(tm1,tm2);
		else setUkAttackingAreas();
                
		if(inpSettings.getPlayers()){
			setFirstLineup(tm1);
			setFirstLineup(tm2);
			setSubLineup(tm1);
			setSubLineup(tm2);
		}
		else setUkPlayers();
            
		if(inpSettings.getOveralls()) setOverallPrs(tm1,tm2);
		else setUkOveralls();
                
		if(inpSettings.getGoals()) set_goals_scorers(tm1,tm2,inpSettings); else setUkGoalsScorers();
		if(inpSettings.getNumCards()) set_tcards(tm1,tm2); else setUkNumCards();
		if(inpSettings.getCards()) set_cards(tm1,tm2,inpSettings); else setUkCards();
		if(inpSettings.getMom()) set_mom(tm1,tm2,inpSettings); else setUkMom();
		if(inpSettings.getConf()) set_conf(tm1,tm2); else setNoConf();
                
		convertNumbersToID(tm1,tm2);
		exist=1;
		IS_SAVED=false;
		cout<<endl; setColor("BOLDGREEN"); cout<<"Game Entered Succsessfuly.\n"; setColor("RESET");
	}
        
	void setUkDate(){
		year=-2;
		month=-2;
		day=-2;
	}
        
	void setUkStats(){
		t1_possess=-2; t2_possess=-2;
		for(int i=0; 2>i; i++) t1_shots[i]=-2;
		for(int i=0; 2>i; i++) t2_shots[i]=-2;
		for(int i=0; 2>i; i++) t1_fouls[i]=-2;
		for(int i=0; 2>i; i++) t2_fouls[i]=-2;
		t1_corners=-2; t2_corners=-2; t1_fk=-2; t2_fk=-2;
		t1_pass_c=-2; t2_pass_c=-2; t1_cross=-2; t2_cross=-2; t1_interc=-2; t2_interc=-2;
		t1_tackles=-2; t2_tackles=-2; t1_saves=-2; t2_saves=-2;
	}
        
	void setUkAttackingAreas(){
		t1_left=-2; t1_center=-2; t1_right=-2;
		t2_left=-2; t2_center=-2; t2_right=-2;
	}
        
	void setUkPlayers(){
		for(int i=0; 11>i; i++) t1_prs[i]=-2;
		for(int i=0; 11>i; i++) t2_prs[i]=-2;
		t1_tt=-2; t2_tt=-2;
		for(int i=0; 3>i; i++) t1_tvz[i]=-2;
		for(int i=0; 3>i; i++) t2_tvz[i]=-2;
	}
        
	void setUkOveralls(){
		for(int i=0; 11>i; i++){
			if(t1_prs[i]>0) t1_pov[i]=-2;
			else t1_pov[i]=-1;
		}
		
		for(int i=0; 11>i; i++){
			if(t2_prs[i]>0) t2_pov[i]=-2;
			else t2_pov[i]=-1;
		}
		
		for(int i=0; 3>i; i++){
			if(t1_tvz[i]>0) t1_tov[i]=-2;
			else t1_tov[i]=-1;
		}
		
		for(int i=0; 3>i; i++){
			if(t2_tvz[i]>0) t2_tov[i]=-2;
			else t2_tov[i]=-1;
		}
	}
        
	void setUkGoalsScorers(){	
		for(int i=0; tg>i; i++) for(int j=0; 5>j; j++) goals[i][j]=-2;
		for(int i=tg; 30>i; i++) for(int j=0; 5>j; j++) goals[i][j]=-1;
	}
        
	void setUkNumCards(){
		for(int i=0; 3>i; i++) t1_tc[i]=-2;
		for(int i=0; 3>i; i++) t2_tc[i]=-2;
	}
        
	void setUkCards(){
		if(tcards==-2){
			for(int i=0; 28>i; i++) for(int j=0; 5>j; j++) cards[i][j]=-2;
		}
		
		else{
			for(int i=0; tcards>i; i++) for(int j=0; 5>j; j++) cards[i][j]=-2;
			for(int i=tcards; 28>i; i++) for(int j=0; 5>j; j++) cards[i][j]=-2;
		}
	}
        
	void setUkMom(){
		for(int i=0; 2>i; i++) mom[0][i]=-2;
		for(int i=0; 2>i; i++) mom[1][i]=-2;
	}
        
	void setNoConf(){
		t1_conf[0]=0;
		t2_conf[0]=0;
	}
        
	bool editGame(team tm1,team tm2){
		inputProfile inpSettings;
            
		convertIDToNumbers(tm1,tm2);
            
		while(true){
			int num=0;
			int choice;
			cout<<endl;
			boldRedPrint("Edit Game:\n");
			cout<<++num<<": Date\n";
			cout<<++num<<": Result\n";
			cout<<++num<<": Possession and Shots\n";
			cout<<++num<<": Fouls And Corners\n";
			cout<<++num<<": Free Kicks, Pass Completed And Crosses\n";
			cout<<++num<<": Interception, Tackles And Saves\n";
			cout<<++num<<": Attacking Areas\n";
			cout<<++num<<": "<<tm1.getName()<<" First Line Up\n";
			cout<<++num<<": "<<tm1.getName()<<" Substitution\n";
			cout<<++num<<": "<<tm2.getName()<<" First Line Up\n";
			cout<<++num<<": "<<tm2.getName()<<" Substitution\n";
			cout<<++num<<": Players Overall Ratings\n";
			cout<<++num<<": Goals Scorers\n";
			cout<<++num<<": Number of Cards\n";
			cout<<++num<<": Cards Details\n";
			cout<<++num<<": Man of the Match\n";
			cout<<++num<<": Conference\n";
			cout<<++num<<": Delete Game\n";
			cout<<++num<<": Back to Recent Menu\n";
			cout<<endl<<"Enter Your Choice To Edit: ";
			choice=inputChoice(1,num);
                
			if(choice==1){
				set_date(true);
			}
                
			else if(choice==2){
				set_goals(tm1,tm2,true);
				set_goals_scorers(tm1,tm2,inpSettings,false,true);
			}
                
			else if(choice==3){
				set_possess_shots(tm1,tm2,true);
			}

			else if(choice==4){
				set_fouls_corners(tm1,tm2,true);
			}
                
			else if(choice==5){
				set_fk_passc_cross(tm1,tm2,true);
			}
                
			else if(choice==6){
				set_ic_tackle_save(tm1,tm2,true);
			}
                
			else if(choice==7){
				setAttackingAreas(tm1,tm2,true);
			}
                
			else if(choice==8){
				setLineup(tm1,true,true);
			}
                
			else if(choice==9){
				setLineup(tm1,false,true);
			}
                
			else if(choice==10){
				setLineup(tm2,true,true);
			}
                
			else if(choice==11){
				setLineup(tm2,false,true);
			}
                
			else if(choice==12){
				setOverallPrs(tm1,tm2,true);
			}
                
			else if(choice==13){
				if(tg==0){
					cout<<endl<<"This Game Does not have a Goal\n";
					continue;
				}
                    
				set_goals_scorers(tm1,tm2,inpSettings,true,false);
			}
                
			else if(choice==14){
				set_tcards(tm1,tm2,true);
				set_cards(tm1,tm2,inpSettings,false,true);
			}
                
			else if(choice==15){
				if(tcards==0){
					cout<<endl<<"This Game Does not have a Card!\n";
					continue;
				}
				
				else if(tcards==-2){
					cout<<endl<<"Number of Cards is Unknown!\n";
					continue;
				}
                    
				set_cards(tm1,tm2,inpSettings,true,false);
			}
                
			else if(choice==16){
				set_mom(tm1,tm2,inpSettings,true,false);
			}
                
			else if(choice==17){
				set_conf(tm1,tm2,true);
			}
                
			else if(choice==18){
				convertNumbersToID(tm1,tm2);
				return false;
			}
                
			else if(choice==19){
				convertNumbersToID(tm1,tm2);
				return true;
			}
                
                
			if(choice>=8 && choice<=11){
				bool singleCardError=false;
				bool singleGoalError=false;
				for(int i=0; tg>i; i++){
					if(goalErrorAfterEdit(i,tm1,tm2)){
						singleGoalError=true;
						break;
					} 
				
					
				}
				for(int i=0; tcards>i; i++){
					if(cardErrorAfterEdit(i,tm1,tm2)){
						singleCardError=true;
						break;
					} 
				}
                    
				if(singleGoalError){
					cout<<endl;
					printError("Your Edit Cause Error in Goals Scorers Session\n");
					cout<<endl;
					setColor("BOLDBLUE");
					cout<<"Goals:\n";
					setColor("RESET");
					for(int i=0; tg>i; i++){
						if(goalErrorAfterEdit(i,tm1,tm2)){
							setColor("BOLDRED");
							printGoal(i,tm1,tm2,inpSettings);
						}
						else{
							setColor("BOLDBLUE");
							printGoal(i,tm1,tm2,inpSettings);
						}
						setColor("RESET");
					}
					cout<<endl;
						
					for(int i=0; tg>i; i++){
						if(goalErrorAfterEdit(i,tm1,tm2)){
							cout<<"Goal "<<i+1<<": ";
							enterGoal(i,tm1,tm2,inpSettings,true);
						}
					}
					set_goals_scorers(tm1,tm2,inpSettings,false,true);
				}
                    
				if(singleCardError){
					cout<<endl;
					printError("Your Edit Cause Error in Cards Details Session\n");
					cout<<endl;
					setColor("BOLDBLUE");
					cout<<"Cards:\n";
					setColor("RESET");
					for(int i=0; tcards>i; i++){
						if(cardErrorAfterEdit(i,tm1,tm2)){
							setColor("BOLDRED");
							printCard(i,tm1,tm2,inpSettings);
						}
						else{
							setColor("BOLDBLUE");
							printCard(i,tm1,tm2,inpSettings);
						}
						setColor("RESET");
					}
					cout<<endl;
                        
					for(int i=0; tcards>i; i++){
						if(cardErrorAfterEdit(i,tm1,tm2)){
							cout<<"Card "<<i+1<<": ";
							enterCard(i,tm1,tm2,inpSettings,true);
						}
					}
					set_cards(tm1,tm2,inpSettings,false,true);
				}
                    set_mom(tm1,tm2,inpSettings,false,true);
			}
		}
	}
            
        
	void showConf(team tm,int terLength,int terMarigin, int confMarigin){
		char *conf;
		
		if(tm.sendid()==1) conf=t1_conf;
		else if(tm.sendid()==2) conf=t2_conf;
		else throw -1;
            
		int lineLength=terLength-(2*confMarigin)-2;
            
		space(terMarigin);
		setColor("BOLDBLUE");
		cout<<"|";
		setColor("RESET");
		space(confMarigin);
            
		int nameLen;
		for(nameLen=0; tm.getName()[nameLen]!=0; nameLen++);
            
		if(tm.sendid()==1) setColor("BOLDMAGENTA");
		else if(tm.sendid()==2) setColor("BOLDCYAN");
		cout<<tm.getName()<<": ";
		setColor("RESET");
            
		int lineL=nameLen+2;
            
		int i;
		for(i=0; conf[i]!=0; i++){
			char vocab[50];
			for(int m=0; 50>m; m++) vocab[m]=0;
			int k;
			if(conf[i]==' '){
				vocab[0]=' ';
				k=1;
			}
			
			else{
				int j;
				for(j=i,k=0; conf[j]!=' ' && conf[j]!=0; j++,k++){
					vocab[k]=conf[j];
				}
				vocab[k]=0;
			}

			if(lineL+k<=lineLength){
				cout<<vocab;
				lineL+=k;
			}
			else{
				space(lineLength-lineL);
				space(confMarigin);
				setColor("BOLDBLUE");
				cout<<"|";
				setColor("RESET");
				cout<<endl;
				space(terMarigin);
				setColor("BOLDBLUE");
				cout<<"|";
				setColor("RESET");
				space(confMarigin);
				cout<<vocab;
				lineL=k;
			}
			
			i+=(k-1);
		}
		space(lineLength-lineL);
		space(confMarigin);
		setColor("BOLDBLUE");
		cout<<"|";
		setColor("RESET");
	}

	void showAllConfs(team tm1,team tm2,int scrLength,int terLength,int terMarigin, int confMarigin){
		if(t1_conf[0]==0 && t2_conf[0]==0) return;
	
		cout<<endl;
		cout<<endl;
		setColor("BOLDBLUE"); beforeStrWhere("Conferences",scrLength); setColor("RESET");
		if(t1_conf[0]!=0){
			cout<<endl;
			space(terMarigin);
			setColor("BOLDBLUE");
			cadr_dash(terLength);
			setColor("RESET");
			showConf(tm1,terLength,terMarigin,confMarigin);
		}
            
		if(t2_conf[0]!=0){
			cout<<endl;
			space(terMarigin);
			setColor("BOLDBLUE");
			cadr_dash(terLength);
			setColor("RESET");
			showConf(tm2,terLength,terMarigin,confMarigin);
		}
            
		cout<<endl;
		space(terMarigin);
		setColor("BOLDBLUE");
		cadr_dash(terLength);
		setColor("RESET");

	}
        
	void show(team,team);
	//void print_goals(team,team);
	void update_after_game(team &,team &,bool silent=false);
	friend class competition;
	friend void add_game(match *,team &,team &);
	//friend void print_all_goals(match *m,team tm1,team tm2);
};



class competition{
	team teamOne;
	team teamTwo;
	match games[200];
        
	
	int * getStreak(team tm,int state){
		//state:    1:Unbeaten Streak | 2:Winning Streak
		if(state!=1 && state!=2) throw -1;
		
		int start;
		int streak=0;
		int * maxStreak;
		maxStreak=new int[3];    //0:Streak | 1:Start | 2:End
		for(int i=0; 3>i; i++) maxStreak[i]=0;
		
		for(int i=0; games[i].sendexist() && 200>i; i++){
			if(streak==0) start=i;
			if(games[i].getResult()==tm.sendid() || (state==1 && games[i].getResult()==3)) streak++;
			else{
				if(streak>maxStreak[0]){
					maxStreak[0]=streak;
					maxStreak[1]=start;
					maxStreak[2]=i-1;
				}
				streak=0;
			}
		}
		
		return maxStreak;
	}
	
	int getNumGames(){
		int num;
		for(num=0; games[num].sendexist(); num++);
		return num;
	}
		
	int * getUnbeatenStreak(team tm){
		return getStreak(tm,1);
	}
	
	int * getWinningStreak(team tm){
		return getStreak(tm,2);
	}
	
	void printStreak(int *streak){
		if(streak[0]==0) cout<<"0 Match";
		else if(streak[0]==1) cout<<"1 Match | Game "<<streak[1]+1;
		else if(streak[0]>1) cout<<streak[0]<<" Match | Games: ["<<streak[1]+1<<","<<streak[2]+1<<"]";
		 setColor("RESET");
	}
	
	
	//competition(){}
	public:
	competition(team t1,team t2,match m[200]){
		teamOne=t1;
		teamTwo=t2;
		for(int i=0; 200>i; i++) games[i]=m[i];
	}
	
	int ** getAllGoals(){
		int tg=0;
		for(int i=0; games[i].sendexist() && 200>i; i++) tg+=games[i].dynamicGet("tg");
		int **goals;
		goals=new int *[tg];
		for(int i=0; tg>i; i++) goals[i]=new int[6];
		if(tg==0){
			goals[0][0]=0;
			return goals;
		}
		for(int i=0,j=0; games[i].sendexist() && 200>i; i++){
			int **scores;
			scores=games[i].getGoals();
			for(int k=0; games[i].dynamicGet("tg")>k; k++,j++){
				goals[j][0]=i;
				for(int m=1; 5>=m; m++) goals[j][m]=scores[k][m-1];
			}
		}
		return goals;
	}
	
	void WinnerAgLooser(){
        stringstream temp1;
        stringstream temp2;
        stringstream temp3;
        stringstream temp4;
        stringstream temp5;
        stringstream temp6;
                
		int numGames[13];
		char winName[40];
		char looseName[40];
		strcpy(winName,"Winner");
		strcpy(looseName,"Looser");
		teamGameStat win(winName,0);
		teamGameStat loose(looseName,0);
		
		for(int i=0; 13>i; i++) numGames[i]=0;
		//0: Goals
		//1: Possess
		//2: Shots
		//3: Fouls
		//4: Corners
		//5: Free Kicks
		//6: Passes Completed
		//7: Crosses
		//8: Interception
		//9: Tackles
		//10: Saves
		//11: TCards
		//12: TSubs
		
		for(int i=0; 200>i && games[i].exist==true; i++){
			if(games[i].res>2) continue;
			
			if(games[i].res==1){
				if(games[i].t1_goals>=0 && games[i].t2_goals>=0){
					win.nGoals+=games[i].t1_goals;
					loose.nGoals+=games[i].t2_goals;
					numGames[0]++;
				}
				
				if(games[i].t1_possess>=0 && games[i].t2_possess>=0){
					win.possess+=games[i].t1_possess;
					loose.possess+=games[i].t2_possess;
					numGames[1]++;
				}
				
				if(games[i].t1_shots[0]>=0 && games[i].t1_shots[1]>=0 && games[i].t2_shots[0]>=0 && games[i].t2_shots[1]>=0){
					win.shots[0]+=games[i].t1_shots[0]; win.shots[1]+=games[i].t1_shots[1];
					loose.shots[0]+=games[i].t2_shots[0]; loose.shots[1]+=games[i].t2_shots[1];
					numGames[2]++;
				}
				
				if(games[i].t1_fouls[0]>=0 && games[i].t1_fouls[1]>=0 && games[i].t2_fouls[0]>=0 && games[i].t2_fouls[1]>=0){
					win.fouls[0]+=games[i].t1_fouls[0]; win.fouls[1]+=games[i].t1_fouls[1];
					loose.fouls[0]+=games[i].t2_fouls[0]; loose.fouls[1]+=games[i].t2_fouls[1];
					numGames[3]++;
				}
				
				if(games[i].t1_corners>=0 && games[i].t2_corners>=0){
					win.corners+=games[i].t1_corners;
					loose.corners+=games[i].t2_corners;
					numGames[4]++;
				}
				
				if(games[i].t1_fk>=0 && games[i].t2_fk>=0){
					win.fk+=games[i].t1_fk;
					loose.fk+=games[i].t2_fk;
					numGames[5]++;
				}
				
				if(games[i].t1_pass_c>=0 && games[i].t2_pass_c>=0){
					win.passC+=games[i].t1_pass_c;
					loose.passC+=games[i].t2_pass_c;
					numGames[6]++;
				}
				
				if(games[i].t1_cross>=0 && games[i].t2_cross>=0){
					win.cross+=games[i].t1_cross;
					loose.cross+=games[i].t2_cross;
					numGames[7]++;
				}
				
				if(games[i].t1_interc>=0 && games[i].t2_interc>=0){
					win.interc+=games[i].t1_interc;
					loose.interc+=games[i].t2_interc;
					numGames[8]++;
				}
				
				if(games[i].t1_tackles>=0 && games[i].t2_tackles>=0){
					win.tackles+=games[i].t1_tackles;
					loose.tackles+=games[i].t2_tackles;
					numGames[9]++;
				}
				
				if(games[i].t1_saves>=0 && games[i].t2_saves>=0){
					win.saves+=games[i].t1_saves;
					loose.saves+=games[i].t2_saves;
					numGames[10]++;
				}
				
				if(games[i].t1_tc[0]>=0 && games[i].t1_tc[1]>=0 && games[i].t2_tc[0]>=0 && games[i].t2_tc[1]>=0){
					win.nCards[0]+=games[i].t1_tc[0]; win.nCards[1]+=games[i].t1_tc[1];
					loose.nCards[0]+=games[i].t2_tc[0]; loose.nCards[1]+=games[i].t2_tc[1];
					numGames[11]++;
				}
				
				if(games[i].t1_tt>=0 && games[i].t2_tt>=0){
					win.nSub+=games[i].t1_tt;
					loose.nSub+=games[i].t2_tt;
					numGames[12]++;
				}
			}
			
			if(games[i].res==2){
				if(games[i].t1_goals>=0 && games[i].t2_goals>=0){
					win.nGoals+=games[i].t2_goals;
					loose.nGoals+=games[i].t1_goals;
					numGames[0]++;
				}
				
				if(games[i].t1_possess>=0 && games[i].t2_possess>=0){
					win.possess+=games[i].t2_possess;
					loose.possess+=games[i].t1_possess;
					numGames[1]++;
				}
				
				if(games[i].t1_shots[0]>=0 && games[i].t1_shots[1]>=0 && games[i].t2_shots[0]>=0 && games[i].t2_shots[1]>=0){
					win.shots[0]+=games[i].t2_shots[0]; win.shots[1]+=games[i].t2_shots[1];
					loose.shots[0]+=games[i].t1_shots[0]; loose.shots[1]+=games[i].t1_shots[1];
					numGames[2]++;
				}
				
				if(games[i].t1_fouls[0]>=0 && games[i].t1_fouls[1]>=0 && games[i].t2_fouls[0]>=0 && games[i].t2_fouls[1]>=0){
					win.fouls[0]+=games[i].t2_fouls[0]; win.fouls[1]+=games[i].t2_fouls[1];
					loose.fouls[0]+=games[i].t1_fouls[0]; loose.fouls[1]+=games[i].t1_fouls[1];
					numGames[3]++;
				}
				
				if(games[i].t1_corners>=0 && games[i].t2_corners>=0){
					win.corners+=games[i].t2_corners;
					loose.corners+=games[i].t1_corners;
					numGames[4]++;
				}
				
				if(games[i].t1_fk>=0 && games[i].t2_fk>=0){
					win.fk+=games[i].t2_fk;
					loose.fk+=games[i].t1_fk;
					numGames[5]++;
				}
				
				if(games[i].t1_pass_c>=0 && games[i].t2_pass_c>=0){
					win.passC+=games[i].t2_pass_c;
					loose.passC+=games[i].t1_pass_c;
					numGames[6]++;
				}
				
				if(games[i].t1_cross>=0 && games[i].t2_cross>=0){
					win.cross+=games[i].t2_cross;
					loose.cross+=games[i].t1_cross;
					numGames[7]++;
				}
				
				if(games[i].t1_interc>=0 && games[i].t2_interc>=0){
					win.interc+=games[i].t2_interc;
					loose.interc+=games[i].t1_interc;
					numGames[8]++;
				}
				
				if(games[i].t1_tackles>=0 && games[i].t2_tackles>=0){
					win.tackles+=games[i].t2_tackles;
					loose.tackles+=games[i].t1_tackles;
					numGames[9]++;
				}
				
				if(games[i].t1_saves>=0 && games[i].t2_saves>=0){
					win.saves+=games[i].t2_saves;
					loose.saves+=games[i].t1_saves;
					numGames[10]++;
				}
				
				if(games[i].t1_tc[0]>=0 && games[i].t1_tc[1]>=0 && games[i].t2_tc[0]>=0 && games[i].t2_tc[1]>=0){
					win.nCards[0]+=games[i].t2_tc[0]; win.nCards[1]+=games[i].t2_tc[1];
					loose.nCards[0]+=games[i].t1_tc[0]; loose.nCards[1]+=games[i].t1_tc[1];
					numGames[11]++;
				}
				
				if(games[i].t1_tt>=0 && games[i].t2_tt>=0){
					win.nSub+=games[i].t2_tt;
					loose.nSub+=games[i].t1_tt;
					numGames[12]++;
				}
			}
		}
		
		temp1.str("");
		cout<<endl;
		temp1<<"$$WHT"<<"Number of Games: "<<numGames[0]<<"$0RST";
		space(15); beforeStrWhere(temp1,44);  setColor("RESET");
		temp1.str("");
		win.convertToPerGame(numGames);
		loose.convertToPerGame(numGames);
		//cout<<endl<<"WinnerGoals: "<<win.nGoals<<" | LooserGoals: "<<loose.nGoals<<endl;
		showWALTable(win,loose,true,true);
	}
	
	bool existKnownData(const char * factor){
		for(int i=0; games[i].sendexist(); i++){
			if(games[i].dynamicGet(factor)!=-2) return true;
		}
		return false;
	}
	
	int getMaxMatchIndex(const char * factor){
		int max,index;
		max=games[0].dynamicGet(factor);
		index=0;
		for(int i=1; 200>i && games[i].sendexist(); i++){
			if(games[i].dynamicGet(factor)>max){
				max=games[i].dynamicGet(factor);
				index=i;
			}
			else if((strcasecmp(factor,"t1DifGoals")==0 || strcasecmp(factor,"t2DifGoals")==0) &&
			games[i].dynamicGet(factor)==max && games[i].dynamicGet("tg")>games[index].dynamicGet("tg")){
				index=i;
			}
		}
		if(max==-2) return -1;
		return index;
	}
	
	int** getFastestAndLatestGoal(){
		int tg=0;
		int ** twoGoals;
		twoGoals=new int*[2]; //0: Fastest | 1: Latest
		for(int i=0; 2>i; i++) twoGoals[i]=new int[6]; //fast[5] -> game Index
		
		for(int i=0; games[i].sendexist() && 200>i; i++) tg+=games[i].dynamicGet("tg");
		if(tg==0){
			twoGoals[0][0]=0;
			return twoGoals;
		}
		
		bool find=false;
		for(int i=0; games[i].sendexist() && 200>i; i++){
			int **scores;
			scores=games[i].getGoals();
			for(int j=0; games[i].dynamicGet("tg")>j; j++){
				if(scores[j][4]!=-2){
					if(find==false || scores[j][4]<twoGoals[0][4]){
						for(int k=0; 5>k; k++) twoGoals[0][k]=scores[j][k];
						twoGoals[0][5]=i;
					}
					
					if(find==false || scores[j][4]>twoGoals[1][4]){
						for(int k=0; 5>k; k++) twoGoals[1][k]=scores[j][k];
						twoGoals[1][5]=i;
					}
					
					if(!find) find=true;
				}
			}
		}
		return twoGoals;
	}
	
	
	void printMost(){
		if(!games[0].sendexist()) cout<<endl<<"Mosabeghe ei sabt nashode ast!"<<endl;
		else if(teamOne.sendid()==2 && teamTwo.sendid()==1) cout<<endl<<"Error in Teams Order"<<endl;
		else{
			int index;
			cout<<endl; setColor("BOLDRED"); cout<<"Most Stats: "; setColor("RESET"); cout<<endl;
			
			cout<<endl; setColor("BOLDBLUE"); cout<<"Highest Scoring Game: ";
			index=getMaxMatchIndex("tg");
			cout<<teamOne.getName()<<" "<<games[index].dynamicGet("t1_goals")<<" - "<<games[index].dynamicGet("t2_goals")<<" "<<teamTwo.getName()
			<<" | Game "<<index+1; setColor("RESET");
			
			cout<<endl; setColor("BOLDBLUE"); cout<<"Most Cards In a Game: ";
			index=getMaxMatchIndex("tcards");
			cout<<games[index].dynamicGet("tcards")<<" Cards"
			<<" | Game "<<index+1; setColor("RESET");
			
			
			int ** twoGoals=getFastestAndLatestGoal();
			if(twoGoals[0][0]!=0){
				int *fast=twoGoals[0];
				cout<<endl; setColor("BOLDBLUE"); cout<<"Fastest Goal: ";
				
				if(fast[0]==1){
					setColor("BOLDMAGENTA");
					if(fast[2]==-2) cout<<"UK"; else if(fast[2]==-1) cout<<"OG"; else cout<<teamOne.getPrFromId(fast[2]).sendname();
					if(fast[3]!=-1 && fast[3]!=-2) cout<<" ("<<teamOne.getPrFromId(fast[3]).sendname()<<")";
					else if(fast[3]==-1) cout<<" (WA)";
					cout<<" Minute "<<fast[4];
				}
				
				else if(fast[0]==2){
					setColor("BOLDCYAN");
					if(fast[2]==-2) cout<<"UK"; else if(fast[2]==-1) cout<<"OG"; else cout<<teamTwo.getPrFromId(fast[2]).sendname();
					if(fast[3]!=-1 && fast[3]!=-2) cout<<" ("<<teamTwo.getPrFromId(fast[3]).sendname()<<")";
					else if(fast[3]==-1) cout<<" (WA)";
					cout<<" Minute "<<fast[4];
				}
				cout<<" | Game "<<fast[5]+1; setColor("RESET");
				
				int *latest=twoGoals[1];
				cout<<endl; setColor("BOLDBLUE"); cout<<"Latest Goal: ";
				if(latest[0]==1){
					setColor("BOLDMAGENTA");
					if(fast[2]==-2) cout<<"UK"; else if(fast[2]==-1) cout<<"OG"; else cout<<teamOne.getPrFromId(latest[2]).sendname();
					if(latest[3]!=-1 && latest[3]!=-2) cout<<" ("<<teamOne.getPrFromId(latest[3]).sendname()<<")";
					else if(latest[3]==-1) cout<<" (WA)";
					cout<<" Minute "<<latest[4];
				}
				
				else if(latest[0]==2){
					setColor("BOLDCYAN");
					if(fast[2]==-2) cout<<"UK"; else if(fast[2]==-1) cout<<"OG"; else cout<<teamTwo.getPrFromId(latest[2]).sendname();
					if(latest[3]!=-1 && latest[3]!=-2) cout<<" ("<<teamTwo.getPrFromId(latest[3]).sendname()<<")";
					else if(latest[3]==-1) cout<<" (WA)";
					cout<<" Minute "<<latest[4];
				}
				cout<<" | Game "<<latest[5]+1; setColor("RESET"); cout<<endl;
				
			}
			
			cout<<endl; setColor("BOLDBLUE"); cout<<"Best Result:"; setColor("RESET");
			
			cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
			index=getMaxMatchIndex("t1DifGoals");
			cout<<teamOne.getName()<<" "<<games[index].dynamicGet("t1_goals")<<" - "<<games[index].dynamicGet("t2_goals")<<" "<<teamTwo.getName()
			<<" | Game "<<index+1; setColor("RESET");
			
			cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
			index=getMaxMatchIndex("t2DifGoals");
			cout<<teamOne.getName()<<" "<<games[index].dynamicGet("t1_goals")<<" - "<<games[index].dynamicGet("t2_goals")<<" "<<teamTwo.getName()
			<<" | Game "<<index+1; setColor("RESET");
			
			cout<<endl;
			
			cout<<endl; setColor("BOLDBLUE"); cout<<"Unbeaten Streak:"; setColor("RESET");
			int *streak;
			
			cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
			streak=getUnbeatenStreak(teamOne);
			printStreak(streak);
			
			cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
			streak=getUnbeatenStreak(teamTwo);
			printStreak(streak);
			
			cout<<endl;
			
			cout<<endl; setColor("BOLDBLUE"); cout<<"Winning Streak:"; setColor("RESET");
			
			cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
			streak=getWinningStreak(teamOne);
			printStreak(streak);
			
			cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
			streak=getWinningStreak(teamTwo);
			printStreak(streak);
			
			cout<<endl;
			
			if(existKnownData("t1_shotsOne") || existKnownData("t2_shotsOne")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Shots:"; setColor("RESET");
				
				if(existKnownData("t1_shotsOne")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_shotsOne");
					cout<<games[index].dynamicGet("t1_shotsOne")<<" Shots | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_shotsOne")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_shotsOne");
					cout<<games[index].dynamicGet("t2_shotsOne")<<" Shots | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_shotsTwo") || existKnownData("t2_shotsTwo")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max On Target Shots:"; setColor("RESET");
				
				if(existKnownData("t1_shotsTwo")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_shotsTwo");
					cout<<games[index].dynamicGet("t1_shotsTwo")<<" Shots | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_shotsTwo")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_shotsTwo");
					cout<<games[index].dynamicGet("t2_shotsTwo")<<" Shots | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_possess") || existKnownData("t2_possess")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Possession:"; setColor("RESET");
				
				if(existKnownData("t1_possess")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_possess");
					cout<<games[index].dynamicGet("t1_possess")<<" % | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_possess")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_possess");
					cout<<games[index].dynamicGet("t2_possess")<<" % | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_pass_c") || existKnownData("t2_pass_c")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Pass Completed:"; setColor("RESET");
				
				if(existKnownData("t1_pass_c")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_pass_c");
					cout<<games[index].dynamicGet("t1_pass_c")<<" % | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_pass_c")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_pass_c");
					cout<<games[index].dynamicGet("t2_pass_c")<<" % | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_interc") || existKnownData("t2_interc")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Interception:"; setColor("RESET");
				
				if(existKnownData("t1_interc")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_interc");
					cout<<games[index].dynamicGet("t1_interc")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_interc")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_interc");
					cout<<games[index].dynamicGet("t2_interc")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_saves") || existKnownData("t2_saves")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Saves:"; setColor("RESET");
				
				if(existKnownData("t1_saves")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_saves");
					cout<<games[index].dynamicGet("t1_saves")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_saves")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_saves");
					cout<<games[index].dynamicGet("t2_saves")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_cross") || existKnownData("t2_cross")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Crosses:"; setColor("RESET");
				
				if(existKnownData("t1_cross")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_cross");
					cout<<games[index].dynamicGet("t1_cross")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_cross")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_cross");
					cout<<games[index].dynamicGet("t2_cross")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_corners") || existKnownData("t2_corners")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Corners:"; setColor("RESET");
				
				if(existKnownData("t1_corners")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_corners");
					cout<<games[index].dynamicGet("t1_corners")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_corners")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_corners");
					cout<<games[index].dynamicGet("t2_corners")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_fk") || existKnownData("t2_fk")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Free Kick:"; setColor("RESET");
				
				if(existKnownData("t1_fk")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_fk");
					cout<<games[index].dynamicGet("t1_fk")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_fk")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_fk");
					cout<<games[index].dynamicGet("t2_fk")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
			
			if(existKnownData("t1_foulsOne") || existKnownData("t2_foulsOne")){
				cout<<endl; setColor("BOLDBLUE"); cout<<"Max Fouls:"; setColor("RESET");
				
				if(existKnownData("t1_foulsOne")){
					cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<": ";
					index=getMaxMatchIndex("t1_foulsOne");
					cout<<games[index].dynamicGet("t1_foulsOne")<<" | Game "<<index+1; setColor("RESET");
				}
				
				if(existKnownData("t2_foulsOne")){
					cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<": ";
					index=getMaxMatchIndex("t2_foulsOne");
					cout<<games[index].dynamicGet("t2_foulsOne")<<" | Game "<<index+1; setColor("RESET");
				}
				
				cout<<endl;
			}
		}
	}
	
	int getNumAbsValues(const char * factor){
		int num=0;
		for (int i=0; games[i].sendexist(); i++){
			if(games[i].dynamicGet(factor)!=-2) num++;
		}
		return num;
	}
	
	int getSumValues(const char * factor){
		int sum=0;
		for (int i=0; games[i].sendexist(); i++){
			if(games[i].dynamicGet(factor)!=-2) sum+=games[i].dynamicGet(factor);
		}
		return sum;
	}
	
	void compare(double m1,double m2,int s,int h=0){
		for(int i=0; s>i; i++) cout<<" ";
		if(h==0){
			if(m1>m2){ setColor("BOLDGREEN"); cout<<teamOne.name<<": "<<setprecision(2)<<m1; setColor("RESET"); cout<<" | "<<teamTwo.name<<": "<<setprecision(2)<<m2<<endl;}
			else if(m1<m2){ cout<<teamOne.name<<": "<<setprecision(2)<<m1<<" | "; setColor("BOLDGREEN"); cout<<teamTwo.name<<": "<<setprecision(2)<<m2; setColor("RESET"); cout<<endl;}
			else if(m1==m2){ cout<<teamOne.name<<": "<<setprecision(2)<<m1<<" | "<<teamTwo.name<<": "<<setprecision(2)<<m2<<endl;}
		}
		else{
			if(m1<m2){ setColor("BOLDGREEN"); cout<<teamOne.name<<": "<<setprecision(2)<<m1; setColor("RESET"); cout<<" | "<<teamTwo.name<<": "<<setprecision(2)<<m2<<endl;}
			else if(m1>m2){ cout<<teamOne.name<<": "<<setprecision(2)<<m1<<" | "; setColor("BOLDGREEN"); cout<<teamTwo.name<<": "<<setprecision(2)<<m2; setColor("RESET"); cout<<endl;}
			else if(m1==m2){ cout<<teamOne.name<<": "<<setprecision(2)<<m1<<" | "<<teamTwo.name<<": "<<setprecision(2)<<m2<<endl;}
		}
	}
	
	void compareTeams(){
		int oneNumber,twoNumber, altOneNumber, altTwoNumber;
		cout<<endl<<teamOne.name<<" Against "<<teamTwo.name<<endl;
		cout<<"Apps: "<<teamOne.apps<<endl<<endl;
		cout<<"Wins Percent: "; compare((double)teamOne.wins/teamOne.apps*100,(double)teamTwo.wins/teamTwo.apps*100,23);
		cout<<"Goals Per Game: "; compare((double)teamOne.goals/teamOne.apps,(double)teamTwo.goals/teamTwo.apps,21);
		
		oneNumber=getNumAbsValues("t1YC"); twoNumber=getNumAbsValues("t2YC");
		cout<<"Yellow Cards Per Game: "; compare((double)teamOne.yc/oneNumber,(double)teamTwo.yc/twoNumber,14,1);
		
		oneNumber=getNumAbsValues("t1RC"); twoNumber=getNumAbsValues("t2RC");
		cout<<"Red Cards Per Game: "; compare((double)teamOne.rc/oneNumber,(double)teamTwo.rc/twoNumber,17,1);
		
		oneNumber=getNumAbsValues("t1_possess"); twoNumber=getNumAbsValues("t2_possess");
		cout<<"Possession Per Game: "; compare((double)teamOne.possess/oneNumber,(double)teamTwo.possess/twoNumber,16);
		
		oneNumber=getNumAbsValues("t1_shotsOne"); twoNumber=getNumAbsValues("t2_shotsOne");
		altOneNumber=getNumAbsValues("t1_shotsTwo"); altTwoNumber=getNumAbsValues("t2_shotsTwo");
		cout<<"Shots(On Target) Per Game: ";
		if(teamOne.shots[0]+teamOne.shots[1]>teamTwo.shots[0]+teamTwo.shots[1]){ cout<<"          "; setColor("BOLDGREEN"); cout<<teamOne.name<<": "<<setprecision(2)<<(double)teamOne.shots[0]/oneNumber<<"("<<setprecision(2)<<(double)teamOne.shots[1]/altOneNumber<<")"; setColor("RESET"); cout<<" | "<<teamTwo.name<<": "<<setprecision(2)<<(double)teamTwo.shots[0]/twoNumber<<"("<<setprecision(2)<<(double)teamTwo.shots[1]/altTwoNumber<<")"<<endl;}
		else if(teamOne.shots[0]+teamOne.shots[1]<teamTwo.shots[0]+teamTwo.shots[1]){ cout<<"          "<<teamOne.name<<": "<<setprecision(2)<<(double)teamOne.shots[0]/oneNumber<<"("<<setprecision(2)<<(double)teamOne.shots[1]/altOneNumber<<")"<<" | "; setColor("BOLDGREEN"); cout<<teamTwo.name<<": "<<setprecision(2)<<(double)teamTwo.shots[0]/twoNumber<<"("<<setprecision(2)<<(double)teamTwo.shots[1]/altTwoNumber<<")"; setColor("RESET"); cout<<endl;}
		else if(teamOne.shots[0]+teamOne.shots[1]==teamTwo.shots[0]+teamTwo.shots[1]){ cout<<"          "<<teamOne.name<<": "<<setprecision(2)<<(double)teamOne.shots[0]/oneNumber<<"("<<setprecision(2)<<(double)teamOne.shots[1]/altOneNumber<<")"<<" | "<<teamTwo.name<<": "<<setprecision(2)<<(double)teamTwo.shots[0]/twoNumber<<"("<<setprecision(2)<<(double)teamTwo.shots[1]/altTwoNumber<<")"<<endl;}
		
		oneNumber=getNumAbsValues("t1_foulsOne"); twoNumber=getNumAbsValues("t2_foulsOne");
		altOneNumber=getNumAbsValues("t1_foulsTwo"); altTwoNumber=getNumAbsValues("t2_foulsTwo");
		cout<<"Fouls(Offside) Per Game: ";
		if(teamOne.fouls[0]<teamTwo.fouls[0]){ cout<<"            "; setColor("BOLDGREEN"); cout<<teamOne.name<<": "<<(double)teamOne.fouls[0]/oneNumber<<"("<<(double)teamOne.fouls[1]/altOneNumber<<")"; setColor("RESET"); cout<<" | "<<teamTwo.name<<": "<<(double)teamTwo.fouls[0]/twoNumber<<"("<<(double)teamTwo.fouls[1]/altTwoNumber<<")"<<endl;}
		if(teamOne.fouls[0]>teamTwo.fouls[0]){ cout<<"            "<<teamOne.name<<": "<<(double)teamOne.fouls[0]/oneNumber<<"("<<(double)teamOne.fouls[1]/altOneNumber<<")"<<" | "; setColor("BOLDGREEN"); cout<<teamTwo.name<<": "<<(double)teamTwo.fouls[0]/twoNumber<<"("<<(double)teamTwo.fouls[1]/altTwoNumber<<")"; setColor("RESET"); cout<<endl;}
		if(teamOne.fouls[0]==teamTwo.fouls[0]){ cout<<"            "<<teamOne.name<<": "<<(double)teamOne.fouls[0]/oneNumber<<"("<<(double)teamOne.fouls[1]/altOneNumber<<")"<<" | "<<teamTwo.name<<": "<<(double)teamTwo.fouls[0]/twoNumber<<"("<<(double)teamTwo.fouls[1]/altTwoNumber<<")"<<endl;}
		
		oneNumber=getNumAbsValues("t1_corners"); twoNumber=getNumAbsValues("t2_corners");
		cout<<"Corners Per Game: "; compare((double)teamOne.corners/oneNumber,(double)teamTwo.corners/twoNumber,19);
		
		oneNumber=getNumAbsValues("t1_fk"); twoNumber=getNumAbsValues("t2_fk");
		cout<<"Free Kicks Per Game: "; compare((double)teamOne.fk/oneNumber,(double)teamTwo.fk/twoNumber,16);
		
		oneNumber=getNumAbsValues("t1_pass_c"); twoNumber=getNumAbsValues("t2_pass_c");
		cout<<"Pass Completed Per Game: "; compare((double)teamOne.pass_c/oneNumber,(double)teamTwo.pass_c/twoNumber,12); 
		
		oneNumber=getNumAbsValues("t1_cross"); twoNumber=getNumAbsValues("t2_cross");
		cout<<"Crosses Per Game: "; compare((double)teamOne.cross/oneNumber,(double)teamTwo.cross/twoNumber,19);
		
		oneNumber=getNumAbsValues("t1_interc"); twoNumber=getNumAbsValues("t2_interc");
		cout<<"Interception Per Game: "; compare((double)teamOne.interc/oneNumber,(double)teamTwo.interc/twoNumber,14);
		
		oneNumber=getNumAbsValues("t1_tackles"); twoNumber=getNumAbsValues("t2_tackles");
		cout<<"Tackles Per Game: "; compare((double)teamOne.tackles/oneNumber,(double)teamTwo.tackles/twoNumber,19);
		
		oneNumber=getNumAbsValues("t1_saves"); twoNumber=getNumAbsValues("t2_saves");
		cout<<"Saves Per Game: "; compare((double)teamOne.saves/oneNumber,(double)teamTwo.saves/twoNumber,21);
	}
	
	void printCompareGraph(double t1val,double t2val,int nStar){
		if(t1val==0 && t2val==0){
			for(int i=0; nStar>i; i++) cout<<"*";
			return;
		}
		
		double unit=(t1val+t2val)/nStar;
		int t1Star=t1val/unit;
		int t2Star=t2val/unit;
		double t1Ashar=(t1val/unit)-t1Star;
		double t2Ashar=(t2val/unit)-t2Star;
		bool whiteStar=(t1Ashar==t2Ashar && t1Ashar!=0);
		if(!whiteStar){
			if(t1Ashar>t2Ashar) t1Star++;
			else if(t2Ashar>t1Ashar) t2Star++;
		}
		setColor("BOLDMAGENTA");
		for(int i=0; t1Star>i; i++) cout<<"*";
		if(whiteStar){
			setColor("RESET");
			cout<<"*";
		}
		setColor("BOLDCYAN");
		for(int i=0; t2Star>i; i++) cout<<"*";
	}
	
	void printCompareFromFactors(const char*title,const char *t1_factor, const char *t2_factor,int s, int nStar,int valueLen,stringstream &cadr,bool printPH=false, bool fewBetter=false){
		stringstream t1SS,t2SS;
		int t1Sum,t2Sum;
		double t1Avg,t2Avg;
		
		if(strcmp(title,"Wins")==0){
			t1Avg=teamOne.getWins();
			t2Avg=teamTwo.getWins();
		}		
		else{
			if(existKnownData(t1_factor)){
				t1Sum=getSumValues(t1_factor);
				t1Avg=(double)t1Sum/getNumAbsValues(t1_factor);
			}
			else t1Avg=-2;
			
			if(existKnownData(t2_factor)){
				t2Sum=getSumValues(t2_factor);
				t2Avg=(double)t2Sum/getNumAbsValues(t2_factor);
			}
			else t2Avg=-2;
		}
			
		bool UKOne=false;
		bool UKTwo=false;
			
		if(t1Avg==-2){ t1SS<<"UK"; UKOne=true;}		
		if(t2Avg==-2){ t2SS<<"UK"; UKTwo=true;}
			
		if(!UKOne && !UKTwo){
			if((!fewBetter && t1Avg>t2Avg) || (fewBetter && t1Avg<t2Avg)) t1SS<<"$$GRN";
			else if((!fewBetter && t2Avg>t1Avg) || (fewBetter && t2Avg<t1Avg)) t2SS<<"$$GRN";
			t1SS<<setprecision(2)<<t1Avg;
			t2SS<<setprecision(2)<<t2Avg;
			if(printPH){
				t1SS<<"%";
				t2SS<<"%";
			}
		}
		else if(!UKOne){
			t1SS<<setprecision(2)<<t1Avg;
			if(printPH) t1SS<<"%";
		}
		
		else if(!UKTwo){
			t2SS<<setprecision(2)<<t1Avg;
			if(printPH) t2SS<<"%";
		}
		
		int lineLength=nStar+(valueLen*2);
		space(s); ccsPrint(cadr); cout<<"|"; setColor("BOLDBLUE"); strwhere(title,lineLength,1); ccsPrint(cadr); cout<<"|"<<endl;
		space(s); ccsPrint(cadr); cout<<"|"; strwhere(t1SS,valueLen,0); printCompareGraph(t1Avg,t2Avg,nStar); strwhere(t2SS,valueLen,0); ccsPrint(cadr); cout<<"|";
	}
	
	void revCompareTeams(){
		bool exYTCards=(existKnownData("t1YC") || existKnownData("t2YC"));
		bool exRTCards=(existKnownData("t1RC") || existKnownData("t2RC"));
		bool exPossess=(existKnownData("t1_possess") || existKnownData("t2_possess"));
		bool exShotsOne=(existKnownData("t1_shotsOne") || existKnownData("t2_shotsOne"));
		bool exFoulsOne=(existKnownData("t1_foulsOne") || existKnownData("t2_foulsOne"));
		bool exShotsTwo=(existKnownData("t1_shotsTwo") || existKnownData("t2_shotsTwo"));
		bool exFoulsTwo=(existKnownData("t1_foulsTwo") || existKnownData("t2_foulsTwo"));
		bool exCorners=(existKnownData("t1_corners") || existKnownData("t2_corners"));
		bool exFk=(existKnownData("t1_fk") || existKnownData("t2_fk"));
		bool exPassC=(existKnownData("t1_pass_c") || existKnownData("t2_pass_c"));
		bool exCross=(existKnownData("t1_cross") || existKnownData("t2_cross"));
		bool exInterc=(existKnownData("t1_interc") || existKnownData("t2_interc"));
		bool exTackles=(existKnownData("t1_tackles") || existKnownData("t2_tackles"));
		bool exSaves=(existKnownData("t1_saves") || existKnownData("t2_saves"));
		
		bool exLeft=(existKnownData("t1_left") || existKnownData("t2_left"));
		bool exCenter=(existKnownData("t1_center") || existKnownData("t2_right"));
		bool exRight=(existKnownData("t1_center") || existKnownData("t2_right"));
		
		cout<<endl;
		int s=10;
		int nStar=30;
		int valueLen=7;
		int maxLength=nStar+(valueLen*2)+2;
		stringstream cadr;
		cadr<<"$$BLU";
		
		stringstream temp;
		temp<<"$$RED"<<teamOne.getName()<<" Against "<<teamTwo.getName()<<"$0RST";
		space(s); beforeStrWhere(temp,maxLength); cout<<endl;
		temp.str("");
		temp<<"Number Of Games: "<<getNumGames();
		space(s); beforeStrWhere(temp,maxLength); cout<<endl<<endl;
		
		temp.str("");
		temp<<"$$RED"<<"Championship"<<"$0RST";
		space(s); beforeStrWhere(temp,maxLength); cout<<endl;
		space(s); ccsPrint(cadr); cadr_dash(maxLength); setColor("RESET");
		
		printCompareFromFactors("Wins","","",s,nStar,valueLen,cadr); cout<<endl;
		
		space(s); ccsPrint(cadr); cadr_dash(maxLength); setColor("RESET");
		

			
		cout<<endl;
		temp.str("");
		temp<<"$$RED"<<"Stats (Per Game)"<<"$0RST";
		space(s); strwhere(temp,maxLength); cout<<endl;
		space(s); ccsPrint(cadr); cadr_dash(maxLength); setColor("RESET");
		
		printCompareFromFactors("Goals","t1_goals","t2_goals",s,nStar,valueLen,cadr); cout<<endl;
		if(exYTCards){ printCompareFromFactors("Yellow Cards","t1YC","t2YC",s,nStar,valueLen,cadr,false,true); cout<<endl;}
		if(exRTCards){ printCompareFromFactors("Red Cards","t1RC","t2RC",s,nStar,valueLen,cadr,false,true); cout<<endl;}
		if(exPossess){ printCompareFromFactors("Possession","t1_possess","t2_possess",s,nStar,valueLen,cadr,true); cout<<endl;}
		if(exShotsOne){ printCompareFromFactors("Shots","t1_shotsOne","t2_shotsOne",s,nStar,valueLen,cadr); cout<<endl;}
		if(exShotsTwo){ printCompareFromFactors("Shots (On Target)","t1_shotsTwo","t2_shotsTwo",s,nStar,valueLen,cadr); cout<<endl;}
		if(exFoulsOne){ printCompareFromFactors("Fouls","t1_foulsOne","t2_foulsOne",s,nStar,valueLen,cadr,false,true); cout<<endl;}
		if(exFoulsTwo){ printCompareFromFactors("Offside","t1_foulsTwo","t2_foulsTwo",s,nStar,valueLen,cadr,false,true); cout<<endl;}
		if(exCorners){ printCompareFromFactors("Corners","t1_corners","t2_corners",s,nStar,valueLen,cadr); cout<<endl;}
		if(exFk){ printCompareFromFactors("Free Kick","t1_fk","t2_fk",s,nStar,valueLen,cadr); cout<<endl;}
		if(exPassC){ printCompareFromFactors("Pass Completed","t1_pass_c","t2_pass_c",s,nStar,valueLen,cadr,true); cout<<endl;}
		if(exCross){ printCompareFromFactors("Crosses","t1_cross","t2_cross",s,nStar,valueLen,cadr); cout<<endl;}
		if(exInterc){ printCompareFromFactors("Interception","t1_interc","t2_interc",s,nStar,valueLen,cadr); cout<<endl;}
		if(exTackles){ printCompareFromFactors("Tackles","t1_tackles","t2_tackles",s,nStar,valueLen,cadr); cout<<endl;}
		if(exSaves){ printCompareFromFactors("Saves","t1_saves","t2_saves",s,nStar,valueLen,cadr); cout<<endl;}
		
		space(s); setColor("BOLDBLUE"); cadr_dash(maxLength); setColor("RESET");
		
		if(exLeft || exCenter || exRight){
			cout<<endl;
			temp.str("");
			temp<<"$$RED"<<"Attacink Areas (Per Game)"<<"$0RST";
			space(s); strwhere(temp,maxLength); cout<<endl;
			space(s); ccsPrint(cadr); cadr_dash(maxLength); setColor("RESET");
			if(exLeft){ printCompareFromFactors("Left","t1_left","t2_left",s,nStar,valueLen,cadr,true); cout<<endl;}
			if(exCenter){ printCompareFromFactors("Center","t1_center","t2_center",s,nStar,valueLen,cadr,true); cout<<endl;}
			if(exRight){ printCompareFromFactors("Right","t1_right","t2_right",s,nStar,valueLen,cadr,true); cout<<endl;}
			
			space(s); setColor("BOLDBLUE"); cadr_dash(maxLength); setColor("RESET");
		}
	}
	
	void printGoalTimes(){
        int *tmOneTimes=new int[7];
        int *tmTwoTimes=new int[7];
        int tmOneNGoals=0;
        int tmTwoNGoals=0;
        for(int i=0; 7>i; i++) tmOneTimes[i]=0;
        for(int i=0; 7>i; i++) tmTwoTimes[i]=0;
        for(int i=0; games[i].sendexist() && 200>i; i++){
			int ** scores;
			scores=games[i].getGoals();
			for(int j=0; games[i].dynamicGet("tg")>j; j++){
				if(scores[j][0]==1){
					tmOneNGoals++;
					if(scores[j][1]==1){
						if(scores[j][4]<=15) tmOneTimes[1]++;
						else if(scores[j][4]<=30) tmOneTimes[2]++;
						else if(scores[j][4]>30) tmOneTimes[3]++;
					}
					else if(scores[j][1]==2){
						if(scores[j][4]<=60) tmOneTimes[4]++;
						else if(scores[j][4]<=75) tmOneTimes[5]++;
						else if(scores[j][4]>75) tmOneTimes[6]++;
					}
					else if(scores[j][1]<0){
						tmOneTimes[0]++;
					}
				}
				else if(scores[j][0]==2){
					tmTwoNGoals++;
					if(scores[j][1]==1){
						if(scores[j][4]<=15) tmTwoTimes[1]++;
						else if(scores[j][4]<=30) tmTwoTimes[2]++;
						else if(scores[j][4]>30) tmTwoTimes[3]++;
					}
					else if(scores[j][1]==2){
						if(scores[j][4]<=60) tmTwoTimes[4]++;
						else if(scores[j][4]<=75) tmTwoTimes[5]++;
						else if(scores[j][4]>75) tmTwoTimes[6]++;
					}
					else if(scores[j][1]<0){
						tmTwoTimes[0]++;
					}
				}
			}
        }
		
        cout<<endl; setColor("BOLDRED"); cout<<"Goal Times: "; setColor("RESET"); cout<<endl;

        cout<<endl; setColor("BOLDMAGENTA"); cout<<teamOne.getName()<<" Goal Times: "<<endl;
        cout<<"All Goals: "<<tmOneNGoals<<" Goals"<<endl;
        cadr_dash(15);
        cout<<"Min [0-15]: "<<tmOneTimes[1]<<" Goals"<<endl;
        cout<<"Min [15-30]: "<<tmOneTimes[2]<<" Goals"<<endl;
        cout<<"Min [30-45]: "<<tmOneTimes[3]<<" Goals"<<endl;
        cout<<"Min [45-60]: "<<tmOneTimes[4]<<" Goals"<<endl;
        cout<<"Min [60-75]: "<<tmOneTimes[5]<<" Goals"<<endl;
        cout<<"Min [75-90]: "<<tmOneTimes[6]<<" Goals"<<endl;
        cadr_dash(15);
        if(tmOneTimes[0]>0) cout<<"Unknown: "<<tmOneTimes[0]<<" Goals"<<endl;
        cout<<"First Half: "<<tmOneTimes[1]+tmOneTimes[2]+tmOneTimes[3]<<" Goals"<<endl;
        cout<<"Second Half: "<<tmOneTimes[4]+tmOneTimes[5]+tmOneTimes[6]<<" Goals"<<endl;

        cout<<endl; setColor("BOLDCYAN"); cout<<teamTwo.getName()<<" Goal Times: "<<endl;
        cout<<"All Goals: "<<tmTwoNGoals<<" Goals"<<endl;
        cadr_dash(15);
        cout<<"Min [0-15]: "<<tmTwoTimes[1]<<" Goals"<<endl;
        cout<<"Min [15-30]: "<<tmTwoTimes[2]<<" Goals"<<endl;
        cout<<"Min [30-45]: "<<tmTwoTimes[3]<<" Goals"<<endl;
        cout<<"Min [45-60]: "<<tmTwoTimes[4]<<" Goals"<<endl;
        cout<<"Min [60-75]: "<<tmTwoTimes[5]<<" Goals"<<endl;
        cout<<"Min [75-90]: "<<tmTwoTimes[6]<<" Goals"<<endl;
        cadr_dash(15);
        if(tmTwoTimes[0]>0) cout<<"Unknown: "<<tmTwoTimes[0]<<" Goals"<<endl;
        cout<<"First Half: "<<tmTwoTimes[1]+tmTwoTimes[2]+tmTwoTimes[3]<<" Goals"<<endl;
        cout<<"Second Half: "<<tmTwoTimes[4]+tmTwoTimes[5]+tmTwoTimes[6]<<" Goals"<<endl;
	}
	
	void printGraphResults(){
		if(!games[0].sendexist()){
			cout<<endl<<"Hanuz Bazi ei Bargozar Nashode Ast"<<endl;
			return;
		}
		
		cout<<endl; setColor("BOLDRED"); cout<<"Results Graph: "; setColor("RESET"); cout<<endl;
		for(int i=0; games[i].sendexist() && 200>i; i++){
			if(i/10*10==i){ cout<<endl; setColor("BOLDBLACK"); cout<<"| "; setColor("RESET");}
			switch(games[i].dynamicGet("res")){
				case 1: setColor("BOLDMAGENTA"); break;
				case 2: setColor("BOLDCYAN"); break;
				case 3: setColor("BOLDWHITE"); break;
			}
			if(i<9) cout<<"0";
			cout<<i+1; setColor("BOLDBLACK"); cout<<" | ";
		}
		cout<<endl<<endl;
		
		for(int i=0; games[i].sendexist() && 200>i; i++){
			if(i/10*10==i){ cout<<endl<<"| "; setColor("RESET");}
			switch(games[i].dynamicGet("res")){
				case 1: setColor("BOLDMAGENTA"); break;
				case 2: setColor("BOLDCYAN"); break;
				case 3: setColor("BOLDWHITE"); break;
			}
			cout<<games[i].dynamicGet("t1_goals")<<"-"<<games[i].dynamicGet("t2_goals");
			cout<<" | ";
		}
		cout<<endl;
	}
	
	int ** getOrderedSoloPerformance(){
		int tp,tp1;
		for(tp1=0; games[tp1].sendexist() && 200>tp1; tp1++);
		tp=tp1*15;
		int **prStats;
		prStats=new int*[tp];
		for(int i=0; tp>i; i++){
			prStats[i]=new int[6];     //0:Match Index | 1:Team | 2:Player ID | 3:Goals | 4:Assists | 5:Goals+Assists
			for(int j=0; 5>j; j++) prStats[i][j]=0;
		}
		int k=0;
		for(int i=0; games[i].sendexist() && 200>i; i++){
			int **gStats=games[i].getPlayersStats();
			for(int j=0; gStats[j][0]!=0; j++,k++){
				prStats[k][0]=i;
				for(int m=0; 4>m; m++) prStats[k][m+1]=gStats[j][m];
				prStats[k][5]=prStats[k][3]+prStats[k][4];
			}
		}
		if(k==0){
			return prStats;
		}
		
		int number=k;
		int *max;
		max=new int[6];
		int index;
		for(int i=0; number>i && prStats[i][1]!=0; i++){
			index=i;
			for(int m=0; 6>m; m++) max[m]=prStats[i][m];
			for(int j=i+1; number>j && prStats[j][1]!=0; j++){
				if(prStats[j][5]>max[5] || (prStats[j][5]==max[5] && prStats[j][3]>max[3])){
					for(int m=0; 6>m; m++) max[m]=prStats[j][m];
					index=j;
				}
			}
			if(index!=i){
				for(int m=0; 6>m; m++) prStats[index][m]=prStats[i][m];
				for(int m=0; 6>m; m++) prStats[i][m]=max[m];
			}
		}
                
		return prStats;
	}
	
	void printBestSoloPerformance(){
		int **prStats;
		prStats=getOrderedSoloPerformance();
		cout<<endl; setColor("BOLDRED"); cout<<"Best Solo Performance: "; setColor("RESET"); cout<<endl;
		for(int i=0; prStats[i][5]>=3 && prStats[i][1]!=0; i++){
			if(prStats[i][1]==1){
				if(prStats[i][3]>0 && prStats[i][4]>0){
					setColor("BOLDMAGENTA"); cout<<teamOne.getPrFromId(prStats[i][2]).sendname()<<" | Goals: "<<prStats[i][3]
					<<" | Assists: "<<prStats[i][4]<<" | Game "<<prStats[i][0]<<endl;
				}
				else if(prStats[i][3]>0){
					setColor("BOLDMAGENTA"); cout<<teamOne.getPrFromId(prStats[i][2]).sendname()<<" | Goals: "<<prStats[i][3]
					<<" | Game "<<prStats[i][0]<<endl;
				}
				else if(prStats[i][4]>0){
					setColor("BOLDMAGENTA"); cout<<teamOne.getPrFromId(prStats[i][2]).sendname()
					<<" | Assists: "<<prStats[i][4]<<" | Game "<<prStats[i][0]<<endl;
				}
			}
			else if(prStats[i][1]==2){
				if(prStats[i][3]>0 && prStats[i][4]>0){
					setColor("BOLDCYAN"); cout<<teamTwo.getPrFromId(prStats[i][2]).sendname()<<" | Goals: "<<prStats[i][3]
					<<" | Assists: "<<prStats[i][4]<<" | Game "<<prStats[i][0]<<endl;
				}
				else if(prStats[i][3]>0){
					setColor("BOLDCYAN"); cout<<teamTwo.getPrFromId(prStats[i][2]).sendname()<<" | Goals: "<<prStats[i][3]
					<<" | Game "<<prStats[i][0]<<endl;
				}
				else if(prStats[i][4]>0){
					setColor("BOLDCYAN"); cout<<teamTwo.getPrFromId(prStats[i][2]).sendname()
					<<" | Assists: "<<prStats[i][4]<<" | Game "<<prStats[i][0]<<endl;
				}
			}
		}
		cout<<endl;
	}
        
    void moratab(int tmp[][3],int s){
            int tp1,tp2;
            for(tp1=0; teamOne.pr[tp1].sendexist(); tp1++);
            for(tp2=0; teamTwo.pr[tp2].sendexist(); tp2++);
            if(s==1){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].sendapps();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].sendapps();
            }
            if(s==2){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].sendgoals();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].sendgoals();
            }
            if(s==3){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].sendass();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].sendass();
            }
            if(s==4){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].getHatTricks();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].getHatTricks();
            }
            if(s==5){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].sendmom();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].sendmom();
            }
            if(s==6){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].sendyc();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].sendyc();
            }
            if(s==7){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].sendrc();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].sendrc();
            }
            if(s==8){
                    int i=0;
                    for(int j=0; tp1>j; i++,j++) tmp[i][2]=teamOne.pr[j].sendyc()+ 2* teamOne.pr[j].sendrc();
                    for(int j=0; tp2>j; i++,j++) tmp[i][2]=teamTwo.pr[j].sendyc()+ 2* teamTwo.pr[j].sendrc();
            }
            int i,j,big,andis,tp[3],anjam;
            for(i=0; 200>i; i++){
                    big=tmp[i][2];
                    anjam=0;
                    for(j=i+1; 200>j; j++){
                            if(tmp[j][2]>big){
                                    big=tmp[j][2];
                                    andis=j;
                                    anjam=1;
                            }
                    }
                    if(anjam==1){
                            tp[0]=tmp[i][0];
                            tp[1]=tmp[i][1];
                            tp[2]=tmp[i][2];
                            tmp[i][0]=tmp[andis][0];
                            tmp[i][1]=tmp[andis][1];
                            tmp[i][2]=tmp[andis][2];
                            tmp[andis][0]=tp[0];
                            tmp[andis][1]=tp[1];
                            tmp[andis][2]=tp[2];
                    }
            }
    }
    
    void subsumePlayers(){
		int choice;
		while(1){
			setColor("BOLDRED"); cout<<"\nSubsumption Players:\n"; setColor("RESET");
			cout<<"1: Most Apps\n2: Top Scorers\n3: Top Assisters\n4: Top HatTrickers\n5: Most MOTM Points\n"
			<<"6: Most yellow cards\n7: Most red cards\n8: Most Violence\n9: Back to main\n\nEnter your choice\n";
			choice=inputChoice(1,9);
			if(choice==9) break;
			else{
				int tmp[300][3],tp1,tp2,i;
				for(tp1=0; teamOne.pr[tp1].sendexist(); tp1++);
				for(tp2=0; teamTwo.pr[tp2].sendexist(); tp2++);
				i=0;
				for(int j=0; tp1>j; i++,j++){
					tmp[i][0]=1;
					tmp[i][1]=j;
				}
				for(int j=0; tp2>j; i++,j++){
					tmp[i][0]=2;
					tmp[i][1]=j;
				}
				for(; 300>i; i++){ tmp[i][0]=0; tmp[i][1]=0; tmp[i][2]=-1;}
				switch(choice){
					case 1: cout<<endl; setColor("BOLDRED"); cout<<"Most Apps:\n"; setColor("RESET"); break;
					case 2: cout<<endl; setColor("BOLDRED"); cout<<"Top Scorers:\n"; setColor("RESET"); break;
					case 3: cout<<endl; setColor("BOLDRED"); cout<<"Top Assisters:\n"; setColor("RESET"); break;
					case 4: cout<<endl; setColor("BOLDRED"); cout<<"Top Hat Trickers:\n"; setColor("RESET"); break;
					case 5: cout<<endl; setColor("BOLDRED"); cout<<"Most MOTM Points:\n"; setColor("RESET"); break;
					case 6: cout<<endl; setColor("BOLDRED"); cout<<"Most Yellow Cards:\n"; setColor("RESET"); break;
					case 7: cout<<endl; setColor("BOLDRED"); cout<<"Most Red Cards:\n"; setColor("RESET"); break;
					case 8: cout<<endl; setColor("BOLDRED"); cout<<"Most Violence:\n"; setColor("RESET"); break;
				}
				moratab(tmp,choice);
				for(int i=0; 200>i; i++){
					if(tmp[i][2]<1) break;
					cout<<i+1<<": ";
					if(tmp[i][0]==1){ setColor("BOLDMAGENTA"); cout<<teamOne.pr[tmp[i][1]].sendname()<<"     "<<tmp[i][2]; setColor("RESET");}
					else if(tmp[i][0]==2){ setColor("BOLDCYAN"); cout<<teamTwo.pr[tmp[i][1]].sendname()<<"     "<<tmp[i][2]; setColor("RESET");}
					cout<<endl;
				}
			}
		}
    }
		
};




//Main Function


int main(int argc, char** argv) {
    DATA_FILE_NAME=new char[256];
    NULL_PATH_STRING=new char[100];
	EXE_APP_NAME=new char[150];
    strcpy(NULL_PATH_STRING,"###NULLPATH###");
    strcpy(DATA_FILE_NAME,NULL_PATH_STRING);
	strcpy(EXE_APP_NAME,"arenacpp");
    IS_SAVED=true;
    srand(time(NULL));
    int choice;
    team t1,t2;
    match *games;
    games = new match[200];
    inputProfile inpSettings;
	
	if(argc>=3 && strcmp(argv[1],"__players")==0){
		start_squads:
		fstream f1(argv[2] , ios::in | ios::binary);
		if(!isDataFileAndReady(f1)) return 0;
		f1.read((char *)&inpSettings, sizeof(inpSettings));
		f1.read((char *)&t1, sizeof(t1));
		f1.read((char *)&t2, sizeof(t2));
		f1.read((char *)games, sizeof(match)*200);
		f1.close();
		newTermPlayers(t1,t2,games);
		while(true){
			cout<<endl<<"Enter[R/r] To Reload [Q/q] To Exit: ";
			char temp[20];
			cin.getline(temp,20);
			if(strcmp(temp,"q")==0 || strcmp(temp,"Q")==0) break;
			else if(strcmp(temp,"R")==0 || strcmp(temp,"r")==0){
				system("cls");
				goto start_squads;
			}
		}
		return 0;
	}
	
    setColor("BOLDRED");
    cout<<"In The Name Of God\n";
    setColor("RESET");
    cout<<"Welcome to SA-Arena";
    start:
    setColor("BOLDRED");
    cout<<"\n\nEnter your choice\n";
    setColor("RESET");
    cout<<"1: Start a new Tournament\n"<<"2: Load Recent Tournament\n";
    choice=inputChoice(1,2);
    if(choice==1){
        newtour:
        if(!enterTeams(t1,t2)) goto start;
        IS_SAVED=false;
    }
    else{
        if(!load(t1,t2,games,inpSettings)) goto start;
        //if(!loadTxt("data.txt",t1,t2,games,inpSettings)) goto start;
    }
    
    if(t1.sendid()==t2.sendid()){
        setColor("BOLDBLACK");
        cout<<"Warning!!! Error in Team Id\n\n";
        setColor("RESET");
    }
    
    //correctData(t1,t2,games,inpSettings);
    
    if(!mainMenu(t1,t2,games,inpSettings,argv[0])) goto newtour;
    return 0;
}


//End Main Function



void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}

void swap(int a[],int b[],int n){
	for(int i=0; n>i; i++){
		int temp;
		temp=a[i];
		a[i]=b[i];
		b[i]=temp;
	}
}

bool randYesNo(){
    int min=0,max=1;
    return (min + (rand() % (int)(max - min + 1)));
}

void space(int s){
	if(s>0) for(int i=0; s>i; i++) cout<<" ";
}

void cadr_dash(int tul,bool noEndl){
	for(int i=0; tul>i; i++) cout<<"-";
	if(!noEndl) cout<<endl;
}

void print_passage(char *p){
	char space=32;
	for(int i=0; p[i]!=0 || i==0; i++){
		if(i==0){ if(p[i]==0){ cout<<"No Confrence"; break;}}
		if(p[i]==95) cout<<space;
		else cout<<p[i];
	}
}

void colorStringPrint(string str){
	if(str.find("$")>str.size()){
		cout<<str;
		return;
	}
	else{
		unsigned int size=str.size();
		for(unsigned int i=0; size>i; i++){
			if(size-4>i && str[i]=='$'){
				int num;
				string codeColor;
				codeColor=str.substr(i+2,3);
				num=getColorNum(codeColor);
				if(num>0 || (num==0 && str[i+1]=='0')){
					if(str[i+1]=='0'){
						setColor(num,false);
						i+=4;
					}
					else if(str[i+1]=='$'){
						setColor(num,true);
						i+=4;
					}
					else{
						cout<<str[i];
					}
				}
				else{
					cout<<str[i];
				}
			}
			else cout<<str[i];
		}
	}
}

int getColorNum(string color){
	if(color.compare("RST")==0) return 0;
	else if(color.compare("BLU")==0) return 1;
	else if(color.compare("GRN")==0) return 2;
	else if(color.compare("CYN")==0) return 3;
	else if(color.compare("RED")==0) return 4;
	else if(color.compare("MAG")==0) return 5;
	else if(color.compare("YEL")==0) return 6;
	else if(color.compare("WHT")==0) return 7;
	else if(color.compare("BLK")==0) return 8;
	else return -1;
}

void setColor(int num,bool bold){
    #define RESET   "\033[0m"
    #define BLACK   "\033[30m"      // Black
    #define RED     "\033[31m"      // Red
    #define GREEN   "\033[32m"      // Green
    #define YELLOW  "\033[33m"      // Yellow
    #define BLUE    "\033[34m"      // Blue
    #define MAGENTA "\033[35m"      // Magenta
    #define CYAN    "\033[36m"      // Cyan
    #define WHITE   "\033[37m"      // White
    #define BOLDBLACK   "\033[1m\033[30m"      // Bold Black
    #define BOLDRED     "\033[1m\033[31m"      // Bold Red
    #define BOLDGREEN   "\033[1m\033[32m"      // Bold Green
    #define BOLDYELLOW  "\033[1m\033[33m"      // Bold Yellow
    #define BOLDBLUE    "\033[1m\033[34m"      // Bold Blue
    #define BOLDMAGENTA "\033[1m\033[35m"      // Bold Magenta
    #define BOLDCYAN    "\033[1m\033[36m"      // Bold Cyan
    #define BOLDWHITE   "\033[1m\033[37m"      // Bold White
    
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
	if(num<0 || num>8) throw -1;
	if(bold){
		if(num==0) throw -1;
		else if(num==1) SetConsoleTextAttribute(hConsole, 9);  //BOLDBLUE
		else if(num==2) SetConsoleTextAttribute(hConsole, 10);  //BOLDGREEN
		else if(num==3) SetConsoleTextAttribute(hConsole, 11);  //BOLDCYAN
		else if(num==4) SetConsoleTextAttribute(hConsole, 12);  //BOLDRED
		else if(num==5) SetConsoleTextAttribute(hConsole, 13);  //BOLDMAGENTA
		else if(num==6) SetConsoleTextAttribute(hConsole, 14);  //BOLDYELLOW
		else if(num==7) SetConsoleTextAttribute(hConsole, 15);  //BOLDWHITE
		else if(num==8) SetConsoleTextAttribute(hConsole, 16);  //BOLDBLACK
	}
	else{
		if(num==0) SetConsoleTextAttribute(hConsole, 7);  //RESET = WHITE
		else if(num==1) SetConsoleTextAttribute(hConsole, 1);  //BLUE
		else if(num==2) SetConsoleTextAttribute(hConsole, 2);  //GREEN
		else if(num==3) SetConsoleTextAttribute(hConsole, 3);  //CYAN
		else if(num==4) SetConsoleTextAttribute(hConsole, 4);  //RED
		else if(num==5) SetConsoleTextAttribute(hConsole, 5);  //MAGENTA
		else if(num==6) SetConsoleTextAttribute(hConsole, 6);  //YELLOW
		else if(num==7) SetConsoleTextAttribute(hConsole, 7);  //WHITE
		else if(num==8) SetConsoleTextAttribute(hConsole, 8);  //BLACK
	}
}

void setColor(int num){
    setColor(num,false);
}

void setColor(const char *color){
    if(strcasecmp(color,"RESET")==0) setColor(0);
    else if(strcasecmp(color,"BLUE")==0) setColor(1);
    else if(strcasecmp(color,"GREEN")==0) setColor(2);
    else if(strcasecmp(color,"CYAN")==0) setColor(3);
    else if(strcasecmp(color,"RED")==0) setColor(4);
    else if(strcasecmp(color,"MAGENTA")==0) setColor(5);
    else if(strcasecmp(color,"YELLOW")==0) setColor(6);
    else if(strcasecmp(color,"WHITE")==0) setColor(7);
    else if(strcasecmp(color,"BLACK")==0) setColor(8);
    
    else if(strcasecmp(color,"BOLDBLUE")==0) setColor(1,true);
    else if(strcasecmp(color,"BOLDGREEN")==0) setColor(2,true);
    else if(strcasecmp(color,"BOLDCYAN")==0) setColor(3,true);
    else if(strcasecmp(color,"BOLDRED")==0) setColor(4,true);
    else if(strcasecmp(color,"BOLDMAGENTA")==0) setColor(5,true);
    else if(strcasecmp(color,"BOLDYELLOW")==0) setColor(6,true);
    else if(strcasecmp(color,"BOLDWHITE")==0) setColor(7,true);
    else if(strcasecmp(color,"BOLDBLACK")==0) setColor(8,true);
    else throw -1;
}

void ccsPrint(stringstream &s1){
	string str=s1.str();
	colorStringPrint(str);
}

int sstreamLength(stringstream &s1){
    string str;
    str=s1.str();
    int length=0;
	if(str.find("$")>str.size()){
            length=str.size();
		return length;
	}
	else{
		unsigned int size=str.size();
		for(unsigned int i=0; size>i; i++){
			if(size-4>i && str[i]=='$'){
				int num;
				string codeColor;
				codeColor=str.substr(i+2,3);
				num=getColorNum(codeColor);
				if(num>0 || (num==0 && str[i+1]=='0')){
					if(str[i+1]=='0'){
						i+=4;
					}
					else if(str[i+1]=='$'){
						i+=4;
					}
					else{
                        length++;
					}
				}
				else{
                    length++;
				}
			}
			else length++;
		}
	}
        return length;
}

void beforeStrWhere(stringstream &a,int zarf){
	int len=sstreamLength(a);
	int s=(zarf-len)/2;
	for(int i=0; s>i; i++) cout<<" ";
	ccsPrint(a);
}

void strwhere(stringstream &a,int zarf,int halat){
	int len=sstreamLength(a);
	int s=(zarf-len)/2;
	if(halat==0) setColor("RESET");
	for(int i=0; s>i; i++) cout<<" ";
	ccsPrint(a);
	for(int i=0; s>i; i++) cout<<" ";
	if((zarf-len)/2*2!=(zarf-len)) cout<<" ";
}

void strwhere(stringstream &a,int zarf){
    strwhere(a,zarf,0);
}

void beforeStrWhere(const char*a,int zarf){
	int len=strlen(a);
	int s=(zarf-len)/2;
	for(int i=0; s>i; i++) cout<<" ";
	cout<<a;
}

void strwhere(const char *a,int zarf,int halat){
	int len=strlen(a);
	int s=(zarf-len)/2;
	if(halat==0) setColor("RESET");
	for(int i=0; s>i; i++) cout<<" ";
	cout<<a;
	for(int i=0; s>i; i++) cout<<" ";
	if((zarf-len)/2*2!=(zarf-len)) cout<<" ";
}

void strwhere(const char *a,int zarf){
    strwhere(a,zarf,0);
}

int generateNewPrId(team tm1,team tm2){
    bool correct;
    int min=1000;
    int max=9999;
    int id;
    do{
        correct=true;
        id = min + (rand() % (int)(max - min + 1));
        for(int i=0; tm1.getPrFromIndex(i).sendexist(); i++){
            if(tm1.getPrFromIndex(i).getId()==id){
                correct=false;
                continue;
            }
        }
        for(int i=0; tm2.getPrFromIndex(i).sendexist(); i++){
            if(tm2.getPrFromIndex(i).getId()==id){
                correct=false;
                continue;
            }
        }
    } while(!correct);
    return id;
}

bool existFile(char* fileName){
	fstream f1(fileName , ios::in | ios::binary);
    if(!f1){
        f1.close();
        return false;
    }
    f1.close();
    return true;
}

bool isDataFileAndReady(istream& f1){
    string type;
    int size;
    char *buf;
	f1.read(reinterpret_cast<char *>(&size), sizeof(int));
	buf = new char[size];
	f1.read(buf, size);
	type = "";
	type.append(buf, size);
    if(type.compare("SA_SaveData")==0){
        return true;
    }
    return false;
}

bool isDataFile(char* fileName){
    if(!existFile(fileName)) return false;
    fstream f1(fileName , ios::in | ios::binary);
    if(isDataFileAndReady(f1)){
        f1.close();
        return true;
    }
    f1.close();
    return false;
}

bool isDataFile(const char* fileName){
    char newFileName[256];
    strcpy(newFileName,fileName);
    return isDataFile(newFileName);
}

bool lostDataWarning(team tm1,team tm2,match *m, inputProfile inpSettings,bool showWarn){
    int choice;
    start:
    if(!IS_SAVED){
        cout<<endl;
        typeWarning();
		if(showWarn) cout<<"Unsaved Data will not shown!"<<endl;
        cout<<"Do You Want to Save Changes? (1:Yes | 2:No | 3:Cancel): ";
        choice=inputChoice(1,3);
        if(choice==1){
            if(strcmp(DATA_FILE_NAME,NULL_PATH_STRING)==0) saveAs(tm1,tm2,m,inpSettings);
            else save(DATA_FILE_NAME,tm1,tm2,m,inpSettings);
            if(!IS_SAVED) goto start;
        }
        else if(choice==3) return false;
    }
    return true;
}


bool saveAs(team tm1,team tm2, match *m, inputProfile inpSettings){
    char newPath[256];
    cout<<endl<<"Enter File Name: ";
    cin.getline(newPath,256);
    if(existFile(newPath)){
        cout<<endl;
        typeWarning();
        cout<<"A file Named "<<newPath<<" Already Exists!\n";
        cout<<"Do you Want to Replace It? (1:Yes | 2:No): ";
        if(inputChoice(1,2)==2) return false;
    }
    save(newPath,tm1,tm2,m,inpSettings);
    return true;
}

bool save(char* fileName,team tm1,team tm2,match *m, inputProfile inpSettings){
    fstream f1(fileName , ios::in | ios::binary);
    int choice=1;
    if(f1){
        cout<<endl<<"Are You Sure? (1:Yes | 2:No): ";
        choice=inputChoice(1,2);
    }
    
	if(choice==1){
        string type("SA_SaveData");
        int size = (type.size());
		fstream f1(fileName , ios::out | ios::binary);
        f1.write(reinterpret_cast<char *>(&size), sizeof(int));
        f1.write(type.c_str(), size);
        
        f1.write((char *)&inpSettings,sizeof(inpSettings));
		f1.write((char *)&tm1,sizeof(tm1));
		f1.write((char *)&tm2,sizeof(tm2));
		f1.write((char *)m,sizeof(match)*200);
        f1.flush();
		f1.close();
        
        strcpy(DATA_FILE_NAME,fileName);
        FileNames flnames;
        flnames.load();
        flnames.append(fileName);
		
        IS_SAVED=true;
        
        setColor("BOLDGREEN");
		cout<<"Tournament Saved Successfuly.\n";
        setColor("RESET");
        return true;
	}
    return false;
}

bool save(const char* fileName,team tm1,team tm2,match *m, inputProfile inpSettings){
    char newFileName[256];
    strcpy(newFileName,fileName);
    return save(newFileName,tm1,tm2,m,inpSettings);
}

bool saveTxt(char* fileName,team tm1,team tm2,match *m,inputProfile inpSettings){
	int choice;
	cout<<endl<<"Are You Sure? (1:Yes | 2:No): ";
    choice=inputChoice(1,2);
	if(choice==1){
		fstream f1("data.txt" , ios::out);
        inpSettings.saveTxt(f1);
		tm1.saveTxt(f1);
		tm2.saveTxt(f1);
		int t;
		for(t=0; m[t].sendexist(); t++);
		f1<<t<<endl;
		for(int i=0; t>i; i++) m[i].saveTxt(f1);
		f1.close();
        setColor("BOLDGREEN");
		cout<<"Tournament Saved Successfuly.\n";
        setColor("RESET");
        return true;
	}
    return false;
}

bool saveTxt(const char* fileName,team tm1,team tm2,match *m,inputProfile inpSettings){
    char newFileName[256];
    strcpy(newFileName,fileName);
    return saveTxt(newFileName,tm1,tm2,m,inpSettings);
}


bool load(team &tm1, team &tm2, match *m,inputProfile& inpSettings){
    if(!lostDataWarning(tm1,tm2,m,inpSettings)) return false;
    
    char fileName[256];
    FileNames flnames;
    flnames.load();
    if(!flnames.choiceMenu(fileName)) return false;
    
    fstream f1(fileName , ios::in | ios::binary);
    if(!isDataFileAndReady(f1)) throw-1;
    
    f1.read((char *)&inpSettings, sizeof(inpSettings));
    f1.read((char *)&tm1, sizeof(tm1));
    f1.read((char *)&tm2, sizeof(tm2));
    f1.read((char *)m, sizeof(match)*200);
    f1.close();
    setColor("BOLDGREEN");
    cout<<fileName<<" Loaded Successfully.\n";
    setColor("RESET");
    strcpy(DATA_FILE_NAME,fileName);
    return true;
}

/*bool load(const char* fileName,team &tm1, team &tm2, match *m){
    char newFileName[256];
    strcpy(newFileName,fileName);
    return load(newFileName,tm1,tm2,m);
}*/

bool loadTxt(char* fileName,team &tm1, team &tm2, match *m, inputProfile &inpSettings){
	fstream f1("data.txt" , ios::in);
    if(!f1){
        printError("Save File (data.txt) Not Found!\n");
        return false;
    }
        
	int choice;
	cout<<endl<<"Are You Sure? (1:Yes | 2:No): ";
    choice=inputChoice(1,2);
	if(choice==1){
        inpSettings.loadTxt(f1);
        tm1.loadTxt(f1);
        tm2.loadTxt(f1);
        int t;
        f1>>t;
        f1.ignore();
        for(int i=0; t>i; i++) m[i].loadTxt(f1); 
        f1.close();
        setColor("BOLDGREEN");
        cout<<"Tornoment Loaded Successfuly.\n";
        setColor("RESET");
        return true;
    }
    return false;
}

bool loadTxt(const char* fileName,team &tm1, team &tm2, match *m, inputProfile &inpSettings){
    char newFileName[256];
    strcpy(newFileName,fileName);
    return loadTxt(newFileName,tm1,tm2,m,inpSettings);
}

bool exitApp(team tm1,team tm2,match *m,inputProfile inpSettings){
    if(lostDataWarning(tm1,tm2,m,inpSettings)) return true;
    return false;
}

bool enterTeams(team& tm1,team& tm2){
    int i=0;
    do{ 
        if(i>0){
            cout<<endl;
            printError("Two Id Are The Same !!! Try Again.\n");
        }
        setColor("BOLDRED");
        cout<<"\nTeam 1:\n";
        setColor("RESET");
        if(!tm1.input()) return false;
        setColor("BOLDRED");
        cout<<"\nTeam 2:\n";
        setColor("RESET");
        if(!tm2.input()) return false;
        i++;
    } while(tm1.sendid()==tm2.sendid());
    return true;
}

bool mainMenu(team& t1,team& t2,match *games,inputProfile& inpSettings, const char* arg){
    while(true){
        int num=0;
        bool canSave=strcmp(DATA_FILE_NAME,NULL_PATH_STRING)!=0;
        setColor("BOLDRED");
        cout<<"\nMenu: \n";
        setColor("RESET");
        cout<<++num<<": ";
        t1.printname();
        cout<<"\n"<<++num<<": ";
        t2.printname();
        cout<<endl<<++num<<": External Squads\n";
		cout<<++num<<": Add match\n";
        cout<<++num<<": Edit Match\n";
        cout<<++num<<": Show match\n";
        cout<<++num<<": Competition Stats\n";
        cout<<++num<<": Repair details\n";
        cout<<++num<<": Game Input Settings\n";
        cout<<++num<<": New Tournament\n";
        cout<<++num<<": Load\n";
        if(canSave) cout<<num+1<<": Save\n";
        cout<<num+1+canSave<<": Save As\n";
        cout<<num+2+canSave<<": Exit\n";
        
        cout<<"\nEnter your choice: ";
        int choice = inputChoice(1,num+2+canSave);
        if(choice==1) t1.teamManage(t2);
        else if(choice==2) t2.teamManage(t1);
		else if(choice==3 && lostDataWarning(t1,t2,games,inpSettings,true)) externalShowAllPrs(arg);
        else if(choice==4) add_game(games,t1,t2,inpSettings);
        else if(choice==5) editGame(games,t1,t2);
        else if(choice==6) show_game(games,t1,t2);
        else if(choice==7) competition_stats(t1,t2,games);
        else if(choice==8) details_repair(games,t1,t2);
        else if(choice==9) inpSettings.settings();
        else if(choice==10 && exitApp(t1,t2,games,inpSettings)) return false;
        
        else if(choice==11) load(t1,t2,games,inpSettings);
        //else if(choice==10) loadTxt("data.txt",t1,t2,games,inpSettings);
        
        else if(choice==11+1 && canSave) save(DATA_FILE_NAME,t1,t2,games,inpSettings);
        else if(choice==11+1+canSave) saveAs(t1,t2,games,inpSettings);
        //else if(choice==10+1) saveTxt("data.txt",t1,t2,games,inpSettings);
        
        else if(choice==(11+2+canSave) && exitApp(t1,t2,games,inpSettings)) return true;
    }
}

void competition_stats(team tm1,team tm2,match m[200]){
	int choice;
	competition league(tm1,tm2,m);
	
	if(!m[0].sendexist()){
		cout<<endl<<"No Recorded Match For Stats!"<<endl;
	}
	
	while(1){
		cout<<"\n";
		setColor("BOLDRED");
        cout<<"Competition Stats:\n";
        setColor("RESET");
		cout<<"1: Compare Teams\n2: Results Graph\n3: See Most\n4: Goals Times\n5: Best Solo Performance\n"
		<<"6: Subsume Players\n7: Winners Against Loosers\n8: Back to main\n\nEnter your choice\n";
        choice=inputChoice(1,8);
		switch(choice){
			//case 1: league.compareTeams(); break;
			case 1: league.revCompareTeams(); break;
			case 2: league.printGraphResults(); break;
			case 3: league.printMost(); break;
			case 4: league.printGoalTimes(); break;
			case 5: league.printBestSoloPerformance(); break;
			case 6: league.subsumePlayers(); break;
			case 7: league.WinnerAgLooser(); break;
		}
		if (choice==8) break;
	}
}

int getNumGames(match *m){
	int num;
	for(num=0; m[num].sendexist(); num++);
	return num;
}

void add_game(match *m,team &tm1,team &tm2, inputProfile & inpSettings){
	int i;
	for(i=0; 200>i && m[i].exist==1; i++);
	if(i==200){
		cout<<endl<<"Zarfiate afzudane bazi vojud nadarad.\n";
	}
	else{
		cout<<"\nGame "<<i+1<<":\n";
		m[i].input_game(tm1,tm2,inpSettings);
		m[i].update_after_game(tm1,tm2);
	}
}

int choiceMatch(match *m,team tm1,team tm2){
	int number;
	cout<<endl;
    setColor("BOLDRED");
    cout<<"Recorded Games:\n";
    setColor("RESET");
    for(number=0; m[number].sendexist(); number++){
		int tm1Goals,tm2Goals;
		tm1Goals=m[number].dynamicGet("t1_goals");
		tm2Goals=m[number].dynamicGet("t2_goals");
		if(tm1Goals>tm2Goals) setColor("BOLDMAGENTA");
		else if(tm1Goals<tm2Goals) setColor("BOLDCYAN");
		else if(tm1Goals==tm2Goals) setColor("BOLDWHITE");
        cout<<number+1<<": ";
		setColor("RESET");
		cout<<tm1.getName()<<" "<<tm1Goals
        <<"-"<<tm2Goals<<" "<<tm2.getName()<<endl;
    }
    cout<<number+1<<": Back to Main Menu\n";
    cout<<endl<<"Enter Your Choice: ";
    int choice=inputChoice(1,number+1);
    if(choice==number+1) return -1;
	return choice;
}

void externalShowAllPrs(const char* arg){
	int lastPos=0;
	for(int i=0; arg[i]!=0; i++){
		if(arg[i]=='\\') lastPos=i;
	}
	
	char fileName[100];
	int i,j;
	for(i=lastPos+1,j=0; arg[i]!=0; i++,j++) fileName[j]=arg[i];
	
	
	
	char command[200];
	sprintf(command,"start \"\" cmd /k \"mode con: cols=46 lines=45 & %s __players %s\"",fileName,DATA_FILE_NAME);
	system(command);
}

void editGame(match *m,team &tm1,team &tm2){
    if(!m[0].sendexist()){
        cout<<endl<<"There is No Recorded Game For Edit!"<<endl;
        return;
    }
    while(true){
		int choice;
		choice=choiceMatch(m,tm1,tm2);
        if(choice==-1) break;
        m[choice-1].editGame(tm1,tm2);
		
		cout<<endl;
		setColor("BOLDRED");
		cout<<"Next Work?"<<endl;
		setColor("RESET");
		cout<<"1: Edit Another Game\n2: Back To Main Menu\n";
		cout<<"Enter Your Choice: ";
		if(inputChoice(1,2)==2) break;
    }
    silentDetailsRepair(m,tm1,tm2);
}

void silentDetailsRepair(match *m,team &tm1,team &tm2){
    for(int i=0; tm1.getPrFromIndex(i).sendexist(); i++) tm1.pr[i].zero();
	for(int i=0; tm2.getPrFromIndex(i).sendexist(); i++) tm2.pr[i].zero();
	tm1.zero();
	tm2.zero();
	for(int i=0; m[i].sendexist(); i++){
		m[i].update_after_game(tm1,tm2,true);
    }
    IS_SAVED=false;
}

void details_repair(match *m,team &tm1,team &tm2){
	int tp1,tp2,choice;
	for(tp1=0; tm1.pr[tp1].sendexist(); tp1++);
	for(tp2=0; tm2.pr[tp2].sendexist(); tp2++);
	cout<<endl<<"Do you want to Repair details? (1:Yes | 2:No)\n";
    choice=inputChoice(1,2);
	if(choice==2) return;
	else{
		for(int i=0; tp1>i; i++) tm1.pr[i].zero();
		for(int i=0; tp2>i; i++) tm2.pr[i].zero();
		tm1.zero();
		tm2.zero();
		for(int i=0; m[i].sendexist()==1; i++){
			cout<<"Game "<<i+1<<": "; 
			m[i].update_after_game(tm1,tm2);
        }
        IS_SAVED=false;
	}
}

void show_game(match *m,team tm1,team tm2){
    if(!m[0].sendexist()){
        cout<<endl<<"There is No Recorded Game For Show!"<<endl;
        return;
    }
    while(true){
		int choice;
		choice=choiceMatch(m,tm1,tm2);
		if(choice==-1) break;
        m[choice-1].show(tm1,tm2);
		
		cout<<endl;
		setColor("BOLDRED");
		cout<<"Next Work?"<<endl;
		setColor("RESET");
		cout<<"1: Show Another Game\n2: Back To Main Menu\n";
		cout<<"Enter Your Choice: ";
		if(inputChoice(1,2)==2) break;
    }
}

void newTermPlayers(team tm1,team tm2,match *m){
	bool t1PrintedPrs[200];
	bool t2PrintedPrs[200];
	int t1Ids[200];
	int t2Ids[200];
	for(int i=0; 200>i; i++) t1PrintedPrs[i]=false;
	for(int i=0; 200>i; i++) t2PrintedPrs[i]=false;
	
	int numGames=getNumGames(m);
	int t1Index=0;
	int t2Index=0;
	for(int i=1; 5>=i && numGames-i>=0 ;i++){
		for(int j=0; 11>j; j++){
			if(m[numGames-i].t1_prs[j]>0){
				int Id=m[numGames-i].t1_prs[j];
				int Index=tm1.getPrIndexFromId(Id);
				if(t1PrintedPrs[Index]) continue;
				t1PrintedPrs[Index]=true;
				t1Ids[t1Index++]=Id;
			}
		}
		
		for(int j=0; 11>j; j++){
			if(m[numGames-i].t2_prs[j]>0){
				int Id=m[numGames-i].t2_prs[j];
				int Index=tm2.getPrIndexFromId(Id);
				if(t2PrintedPrs[Index]) continue;
				t2PrintedPrs[Index]=true;
				t2Ids[t2Index++]=Id;
			}
		}
		
		for(int j=0; 3>j; j++){
			if(m[numGames-i].t1_tvz[j]>0){
				int Id=m[numGames-i].t1_tvz[j];
				int Index=tm1.getPrIndexFromId(Id);
				if(t1PrintedPrs[Index]) continue;
				t1PrintedPrs[Index]=true;
				t1Ids[t1Index++]=Id;
			}
		}
		
		for(int j=0; 3>j; j++){
			if(m[numGames-i].t2_tvz[j]>0){
				int Id=m[numGames-i].t2_tvz[j];
				int Index=tm2.getPrIndexFromId(Id);
				if(t2PrintedPrs[Index]) continue;
				t2PrintedPrs[Index]=true;
				t2Ids[t2Index++]=Id;
			}
		}
	}
	
	for(int i=0; tm1.getPrFromIndex(i).sendexist(); i++){
		int Index=i;
		int Id=tm1.getPrFromIndex(i).getId();
		if(t1PrintedPrs[Index]) continue;
		t1PrintedPrs[Index]=true;
		t1Ids[t1Index++]=Id;
	}
	
	for(int i=0; tm2.getPrFromIndex(i).sendexist(); i++){
		int Index=i;
		int Id=tm2.getPrFromIndex(i).getId();
		if(t2PrintedPrs[Index]) continue;
		t2PrintedPrs[Index]=true;
		t2Ids[t2Index++]=Id;
	}
	
	int t1NumPrs=t1Index;
	int t2NumPrs=t2Index;
	
	
	int t=20;
	int tDash=42;
	stringstream cadr;
	cadr<<"$$BLU";
	setColor("BOLDBLUE");
	beforeStrWhere("Teams Squad List",tDash);
	setColor("RESET");
	cout<<endl;
	ccsPrint(cadr); space(1); cadr_dash(tDash); setColor("RESET");
	for(int i=0; t1NumPrs>i || t2NumPrs>i; i++){
		stringstream p1;
		stringstream p2;
		p1<<"$0MAG";
		p2<<"$0CYN";
		
		if(t1NumPrs>i) p1<<tm1.getPrFromId(t1Ids[i]).getNumber()<<": "<<tm1.getPrFromId(t1Ids[i]).sendname()<<"$0RST";
		else p1<<"$0RST";
		
		if(t2NumPrs>i) p2<<tm2.getPrFromId(t2Ids[i]).getNumber()<<": "<<tm2.getPrFromId(t2Ids[i]).sendname()<<"$0RST";
		else p2<<"$0RST";
		
		ccsPrint(cadr);
		cout<<" |";
		setColor("RESET");
		
		strwhere(p1,t,1);
		strwhere(p2,t,1);	

		ccsPrint(cadr);
		cout<<"|";
		setColor("RESET");
		cout<<endl;
	}
	ccsPrint(cadr); space(1); cadr_dash(tDash); setColor("RESET");
}


void showWALTable(teamGameStat teamOne,teamGameStat teamTwo,bool showCards, bool showSubs){
	int s,t,c,ttitle;
	stringstream ts1[14];
	stringstream ts2[14];
	stringstream cadr;
    stringstream temp1;
    stringstream temp2;
    stringstream temp3;
    stringstream temp4;
    stringstream temp5;
    stringstream temp6;
	
	bool exGoals=true;
	bool exPossess=(teamOne.possess!=-2 && teamTwo.possess!=-2);
	bool exShots=((teamOne.shots[0]!=-2 && teamOne.shots[1]!=-2) && (teamTwo.shots[0]!=-2 && teamTwo.shots[1]!=-2));
	bool exFouls=((teamOne.fouls[0]!=-2 && teamOne.fouls[1]!=-2) && (teamTwo.fouls[0]!=-2 && teamTwo.fouls[1]!=-2));
	bool exCorners=(teamOne.corners!=-2 && teamTwo.corners!=-2);
	bool exFk=(teamOne.fk!=-2 && teamTwo.fk!=-2);
	bool exPassC=(teamOne.passC!=-2 && teamTwo.passC!=-2);
	bool exCross=(teamOne.cross!=-2 && teamTwo.cross!=-2);
	bool exInterc=(teamOne.interc!=-2 && teamTwo.interc!=-2);
	bool exTackles=(teamOne.tackles!=-2 && teamTwo.tackles!=-2);
	bool exSaves=(teamOne.saves!=-2 && teamTwo.saves!=-2);
	bool exCards=((teamOne.nCards[0]!=-2 && teamOne.nCards[1]!=-2)
	&& (teamTwo.nCards[0]!=-2 && teamTwo.nCards[1]!=-2) && showCards);
	bool exSubs=(teamOne.nSub!=-2 && teamTwo.nSub!=-2 && showSubs);
	
	if(teamOne.nGoals==-2) ts1[0]<<"UK"; else ts1[0]<<setprecision(2)<<teamOne.nGoals;
	if(teamTwo.nGoals==-2) ts2[0]<<"UK"; else ts2[0]<<setprecision(2)<<teamTwo.nGoals;
	if(teamOne.possess==-2) ts1[1]<<"UK"; else ts1[1]<<setprecision(2)<<teamOne.possess<<"%";
	if(teamTwo.possess==-2) ts2[1]<<"UK"; else ts2[1]<<setprecision(2)<<teamTwo.possess<<"%";
	
	if(teamOne.shots[0]!=-2 && teamOne.shots[1]!=-2) ts1[2]<<setprecision(2)<<teamOne.shots[0]<<"("<<setprecision(2)<<teamOne.shots[1]<<")";
	if(teamTwo.shots[0]!=-2 && teamTwo.shots[1]!=-2) ts2[2]<<setprecision(2)<<teamTwo.shots[0]<<"("<<setprecision(2)<<teamTwo.shots[1]<<")";
	if(teamOne.fouls[0]!=-2 && teamOne.fouls[1]!=-2) ts1[3]<<setprecision(2)<<teamOne.fouls[0]<<"("<<setprecision(2)<<teamOne.fouls[1]<<")";
	if(teamTwo.fouls[0]!=-2 && teamTwo.fouls[1]!=-2) ts2[3]<<setprecision(2)<<teamTwo.fouls[0]<<"("<<setprecision(2)<<teamTwo.fouls[1]<<")";
	
	if(teamOne.corners==-2) ts1[4]<<"UK"; else ts1[4]<<setprecision(2)<<teamOne.corners;
	if(teamTwo.corners==-2) ts2[4]<<"UK"; else ts2[4]<<setprecision(2)<<teamTwo.corners;
	if(teamOne.fk==-2) ts1[5]<<"UK"; else ts1[5]<<setprecision(2)<<teamOne.fk;
	if(teamTwo.fk==-2) ts2[5]<<"UK"; else ts2[5]<<setprecision(2)<<teamTwo.fk;
	if(teamOne.passC==-2) ts1[6]<<"UK"; else ts1[6]<<setprecision(2)<<teamOne.passC<<"%";
	if(teamTwo.passC==-2) ts2[6]<<"UK"; else ts2[6]<<setprecision(2)<<teamTwo.passC<<"%";
	if(teamOne.cross==-2) ts1[7]<<"UK"; else ts1[7]<<setprecision(2)<<teamOne.cross;
	if(teamTwo.cross==-2) ts2[7]<<"UK"; else ts2[7]<<setprecision(2)<<teamTwo.cross;
	if(teamOne.interc==-2) ts1[8]<<"UK"; else ts1[8]<<setprecision(2)<<teamOne.interc;
	if(teamTwo.interc==-2) ts2[8]<<"UK"; else ts2[8]<<setprecision(2)<<teamTwo.interc;
	if(teamOne.tackles==-2) ts1[9]<<"UK"; else ts1[9]<<setprecision(2)<<teamOne.tackles;
	if(teamTwo.tackles==-2) ts2[9]<<"UK"; else ts2[9]<<setprecision(2)<<teamTwo.tackles;
	if(teamOne.saves==-2) ts1[10]<<"UK"; else ts1[10]<<setprecision(2)<<teamOne.saves;
	if(teamTwo.saves==-2) ts2[10]<<"UK"; else ts2[10]<<setprecision(2)<<teamTwo.saves;
	
	if(teamOne.nCards[0]!=-2 && teamOne.nCards[1]!=-2){
		ts1[11]<<setprecision(2)<<teamOne.nCards[0];
		ts1[12]<<setprecision(2)<<teamOne.nCards[1];
	}
	
	if(teamTwo.nCards[0]!=-2 && teamTwo.nCards[1]!=-2){
		ts2[11]<<setprecision(2)<<teamTwo.nCards[0];
		ts2[12]<<setprecision(2)<<teamTwo.nCards[1];
	}
	
	if(teamOne.nSub==-2) ts1[13]<<"UK"; else ts1[13]<<setprecision(2)<<teamOne.nSub;
	if(teamTwo.nSub==-2) ts2[13]<<"UK"; else ts2[13]<<setprecision(2)<<teamTwo.nSub;
	
	/*if(teamOne.shots[0]==-2 || teamOne.shots[1]==-2){
		if(teamOne.shots[0]==-2 && teamOne.shots[1]==-2) ts1[2]<<"UK";
		else if(teamOne.shots[0]==-2) ts1[2]<<"UK("<<setprecision(2)<<teamOne.shots[1]<<")";
		else ts1[2]<<setprecision(2)<<teamOne.shots[0]<<"(UK)";
	}
	
	if(teamTwo.shots[0]==-2 || teamTwo.shots[1]==-2){
		if(teamTwo.shots[0]==-2 && teamTwo.shots[1]==-2) ts2[2]<<"UK";
		else if(teamTwo.shots[0]==-2) ts2[2]<<"UK("<<setprecision(2)<<teamTwo.shots[1]<<")";
		else ts2[2]<<setprecision(2)<<teamTwo.shots[0]<<"(UK)";
	}
	
	if(teamOne.fouls[0]==-2 || teamOne.fouls[1]==-2){
		if(teamOne.fouls[0]==-2 && teamOne.fouls[1]==-2) ts1[3]<<"UK";
		else if(teamOne.fouls[0]==-2) ts1[3]<<"UK("<<setprecision(2)<<teamOne.fouls[1]<<")";
		else ts1[3]<<setprecision(2)<<teamOne.fouls[0]<<"(UK)";
	}
	
	if(teamTwo.fouls[0]==-2 || teamTwo.fouls[1]==-2){
		if(teamTwo.fouls[0]==-2 && teamTwo.fouls[1]==-2) ts2[3]<<"UK";
		else if(teamTwo.fouls[0]==-2) ts2[3]<<"UK("<<setprecision(2)<<teamTwo.fouls[1]<<")";
		else ts2[3]<<setprecision(2)<<teamTwo.fouls[0]<<"(UK)";
	}*/

	cadr<<"$$BLU";
	s=15;
	t=10;
	ttitle=22;
	c=ttitle+(2*t)+2;
	
	temp1.str("");
	cout<<endl;
	temp1<<"$$RED"<<teamOne.name<<" Against "<<teamTwo.name<<"$0RST";
	space(s); beforeStrWhere(temp1,c); cout<<endl<<endl;

	space(s); ccsPrint(cadr); cadr_dash(c);
	space(s); cout<<"|"; setColor("BOLDCYAN"); strwhere(teamOne.name,t,1); setColor("BOLDBLUE"); strwhere("Stats",ttitle,1); setColor("BOLDCYAN"); strwhere(teamTwo.name,t,1); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	
	if(exGoals){ space(s); cout<<"|"; strwhere(ts1[0],t); strwhere("Goals Scored",ttitle); strwhere(ts2[0],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	
	if(exCards){
		space(s); cout<<"|"; strwhere(ts1[11],t); strwhere("Yellow Cards",ttitle); strwhere(ts2[11],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
		space(s); cout<<"|"; strwhere(ts1[12],t); strwhere("Red Cards",ttitle); strwhere(ts2[12],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	}
	if(exSubs){ space(s); cout<<"|"; strwhere(ts1[13],t); strwhere("Number Of Subs",ttitle); strwhere(ts2[13],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	
	if(exPossess){ space(s); cout<<"|"; strwhere(ts1[1],t); strwhere("Possession",ttitle); strwhere(ts2[1],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exShots){ space(s); cout<<"|"; strwhere(ts1[2],t); strwhere("Shots (On Target)",ttitle); strwhere(ts2[2],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exFouls){ space(s); cout<<"|"; strwhere(ts1[3],t); strwhere("Fouls (Offside)",ttitle); strwhere(ts2[3],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exCorners){ space(s); cout<<"|"; strwhere(ts1[4],t); strwhere("Corner Kicks",ttitle); strwhere(ts2[4],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exFk){ space(s); cout<<"|"; strwhere(ts1[5],t); strwhere("Free Kicks",ttitle); strwhere(ts2[5],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exPassC){ space(s); cout<<"|"; strwhere(ts1[6],t); strwhere("Passes Completed (%)",ttitle); strwhere(ts2[6],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exCross){ space(s); cout<<"|"; strwhere(ts1[7],t); strwhere("Crosses",ttitle); strwhere(ts2[7],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exInterc){ space(s); cout<<"|"; strwhere(ts1[8],t); strwhere("Interception",ttitle); strwhere(ts2[8],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exTackles){ space(s); cout<<"|"; strwhere(ts1[9],t); strwhere("Tackles",ttitle); strwhere(ts2[9],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(exSaves){ space(s); cout<<"|"; strwhere(ts1[10],t); strwhere("Saves",ttitle); strwhere(ts2[10],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
}

void correctData(team &tm1, team &tm2, match *m,inputProfile &inpSettings){
    for(int i=0; tm1.getPrFromIndex(i).sendexist(); i++) tm1.pr[i].setOverall(-2);
    for(int i=0; tm2.getPrFromIndex(i).sendexist(); i++) tm2.pr[i].setOverall(-2);
    for(int i=0; m[i].sendexist(); i++){
        for(int j=0; 11>j; j++){
            if(m[i].t1_prs[j]==-2) m[i].t1_pov[j]=-1;
            else m[i].t1_pov[j]=-2;
        }
        for(int j=0; 11>j; j++){
            if(m[i].t2_prs[j]==-2) m[i].t2_pov[j]=-1;
            else m[i].t2_pov[j]=-2;
        }
        for(int j=0; 3>j; j++){
            if(m[i].t1_prs[j]<0) m[i].t1_pov[j]=-1;
            else m[i].t1_pov[j]=-2;
        }
        for(int j=0; 3>j; j++){
            if(m[i].t2_prs[j]<0) m[i].t2_pov[j]=-1;
            else m[i].t2_pov[j]=-2;
        }
        m[i].t1_left=-2;
        m[i].t1_center=-2;
        m[i].t1_right=-2;
        m[i].t2_left=-2;
        m[i].t2_center=-2;
        m[i].t2_right=-2;
    }
}


int stringToInt(char a[]){
    int t,out=0,zarb=1,r;
    int first;
    if(a[0]=='-') first=1;
    else first=0;
    if(a[first]==0) return INT_MAX;
    for (t=0; a[t]; t++);
    
    for (int i=first; t>i; i++){
		if(a[i]>57 || a[i]<48){
            return INT_MAX;
		}
    }
    
    if(t-first>9) return INT_MAX-1;
    for (int i=first; t-1>i; i++) zarb=zarb*10;
    for (int i=first; t>i; i++){
		r= a[i]-48;
		out=out+r*zarb;
		zarb=zarb/10;
    }
    
    if(first==1) out=-(out);
    return out;
}

int nextInt(){
    char numch[60];
    cin>>numch;
    cin.ignore();
    int out=stringToInt(numch);
    return out;
}

bool printCheckChoice (int a,int min,int max){
    if (min<0) min = 0;
    if (max<0) max = INT_MAX-2;
    if(a==INT_MAX){
        printError("You most Enter an Integer Number\n");
        return false;
    }
    if(a<min || a>max){
        setColor("BOLDRED");
        cout<<endl<<"Error: ";
        setColor("RESET");
        cout<<"Invalid Number. Your Num Most be Between "<<min<<","<<max<<endl;
        return false;
    }
    return true;
}

bool easycheck (int num, int min, int max){
    if(num<min || num>max) return false;
    return true;
}

bool ukEasycheck (int num, int min, int max,bool waAccept){
    if(num==-2) return true;
    if(waAccept && num==-1) return true;
    if(num<min || num>max) return false;
    return true;
}

bool ukEasycheck (int num, int min, int max){
    return ukEasycheck(num,min,max,false);
}

int inputChoice(int min,int max){
    int out;
    bool first=true;
    do{
        if(!first) cout<<endl<<"Enter Your Choice Again: ";
        out=nextInt();
        first=false;
    } while(!printCheckChoice(out,min,max));
    return out;
}

bool sure(){
    cout<<endl<<"Are you sure? (1:Yes | 2:No): ";
    return inputChoice(1,2)==1;
}


void printError(const char* er){
    typeError();
    cout<<er;
}

void sucPrint(const char* mes){
    setColor("BOLDGREEN");
    cout<<mes;
    setColor("RESET");
}

void rulePrint(const char * mes){
    typeRule();
    cout<<mes;
}

void blackPrint(const char* mes){
    setColor("BOLDBLACK");
    cout<<mes;
    setColor("RESET");
}

void typeWarning(){
    setColor("BOLDYELLOW");
    cout<<"Warning: ";
    setColor("RESET"); 
}

void typeRule(){
    setColor("BOLDGREEN");
    cout<<"Rule: ";
    setColor("RESET"); 
}

void typeError(){
    setColor("BOLDRED");
    cout<<"Error: ";
    setColor("RESET"); 
}

void noBoldBlackPrint(const char* mes){
    setColor("BLACK");
    cout<<mes;
    setColor("RESET");
}

void boldGreenPrint(const char* mes){
    setColor("BOLDGREEN");
    cout<<mes;
    setColor("RESET");
}

void boldRedPrint(const char* mes){
    setColor("BOLDRED");
    cout<<mes;
    setColor("RESET");
}


void match::set_goals(team tm1,team tm2,bool edit){
    stringstream temp1;
    stringstream temp2;
	int choice,error=0;
    int oldTG=-1;
    
    start:
    if(edit){
        edit=false;
        oldTG=tg;
        goto finalaproval;
    }
    
	cout<<"\nEnter Goals Respectively (According to ID)\n";
	t1_goals=nextInt();
    t2_goals=nextInt();
    
    finalaproval:
	temp1.str("");
	temp2.str("");
    if(t1_goals<0 || t1_goals>20){ temp1<<"Null"; error=1;} else if(t1_goals>=0) temp1<<t1_goals;
	if(t2_goals<0 || t2_goals>20){ temp2<<"Null"; error=1;} else if(t2_goals>=0) temp2<<t2_goals;
	cout<<endl; setColor("BOLDBLUE"); cout<<tm1.name<<" "; ccsPrint(temp1); cout<<" - "; ccsPrint(temp2); cout<<" "<<tm2.name; setColor("RESET"); cout<<endl;
	if(error==1){
		cout<<endl; setColor("BOLDYELLOW"); cout<<"Invalid Value For Goals. Try again.\n"; setColor("RESET");
		goto start;
		return;
	}
	
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
    choice=inputChoice(1,2);
	if(choice==2) goto start;
    if(t1_goals+t2_goals<oldTG){
        cout<<endl;
        typeWarning();
        cout<<"Details of "<<oldTG-(t1_goals+t2_goals)<<" Goals Will Remove. Are You Sure? (1:Yes | 2:No): ";
        if(inputChoice(1,2)==2) goto finalaproval;
        for(int i=t1_goals+t2_goals; oldTG-(t1_goals+t2_goals)>i; i++){
            for(int j=0; 5>j; j++) goals[i][j]=0;
        }
    }
    
	if(t1_goals>t2_goals) res=1; else if(t2_goals>t1_goals) res=2; else if(t1_goals==t2_goals) res=3;
    tg=t1_goals+t2_goals;
}
void match::set_possess_shots(team tm1,team tm2,bool edit){
    stringstream temp1;
    stringstream temp2;
    stringstream temp3;
    stringstream temp4;
    stringstream temp5;
    stringstream temp6;
	int choice,error=0;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	temp5.str("");
	temp6.str("");
    if(edit){
        edit=false;
        goto finalaproval;
    }
    
	cout<<"\nEnter Possession Respectively:\n"; cin>>t1_possess>>t2_possess; cin.ignore();
	cout<<"\nEnter Shots(On Target) Respectively"<<endl<<"Help: T1_Shots | T1_On_Target | T2_Shots | T2_On_Target:\n"; cin>>t1_shots[0]>>t1_shots[1]>>t2_shots[0]>>t2_shots[1]; cin.ignore();
    
    finalaproval:
	if(t1_possess==-2) temp1<<"UK"; else if(t1_possess<0){ temp1<<"Null"; error=1;} else if(t1_possess>=0) temp1<<t1_possess;
	if(t2_possess==-2) temp2<<"UK"; else if(t2_possess<0){ temp2<<"Null"; error=1;} else if(t2_possess>=0) temp2<<t2_possess;
	if(t1_shots[0]==-2) temp3<<"UK"; else if(t1_shots[0]<0){ temp3<<"Null"; error=1;} else if(t1_shots[0]>=0) temp3<<t1_shots[0];
	if(t1_shots[1]==-2) temp4<<"UK"; else if(t1_shots[1]<0){ temp4<<"Null"; error=1;} else if(t1_shots[1]>=0) temp4<<t1_shots[1];
	if(t2_shots[0]==-2) temp5<<"UK"; else if(t2_shots[0]<0){ temp5<<"Null"; error=1;} else if(t2_shots[0]>=0) temp5<<t2_shots[0];
	if(t2_shots[1]==-2) temp6<<"UK"; else if(t2_shots[1]<0){ temp6<<"Null"; error=1;} else if(t2_shots[1]>=0) temp6<<t2_shots[1];
	if(t1_shots[0]<t1_shots[1] || t2_shots[0]<t2_shots[1]) error=1;
	setColor("BOLDBLUE"); cout<<endl<<"Possession: "<<tm1.name<<": "; ccsPrint(temp1); cout<<" | "<<tm2.name<<": "; ccsPrint(temp2); cout<<endl;
	cout<<"Shots (On Target): "<<tm1.name<<": "; ccsPrint(temp3); cout<<"("; ccsPrint(temp4); cout<<")"<<" | "<<tm2.name<<": "; ccsPrint(temp5); cout<<"("; ccsPrint(temp6); cout<<")"<<endl; setColor("RESET");
	if(t1_possess!=-2 && t2_possess!=-2 && t1_possess+t2_possess!=100){ cout<<endl; setColor("BOLDYELLOW"); cout<<"Error In Possession\n"; setColor("RESET"); cout<<endl; set_possess_shots(tm1,tm2); return;}
	if(error==1){
		cout<<endl; setColor("BOLDYELLOW"); cout<<"Error Dar Vared kardane Etelaat. Try again.\n"; setColor("RESET");
		set_possess_shots(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
    choice=inputChoice(1,2);
	if(choice==2){ set_possess_shots(tm1,tm2); return;}	
}

void match::set_fouls_corners(team tm1,team tm2,bool edit){
    stringstream temp1;
    stringstream temp2;
    stringstream temp3;
    stringstream temp4;
    stringstream temp5;
    stringstream temp6;
	int choice,error=0;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	temp5.str("");
	temp6.str("");
    if(edit){
        edit=false;
        goto finalaproval;
    }
    
	cout<<"\nEnter Fouls(Offsides) Respectively:\n"; cin>>t1_fouls[0]>>t1_fouls[1]>>t2_fouls[0]>>t2_fouls[1]; cin.ignore();
	cout<<"\nEnter Corners Respectively"<<endl; cin>>t1_corners>>t2_corners; cin.ignore();
    
    finalaproval:
	if(t1_fouls[0]==-2) temp1<<"UK"; else if(t1_fouls[0]<0){ temp1<<"Null"; error=1;} else if(t1_fouls[0]>=0) temp1<<t1_fouls[0];
	if(t1_fouls[1]==-2) temp2<<"UK"; else if(t1_fouls[1]<0){ temp2<<"Null"; error=1;} else if(t1_fouls[1]>=0) temp2<<t1_fouls[1];
	if(t2_fouls[0]==-2) temp3<<"UK"; else if(t2_fouls[0]<0){ temp3<<"Null"; error=1;} else if(t2_fouls[0]>=0) temp3<<t2_fouls[0];
	if(t2_fouls[1]==-2) temp4<<"UK"; else if(t2_fouls[1]<0){ temp4<<"Null"; error=1;} else if(t2_fouls[1]>=0) temp4<<t2_fouls[1];
	if(t1_corners==-2) temp5<<"UK"; else if(t1_corners<0){ temp5<<"Null"; error=1;} else if(t1_corners>=0) temp5<<t1_corners;
	if(t2_corners==-2) temp6<<"UK"; else if(t2_corners<0){ temp6<<"Null"; error=1;} else if(t2_corners>=0) temp6<<t2_corners;
	cout<<endl; setColor("BOLDBLUE"); cout<<"Fouls (Offsides): "<<tm1.name<<": "; ccsPrint(temp1); cout<<"("; ccsPrint(temp2); cout<<")"<<" | "<<tm2.name<<": "; ccsPrint(temp3); cout<<"("; ccsPrint(temp4); cout<<")"<<endl;
	cout<<"Corners: "<<tm1.name<<": "; ccsPrint(temp5); cout<<" | "<<tm2.name<<": "; ccsPrint(temp6); cout<<endl; setColor("RESET");
	
	if(error==1){
		cout<<endl; setColor("BOLDYELLOW"); cout<<"Error Dar Vared kardane Etelaat. Try again.\n"; setColor("RESET");
		set_fouls_corners(tm1,tm2);
		return;
	}
	
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
    choice=inputChoice(1,2);
	if(choice==2){ set_fouls_corners(tm1,tm2); return;}	
}

void match::set_fk_passc_cross(team tm1,team tm2,bool edit){
    stringstream temp1;
    stringstream temp2;
    stringstream temp3;
    stringstream temp4;
    stringstream temp5;
    stringstream temp6;
	int choice,error=0;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	temp5.str("");
	temp6.str("");
    if(edit){
        edit=false;
        goto finalaproval;
    }
    
	cout<<"\nEnter Freekicks Respectively:\n"; cin>>t1_fk>>t2_fk; cin.ignore();
	cout<<"\nEnter Passess Completed Respectively:"<<endl; cin>>t1_pass_c>>t2_pass_c; cin.ignore();
	cout<<"\nEnter Crossess Respectively:"<<endl; cin>>t1_cross>>t2_cross; cin.ignore();
    
    finalaproval:
	if(t1_fk==-2) temp1<<"UK"; else if(t1_fk<0){ temp1<<"Null"; error=1;} else if(t1_fk>=0) temp1<<t1_fk;
	if(t2_fk==-2) temp2<<"UK"; else if(t2_fk<0){ temp2<<"Null"; error=1;} else if(t2_fk>=0) temp2<<t2_fk;
	if(t1_pass_c==-2) temp3<<"UK"; else if(t1_pass_c<0){ temp3<<"Null"; error=1;} else if(t1_pass_c>=0) temp3<<t1_pass_c;
	if(t2_pass_c==-2) temp4<<"UK"; else if(t2_pass_c<0){ temp4<<"Null"; error=1;} else if(t2_pass_c>=0) temp4<<t2_pass_c;
	if(t1_cross==-2) temp5<<"UK"; else if(t1_cross<0){ temp5<<"Null"; error=1;} else if(t1_cross>=0) temp5<<t1_cross;
	if(t2_cross==-2) temp6<<"UK"; else if(t2_cross<0){ temp6<<"Null"; error=1;} else if(t2_cross>=0) temp6<<t2_cross;
	setColor("BOLDBLUE"); cout<<endl<<"Freekicks: "<<tm1.name<<": "; ccsPrint(temp1); cout<<" | "<<tm2.name<<": "; ccsPrint(temp2); cout<<endl;
	cout<<"Passess Completed: "<<tm1.name<<": "; ccsPrint(temp3); cout<<"% | "<<tm2.name<<": "; ccsPrint(temp4); cout<<"%"<<endl;
	cout<<"Crossess: "<<tm1.name<<": "; ccsPrint(temp5); cout<<" | "<<tm2.name<<": "; ccsPrint(temp6); cout<<endl; setColor("RESET");
	if(t1_pass_c>100 || t2_pass_c>100){ setColor("BOLDYELLOW"); cout<<"Error In Passes Completed\n"<<endl; setColor("RESET"); set_fk_passc_cross(tm1,tm2); return;}
	if(error==1){
		cout<<endl; setColor("BOLDYELLOW"); cout<<"Error Dar Vared kardane Etelaat. Try again.\n"; setColor("RESET");
		set_fk_passc_cross(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
    choice=inputChoice(1,2);
	if(choice==2){ set_fk_passc_cross(tm1,tm2); return;}	
}

void match::set_ic_tackle_save(team tm1,team tm2,bool edit){
	int choice,error=0;
    stringstream temp1;
    stringstream temp2;
    stringstream temp3;
    stringstream temp4;
    stringstream temp5;
    stringstream temp6;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
	temp5.str("");
	temp6.str("");
    if(edit){
        edit=false;
        goto finalaproval;
    }
    
	cout<<"\nEnter Interceptions Respectively:\n"; cin>>t1_interc>>t2_interc; cin.ignore();
	cout<<"\nEnter Tackles Respectively:"<<endl; cin>>t1_tackles>>t2_tackles; cin.ignore();
	cout<<"\nEnter Saves Respectively:"<<endl; cin>>t1_saves>>t2_saves; cin.ignore();
    
    finalaproval:
	if(t1_interc==-2) temp1<<"UK"; else if(t1_interc<0){ temp1<<"Null"; error=1;} else if(t1_interc>=0) temp1<<t1_interc;
	if(t2_interc==-2) temp2<<"UK"; else if(t2_interc<0){ temp2<<"Null"; error=1;} else if(t2_interc>=0) temp2<<t2_interc;
	if(t1_tackles==-2) temp3<<"UK"; else if(t1_tackles<0){ temp3<<"Null"; error=1;} else if(t1_tackles>=0) temp3<<t1_tackles;
	if(t2_tackles==-2) temp4<<"UK"; else if(t2_tackles<0){ temp4<<"Null"; error=1;} else if(t2_tackles>=0) temp4<<t2_tackles;
	if(t1_saves==-2) temp5<<"UK"; else if(t1_saves<0){ temp5<<"Null"; error=1;} else if(t1_saves>=0) temp5<<t1_saves;
	if(t2_saves==-2) temp6<<"UK"; else if(t2_saves<0){ temp6<<"Null"; error=1;} else if(t2_saves>=0) temp6<<t2_saves;
	setColor("BOLDBLUE"); cout<<endl<<"Interceptions: "<<tm1.name<<": "; ccsPrint(temp1); cout<<" | "<<tm2.name<<": "; ccsPrint(temp2); cout<<endl;
	cout<<"Tackles: "<<tm1.name<<": "; ccsPrint(temp3); cout<<" | "<<tm2.name<<": "; ccsPrint(temp4); cout<<endl;
	cout<<"Saves: "<<tm1.name<<": "; ccsPrint(temp5); cout<<" | "<<tm2.name<<": "; ccsPrint(temp6); cout<<endl; setColor("RESET");
	if(error==1){
		cout<<endl; setColor("BOLDYELLOW"); cout<<"Error Dar Vared kardane Etelaat. Try again.\n"; setColor("RESET");
		set_ic_tackle_save(tm1,tm2);
		return;
	}
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
    choice=inputChoice(1,2);
	if(choice==2){ set_ic_tackle_save(tm1,tm2); return;}		
}

void match::setLineup(team tm,bool first,bool edit){
    int *inputArray;
    int *otherArray;
    int tedad;
        
    start:
    if(first){
        if(tm.sendid()==1) inputArray=t1_prs;
        else if(tm.sendid()==2) inputArray=t2_prs;
        tedad=11;
    }
    else{
        if(tm.sendid()==1){
            otherArray=t1_prs;
            inputArray=t1_tvz;
            if(!edit){
                cout<<endl<<"Enter Number Of "<<tm.getName()<<" Subs: ";
                t1_tt=inputChoice(0,3);
            }
            tedad=t1_tt;
        }
        else if(tm.sendid()==2){
            otherArray=t2_prs;
            inputArray=t2_tvz;
            if(!edit){
                cout<<endl<<"Enter Number Of "<<tm.getName()<<" Subs: ";
                t2_tt=inputChoice(0,3);
            }
            tedad=t2_tt;
        }
    }
    
    if(edit){
        edit=false;
        goto printplayers;
    }
        
    if(!first && tedad==0){
        if(sure()){
            for(int i=0; 3>i; i++) inputArray[i]=-1;
            return;
        }
        else goto start;
    }
        
	int choice,j,error,secondError;
    int err[11];
        
	if(first) cout<<"\nEnter 11 Numbers For "<<tm.getName()<<" First Line Up\n";
    else cout<<"\nEnter "<<tedad<<" Numbers For "<<tm.getName()<<" Substitutes Players\n";
        
	for(int i=0; tedad>i; i++){ inputArray[i]=nextInt();}
        
        
	printplayers:
    for(int i=0; tedad>i; i++) err[i]=0;
	cout<<endl;
    setColor("BOLDBLUE");
    bool existEr=false;
	for(int i=0; tedad>i; i++){
		if(inputArray[i]==-2){
            setColor("BOLDBLACK");
            cout<<i+1<<": ";
            cout<<"UK";
            setColor("RESET");
        }
        else if(inputArray[i]>(INT_MAX-2)){
            setColor("RED");
            cout<<i+1<<": ";
            cout<<"Null";
            err[i]=1;
            existEr=true;
            setColor("RESET");
        }
		else if(!tm.existNumber(inputArray[i])){
            setColor("RED");
            cout<<i+1<<": ";
            cout<<"Null";
            err[i]=2;
            existEr=true;
            setColor("RESET");
        }
		else if(tm.existNumber(inputArray[i])){
            setColor("BOLDBLUE");
            cout<<i+1<<": ";
            cout<<tm.getPrFromNumber(inputArray[i]).sendname();
            setColor("RESET");
        }
		cout<<endl;
	}
	error=0;
    secondError=0;
	for (int i=0; tedad>i; i++){
		if(error==0 && inputArray[i]>0 && err[i]==0){
            for(int j=i+1; tedad>j; j++){
                if(inputArray[i]==inputArray[j]){
                    error=1;
                    break;
                }
            }
        }
        if(!first && secondError==0 && inputArray[i]>0){
            for(int j=0; 11>j; j++){
                if(inputArray[i]==otherArray[j]){
                    secondError=1;
                    break;
                }
            }
        }
        if(error!=0 && secondError!=0) break;     
    }
 
    bool oneEndl=false;
    for(int i=0; 11>i; i++){
        if(!oneEndl) cout<<endl;
        oneEndl=true;
        if(err[i]==1){
            char sprTemp[70];
            sprintf(sprTemp,"Player %d: Entering Non Numerical String\n",i+1);
            printError(sprTemp);
        }
        else if(err[i]==2){
            char sprTemp[70];
            sprintf(sprTemp,"Player %d: There is No Player with This Number\n",i+1);
            printError(sprTemp);
        }
    }
    if(error==1) printError("Same Players In Line Up!\n");
    if(secondError==1) printError("Same Players In First Line Up And Substitutes Line Up!\n");
        
	cout<<endl;
    setColor("BOLDRED");
    cout<<"Do you want to edit a Player?\n";
    setColor("RESET");
    cout<<"1: No\n2: Yes\n";
    if(first) cout<<"3: Enter Line Up From The Beginning\n";
    else cout<<"3: Set Substitution From The Beginning\n";
    cout<<endl<<"Enter Your Choice: ";
    choice=inputChoice(1,3);
    if(choice==3) goto start;
	if(choice==2){
		cout<<"Player List Number?: ";
        j=inputChoice(1,tedad);
		cout<<"Enter New Player Number: ";
		inputArray[j-1]=nextInt();
		goto printplayers;
	}
	if(error==1 || secondError || existEr){
        cout<<endl;
        if(error==1) printError("Same Players In Line Up!\n");
        if(existEr) printError("Invalid Values In Line Up!\n");
        if(secondError==1) printError("Same Players In First Line Up And Substitutes Line Up!\n");
		setColor("BOLDYELLOW"); cout<<"Please Enter Line Up From The Beginning\n"; setColor("RESET");
		goto start;
	}
}


void match::set_goals_scorers(team tm1,team tm2, inputProfile& inpSettings,bool edit, bool checkAfterEdit){
	int choice, j, inpg1,inpg2;
    int error;
        
    start:
	while(1){
        
        if(checkAfterEdit){
            checkAfterEdit=false;
            error=0;
            inpg1=0; inpg2=0;
            for(int i=0; tg>i; i++){
                if(goals[i][0]==1) inpg1++; else if(goals[i][0]==2) inpg2++;
            }
            
            if(t1_goals != inpg1 || t2_goals != inpg2){
                error=1;
            }
            if(error==0){
                goto chapgoals;
            }
            else{
                cout<<endl;
                printError("Your Edit Cause Error In Goals Scorers Section\n");
                goto chapgoals;
            }
        }
        
		if(tg==0){
			for(int i=0; 30>i; i++) for(int k=0; 5>k; k++) goals[i][k]=-1;
			break;
		}
        
        if(edit){
            edit=false;
            goto chapgoals;
        }
        
		cout<<"\nEnter "<<tg<<" Goals:\n";
		setColor("BOLDYELLOW"); cout<<"Instruction: "; setColor("RESET");
        cout<<"Team ID-Scorer ID";
        if(inpSettings.getAssists()) cout<<"-Assister ID";
        if(inpSettings.getGoalsTimes()) cout<<"-Minute";
        cout<<"\n";
        if(inpSettings.getGoalsTimes()){
            setColor("BOLDYELLOW"); cout<<"Rule: "; setColor("RESET");
            cout<<"If the Goal Has been Scored in Last Minute Of Normal Time\n";
            cout<<"Enter Minute in Two Number (Normal Time Then Extra Time)\n";
        }
        
        rulePrint("Own Goal Number=-1\n");
        if(inpSettings.getAssists()){
            typeRule();
            cout<<"Without Assist Number=-1;\n";
        }
        
		for(int i=0; tg>i; i++){
			cout<<endl<<i+1<<": ";
            if(!enterGoal(i,tm1,tm2,inpSettings)){
                goto start;
            }
            cout<<"Goal "<<i+1<<": ";
            printGoal(i,tm1,tm2,inpSettings);
		}
                
		chapgoals:
		cout<<endl; setColor("BOLDBLUE"); cout<<"All Goals: \n";
		for(int i=0; tg>i; i++){
            cout<<"Goal "<<i+1<<": ";
            printGoal(i,tm1,tm2,inpSettings);
		}
		setColor("RESET"); cout<<endl;
                
        finalquest:
		inpg1=0; inpg2=0;
		for(int i=0; tg>i; i++){
			if(goals[i][0]==1) inpg1++; else if(goals[i][0]==2) inpg2++;
		}
        error=0;
		if(t1_goals != inpg1 || t2_goals != inpg2){
            cout<<endl;
            printError("Contradiction Between Number Of Goals And These Inputs!!!\n");
            error=1;
        }
        
        if(error==0 && checkAfterEdit) return;
        else if(checkAfterEdit) checkAfterEdit=false;

		cout<<endl;
        setColor("BOLDRED"); cout<<"Next Work?\n"; setColor("RESET");
        if(error==0) cout<<"1: Apply And Go to Next Session\n";
        cout<<2-error<<": Edit A Goal\n";
        cout<<3-error<<": Enter Goals From The Beginning\n";
        cout<<4-error<<": Compatible Number Of Goals With Goals Inputs And Apply\n";
        cout<<5-error<<": Edit Game Input Settings\n";
        cout<<6-error<<": Go to Number of Goals Session\n";
        cout<<7-error<<": Go To Line Up Session\n";
        cout<<endl<<"Enter Your Choice: ";
        choice=inputChoice(1,7-error);
		if(choice==2-error){
			cout<<"Goal List Number?: ";
            j=inputChoice(1,tg);
			j--;
			cout<<"Enter The Goal: ";
            if(!enterGoal(j,tm1,tm2,inpSettings)){
                set_goals(tm1,tm2);
                goto start;
            }
			goto chapgoals;
		}
        else if(choice==3-error) goto start;
        else if(choice==4-error){
            setColor("BOLDBLUE");
            cout<<endl<<tm1.getName()<<" "<<inpg1<<" - "<<inpg2<<" "<<tm2.getName()<<endl;
            setColor("RESET");
                    
            cout<<endl<<"Are you sure? (1:Yes | 2:No Cancel It): ";
            int ch=inputChoice(1,2);
            if(ch==2) goto finalquest;
            t1_goals=inpg1;
            t2_goals=inpg2;
            setColor("GREEN");
            cout<<endl<<"Number Of Goals Compatible With Inputs\n";
            setColor("RESET");
        }
        
        else if(choice==5-error){
            inpSettings.settings();
            goto chapgoals;
        } 
        
        else if(choice==6-error){
            set_goals(tm1,tm2);
            goto start;
        } 
                
        else if(choice==7-error){
            setColor("BOLDRED");
            cout<<"Works:\n";
            setColor("RESET");
            cout<<"1: Enter Complete Teams Line Ups\n";
            cout<<"2: Enter "<<tm1.getName()<<" Line Up\n";
            cout<<"3: Enter "<<tm2.getName()<<" Line Up\n";
            cout<<"4: Cancel And Try Again to Entering Goal\n";
            choice=inputChoice(1,4);
            if(choice==1){
                setFirstLineup(tm1);
                setFirstLineup(tm2);
                setSubLineup(tm1);
                setSubLineup(tm2);
            }
            else if(choice==2){
                setFirstLineup(tm1);
                setSubLineup(tm1);
            }
            else if(choice==3){
                setFirstLineup(tm2);
                setSubLineup(tm2);
            }
            if(choice!=4) goto start;
        }
                	
		for(int i=0; 30-tg>i; i++) for(int k=0; 5>k; k++) goals[29-i][k]=-1;
		break;
	}
}

void match::set_tcards(team tm1,team tm2,bool edit){
	int choice,error=0;
    int oldTC=-1;
    stringstream temp1;
    stringstream temp2;
    stringstream temp3;
    stringstream temp4;
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
    
    start:
    if(edit){
        edit=false;
        oldTC=tcards;
        goto finalaproval;
    }
    
	cout<<"\nEnter Respectively Number of Team1 Yellow Cards | Team1 Red Cards | Team2 Yellow Cards | Team2 Red Cards\n";
	t1_tc[0]=nextInt();
    t1_tc[1]=nextInt();
    t2_tc[0]=nextInt();
    t2_tc[1]=nextInt();
    
    finalaproval:
	if((t1_tc[0]>11 || t1_tc[0]<0)){ temp1<<"Null"; error=1;} else temp1<<t1_tc[0];
	if((t1_tc[1]>11 || t1_tc[1]<0)){ temp2<<"Null"; error=1;} else temp2<<t1_tc[1];
	if((t2_tc[0]>11 || t2_tc[0]<0)){ temp3<<"Null"; error=1;} else temp3<<t2_tc[0];
	if((t2_tc[1]>11 || t2_tc[1]<0)){ temp4<<"Null"; error=1;} else temp4<<t2_tc[1];
	cout<<endl; setColor("BOLDBLUE"); cout<<tm1.name<<": Yellow cards: "; ccsPrint(temp1); cout<<" | Red cards: "; ccsPrint(temp2); cout<<endl;
	cout<<tm2.name<<": Yellow cards: "; ccsPrint(temp3); cout<<" | Red cards: "; ccsPrint(temp4); cout<<endl; setColor("RESET");
	if(error==1){
		cout<<endl; setColor("BOLDYELLOW"); cout<<"Error!!! Invalid Numbers! Try again.\n"; setColor("RESET");
		goto start;
		return;
	}
	
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
    choice=inputChoice(1,2);
	if(choice==2) goto start;
    int nrem=0;
    if(t1_tc[0]==-2 || t1_tc[1]==-2 || t2_tc[0]==-2 || t2_tc[1]==-2) nrem=oldTC;
    else nrem=oldTC-t1_tc[0]-t1_tc[1]-t2_tc[0]-t2_tc[1];
    if(nrem>0){
        cout<<endl;
        typeWarning();
        cout<<"Details of "<<nrem<<" Cards Will Remove. Are You Sure? (1:Yes | 2:No): ";
        if(inputChoice(1,2)==2) goto finalaproval;
        int start=oldTC-nrem;
        for(int i=start; nrem-start>i; i++){
            for(int j=0; 5>j; j++) cards[i][j]=0;
        }
    }
    
	if(t1_tc[0]==-2 || t1_tc[1]==-2) t1_tc[2]=-2; else t1_tc[2]=t1_tc[0]+t1_tc[1];
	if(t2_tc[0]==-2 || t2_tc[1]==-2) t2_tc[2]=-2; else t2_tc[2]=t2_tc[0]+t2_tc[1];
	if(t1_tc[2]==-2 || t2_tc[2]==-2) tcards=-2; else tcards=t1_tc[2]+t2_tc[2];
}

void match::set_cards(team tm1,team tm2,inputProfile& inpSettings,bool edit, bool checkAfterEdit){
	int choice,inptc1[2],inptc2[2],j;
    int firstError,secondError,error;
        
    start:
	while(1){
        if(checkAfterEdit){
            checkAfterEdit=false;
            inptc1[0]=0; inptc1[1]=0; inptc2[0]=0; inptc2[1]=0;
            for(int i=0; tcards>i; i++){
                if(cards[i][2]==1){ if(cards[i][0]==1) inptc1[0]++; else if(cards[i][0]==2) inptc2[0]++;}
                if(cards[i][2]==2){ if(cards[i][0]==1) inptc1[1]++; else if(cards[i][0]==2) inptc2[1]++;}
            }

            firstError=0;
            if(t1_tc[0] != inptc1[0] || t1_tc[1] != inptc1[1] || t2_tc[0] != inptc2[0] || t2_tc[1] != inptc2[1]){
                firstError=1;
            }

            secondError=0;
            for(int i=0; tcards-1>i && secondError==0; i++){
                for(int j=i+1; tcards>j && secondError==0; j++){
                    if(cards[i][0]==cards[j][0] && cards[i][2]==cards[j][2] && cards[i][3]==cards[j][3]){
                        secondError=1;
                    }
                    else if(cards[i][0]==cards[j][0] && cards[i][3]==cards[j][3]){
                        if((cards[i][2]==2 && cards[i][4]<cards[j][4]) ||
                                (cards[j][2]==2 && cards[j][4]<cards[i][4])){
                            secondError=1;
                        }
                    }
                }
            }
            
            if(firstError==0 && secondError==0){
                goto chapcards;
                return;
            }
            else{
                cout<<endl;
                printError("Your Edit Cause Error In Cards Details Section\n");
                goto chapcards;
            }
        }
        
		if(tcards==-2){
			for(int i=0; 28>i; i++) for(int k=0; 5>k; k++) cards[i][k]=-2;
			break;
		}
		if(tcards==0){
			for(int i=0; 28>i; i++) for(int k=0; 5>k; k++) cards[i][k]=-1;
			break;
		}
        
        if(edit){
            edit=false;
            goto chapcards;
        }
                
		cout<<"\nEnter "<<tcards<<" Cards:\n";
		setColor("BOLDYELLOW"); cout<<"Instruction: "; setColor("RESET");
        cout<<"Team-Color-Player ID";
        if(inpSettings.getCardsTimes()) cout<<"-Minute";
        cout<<"\n";
        if(inpSettings.getCardsTimes()){
            typeRule();
            cout<<"If the Cart Has been Showed in Last Minute Of Normal Time\n";
            cout<<"Enter Minute in Two Number (Normal Time Then Extra Time)\n";
        }
                
		for(int i=0; tcards>i; i++){
            cout<<endl<<i+1<<": ";
            if(!enterCard(i,tm1,tm2,inpSettings)){
                goto start;
            }
            cout<<"Card "<<i+1<<": ";
            printCard(i,tm1,tm2,inpSettings);
        }
                
		chapcards:
		cout<<endl; setColor("BOLDBLUE"); cout<<"All Cards: \n";	
		for(int i=0; tcards>i; i++){
            cout<<"Card "<<i+1<<": ";
            printCard(i,tm1,tm2,inpSettings);
		}
		setColor("RESET"); cout<<endl;
                
                
        finalquest:
		inptc1[0]=0; inptc1[1]=0; inptc2[0]=0; inptc2[1]=0;
		for(int i=0; tcards>i; i++){
			if(cards[i][2]==1){ if(cards[i][0]==1) inptc1[0]++; else if(cards[i][0]==2) inptc2[0]++;}
			if(cards[i][2]==2){ if(cards[i][0]==1) inptc1[1]++; else if(cards[i][0]==2) inptc2[1]++;}
		}
		
        firstError=0;
		if(t1_tc[0] != inptc1[0] || t1_tc[1] != inptc1[1] || t2_tc[0] != inptc2[0] || t2_tc[1] != inptc2[1]){
            cout<<endl;
            printError("Contradiction Between Number Of Cards And These Inputs!!!\n");
            firstError=1;
        }
                
        secondError=0;
		for(int i=0; tcards-1>i && secondError==0; i++){
			for(int j=i+1; tcards>j && secondError==0; j++){
				if(cards[i][0]==cards[j][0] && cards[i][2]==cards[j][2] && cards[i][3]==cards[j][3]){
                    if(error==0) cout<<endl;
                    printError("There is A player Who get More Than One Yellow Or Red Card!!!\n");
                    secondError=1;
                }
                else if(cards[i][0]==cards[j][0] && cards[i][3]==cards[j][3]){
                    if((cards[i][2]==2 && cards[i][4]<cards[j][4]) ||
                            (cards[j][2]==2 && cards[j][4]<cards[i][4])){
                        if(error==0) cout<<endl;
                        printError("There is A player Who get Red Card Before Yellow Card!!!\n");
                        secondError=1;
                    }
                }
			}
		}
                
        if(firstError || secondError) error=1;
        if(error==0 && checkAfterEdit) return;
        else if(checkAfterEdit) checkAfterEdit=false;
                
		cout<<endl;
        setColor("BOLDRED"); cout<<"Next Work?\n"; setColor("RESET");
        if(error==0) cout<<"1: Apply And Go to Next Session\n";
        cout<<2-error<<": Edit A Card\n";
        cout<<3-error<<": Enter Cards From The Beginning\n";
        cout<<4-error<<": Compatible Number Of Cards With Cards Inputs And Apply\n";
        cout<<5-error<<": Edit Game Input Settings\n";
        cout<<6-error<<": Go to Number of Cards Session\n";
        cout<<7-error<<": Go To Line Up Session\n";
        cout<<endl<<"Enter Your Choice: ";
        choice=inputChoice(1,7-error);
		if(choice==2-error){
			cout<<"Card List Number?: ";
            j=inputChoice(1,tcards);
			j--;
			cout<<"Enter The Card: ";
            if(!enterCard(j,tm1,tm2,inpSettings)){
                set_tcards(tm1,tm2);
                goto start;
            }
			goto chapcards;
		}
        else if(choice==3-error) goto start;
        else if(choice==4-error){
            setColor("BOLDBLUE");
            cout<<endl<<tm1.name<<": Yellow cards: "<<inptc1[0]<<" | Red cards: "<<inptc1[1]<<endl;
            cout<<tm2.name<<": Yellow cards: "<<inptc2[0]<<" | Red cards: "<<inptc2[1]<<endl;
            setColor("RESET");
                    
            cout<<endl<<"Are you sure? (1:Yes | 2:No Cancel It): ";
            int ch=inputChoice(1,2);
            if(ch==2) goto finalquest;
            t1_tc[0]=inptc1[0];
            t1_tc[1]=inptc1[1];
            t1_tc[2]=inptc1[2];
            t2_tc[0]=inptc2[0];
            t2_tc[1]=inptc2[1];
            t2_tc[2]=inptc2[2];
            setColor("GREEN");
            cout<<endl<<"Number Of Cards Compatible With Inputs\n";
            setColor("RESET");
        }
        
        else if(choice==5-error){
            inpSettings.settings();
            goto chapcards;
        } 
        
        else if(choice==6-error){
            set_tcards(tm1,tm2);
            goto start;
        } 
        
        else if(choice==6-error){
            set_tcards(tm1,tm2);
            goto start;
        } 
                
        if(choice==7-error){
            setColor("BOLDRED");
            cout<<"Works:\n";
            setColor("RESET");
            cout<<"1: Enter Complete Teams Line Ups\n";
            cout<<"2: Enter "<<tm1.getName()<<" Line Up\n";
            cout<<"3: Enter "<<tm2.getName()<<" Line Up\n";
            cout<<"4: Cancel And Try Again to Entering Goal\n";
            choice=inputChoice(1,4);
            if(choice==1){
                setFirstLineup(tm1);
                setFirstLineup(tm2);
                setSubLineup(tm1);
                setSubLineup(tm2);
            }
            else if(choice==2){
                setFirstLineup(tm1);
                setSubLineup(tm1);
            }
            else if(choice==3){
                setFirstLineup(tm2);
                setSubLineup(tm2);
            }
            if(choice!=4) goto start;
        }
                						
		for(int i=0; 28-tcards>i; i++) for(int k=0; 5>k; k++) cards[27-i][k]=-1;
		break;
	}
}

void match::set_mom(team tm1,team tm2,inputProfile& inpSettings,bool edit, bool checkAfterEdit){
    stringstream temp1;
    stringstream temp2;
    stringstream temp3;
    stringstream temp4;
	int choice,error=0;
        
    start:
	temp1.str("");
	temp2.str("");
	temp3.str("");
	temp4.str("");
    
    if(checkAfterEdit){
        if(mom[0][0]<0){
            return;
        }
        else if(mom[1][0]<0){
            choice=2;
        }
        else{
            choice=1;
        }
        goto findingError;
    }
    
    if(edit){
        edit=false;
        if(mom[0][0]<0){
            goto start;
        }
        else if(mom[1][0]<0){
            choice=2;
        }
        else{
            choice=1;
        }
        goto findingError;
    }
    
    setColor("BOLDRED");
    cout<<endl<<"Do you want Enter Man Of the Match And Second Player Of the Match?\n";
    setColor("RESET");
    cout<<"1: Yes Both of Them\n";
    cout<<"2: Yes Only Man Of The Match\n";
    cout<<"3: No\n";
    cout<<"\nEnter Your Choice: ";
    choice=inputChoice(1,3);
    if(choice==3){
        if(sure()){
            for(int i=0; 2>i; i++) for(int j=0; 2>j; j++) mom[i][j]=-1;
            return;
        }
        else goto start;
    }
    else if(choice==2){
        mom[1][0]=-1;
        mom[1][1]=-1;
    }
	cout<<"\nEnter Number Of Man of The Match(2 Points)\n";
    if(choice==1) cout<<"Then Second Player Of The Match (1 Points)\n";
	if(choice==1) rulePrint("Help: MOTM - Team - Second Player - Team\n");
    else if(choice==2) rulePrint("Help: MOTM - Team\n");

        
             
    mom[0][0]=nextInt();
    mom[0][1]=nextInt();
    if(choice==1){
        mom[1][0]=nextInt();
        mom[1][1]=nextInt();
    }
    
    error=0; 
    
    findingError:
	if(easycheck(mom[0][1],1,2)==0){
        if(error==0 && checkAfterEdit){
            cout<<endl;
            printError("Your Edit Cause Error In MOTM Section\n\n");
        }
        else if(error==0) cout<<endl;
        error=1;
        printError("Invalid MOTM Team Id\n");
    }
                
	if(choice==1 && easycheck(mom[1][1],1,2)==0){
        if(error==0 && checkAfterEdit){
            cout<<endl;
            printError("Your Edit Cause Error In MOTM Section\n\n");
        }
        else if(error==0) cout<<endl;
        error=1;
        printError("Invalid SPOTM Team Id\n");
    }
                
	if((mom[0][1]==1 && !prCanEnter(mom[0][0],tm1)) || (mom[0][1]==2 && !prCanEnter(mom[0][0],tm2))){
        if(error==0 && checkAfterEdit){
            cout<<endl;
            printError("Your Edit Cause Error In MOTM Section\n\n");
        }
        else if(error==0) cout<<endl;
        error=1;
        if(mom[0][0]>INT_MAX-2) printError("Invalid Value For MOTM Number\n");
        else if((mom[0][1]==1 && !tm1.existNumber(mom[0][0])) || (mom[0][1]==2 && !tm2.existNumber(mom[0][0]))){
            printError("MOTM: There is No Player With This Number!\n");
        }
        else printError("MOTM: This Player Not entered This Game!\n");
    }
                
	if(choice==1 && ((mom[1][1]==1 && !prCanEnter(mom[1][0],tm1)) || (mom[1][1]==2 && !prCanEnter(mom[1][0],tm2)))){
        if(error==0 && checkAfterEdit){
            cout<<endl;
            printError("Your Edit Cause Error In MOTM Section\n\n");
        }
        else if(error==0) cout<<endl;
        error=1;
        if(mom[1][0]>INT_MAX-2) printError("Invalid Value For SPOTM Number\n");
        else if((mom[0][1]==1 && !tm1.existNumber(mom[1][0])) || (mom[0][1]==2 && !tm2.existNumber(mom[1][0]))){
            printError("SPOTM: There is No Player With This Number!\n");
        }
        else printError("SPOTM: This Player Not entered This Game!\n");
    }
                
	if(choice==1 && mom[0][1]==mom[1][1] && mom[0][0]==mom[1][0]){
        if(error==0 && checkAfterEdit){
            cout<<endl;
            printError("Your Edit Cause Error In MOTM Section\n\n");
        }
        else if(error==0) cout<<endl;
        error=1;
        printError("Same Inputs For MOTM and SPOTM\n");
    }
    
    if(error==0 && checkAfterEdit) return;
    checkAfterEdit=false;
    if(error){
        setColor("BOLDYELLOW");
        cout<<"You are wrong! Try Again\n";
        goto start;
    }
        
	cout<<endl; setColor("BOLDBLUE"); cout<<"Man of the match: ";
	if(mom[0][1]==1) cout<<tm1.getPrFromNumber(mom[0][0]).sendname()<<" from "<<tm1.name<<endl;
	else if(mom[0][1]==2) cout<<tm2.getPrFromNumber(mom[0][0]).sendname()<<" from "<<tm2.name<<endl;
    if(choice==1){
        cout<<"Second Player of the match: ";
        if(mom[1][1]==1){ cout<<tm1.getPrFromNumber(mom[1][0]).sendname()<<" from "<<tm1.name<<endl;}
        else if(mom[1][1]==2){ cout<<tm2.getPrFromNumber(mom[1][0]).sendname()<<" from "<<tm2.name<<endl;}
    }
    setColor("RESET");
	cout<<endl<<"Do you want to edit? (1:No | 2:Yes)\n";
    choice=inputChoice(1,2);
	if(choice==2){ set_mom(tm1,tm2,inpSettings); return;}
}

void match::set_conf(team tm1,team tm2,bool edit){
	int choice,bar=0;
    if(edit){
        edit=false;
        goto chapconf;
    }
    
	tm1_conf:
	while(1){
		cout<<endl<<tm1.name<<": Do You Conference? (1:Yes | 2:No): ";
        choice=inputChoice(1,2);
		if(choice==2){
			t1_conf[0]=0;
			break;
		}
		cin.getline(t1_conf,1200);
		break;
	}
    
	while(1){
		bar++;
		tm2_conf:
		if(bar>1) break;
		cout<<endl<<tm2.name<<": Do You Conference? (1:Yes | 2:No): ";
		choice=inputChoice(1,2);
		if(choice==2){
			t2_conf[0]=0;
			break;
		}
		cin.getline(t2_conf,1200);
		break;
	}
    
    chapconf:
	cout<<endl; setColor("BOLDBLUE"); cout<<tm1.name<<": ";
	print_passage(t1_conf);
	cout<<endl;
	cout<<endl<<tm2.name<<": ";
	print_passage(t2_conf);
	cout<<endl; setColor("RESET");
	cout<<endl<<"Do you want to edit? (1:No | 2:"<<tm1.name<<" | 3:"<<tm2.name<<")\n";
	choice=inputChoice(1,3);
	if(choice==2) goto tm1_conf;
	else if(choice==3) goto tm2_conf;
}

void match::setPlayersHatTricks(team &tm1,team &tm2){
	if(tg<3) return;
	int **prStats;
	prStats=getPlayersStats();
	for(int i=0; prStats[i][0]!=0 && 28>i; i++){
		if(prStats[i][2]>=3){
			int p=prStats[i][2]/3;
			if(prStats[i][0]==1){
				tm1.getPrFromId(prStats[i][1]).hatTrikPlus(p);
			}
			else if(prStats[i][0]==2){
				tm2.getPrFromId(prStats[i][1]).hatTrikPlus(p);	
			}
		}
	}
}

void match::update_after_game(team &tm1,team &tm2,bool silent){
	if(exist==1){ tm1.app_p(); tm2.app_p();}
	if(res==1){ tm1.win_p(); tm2.lose_p();}
	else if(res==2){ tm2.win_p(); tm1.lose_p();}
	else if(res==3){ tm1.draw_p(); tm2.draw_p();}

	for(int i=0; 11>i; i++){
		if(t1_prs[i]>0){
			tm1.getPrFromId(t1_prs[i]).app_p();
			if(t1_pov[i]>0) tm1.getPrFromId(t1_prs[i]).setOverall(t1_pov[i]);
		}
	}
	
	for(int i=0; 11>i; i++){
		if(t2_prs[i]>0){
			tm2.getPrFromId(t2_prs[i]).app_p();
			if(t2_pov[i]>0) tm2.getPrFromId(t2_prs[i]).setOverall(t2_pov[i]);
		}
	}
	
	for(int i=0; t1_tt>i; i++){
		if(t1_tvz[i]>0){
			tm1.getPrFromId(t1_tvz[i]).app_p();
			if(t1_tov[i]>0) tm1.getPrFromId(t1_tvz[i]).setOverall(t1_tov[i]);
		}
	}
	
	for(int i=0; t2_tt>i; i++){
		if(t2_tvz[i]>0){
			tm2.getPrFromId(t2_tvz[i]).app_p();
			if(t2_tov[i]>0) tm2.getPrFromId(t2_tvz[i]).setOverall(t2_tov[i]);
		}
	}
	
    if(mom[0][0]!=-1){
        if(mom[0][1]==1) tm1.getPrFromId(mom[0][0]).momPlus();
        else if(mom[0][1]==2) tm2.getPrFromId(mom[0][0]).momPlus();
    }
    
    if(mom[1][0]!=-1){
        if(mom[1][1]==1) tm1.getPrFromId(mom[1][0]).secondMomPlus();
        else if(mom[1][1]==2) tm2.getPrFromId(mom[1][0]).secondMomPlus();
    }
        
	if(t1_goals!=-2){ for(int i=0; t1_goals>i; i++) tm1.goal_p();}
	if(t2_goals!=-2){ for(int i=0; t2_goals>i; i++) tm2.goal_p();}
	if(t1_possess!=-2) tm1.possess_p(t1_possess);
	if(t2_possess!=-2) tm2.possess_p(t2_possess);
	if(t1_shots[0]!=-2) tm1.shots0_p(t1_shots[0]);
	if(t1_shots[1]!=-2) tm1.shots1_p(t1_shots[1]);
	if(t2_shots[0]!=-2) tm2.shots0_p(t2_shots[0]);
	if(t2_shots[1]!=-2) tm2.shots1_p(t2_shots[1]);
	if(t1_fouls[0]!=-2) tm1.fouls0_p(t1_fouls[0]);
	if(t1_fouls[1]!=-2) tm1.fouls1_p(t1_fouls[1]);
	if(t2_fouls[0]!=-2) tm2.fouls0_p(t2_fouls[0]);
	if(t2_fouls[1]!=-2) tm2.fouls1_p(t2_fouls[1]);
	if(t1_corners!=-2) tm1.corners_p(t1_corners);
	if(t2_corners!=-2) tm2.corners_p(t2_corners);
	if(t1_tackles!=-2) tm1.tackles_p(t1_tackles);
	if(t2_tackles!=-2) tm2.tackles_p(t2_tackles);
	if(t1_saves!=-2) tm1.saves_p(t1_saves);
	if(t2_saves!=-2) tm2.saves_p(t2_saves);
	if(t1_fk!=-2) tm1.fk_p(t1_fk);
	if(t2_fk!=-2) tm2.fk_p(t2_fk);
	if(t1_interc!=-2) tm1.interc_p(t1_interc);
	if(t2_interc!=-2) tm2.interc_p(t2_interc);
	if(t1_pass_c!=-2) tm1.pass_c_p(t1_pass_c);
	if(t2_pass_c!=-2) tm2.pass_c_p(t2_pass_c);
	if(t1_cross!=-2) tm1.cross_p(t1_cross);
	if(t2_cross!=-2) tm2.cross_p(t2_cross);
        
	if(t1_tc[0]!=-2) for(int i=0; t1_tc[0]>i; i++) tm1.yc_p();
	if(t1_tc[1]!=-2) for(int i=0; t1_tc[1]>i; i++) tm1.rc_p();
	if(t2_tc[0]!=-2) for(int i=0; t2_tc[0]>i; i++) tm2.yc_p();
	if(t2_tc[1]!=-2) for(int i=0; t2_tc[1]>i; i++) tm2.rc_p();
        
	for(int i=0; tcards>i; i++){
		if(cards[i][0]==1){ if(cards[i][2]==1 && cards[i][3]!=-2) tm1.getPrFromId(cards[i][3]).yc_p();}
		if(cards[i][0]==1){ if(cards[i][2]==2 && cards[i][3]!=-2) tm1.getPrFromId(cards[i][3]).rc_p();}
		if(cards[i][0]==2){ if(cards[i][2]==1 && cards[i][3]!=-2) tm2.getPrFromId(cards[i][3]).yc_p();}
		if(cards[i][0]==2){ if(cards[i][2]==2 && cards[i][3]!=-2) tm2.getPrFromId(cards[i][3]).rc_p();}
	}
        
	for(int i=0; tg>i; i++){
		if(goals[i][0]==1){
			if(goals[i][2]!=-2 && goals[i][2]!=-1) tm1.getPrFromId(goals[i][2]).goal_p();
			if(goals[i][3]!=-2 && goals[i][3]!=-1) tm1.getPrFromId(goals[i][3]).ass_p();
		}
		else if(goals[i][0]==2){
			if(goals[i][2]!=-2 && goals[i][2]!=-1) tm2.getPrFromId(goals[i][2]).goal_p();
			if(goals[i][3]!=-2 && goals[i][3]!=-1) tm2.getPrFromId(goals[i][3]).ass_p();
		}
	}
        
	setPlayersHatTricks(tm1,tm2);
	if(!silent){
        setColor("BOLDGREEN");
        cout<<"Teams and Players Details Updated.\n";
        setColor("RESET");
        cout<<endl;
    }
}

void match::show(team tm1,team tm2){
	int s,t,c;
    const int scrLength=78;
    stringstream temp1;
	stringstream ts1[14];
	stringstream ts2[14];
	stringstream gl[30];
	stringstream cs[28];
	stringstream att1[3];
	stringstream att2[3];
	stringstream cadr;
	stringstream ov1,ov2;
	
	bool pPossess=(t1_possess!=-2 || t2_possess!=-2);
	bool pShots=(t1_shots[0]!=-2 || t2_shots[0]!=-2);
	bool pFouls=(t1_fouls[0]!=-2 || t2_fouls[0]!=-2);
	bool pCorners=(t1_corners!=-2 || t2_corners!=-2);
	bool pFk=(t1_fk!=-2 || t2_fk!=-2);
	bool pPassC=(t1_pass_c!=-2 || t2_pass_c!=-2);
	bool pCross=(t1_cross!=-2 || t2_cross!=-2);
	bool pInterc=(t1_interc!=-2 || t2_interc!=-2);
	bool pTackles=(t1_tackles!=-2 || t2_tackles!=-2);
	bool pSaves=(t1_saves!=-2 || t2_saves!=-2);
	
	
	if(t1_goals==-2) ts1[0]<<"UK"; else ts1[0]<<t1_goals;
	if(t2_goals==-2) ts2[0]<<"UK"; else ts2[0]<<t2_goals;
	if(t1_possess==-2) ts1[1]<<"UK"; else ts1[1]<<t1_possess<<"%";
	if(t2_possess==-2) ts2[1]<<"UK"; else ts2[1]<<t2_possess<<"%";
	if(t1_shots[0]!=-2 && t1_shots[1]!=-2) ts1[2]<<t1_shots[0]<<"("<<t1_shots[1]<<")";
	if(t2_shots[0]!=-2 && t2_shots[1]!=-2) ts2[2]<<t2_shots[0]<<"("<<t2_shots[1]<<")";
	if(t1_fouls[0]!=-2 && t1_fouls[1]!=-2) ts1[3]<<t1_fouls[0]<<"("<<t1_fouls[1]<<")";
	if(t2_fouls[0]!=-2 && t2_fouls[1]!=-2) ts2[3]<<t2_fouls[0]<<"("<<t2_fouls[1]<<")";
	if(t1_corners==-2) ts1[4]<<"UK"; else ts1[4]<<t1_corners;
	if(t2_corners==-2) ts2[4]<<"UK"; else ts2[4]<<t2_corners;
	if(t1_fk==-2) ts1[5]<<"UK"; else ts1[5]<<t1_fk;
	if(t2_fk==-2) ts2[5]<<"UK"; else ts2[5]<<t2_fk;
	if(t1_pass_c==-2) ts1[6]<<"UK"; else ts1[6]<<t1_pass_c<<"%";
	if(t2_pass_c==-2) ts2[6]<<"UK"; else ts2[6]<<t2_pass_c<<"%";
	if(t1_cross==-2) ts1[7]<<"UK"; else ts1[7]<<t1_cross;
	if(t2_cross==-2) ts2[7]<<"UK"; else ts2[7]<<t2_cross;
	if(t1_interc==-2) ts1[8]<<"UK"; else ts1[8]<<t1_interc;
	if(t2_interc==-2) ts2[8]<<"UK"; else ts2[8]<<t2_interc;
	if(t1_tackles==-2) ts1[9]<<"UK"; else ts1[9]<<t1_tackles;
	if(t2_tackles==-2) ts2[9]<<"UK"; else ts2[9]<<t2_tackles;
	if(t1_saves==-2) ts1[10]<<"UK"; else ts1[10]<<t1_saves;
	if(t2_saves==-2) ts2[10]<<"UK"; else ts2[10]<<t2_saves;
	
	if(t1_shots[0]==-2 || t1_shots[1]==-2){
		if(t1_shots[0]==-2 && t1_shots[1]==-2) ts1[2]<<"Uk"; else if(t1_shots[0]==-2) ts1[2]<<"Uk("<<t1_shots[1]<<")"; else ts1[2]<<t1_shots[0]<<"(UK)";
	}
	if(t2_shots[0]==-2 || t2_shots[1]==-2){
		if(t2_shots[0]==-2 && t2_shots[1]==-2) ts2[2]<<"Uk"; else if(t2_shots[0]==-2) ts2[2]<<"Uk("<<t2_shots[1]<<")"; else ts2[2]<<t2_shots[0]<<"(UK)";
	}
	if(t1_fouls[0]==-2 || t1_fouls[1]==-2){
		if(t1_fouls[0]==-2 && t1_fouls[1]==-2) ts1[3]<<"Uk"; else if(t1_fouls[0]==-2) ts1[3]<<"Uk("<<t1_fouls[1]<<")"; else ts1[3]<<t1_fouls[0]<<"(UK)";
	}
	if(t2_fouls[0]==-2 || t2_fouls[1]==-2){
		if(t2_fouls[0]==-2 && t2_fouls[1]==-2) ts2[3]<<"Uk"; else if(t2_fouls[0]==-2) ts2[3]<<"Uk("<<t2_fouls[1]<<")"; else ts2[3]<<t2_fouls[0]<<"(UK)";
	}
	temp1.str("");
	cout<<endl;
    setColor("BOLDRED");
	temp1<<tm1.name<<" Against "<<tm2.name;
	space(27); ccsPrint(temp1); setColor("RESET");
	temp1.str("");
	if(year!=-2){
		cout<<endl;
		temp1<<"$$WHT"<<"Date: ";
		temp1<<year;
		if(month!=-2 && month>9) temp1<<"/"<<month; else if(month!=-2 && month<10)temp1<<"/"<<"0"<<month;
		if(month!=-2 && day!=-2 && day>9) temp1<<"/"<<day<<"$0RST"<<endl; else if(day!=-2 && day<10)temp1<<"/"<<"0"<<day<<"$0RST"<<endl;
		beforeStrWhere(temp1,scrLength);
	}
	
	cout<<endl<<endl;
	cadr<<"$$BLU";
	t=12; c=48; s=15;
	space(s); ccsPrint(cadr); cadr_dash(c);
	space(s); cout<<"|"; setColor("BOLDCYAN"); strwhere(tm1.name,t,1); setColor("BOLDBLUE"); strwhere("Stats",22,1); setColor("BOLDCYAN"); strwhere(tm2.name,t,1); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	space(s); cout<<"|"; strwhere(ts1[0],t); strwhere("Goals Scored",22); strwhere(ts2[0],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);
	
	if(pPossess){ space(s); cout<<"|"; strwhere(ts1[1],t); strwhere("Possession",22); strwhere(ts2[1],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(pShots){ space(s); cout<<"|"; strwhere(ts1[2],t); strwhere("Shots (On Target)",22); strwhere(ts2[2],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(pFouls){ space(s); cout<<"|"; strwhere(ts1[3],t); strwhere("Fouls (Offside)",22); strwhere(ts2[3],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(pCorners){ space(s); cout<<"|"; strwhere(ts1[4],t); strwhere("Corner Kicks",22); strwhere(ts2[4],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(pFk){ space(s); cout<<"|"; strwhere(ts1[5],t); strwhere("Free Kicks",22); strwhere(ts2[5],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(pPassC){ space(s); cout<<"|"; strwhere(ts1[6],t); strwhere("Passes Completed (%)",22); strwhere(ts2[6],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(pCross){ space(s); cout<<"|"; strwhere(ts1[7],t); strwhere("Crosses",22); strwhere(ts2[7],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(pInterc){ space(s); cout<<"|"; strwhere(ts1[8],t); strwhere("Interception",22); strwhere(ts2[8],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(pTackles){ space(s); cout<<"|"; strwhere(ts1[9],t); strwhere("Tackles",22); strwhere(ts2[9],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	if(pSaves){ space(s); cout<<"|"; strwhere(ts1[10],t); strwhere("Saves",22); strwhere(ts2[10],t); ccsPrint(cadr); cout<<"|"<<endl; space(s); cadr_dash(c);}
	
	bool knownPrs=false;
	for(int i=0; 11>i && !knownPrs; i++) if(t1_prs[i]>0) knownPrs=true;
	for(int i=0; 11>i && !knownPrs; i++) if(t2_prs[i]>0) knownPrs=true;
	for(int i=0; 3>i && !knownPrs; i++) if(t1_tvz[i]>0) knownPrs=true;
	for(int i=0; 3>i && !knownPrs; i++) if(t2_tvz[i]>0) knownPrs=true;
	
	if(knownPrs){
		for(int i=0; 14>i; i++){
			ts1[i].str("");
			ts2[i].str("");
		}
		
		for(int i=0; 11>i; i++){
			if(t1_prs[i]==-2) ts1[i]<<"UK";
			else ts1[i]<<tm1.getPrFromId(t1_prs[i]).sendname();
			if(t1_pov[i]>0) ts1[i]<<"$0RST ("<<player::getOverallString(t1_pov[i])<<")";
		}
		
		for(int i=0; 11>i; i++){
			if(t2_prs[i]==-2) ts2[i]<<"UK";
			else ts2[i]<<tm2.getPrFromId(t2_prs[i]).sendname();
			if(t2_pov[i]>0) ts2[i]<<"$0RST ("<<player::getOverallString(t2_pov[i])<<")";
		}
		
		for(int i=11; 14>i; i++){
			if(t1_tt>i-11){
				if(t1_tvz[i-11]==-2) ts1[i]<<"UK";
				else ts1[i]<<tm1.getPrFromId(t1_tvz[i-11]).sendname();
				if(t1_tov[i-11]>0) ts1[i]<<"$0RST ("<<player::getOverallString(t1_tov[i-11])<<")";
			}
		}
		
		for(int i=11; 14>i; i++){
			if(t2_tt>i-11){
				if(t2_tvz[i-11]==-2) ts2[i]<<"UK";
				else ts2[i]<<tm2.getPrFromId(t2_tvz[i-11]).sendname();
				if(t2_tov[i-11]>0) ts2[i]<<"$0RST ("<<player::getOverallString(t2_tov[i-11])<<")";
			}
		}
		
		double t1Strength=getTeamStrength(tm1);
		double t2Strength=getTeamStrength(tm2);

		if(t1Strength!=-1) ov1<<"Strength: "<<player::getOverallString(t1Strength);
		else ov1<<"Strength: "<<player::getOverallString(-2);
		
		if(t2Strength!=-1) ov2<<"Strength: "<<player::getOverallString(t2Strength);
		else ov2<<"Strength: "<<player::getOverallString(-2);
		
		cout<<endl<<endl;
		setColor("BOLDBLUE"); beforeStrWhere("Players",scrLength); setColor("RESET");cout<<endl;
		s=18;
		space(s); ccsPrint(cadr); cadr_dash(42,true); setColor("RESET");cout<<endl;
		t=20;
		for(int i=0; 11>i; i++){
			space(s); ccsPrint(cadr); cout<<"|"; setColor("RESET");
			if(mom[0][1]==1 && mom[0][0]==t1_prs[i] && t1_prs[i]!=-2) setColor("BOLDYELLOW");
			if(mom[1][1]==1 && mom[1][0]==t1_prs[i] && t1_prs[i]!=-2) setColor("BOLDGREEN");
			strwhere(ts1[i],t,1); setColor("RESET");
			if(mom[0][1]==2 && mom[0][0]==t2_prs[i] && t2_prs[i]!=-2) setColor("BOLDYELLOW");
			if(mom[1][1]==2 && mom[1][0]==t2_prs[i] && t2_prs[i]!=-2) setColor("BOLDGREEN");
			strwhere(ts2[i],t,1); setColor("RESET");
			ccsPrint(cadr); cout<<"|"; setColor("RESET"); cout<<endl; 
		}
		space(s); ccsPrint(cadr); cadr_dash(42,true); setColor("RESET");cout<<endl;
		for(int i=11; 14>i; i++){
			space(s); ccsPrint(cadr); cout<<"|"; setColor("RESET");
			if(mom[0][1]==1 && mom[0][0]==t1_tvz[i-11] && t1_tvz[i-11]!=-2) setColor("BOLDYELLOW");
			if(mom[1][1]==1 && mom[1][0]==t1_tvz[i-11] && t1_tvz[i-11]!=-2) setColor("BOLDGREEN");
			strwhere(ts1[i],t,1); setColor("RESET");
			if(mom[0][1]==2 && mom[0][0]==t2_tvz[i-11] && t2_tvz[i-11]!=-2) setColor("BOLDYELLOW");
			if(mom[1][1]==2 && mom[1][0]==t2_tvz[i-11] && t2_tvz[i-11]!=-2) setColor("BOLDGREEN");
			strwhere(ts2[i],t,1); setColor("RESET");
			ccsPrint(cadr); cout<<"|"; setColor("RESET");cout<<endl;		
		}
		space(s); ccsPrint(cadr); cadr_dash(42,true); setColor("RESET");cout<<endl;
		if(t1Strength!=-1 || t2Strength!=-1){
			space(s); ccsPrint(cadr); cout<<"|"; setColor("RESET");
			strwhere(ov1,t,1); strwhere(ov2,t,1);
			ccsPrint(cadr); cout<<"|"; setColor("RESET");cout<<endl;
			space(s); ccsPrint(cadr); cadr_dash(42,true); setColor("RESET");cout<<endl;
		}
	}
	
	
	if(tg>0 && goals[0][0]>0){
		for(int i=0; tg>i; i++){
			if(goals[i][4]==-2) gl[i]<<"UK | "; else gl[i]<<goals[i][4]<<" | ";
			if(goals[i][0]==1){
				if(goals[i][2]==-2) gl[i]<<"UK ("; else if(goals[i][2]==-1) gl[i]<<"OG ("; else gl[i]<<tm1.getPrFromId(goals[i][2]).sendname()<<" (";
				if(goals[i][3]==-2) gl[i]<<"UK)"; else if(goals[i][3]==-1) gl[i]<<"WA)"; else gl[i]<<tm1.getPrFromId(goals[i][3]).sendname()<<")";
			}
			if(goals[i][0]==2){
				if(goals[i][2]==-2) gl[i]<<"UK ("; else if(goals[i][2]==-1) gl[i]<<"OG ("; else gl[i]<<tm2.getPrFromId(goals[i][2]).sendname()<<" (";
				if(goals[i][3]==-2) gl[i]<<"UK)"; else if(goals[i][3]==-1) gl[i]<<"WA)"; else gl[i]<<tm2.getPrFromId(goals[i][3]).sendname()<<")";
			}
		}
		cout<<endl<<endl;
		setColor("BOLDBLUE"); beforeStrWhere("Goals",scrLength); setColor("RESET"); cout<<endl;
		space(17); ccsPrint(cadr); cout<<"----------------------------------------------"; setColor("RESET");cout<<endl;
		for(int i=0; tg>i; i++){
			if(goals[i][0]==1){space(20); setColor("BOLDMAGENTA"); ccsPrint(gl[i]); setColor("RESET");cout<<endl;}
			if(goals[i][0]==2){space(30); setColor("BOLDCYAN"); ccsPrint(gl[i]); setColor("RESET");cout<<endl;}
		}
		space(17); ccsPrint(cadr); cout<<"----------------------------------------------"; setColor("RESET");cout<<endl;
	}
	if(tcards>0 && cards[0][0]>0){
		for(int i=0; tcards>i; i++){
			if(cards[i][4]==-2) cs[i]<<"UK | "; else cs[i]<<cards[i][4]<<" | ";
			if(cards[i][2]==1) cs[i]<<"$$YEL"<<"Yellow"<<"$0RST"<<" | "; else if(cards[i][2]==2) cs[i]<<"$$RED"<<"Red"<<"$0RST"<<" | ";
			if(cards[i][0]==1){
				if(cards[i][2]==-2) cs[i]<<"$$MAG"<<"UK"; else cs[i]<<"$$MAG"<<tm1.getPrFromId(cards[i][3]).sendname();
			}
			if(cards[i][0]==2){
				if(cards[i][2]==-2) cs[i]<<"$$CYN"<<"UK"; else cs[i]<<"$$CYN"<<tm2.getPrFromId(cards[i][3]).sendname();
			}
		}
		cout<<endl<<endl;
		setColor("BOLDBLUE"); beforeStrWhere("Cards",scrLength); setColor("RESET");cout<<endl;
		space(17); ccsPrint(cadr); cout<<"----------------------------------------------"; setColor("RESET");cout<<endl;
		for(int i=0; tcards>i; i++){
			if(cards[i][0]==1){space(20); setColor("BOLDMAGENTA"); ccsPrint(cs[i]); setColor("RESET");cout<<endl;}
			if(cards[i][0]==2){space(30); setColor("BOLDCYAN"); ccsPrint(cs[i]); setColor("RESET");cout<<endl;}
		}					
		space(17); ccsPrint(cadr); cout<<"----------------------------------------------"; setColor("RESET");cout<<endl;
                
	}
	
	bool pAttack=(t1_left!=-2 || t2_left!=-2 || t1_center!=-2 || t2_center!=-2 || t1_right!=-2 || t2_right!=-2);
	if(pAttack){
		if(t1_left>0){
			if(t1_left>t1_center && t1_left>t1_right) att1[0]<<"$$GRN";
			att1[0]<<t1_left<<"$0RST";
		}
		if(t1_center>0){
			if(t1_center>t1_left && t1_center>t1_right) att1[1]<<"$$GRN";
			att1[1]<<t1_center<<"$0RST";
		}
		if(t1_right>0){
			if(t1_right>t1_left && t1_right>t1_center) att1[2]<<"$$GRN";
			att1[2]<<t1_right<<"$0RST";
		}
		
		
		if(t2_left>0){
			if(t2_left>t2_center && t2_left>t2_right) att2[0]<<"$$GRN";
			att2[0]<<t2_left<<"$0RST";
		}
		if(t2_center>0){
			if(t2_center>t2_left && t2_center>t2_right) att2[1]<<"$$GRN";
			att2[1]<<t2_center<<"$0RST";
		}
		if(t2_right>0){
			if(t2_right>t2_left && t2_right>t2_center) att2[2]<<"$$GRN";
			att2[2]<<t2_right<<"$0RST";
		}
		
		s=26;
		cout<<endl<<endl;
		setColor("BOLDBLUE"); beforeStrWhere("Attacking Areas",scrLength); setColor("RESET");cout<<endl;
		space(s); ccsPrint(cadr); cadr_dash(25); setColor("RESET");
		space(s); ccsPrint(cadr); cout<<"|"; setColor("BOLDMAGENTA"); strwhere(tm1.getName(),23,1); ccsPrint(cadr); cout<<"|"<<endl;
		space(s); ccsPrint(cadr); cadr_dash(25); setColor("RESET");
		space(s); ccsPrint(cadr); cout<<"|"; strwhere(att1[0],7,0);
		ccsPrint(cadr); cout<<"|"; strwhere(att1[1],7,0);
		ccsPrint(cadr); cout<<"|"; strwhere(att1[2],7,0); ccsPrint(cadr); cout<<"|"<<endl;
		space(s); ccsPrint(cadr); cadr_dash(25); setColor("RESET");
		
		space(s); ccsPrint(cadr); cout<<"|"; setColor("BOLDCYAN"); strwhere(tm2.getName(),23,1); ccsPrint(cadr); cout<<"|"<<endl;
		space(s); ccsPrint(cadr); cadr_dash(25); setColor("RESET");
		space(s); ccsPrint(cadr); cout<<"|"; strwhere(att2[0],7,0);
		ccsPrint(cadr); cout<<"|"; strwhere(att2[1],7,0);
		ccsPrint(cadr); cout<<"|"; strwhere(att2[2],7,0); ccsPrint(cadr); cout<<"|"<<endl;
		space(s); ccsPrint(cadr); cadr_dash(25); setColor("RESET");
	}
	
    showAllConfs(tm1,tm2,scrLength,60,(scrLength-60)/2,3);
}
