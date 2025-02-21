#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Menu(){
	system("cls");
	cout<<"MENU"<<endl;
	cout<<"===="<<endl;
	cout<<"1. Add segitiga berisi"<<endl;
	cout<<"2. Add kotak berisi"<<endl;
	cout<<"3. Add kotak bolong"<<endl;
	cout<<"4. View bangun"<<endl;
	cout<<"5. Save"<<endl;
	cout<<">>> ";
}

void Save(vector<int> segitiga,vector<int> kotakberisi,vector<int> kotakbolong,int counter[]){
	ofstream f("bangun.txt");
	if(f.is_open()){
		f<<counter[0]<<endl;
		for(int i=0;i<counter[0];i++){
			f<<segitiga[i]<<endl;
		}
		f<<counter[1]<<endl;
		for(int i=0;i<counter[1];i++){
			f<<kotakberisi[i]<<endl;
		}
		f<<counter[2]<<endl;
		for(int i=0;i<counter[2];i++){
			f<<kotakbolong[i]<<endl;
		}
	}
	f.close();
}

void Load(int counter[],vector<int> &segitiga,vector<int> &kotakberisi,vector<int> &kotakbolong){
	segitiga.clear();
	kotakberisi.clear();
	kotakbolong.clear();
	ifstream f("bangun.txt");
	if(f.is_open()){
		while(!f.eof()){
			int temp;
			f>>counter[0];
			if(counter[0]!=0){
				for(int i=0;i<counter[0];i++){
					f>>temp;
					segitiga.push_back(temp);
				}
			}
			f>>counter[1];
			if(counter[1]!=0){
				for(int i=0;i<counter[1];i++){
					f>>temp;
					kotakberisi.push_back(temp);
				}
			}
			f>>counter[2];
			if(counter[2]!=0){
				for(int i=0;i<counter[2];i++){
					f>>temp;
					kotakbolong.push_back(temp);
				}
			}
		}
	}
	f.close();
}

int main()
{
	int menu,ukuran,temp;
	vector<int> segitiga;
	vector<int> kotakberisi;
	vector<int> kotakbolong;
	int counter[]={0,0,0};

	Load(counter,segitiga,kotakberisi,kotakbolong);
	do{
		Menu(); cin>>menu;
		if(menu==1){
			cout<<"ukuran segitiga: "; cin>>ukuran;
			segitiga.push_back(ukuran);
			counter[0]+=1;
			for(int y=0;y<ukuran;y++){
				for(int x=0;x<=y;x++){
					cout<<'*';
				}
				cout<<endl;
			}

		} else if(menu==2){
			cout<<"ukuran kotak berisi: "; cin>>ukuran;
			counter[1]+=1;
			kotakberisi.push_back(ukuran);
			for(int y=0;y<ukuran;y++){
				for(int x=0;x<ukuran;x++){
					cout<<'*';
				}
				cout<<endl;
			}

		} else if(menu==3){
			cout<<"ukuran kotak bolong: "; cin>>ukuran;
			counter[2]+=1;
			kotakbolong.push_back(ukuran);
			for(int y=0;y<ukuran;y++){
				for(int x=0;x<ukuran;x++){
					if(y==0 || x==0 || y==ukuran-1 || x==ukuran-1) cout<<'*';
					else cout<<' ';
				}
				cout<<endl;
			}

		} else if(menu==4){
			cout<<"jumlah bangun: "<<counter[0]+counter[1]+counter[2]<<endl;
			cout<<"segitiga: "<<counter[0]<<endl;
			cout<<"kotak berisi: "<<counter[1]<<endl;
			cout<<"kotak bolong: "<<counter[2]<<endl;
			cout<<endl;
			for(int i=0;i<counter[0];i++){
				for(int y=0;y<segitiga[i];y++){
					for(int x=0;x<=y;x++){
						cout<<'*';
					}
					cout<<endl;
				}
				cout<<endl;
			}
			for(int i=0;i<counter[1];i++){
				for(int y=0;y<kotakberisi[i];y++){
					for(int x=0;x<kotakberisi[i];x++){
						cout<<'*';
					}
					cout<<endl;
				}
				cout<<endl;
			}
			for(int i=0;i<counter[2];i++){
				for(int y=0;y<kotakbolong[i];y++){
					for(int x=0;x<kotakbolong[i];x++){
						if(y==0 || x==0 || y==kotakbolong[i]-1 || x==kotakbolong[i]-1) cout<<'*';
						else cout<<' ';
					}
					cout<<endl;
				}
				cout<<endl;
			}

		} else if(menu==5){
			Save(segitiga,kotakberisi,kotakbolong,counter);
			cout<<"Data bangun telah tersave"<<endl;
		}
		system("pause");
	}while(true);
    return 0;
}
