#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<windows.h>

//--------------------------ANSI ESCAPE CODES(USED FOR FORMATTING)--------------------------------

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;


//----------------------------- Title bar------------------------------------

void titleBar()
{
		system("cls");
		int ascii=178,choice;
		char ch=ascii;
		cout<<"\n";
		for(int i=1;i<=47;i++)
		{
			cout<<BOLDYELLOW<<ch;
		}
		cout<<RESET<<BOLDGREEN<<" RAILWAY MANAGEMENT SYSTEM ";
		for(int i=1;i<=45;i++)
		{
			cout<<RESET<<BOLDYELLOW<<ch;
		}
}

//------------------------------FUNCTION TO PRINT MESSAGE SLOWLY----------------------------------

void printMessageSlowly(string message)
{
    // will type each character after 0.05 seconds
    for(char c : message)
	{
        cout<<c;
        Sleep(50);
    }
}


class Train;
class Passenger;
class Station;
class Route;

//-------------------------------- Person Class ------------------------------------------

class Person{
	string name;
	string address;
	int age;
	public:
		Person(){
		}
		Person(string n, string ad, int a)
		{
			name=n;
			address=ad;
			age=a;
		}
		void setName(string n){
			name=n;
		}
		void setAge(int a){
			age=a;
		}
		string getName(){
			return name;
		}
		int getAge(){
			return age;
		}
		void setAddress(string a){
			address=a;
		}
		string getAddress(){
			return address;
		}
};

//--------------------------------- Staff Class---------------------------------------------

class Staff: public Person{
	string staffId;
	double salary;
	public:
		Staff():Person(){}
		Staff(string n, string ad, int a,string sid, double s):Person(n,ad,a){
			staffId=sid;
			salary=s;
		}
		void setStaffId(string i){
			staffId=i;
		}
		void setsalary(double s){
			salary=s;
		}
		string getStaffId(){
			return staffId;
		}
		double getsalary(){
			return salary;
		}

};

//--------------------------------- Ticket Class ------------------------------------

class Ticket
{
	int ticket_number;
	int ticket_id;
	int number_Of_Tickets;
	char ticket_class;
	int ticketPrice=800;
	int total;
	friend class Station;
	string departure_station;
	string arrival_station;
	string departure_time;
	string arrival_time;
	public:
		friend class Train;
		friend class Passenger;
		void setArrival_station(string as){
			arrival_station=as;
		}
		void setDeparture_station(string ds){
			departure_station=ds;
		}
		string getArrival_station(){
			return arrival_station;
		}
		string getDeparture_station(){
			return departure_station;
		}
		void setticket_number(int t){
			ticket_number=t;
		}
		void setticket_id(int id){
			ticket_id=id;
		}
		void setnumber_Of_Tickets(int n){
			number_Of_Tickets=n;
		}
		void setticket_class(char c){
			ticket_class=c;
		}
		void setDeparture_time(string dt){
			departure_time=dt;
		}
		void setArrival_time(string at){
			arrival_time=at;
		}
		void settotal(int t){
			total=t;
		}
		int gettotal(){
			return total;
		}
		int getticketPrice(){
			return ticketPrice;
		}
		int getticket_number(){
			return ticket_number;
		}
		int getticket_id(){
			return ticket_id;
		}
		int getnumber_Of_Tickets(){
			return number_Of_Tickets;
		}
		char getticket_class(){
			return ticket_class;
		}
		string getDeparture_time(){
			return departure_time;
		}
		string getArrival_time(){
			return arrival_time;
		}
};

//------------------------------ Passenger Class --------------------------------------------

class Passenger: public Person
{
	vector<Train>train;
	string passengerID;
	int accountNo;
	public:	
	Passenger():Person(){}
		void setPassengerID(string id){
			passengerID=id;
		}
		string getpassengerID(){
			return passengerID;
		}
		void setaccountNo(int ac){
			accountNo=ac;
		}
		int getaccountNo(){
			return accountNo;
		}
		void generateTicket()
		{
			cout<<"Ticket is generated. "<<endl;
		}
		void cancelTicket()
		{
			cout<<"Ticket is cancelled. "<<endl;
		}
};

