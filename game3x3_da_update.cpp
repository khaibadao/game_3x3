#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
// muc tieu se la làm mot bai random ngau nhien voi may:))
// nhung thu can lam : + ham random(1 ---> 9 va moi lan nhu v deu danh dau la da duoc danh)
//                     + muom cho dep hon thi use mau me ti :))
//                     + day hay coi nhu la mot project hoan hao
//                     + luon phai kiem tra nguoi nhap co dung voi yeu cau hay ko:))
//     
void SET_COLOR(int color)
{
	WORD wColor;
     

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}                
char mang[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
void banco(){
	SET_COLOR(14);
	cout << endl;
    for(int i = 0 ; i < 3 ; i++){
    	cout << "              ";
    	for(int j = 0 ; j < 3 ; j++){
    		if(mang[i][j] == 'X'){
    			SET_COLOR(3);
    			cout << mang[i][j] << "       ";
			}else
			{
				SET_COLOR(10);
				if(mang[i][j] == 'O'){
					cout << mang[i][j] << "       ";
				}
			}
			if(mang[i][j] != 'X' && mang[i][j] != 'O'){
				SET_COLOR(14);
				cout << mang[i][j] << "       ";
			}
		}
	cout << endl << endl;
	}
}
// 7749 bug :))
int Ran(int l, int r){
	return l + rand() % (r - l + 1);
}
int dem[10] = {0};
// se co 2 thang nguoi_chon va may_chon
char Nguoi_choi = 'X', May_choi = 'O';
int gia_tri = 0;
//int So_nguoi_choi_chon = 0;
void choi(){
	srand(time(NULL));
	SET_COLOR(14);
	cout << " Hay chon so di nao : ";
	SET_COLOR(11);
	string Xau_fake; cin >> Xau_fake;
	gia_tri += 2;
	while(Xau_fake[0] == '\n'){
		gia_tri -= 2;
		SET_COLOR(4);
		cout << "Bi Loi !!! " << endl;
		cout << "Hay nhap lai : ";
		SET_COLOR(11); 
		cin >> Xau_fake;
		gia_tri += 2;
	}
	while(Xau_fake.size() > 1){
		gia_tri -= 2;
		SET_COLOR(4);
		gia_tri -= 2;
		cout << "Bi Loi !!! " << endl;
		cout << "Hay nhap lai : ";
		SET_COLOR(11); 
		cin >> Xau_fake;
		gia_tri += 2;
	}
	while(Xau_fake[0] == '0' || Xau_fake[0] == ' ' || ('1' > Xau_fake[0] || Xau_fake[0] > '9')){
		gia_tri -= 2;
		SET_COLOR(4);
		cout << "Bi Loi  !!! " << endl;
		cout << "Hay nhap lai : ";
		SET_COLOR(11); 
		cin >> Xau_fake;
		gia_tri += 2;
	}
	int So_nguoi_choi_chon = Xau_fake[0] - 48;
	dem[So_nguoi_choi_chon]++;
	while(dem[So_nguoi_choi_chon] > 1){
		gia_tri -= 2;
		cout << endl;
		SET_COLOR(4);
		cout << "Bi Loi !!! " << endl;
		cout << "Hay nhap lai : ";
		SET_COLOR(11); 
		cin >> Xau_fake;
		gia_tri += 2;
	    So_nguoi_choi_chon = Xau_fake[0] - 48;
	    dem[So_nguoi_choi_chon]++;
	}
	int may_chon = Ran(1, 9);
	dem[may_chon]++;
//	cout << gia_tri << endl;
	while(dem[may_chon] > 1){
		if(gia_tri == 10){
			may_chon = 0;
			break;
//			may_chon = 0;
		}
		may_chon = Ran(1, 9);
		dem[may_chon]++;
	}
//	cout << may_chon << " " << dem[may_chon] << endl;
	switch (So_nguoi_choi_chon){
    	case 1:
    		mang[0][0] = Nguoi_choi;
			break;
		case 2:
		   mang[0][1] = Nguoi_choi;
		   break;
		case 3:
    	    mang[0][2] = Nguoi_choi;
	    	break;
		case 4:
		   mang[1][0] = Nguoi_choi;
		   break;
		case 5:
		   mang[1][1] = Nguoi_choi;
		   break;
		case 6:
		   mang[1][2] = Nguoi_choi;
		   break;
		case 7:
		   mang[2][0] = Nguoi_choi;
		   break;
		case 8:
		   mang[2][1] = Nguoi_choi;
		   break;
		case 9:
		   mang[2][2] = Nguoi_choi;
		   break;
	}
	switch (may_chon){
    	case 1:
		   mang[0][0] = May_choi;
		   break;
		case 2:
		   mang[0][1] = May_choi;
		   break;
		case 3:
		   mang[0][2] = May_choi;
		   break;
		case 4:
		   mang[1][0] = May_choi;
		   break;
		case 5:
		   mang[1][1] = May_choi;
		   break;
		case 6:
		   mang[1][2] = May_choi;
		   break;
		case 7:
		   mang[2][0] = May_choi;
		   break;
		case 8:
		   mang[2][1] = May_choi;
		   break;
		case 9:
		   mang[2][2] = May_choi;
		   break;
	}
}
char thang_thua()
{
    if(mang[0][0] == 'X' && mang[0][1] == 'X' && mang[0][2] == 'X')
        return 'X';
    if(mang[1][0] == 'X' && mang[1][1] == 'X' && mang[1][2] == 'X')
        return 'X';
    if(mang[2][0] == 'X' && mang[2][1] == 'X' && mang[2][2] == 'X')
        return 'X';
    if(mang[0][0] == 'X' && mang[1][0] == 'X' && mang[2][0] == 'X')
        return 'X';
    if(mang[0][1] == 'X' && mang[1][1] == 'X' && mang[2][1] == 'X')
        return 'X';
    if(mang[0][2] == 'X' && mang[1][2] == 'X' && mang[2][2] == 'X')
        return 'X';
    if(mang[0][0] == 'X' && mang[1][1] == 'X' && mang[2][2] == 'X')
        return 'X';
    if(mang[0][2] == 'X' && mang[1][1] == 'X' && mang[2][0] == 'X')
        return 'X'; 
	if(mang[0][0] == 'O' && mang[0][1] == 'O' && mang[0][2] == 'O')
        return 'O';
    if(mang[1][0] == 'O' && mang[1][1] == 'O' && mang[1][2] == 'O')
        return 'O';
    if(mang[2][0] == 'O' && mang[2][1] == 'O' && mang[2][2] == 'O')
        return 'O';
    if(mang[0][0] == 'O' && mang[1][0] == 'O' && mang[2][0] == 'O')
        return 'O';
    if(mang[0][1] == 'O' && mang[1][1] == 'O' && mang[2][1] == 'O')
        return 'O';
    if(mang[0][2] == 'O' && mang[1][2] == 'O' && mang[2][2] == 'O')
        return 'O';
    if(mang[0][0] == 'O' && mang[1][1] == 'O' && mang[2][2] == 'O')
        return 'O';
    if(mang[0][2] == 'O' && mang[1][1] == 'O' && mang[2][0] == 'O')
        return 'O'; 
	return 'H';
}
int main()
{
	SET_COLOR(12);
	cout << "    Tinh hinh la tui moi update lai phien ban moi cho no :)))" << endl;
	cout << "          Hay try thu di nao :ooo" << endl;
	banco();
	while(true){
		choi();
		banco();
		if(thang_thua() == 'X'){
		   SET_COLOR(12);
	       cout << "----> Nguoi choi X da thang!!!" ;
	       SET_COLOR(7);
	       return 0;
	   }
		if(thang_thua() == 'O'){
    	   SET_COLOR(12);
		   cout << "----> Nguoi May Da Thang !!!";
		   SET_COLOR(7);
	       return 0;
	   }
	    if(gia_tri == 10 && thang_thua() == 'H'){
	   	    SET_COLOR(12);
	     	cout << "----> Ca hai de hue nhau !!!";
	     	SET_COLOR(7);
	   		return 0;
	    }
	}
	return 0;
}
