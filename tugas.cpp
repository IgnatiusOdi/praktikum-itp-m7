#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Menu(){
    system("cls");
	cout<<"+++++ADMIN+++++"<<endl;
	cout<<"==============="<<endl;
	cout<<"MENU RESTAURANT"<<endl;
	cout<<"==============="<<endl;
	cout<<"1. Insert"<<endl;
	cout<<"2. Update"<<endl;
	cout<<"3. Delete"<<endl;
	cout<<"4. List all"<<endl;
	cout<<"5. Sort"<<endl;
	cout<<"6. Exit"<<endl;
	cout<<">> ";
}

void Load(int &counter,string nama[],int harga[],int hargapajak[]){
	ifstream f("menu.txt");
	if(f.is_open()){
		int i=0;
        while(!f.eof()){
            getline(f,nama[i]);
            if(nama[i]!=""){
	            f>>harga[i];
	            f>>hargapajak[i];
            	i++;
			}
        }
        counter=i;
    }
	f.close();
}

void Save(int counter,string nama[],int harga[],int hargapajak[]){
	ofstream f("menu.txt");
	if(f.is_open()){
		for(int i=0;i<counter;i++){
			f<<nama[i]<<endl;
			f<<harga[i]<<endl;
			f<<hargapajak[i]<<endl;
		}
	}
	f.close();
}

int main()
{
	int menu,counter=0;
	string nama[20];
	int harga[20],hargapajak[20];	
    Load(counter,nama,harga,hargapajak);
	do{
		Menu(); cin>>menu;
		if(menu==1){ //INSERT
			system("cls");
			cout<<"INSERT"<<endl;
			cout<<"======"<<endl;
			cout<<"nama menu   : "; cin.ignore(); getline(cin,nama[counter]);
			cout<<"harga       : "; cin>>harga[counter];
			cout<<"harga+pajak : "; cin>>hargapajak[counter];
            counter++;

		} else if(menu==2){ //UPDATE
			string nm;
			int hrg,hrgp,index;
			bool ketemu=false;
			system("cls");
			cout<<"UPDATE"<<endl;
			cout<<"======"<<endl;
			cout<<"nama menu   : "; cin.ignore(); getline(cin,nm);
			for(int i=0;i<counter;i++){
				if(nama[i]==nm){
                    ketemu=true;
                    index=i;
				}
			}
			if(ketemu){
				cout<<"harga       : "; cin>>hrg;
				harga[index]=hrg;
				cout<<"harga+pajak : "; cin>>hrgp;
				hargapajak[index]=hrgp;
				cout<<"harga telah di update"<<endl;
			} else cout<<"Data tidak ditemukan"<<endl;
			system("pause");

		} else if(menu==3){ //DELETE
			string nm;
			int index;
			bool ketemu=false;
			system("cls");
			cout<<"DELETE"<<endl;
			cout<<"====="<<endl;
			cout<<"nama menu   : "; cin.ignore(); getline(cin,nm);
			for(int i=0;i<counter;i++){
				if(nama[i]==nm){
                    ketemu=true;
                    index=i;
				}
			}
			if(ketemu){
				for(int i=index;i<counter-1;i++){
					nama[i]=nama[i+1];
					harga[i]=harga[i+1];
					hargapajak[i]=hargapajak[i+1];
				}
				counter--;
				cout<<"nama menu telah di delete"<<endl;
			} else cout<<"Data tidak ditemukan"<<endl;
			system("pause");

		} else if(menu==4){
			//LIST
			for(int i=0;i<counter;i++){
				cout<<i+1<<". "<<nama[i]<<" ("<<harga[i]<<") - "<<hargapajak[i]<<endl;
			}
			system("pause");

		} else if(menu==5){
			//SORT ASCENDING
			string sortnama[counter];
			int sortharga[counter];
			int sorthargapajak[counter];
			string tempnm;
			int temphrg,temphrgp;
			for(int i=0;i<counter;i++){
				sortnama[i]=nama[i];
				sortharga[i]=harga[i];
				sorthargapajak[i]=hargapajak[i];
			}
			for(int i=0;i<counter;i++){
				for(int j=i+1;j<counter;j++){
					if(sorthargapajak[i]>sorthargapajak[j]){
						tempnm=sortnama[i];
						temphrg=sortharga[i];
						temphrgp=sorthargapajak[i];

						sortnama[i]=sortnama[j];
						sortharga[i]=sortharga[j];
						sorthargapajak[i]=sorthargapajak[j];

						sortnama[j]=tempnm;
						sortharga[j]=temphrg;
						sorthargapajak[j]=temphrgp;
					}
				}
			}
			for(int i=0;i<counter;i++){
				cout<<i+1<<". "<<sortnama[i]<<" ("<<sortharga[i]<<") - "<<sorthargapajak[i]<<endl;
			}
			system("pause");
		}
	}while(menu!=6);
	Save(counter,nama,harga,hargapajak);
    return 0;
}