//------------------------------ Train Class  ----------------------------------

class Train
{
	private:
	int trainID;
	string schedule;
	int capacity;
	int currentCapacity;
	public:
		friend class Route;
		Train(){
		}
		Train(int trainID,int capacity,string schedule)   //string route,
		{
			this->trainID=trainID;
			this->capacity=capacity;
			currentCapacity=capacity;
			this->schedule=schedule;
		}
		void setTrainID(int id) 
		{
			trainID=id; 
		}
		void setTrainCapacity(int c)
		{
			capacity=c;
		}
		void setCurrentCapacity(int r)
		{
			currentCapacity=r;
		}
		void getSchedule(string s)
		{
			schedule=s;
		}
		
		int getTrainID() 
		{
			return trainID; 
		}
		int getTrainCapacity()
		{
			return capacity;
		}
		int getCurrentCapacity()
		{
			return currentCapacity;
		}
		string getSchedule()
		{
			return schedule;
		}
		
		void loadPassenger()
		{
			if(currentCapacity<=capacity)
			{
				int x;
				currentCapacity--;
				x=capacity-currentCapacity;
				cout<<"Passenger loaded. Current Capacity is : "<<capacity-x<<endl;
			}
			else
			{
				cout<<"Train is full"<<endl;
			}
		}
		void unloadPassenger()
		{
			if(currentCapacity>0)
			{
				currentCapacity++;
				cout<<"Passenger unloaded. Current Capacity is : "<<capacity-currentCapacity<<endl;
			}
			else
			{
				cout<<"Train is empty"<<endl;
			}
		}
};

//-------------------------------------- Class Station ----------------------------------------

class Station
{
	char stationID;
	string stationName;
	string location;
	vector<Train>trains; // Declaring a vector of custom objects. its syntax is: vector<classname>vectorname
	// A vector that stores Train class objects, representing the train associated with station.
	public:
		Station(){
		}
		Station(char ID,string na,string loc)
		{
			stationID=ID;
			stationName=na;
			location=loc;
		}
		void setStationID(char i)
		{
			stationID=i;
		}
		void setStationName(string n)
		{
			stationName=n;
		}
		void setLocation(string l)
		{
			location=l;
		}
		char getStationID()
		{
			return stationID;
		}
		string getStationName()
		{
			return stationName;
		}
		string getLocation()
		{
			return location;
		}
};

//------------------------------------- class Route-------------------------------------

class Route
{
	string routeID;
	vector<Station>stations; // A vector that storing Station class object, representing Station associated with route.
	public:
		Route(int ID)
		{
		    routeID=ID;
		} 
		void setRouteId(string i){
			routeID=i;
		}
		string getRouteID()
		{
			return routeID;
		}
};

//------------------------------ class Railway Manager----------------------------------

class RailwayManager
{
	int id=1122;
	string password="Admin123";
	vector<Train>trains; // A vector that storing Train class objects, representing Train class associated with RailwayManager class.
	vector<Passenger>passengers; // A vector that storing Passenger class objects, representing Passenger class associated with RailwayManager class.
	vector<Station>stations; // A vector that storing Station class objects, representing Station class associated with RailwayManager class.
	vector<Route>routes; // A vector that storing Route class objects, representing Route class associated with RailwayManager class.
	vector<Staff>staffs;
	public:
		int getid()
		{
			return id;
		} 
		string getpassword()
		{
			return password;
		}
		void displayTrains()
		{
			cout<<"Displaying all trains detail in the system: "<<endl;
			for(auto &train: trains)
			{
				cout<<"Train ID: "<<train.getTrainID()<<endl;
				cout<<"Train Capacity: "<<train.getTrainCapacity()<<endl;
				cout<<"Train Current Capacity: "<<train.getCurrentCapacity()<<endl;
				cout<<"Train Schedule: "<<train.getSchedule()<<endl;
			}
		}
		void displayStaff()
		{
			cout<<"List of Staff details:"<<endl;
			for(auto &staff: staffs)
			{
				cout<<"Name: "<<staff.getName()<<endl;
				cout<<"ID: "<<staff.getStaffId()<<endl;
				cout<<"Salary: "<<staff.getsalary()<<endl;
			}
			
		}
		void displayPassengers()
		{
			cout<<"Displaying all passengers detail in the system: "<<endl;
			for(auto &passenger: passengers)
			{
				cout<<"Passenger ID: "<<passenger.getpassengerID()<<endl;
				cout<<"Passenger Name: "<<passenger.getName()<<endl;
				cout<<"Passenger Age: "<<passenger.getAge()<<endl;
			}
		}
		void displayStations()
		{
			cout<<"Displaying all stations detail in the system: "<<endl;
			for(auto &station: stations)
			{
				cout<<"Station ID: "<<station.getStationID()<<endl;
				cout<<"Station Name: "<<station.getStationName()<<endl;
				cout<<"Station Location: "<<station.getLocation()<<endl;
			}
		}
};

//----------------------------------------- Main Function------------------------------------

main()
{
	Staff* s=new Staff[10];
	s[0]=Staff("Ali","Lahore",27,"Ali123",27000);
	s[1]=Staff("Umair","Lahore",24,"Umair123",25000);
	s[2]=Staff("Imran","Lahore",23,"Imran123",30000);
	s[3]=Staff("Adil","Islamabad",22,"Adil123",26000);
	s[4]=Staff("Zain","Lahore",28,"Zain123",29000);
	
	Station* sta=new Station[7];
	sta[0]=Station(1,"LAHORE","Androon Lahore");
	sta[1]=Station(2,"MULTAN","City Multan");
	sta[2]=Station(3,"ISLAMABAD","City Islamabad");
	sta[3]=Station(4,"SARGODAH","City Sargodah");
	sta[4]=Station(5,"KARACHI","City Karachi");
	
	
	
	Train* t=new Train[8];
	t[0]=Train(11,200,"6am Lahore--7am Multan--8am Islamabad--9am Sargodah--10am Karachi");
	t[1]=Train(22,200,"8am Lahore--9am Multan--10am Islamabad--11am Sargodah--12pm Karachi");
	t[2]=Train(33,200,"10am Lahore--11am Multan--12pm Islamabad--1pm Sargodah--2pm Karachi");
	t[3]=Train(44,200,"7am Karachi--8am Sargodah--9am Islamabad--10am Multan--11am Lahore");
	t[4]=Train(44,200,"11am Karachi--12pm Sargodah--1pm Islamabad--2pm Multan--3pm Lahore");
	t[5]=Train(44,200,"1pm Karachi--2pm Sargodah--3pm Islamabad--4pm Multan--5pm Lahore");
	
	int time,count=1,from,To,cap=200,age,no,ac,total,ide;
	int hold=1000;
	string name,address,id,pas;
	Passenger p[cap];
	Ticket ti[hold];
	RailwayManager M;
	int x=0,choice;
	char next,con,confirm,ad,log;
	do
	{
	p:
	titleBar();
	cout<<RESET<<BOLDCYAN;
	cout<<"\n\n\n";
	printMessageSlowly("-> 1. PASSENGER");
	cout<<"\n\n\n";
	printMessageSlowly("-> 2. ADMINISTRATOR");
	cout<<"\n\n\n";
	printMessageSlowly("-> PRESS ANY KEY FOR EXIT");
	cout<<"\n\n\n     ";
	printMessageSlowly("ENTER YOUR CHOICE -> ");
	cin>>choice;
	if(choice==1){
		p[x];
		a:
			system("cls");
			titleBar();
		cout<<"\n\n\n\t\t\t\t\t\tWELCOME TO DEVELOPERS LINE"<<endl;
		cout<<RESET<<BOLDCYAN;
		cout<<"\n\n 1. LAHORE"<<endl;
		cout<<"\n\n 2. MULTAN"<<endl;
		cout<<"\n\n 3. ISLAMABAD"<<endl;
		cout<<"\n\n 4. SARGODAH"<<endl;
		cout<<"\n\n 5. KARACHI"<<endl;
		cout<<"\n\n PRESS ANY OTHER KEY FOR EXIT"<<endl;
		cout<<"\n\n FROM WHERE DO YOU LIKE TO BEGIN YOUR JOURNEY: \n\n\n";
		printMessageSlowly("-> ENTER YOUR CHOICE: ");
		cin>>from;
		switch(from){
			case 1:{
				ti[x].setDeparture_station("LAHORE");
				break;
			}
			case 2:{
				ti[x].setDeparture_station("MULTAN");
				break;
			}
			case 3:{
				ti[x].setDeparture_station("ISLAMABAD");
				break;
			}
			case 4:{
				ti[x].setDeparture_station("SARGODAH");
				break;
			}
			case 5:{
				ti[x].setDeparture_station("KARACHI");
				break;
			}
			default:{
				goto p;
				
				break;
			}
		}
		//----------------------------------------------------------------------------------------
		l:
		int a=0,b=1;
		system("cls");
		titleBar();
		cout<<"\n\n\n";
		cout<<"\t\t\t\t\t\t  ENTER YOUR DESTINATION \n\n\n"<<endl;
		cout<<RESET<<BOLDCYAN;
		do{
			if(from!=sta[a].getStationID())
			{
				cout<<"\n\n ";
				cout<<b<<". "<<sta[a].getStationName()<<endl;
				b++;
			}
			a++;
		}while(a<=4);
		
		cout<<"\n\n PRESS ANY OTHER KEY FOR EXIT"<<endl;
		cout<<"\n\n";
		printMessageSlowly("-> ENTER YOUR CHOICE: ");
		cin>>To;
		c:
		if(To>=1&&To<=4){
			system("cls");
			titleBar();
			ti[x].setArrival_station(sta[To].getStationName());
			cout<<"\n\n\n\t\t\t\t\t\t\tARRIVAL TIME "<<endl<<"\n\n\n";
			cout<<RESET<<BOLDCYAN;
		}else{
			goto a;
		}
		
			//system("cls");
			bool condition=true;
		if(from<To){
		cout<<" 1. "<<t[0].getSchedule()<<endl<<"\n\n";
		cout<<" 2. "<<t[1].getSchedule()<<endl<<"\n\n";
		cout<<" 3. "<<t[2].getSchedule()<<endl<<"\n\n";
		}else{
			cout<<" 1. "<<t[3].getSchedule()<<endl<<"\n\n";
			cout<<" 2. "<<t[4].getSchedule()<<endl<<"\n\n";
			cout<<" 3. "<<t[5].getSchedule()<<endl<<"\n\n";
			condition=false;//condition
		}
		cout<<" PRESS ANY OTHER KEY FOR EXIT \n\n"<<endl;
		printMessageSlowly(" ENTER YOUR CHOICE -> ");
		cin>>time;
		if(condition==true&&time>=1&&time<=3){
			if(from==1){
				if(time==1){
					ti[x].setDeparture_time("6am");
				}
				else if(time==2){
					ti[x].setDeparture_time("8am");
				}
				else if(time==3){
					ti[x].setDeparture_time("10am");
				}
			}else if(from==2){
				if(time==1){
					ti[x].setDeparture_time("7am");
				}
				else if(time==2){
					ti[x].setDeparture_time("9am");
				}
				else if(time==3){
					ti[x].setDeparture_time("11am");
				}
			}else if(from==3){
				if(time==1){
					ti[x].setDeparture_time("8am");
				}
				else if(time==2){
					ti[x].setDeparture_time("10am");
				}
				else if(time==3){
					ti[x].setDeparture_time("12pm");
				}
			}else if(from==4){
				if(time==1){
					ti[x].setDeparture_time("9am");
				}
				else if(time==2){
					ti[x].setDeparture_time("11am");
				}
				else if(time==3){
					ti[x].setDeparture_time("1pm");
				}
			}else if(from==5){
				if(time==1){
					ti[x].setDeparture_time("10am");
				}
				else if(time==2){
					ti[x].setDeparture_time("12pm");
				}
				else if(time==3){
					ti[x].setDeparture_time("2pm");
				}
			}
		}else if(condition==false&&time>=1&&time<=3)
		{
			if(from==1){
				if(time==1){
					ti[x].setDeparture_time("11am");
				}
				else if(time==2){
					ti[x].setDeparture_time("3pm");
				}
				else if(time==3){
					ti[x].setDeparture_time("5pm");
				}
			}else if(from==2){
				if(time==1){
					ti[x].setDeparture_time("10am");
				}
				else if(time==2){
					ti[x].setDeparture_time("2pm");
				}
				else if(time==3){
					ti[x].setDeparture_time("4pm");
				}
			}else if(from==3){
				if(time==1){
					ti[x].setDeparture_time("9am");
				}
				else if(time==2){
					ti[x].setDeparture_time("1pm");
				}
				else if(time==3){
					ti[x].setDeparture_time("3pm");
				}
			}else if(from==4){
				if(time==1){
					ti[x].setDeparture_time("8am");
				}
				else if(time==2){
					ti[x].setDeparture_time("12pm");
				}
				else if(time==3){
					ti[x].setDeparture_time("2pm");
				}
			}else if(from==5){
				if(time==1){
					ti[x].setDeparture_time("7am");
				}
				else if(time==2){
					ti[x].setDeparture_time("11pm");
				}
				else if(time==3){
					ti[x].setDeparture_time("1pm");
				}
			}
		}else{
		
			goto l;
		}
		
		if(condition==true){
				if(To==1){
				if(time==1){
					ti[x].setArrival_time("7am");
				}
				else if(time==2){
					ti[x].setArrival_time("11am");
				}
				else if(time==3){
					ti[x].setArrival_time("1pm");
				}
			}else if(To==2){
				if(time==1){
					ti[x].setArrival_time("8am");
				}
				else if(time==2){
					ti[x].setArrival_time("12pm");
				}
				else if(time==3){
					ti[x].setArrival_time("2pm");
				}
			}else if(To==3){
				if(time==1){
					ti[x].setArrival_time("8am");
				}
				else if(time==2){
					ti[x].setArrival_time("1pm");
				}
				else if(time==3){
					ti[x].setArrival_time("3pm");
				}
			}else if(To==4){
				if(time==1){
					ti[x].setArrival_time("9am");
				}
				else if(time==2){
					ti[x].setArrival_time("2pm");
				}
				else if(time==3){
					ti[x].setArrival_time("4pm");
				}
			}else if(To==5){
				if(time==1){
					ti[x].setArrival_time("10am");
				}
				else if(time==2){
					ti[x].setArrival_time("3pm");
				}
				else if(time==3){
					ti[x].setArrival_time("5pm");
				}
			}
		}else if(condition==false){
			if(To==1){
				if(time==1){
					ti[x].setArrival_time("11am");
				}
				else if(time==2){
					ti[x].setArrival_time("3pm");
				}
				else if(time==3){
					ti[x].setArrival_time("5pm");
				}
			}else if(To==2){
				if(time==1){
					ti[x].setArrival_time("10am");
				}
				else if(time==2){
					ti[x].setArrival_time("2pm");
				}
				else if(time==3){
					ti[x].setArrival_time("4pm");
				}
			}else if(To==3){
				if(time==1){
					ti[x].setArrival_time("9am");
				}
				else if(time==2){
					ti[x].setArrival_time("1pm");
				}
				else if(time==3){
					ti[x].setArrival_time("3pm");
				}
			}else if(To==4){
				if(time==1){
					ti[x].setArrival_time("8am");
				}
				else if(time==2){
					ti[x].setArrival_time("12pm");
				}
				else if(time==3){
					ti[x].setArrival_time("2pm");
				}
			}else if(To==5){
				if(time==1){
					ti[x].setArrival_time("7am");
				}
				else if(time==2){
					ti[x].setArrival_time("11am");
				}
				else if(time==3){
					ti[x].setArrival_time("1pm");
				}
			}
		}
		else
		{
			goto l;
		}
	d:
	system("cls");
	titleBar();
	cout<<"\n\n\n\t\t\t\t\t\tCURRENT TRAIN INFORMATION "<<endl;
	cout<<RESET<<BOLDCYAN<<endl;	
	cout<<"\n\n DEPARTURE TIME: "<<ti[x].getDeparture_time()<<endl;
	cout<<"\n\n ARRIVAL TIME: "<<ti[x].getArrival_time()<<endl;
	cout<<"\n\n NUMBER OF AVAILABLE SEATS: "<<t[x].getCurrentCapacity()<<endl;
	cout<<"\n\n PRICE OF 1 TICKET IS: "<<ti[x].getticketPrice()<<endl;
	cout<<"\n\n PRESS 1 TO PROCEED NEXT"<<endl;
	cout<<"\n\n PRESS ANY OTHER KEY TO EXIT\n\n"<<endl;
	printMessageSlowly("-> ENTER YOUR CHOICE: ");
	cin>>next;
	if(next=='1')
	{
		system("cls");
		titleBar();
		cout<<"\n\n\n\t\t\t\t\t\t    ENTER YOUR DETAILS"<<endl;
		cout<<RESET<<BOLDCYAN;
		cout<<"\n\n NAME: ";
		cin>>name;
		p[x].setName(name);
		cout<<"\n\n AGE: ";
		cin>>age;
		p[x].setAge(age);
		cin.ignore();
		cout<<"\n\n ADDRESS: ";
		cin>>address;
		p[x].setAddress(address);
		cout<<"\n\n ID: ";
		cin>>id;
		p[x].setPassengerID(id);
		cout<<"\n\n SEATS AVAILABLE: "<<t[x].getCurrentCapacity()<<endl;
		cout<<"\n\n ENTER NUMBER OF SEATS YOU WANT TO BOOK: ";
		cin>>no;
		ti[x].setnumber_Of_Tickets(no);
		cout<<"\n\n ENTER YOUR ACCOUNT NUMBER: ";
		cin>>ac;
		p[x].setaccountNo(ac);
		total=ti[x].getnumber_Of_Tickets()*ti[x].getticketPrice();
		ti[x].settotal(total);
		cout<<"\n\n TOTAL BILL: "<<ti[x].gettotal()<<endl;
		cout<<"\n\n PRESS 1 TO CONFIRM PAYMENT"<<endl;
		cout<<"\n\n OR ANY OTHER KEY TO EXIT\n\n";
		printMessageSlowly(" ENTER YOUR CHOICE -> ");
		cin>>con;
		if(con=='1')
		{
			system("cls");
			titleBar();
			cout<<"\n\n\n\t\t\t\t\t\t   TICKET INFORMATION "<<endl;
			cout<<RESET<<BOLDCYAN;
			cout<<"\n\n NAME: "<<p[x].getName()<<endl;
			cout<<"\n\n ID: "<<p[x].getpassengerID()<<endl;
			cout<<"\n\n DEPARTURE TIME: "<<ti[x].getDeparture_time()<<endl;
			cout<<"\n\n ARRIVAL TIME: "<<ti[x].getArrival_time()<<endl<<endl;
			cout<<"\n\n PRESS 1 TO ENJOY YOUR JOURNEY"<<endl;
			cout<<"\n\n OR PRESS ANY OTHER KEY TO EXIT\n\n"<<endl;
			printMessageSlowly(" ENTER YOUR CHOICE -> ");
			cin>>confirm;
			if(confirm=='1'){
				p[x].generateTicket();
				t[x].loadPassenger();
				system("cls");
				titleBar();
				cout<<"\n\n";
				cout<<"\t\t\t\t\t\t    \n\n\nTICKET GENERATED!\n\n"<<endl;
				cout<<RESET<<BOLDCYAN<<"\n\n\n\n";
				cout<<"Note. Reached at station before 15 mins and reserve your seat\n\tThanks for joining us..."<<endl;
				getch();
			}else{
				system("cls");
				titleBar();
				cout<<"\n\n\n\n";
				p[x].cancelTicket();
				if(x<0){
					t[x].unloadPassenger();
				}
				cout<<"\nThanks for visit!"<<endl;
				getch();
				goto d;
			}
		}else{
			goto d;
		}
		}else{
			goto c;
		}
		}else if(choice==2)
		{
			q:
				system("cls");
				titleBar();
				cout<<"\n\n\n\n";
				cout<<RESET<<BOLDCYAN;
			cout<<" PRESS 1 TO LOGIN"<<endl;
			cout<<" PRESS 2 TO FORGETPASSWORD"<<endl;
			cout<<"Any other key for Exit"<<endl;
			cout<<"Enter choice: ";
			cin>>ad;
			if(ad=='1'){
				system("cls");
				titleBar();
				cout<<"\n\n\n\n";
		cout<<"Enter ID: ";
		cin>>ide;
		cout<<"Enter Password: ";
		cin>>pas;
		t:
		if(ide==M.getid()&&pas==M.getpassword()){
			system("cls");
			titleBar();
			cout<<"\n\n\n\nWelcome Sir! what do want to see?"<<endl;
			cout<<"1. list of Trains Schedule"<<endl;
			cout<<"2. list of Staff Members"<<endl;
			cout<<"3. list of Stations"<<endl;
			cout<<"4. list of Passenger"<<endl;
			cout<<"Any other key for Logout"<<endl;
			cout<<"Enter choice: ";
			cin>>log;
			if(log=='1')
			{
				for(int i=0;i<6;i++)
				{
					cout<<t[i].getSchedule()<<endl;
				}
				getch();
				goto t;
			}
			else if(log=='2')
			{
				for(int i=0;i<6;i++)
				{
				cout<<s[i].getName()<<endl;
				}
				getch();
				goto t;
			}
			else if(log=='3')
			{
				for(int i=0;i<5;i++)
				{
					cout<<sta[i].getStationName()<<endl;
				}
				getch();
				goto t;
			}
			else if(log=='4')
			{
				if(x>0)
				{
					for(int i=0;i<x;i++)
					{
						cout<<p[i].getName()<<"\t"<<p[i].getpassengerID()<<endl;
					}
					getch();
					goto t;
				}
				else
				{
					cout<<"No Passenger"<<endl;
					getch();
					goto t;	
				}
			}
			else
			{
				cout<<"Logout successfully"<<endl;
				getch();
				goto q;
			}
		}
		else
		{
			cout<<"Invalid Password or Id"<<endl;
			goto q;
		}
		}
		else if(ad=='2')
		{
			cout<<"PASSWORD HINT: 123456"<<endl;
			getch();
			goto q;
		}
		else
		{
			goto p;
		}
	}
	else
	{
		exit(0);
	}
	x++;
	}while(choice==1 || choice==2);
}